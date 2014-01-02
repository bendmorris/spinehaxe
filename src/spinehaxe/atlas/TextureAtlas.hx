// SEE https://github.com/libgdx/libgdx/blob/master/gdx/src/com/badlogic/gdx/graphics/g2d/TextureAtlas.java

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

import haxe.io.Input;
import spinehaxe.Exception;
import haxe.io.Eof;
import haxe.io.StringInput;
import spinehaxe.atlas.Texture;
import spinehaxe.ArrayUtils;
import StringTools;
using StringTools;
import Lambda;
using Lambda;

class Page {
    public var textureFile:String;//FileHandler
    public var texture:Texture;
    public var useMipMaps:Bool;
    public var format:String;//Format
    public var minFilter:String;//TextureFilter
    public var magFilter:String;//TextureFilter;
    public var uWrap:String;//TextureWrap
    public var vWrap:String;//TextureWrap

    public function new (textureFile:String, useMipMaps:Bool, format:String, minFilter:String, magFilter:String, uWrap:String,  vWrap:String) {
        this.textureFile = textureFile;
        this.useMipMaps = useMipMaps;
        this.format = format;
        this.minFilter = minFilter;
        this.magFilter = magFilter;
        this.uWrap = uWrap;
        this.vWrap = vWrap;
    }
}

class Region {
    public var page:Page;
    public var index:Int = 0;
    public var name:String;
    public var offsetX:Float = 0;
    public var offsetY:Float = 0;
    public var originalWidth:Int = 0;
    public var originalHeight:Int = 0;
    public var rotate:Bool;
    public var left:Int = 0;
    public var top:Int = 0;
    public var width:Int = 0;
    public var height:Int = 0;
    public var flip:Bool;
    public var splits:Array<Int>;
    public var pads:Array<Int>;

    public function new(){

    }
}

class TextureAtlasData {


    public var pages:Array<Page>;
    public var regions:Array<Region>;
    private var tuple:Array<String>;

    public function new (packFileData:String, imagesDir:String, flip:Bool) {
        tuple = [null, null, null, null];
        pages = new Array<Page>();
        regions = new Array<Region>();

        var reader = new StringInput(packFileData);// new BufferedReader(new InputStreamReader(packFile.read()), 64);
        try {
            var pageImage:Page = null;
            while (true) {
                var line:String = null;
                try{line = reader.readLine();}catch(e:Eof){break;}
                if (line == null) break;
                if (line.trim().length == 0)
                    pageImage = null;
                else if (pageImage == null) {
                    var file:String = imagesDir + line;

                    var format = /*Format.valueOf*/(readValue(reader));

                    readTuple(reader);
                    var min = /*TextureFilter.valueOf*/(tuple[0]);
                    var mag = /*TextureFilter.valueOf*/(tuple[1]);

                    var direction:String = readValue(reader);
                    var repeatX/*:TextureWrap*/ = "ClampToEdge";
                    var repeatY = "ClampToEdge";
                    if (direction == "x")
                        repeatX = "Repeat";
                    else if (direction == "y")
                        repeatY = "Repeat";
                    else if (direction == "xy") {
                        repeatX = "Repeat";
                        repeatY = "Repeat";
                    }

                    pageImage = new Page(file, min == "MipMap", format, min, mag, repeatX, repeatY);
                    pages.push(pageImage);
                } else {
                    var rotate = /*Boolean.valueOf*/(readValue(reader) == "true");

                    readTuple(reader);
                    var left:Int = Std.parseInt(tuple[0]);
                    var top:Int = Std.parseInt(tuple[1]);

                    readTuple(reader);
                    var width:Int = Std.parseInt(tuple[0]);
                    var height:Int = Std.parseInt(tuple[1]);

                    var region = new Region();
                    region.page = pageImage;
                    region.left = left;
                    region.top = top;
                    region.width = width;
                    region.height = height;
                    region.name = line;
                    region.rotate = rotate;

                    if (readTuple(reader) == 4) { // split is optional
                        region.splits = [Std.parseInt(tuple[0]), Std.parseInt(tuple[1]),
                        Std.parseInt(tuple[2]), Std.parseInt(tuple[3])];

                        if (readTuple(reader) == 4) { // pad is optional, but only present with splits
                            region.pads = [Std.parseInt(tuple[0]), Std.parseInt(tuple[1]),
                            Std.parseInt(tuple[2]), Std.parseInt(tuple[3])];

                            readTuple(reader);
                        }
                    }

                    region.originalWidth = Std.parseInt(tuple[0]);
                    region.originalHeight = Std.parseInt(tuple[1]);

                    readTuple(reader);
                    region.offsetX = Std.parseInt(tuple[0]);
                    region.offsetY = Std.parseInt(tuple[1]);

                    region.index = Std.parseInt(readValue(reader));

                    if (flip) region.flip = true;

                    regions.push(region);
                }
            }
            try {reader.close();} catch (ignored:Dynamic) { }
        } catch (ex:Dynamic) {
            try {reader.close();} catch (ignored:Dynamic) { }
            throw new RuntimeException("Error reading pack file: " +ex);
        }

        regions.sort(function (region1:Region, region2:Region) {
            var MAX_VALUE = 0x00ffffff;
            var i1 = region1.index;
            if (i1 == -1) i1 = MAX_VALUE;
            var i2 = region2.index;
            if (i2 == -1) i2 = MAX_VALUE;
            return i1 - i2;
        });
    }

