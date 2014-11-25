package spinehaxe.platform.openfl;

import spinehaxe.Exception.IllegalArgumentException;
import spinehaxe.atlas.AtlasPage;
import spinehaxe.atlas.AtlasRegion;
import spinehaxe.atlas.Texture;
import spinehaxe.atlas.TextureLoader;
import flash.display.BitmapData;
import openfl.Assets;

class BitmapDataTextureLoader implements TextureLoader {
	var prefix:String;

	public function new(prefix:String) {
		this.prefix = prefix;
	}

	public function loadPage (page:AtlasPage, path:String) : Void {
		var bitmapData:BitmapData = Assets.getBitmapData(prefix + path);
		if (bitmapData == null)
			throw new IllegalArgumentException("BitmapData not found with name: " + prefix + path);
		page.rendererObject = bitmapData;
		page.width = bitmapData.width;
		page.height = bitmapData.height;
	}

	public function loadRegion (region:AtlasRegion) : Void {
	}

	public function unloadPage (page:AtlasPage) : Void {
		page.rendererObject.dispose();
	}

	public function loadTexture(textureFile:String, format, useMipMaps):Texture {
		 return new BitmapDataTexture(prefix + textureFile);
	}
}
