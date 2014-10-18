#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_attachments_NumberUtils
#include <spinehaxe/attachments/NumberUtils.h>
#endif
namespace spinehaxe{
namespace attachments{

Void NumberUtils_obj::__construct()
{
	return null();
}

//NumberUtils_obj::~NumberUtils_obj() { }

Dynamic NumberUtils_obj::__CreateEmpty() { return  new NumberUtils_obj; }
hx::ObjectPtr< NumberUtils_obj > NumberUtils_obj::__new()
{  hx::ObjectPtr< NumberUtils_obj > result = new NumberUtils_obj();
	result->__construct();
	return result;}

Dynamic NumberUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NumberUtils_obj > result = new NumberUtils_obj();
	result->__construct();
	return result;}

Float NumberUtils_obj::intToFloatColor( int value){
	HX_STACK_FRAME("spinehaxe.attachments.NumberUtils","intToFloatColor",0x663d6788,"spinehaxe.attachments.NumberUtils.intToFloatColor","spinehaxe/attachments/RegionAttachment.hx",182,0xd77a2622)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(182)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtils_obj,intToFloatColor,return )


NumberUtils_obj::NumberUtils_obj()
{
}

Dynamic NumberUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"intToFloatColor") ) { return intToFloatColor_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NumberUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NumberUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("intToFloatColor"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NumberUtils_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NumberUtils_obj::__mClass,"__mClass");
};

#endif

Class NumberUtils_obj::__mClass;

void NumberUtils_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.NumberUtils"), hx::TCanCast< NumberUtils_obj> ,sStaticFields,sMemberFields,
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

void NumberUtils_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
