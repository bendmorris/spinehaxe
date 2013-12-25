// SEE https://github.com/libgdx/libgdx/blob/master/gdx/src/com/badlogic/gdx/graphics/g2d/TextureRegion.java

/*******************************************************************************
 * Copyright 2011 See AUTHORS file.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

package spinehaxe.atlas;


/** Defines a rectangular area of a texture. The coordinate system used has its origin in the upper left corner with the x-axis
 * pointing to the right and the y axis pointing downwards.
 * @author mzechner
 * @author Nathan Sweet */
import spinehaxe.Exception;
class TextureRegion {
    public var texture:Texture;
	public var u:Float;
    public var v:Float;
    public var u2:Float;
    public var v2:Float;
    public var regionWidth:Int;
    public var regionHeight:Int;
    public var regionX(get, set):Int;
    public var regionY(get, set):Int;

	/** Constructs a region with no texture and no coordinates defined. */
	public function new () {
	}

	/** Constructs a region the size of the specified texture. */
	public static function fromTexture (texture:Texture):TextureRegion {
		if (texture == null) throw new IllegalArgumentException("texture cannot be null.");
        var t = new TextureRegion();
		t.texture = texture;
		t.setRegionXYWH(0, 0, texture.width, texture.height);
        return t;
	}

	/** @param width The width of the texture region. May be negative to flip the sprite when drawn.
	 * @param height The height of the texture region. May be negative to flip the sprite when drawn. */
	public static function fromTextureWH (texture:Texture, width:Int, height:Int):TextureRegion {
        var t = new TextureRegion();
		t.texture = texture;
		t.setRegionXYWH(0, 0, width, height);
        return t;
	}

	/** @param width The width of the texture region. May be negative to flip the sprite when drawn.
	 * @param height The height of the texture region. May be negative to flip the sprite when drawn. */
	public static function fromTextureXYWH ( texture:Texture, x:Int, y:Int, width:Int, height:Int):TextureRegion {
        var t = new TextureRegion();
		t.texture = texture;
		t.setRegionXYWH(x, y, width, height);
        return t;
	}

	public static function fromTextureUVUV (texture:Texture, u:Float, v:Float, u2:Float, v2:Float):TextureRegion {
        var t = new TextureRegion();
        t.texture = texture;
		t.setRegionUV(u, v, u2, v2);
        return t;
	}

	/** Constructs a region with the same texture and coordinates of the specified region. */
	public  static function copy (region:TextureRegion):TextureRegion {
        var t = new TextureRegion();
        t.setRegionCopy(region);
        return t;
	}

	/** Constructs a region with the same texture as the specified region and sets the coordinates relative to the specified region.
	 * @param width The width of the texture region. May be negative to flip the sprite when drawn.
	 * @param height The height of the texture region. May be negative to flip the sprite when drawn. */
    public static function createRelXYWH (region:TextureRegion, x:Int, y:Int, width:Int, height:Int):TextureRegion {
        var t = new TextureRegion();
        t.setRegionRelXYWH(region, x, y, width, height);
        return t;
	}

	/** Sets the texture and sets the coordinates to the size of the specified texture. */
	public function setRegionTex (texture:Texture) {
		this.texture = texture;
        setRegionXYWH(0, 0, texture.width, texture.height);
	}

	/** @param width The width of the texture region. May be negative to flip the sprite when drawn.
	 * @param height The height of the texture region. May be negative to flip the sprite when drawn. */
	public function setRegionXYWH (x:Int, y:Int, width:Int, height:Int) {
		var invTexWidth:Float = 1.0 / texture.width;
		var invTexHeight:Float = 1.0 / texture.height;
		setRegionUV(x * invTexWidth, y * invTexHeight, (x + width) * invTexWidth, (y + height) * invTexHeight);
		regionWidth = Math.floor(Math.abs(width));
		regionHeight = Math.floor(Math.abs(height));
	}

	public function setRegionUV (u:Float, v:Float, u2:Float, v2:Float) {
		this.u = u;
		this.v = v;
		this.u2 = u2;
		this.v2 = v2;
		regionWidth = Math.round(Math.abs(u2 - u) * texture.width);
		regionHeight = Math.round(Math.abs(v2 - v) * texture.height);
	}

	/** Sets the texture and coordinates to the specified region. */
	public function setRegionCopy (region:TextureRegion) {
		texture = region.texture;
		setRegionUV(region.u, region.v, region.u2, region.v2);
	}

	/** Sets the texture to that of the specified region and sets the coordinates relative to the specified region. */
	public function setRegionRelXYWH (region:TextureRegion, x:Int, y:Int, width:Int, height:Int) {
		texture = region.texture;
		setRegionXYWH(region.regionX + x, region.regionY + y, width, height);
	}

