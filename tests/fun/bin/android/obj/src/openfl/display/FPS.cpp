#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_text_TextFormat
#include <openfl/text/TextFormat.h>
#endif
namespace openfl{
namespace display{

Void FPS_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color)
{
HX_STACK_FRAME("openfl.display.FPS","new",0xe5d2c231,"openfl.display.FPS.new","openfl/display/FPS.hx",19,0x584764e1)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_x,"x")
HX_STACK_ARG(__o_y,"y")
HX_STACK_ARG(__o_color,"color")
Float x = __o_x.Default(10);
Float y = __o_y.Default(10);
int color = __o_color.Default(0);
{
	HX_STACK_LINE(21)
	super::__construct();
	HX_STACK_LINE(23)
	this->set_x(x);
	HX_STACK_LINE(24)
	this->set_y(y);
	HX_STACK_LINE(26)
	this->currentFPS = (int)0;
	HX_STACK_LINE(27)
	this->set_selectable(false);
	HX_STACK_LINE(28)
	::openfl::text::TextFormat _g = ::openfl::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,color,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	this->set_defaultTextFormat(_g);
	HX_STACK_LINE(29)
	this->set_text(HX_CSTRING("FPS: "));
	HX_STACK_LINE(31)
	this->cacheCount = (int)0;
	HX_STACK_LINE(32)
	this->times = Array_obj< Float >::__new();
	HX_STACK_LINE(34)
	this->addEventListener(::openfl::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null(),null(),null());
}
;
	return null();
}

//FPS_obj::~FPS_obj() { }

Dynamic FPS_obj::__CreateEmpty() { return  new FPS_obj; }
hx::ObjectPtr< FPS_obj > FPS_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(__o_x,__o_y,__o_color);
	return result;}

Dynamic FPS_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FPS_obj::this_onEnterFrame( ::openfl::events::Event event){
{
		HX_STACK_FRAME("openfl.display.FPS","this_onEnterFrame",0x56ef2d46,"openfl.display.FPS.this_onEnterFrame","openfl/display/FPS.hx",46,0x584764e1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(48)
		Float currentTime = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(49)
		this->times->push(currentTime);
		HX_STACK_LINE(51)
		while((true)){
			HX_STACK_LINE(51)
			if ((!(((this->times->__get((int)0) < (currentTime - (int)1)))))){
				HX_STACK_LINE(51)
				break;
			}
			HX_STACK_LINE(53)
			this->times->shift();
		}
		HX_STACK_LINE(57)
		int currentCount = this->times->length;		HX_STACK_VAR(currentCount,"currentCount");
		HX_STACK_LINE(58)
		int _g = ::Math_obj::round((Float(((currentCount + this->cacheCount))) / Float((int)2)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		this->currentFPS = _g;
		HX_STACK_LINE(60)
		if (((  (((currentCount != this->cacheCount))) ? bool(this->get_visible()) : bool(false) ))){
			HX_STACK_LINE(62)
			this->set_text((HX_CSTRING("FPS: ") + this->currentFPS));
		}
		HX_STACK_LINE(66)
		this->cacheCount = currentCount;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FPS_obj,this_onEnterFrame,(void))


FPS_obj::FPS_obj()
{
}

void FPS_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPS);
	HX_MARK_MEMBER_NAME(currentFPS,"currentFPS");
	HX_MARK_MEMBER_NAME(cacheCount,"cacheCount");
	HX_MARK_MEMBER_NAME(times,"times");
	::openfl::text::TextField_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FPS_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(currentFPS,"currentFPS");
	HX_VISIT_MEMBER_NAME(cacheCount,"cacheCount");
	HX_VISIT_MEMBER_NAME(times,"times");
	::openfl::text::TextField_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FPS_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { return times; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"currentFPS") ) { return currentFPS; }
		if (HX_FIELD_EQ(inName,"cacheCount") ) { return cacheCount; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FPS_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { times=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"currentFPS") ) { currentFPS=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cacheCount") ) { cacheCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FPS_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentFPS"));
	outFields->push(HX_CSTRING("cacheCount"));
	outFields->push(HX_CSTRING("times"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FPS_obj,currentFPS),HX_CSTRING("currentFPS")},
	{hx::fsInt,(int)offsetof(FPS_obj,cacheCount),HX_CSTRING("cacheCount")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(FPS_obj,times),HX_CSTRING("times")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("currentFPS"),
	HX_CSTRING("cacheCount"),
	HX_CSTRING("times"),
	HX_CSTRING("this_onEnterFrame"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

#endif

Class FPS_obj::__mClass;

void FPS_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.FPS"), hx::TCanCast< FPS_obj> ,sStaticFields,sMemberFields,
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

void FPS_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
