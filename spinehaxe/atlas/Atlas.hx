/******************************************************************************
 * Spine Runtimes Software License
 * Version 2.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to install, execute and perform the Spine Runtimes
 * Software (the "Software") solely for internal use. Without the written
 * permission of Esoteric Software (typically granted by licensing Spine), you
 * may not (a) modify, translate, adapt or otherwise create derivative works,
 * improvements of the Software or develop new applications using the Software
 * or (b) remove, delete, alter or obscure any trademarks or any copyright,
 * trademark, patent or other intellectual property or proprietary rights
 * notices on or in the Software, including any copy thereof. Redistributions
 * in binary or source form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

package spinehaxe.atlas;

import spinehaxe.atlas.Format;
import spinehaxe.Exception.IllegalArgumentException;
import openfl.Vector;

class Atlas {
	private var pages:Array<AtlasPage> = new Array<AtlasPage>();
	private var regions:Array<AtlasRegion> = new Array<AtlasRegion>();
	private var textureLoader:TextureLoader;

	/** @param object A String or ByteArray. */
	public function new (object:String, textureLoader:TextureLoader) {
		load(object, textureLoader);
	}

	function load (atlasText:String, textureLoader:TextureLoader) : Void {
		if (textureLoader == null)
			throw new IllegalArgumentException("textureLoader cannot be null.");
		this.textureLoader = textureLoader;

		var reader:Reader = new Reader(atlasText);
		var tuple:Array<String> = new Array<String>();
		var page:AtlasPage = null;
		while (true) {
			var line:String = reader.readLine();
			if (line == null)
				break;
			line = reader.trim(line);
			if (line.length == 0)
				page = null;
			else if (page == null) {
				page = new AtlasPage();
				page.name = line;

				if (reader.readTuple(tuple) == 2) { // size is only optional for an atlas packed with an old TexturePacker.
					page.width = Std.parseInt(tuple[0]);
					page.height = Std.parseInt(tuple[1]);
					reader.readTuple(tuple);
				}
				page.format = tuple[0];

				reader.readTuple(tuple);
				page.minFilter = tuple[0];
				page.magFilter = tuple[1];

				var direction:String = reader.readValue();
				page.uWrap = TextureWrap.ClampToEdge;
				page.vWrap = TextureWrap.ClampToEdge;
				if (direction == "x")
					page.uWrap = TextureWrap.Repeat;
				else if (direction == "y")
					page.vWrap = TextureWrap.Repeat;
				else if (direction == "xy")
					page.uWrap = page.vWrap = TextureWrap.Repeat;

				textureLoader.loadPage(page, line);

				pages[pages.length] = page;

			} else {
				var region:AtlasRegion = new AtlasRegion();
				region.name = line;
				region.page = page;

				region.rotate = reader.readValue() == "true";

				reader.readTuple(tuple);
				var x:Int = Std.parseInt(tuple[0]);
				var y:Int = Std.parseInt(tuple[1]);

				reader.readTuple(tuple);
				var width:Int = Std.parseInt(tuple[0]);
				var height:Int = Std.parseInt(tuple[1]);

				region.u = x / page.width;
				region.v = y / page.height;
				if (region.rotate) {
					region.u2 = (x + height) / page.width;
					region.v2 = (y + width) / page.height;
				} else {
					region.u2 = (x + width) / page.width;
					region.v2 = (y + height) / page.height;
				}
				region.x = x;
				region.y = y;
				region.width = Std.int(Math.abs(width));
				region.height = Std.int(Math.abs(height));

				if (reader.readTuple(tuple) == 4) { // split is optional
					region.splits = [Std.parseInt(tuple[0]), Std.parseInt(tuple[1]), Std.parseInt(tuple[2]), Std.parseInt(tuple[3])];

					if (reader.readTuple(tuple) == 4) { // pad is optional, but only present with splits
						region.pads = [Std.parseInt(tuple[0]), Std.parseInt(tuple[1]), Std.parseInt(tuple[2]), Std.parseInt(tuple[3])];

						reader.readTuple(tuple);
					}
				}

				region.originalWidth = Std.parseInt(tuple[0]);
				region.originalHeight = Std.parseInt(tuple[1]);

				reader.readTuple(tuple);
				region.offsetX = Std.parseInt(tuple[0]);
				region.offsetY = Std.parseInt(tuple[1]);

				region.index = Std.parseInt(reader.readValue());

				textureLoader.loadRegion(region);
				regions[regions.length] = region;
			}
		}
	}

	/** Returns the first region found with the specified name. This method uses string comparison to find the region, so the result
	 * should be cached rather than calling this method multiple times.
	 * @return The region, or null. */
	public function findRegion (name:String) : AtlasRegion {
		for (i in 0 ... regions.length)
			if (regions[i].name == name)
				return regions[i];
		return null;
	}

	public function dispose () : Void {
		for (i in 0 ... pages.length)
			textureLoader.unloadPage(pages[i]);
	}
}

class Reader {
	private var lines:Array<String>;
	private var index:Int = 0;

	public function new (text:String) {
		var regex:EReg = new EReg("[ \t]*((\r\n)|\r|\n)[ \t]*", "g");
		lines = regex.split(text);
	}

	public function trim (value:String) : String {
		return StringTools.trim(value);
	}

	public function readLine () : String {
		if (index >= lines.length)
			return null;
		return lines[index++];
	}

	public function readValue () : String {
		var line:String = readLine();
		var colon:Int = line.indexOf(":");
		if (colon == -1)
			throw "Invalid line: " + line;
		return trim(line.substring(colon + 1));
	}

	/** Returns the number of tuple values read (1, 2 or 4). */
	public function readTuple (tuple:Array<String>) : Int {
		var line:String = readLine();
		var colon:Int = line.indexOf(":");
		if (colon == -1)
			throw "Invalid line: " + line;
		var i:Int = 0, lastMatch:Int = colon + 1;
		while (i < 3) {
			var comma:Int = line.indexOf(",", lastMatch);
			if (comma == -1) break;
			tuple[i] = trim(line.substr(lastMatch, comma - lastMatch));
			lastMatch = comma + 1;
			i++;
		}
		tuple[i] = trim(line.substring(lastMatch));
		return i + 1;
	}
}
