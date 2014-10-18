#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void EReg_obj::__construct(::String r,::String opt)
{
HX_STACK_FRAME("EReg","new",0x8b859e81,"EReg.new","/usr/lib/haxe/std/cpp/_std/EReg.hx",28,0x16cad931)
HX_STACK_THIS(this)
HX_STACK_ARG(r,"r")
HX_STACK_ARG(opt,"opt")
{
	HX_STACK_LINE(29)
	Array< ::String > a = opt.split(HX_CSTRING("g"));		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(30)
	this->global = (a->length > (int)1);
	HX_STACK_LINE(31)
	if ((this->global)){
		HX_STACK_LINE(32)
		::String _g = a->join(HX_CSTRING(""));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		opt = _g;
	}
	HX_STACK_LINE(33)
	Dynamic _g1 = ::EReg_obj::regexp_new_options(r,opt);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(33)
	this->r = _g1;
}
;
	return null();
}

//EReg_obj::~EReg_obj() { }

Dynamic EReg_obj::__CreateEmpty() { return  new EReg_obj; }
hx::ObjectPtr< EReg_obj > EReg_obj::__new(::String r,::String opt)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(r,opt);
	return result;}

Dynamic EReg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic EReg_obj::regexp_new_options;


EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EReg);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_END_CLASS();
}

void EReg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(global,"global");
}

Dynamic EReg_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { return global; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { return regexp_new_options; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EReg_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { regexp_new_options=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("global"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("regexp_new_options"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(EReg_obj,r),HX_CSTRING("r")},
	{hx::fsBool,(int)offsetof(EReg_obj,global),HX_CSTRING("global")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("r"),
	HX_CSTRING("global"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EReg_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_new_options,"regexp_new_options");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EReg_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EReg_obj::regexp_new_options,"regexp_new_options");
};

#endif

Class EReg_obj::__mClass;

void EReg_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("EReg"), hx::TCanCast< EReg_obj> ,sStaticFields,sMemberFields,
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

void EReg_obj::__boot()
{
	regexp_new_options= ::cpp::Lib_obj::load(HX_CSTRING("regexp"),HX_CSTRING("regexp_new_options"),(int)2);
}

