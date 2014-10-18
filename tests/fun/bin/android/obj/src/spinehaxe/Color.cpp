#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_Color
#include <spinehaxe/Color.h>
#endif
namespace spinehaxe{

Void Color_obj::__construct(Float r,Float g,Float b,Float a)
{
HX_STACK_FRAME("spinehaxe.Color","new",0xd0eaf910,"spinehaxe.Color.new","spinehaxe/Color.hx",3,0xb6084161)
HX_STACK_THIS(this)
HX_STACK_ARG(r,"r")
HX_STACK_ARG(g,"g")
HX_STACK_ARG(b,"b")
HX_STACK_ARG(a,"a")
{
	HX_STACK_LINE(30)
	this->a = (int)0;
	HX_STACK_LINE(29)
	this->b = (int)0;
	HX_STACK_LINE(28)
	this->g = (int)0;
	HX_STACK_LINE(27)
	this->r = (int)0;
	HX_STACK_LINE(183)
	this->set(r,g,b,a);
}
;
	return null();
}

//Color_obj::~Color_obj() { }

Dynamic Color_obj::__CreateEmpty() { return  new Color_obj; }
hx::ObjectPtr< Color_obj > Color_obj::__new(Float r,Float g,Float b,Float a)
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct(r,g,b,a);
	return result;}

