package spinehaxe.platform.nme;
import spinehaxe.atlas.Texture;
import flash.display.BitmapData;

#if openfl
import openfl.Assets;
#else
import nme.Assets;
#end

class BitmapDataTexture implements Texture {
    public var width(get, never):Int;
    public var height(get, never):Int;
    
    public var bd:BitmapData;
    public function new(textureFile:String) {
        this.bd = Assets.getBitmapData(textureFile);
    }
    public function get_width():Int {
        return bd.width;
    }
    public function get_height():Int {
        return bd.height;
    }
    public function dispose():Void { bd.dispose(); }
    public function setWrap(uWrap, vWrap):Void {  }
    public function setFilter(minFilter, magFilter):Void {  }
}
