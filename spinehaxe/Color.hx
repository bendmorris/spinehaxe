package spinehaxe;

class Color {
    public static var CLEAR:Color = new Color(0, 0, 0, 0);
    public static var WHITE:Color = new Color(1, 1, 1, 1);
    public static var BLACK:Color = new Color(0, 0, 0, 1);
//TODO port from gdx
	public var r:Float = 0;
	public var g:Float = 0;
	public var b:Float = 0;
	public var a:Float = 0;

	public function set2(c:Color) {
		set(c.r, c.g, c.b, c.a);
	}

	public static function copy(c:Color) {
		return new Color(c.r, c.g, c.b, c.a);
	}

	public function add(r, g, b, a) {
		set(
			this.r + r,
			this.g + g,
			this.b + b,
			this.a + a
		);
	}

	public function set(r, g, b, a) {
		this.r = MathUtils.clamp(r, 0, 1);
		this.g = MathUtils.clamp(g, 0, 1);
		this.b = MathUtils.clamp(b, 0, 1);
		this.a = MathUtils.clamp(a, 0, 1);
	}

	public static function valueOf(s) {return new Color(0, 0, 0, 0);}

	public function new(r, g, b, a) {
		set(r, g, b, a);
	}

    /** Returns the color encoded as hex string with the format RRGGBBAA. */
    public function toString():String {
        //var value:String = Integer.toHexString(((int)(255 * r) << 24) | ((int)(255 * g) << 16) | ((int)(255 * b) << 8) | ((int)(255 * a)));
        //while (value.length() < 8) {
            //value = "0" + value;
        //}
        //return value;AAhA
        return (StringTools.hex(colorFloatToInt(a), 2)) + StringTools.hex(colorFloatToInt(r), 2) + StringTools.hex(colorFloatToInt(g), 2) + StringTools.hex(colorFloatToInt(b), 2);
    }

    private function colorFloatToInt(value: Float):Int {
        return Math.round(value * 255);
    }
}