    function readValue (reader:Input):String /*throws IOException*/ {
        var line:String = reader.readLine();
        var colon:Int = line.indexOf(':');
        if (colon == -1) throw new RuntimeException("Invalid line: " + line);
        return line.substring(colon + 1).trim();
    }

    /** Returns the number of tuple values read (2 or 4). */
    function readTuple (reader:Input):Int /*throws IOException*/ {
        var line:String = reader.readLine();
        var colon:Int = line.indexOf(':');
        if (colon == -1) throw new RuntimeException("Invalid line: " + line);
        var i:Int = 0;
        var lastMatch:Int = colon + 1;
        while (i < 3) {
            var comma:Int = line.indexOf(',', lastMatch);
            if (comma == -1) {
                if (i == 0) throw new RuntimeException("Invalid line: " + line);
                break;
            }
            tuple[i] = line.substring(lastMatch, comma).trim();
            lastMatch = comma + 1;
            i++;
        }
        tuple[i] = line.substring(lastMatch).trim();
        return i + 1;
    }


    public function getPages ():Array<Page> {
        return pages;
    }

    public function getRegions ():Array<Region>  {
        return regions;
    }
}

/** Loads images from texture atlases created by TexturePacker.<br>
 * <br>
 * A TextureAtlas must be disposed to free up the resources consumed by the backing textures.
 * @author Nathan Sweet */
class TextureAtlas /*implements Disposable*/ {

	private var /*HashSet<Texture>*/ textures:Array<Texture>;
	private var regions:Array<AtlasRegion>;

    private function addTexture(texture:Texture):Void {
        if(ArrayUtils.indexOf(textures, texture) == -1){
            textures.push(texture);
        }
    }

//	/** Creates an empty atlas to which regions can be added. */
//	public function new () {
//	}
//
//	/** Loads the specified pack file using {@link FileType#Internal}, using the parent directory of the pack file to find the page
//	 * images. */
//	public TextureAtlas (String internalPackFile) {
//		this(Gdx.files.internal(internalPackFile));
//	}
//
//	/** Loads the specified pack file, using the parent directory of the pack file to find the page images. */
//	public TextureAtlas (FileHandle packFile) {
//		this(packFile, packFile.parent());
//	}
//
//	/** @param flip If true, all regions loaded will be flipped for use with a perspective where 0,0 is the upper left corner.
//	 * @see #TextureAtlas(FileHandle) */
//	public TextureAtlas (FileHandle packFile, boolean flip) {
//		this(packFile, packFile.parent(), flip);
//	}
//
//	public TextureAtlas (FileHandle packFile, FileHandle imagesDir) {
//		this(packFile, imagesDir, false);
//	}

