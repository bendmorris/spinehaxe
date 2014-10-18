#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureLoader
#include <spinehaxe/atlas/TextureLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTexture
#include <spinehaxe/platform/nme/BitmapDataTexture.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTextureLoader
#include <spinehaxe/platform/nme/BitmapDataTextureLoader.h>
#endif
namespace spinehaxe{
namespace platform{
namespace nme{

Void BitmapDataTextureLoader_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTextureLoader","new",0x6caead49,"spinehaxe.platform.nme.BitmapDataTextureLoader.new","spinehaxe/platform/nme/BitmapDataTextureLoader.hx",6,0x23a54b68)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//BitmapDataTextureLoader_obj::~BitmapDataTextureLoader_obj() { }

Dynamic BitmapDataTextureLoader_obj::__CreateEmpty() { return  new BitmapDataTextureLoader_obj; }
hx::ObjectPtr< BitmapDataTextureLoader_obj > BitmapDataTextureLoader_obj::__new()
{  hx::ObjectPtr< BitmapDataTextureLoader_obj > result = new BitmapDataTextureLoader_obj();
	result->__construct();
	return result;}

Dynamic BitmapDataTextureLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapDataTextureLoader_obj > result = new BitmapDataTextureLoader_obj();
	result->__construct();
	return result;}

hx::Object *BitmapDataTextureLoader_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::atlas::TextureLoader_obj)) return operator ::spinehaxe::atlas::TextureLoader_obj *();
	return super::__ToInterface(inType);
}

::spinehaxe::atlas::Texture BitmapDataTextureLoader_obj::loadTexture( ::String textureFile,::String format,bool useMipMaps){
	HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTextureLoader","loadTexture",0x39cdf53e,"spinehaxe.platform.nme.BitmapDataTextureLoader.loadTexture","spinehaxe/platform/nme/BitmapDataTextureLoader.hx",10,0x23a54b68)
	HX_STACK_THIS(this)
	HX_STACK_ARG(textureFile,"textureFile")
	HX_STACK_ARG(format,"format")
	HX_STACK_ARG(useMipMaps,"useMipMaps")
	HX_STACK_LINE(10)
	return ::spinehaxe::platform::nme::BitmapDataTexture_obj::__new(textureFile);
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapDataTextureLoader_obj,loadTexture,return )


BitmapDataTextureLoader_obj::BitmapDataTextureLoader_obj()
{
}

Dynamic BitmapDataTextureLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"loadTexture") ) { return loadTexture_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapDataTextureLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapDataTextureLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("loadTexture"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapDataTextureLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapDataTextureLoader_obj::__mClass,"__mClass");
};

#endif

Class BitmapDataTextureLoader_obj::__mClass;

void BitmapDataTextureLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.platform.nme.BitmapDataTextureLoader"), hx::TCanCast< BitmapDataTextureLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void BitmapDataTextureLoader_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme
