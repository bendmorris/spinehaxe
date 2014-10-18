#ifndef INCLUDED_openfl_text_FontStyle
#define INCLUDED_openfl_text_FontStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,text,FontStyle)
namespace openfl{
namespace text{


class FontStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontStyle_obj OBJ_;

	public:
		FontStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.text.FontStyle"); }
		::String __ToString() const { return HX_CSTRING("FontStyle.") + tag; }

		static ::openfl::text::FontStyle BOLD;
		static inline ::openfl::text::FontStyle BOLD_dyn() { return BOLD; }
		static ::openfl::text::FontStyle BOLD_ITALIC;
		static inline ::openfl::text::FontStyle BOLD_ITALIC_dyn() { return BOLD_ITALIC; }
		static ::openfl::text::FontStyle ITALIC;
		static inline ::openfl::text::FontStyle ITALIC_dyn() { return ITALIC; }
		static ::openfl::text::FontStyle REGULAR;
		static inline ::openfl::text::FontStyle REGULAR_dyn() { return REGULAR; }
};

} // end namespace openfl
} // end namespace text

#endif /* INCLUDED_openfl_text_FontStyle */ 
