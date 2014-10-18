#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_HTTPStatusEvent
#include <openfl/events/HTTPStatusEvent.h>
#endif
#ifndef INCLUDED_openfl_net_URLRequestHeader
#include <openfl/net/URLRequestHeader.h>
#endif
namespace openfl{
namespace events{

Void HTTPStatusEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status)
{
HX_STACK_FRAME("openfl.events.HTTPStatusEvent","new",0x992d4c1b,"openfl.events.HTTPStatusEvent.new","openfl/events/HTTPStatusEvent.hx",14,0x9d0269d5)
HX_STACK_THIS(this)
HX_STACK_ARG(type,"type")
HX_STACK_ARG(__o_bubbles,"bubbles")
HX_STACK_ARG(__o_cancelable,"cancelable")
HX_STACK_ARG(__o_status,"status")
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int status = __o_status.Default(0);
{
	HX_STACK_LINE(16)
	super::__construct(type,bubbles,cancelable);
	HX_STACK_LINE(18)
	this->status = status;
	HX_STACK_LINE(19)
	this->responseHeaders = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//HTTPStatusEvent_obj::~HTTPStatusEvent_obj() { }

Dynamic HTTPStatusEvent_obj::__CreateEmpty() { return  new HTTPStatusEvent_obj; }
hx::ObjectPtr< HTTPStatusEvent_obj > HTTPStatusEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status)
{  hx::ObjectPtr< HTTPStatusEvent_obj > result = new HTTPStatusEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_status);
	return result;}

Dynamic HTTPStatusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPStatusEvent_obj > result = new HTTPStatusEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::openfl::events::Event HTTPStatusEvent_obj::clone( ){
	HX_STACK_FRAME("openfl.events.HTTPStatusEvent","clone",0xe75f33d8,"openfl.events.HTTPStatusEvent.clone","openfl/events/HTTPStatusEvent.hx",23,0x9d0269d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(25)
	::String _g = this->get_type();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(25)
	bool _g1 = this->get_bubbles();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(25)
	bool _g2 = this->get_cancelable();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(25)
	return ::openfl::events::HTTPStatusEvent_obj::__new(_g,_g1,_g2,this->status);
}


::String HTTPStatusEvent_obj::toString( ){
	HX_STACK_FRAME("openfl.events.HTTPStatusEvent","toString",0x9713ef11,"openfl.events.HTTPStatusEvent.toString","openfl/events/HTTPStatusEvent.hx",30,0x9d0269d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	::String _g = this->get_type();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	::String _g1 = (HX_CSTRING("[HTTPStatusEvent type=") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	::String _g2 = (_g1 + HX_CSTRING(" bubbles="));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(32)
	bool _g3 = this->get_bubbles();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(32)
	::String _g4 = ::Std_obj::string(_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(32)
	::String _g5 = (_g2 + _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(32)
	::String _g6 = (_g5 + HX_CSTRING(" cancelable="));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(32)
	bool _g7 = this->get_cancelable();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(32)
	::String _g8 = ::Std_obj::string(_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(32)
	::String _g9 = (_g6 + _g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(32)
	::String _g10 = (_g9 + HX_CSTRING(" status="));		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(32)
	::String _g11 = (_g10 + this->status);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(32)
	return (_g11 + HX_CSTRING("]"));
}


::String HTTPStatusEvent_obj::HTTP_STATUS;


HTTPStatusEvent_obj::HTTPStatusEvent_obj()
{
}

void HTTPStatusEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPStatusEvent);
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_MARK_MEMBER_NAME(responseURL,"responseURL");
	::openfl::events::Event_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTTPStatusEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_VISIT_MEMBER_NAME(responseURL,"responseURL");
	::openfl::events::Event_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HTTPStatusEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HTTP_STATUS") ) { return HTTP_STATUS; }
		if (HX_FIELD_EQ(inName,"responseURL") ) { return responseURL; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { return responseHeaders; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPStatusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HTTP_STATUS") ) { HTTP_STATUS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"responseURL") ) { responseURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { responseHeaders=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPStatusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("responseHeaders"));
	outFields->push(HX_CSTRING("responseURL"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTTP_STATUS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(HTTPStatusEvent_obj,status),HX_CSTRING("status")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(HTTPStatusEvent_obj,responseHeaders),HX_CSTRING("responseHeaders")},
	{hx::fsString,(int)offsetof(HTTPStatusEvent_obj,responseURL),HX_CSTRING("responseURL")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("status"),
	HX_CSTRING("responseHeaders"),
	HX_CSTRING("responseURL"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPStatusEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTTPStatusEvent_obj::HTTP_STATUS,"HTTP_STATUS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTTPStatusEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTTPStatusEvent_obj::HTTP_STATUS,"HTTP_STATUS");
};

#endif

Class HTTPStatusEvent_obj::__mClass;

void HTTPStatusEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.events.HTTPStatusEvent"), hx::TCanCast< HTTPStatusEvent_obj> ,sStaticFields,sMemberFields,
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

void HTTPStatusEvent_obj::__boot()
{
	HTTP_STATUS= HX_CSTRING("httpStatus");
}

} // end namespace openfl
} // end namespace events
