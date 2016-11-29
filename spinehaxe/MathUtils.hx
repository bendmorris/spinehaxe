package spinehaxe;

class MathUtils {
	public inline static var MAX_INT = 2147483647; // 2**31 - 1
	public inline static var MIN_INT = -2147483648;

	public static var radDeg:Float = 180 / Math.PI;
	public static var degRad:Float = Math.PI / 180;

	/**
	 * Converts specified angle in radians to degrees.
	 * @return angle in degrees (not normalized to 0...360)
	 */
	public inline static function radToDeg(rad:Float):Float {
		return radDeg * rad;
	}

	/**
	 * Converts specified angle in degrees to radians.
	 * @return angle in radians (not normalized to 0...Math.PI*2)
	 */
	public inline static function degToRad(deg:Float):Float {
		return degRad * deg;
	}

	public inline static function cosDeg(degrees:Float):Float {
		return Math.cos(degToRad(degrees));
	}

	public inline static function sinDeg(degrees:Float):Float {
		return Math.sin(degToRad(degrees));
	}

	/**
	 * "Clamps" a value to boundaries [min, max].
	 * Example:
	 * clamp(2, 1, 5) == 2;
	 * clamp(0, 1, 5) == 1;
	 * clamp(6, 1, 5) == 5;
	 */
	public inline static function clamp(value:Float, min:Float, max:Float):Float {
		if (value < min)
			return min;
		else if (value > max)
			return max;
		else
			return value;
	}

	public inline static function signum(value:Float):Int {
		return (value > 0) ? 1 : (value < 0) ? -1 : 0;
	}

	public inline static function random(max:Int):Int {
		return Math.round(max * Math.random());
	}

	public inline static function minInt(a:Int, b:Int):Int {
		return a < b ? a : b;
	}

	public inline static function maxInt(a:Int, b:Int):Int {
		return a > b ? a : b;
	}
}
