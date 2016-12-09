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

package spinehaxe.attachments;

import spinehaxe.Exception.IllegalArgumentException;
import spinehaxe.Skin;
import spinehaxe.atlas.Atlas;
import spinehaxe.atlas.AtlasRegion;

class AtlasAttachmentLoader implements AttachmentLoader {
	var atlas:Atlas;

	public function new(atlas:Atlas) {
		if (atlas == null)
			throw new IllegalArgumentException("atlas cannot be null.");
		this.atlas = atlas;
	}
	
	public function newRegionAttachment(skin:Skin, name:String, path:String):RegionAttachment {
		var region:AtlasRegion = atlas.findRegion(path);
		if (region == null)
			throw "Region not found in atlas: " + path + " (region attachment: " + name + ")";
		var attachment:RegionAttachment = new RegionAttachment(name);
		attachment.rendererObject = region;
		var scaleX:Float = region.page.width / nextPOT(region.page.width);
		var scaleY:Float = region.page.height / nextPOT(region.page.height);
		attachment.setUVs(region.u * scaleX, region.v * scaleY, region.u2 * scaleX, region.v2 * scaleY, region.rotate);
		attachment.regionOffsetX = region.offsetX;
		attachment.regionOffsetY = region.offsetY;
		attachment.regionWidth = region.width;
		attachment.regionHeight = region.height;
		attachment.regionOriginalWidth = region.originalWidth;
		attachment.regionOriginalHeight = region.originalHeight;
		return attachment;
	}
	
	public function newMeshAttachment(skin:Skin, name:String, path:String):MeshAttachment {
		var region:AtlasRegion = atlas.findRegion(path);
		if (region == null)
			throw "Region not found in atlas: " + path + " (mesh attachment: " + name + ")";
		var attachment:MeshAttachment = new MeshAttachment(name);
		attachment.rendererObject = region;
		var scaleX:Float = region.page.width / nextPOT(region.page.width);
		var scaleY:Float = region.page.height / nextPOT(region.page.height);
		attachment.regionU = region.u * scaleX;
		attachment.regionV = region.v * scaleY;
		attachment.regionU2 = region.u2 * scaleX;
		attachment.regionV2 = region.v2 * scaleY;
		attachment.regionRotate = region.rotate;
		attachment.regionOffsetX = region.offsetX;
		attachment.regionOffsetY = region.offsetY;
		attachment.regionWidth = region.width;
		attachment.regionHeight = region.height;
		attachment.regionOriginalWidth = region.originalWidth;
		attachment.regionOriginalHeight = region.originalHeight;
		return attachment;
	}

	public function newBoundingBoxAttachment(skin:Skin, name:String):BoundingBoxAttachment {
		return new BoundingBoxAttachment(name);
	}

	public function newPathAttachment(skin:Skin, name:String):PathAttachment {
		return new PathAttachment(name);
	}

	static public function nextPOT(value:Int):Int {
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value |= value >> 8;
		value |= value >> 16;
		return value + 1;
	}
}
