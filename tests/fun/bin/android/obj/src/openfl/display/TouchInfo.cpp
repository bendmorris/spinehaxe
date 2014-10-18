#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_TouchInfo
#include <openfl/display/TouchInfo.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
namespace openfl{
namespace display{

Void TouchInfo_obj::__construct()
{
HX_STACK_FRAME("openfl.display.TouchInfo","new",0x23c4e495,"openfl.display.TouchInfo.new","openfl/display/Stage.hx",1389,0xadca4c2c)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1389)
	this->touchOverObjects = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//TouchInfo_obj::~TouchInfo_obj() { }

Dynamic TouchInfo_obj::__CreateEmpty() { return  new TouchInfo_obj; }
hx::ObjectPtr< TouchInfo_obj > TouchInfo_obj::__new()
{  hx::ObjectPtr< TouchInfo_obj > result = new TouchInfo_obj();
	result->__construct();
	return result;}

Dynamic TouchInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchInfo_obj > result = new TouchInfo_obj();
	result->__construct();
	return result;}


TouchInfo_obj::TouchInfo_obj()
{
}

void TouchInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchInfo);
	HX_MARK_MEMBER_NAME(touchOverObjects,"touchOverObjects");
	HX_MARK_END_CLASS();
}

void TouchInfo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(touchOverObjects,"touchOverObjects");
}

Dynamic TouchInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"touchOverObjects") ) { return touchOverObjects; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"touchOverObjects") ) { touchOverObjects=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("touchOverObjects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TouchInfo_obj,touchOverObjects),HX_CSTRING("touchOverObjects")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("touchOverObjects"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchInfo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchInfo_obj::__mClass,"__mClass");
};

#endif

Class TouchInfo_obj::__mClass;

void TouchInfo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.TouchInfo"), hx::TCanCast< TouchInfo_obj> ,sStaticFields,sMemberFields,
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

void TouchInfo_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
