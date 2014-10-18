#ifndef INCLUDED_openfl_display_SpreadMethod
#define INCLUDED_openfl_display_SpreadMethod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,SpreadMethod)
namespace openfl{
namespace display{


class SpreadMethod_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SpreadMethod_obj OBJ_;

	public:
		SpreadMethod_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.SpreadMethod"); }
		::String __ToString() const { return HX_CSTRING("SpreadMethod.") + tag; }

		static ::openfl::display::SpreadMethod PAD;
		static inline ::openfl::display::SpreadMethod PAD_dyn() { return PAD; }
		static ::openfl::display::SpreadMethod REFLECT;
		static inline ::openfl::display::SpreadMethod REFLECT_dyn() { return REFLECT; }
		static ::openfl::display::SpreadMethod REPEAT;
		static inline ::openfl::display::SpreadMethod REPEAT_dyn() { return REPEAT; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_SpreadMethod */ 
