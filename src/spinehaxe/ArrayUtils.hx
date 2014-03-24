package spinehaxe;
import haxe.ds.Vector;

class ArrayUtils {
    public static function allocFloat(n:Int):Vector<Float> {
#if neko
        var v:Vector<Float> = new Vector(n);
        for (i in 0 ... n) v.set(i, 0);
        return v;
#else
        return new Vector<Float>(n);
#end
    }

    public static function allocString(n:Int):Vector<String> {
        return new Vector<String>(n);
    }

    public static function indexOf<T>(arr:Array<T>, v:T):Int {
        return arr.indexOf(v);
    }
}