	/** @param flip If true, all regions loaded will be flipped for use with a perspective where 0,0 is the upper left corner. */
	public static function create (packFileData:String, imagesDir:String, textureLoader:TextureLoader, flip:Bool=false):TextureAtlas {
		return new TextureAtlas(new TextureAtlasData(packFileData, imagesDir, flip), textureLoader);
	}

	public function new (data:TextureAtlasData, textureLoader:TextureLoader) {
        textures = new Array<Texture>();
        regions = new Array<AtlasRegion>();
        if(data!=null){
            load(data, textureLoader);
        }
	}

	private function load (data:TextureAtlasData, textureLoader:TextureLoader) {
		var pageToTexture:Map<Page, Texture> = new Map();
		for (page in data.pages) {
			var texture:Texture = null;
			if (page.texture == null) {
				texture = textureLoader.loadTexture(page.textureFile, page.format, page.useMipMaps);
				texture.setFilter(page.minFilter, page.magFilter);
				texture.setWrap(page.uWrap, page.vWrap);
			} else {
				texture = page.texture;
				texture.setFilter(page.minFilter, page.magFilter);
				texture.setWrap(page.uWrap, page.vWrap);
			}
            addTexture(texture);
			pageToTexture.set(page, texture);
		}

		for (region in data.regions) {
			var width = region.width;
			var height = region.height;
			var atlasRegion = AtlasRegion.create(pageToTexture.get(region.page), region.left, region.top,
				region.rotate ? height : width, region.rotate ? width : height);
			atlasRegion.index = region.index;
			atlasRegion.name = region.name;
			atlasRegion.offsetX = region.offsetX;
			atlasRegion.offsetY = region.offsetY;
            atlasRegion.originalHeight = region.originalHeight;
			atlasRegion.originalWidth = region.originalWidth;
			atlasRegion.rotate = region.rotate;
			atlasRegion.splits = region.splits;
			atlasRegion.pads = region.pads;
			if (region.flip) atlasRegion.flip(false, true);
			regions.push(atlasRegion);
		}
	}

	/** Adds a region to the atlas. The specified texture will be disposed when the atlas is disposed. */
	public function addRegion (name:String, texture:Texture, x:Int, y:Int, width:Int, height:Int):AtlasRegion {
        addTexture(texture);
		var region = AtlasRegion.create(texture, x, y, width, height);
		region.name = name;
		region.originalWidth = width;
		region.originalHeight = height;
		region.index = -1;
		regions.push(region);
		return region;
	}

	/** Adds a region to the atlas. The texture for the specified region will be disposed when the atlas is disposed. */
	public function addRegionTex (name:String, textureRegion:TextureRegion) {
		return addRegion(name, textureRegion.texture, textureRegion.regionX, textureRegion.regionY,
			textureRegion.regionWidth, textureRegion.regionHeight);
	}

	/** Returns all regions in the atlas. */
	public function getRegions ():Array<AtlasRegion> {
		return regions;
	}

	/** Returns the first region found with the specified name. This method uses string comparison to find the region, so the result
	 * should be cached rather than calling this method multiple times.
	 * @return The region, or null. */
	public function findRegion (name:String):AtlasRegion {
		for (region in regions)
			if (region.name == name) return region;
		return null;
	}

	/** Returns the first region found with the specified name and index. This method uses string comparison to find the region, so
	 * the result should be cached rather than calling this method multiple times.
	 * @return The region, or null. */
	public function findRegionIdx (name:String, index:Int):AtlasRegion {
		for (region in regions) {
			if (region.name == name && region.index == index)
                return region;
		}
		return null;
	}

