package spinehaxe;
import haxe.ds.Vector;

class ArrayUtils {
	public static inline function allocFloat(n:Int):Vector<Float> {
		var v:Vector<Float> = new Vector(n);
		for (i in 0 ... n) v.set(i, 0);
		return v;
	}

	public static inline function allocString(n:Int):Vector<String> {
		return new Vector<String>(n);
	}

	@:generic public static inline function clearArray<T>(array:Array<T>):Void
	{
		while (array.length > 0)
		{
			array.pop();
		}
	}
}
