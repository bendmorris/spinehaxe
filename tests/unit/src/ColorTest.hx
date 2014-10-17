import haxe.unit.TestCase;

using spinehaxe.Color;

class ColorTest extends TestCase
{
    public function testBasic()
    {
        assertEquals( "A", "A" );
    }

    public function testNameDefinition() 
    {
        var clearColor:Color = Color.CLEAR;
        assertEquals("00000000", clearColor.toString());  
        var whiteColor:Color = Color.WHITE;
        assertEquals("FFFFFFFF", whiteColor.toString());  
        var blackColor:Color = Color.BLACK;
        assertEquals("FF000000", blackColor.toString());  
    }

    public function testColorInit() {
        var color:Color = new Color(0.61, 0.61, 0.61, 1);
        assertEquals("FF9C9C9C", color.toString());  
    }

    //public function testCSSColorInit()
    //{
        //var cssColor:CSSColor = new CSSColor("#F00");
        //assertTrue(Std.is(cssColor, CSSColor));
    //}

    //public function testColor()
    //{
        //var cssColor:CSSColor = new CSSColor("#F00");
        //assertEquals(16711680, cssColor.getColor());
        //var cssColor2:CSSColor = new CSSColor("#FF0000");
        //assertEquals(cssColor2.getColor(), cssColor.getColor());
        //var cssColorRgb:CSSColor = new CSSColor("rgb(255,0,0)");
        //assertEquals(cssColor.getColor(), cssColorRgb.getColor());
        //var cssColorRgb2:CSSColor = new CSSColor("rgb(100%,0%,0%)");
        //assertEquals(cssColor.getColor(), cssColorRgb2.getColor());
        //var cssColorRgba:CSSColor = new CSSColor("rgba(255,0,0,1)");
        //assertEquals(cssColor.getColor(), cssColorRgba.getColor());
        //var cssColorRgba:CSSColor = new CSSColor("rgba(100%,0%,0%,1)");
        //assertEquals(cssColor.getColor(), cssColorRgba.getColor());
        //var cssColorWithName:CSSColor = new CSSColor("red");
        //assertEquals(cssColor.getColor(), cssColorWithName.getColor());
        //var cssColorTransparent:CSSColor = new CSSColor("transparent");
        //assertEquals(cssColorTransparent.getColor(), CSSColor.getColorByName());

        ////
        //var cssColorRgba2:CSSColor = new CSSColor("rgba(255, 0, 0,   1)");
        //assertEquals(cssColor.getColor(), cssColorRgba2.getColor());
    //}

    //public function testToString()
    //{
        //var cssColor:CSSColor = new CSSColor("#F00");
        //assertEquals("#FF0000", cssColor.toString());
        //var cssColorWithAlpha:CSSColor = new CSSColor("rgba(255,0,0,0.2)");
        //assertEquals("rgba(255, 0, 0, 0.2)", cssColorWithAlpha.toString());
    //}

    //public function testDecColorToHEx()
    //{
        //assertEquals("0xFF0000", CSSColor.decColorToHex(16711680)); 
    //}
}