	/** Returns all regions with the specified name, ordered by smallest to largest {@link AtlasRegion#index index}. This method
	 * uses string comparison to find the regions, so the result should be cached rather than calling this method multiple times. */
	public function findRegions (name:String):Array<AtlasRegion> {
		var matched = new Array<AtlasRegion>();
		for (region in regions) {
			if (region.name == name) matched.push(AtlasRegion.copy(region));
		}
		return matched;
	}
//
//	/** Returns all regions in the atlas as sprites. This method creates a new sprite for each region, so the result should be
//	 * stored rather than calling this method multiple times.
//	 * @see #createSprite(String) */
//	public Array<Sprite> createSprites () {
//		Array sprites = new Array(regions.size);
//		for (int i = 0, n = regions.size; i < n; i++)
//			sprites.add(newSprite(regions.get(i)));
//		return sprites;
//	}
//
//	/** Returns the first region found with the specified name as a sprite. If whitespace was stripped from the region when it was
//	 * packed, the sprite is automatically positioned as if whitespace had not been stripped. This method uses string comparison to
//	 * find the region and constructs a new sprite, so the result should be cached rather than calling this method multiple times.
//	 * @return The sprite, or null. */
//	public Sprite createSprite (String name) {
//		for (int i = 0, n = regions.size; i < n; i++)
//			if (regions.get(i).name.equals(name)) return newSprite(regions.get(i));
//		return null;
//	}
//
//	/** Returns the first region found with the specified name and index as a sprite. This method uses string comparison to find the
//	 * region and constructs a new sprite, so the result should be cached rather than calling this method multiple times.
//	 * @return The sprite, or null.
//	 * @see #createSprite(String) */
//	public Sprite createSprite (String name, int index) {
//		for (int i = 0, n = regions.size; i < n; i++) {
//			AtlasRegion region = regions.get(i);
//			if (!region.name.equals(name)) continue;
//			if (region.index != index) continue;
//			return newSprite(regions.get(i));
//		}
//		return null;
//	}
//
//	/** Returns all regions with the specified name as sprites, ordered by smallest to largest {@link AtlasRegion#index index}. This
//	 * method uses string comparison to find the regions and constructs new sprites, so the result should be cached rather than
//	 * calling this method multiple times.
//	 * @see #createSprite(String) */
//	public Array<Sprite> createSprites (String name) {
//		Array<Sprite> matched = new Array();
//		for (int i = 0, n = regions.size; i < n; i++) {
//			AtlasRegion region = regions.get(i);
//			if (region.name.equals(name)) matched.add(newSprite(region));
//		}
//		return matched;
//	}
//
//	private Sprite newSprite (AtlasRegion region) {
//		if (region.packedWidth == region.originalWidth && region.packedHeight == region.originalHeight) {
//			if (region.rotate) {
//				Sprite sprite = new Sprite(region);
//				sprite.setBounds(0, 0, region.getRegionHeight(), region.getRegionWidth());
//				sprite.rotate90(true);
//				return sprite;
//			}
//			return new Sprite(region);
//		}
//		return new AtlasSprite(region);
//	}
//
//	/** Returns the first region found with the specified name as a {@link NinePatch}. The region must have been packed with
//	 * ninepatch splits. This method uses string comparison to find the region and constructs a new ninepatch, so the result should
//	 * be cached rather than calling this method multiple times.
//	 * @return The ninepatch, or null. */
//	public NinePatch createPatch (String name) {
//		for (int i = 0, n = regions.size; i < n; i++) {
//			AtlasRegion region = regions.get(i);
//			if (region.name.equals(name)) {
//				int[] splits = region.splits;
//				if (splits == null) throw new IllegalArgumentException("Region does not have ninepatch splits: " + name);
//				NinePatch patch = new NinePatch(region, splits[0], splits[1], splits[2], splits[3]);
//				if (region.pads != null) patch.setPadding(region.pads[0], region.pads[1], region.pads[2], region.pads[3]);
//				return patch;
//			}
//		}
//		return null;
//	}

	/** @return the textures of the pages, unordered */
	public function getTextures ():Array<Texture> {
		return textures;
	}

	/** Releases all resources associated with this TextureAtlas instance. This releases all the textures backing all TextureRegions
	 * and Sprites, which should no longer be used after calling dispose. */
	public function dispose () {
		for (texture in textures)
			texture.dispose();
		textures = new Array<Texture>();
	}

}

