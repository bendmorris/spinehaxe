package spinehaxe;
import openfl.Vector;

class ArrayUtils {
	public static function allocFloat(n:Int, fixed:Bool = false):Vector<Float> {
#if (neko || js)
		var v:Vector<Float> = new Vector(n, fixed);
		for (i in 0 ... n) v[i] = 0;
		return v;
#else
		return new Vector<Float>(n, fixed);
#end
	}

	public static function allocString(n:Int):Vector<String> {
		return new Vector<String>(n);
	}
}
