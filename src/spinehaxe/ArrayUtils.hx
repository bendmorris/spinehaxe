package spinehaxe;
import haxe.ds.Vector;

class ArrayUtils {
    public static function allocFloat(n:Int):Vector<Float> {
        return new Vector<Float>(n);
    }

    public static function allocString(n:Int):Vector<String> {
        return new Vector<String>(n);
    }

    public static function indexOf<T>(arr:Array<T>, v:T):Int {
        return arr.indexOf(v);
    }
}