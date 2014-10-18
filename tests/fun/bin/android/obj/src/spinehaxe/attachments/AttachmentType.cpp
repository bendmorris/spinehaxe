#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_attachments_AttachmentType
#include <spinehaxe/attachments/AttachmentType.h>
#endif
namespace spinehaxe{
namespace attachments{

::spinehaxe::attachments::AttachmentType AttachmentType_obj::boundingbox;

::spinehaxe::attachments::AttachmentType AttachmentType_obj::region;

::spinehaxe::attachments::AttachmentType AttachmentType_obj::regionSequence;

HX_DEFINE_CREATE_ENUM(AttachmentType_obj)

int AttachmentType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("boundingbox")) return 2;
	if (inName==HX_CSTRING("region")) return 0;
	if (inName==HX_CSTRING("regionSequence")) return 1;
	return super::__FindIndex(inName);
}

int AttachmentType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("boundingbox")) return 0;
	if (inName==HX_CSTRING("region")) return 0;
	if (inName==HX_CSTRING("regionSequence")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AttachmentType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("boundingbox")) return boundingbox;
	if (inName==HX_CSTRING("region")) return region;
	if (inName==HX_CSTRING("regionSequence")) return regionSequence;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("region"),
	HX_CSTRING("regionSequence"),
	HX_CSTRING("boundingbox"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AttachmentType_obj::boundingbox,"boundingbox");
	HX_MARK_MEMBER_NAME(AttachmentType_obj::region,"region");
	HX_MARK_MEMBER_NAME(AttachmentType_obj::regionSequence,"regionSequence");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttachmentType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AttachmentType_obj::boundingbox,"boundingbox");
	HX_VISIT_MEMBER_NAME(AttachmentType_obj::region,"region");
	HX_VISIT_MEMBER_NAME(AttachmentType_obj::regionSequence,"regionSequence");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class AttachmentType_obj::__mClass;

Dynamic __Create_AttachmentType_obj() { return new AttachmentType_obj; }

void AttachmentType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.AttachmentType"), hx::TCanCast< AttachmentType_obj >,sStaticFields,sMemberFields,
	&__Create_AttachmentType_obj, &__Create,
	&super::__SGetClass(), &CreateAttachmentType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void AttachmentType_obj::__boot()
{
hx::Static(boundingbox) = hx::CreateEnum< AttachmentType_obj >(HX_CSTRING("boundingbox"),2);
hx::Static(region) = hx::CreateEnum< AttachmentType_obj >(HX_CSTRING("region"),0);
hx::Static(regionSequence) = hx::CreateEnum< AttachmentType_obj >(HX_CSTRING("regionSequence"),1);
}


} // end namespace spinehaxe
} // end namespace attachments
