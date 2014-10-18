#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_geom_ColorTransform
#include <openfl/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
namespace openfl{
namespace display{

HX_DEFINE_DYNAMIC_FUNC6(IBitmapDrawable_obj,__drawToSurface,)


static ::String sMemberFields[] = {
	HX_CSTRING("__drawToSurface"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IBitmapDrawable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IBitmapDrawable_obj::__mClass,"__mClass");
};

#endif

Class IBitmapDrawable_obj::__mClass;

void IBitmapDrawable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.IBitmapDrawable"), hx::TCanCast< IBitmapDrawable_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void IBitmapDrawable_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
