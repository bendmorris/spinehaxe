import haxe.unit.TestCase;

using spinehaxe.Color;

class ColorTest extends TestCase
{
    public function testNameDefinition() 
    {
        assertEquals("00000000", Color.CLEAR.toString());  
        assertEquals("FFFFFFFF", Color.WHITE.toString());  
        assertEquals("000000FF", Color.BLACK.toString());  
        assertEquals("FF0000FF", Color.RED.toString());  
        assertEquals("00FF00FF", Color.GREEN.toString());  
        assertEquals("0000FFFF", Color.BLUE.toString());  
        assertEquals("BFBFBFFF", Color.LIGHT_GRAY.toString());  
    }

    public function testCreateNewColor() {
        assertEquals(new Color(1, 0, 0, 0).r, 1); 
        assertEquals(new Color(0, 1, 0, 0).r, 0); 
        assertEquals(new Color(0, 1, 0, 0).g, 1); 
        assertEquals(new Color(0, 0, 1, 0).g, 0); 
        assertEquals(new Color(0, 0, 1, 0).b, 1); 
        assertEquals(new Color(0, 0, 0, 1).a, 1); 
    }

    public function testColorFromString() {
        // red = 0, green = 1, blue = 0, alpha = 0
        var color:Color = new Color(0, 1, 0, 0);
        assertEquals(Color.fromString("00FF0000").r, color.r); 
        assertEquals(Color.fromString("00FF0000").g, color.g); 
        assertEquals(Color.fromString("00FF0000").b, color.b); 
        assertEquals(Color.fromString("00FF0000").a, color.a); 
        assertEquals(Color.fromString("00FF0000").toString(), color.toString()); 
        //assertEquals(Color.fromDecColor(Color.hex2dec("00ff04ff")).r, 0); 
        //assertEquals(Color.fromDecColor(Color.hex2dec("00ff04ff")).g, 1); 
        //assertEquals(Color.fromDecColor(Color.hex2dec("00ff04ff")).b, 0.015); 
        //assertEquals(Color.fromDecColor(Color.hex2dec("00ff04ff")).a, 1); 
    }

    public function testColorToString() {
        var color:Color = new Color(0.61, 0.61, 0.61, 1);
        assertEquals("9C9C9CFF", color.toString());  
    }

    public function testDecColortoHex() {
        assertEquals("0x00FF0000", Color.decColorToHex(16711680)); 
        assertEquals("0xFF0000FF", Color.decColorToHex(-16776961)); 
    }

    public function testFromDecColor() {
        var color:Color = Color.fromDecColor(16711680);
        assertEquals(0.0, color.r);  
        assertEquals(1.0, color.g);  
        assertEquals(0.0, color.b);  
        assertEquals(0.0, color.a);

        var color:Color = Color.fromDecColor(255);
        assertEquals(0.0, color.r);  
        assertEquals(0.0, color.g);  
        assertEquals(0.0, color.b);  
        assertEquals(1.0, color.a);  

        var color:Color = Color.fromDecColor(65280);
        assertEquals(0.0, color.r);  
        assertEquals(0.0, color.g);  
        assertEquals(1.0, color.b);  
        assertEquals(0.0, color.a);
    }

    public function testParseHex() {
        assertEquals(Color.parseHex("000000FF"), 255);
    }

    public function testHex2dec() {
        assertEquals(Color.hex2dec("FF0000"), 16711680);
        assertEquals(Color.hex2dec("FF0000FF"), -16776961);
        assertEquals(Color.hex2dec("000000FF"), 255);
        assertEquals(Color.hex2dec("0000FF00"), 65280);
    }

    public function testColorType()
    {
        var myColor:Color = new Color(0, 1, 1, 1);
        assertTrue(Std.is(myColor, Color));
    }
}
