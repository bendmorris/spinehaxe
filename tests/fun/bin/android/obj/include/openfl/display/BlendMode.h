#ifndef INCLUDED_openfl_display_BlendMode
#define INCLUDED_openfl_display_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,BlendMode)
namespace openfl{
namespace display{


class BlendMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BlendMode_obj OBJ_;

	public:
		BlendMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.BlendMode"); }
		::String __ToString() const { return HX_CSTRING("BlendMode.") + tag; }

		static ::openfl::display::BlendMode ADD;
		static inline ::openfl::display::BlendMode ADD_dyn() { return ADD; }
		static ::openfl::display::BlendMode ALPHA;
		static inline ::openfl::display::BlendMode ALPHA_dyn() { return ALPHA; }
		static ::openfl::display::BlendMode DARKEN;
		static inline ::openfl::display::BlendMode DARKEN_dyn() { return DARKEN; }
		static ::openfl::display::BlendMode DIFFERENCE;
		static inline ::openfl::display::BlendMode DIFFERENCE_dyn() { return DIFFERENCE; }
		static ::openfl::display::BlendMode ERASE;
		static inline ::openfl::display::BlendMode ERASE_dyn() { return ERASE; }
		static ::openfl::display::BlendMode HARDLIGHT;
		static inline ::openfl::display::BlendMode HARDLIGHT_dyn() { return HARDLIGHT; }
		static ::openfl::display::BlendMode INVERT;
		static inline ::openfl::display::BlendMode INVERT_dyn() { return INVERT; }
		static ::openfl::display::BlendMode LAYER;
		static inline ::openfl::display::BlendMode LAYER_dyn() { return LAYER; }
		static ::openfl::display::BlendMode LIGHTEN;
		static inline ::openfl::display::BlendMode LIGHTEN_dyn() { return LIGHTEN; }
		static ::openfl::display::BlendMode MULTIPLY;
		static inline ::openfl::display::BlendMode MULTIPLY_dyn() { return MULTIPLY; }
		static ::openfl::display::BlendMode NORMAL;
		static inline ::openfl::display::BlendMode NORMAL_dyn() { return NORMAL; }
		static ::openfl::display::BlendMode OVERLAY;
		static inline ::openfl::display::BlendMode OVERLAY_dyn() { return OVERLAY; }
		static ::openfl::display::BlendMode SCREEN;
		static inline ::openfl::display::BlendMode SCREEN_dyn() { return SCREEN; }
		static ::openfl::display::BlendMode SUBTRACT;
		static inline ::openfl::display::BlendMode SUBTRACT_dyn() { return SUBTRACT; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_BlendMode */ 
