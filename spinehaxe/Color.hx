package spinehaxe;

class Color {

    private static var COLOR_REGEX = ~/^(0x|#)(([A-F0-9]{2}){3,4})$/i;

    public static var CLEAR:Color = new Color(0, 0, 0, 0);
    public static var WHITE:Color = new Color(1, 1, 1, 1);
    public static var BLACK:Color = new Color(0, 0, 0, 1);
    public static var RED:Color = new Color(1, 0, 0, 1);
    public static var GREEN:Color = new Color(0, 1, 0, 1);
    public static var BLUE:Color = new Color(0, 0, 1, 1);
    public static var LIGHT_GRAY:Color = new Color(0.75, 0.75, 0.75, 1);
    public static var GRAY:Color = new Color(0.5, 0.5, 0.5, 1);
    public static var DARK_GRAY:Color = new Color(0.25, 0.25, 0.25, 1);
    public static var PINK:Color = new Color(1, 0.68, 0.68, 1);
    public static var ORANGE:Color = new Color(1, 0.78, 0, 1);
    public static var YELLOW:Color = new Color(1, 1, 0, 1);
    public static var MAGENTA:Color = new Color(1, 0, 1, 1);
    public static var CYAN:Color = new Color(0, 1, 1, 1);
    public static var OLIVE:Color = new Color(0.5, 0.5, 0, 1);
    public static var PURPLE:Color = new Color(0.5, 0, 0.5, 1);
    public static var MAROON:Color = new Color(0.5, 0, 0, 1);
    public static var TEAL:Color = new Color(0, 0.5, 0.5, 1);
    public static var NAVY:Color = new Color(0, 0, 0.5, 1);

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

    /**
     * Parses a String and returns a FlxColor or null if the String couldn't be parsed.
     * Examples (input -> output in hex):
     * 0x00FF00    -> 0xFF00FF00
     * 0xAA4578C2  -> 0xAA4578C2
     * #0000FF     -> 0xFF0000FF
     * #3F000011   -> 0x3F000011
     * GRAY        -> 0xFF808080
     * blue        -> 0xFF0000FF
     * @param   str     The string to be parsed
     * @return  A FlxColor or null if the String couldn't be parsed
     */
    public static function fromString(str:String):Null<Color>
    {
        //var result:Null<Color> = null;
        //str = StringTools.trim(str);
        
        if (str != null) {
            var hex_represent_of_color:Int = parseHex(str);
            return fromDecColor(hex_represent_of_color);
        }
        else return null;
        //if (COLOR_REGEX.match(str)) 
        //{
            //var hexColor:String = "0x" + COLOR_REGEX.matched(2);
            //result = new Color(Std.parseInt(hexColor));
            //if (hexColor.length == 8) 
            //{
                //result.alphaFloat = 1;
            //}
        //}
        //else
        //{
          //TODO: реализация цветов по именам
            //str = str.toUpperCase();
            //for (key in colorLookup.keys())
            //{
                //if (key.toUpperCase() == str)
                //{
                    //result = new Color(colorLookup.get(key));
                    //break;
                //}
            //}
        //}
        
        //return result;
    }

    public static function fromDecColor(color:Int):Null<Color>{
        var r:Float = color >> 24 & 255;
        var g:Float = color >> 16 & 255;
        //var b:Float = color >> 8 & 255;
        var b:Float = (0x0000FF00 & color) >> 8;
        var a:Float = color & 255;
        return new Color(r / 255, g / 255, b / 255, a / 255);
    }

    public static function decColorToHex(color:Int):String {
    // input: (Number) decimal color (i.e. 16711680)
    // returns: (String) hex color (i.e. 0xFF0000)
        return ('0x' + StringTools.hex(color, 8));
    }

    /**
     * Parses an individual hexadecimal string character to the equivalent decimal integer value
     * @param   hex_char hexadecimal character (1-length string)
     * @return  decimal value of hex_char
     */
    
    public static inline function hexChar2dec(hex_char:String):Int {
        var val:Int = -1;
        switch(hex_char) {
            case "0","1","2","3","4","5","6","7","8","9","10":val = Std.parseInt(hex_char);
            case "A","a": val = 10;
            case "B", "b": val = 11; 
            case "C", "c": val = 12; 
            case "D", "d": val = 13; 
            case "E", "e": val = 14; 
            case "F", "f": val = 15; 
        }
        if(val == -1){
            throw "U.hexChar2dec() illegal char(" + hex_char + ")";
        }
        return val;
    }
    
    /**
     * Parses hex string to equivalent integer
     * @param   hex_str string in format RRGGBB or RRGGBBAA (no "0x")
     * @return integer value
     */
    
    public static inline function hex2dec(hex_str:String):Int {
        var length:Int = hex_str.length;
        var place_mult:Int = 1;     
        var sum:Int = 0;
        var i:Int = length - 1; while (i >= 0) {
            var char_hex:String = hex_str.substr(i, 1);
            var char_int:Int = hexChar2dec(char_hex);
            sum += char_int * place_mult;
            place_mult *= 16;
            i--;
        }
        return sum;
    }

    /**
     * Parses hex string to equivalent integer, with safety checks
     * @param  hex_str string in format 0xRRGGBBAA
     * @return integer value
     */
    
    public static inline function parseHex(str:String):Int {
        if (str.indexOf("0x") == 0) {   //if it doesn't start with "0x"
            throw "parseHex() string(" + str + ") does start with \"0x\"!";
        }
        if (str.length != 8) {
            throw "parseHex() string(" + str + ") must be 8(RRGGBBAA) characters long!";
        }

        return hex2dec(str);
        
    }

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
        return (StringTools.hex(colorFloatToInt(r), 2) + StringTools.hex(colorFloatToInt(g), 2) + StringTools.hex(colorFloatToInt(b), 2) +StringTools.hex(colorFloatToInt(a), 2));
    }

    private function colorFloatToInt(value: Float):Int {
        return Math.round(value * 255);
    }
}
