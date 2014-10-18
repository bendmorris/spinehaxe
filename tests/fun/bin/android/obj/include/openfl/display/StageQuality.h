#ifndef INCLUDED_openfl_display_StageQuality
#define INCLUDED_openfl_display_StageQuality

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,StageQuality)
namespace openfl{
namespace display{


class StageQuality_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageQuality_obj OBJ_;

	public:
		StageQuality_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.StageQuality"); }
		::String __ToString() const { return HX_CSTRING("StageQuality.") + tag; }

		static ::openfl::display::StageQuality BEST;
		static inline ::openfl::display::StageQuality BEST_dyn() { return BEST; }
		static ::openfl::display::StageQuality HIGH;
		static inline ::openfl::display::StageQuality HIGH_dyn() { return HIGH; }
		static ::openfl::display::StageQuality LOW;
		static inline ::openfl::display::StageQuality LOW_dyn() { return LOW; }
		static ::openfl::display::StageQuality MEDIUM;
		static inline ::openfl::display::StageQuality MEDIUM_dyn() { return MEDIUM; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_StageQuality */ 