/** Describes the region of a packed image and provides information about the original image before it was packed. */
class AtlasRegion extends TextureRegion {
    /** The number at the end of the original image file name, or -1 if none.<br>
     * <br>
     * When sprites are packed, if the original file name ends with a number, it is stored as the index and is not considered as
     * part of the sprite's name. This is useful for keeping animation frames in order.
     * @see TextureAtlas#findRegions(String) */
    public var index:Int = 0;

    /** The name of the original image file, up to the first underscore. Underscores denote special instructions to the texture
     * packer. */
    public var name:String;

    /** The offset from the left of the original image to the left of the packed image, after whitespace was removed for packing. */
    public var offsetX:Float = 0;

    /** The offset from the bottom of the original image to the bottom of the packed image, after whitespace was removed for
     * packing. */
    public var offsetY:Float = 0;

    /** The width of the image, after whitespace was removed for packing. */
    public var packedWidth:Int = 0;

    /** The height of the image, after whitespace was removed for packing. */
    public var packedHeight:Int = 0;

    /** The width of the image, before whitespace was removed and rotation was applied for packing. */
    public var originalWidth:Int = 0;

    /** The height of the image, before whitespace was removed for packing. */
    public var originalHeight:Int = 0;

    /** If true, the region has been rotated 90 degrees counter clockwise. */
    public var rotate:Bool;

    /** The ninepatch splits, or null if not a ninepatch. Has 4 elements: left, right, top, bottom. */
    public var splits:Array<Int>;

    /** The ninepatch pads, or null if not a ninepatch or the has no padding. Has 4 elements: left, right, top, bottom. */
    public var pads:Array<Int>;

    public function new () {
        super();
    }

    public static function create ( texture:Texture, x:Int, y:Int, width:Int, height:Int):AtlasRegion {
        var r = new AtlasRegion();
        r.texture = texture;
        r.setRegionXYWH(x, y, width, height);
        r.packedWidth = width;
        r.packedHeight = height;
        return r;
    }

    public static function copy ( region:AtlasRegion):AtlasRegion {
        var r = new AtlasRegion();
        r.setRegionCopy(region);
        r.index = region.index;
        r.name = region.name;
        r.offsetX = region.offsetX;
        r.offsetY = region.offsetY;
        r.packedWidth = region.packedWidth;
        r.packedHeight = region.packedHeight;
        r.originalWidth = region.originalWidth;
        r.originalHeight = region.originalHeight;
        r.rotate = region.rotate;
        r.splits = region.splits;
        return r;
    }

    /** Flips the region, adjusting the offset so the image appears to be flip as if no whitespace has been removed for packing. */
    public override function flip (x:Bool, y:Bool) {
        super.flip(x, y);
        if (x) offsetX = originalWidth - offsetX - getRotatedPackedWidth();
        if (y) offsetY = originalHeight - offsetY - getRotatedPackedHeight();
    }

    /** Returns the packed width considering the rotate value, if it is true then it returns the packedHeight, otherwise it
     * returns the packedWidth. */
    public function getRotatedPackedWidth ():Float {
        return rotate ? packedHeight : packedWidth;
    }