Dynamic Color_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Color_obj::set2( ::spinehaxe::Color c){
{
		HX_STACK_FRAME("spinehaxe.Color","set2",0xfffd03a0,"spinehaxe.Color.set2","spinehaxe/Color.hx",33,0xb6084161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(33)
		this->set(c->r,c->g,c->b,c->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set2,(void))

Void Color_obj::add( Float r,Float g,Float b,Float a){
{
		HX_STACK_FRAME("spinehaxe.Color","add",0xd0e11ad1,"spinehaxe.Color.add","spinehaxe/Color.hx",41,0xb6084161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(g,"g")
		HX_STACK_ARG(b,"b")
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(41)
		this->set((this->r + r),(this->g + g),(this->b + b),(this->a + a));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Color_obj,add,(void))

Void Color_obj::set( Float r,Float g,Float b,Float a){
{
		HX_STACK_FRAME("spinehaxe.Color","set",0xd0eec452,"spinehaxe.Color.set","spinehaxe/Color.hx",49,0xb6084161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(g,"g")
		HX_STACK_ARG(b,"b")
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(50)
		if (((r < (int)0))){
			HX_STACK_LINE(50)
			this->r = (int)0;
		}
		else{
			HX_STACK_LINE(50)
			if (((r > (int)1))){
				HX_STACK_LINE(50)
				this->r = (int)1;
			}
			else{
				HX_STACK_LINE(50)
				this->r = r;
			}
		}
		HX_STACK_LINE(51)
		if (((g < (int)0))){
			HX_STACK_LINE(51)
			this->g = (int)0;
		}
		else{
			HX_STACK_LINE(51)
			if (((g > (int)1))){
				HX_STACK_LINE(51)
				this->g = (int)1;
			}
			else{
				HX_STACK_LINE(51)
				this->g = g;
			}
		}
		HX_STACK_LINE(52)
		if (((b < (int)0))){
			HX_STACK_LINE(52)
			this->b = (int)0;
		}
		else{
			HX_STACK_LINE(52)
			if (((b > (int)1))){
				HX_STACK_LINE(52)
				this->b = (int)1;
			}
			else{
				HX_STACK_LINE(52)
				this->b = b;
			}
		}
		HX_STACK_LINE(53)
		if (((a < (int)0))){
			HX_STACK_LINE(53)
			this->a = (int)0;
		}
		else{
			HX_STACK_LINE(53)
			if (((a > (int)1))){
				HX_STACK_LINE(53)
				this->a = (int)1;
			}
			else{
				HX_STACK_LINE(53)
				this->a = a;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Color_obj,set,(void))

::String Color_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Color","toString",0x89b629fc,"spinehaxe.Color.toString","spinehaxe/Color.hx",187,0xb6084161)
	HX_STACK_THIS(this)
	HX_STACK_LINE(193)
	int _g = this->colorFloatToInt(this->r);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(193)
	::String _g1 = ::StringTools_obj::hex(_g,(int)2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(193)
	int _g2 = this->colorFloatToInt(this->g);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(193)
	::String _g3 = ::StringTools_obj::hex(_g2,(int)2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(193)
	::String _g4 = (_g1 + _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(193)
	int _g5 = this->colorFloatToInt(this->b);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(193)
	::String _g6 = ::StringTools_obj::hex(_g5,(int)2);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(193)
	::String _g7 = (_g4 + _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(193)
	int _g8 = this->colorFloatToInt(this->a);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(193)
	::String _g9 = ::StringTools_obj::hex(_g8,(int)2);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(193)
	return (_g7 + _g9);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,toString,return )

int Color_obj::colorFloatToInt( Float value){
	HX_STACK_FRAME("spinehaxe.Color","colorFloatToInt",0x611c32eb,"spinehaxe.Color.colorFloatToInt","spinehaxe/Color.hx",197,0xb6084161)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(197)
	return ::Math_obj::round((value * (int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,colorFloatToInt,return )

::EReg Color_obj::COLOR_REGEX;

::spinehaxe::Color Color_obj::CLEAR;

::spinehaxe::Color Color_obj::WHITE;

::spinehaxe::Color Color_obj::BLACK;

::spinehaxe::Color Color_obj::RED;

::spinehaxe::Color Color_obj::GREEN;

::spinehaxe::Color Color_obj::BLUE;

::spinehaxe::Color Color_obj::LIGHT_GRAY;

::spinehaxe::Color Color_obj::GRAY;

::spinehaxe::Color Color_obj::DARK_GRAY;

::spinehaxe::Color Color_obj::PINK;

::spinehaxe::Color Color_obj::ORANGE;

::spinehaxe::Color Color_obj::YELLOW;

::spinehaxe::Color Color_obj::MAGENTA;

::spinehaxe::Color Color_obj::CYAN;

::spinehaxe::Color Color_obj::OLIVE;

::spinehaxe::Color Color_obj::PURPLE;

::spinehaxe::Color Color_obj::MAROON;

::spinehaxe::Color Color_obj::TEAL;

::spinehaxe::Color Color_obj::NAVY;

::spinehaxe::Color Color_obj::copy( ::spinehaxe::Color c){
	HX_STACK_FRAME("spinehaxe.Color","copy",0xf5712d05,"spinehaxe.Color.copy","spinehaxe/Color.hx",37,0xb6084161)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(37)
	return ::spinehaxe::Color_obj::__new(c->r,c->g,c->b,c->a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,copy,return )

::spinehaxe::Color Color_obj::valueOf( Dynamic s){
	HX_STACK_FRAME("spinehaxe.Color","valueOf",0x363d8398,"spinehaxe.Color.valueOf","spinehaxe/Color.hx",56,0xb6084161)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(56)
	return ::spinehaxe::Color_obj::__new((int)0,(int)0,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,valueOf,return )

::spinehaxe::Color Color_obj::fromString( ::String str){
	HX_STACK_FRAME("spinehaxe.Color","fromString",0x09407b2b,"spinehaxe.Color.fromString","spinehaxe/Color.hx",75,0xb6084161)
	HX_STACK_ARG(str,"str")
	HX_STACK_LINE(75)
	if (((str != null()))){
		HX_STACK_LINE(76)
		int hex_represent_of_color;		HX_STACK_VAR(hex_represent_of_color,"hex_represent_of_color");
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			int _g = str.indexOf(HX_CSTRING("0x"),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(76)
			if (((_g == (int)0))){
				HX_STACK_LINE(76)
				HX_STACK_DO_THROW(((HX_CSTRING("parseHex() string(") + str) + HX_CSTRING(") does start with \"0x\"!")));
			}
			HX_STACK_LINE(76)
			if (((str.length != (int)8))){
				HX_STACK_LINE(76)
				HX_STACK_DO_THROW(((HX_CSTRING("parseHex() string(") + str) + HX_CSTRING(") must be 8(RRGGBBAA) characters long!")));
			}
			HX_STACK_LINE(76)
			{
				HX_STACK_LINE(76)
				int length = str.length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(76)
				int place_mult = (int)1;		HX_STACK_VAR(place_mult,"place_mult");
				HX_STACK_LINE(76)
				int sum = (int)0;		HX_STACK_VAR(sum,"sum");
				HX_STACK_LINE(76)
				int i = (length - (int)1);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(76)
				while((true)){
					HX_STACK_LINE(76)
					if ((!(((i >= (int)0))))){
						HX_STACK_LINE(76)
						break;
					}
					HX_STACK_LINE(76)
					::String char_hex = str.substr(i,(int)1);		HX_STACK_VAR(char_hex,"char_hex");
					HX_STACK_LINE(76)
					int char_int;		HX_STACK_VAR(char_int,"char_int");
					HX_STACK_LINE(76)
					{
						HX_STACK_LINE(76)
						int val = (int)-1;		HX_STACK_VAR(val,"val");
						HX_STACK_LINE(76)
						::String _switch_1 = (char_hex);
						if (  ( _switch_1==HX_CSTRING("0")) ||  ( _switch_1==HX_CSTRING("1")) ||  ( _switch_1==HX_CSTRING("2")) ||  ( _switch_1==HX_CSTRING("3")) ||  ( _switch_1==HX_CSTRING("4")) ||  ( _switch_1==HX_CSTRING("5")) ||  ( _switch_1==HX_CSTRING("6")) ||  ( _switch_1==HX_CSTRING("7")) ||  ( _switch_1==HX_CSTRING("8")) ||  ( _switch_1==HX_CSTRING("9")) ||  ( _switch_1==HX_CSTRING("10"))){
							HX_STACK_LINE(76)
							Dynamic _g1 = ::Std_obj::parseInt(char_hex);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(76)
							val = _g1;
						}
						else if (  ( _switch_1==HX_CSTRING("A")) ||  ( _switch_1==HX_CSTRING("a"))){
							HX_STACK_LINE(76)
							val = (int)10;
						}
						else if (  ( _switch_1==HX_CSTRING("B")) ||  ( _switch_1==HX_CSTRING("b"))){
							HX_STACK_LINE(76)
							val = (int)11;
						}
						else if (  ( _switch_1==HX_CSTRING("C")) ||  ( _switch_1==HX_CSTRING("c"))){
							HX_STACK_LINE(76)
							val = (int)12;
						}
						else if (  ( _switch_1==HX_CSTRING("D")) ||  ( _switch_1==HX_CSTRING("d"))){
							HX_STACK_LINE(76)
							val = (int)13;
						}
						else if (  ( _switch_1==HX_CSTRING("E")) ||  ( _switch_1==HX_CSTRING("e"))){
							HX_STACK_LINE(76)
							val = (int)14;
						}
						else if (  ( _switch_1==HX_CSTRING("F")) ||  ( _switch_1==HX_CSTRING("f"))){
							HX_STACK_LINE(76)
							val = (int)15;
						}
						HX_STACK_LINE(76)
						if (((val == (int)-1))){
							HX_STACK_LINE(76)
							HX_STACK_DO_THROW(((HX_CSTRING("U.hexChar2dec() illegal char(") + char_hex) + HX_CSTRING(")")));
						}
						HX_STACK_LINE(76)
						char_int = val;
					}
					HX_STACK_LINE(76)
					hx::AddEq(sum,(char_int * place_mult));
					HX_STACK_LINE(76)
					hx::MultEq(place_mult,(int)16);
					HX_STACK_LINE(76)
					(i)--;
				}
				HX_STACK_LINE(76)
				hex_represent_of_color = sum;
			}
		}
		HX_STACK_LINE(77)
		return ::spinehaxe::Color_obj::fromDecColor(hex_represent_of_color);
	}
	else{
		HX_STACK_LINE(79)
		return null();
	}
	HX_STACK_LINE(75)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,fromString,return )

::spinehaxe::Color Color_obj::fromDecColor( int color){
	HX_STACK_FRAME("spinehaxe.Color","fromDecColor",0x8d18251b,"spinehaxe.Color.fromDecColor","spinehaxe/Color.hx",106,0xb6084161)
	HX_STACK_ARG(color,"color")
	HX_STACK_LINE(107)
	Float r = (int((int(color) >> int((int)24))) & int((int)255));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(108)
	Float g = (int((int(color) >> int((int)16))) & int((int)255));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(110)
	Float b = (int(((int((int)65280) & int(color)))) >> int((int)8));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(111)
	Float a = (int(color) & int((int)255));		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(112)
	return ::spinehaxe::Color_obj::__new((Float(r) / Float((int)255)),(Float(g) / Float((int)255)),(Float(b) / Float((int)255)),(Float(a) / Float((int)255)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,fromDecColor,return )

::String Color_obj::decColorToHex( int color){
	HX_STACK_FRAME("spinehaxe.Color","decColorToHex",0xa1ebb4cf,"spinehaxe.Color.decColorToHex","spinehaxe/Color.hx",115,0xb6084161)
	HX_STACK_ARG(color,"color")
	HX_STACK_LINE(118)
	::String _g = ::StringTools_obj::hex(color,(int)8);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(118)
	return (HX_CSTRING("0x") + _g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,decColorToHex,return )

int Color_obj::hexChar2dec( ::String hex_char){
	HX_STACK_FRAME("spinehaxe.Color","hexChar2dec",0x016e9151,"spinehaxe.Color.hexChar2dec","spinehaxe/Color.hx",127,0xb6084161)
	HX_STACK_ARG(hex_char,"hex_char")
	HX_STACK_LINE(128)
	int val = (int)-1;		HX_STACK_VAR(val,"val");
	HX_STACK_LINE(129)
	::String _switch_2 = (hex_char);
	if (  ( _switch_2==HX_CSTRING("0")) ||  ( _switch_2==HX_CSTRING("1")) ||  ( _switch_2==HX_CSTRING("2")) ||  ( _switch_2==HX_CSTRING("3")) ||  ( _switch_2==HX_CSTRING("4")) ||  ( _switch_2==HX_CSTRING("5")) ||  ( _switch_2==HX_CSTRING("6")) ||  ( _switch_2==HX_CSTRING("7")) ||  ( _switch_2==HX_CSTRING("8")) ||  ( _switch_2==HX_CSTRING("9")) ||  ( _switch_2==HX_CSTRING("10"))){
		HX_STACK_LINE(130)
		Dynamic _g = ::Std_obj::parseInt(hex_char);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(130)
		val = _g;
	}
	else if (  ( _switch_2==HX_CSTRING("A")) ||  ( _switch_2==HX_CSTRING("a"))){
		HX_STACK_LINE(131)
		val = (int)10;
	}
	else if (  ( _switch_2==HX_CSTRING("B")) ||  ( _switch_2==HX_CSTRING("b"))){
		HX_STACK_LINE(132)
		val = (int)11;
	}
	else if (  ( _switch_2==HX_CSTRING("C")) ||  ( _switch_2==HX_CSTRING("c"))){
		HX_STACK_LINE(133)
		val = (int)12;
	}
	else if (  ( _switch_2==HX_CSTRING("D")) ||  ( _switch_2==HX_CSTRING("d"))){
		HX_STACK_LINE(134)
		val = (int)13;
	}
	else if (  ( _switch_2==HX_CSTRING("E")) ||  ( _switch_2==HX_CSTRING("e"))){
		HX_STACK_LINE(135)
		val = (int)14;
	}
	else if (  ( _switch_2==HX_CSTRING("F")) ||  ( _switch_2==HX_CSTRING("f"))){
		HX_STACK_LINE(136)
		val = (int)15;
	}
	HX_STACK_LINE(138)
	if (((val == (int)-1))){
		HX_STACK_LINE(139)
		HX_STACK_DO_THROW(((HX_CSTRING("U.hexChar2dec() illegal char(") + hex_char) + HX_CSTRING(")")));
	}
	HX_STACK_LINE(141)
	return val;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,hexChar2dec,return )

int Color_obj::hex2dec( ::String hex_str){
	HX_STACK_FRAME("spinehaxe.Color","hex2dec",0x460371db,"spinehaxe.Color.hex2dec","spinehaxe/Color.hx",150,0xb6084161)
	HX_STACK_ARG(hex_str,"hex_str")
	HX_STACK_LINE(151)
	int length = hex_str.length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(152)
	int place_mult = (int)1;		HX_STACK_VAR(place_mult,"place_mult");
	HX_STACK_LINE(153)
	int sum = (int)0;		HX_STACK_VAR(sum,"sum");
	HX_STACK_LINE(154)
	int i = (length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(154)
	while((true)){
		HX_STACK_LINE(154)
		if ((!(((i >= (int)0))))){
			HX_STACK_LINE(154)
			break;
		}
		HX_STACK_LINE(155)
		::String char_hex = hex_str.substr(i,(int)1);		HX_STACK_VAR(char_hex,"char_hex");
		HX_STACK_LINE(156)
		int char_int;		HX_STACK_VAR(char_int,"char_int");
		HX_STACK_LINE(156)
		{
			HX_STACK_LINE(156)
			int val = (int)-1;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(156)
			::String _switch_3 = (char_hex);
			if (  ( _switch_3==HX_CSTRING("0")) ||  ( _switch_3==HX_CSTRING("1")) ||  ( _switch_3==HX_CSTRING("2")) ||  ( _switch_3==HX_CSTRING("3")) ||  ( _switch_3==HX_CSTRING("4")) ||  ( _switch_3==HX_CSTRING("5")) ||  ( _switch_3==HX_CSTRING("6")) ||  ( _switch_3==HX_CSTRING("7")) ||  ( _switch_3==HX_CSTRING("8")) ||  ( _switch_3==HX_CSTRING("9")) ||  ( _switch_3==HX_CSTRING("10"))){
				HX_STACK_LINE(156)
				Dynamic _g = ::Std_obj::parseInt(char_hex);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(156)
				val = _g;
			}
			else if (  ( _switch_3==HX_CSTRING("A")) ||  ( _switch_3==HX_CSTRING("a"))){
				HX_STACK_LINE(156)
				val = (int)10;
			}
			else if (  ( _switch_3==HX_CSTRING("B")) ||  ( _switch_3==HX_CSTRING("b"))){
				HX_STACK_LINE(156)
				val = (int)11;
			}
			else if (  ( _switch_3==HX_CSTRING("C")) ||  ( _switch_3==HX_CSTRING("c"))){
				HX_STACK_LINE(156)
				val = (int)12;
			}
			else if (  ( _switch_3==HX_CSTRING("D")) ||  ( _switch_3==HX_CSTRING("d"))){
				HX_STACK_LINE(156)
				val = (int)13;
			}
			else if (  ( _switch_3==HX_CSTRING("E")) ||  ( _switch_3==HX_CSTRING("e"))){
				HX_STACK_LINE(156)
				val = (int)14;
			}
			else if (  ( _switch_3==HX_CSTRING("F")) ||  ( _switch_3==HX_CSTRING("f"))){
				HX_STACK_LINE(156)
				val = (int)15;
			}
			HX_STACK_LINE(156)
			if (((val == (int)-1))){
				HX_STACK_LINE(156)
				HX_STACK_DO_THROW(((HX_CSTRING("U.hexChar2dec() illegal char(") + char_hex) + HX_CSTRING(")")));
			}
			HX_STACK_LINE(156)
			char_int = val;
		}
		HX_STACK_LINE(157)
		hx::AddEq(sum,(char_int * place_mult));
		HX_STACK_LINE(158)
		hx::MultEq(place_mult,(int)16);
		HX_STACK_LINE(159)
		(i)--;
	}
	HX_STACK_LINE(161)
	return sum;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,hex2dec,return )

int Color_obj::parseHex( ::String str){
	HX_STACK_FRAME("spinehaxe.Color","parseHex",0x27b8a5b8,"spinehaxe.Color.parseHex","spinehaxe/Color.hx",170,0xb6084161)
	HX_STACK_ARG(str,"str")
	HX_STACK_LINE(171)
	int _g = str.indexOf(HX_CSTRING("0x"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(171)
	if (((_g == (int)0))){
		HX_STACK_LINE(172)
		HX_STACK_DO_THROW(((HX_CSTRING("parseHex() string(") + str) + HX_CSTRING(") does start with \"0x\"!")));
	}
	HX_STACK_LINE(174)
	if (((str.length != (int)8))){
		HX_STACK_LINE(175)
		HX_STACK_DO_THROW(((HX_CSTRING("parseHex() string(") + str) + HX_CSTRING(") must be 8(RRGGBBAA) characters long!")));
	}
	HX_STACK_LINE(178)
	int length = str.length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(178)
	int place_mult = (int)1;		HX_STACK_VAR(place_mult,"place_mult");
	HX_STACK_LINE(178)
	int sum = (int)0;		HX_STACK_VAR(sum,"sum");
	HX_STACK_LINE(178)
	int i = (length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(178)
	while((true)){
		HX_STACK_LINE(178)
		if ((!(((i >= (int)0))))){
			HX_STACK_LINE(178)
			break;
		}
		HX_STACK_LINE(178)
		::String char_hex = str.substr(i,(int)1);		HX_STACK_VAR(char_hex,"char_hex");
		HX_STACK_LINE(178)
		int char_int;		HX_STACK_VAR(char_int,"char_int");
		HX_STACK_LINE(178)
		{
			HX_STACK_LINE(178)
			int val = (int)-1;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(178)
			::String _switch_4 = (char_hex);
			if (  ( _switch_4==HX_CSTRING("0")) ||  ( _switch_4==HX_CSTRING("1")) ||  ( _switch_4==HX_CSTRING("2")) ||  ( _switch_4==HX_CSTRING("3")) ||  ( _switch_4==HX_CSTRING("4")) ||  ( _switch_4==HX_CSTRING("5")) ||  ( _switch_4==HX_CSTRING("6")) ||  ( _switch_4==HX_CSTRING("7")) ||  ( _switch_4==HX_CSTRING("8")) ||  ( _switch_4==HX_CSTRING("9")) ||  ( _switch_4==HX_CSTRING("10"))){
				HX_STACK_LINE(178)
				Dynamic _g1 = ::Std_obj::parseInt(char_hex);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(178)
				val = _g1;
			}
			else if (  ( _switch_4==HX_CSTRING("A")) ||  ( _switch_4==HX_CSTRING("a"))){
				HX_STACK_LINE(178)
				val = (int)10;
			}
			else if (  ( _switch_4==HX_CSTRING("B")) ||  ( _switch_4==HX_CSTRING("b"))){
				HX_STACK_LINE(178)
				val = (int)11;
			}
			else if (  ( _switch_4==HX_CSTRING("C")) ||  ( _switch_4==HX_CSTRING("c"))){
				HX_STACK_LINE(178)
				val = (int)12;
			}
			else if (  ( _switch_4==HX_CSTRING("D")) ||  ( _switch_4==HX_CSTRING("d"))){
				HX_STACK_LINE(178)
				val = (int)13;
			}
			else if (  ( _switch_4==HX_CSTRING("E")) ||  ( _switch_4==HX_CSTRING("e"))){
				HX_STACK_LINE(178)
				val = (int)14;
			}
			else if (  ( _switch_4==HX_CSTRING("F")) ||  ( _switch_4==HX_CSTRING("f"))){
				HX_STACK_LINE(178)
				val = (int)15;
			}
			HX_STACK_LINE(178)
			if (((val == (int)-1))){
				HX_STACK_LINE(178)
				HX_STACK_DO_THROW(((HX_CSTRING("U.hexChar2dec() illegal char(") + char_hex) + HX_CSTRING(")")));
			}
			HX_STACK_LINE(178)
			char_int = val;
		}
		HX_STACK_LINE(178)
		hx::AddEq(sum,(char_int * place_mult));
		HX_STACK_LINE(178)
		hx::MultEq(place_mult,(int)16);
		HX_STACK_LINE(178)
		(i)--;
	}
	HX_STACK_LINE(178)
	return sum;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,parseHex,return )


Color_obj::Color_obj()
{
}

Dynamic Color_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { return RED; }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { return BLUE; }
		if (HX_FIELD_EQ(inName,"GRAY") ) { return GRAY; }
		if (HX_FIELD_EQ(inName,"PINK") ) { return PINK; }
		if (HX_FIELD_EQ(inName,"CYAN") ) { return CYAN; }
		if (HX_FIELD_EQ(inName,"TEAL") ) { return TEAL; }
		if (HX_FIELD_EQ(inName,"NAVY") ) { return NAVY; }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"set2") ) { return set2_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CLEAR") ) { return CLEAR; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { return WHITE; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { return BLACK; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { return GREEN; }
		if (HX_FIELD_EQ(inName,"OLIVE") ) { return OLIVE; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ORANGE") ) { return ORANGE; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { return YELLOW; }
		if (HX_FIELD_EQ(inName,"PURPLE") ) { return PURPLE; }
		if (HX_FIELD_EQ(inName,"MAROON") ) { return MAROON; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"MAGENTA") ) { return MAGENTA; }
		if (HX_FIELD_EQ(inName,"valueOf") ) { return valueOf_dyn(); }
		if (HX_FIELD_EQ(inName,"hex2dec") ) { return hex2dec_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"parseHex") ) { return parseHex_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"DARK_GRAY") ) { return DARK_GRAY; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LIGHT_GRAY") ) { return LIGHT_GRAY; }
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"COLOR_REGEX") ) { return COLOR_REGEX; }
		if (HX_FIELD_EQ(inName,"hexChar2dec") ) { return hexChar2dec_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"fromDecColor") ) { return fromDecColor_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"decColorToHex") ) { return decColorToHex_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"colorFloatToInt") ) { return colorFloatToInt_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Color_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { RED=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { BLUE=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GRAY") ) { GRAY=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PINK") ) { PINK=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CYAN") ) { CYAN=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TEAL") ) { TEAL=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NAVY") ) { NAVY=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CLEAR") ) { CLEAR=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { WHITE=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { BLACK=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { GREEN=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OLIVE") ) { OLIVE=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ORANGE") ) { ORANGE=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { YELLOW=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PURPLE") ) { PURPLE=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAROON") ) { MAROON=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"MAGENTA") ) { MAGENTA=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"DARK_GRAY") ) { DARK_GRAY=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LIGHT_GRAY") ) { LIGHT_GRAY=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"COLOR_REGEX") ) { COLOR_REGEX=inValue.Cast< ::EReg >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Color_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("COLOR_REGEX"),
	HX_CSTRING("CLEAR"),
	HX_CSTRING("WHITE"),
	HX_CSTRING("BLACK"),
	HX_CSTRING("RED"),
	HX_CSTRING("GREEN"),
	HX_CSTRING("BLUE"),
	HX_CSTRING("LIGHT_GRAY"),
	HX_CSTRING("GRAY"),
	HX_CSTRING("DARK_GRAY"),
	HX_CSTRING("PINK"),
	HX_CSTRING("ORANGE"),
	HX_CSTRING("YELLOW"),
	HX_CSTRING("MAGENTA"),
	HX_CSTRING("CYAN"),
	HX_CSTRING("OLIVE"),
	HX_CSTRING("PURPLE"),
	HX_CSTRING("MAROON"),
	HX_CSTRING("TEAL"),
	HX_CSTRING("NAVY"),
	HX_CSTRING("copy"),
	HX_CSTRING("valueOf"),
	HX_CSTRING("fromString"),
	HX_CSTRING("fromDecColor"),
	HX_CSTRING("decColorToHex"),
	HX_CSTRING("hexChar2dec"),
	HX_CSTRING("hex2dec"),
	HX_CSTRING("parseHex"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Color_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(Color_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(Color_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(Color_obj,a),HX_CSTRING("a")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("set2"),
	HX_CSTRING("add"),
	HX_CSTRING("set"),
	HX_CSTRING("toString"),
	HX_CSTRING("colorFloatToInt"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Color_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Color_obj::COLOR_REGEX,"COLOR_REGEX");
	HX_MARK_MEMBER_NAME(Color_obj::CLEAR,"CLEAR");
	HX_MARK_MEMBER_NAME(Color_obj::WHITE,"WHITE");
	HX_MARK_MEMBER_NAME(Color_obj::BLACK,"BLACK");
	HX_MARK_MEMBER_NAME(Color_obj::RED,"RED");
	HX_MARK_MEMBER_NAME(Color_obj::GREEN,"GREEN");
	HX_MARK_MEMBER_NAME(Color_obj::BLUE,"BLUE");
	HX_MARK_MEMBER_NAME(Color_obj::LIGHT_GRAY,"LIGHT_GRAY");
	HX_MARK_MEMBER_NAME(Color_obj::GRAY,"GRAY");
	HX_MARK_MEMBER_NAME(Color_obj::DARK_GRAY,"DARK_GRAY");
	HX_MARK_MEMBER_NAME(Color_obj::PINK,"PINK");
	HX_MARK_MEMBER_NAME(Color_obj::ORANGE,"ORANGE");
	HX_MARK_MEMBER_NAME(Color_obj::YELLOW,"YELLOW");
	HX_MARK_MEMBER_NAME(Color_obj::MAGENTA,"MAGENTA");
	HX_MARK_MEMBER_NAME(Color_obj::CYAN,"CYAN");
	HX_MARK_MEMBER_NAME(Color_obj::OLIVE,"OLIVE");
	HX_MARK_MEMBER_NAME(Color_obj::PURPLE,"PURPLE");
	HX_MARK_MEMBER_NAME(Color_obj::MAROON,"MAROON");
	HX_MARK_MEMBER_NAME(Color_obj::TEAL,"TEAL");
	HX_MARK_MEMBER_NAME(Color_obj::NAVY,"NAVY");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Color_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Color_obj::COLOR_REGEX,"COLOR_REGEX");
	HX_VISIT_MEMBER_NAME(Color_obj::CLEAR,"CLEAR");
	HX_VISIT_MEMBER_NAME(Color_obj::WHITE,"WHITE");
	HX_VISIT_MEMBER_NAME(Color_obj::BLACK,"BLACK");
	HX_VISIT_MEMBER_NAME(Color_obj::RED,"RED");
	HX_VISIT_MEMBER_NAME(Color_obj::GREEN,"GREEN");
	HX_VISIT_MEMBER_NAME(Color_obj::BLUE,"BLUE");
	HX_VISIT_MEMBER_NAME(Color_obj::LIGHT_GRAY,"LIGHT_GRAY");
	HX_VISIT_MEMBER_NAME(Color_obj::GRAY,"GRAY");
	HX_VISIT_MEMBER_NAME(Color_obj::DARK_GRAY,"DARK_GRAY");
	HX_VISIT_MEMBER_NAME(Color_obj::PINK,"PINK");
	HX_VISIT_MEMBER_NAME(Color_obj::ORANGE,"ORANGE");
	HX_VISIT_MEMBER_NAME(Color_obj::YELLOW,"YELLOW");
	HX_VISIT_MEMBER_NAME(Color_obj::MAGENTA,"MAGENTA");
	HX_VISIT_MEMBER_NAME(Color_obj::CYAN,"CYAN");
	HX_VISIT_MEMBER_NAME(Color_obj::OLIVE,"OLIVE");
	HX_VISIT_MEMBER_NAME(Color_obj::PURPLE,"PURPLE");
	HX_VISIT_MEMBER_NAME(Color_obj::MAROON,"MAROON");
	HX_VISIT_MEMBER_NAME(Color_obj::TEAL,"TEAL");
	HX_VISIT_MEMBER_NAME(Color_obj::NAVY,"NAVY");
};

#endif

Class Color_obj::__mClass;

void Color_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Color"), hx::TCanCast< Color_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Color_obj::__boot()
{
	COLOR_REGEX= ::EReg_obj::__new(HX_CSTRING("^(0x|#)(([A-F0-9]{2}){3,4})$"),HX_CSTRING("i"));
	CLEAR= ::spinehaxe::Color_obj::__new((int)0,(int)0,(int)0,(int)0);
	WHITE= ::spinehaxe::Color_obj::__new((int)1,(int)1,(int)1,(int)1);
	BLACK= ::spinehaxe::Color_obj::__new((int)0,(int)0,(int)0,(int)1);
	RED= ::spinehaxe::Color_obj::__new((int)1,(int)0,(int)0,(int)1);
	GREEN= ::spinehaxe::Color_obj::__new((int)0,(int)1,(int)0,(int)1);
	BLUE= ::spinehaxe::Color_obj::__new((int)0,(int)0,(int)1,(int)1);
	LIGHT_GRAY= ::spinehaxe::Color_obj::__new(0.75,0.75,0.75,(int)1);
	GRAY= ::spinehaxe::Color_obj::__new(0.5,0.5,0.5,(int)1);
	DARK_GRAY= ::spinehaxe::Color_obj::__new(0.25,0.25,0.25,(int)1);
	PINK= ::spinehaxe::Color_obj::__new((int)1,0.68,0.68,(int)1);
	ORANGE= ::spinehaxe::Color_obj::__new((int)1,0.78,(int)0,(int)1);
	YELLOW= ::spinehaxe::Color_obj::__new((int)1,(int)1,(int)0,(int)1);
	MAGENTA= ::spinehaxe::Color_obj::__new((int)1,(int)0,(int)1,(int)1);
	CYAN= ::spinehaxe::Color_obj::__new((int)0,(int)1,(int)1,(int)1);
	OLIVE= ::spinehaxe::Color_obj::__new(0.5,0.5,(int)0,(int)1);
	PURPLE= ::spinehaxe::Color_obj::__new(0.5,(int)0,0.5,(int)1);
	MAROON= ::spinehaxe::Color_obj::__new(0.5,(int)0,(int)0,(int)1);
	TEAL= ::spinehaxe::Color_obj::__new((int)0,0.5,0.5,(int)1);
	NAVY= ::spinehaxe::Color_obj::__new((int)0,(int)0,0.5,(int)1);
}

} // end namespace spinehaxe
