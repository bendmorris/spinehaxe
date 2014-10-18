#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_EventData
#include <spinehaxe/EventData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
namespace spinehaxe{

Void EventData_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.EventData","new",0x83093511,"spinehaxe.EventData.new","spinehaxe/EventData.hx",40,0x5f985500)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(41)
	if (((name == null()))){
		HX_STACK_LINE(42)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(43)
	this->name = name;
}
;
	return null();
}

//EventData_obj::~EventData_obj() { }

Dynamic EventData_obj::__CreateEmpty() { return  new EventData_obj; }
hx::ObjectPtr< EventData_obj > EventData_obj::__new(::String name)
{  hx::ObjectPtr< EventData_obj > result = new EventData_obj();
	result->__construct(name);
	return result;}

Dynamic EventData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventData_obj > result = new EventData_obj();
	result->__construct(inArgs[0]);
	return result;}

::String EventData_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.EventData","toString",0x3ad9ca5b,"spinehaxe.EventData.toString","spinehaxe/EventData.hx",47,0x5f985500)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(EventData_obj,toString,return )


EventData_obj::EventData_obj()
{
}

void EventData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventData);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(intValue,"intValue");
	HX_MARK_MEMBER_NAME(floatValue,"floatValue");
	HX_MARK_MEMBER_NAME(stringValue,"stringValue");
	HX_MARK_END_CLASS();
}

void EventData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(intValue,"intValue");
	HX_VISIT_MEMBER_NAME(floatValue,"floatValue");
	HX_VISIT_MEMBER_NAME(stringValue,"stringValue");
}

Dynamic EventData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
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

Dynamic EventData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
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

void EventData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("intValue"));
	outFields->push(HX_CSTRING("floatValue"));
	outFields->push(HX_CSTRING("stringValue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(EventData_obj,name),HX_CSTRING("name")},
	{hx::fsInt,(int)offsetof(EventData_obj,intValue),HX_CSTRING("intValue")},
	{hx::fsFloat,(int)offsetof(EventData_obj,floatValue),HX_CSTRING("floatValue")},
	{hx::fsString,(int)offsetof(EventData_obj,stringValue),HX_CSTRING("stringValue")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("intValue"),
	HX_CSTRING("floatValue"),
	HX_CSTRING("stringValue"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventData_obj::__mClass,"__mClass");
};

#endif

Class EventData_obj::__mClass;

void EventData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.EventData"), hx::TCanCast< EventData_obj> ,sStaticFields,sMemberFields,
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

void EventData_obj::__boot()
{
}

} // end namespace spinehaxe
