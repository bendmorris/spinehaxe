#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureLoader
#include <spinehaxe/atlas/TextureLoader.h>
#endif
namespace spinehaxe{
namespace atlas{

HX_DEFINE_DYNAMIC_FUNC3(TextureLoader_obj,loadTexture,return )


static ::String sMemberFields[] = {
	HX_CSTRING("loadTexture"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureLoader_obj::__mClass,"__mClass");
};

#endif

Class TextureLoader_obj::__mClass;

void TextureLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.TextureLoader"), hx::TCanCast< TextureLoader_obj> ,0,sMemberFields,
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

void TextureLoader_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
