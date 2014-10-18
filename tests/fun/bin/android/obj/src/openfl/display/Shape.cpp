#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_Shape
#include <openfl/display/Shape.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
namespace openfl{
namespace display{

Void Shape_obj::__construct()
{
HX_STACK_FRAME("openfl.display.Shape","new",0x7b6756e9,"openfl.display.Shape.new","openfl/display/Shape.hx",7,0xe963f3a9)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(9)
	Dynamic _g = ::openfl::display::DisplayObject_obj::lime_create_display_object();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(9)
	super::__construct(_g,HX_CSTRING("Shape"));
}
;
	return null();
}

//Shape_obj::~Shape_obj() { }

Dynamic Shape_obj::__CreateEmpty() { return  new Shape_obj; }
hx::ObjectPtr< Shape_obj > Shape_obj::__new()
{  hx::ObjectPtr< Shape_obj > result = new Shape_obj();
	result->__construct();
	return result;}

Dynamic Shape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Shape_obj > result = new Shape_obj();
	result->__construct();
	return result;}


Shape_obj::Shape_obj()
{
}

Dynamic Shape_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Shape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Shape_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Shape_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Shape_obj::__mClass,"__mClass");
};

#endif

Class Shape_obj::__mClass;

void Shape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.Shape"), hx::TCanCast< Shape_obj> ,sStaticFields,sMemberFields,
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

void Shape_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