	public function getU ():Float {
		return u;
	}

	public function setU (u:Float) {
		this.u = u;
		regionWidth = Math.round(Math.abs(u2 - u) * texture.width);
	}

	public function getV ():Float {
		return v;
	}

	public function setV (v:Float) {
		this.v = v;
		regionHeight = Math.round(Math.abs(v2 - v) * texture.height);
	}

	public function getU2 ():Float {
		return u2;
	}

	public function setU2 ( u2:Float) {
		this.u2 = u2;
		regionWidth = Math.round(Math.abs(u2 - u) * texture.width);
	}

	public function getV2 ():Float {
		return v2;
	}

	public function setV2 (v2:Float) {
		this.v2 = v2;
		regionHeight = Math.round(Math.abs(v2 - v) * texture.height);
	}

	public function get_regionX ():Int {
		return Math.round(u * texture.width);
	}

	public function set_regionX (x:Int) {
		setU(cast(x, Float) / texture.width);
		return x;
	}

	public function get_regionY ():Int {
		return Math.round(v * texture.height);
	}

	public function set_regionY (y:Int) {
		setV(cast(y, Float) / texture.height);
		return y;
	}

	/** Returns the region's width. */
	public function getRegionWidth ():Int {
		return regionWidth;
	}

	public function setRegionWidth (width:Int) {
		setU2(u + cast(width, Float) / texture.width);
	}

	/** Returns the region's height. */
	public function getRegionHeight ():Int {
		return regionHeight;
	}

	public function setRegionHeight (height:Int) {
		setV2(v + cast(height, Float) / texture.height);
	}

	public function flip (x:Bool, y:Bool) {
		if (x) {
			var temp = u;
			u = u2;
			u2 = temp;
		}
		if (y) {
			var temp = v;
			v = v2;
			v2 = temp;
		}
	}

	public function isFlipX ():Bool {
		return u > u2;
	}

	public function isFlipY ():Bool {
		return v > v2;
	}

	/** Offsets the region relative to the current region. Generally the region's size should be the entire size of the texture in
	 * the direction(s) it is scrolled.
	 * @param xAmount The percentage to offset horizontally.
	 * @param yAmount The percentage to offset vertically. This is done in texture space, so up is negative. */
	public function scroll (xAmount:Float, yAmount:Float) {
		if (xAmount != 0) {
			var width:Float = (u2 - u) * texture.width;
			u = (u + xAmount) % 1;
			u2 = u + width / texture.width;
		}
		if (yAmount != 0) {
			var height:Float = (v2 - v) * texture.height;
			v = (v + yAmount) % 1;
			v2 = v + height / texture.height;
		}
	}

	/** Helper function to create tiles out of this TextureRegion starting from the top left corner going to the left and ending at
	 * the bottom right corner. Only complete tiles will be returned so if the region's width or height are not a multiple of the
	 * tile width and height not all of the region will be used.
	 * 
	 * @param tileWidth a tile's width in pixels
	 * @param tileHeight a tile's height in pixels
	 * @return a 2D array of TextureRegions indexed by [row][column]. */
	public function split (tileWidth:Int, tileHeight:Int):Array<Array<TextureRegion>> {
		var x:Int = regionX;
		var y:Int = regionY;
		var width:Int = regionWidth;
		var height:Int = regionHeight;

		var rows:Int = Math.floor(height / tileHeight);
		var cols:Int = Math.floor(width / tileWidth);

		var startX:Int = x;
		var tiles = new Array<Array<TextureRegion>>();
		for (rowIdx in 0...rows) {
            var row = new Array<TextureRegion>();
            tiles[rowIdx] = row;
			x = startX;
			for (colIdx in 0...cols) {
                row[colIdx] = TextureRegion.fromTextureXYWH(texture, x, y, tileWidth, tileHeight);
                x += tileWidth;
			}
            y += tileHeight;
		}

		return tiles;
	}

	/** Helper function to create tiles out of the given {@link Texture} starting from the top left corner going to the left and
	 * ending at the bottom right corner. Only complete tiles will be returned so if the texture's width or height are not a
	 * multiple of the tile width and height not all of the texture will be used.
	 * 
	 * @param texture the Texture
	 * @param tileWidth a tile's width in pixels
	 * @param tileHeight a tile's height in pixels
	 * @return a 2D array of TextureRegions indexed by [row][column]. */
	public static function splitTex (texture:Texture, tileWidth:Int, tileHeight:Int):Array<Array<TextureRegion>>  {
		var region = TextureRegion.fromTexture(texture);
		return region.split(tileWidth, tileHeight);
	}
}
