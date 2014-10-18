#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_StringInput
#include <haxe/io/StringInput.h>
#endif
namespace haxe{
namespace io{

Void StringInput_obj::__construct(::String s)
{
HX_STACK_FRAME("haxe.io.StringInput","new",0x8fd1998b,"haxe.io.StringInput.new","/usr/lib/haxe/std/haxe/io/StringInput.hx",26,0xdf46f5c6)
HX_STACK_THIS(this)
HX_STACK_ARG(s,"s")
{
	HX_STACK_LINE(31)
	::haxe::io::Bytes _g = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	super::__construct(_g,null(),null());
}
;
	return null();
}

//StringInput_obj::~StringInput_obj() { }

Dynamic StringInput_obj::__CreateEmpty() { return  new StringInput_obj; }
hx::ObjectPtr< StringInput_obj > StringInput_obj::__new(::String s)
{  hx::ObjectPtr< StringInput_obj > result = new StringInput_obj();
	result->__construct(s);
	return result;}

Dynamic StringInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringInput_obj > result = new StringInput_obj();
	result->__construct(inArgs[0]);
	return result;}


StringInput_obj::StringInput_obj()
{
}

Dynamic StringInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic StringInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void StringInput_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(StringInput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringInput_obj::__mClass,"__mClass");
};

#endif

Class StringInput_obj::__mClass;

void StringInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.StringInput"), hx::TCanCast< StringInput_obj> ,sStaticFields,sMemberFields,
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

void StringInput_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
