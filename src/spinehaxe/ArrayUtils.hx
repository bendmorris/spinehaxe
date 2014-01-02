package spinehaxe;
import haxe.ds.Vector;

class ArrayUtils {
    public static function allocFloat(n:Int):Vector<Float> {
        var a = new Vector<Float>(n);
        if (n > 0) {
            a[n - 1] = 0;
            for (i in 0...(n - 1)) {
                a[i] = 0;
            }
        }
        return a;
    }

    public static function allocString(n:Int):Vector<String> {
        var a = new Vector<String>(n);
        if (n > 0) {
            a[n - 1] = null;
            for (i in 0...(n - 1)) {
                a[i] = null;
            }
        }
        return a;
    }

    public static function indexOf<T>(arr:Array<T>, v:T):Int {
        #if (flash || js)
            return untyped arr.indexOf(v);
        #else
            return std.Lambda.indexOf(arr, v);
        #end
    }
}