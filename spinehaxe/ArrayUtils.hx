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

	public static inline function clearArray<T>(array:Array<T>):Void
	{
		setLength(array, 0);
	}

	public static inline function setLength<T>(array:Array<T>, length:Int):Void
	{
#if flash
		untyped array.length = length;
#else
		while (array.length > length)
		{
			array.pop();
		}
#end
	}
}
