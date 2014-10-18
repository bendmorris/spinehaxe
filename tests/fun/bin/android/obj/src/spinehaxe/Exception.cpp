#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
namespace spinehaxe{

Void Exception_obj::__construct(::String msg)
{
HX_STACK_FRAME("spinehaxe.Exception","new",0x78f5377c,"spinehaxe.Exception.new","spinehaxe/Exception.hx",5,0xb7f1c8f5)
HX_STACK_THIS(this)
HX_STACK_ARG(msg,"msg")
{
	HX_STACK_LINE(5)
	this->msg = msg;
}
;
	return null();
}

//Exception_obj::~Exception_obj() { }

Dynamic Exception_obj::__CreateEmpty() { return  new Exception_obj; }
hx::ObjectPtr< Exception_obj > Exception_obj::__new(::String msg)
{  hx::ObjectPtr< Exception_obj > result = new Exception_obj();
	result->__construct(msg);
	return result;}

Dynamic Exception_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Exception_obj > result = new Exception_obj();
	result->__construct(inArgs[0]);
	return result;}


Exception_obj::Exception_obj()
{
}

void Exception_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Exception);
	HX_MARK_MEMBER_NAME(msg,"msg");
	HX_MARK_END_CLASS();
}

void Exception_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(msg,"msg");
}

Dynamic Exception_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"msg") ) { return msg; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Exception_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"msg") ) { msg=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Exception_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("msg"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Exception_obj,msg),HX_CSTRING("msg")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("msg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Exception_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Exception_obj::__mClass,"__mClass");
};

#endif

Class Exception_obj::__mClass;

void Exception_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Exception"), hx::TCanCast< Exception_obj> ,sStaticFields,sMemberFields,
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

void Exception_obj::__boot()
{
}

} // end namespace spinehaxe
