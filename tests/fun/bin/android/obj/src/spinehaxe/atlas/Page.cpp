#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_atlas_Page
#include <spinehaxe/atlas/Page.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
namespace spinehaxe{
namespace atlas{

Void Page_obj::__construct(::String textureFile,bool useMipMaps,::String format,::String minFilter,::String magFilter,::String uWrap,::String vWrap)
{
HX_STACK_FRAME("spinehaxe.atlas.Page","new",0x48d63729,"spinehaxe.atlas.Page.new","spinehaxe/atlas/TextureAtlas.hx",42,0xde245664)
HX_STACK_THIS(this)
HX_STACK_ARG(textureFile,"textureFile")
HX_STACK_ARG(useMipMaps,"useMipMaps")
HX_STACK_ARG(format,"format")
HX_STACK_ARG(minFilter,"minFilter")
HX_STACK_ARG(magFilter,"magFilter")
HX_STACK_ARG(uWrap,"uWrap")
HX_STACK_ARG(vWrap,"vWrap")
{
	HX_STACK_LINE(43)
	this->textureFile = textureFile;
	HX_STACK_LINE(44)
	this->useMipMaps = useMipMaps;
	HX_STACK_LINE(45)
	this->format = format;
	HX_STACK_LINE(46)
	this->minFilter = minFilter;
	HX_STACK_LINE(47)
	this->magFilter = magFilter;
	HX_STACK_LINE(48)
	this->uWrap = uWrap;
	HX_STACK_LINE(49)
	this->vWrap = vWrap;
}
;
	return null();
}

//Page_obj::~Page_obj() { }

Dynamic Page_obj::__CreateEmpty() { return  new Page_obj; }
hx::ObjectPtr< Page_obj > Page_obj::__new(::String textureFile,bool useMipMaps,::String format,::String minFilter,::String magFilter,::String uWrap,::String vWrap)
{  hx::ObjectPtr< Page_obj > result = new Page_obj();
	result->__construct(textureFile,useMipMaps,format,minFilter,magFilter,uWrap,vWrap);
	return result;}

Dynamic Page_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Page_obj > result = new Page_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}


Page_obj::Page_obj()
{
}

void Page_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Page);
	HX_MARK_MEMBER_NAME(textureFile,"textureFile");
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(useMipMaps,"useMipMaps");
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(minFilter,"minFilter");
	HX_MARK_MEMBER_NAME(magFilter,"magFilter");
	HX_MARK_MEMBER_NAME(uWrap,"uWrap");
	HX_MARK_MEMBER_NAME(vWrap,"vWrap");
	HX_MARK_END_CLASS();
}

void Page_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(textureFile,"textureFile");
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(useMipMaps,"useMipMaps");
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(minFilter,"minFilter");
	HX_VISIT_MEMBER_NAME(magFilter,"magFilter");
	HX_VISIT_MEMBER_NAME(uWrap,"uWrap");
	HX_VISIT_MEMBER_NAME(vWrap,"vWrap");
}

Dynamic Page_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"uWrap") ) { return uWrap; }
		if (HX_FIELD_EQ(inName,"vWrap") ) { return vWrap; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return format; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"minFilter") ) { return minFilter; }
		if (HX_FIELD_EQ(inName,"magFilter") ) { return magFilter; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useMipMaps") ) { return useMipMaps; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"textureFile") ) { return textureFile; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Page_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"uWrap") ) { uWrap=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vWrap") ) { vWrap=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::spinehaxe::atlas::Texture >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"minFilter") ) { minFilter=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"magFilter") ) { magFilter=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useMipMaps") ) { useMipMaps=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"textureFile") ) { textureFile=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Page_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("textureFile"));
	outFields->push(HX_CSTRING("texture"));
	outFields->push(HX_CSTRING("useMipMaps"));
	outFields->push(HX_CSTRING("format"));
	outFields->push(HX_CSTRING("minFilter"));
	outFields->push(HX_CSTRING("magFilter"));
	outFields->push(HX_CSTRING("uWrap"));
	outFields->push(HX_CSTRING("vWrap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Page_obj,textureFile),HX_CSTRING("textureFile")},
	{hx::fsObject /*::spinehaxe::atlas::Texture*/ ,(int)offsetof(Page_obj,texture),HX_CSTRING("texture")},
	{hx::fsBool,(int)offsetof(Page_obj,useMipMaps),HX_CSTRING("useMipMaps")},
	{hx::fsString,(int)offsetof(Page_obj,format),HX_CSTRING("format")},
	{hx::fsString,(int)offsetof(Page_obj,minFilter),HX_CSTRING("minFilter")},
	{hx::fsString,(int)offsetof(Page_obj,magFilter),HX_CSTRING("magFilter")},
	{hx::fsString,(int)offsetof(Page_obj,uWrap),HX_CSTRING("uWrap")},
	{hx::fsString,(int)offsetof(Page_obj,vWrap),HX_CSTRING("vWrap")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("textureFile"),
	HX_CSTRING("texture"),
	HX_CSTRING("useMipMaps"),
	HX_CSTRING("format"),
	HX_CSTRING("minFilter"),
	HX_CSTRING("magFilter"),
	HX_CSTRING("uWrap"),
	HX_CSTRING("vWrap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Page_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Page_obj::__mClass,"__mClass");
};

#endif

Class Page_obj::__mClass;

void Page_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.Page"), hx::TCanCast< Page_obj> ,sStaticFields,sMemberFields,
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

void Page_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
