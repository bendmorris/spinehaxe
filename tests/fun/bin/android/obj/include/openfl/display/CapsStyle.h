#ifndef INCLUDED_openfl_display_CapsStyle
#define INCLUDED_openfl_display_CapsStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,CapsStyle)
namespace openfl{
namespace display{


class CapsStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CapsStyle_obj OBJ_;

	public:
		CapsStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.CapsStyle"); }
		::String __ToString() const { return HX_CSTRING("CapsStyle.") + tag; }

		static ::openfl::display::CapsStyle NONE;
		static inline ::openfl::display::CapsStyle NONE_dyn() { return NONE; }
		static ::openfl::display::CapsStyle ROUND;
		static inline ::openfl::display::CapsStyle ROUND_dyn() { return ROUND; }
		static ::openfl::display::CapsStyle SQUARE;
		static inline ::openfl::display::CapsStyle SQUARE_dyn() { return SQUARE; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_CapsStyle */ 
