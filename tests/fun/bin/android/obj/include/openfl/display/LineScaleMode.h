#ifndef INCLUDED_openfl_display_LineScaleMode
#define INCLUDED_openfl_display_LineScaleMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,LineScaleMode)
namespace openfl{
namespace display{


class LineScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineScaleMode_obj OBJ_;

	public:
		LineScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.display.LineScaleMode"); }
		::String __ToString() const { return HX_CSTRING("LineScaleMode.") + tag; }

		static ::openfl::display::LineScaleMode HORIZONTAL;
		static inline ::openfl::display::LineScaleMode HORIZONTAL_dyn() { return HORIZONTAL; }
		static ::openfl::display::LineScaleMode NONE;
		static inline ::openfl::display::LineScaleMode NONE_dyn() { return NONE; }
		static ::openfl::display::LineScaleMode NORMAL;
		static inline ::openfl::display::LineScaleMode NORMAL_dyn() { return NORMAL; }
		static ::openfl::display::LineScaleMode OPENGL;
		static inline ::openfl::display::LineScaleMode OPENGL_dyn() { return OPENGL; }
		static ::openfl::display::LineScaleMode VERTICAL;
		static inline ::openfl::display::LineScaleMode VERTICAL_dyn() { return VERTICAL; }
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_LineScaleMode */ 
