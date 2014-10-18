#include <hxcpp.h>

#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
namespace openfl{
namespace filters{

Void BitmapFilter_obj::__construct(::String __o_type)
{
HX_STACK_FRAME("openfl.filters.BitmapFilter","new",0x22686a4a,"openfl.filters.BitmapFilter.new","openfl/filters/BitmapFilter.hx",12,0x1697f5a4)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_type,"type")
::String type = __o_type.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(12)
	this->type = type;
}
;
	return null();
}

//BitmapFilter_obj::~BitmapFilter_obj() { }

Dynamic BitmapFilter_obj::__CreateEmpty() { return  new BitmapFilter_obj; }
hx::ObjectPtr< BitmapFilter_obj > BitmapFilter_obj::__new(::String __o_type)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(__o_type);
	return result;}

Dynamic BitmapFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(inArgs[0]);
	return result;}

::openfl::filters::BitmapFilter BitmapFilter_obj::clone( ){
	HX_STACK_FRAME("openfl.filters.BitmapFilter","clone",0x8c417bc7,"openfl.filters.BitmapFilter.clone","openfl/filters/BitmapFilter.hx",19,0x1697f5a4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(19)
	return ::openfl::filters::BitmapFilter_obj::__new(this->type);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFilter_obj,clone,return )


BitmapFilter_obj::BitmapFilter_obj()
{
}

void BitmapFilter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapFilter);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_END_CLASS();
}

void BitmapFilter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
}

Dynamic BitmapFilter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapFilter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(BitmapFilter_obj,type),HX_CSTRING("type")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapFilter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapFilter_obj::__mClass,"__mClass");
};

#endif

Class BitmapFilter_obj::__mClass;

void BitmapFilter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.filters.BitmapFilter"), hx::TCanCast< BitmapFilter_obj> ,sStaticFields,sMemberFields,
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

void BitmapFilter_obj::__boot()
{
}

} // end namespace openfl
} // end namespace filters
