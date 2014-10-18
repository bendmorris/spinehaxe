#ifndef INCLUDED_openfl_text_FontType
#define INCLUDED_openfl_text_FontType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,text,FontType)
namespace openfl{
namespace text{


class FontType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontType_obj OBJ_;

	public:
		FontType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.text.FontType"); }
		::String __ToString() const { return HX_CSTRING("FontType.") + tag; }

		static ::openfl::text::FontType DEVICE;
		static inline ::openfl::text::FontType DEVICE_dyn() { return DEVICE; }
		static ::openfl::text::FontType EMBEDDED;
		static inline ::openfl::text::FontType EMBEDDED_dyn() { return EMBEDDED; }
		static ::openfl::text::FontType EMBEDDED_CFF;
		static inline ::openfl::text::FontType EMBEDDED_CFF_dyn() { return EMBEDDED_CFF; }
};

} // end namespace openfl
} // end namespace text

#endif /* INCLUDED_openfl_text_FontType */ 
