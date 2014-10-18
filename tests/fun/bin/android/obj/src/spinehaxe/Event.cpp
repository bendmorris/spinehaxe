#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_EventData
#include <spinehaxe/EventData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
namespace spinehaxe{

Void Event_obj::__construct(::spinehaxe::EventData data)
{
HX_STACK_FRAME("spinehaxe.Event","new",0xa48a7747,"spinehaxe.Event.new","spinehaxe/Event.hx",40,0xecefb70a)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
{
	HX_STACK_LINE(41)
	if (((data == null()))){
		HX_STACK_LINE(42)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("data cannot be null.")));
	}
	HX_STACK_LINE(43)
	this->data = data;
}
;
	return null();
}

//Event_obj::~Event_obj() { }

Dynamic Event_obj::__CreateEmpty() { return  new Event_obj; }
hx::ObjectPtr< Event_obj > Event_obj::__new(::spinehaxe::EventData data)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(data);
	return result;}

Dynamic Event_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Event_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Event","toString",0x2acec465,"spinehaxe.Event.toString","spinehaxe/Event.hx",47,0xecefb70a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return this->data->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,toString,return )


Event_obj::Event_obj()
{
}

void Event_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Event);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(intValue,"intValue");
	HX_MARK_MEMBER_NAME(floatValue,"floatValue");
	HX_MARK_MEMBER_NAME(stringValue,"stringValue");
	HX_MARK_END_CLASS();
}

void Event_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(intValue,"intValue");
	HX_VISIT_MEMBER_NAME(floatValue,"floatValue");
	HX_VISIT_MEMBER_NAME(stringValue,"stringValue");
}

Dynamic Event_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"intValue") ) { return intValue; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"floatValue") ) { return floatValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stringValue") ) { return stringValue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Event_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::spinehaxe::EventData >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"intValue") ) { intValue=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"floatValue") ) { floatValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stringValue") ) { stringValue=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Event_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("intValue"));
	outFields->push(HX_CSTRING("floatValue"));
	outFields->push(HX_CSTRING("stringValue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::EventData*/ ,(int)offsetof(Event_obj,data),HX_CSTRING("data")},
	{hx::fsInt,(int)offsetof(Event_obj,intValue),HX_CSTRING("intValue")},
	{hx::fsFloat,(int)offsetof(Event_obj,floatValue),HX_CSTRING("floatValue")},
	{hx::fsString,(int)offsetof(Event_obj,stringValue),HX_CSTRING("stringValue")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("intValue"),
	HX_CSTRING("floatValue"),
	HX_CSTRING("stringValue"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Event_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Event_obj::__mClass,"__mClass");
};

#endif

Class Event_obj::__mClass;

void Event_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Event"), hx::TCanCast< Event_obj> ,sStaticFields,sMemberFields,
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

void Event_obj::__boot()
{
}

} // end namespace spinehaxe
