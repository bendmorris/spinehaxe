package spinehaxe;
import haxe.ds.Vector;

class ArrayUtils {
	public static function allocFloat(n:Int):Vector<Float> {
		var v:Vector<Float> = new Vector(n);
		for (i in 0 ... n) v.set(i, 0);
		return v;
	}

	public static function allocString(n:Int):Vector<String> {
		return new Vector<String>(n);
	}
}