package spinehaxe.platform.nme;
import spinehaxe.atlas.Texture;
import spinehaxe.atlas.TextureLoader;

class BitmapDataTextureLoader implements TextureLoader{
    public function new() {
    }

    public function loadTexture(textureFile:String, format, useMipMaps):Texture {
         return new BitmapDataTexture(textureFile);
    }
}
