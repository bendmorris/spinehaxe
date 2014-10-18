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
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl_events_TouchEvent
#include <openfl/events/TouchEvent.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
namespace openfl{
namespace events{

Void TouchEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_localX,hx::Null< Float >  __o_localY,hx::Null< Float >  __o_sizeX,hx::Null< Float >  __o_sizeY,::openfl::display::InteractiveObject relatedObject,hx::Null< bool >  __o_ctrlKey,hx::Null< bool >  __o_altKey,hx::Null< bool >  __o_shiftKey,hx::Null< bool >  __o_buttonDown,hx::Null< int >  __o_delta,hx::Null< bool >  __o_commandKey,hx::Null< int >  __o_clickCount)
{
HX_STACK_FRAME("openfl.events.TouchEvent","new",0xe223a0c4,"openfl.events.TouchEvent.new","openfl/events/TouchEvent.hx",27,0x2fe85d0c)
HX_STACK_THIS(this)
HX_STACK_ARG(type,"type")
HX_STACK_ARG(__o_bubbles,"bubbles")
HX_STACK_ARG(__o_cancelable,"cancelable")
HX_STACK_ARG(__o_localX,"localX")
HX_STACK_ARG(__o_localY,"localY")
HX_STACK_ARG(__o_sizeX,"sizeX")
HX_STACK_ARG(__o_sizeY,"sizeY")
HX_STACK_ARG(relatedObject,"relatedObject")
HX_STACK_ARG(__o_ctrlKey,"ctrlKey")
HX_STACK_ARG(__o_altKey,"altKey")
HX_STACK_ARG(__o_shiftKey,"shiftKey")
HX_STACK_ARG(__o_buttonDown,"buttonDown")
HX_STACK_ARG(__o_delta,"delta")
HX_STACK_ARG(__o_commandKey,"commandKey")
HX_STACK_ARG(__o_clickCount,"clickCount")
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
Float localX = __o_localX.Default(0);
Float localY = __o_localY.Default(0);
Float sizeX = __o_sizeX.Default(1);
Float sizeY = __o_sizeY.Default(1);
bool ctrlKey = __o_ctrlKey.Default(false);
bool altKey = __o_altKey.Default(false);
bool shiftKey = __o_shiftKey.Default(false);
bool buttonDown = __o_buttonDown.Default(false);
int delta = __o_delta.Default(0);
bool commandKey = __o_commandKey.Default(false);
int clickCount = __o_clickCount.Default(0);
{
	HX_STACK_LINE(29)
	super::__construct(type,bubbles,cancelable,localX,localY,relatedObject,ctrlKey,altKey,shiftKey,buttonDown,delta,commandKey,clickCount);
	HX_STACK_LINE(31)
	this->pressure = (int)1;
	HX_STACK_LINE(32)
	this->touchPointID = (int)0;
	HX_STACK_LINE(33)
	this->isPrimaryTouchPoint = true;
	HX_STACK_LINE(34)
	this->sizeX = sizeX;
	HX_STACK_LINE(35)
	this->sizeY = sizeY;
}
;
	return null();
}

//TouchEvent_obj::~TouchEvent_obj() { }

Dynamic TouchEvent_obj::__CreateEmpty() { return  new TouchEvent_obj; }
hx::ObjectPtr< TouchEvent_obj > TouchEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_localX,hx::Null< Float >  __o_localY,hx::Null< Float >  __o_sizeX,hx::Null< Float >  __o_sizeY,::openfl::display::InteractiveObject relatedObject,hx::Null< bool >  __o_ctrlKey,hx::Null< bool >  __o_altKey,hx::Null< bool >  __o_shiftKey,hx::Null< bool >  __o_buttonDown,hx::Null< int >  __o_delta,hx::Null< bool >  __o_commandKey,hx::Null< int >  __o_clickCount)
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_localX,__o_localY,__o_sizeX,__o_sizeY,relatedObject,__o_ctrlKey,__o_altKey,__o_shiftKey,__o_buttonDown,__o_delta,__o_commandKey,__o_clickCount);
	return result;}

Dynamic TouchEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12],inArgs[13],inArgs[14]);
	return result;}

