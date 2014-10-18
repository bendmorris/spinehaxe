#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_attachments_AttachmentType
#include <spinehaxe/attachments/AttachmentType.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentTypes
#include <spinehaxe/attachments/AttachmentTypes.h>
#endif
namespace spinehaxe{
namespace attachments{

Void AttachmentTypes_obj::__construct()
{
	return null();
}

//AttachmentTypes_obj::~AttachmentTypes_obj() { }

Dynamic AttachmentTypes_obj::__CreateEmpty() { return  new AttachmentTypes_obj; }
hx::ObjectPtr< AttachmentTypes_obj > AttachmentTypes_obj::__new()
{  hx::ObjectPtr< AttachmentTypes_obj > result = new AttachmentTypes_obj();
	result->__construct();
	return result;}

Dynamic AttachmentTypes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AttachmentTypes_obj > result = new AttachmentTypes_obj();
	result->__construct();
	return result;}

::spinehaxe::attachments::AttachmentType AttachmentTypes_obj::valueOf( ::String t,::spinehaxe::attachments::AttachmentType def){
	HX_STACK_FRAME("spinehaxe.attachments.AttachmentTypes","valueOf",0xc6be67cd,"spinehaxe.attachments.AttachmentTypes.valueOf","spinehaxe/attachments/AttachmentType.hx",32,0x59a7c2dc)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(def,"def")
	HX_STACK_LINE(32)
	::String _switch_1 = (t);
	if (  ( _switch_1==HX_CSTRING("region"))){
		HX_STACK_LINE(33)
		return ::spinehaxe::attachments::AttachmentType_obj::region;
	}
	else if (  ( _switch_1==HX_CSTRING("regionSequence"))){
		HX_STACK_LINE(34)
		return ::spinehaxe::attachments::AttachmentType_obj::regionSequence;
	}
	else if (  ( _switch_1==HX_CSTRING("boundingbox"))){
		HX_STACK_LINE(35)
		return ::spinehaxe::attachments::AttachmentType_obj::boundingbox;
	}
	else  {
		HX_STACK_LINE(36)
		return def;
	}
;
;
	HX_STACK_LINE(32)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttachmentTypes_obj,valueOf,return )


AttachmentTypes_obj::AttachmentTypes_obj()
{
}

Dynamic AttachmentTypes_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"valueOf") ) { return valueOf_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AttachmentTypes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void AttachmentTypes_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("valueOf"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AttachmentTypes_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttachmentTypes_obj::__mClass,"__mClass");
};

#endif

Class AttachmentTypes_obj::__mClass;

void AttachmentTypes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.AttachmentTypes"), hx::TCanCast< AttachmentTypes_obj> ,sStaticFields,sMemberFields,
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

void AttachmentTypes_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
