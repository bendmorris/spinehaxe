#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
namespace spinehaxe{
namespace atlas{

HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,dispose,)

HX_DEFINE_DYNAMIC_FUNC2(Texture_obj,setWrap,)

HX_DEFINE_DYNAMIC_FUNC2(Texture_obj,setFilter,)


static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("setWrap"),
	HX_CSTRING("setFilter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

#endif

Class Texture_obj::__mClass;

void Texture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.Texture"), hx::TCanCast< Texture_obj> ,0,sMemberFields,
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

void Texture_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
