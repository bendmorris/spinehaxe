#ifndef INCLUDED_spinehaxe_Color
#define INCLUDED_spinehaxe_Color

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS1(spinehaxe,Color)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Color_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Color_obj OBJ_;
		Color_obj();
		Void __construct(Float r,Float g,Float b,Float a);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Color_obj > __new(Float r,Float g,Float b,Float a);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Color_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Color"); }

		Float r;
		Float g;
		Float b;
		Float a;
		virtual Void set2( ::spinehaxe::Color c);
		Dynamic set2_dyn();

		virtual Void add( Float r,Float g,Float b,Float a);
		Dynamic add_dyn();

		virtual Void set( Float r,Float g,Float b,Float a);
		Dynamic set_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual int colorFloatToInt( Float value);
		Dynamic colorFloatToInt_dyn();

		static ::EReg COLOR_REGEX;
		static ::spinehaxe::Color CLEAR;
		static ::spinehaxe::Color WHITE;
		static ::spinehaxe::Color BLACK;
		static ::spinehaxe::Color RED;
		static ::spinehaxe::Color GREEN;
		static ::spinehaxe::Color BLUE;
		static ::spinehaxe::Color LIGHT_GRAY;
		static ::spinehaxe::Color GRAY;
		static ::spinehaxe::Color DARK_GRAY;
		static ::spinehaxe::Color PINK;
		static ::spinehaxe::Color ORANGE;
		static ::spinehaxe::Color YELLOW;
		static ::spinehaxe::Color MAGENTA;
		static ::spinehaxe::Color CYAN;
		static ::spinehaxe::Color OLIVE;
		static ::spinehaxe::Color PURPLE;
		static ::spinehaxe::Color MAROON;
		static ::spinehaxe::Color TEAL;
		static ::spinehaxe::Color NAVY;
		static ::spinehaxe::Color copy( ::spinehaxe::Color c);
		static Dynamic copy_dyn();

		static ::spinehaxe::Color valueOf( Dynamic s);
		static Dynamic valueOf_dyn();

		static ::spinehaxe::Color fromString( ::String str);
		static Dynamic fromString_dyn();

		static ::spinehaxe::Color fromDecColor( int color);
		static Dynamic fromDecColor_dyn();

		static ::String decColorToHex( int color);
		static Dynamic decColorToHex_dyn();

		static int hexChar2dec( ::String hex_char);
		static Dynamic hexChar2dec_dyn();

		static int hex2dec( ::String hex_str);
		static Dynamic hex2dec_dyn();

		static int parseHex( ::String str);
		static Dynamic parseHex_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Color */ 
