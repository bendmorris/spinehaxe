#ifndef INCLUDED_openfl_display_JointStyle
#define INCLUDED_openfl_display_JointStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,JointStyle)
namespace openfl{
namespace display{


class JointStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef JointStyle_obj OBJ_;

	public:
		JointStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.JointStyle"); }
		::String __ToString() const { return HX_CSTRING("JointStyle.") + tag; }

		static ::openfl::display::JointStyle BEVEL;
		static inline ::openfl::display::JointStyle BEVEL_dyn() { return BEVEL; }
		static ::openfl::display::JointStyle MITER;
		static inline ::openfl::display::JointStyle MITER_dyn() { return MITER; }
		static ::openfl::display::JointStyle ROUND;
		static inline ::openfl::display::JointStyle ROUND_dyn() { return ROUND; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_JointStyle */ 