    /** Returns the packed height considering the rotate value, if it is true then it returns the packedWidth, otherwise it
     * returns the packedHeight. */
    public function getRotatedPackedHeight ():Float {
        return rotate ? packedWidth : packedHeight;
    }
}
//
///** A sprite that, if whitespace was stripped from the region when it was packed, is automatically positioned as if whitespace
// * had not been stripped. */
//static public class AtlasSprite extends Sprite {
//    final AtlasRegion region;
//    float originalOffsetX, originalOffsetY;
//
//    public AtlasSprite (AtlasRegion region) {
//        this.region = new AtlasRegion(region);
//        originalOffsetX = region.offsetX;
//        originalOffsetY = region.offsetY;
//        setRegion(region);
//        setOrigin(region.originalWidth / 2f, region.originalHeight / 2f);
//        int width = region.getRegionWidth();
//        int height = region.getRegionHeight();
//        if (region.rotate) {
//            super.rotate90(true);
//            super.setBounds(region.offsetX, region.offsetY, height, width);
//        } else
//            super.setBounds(region.offsetX, region.offsetY, width, height);
//        setColor(1, 1, 1, 1);
//    }
//
//    public AtlasSprite (AtlasSprite sprite) {
//        region = sprite.region;
//        this.originalOffsetX = sprite.originalOffsetX;
//        this.originalOffsetY = sprite.originalOffsetY;
//        set(sprite);
//    }
//
//    public void setPosition (float x, float y) {
//        super.setPosition(x + region.offsetX, y + region.offsetY);
//    }
//
//    public void setBounds (float x, float y, float width, float height) {
//        float widthRatio = width / region.originalWidth;
//        float heightRatio = height / region.originalHeight;
//        region.offsetX = originalOffsetX * widthRatio;
//        region.offsetY = originalOffsetY * heightRatio;
//        int packedWidth = region.rotate ? region.packedHeight : region.packedWidth;
//        int packedHeight = region.rotate ? region.packedWidth : region.packedHeight;
//        super.setBounds(x + region.offsetX, y + region.offsetY, packedWidth * widthRatio, packedHeight * heightRatio);
//    }
//
//    public void setSize (float width, float height) {
//        setBounds(getX(), getY(), width, height);
//    }
//
//    public void setOrigin (float originX, float originY) {
//        super.setOrigin(originX - region.offsetX, originY - region.offsetY);
//    }
//
//    public void flip (boolean x, boolean y) {
//        // Flip texture.
//
//        super.flip(x, y);
//
//        float oldOriginX = getOriginX();
//        float oldOriginY = getOriginY();
//        float oldOffsetX = region.offsetX;
//        float oldOffsetY = region.offsetY;
//
//        float widthRatio = getWidthRatio();
//        float heightRatio = getHeightRatio();
//
//        region.offsetX = originalOffsetX;
//        region.offsetY = originalOffsetY;
//        region.flip(x, y); // Updates x and y offsets.
//        originalOffsetX = region.offsetX;
//        originalOffsetY = region.offsetY;
//        region.offsetX *= widthRatio;
//        region.offsetY *= heightRatio;
//
//        // Update position and origin with new offsets.
//        translate(region.offsetX - oldOffsetX, region.offsetY - oldOffsetY);
//        setOrigin(oldOriginX, oldOriginY);
//    }
//
//    public void rotate90 (boolean clockwise) {
//        // Rotate texture.
//        super.rotate90(clockwise);
//
//        float oldOriginX = getOriginX();
//        float oldOriginY = getOriginY();
//        float oldOffsetX = region.offsetX;
//        float oldOffsetY = region.offsetY;
//
//        float widthRatio = getWidthRatio();
//        float heightRatio = getHeightRatio();
//
//        if (clockwise) {
//            region.offsetX = oldOffsetY;
//            region.offsetY = region.originalHeight * heightRatio - oldOffsetX - region.packedWidth * widthRatio;
//        } else {
//            region.offsetX = region.originalWidth * widthRatio - oldOffsetY - region.packedHeight * heightRatio;
//            region.offsetY = oldOffsetX;
//        }
//
//        // Update position and origin with new offsets.
//        translate(region.offsetX - oldOffsetX, region.offsetY - oldOffsetY);
//        setOrigin(oldOriginX, oldOriginY);
//    }
//
//    public float getX () {
//        return super.getX() - region.offsetX;
//    }
//
//    public float getY () {
//        return super.getY() - region.offsetY;
//    }
//
//    public float getOriginX () {
//        return super.getOriginX() + region.offsetX;
//    }
//
//    public float getOriginY () {
//        return super.getOriginY() + region.offsetY;
//    }
//
//    public float getWidth () {
//        return super.getWidth() / region.getRotatedPackedWidth() * region.originalWidth;
//    }
//
//    public float getHeight () {
//        return super.getHeight() / region.getRotatedPackedHeight() * region.originalHeight;
//    }
//
//    public float getWidthRatio () {
//        return super.getWidth() / region.getRotatedPackedWidth();
//    }
//
//    public float getHeightRatio () {
//        return super.getHeight() / region.getRotatedPackedHeight();
//    }
//
//    public AtlasRegion getAtlasRegion () {
//        return region;
//    }
//}

