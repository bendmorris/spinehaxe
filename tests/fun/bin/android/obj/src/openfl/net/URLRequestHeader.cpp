#include <hxcpp.h>

#ifndef INCLUDED_openfl_net_URLRequestHeader
#include <openfl/net/URLRequestHeader.h>
#endif
namespace openfl{
namespace net{

Void URLRequestHeader_obj::__construct(::String __o_name,::String __o_value)
{
HX_STACK_FRAME("openfl.net.URLRequestHeader","new",0xe794452e,"openfl.net.URLRequestHeader.new","openfl/net/URLRequestHeader.hx",11,0xf4ac7ec0)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_name,"name")
HX_STACK_ARG(__o_value,"value")
::String name = __o_name.Default(HX_CSTRING(""));
::String value = __o_value.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(13)
	this->name = name;
	HX_STACK_LINE(14)
	this->value = value;
}
;
	return null();
}

//URLRequestHeader_obj::~URLRequestHeader_obj() { }

Dynamic URLRequestHeader_obj::__CreateEmpty() { return  new URLRequestHeader_obj; }
hx::ObjectPtr< URLRequestHeader_obj > URLRequestHeader_obj::__new(::String __o_name,::String __o_value)
{  hx::ObjectPtr< URLRequestHeader_obj > result = new URLRequestHeader_obj();
	result->__construct(__o_name,__o_value);
	return result;}

Dynamic URLRequestHeader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLRequestHeader_obj > result = new URLRequestHeader_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


URLRequestHeader_obj::URLRequestHeader_obj()
{
}

void URLRequestHeader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLRequestHeader);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void URLRequestHeader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic URLRequestHeader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic URLRequestHeader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void URLRequestHeader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(URLRequestHeader_obj,name),HX_CSTRING("name")},
	{hx::fsString,(int)offsetof(URLRequestHeader_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLRequestHeader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(URLRequestHeader_obj::__mClass,"__mClass");
};

#endif

Class URLRequestHeader_obj::__mClass;

void URLRequestHeader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.net.URLRequestHeader"), hx::TCanCast< URLRequestHeader_obj> ,sStaticFields,sMemberFields,
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

void URLRequestHeader_obj::__boot()
{
}

} // end namespace openfl
} // end namespace net
