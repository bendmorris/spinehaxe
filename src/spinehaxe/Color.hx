package spinehaxe;

class Color {
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
}