::openfl::events::MouseEvent TouchEvent_obj::__createSimilar( ::String type,::openfl::display::InteractiveObject related,::openfl::display::InteractiveObject target){
	HX_STACK_FRAME("openfl.events.TouchEvent","__createSimilar",0xa3720dd3,"openfl.events.TouchEvent.__createSimilar","openfl/events/TouchEvent.hx",52,0x2fe85d0c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(related,"related")
	HX_STACK_ARG(target,"target")
	HX_STACK_LINE(54)
	bool _g = this->get_bubbles();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	bool _g1 = this->get_cancelable();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(54)
	::openfl::events::TouchEvent touchEvent = ::openfl::events::TouchEvent_obj::__new(type,_g,_g1,this->localX,this->localY,this->sizeX,this->sizeY,(  (((related == null()))) ? ::openfl::display::InteractiveObject(this->relatedObject) : ::openfl::display::InteractiveObject(related) ),this->ctrlKey,this->altKey,this->shiftKey,this->buttonDown,this->delta,this->commandKey,this->clickCount);		HX_STACK_VAR(touchEvent,"touchEvent");
	HX_STACK_LINE(56)
	touchEvent->touchPointID = this->touchPointID;
	HX_STACK_LINE(57)
	touchEvent->isPrimaryTouchPoint = this->isPrimaryTouchPoint;
	HX_STACK_LINE(59)
	if (((target != null()))){
		HX_STACK_LINE(61)
		touchEvent->set_target(target);
	}
	HX_STACK_LINE(65)
	return touchEvent;
}


::String TouchEvent_obj::TOUCH_BEGIN;

::String TouchEvent_obj::TOUCH_END;

::String TouchEvent_obj::TOUCH_MOVE;

::String TouchEvent_obj::TOUCH_OUT;

::String TouchEvent_obj::TOUCH_OVER;

::String TouchEvent_obj::TOUCH_ROLL_OUT;

::String TouchEvent_obj::TOUCH_ROLL_OVER;

::String TouchEvent_obj::TOUCH_TAP;

::openfl::events::TouchEvent TouchEvent_obj::__create( ::String type,Dynamic event,::openfl::geom::Point local,::openfl::display::InteractiveObject target,Float sizeX,Float sizeY){
	HX_STACK_FRAME("openfl.events.TouchEvent","__create",0x8acd1738,"openfl.events.TouchEvent.__create","openfl/events/TouchEvent.hx",40,0x2fe85d0c)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(event,"event")
	HX_STACK_ARG(local,"local")
	HX_STACK_ARG(target,"target")
	HX_STACK_ARG(sizeX,"sizeX")
	HX_STACK_ARG(sizeY,"sizeY")
	HX_STACK_LINE(42)
	int flags = event->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(43)
	::openfl::events::TouchEvent touchEvent = ::openfl::events::TouchEvent_obj::__new(type,true,false,local->x,local->y,sizeX,sizeY,null(),(((int(flags) & int(::openfl::events::MouseEvent_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::openfl::events::MouseEvent_obj::efAltDown))) != (int)0),(((int(flags) & int(::openfl::events::MouseEvent_obj::efShiftDown))) != (int)0),(((int(flags) & int(::openfl::events::MouseEvent_obj::efLeftDown))) != (int)0),(int)0,null(),(int)0);		HX_STACK_VAR(touchEvent,"touchEvent");
	HX_STACK_LINE(44)
	touchEvent->stageX = event->__Field(HX_CSTRING("x"),true);
	HX_STACK_LINE(45)
	touchEvent->stageY = event->__Field(HX_CSTRING("y"),true);
	HX_STACK_LINE(46)
	touchEvent->set_target(target);
	HX_STACK_LINE(47)
	return touchEvent;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(TouchEvent_obj,__create,return )


TouchEvent_obj::TouchEvent_obj()
{
}

Dynamic TouchEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sizeX") ) { return sizeX; }
		if (HX_FIELD_EQ(inName,"sizeY") ) { return sizeY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__create") ) { return __create_dyn(); }
		if (HX_FIELD_EQ(inName,"pressure") ) { return pressure; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { return TOUCH_END; }
		if (HX_FIELD_EQ(inName,"TOUCH_OUT") ) { return TOUCH_OUT; }
		if (HX_FIELD_EQ(inName,"TOUCH_TAP") ) { return TOUCH_TAP; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { return TOUCH_MOVE; }
		if (HX_FIELD_EQ(inName,"TOUCH_OVER") ) { return TOUCH_OVER; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TOUCH_BEGIN") ) { return TOUCH_BEGIN; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { return touchPointID; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OUT") ) { return TOUCH_ROLL_OUT; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OVER") ) { return TOUCH_ROLL_OVER; }
		if (HX_FIELD_EQ(inName,"__createSimilar") ) { return __createSimilar_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"isPrimaryTouchPoint") ) { return isPrimaryTouchPoint; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sizeX") ) { sizeX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sizeY") ) { sizeY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"pressure") ) { pressure=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { TOUCH_END=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_OUT") ) { TOUCH_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_TAP") ) { TOUCH_TAP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { TOUCH_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_OVER") ) { TOUCH_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TOUCH_BEGIN") ) { TOUCH_BEGIN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { touchPointID=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OUT") ) { TOUCH_ROLL_OUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OVER") ) { TOUCH_ROLL_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"isPrimaryTouchPoint") ) { isPrimaryTouchPoint=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isPrimaryTouchPoint"));
	outFields->push(HX_CSTRING("pressure"));
	outFields->push(HX_CSTRING("sizeX"));
	outFields->push(HX_CSTRING("sizeY"));
	outFields->push(HX_CSTRING("touchPointID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TOUCH_BEGIN"),
	HX_CSTRING("TOUCH_END"),
	HX_CSTRING("TOUCH_MOVE"),
	HX_CSTRING("TOUCH_OUT"),
	HX_CSTRING("TOUCH_OVER"),
	HX_CSTRING("TOUCH_ROLL_OUT"),
	HX_CSTRING("TOUCH_ROLL_OVER"),
	HX_CSTRING("TOUCH_TAP"),
	HX_CSTRING("__create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(TouchEvent_obj,isPrimaryTouchPoint),HX_CSTRING("isPrimaryTouchPoint")},
	{hx::fsFloat,(int)offsetof(TouchEvent_obj,pressure),HX_CSTRING("pressure")},
	{hx::fsFloat,(int)offsetof(TouchEvent_obj,sizeX),HX_CSTRING("sizeX")},
	{hx::fsFloat,(int)offsetof(TouchEvent_obj,sizeY),HX_CSTRING("sizeY")},
	{hx::fsInt,(int)offsetof(TouchEvent_obj,touchPointID),HX_CSTRING("touchPointID")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("isPrimaryTouchPoint"),
	HX_CSTRING("pressure"),
	HX_CSTRING("sizeX"),
	HX_CSTRING("sizeY"),
	HX_CSTRING("touchPointID"),
	HX_CSTRING("__createSimilar"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_BEGIN,"TOUCH_BEGIN");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_END,"TOUCH_END");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_MOVE,"TOUCH_MOVE");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_OUT,"TOUCH_OUT");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_OVER,"TOUCH_OVER");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OUT,"TOUCH_ROLL_OUT");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OVER,"TOUCH_ROLL_OVER");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_TAP,"TOUCH_TAP");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_BEGIN,"TOUCH_BEGIN");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_END,"TOUCH_END");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_MOVE,"TOUCH_MOVE");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_OUT,"TOUCH_OUT");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_OVER,"TOUCH_OVER");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OUT,"TOUCH_ROLL_OUT");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OVER,"TOUCH_ROLL_OVER");
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::TOUCH_TAP,"TOUCH_TAP");
};

#endif

Class TouchEvent_obj::__mClass;

void TouchEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.events.TouchEvent"), hx::TCanCast< TouchEvent_obj> ,sStaticFields,sMemberFields,
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

void TouchEvent_obj::__boot()
{
	TOUCH_BEGIN= HX_CSTRING("touchBegin");
	TOUCH_END= HX_CSTRING("touchEnd");
	TOUCH_MOVE= HX_CSTRING("touchMove");
	TOUCH_OUT= HX_CSTRING("touchOut");
	TOUCH_OVER= HX_CSTRING("touchOver");
	TOUCH_ROLL_OUT= HX_CSTRING("touchRollOut");
	TOUCH_ROLL_OVER= HX_CSTRING("touchRollOver");
	TOUCH_TAP= HX_CSTRING("touchTap");
}

} // end namespace openfl
} // end namespace events
