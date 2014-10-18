#ifndef INCLUDED_openfl_display_TriangleCulling
#define INCLUDED_openfl_display_TriangleCulling

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,TriangleCulling)
namespace openfl{
namespace display{


class TriangleCulling_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TriangleCulling_obj OBJ_;

	public:
		TriangleCulling_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.TriangleCulling"); }
		::String __ToString() const { return HX_CSTRING("TriangleCulling.") + tag; }

		static ::openfl::display::TriangleCulling NEGATIVE;
		static inline ::openfl::display::TriangleCulling NEGATIVE_dyn() { return NEGATIVE; }
		static ::openfl::display::TriangleCulling NONE;
		static inline ::openfl::display::TriangleCulling NONE_dyn() { return NONE; }
		static ::openfl::display::TriangleCulling POSITIVE;
		static inline ::openfl::display::TriangleCulling POSITIVE_dyn() { return POSITIVE; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_TriangleCulling */ 
