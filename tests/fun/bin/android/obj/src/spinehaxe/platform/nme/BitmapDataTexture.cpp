#include <hxcpp.h>

#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTexture
#include <spinehaxe/platform/nme/BitmapDataTexture.h>
#endif
namespace spinehaxe{
namespace platform{
namespace nme{

Void BitmapDataTexture_obj::__construct(::String textureFile)
{
HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","new",0x1da60896,"spinehaxe.platform.nme.BitmapDataTexture.new","spinehaxe/platform/nme/BitmapDataTexture.hx",16,0xc6dd19fb)
HX_STACK_THIS(this)
HX_STACK_ARG(textureFile,"textureFile")
{
	HX_STACK_LINE(17)
	::openfl::display::BitmapData _g = ::openfl::Assets_obj::getBitmapData(textureFile,null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(17)
	this->bd = _g;
}
;
	return null();
}

//BitmapDataTexture_obj::~BitmapDataTexture_obj() { }

Dynamic BitmapDataTexture_obj::__CreateEmpty() { return  new BitmapDataTexture_obj; }
hx::ObjectPtr< BitmapDataTexture_obj > BitmapDataTexture_obj::__new(::String textureFile)
{  hx::ObjectPtr< BitmapDataTexture_obj > result = new BitmapDataTexture_obj();
	result->__construct(textureFile);
	return result;}

Dynamic BitmapDataTexture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapDataTexture_obj > result = new BitmapDataTexture_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *BitmapDataTexture_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::atlas::Texture_obj)) return operator ::spinehaxe::atlas::Texture_obj *();
	return super::__ToInterface(inType);
}

int BitmapDataTexture_obj::get_width( ){
	HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","get_width",0x6c5f5713,"spinehaxe.platform.nme.BitmapDataTexture.get_width","spinehaxe/platform/nme/BitmapDataTexture.hx",20,0xc6dd19fb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	return this->bd->get_width();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapDataTexture_obj,get_width,return )

int BitmapDataTexture_obj::get_height( ){
	HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","get_height",0x1d5c523a,"spinehaxe.platform.nme.BitmapDataTexture.get_height","spinehaxe/platform/nme/BitmapDataTexture.hx",23,0xc6dd19fb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(23)
	return this->bd->get_height();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapDataTexture_obj,get_height,return )

Void BitmapDataTexture_obj::dispose( ){
{
		HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","dispose",0x71be0bd5,"spinehaxe.platform.nme.BitmapDataTexture.dispose","spinehaxe/platform/nme/BitmapDataTexture.hx",25,0xc6dd19fb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(25)
		this->bd->dispose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapDataTexture_obj,dispose,(void))

Void BitmapDataTexture_obj::setWrap( ::String uWrap,::String vWrap){
{
		HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","setWrap",0xcaf505c2,"spinehaxe.platform.nme.BitmapDataTexture.setWrap","spinehaxe/platform/nme/BitmapDataTexture.hx",26,0xc6dd19fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(uWrap,"uWrap")
		HX_STACK_ARG(vWrap,"vWrap")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapDataTexture_obj,setWrap,(void))

Void BitmapDataTexture_obj::setFilter( ::String minFilter,::String magFilter){
{
		HX_STACK_FRAME("spinehaxe.platform.nme.BitmapDataTexture","setFilter",0x432fd9b0,"spinehaxe.platform.nme.BitmapDataTexture.setFilter","spinehaxe/platform/nme/BitmapDataTexture.hx",27,0xc6dd19fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(minFilter,"minFilter")
		HX_STACK_ARG(magFilter,"magFilter")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapDataTexture_obj,setFilter,(void))


BitmapDataTexture_obj::BitmapDataTexture_obj()
{
}

void BitmapDataTexture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapDataTexture);
	HX_MARK_MEMBER_NAME(bd,"bd");
	HX_MARK_END_CLASS();
}

void BitmapDataTexture_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bd,"bd");
}

Dynamic BitmapDataTexture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"bd") ) { return bd; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"setWrap") ) { return setWrap_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"setFilter") ) { return setFilter_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapDataTexture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"bd") ) { bd=inValue.Cast< ::openfl::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapDataTexture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("bd"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::display::BitmapData*/ ,(int)offsetof(BitmapDataTexture_obj,bd),HX_CSTRING("bd")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bd"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("dispose"),
	HX_CSTRING("setWrap"),
	HX_CSTRING("setFilter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapDataTexture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapDataTexture_obj::__mClass,"__mClass");
};

#endif

Class BitmapDataTexture_obj::__mClass;

void BitmapDataTexture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.platform.nme.BitmapDataTexture"), hx::TCanCast< BitmapDataTexture_obj> ,sStaticFields,sMemberFields,
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

void BitmapDataTexture_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme
