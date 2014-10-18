#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Skin
#include <spinehaxe/Skin.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentLoader
#include <spinehaxe/attachments/AttachmentLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentType
#include <spinehaxe/attachments/AttachmentType.h>
#endif
namespace spinehaxe{
namespace attachments{

HX_DEFINE_DYNAMIC_FUNC3(AttachmentLoader_obj,newAttachment,return )


static ::String sMemberFields[] = {
	HX_CSTRING("newAttachment"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AttachmentLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttachmentLoader_obj::__mClass,"__mClass");
};

#endif

Class AttachmentLoader_obj::__mClass;

void AttachmentLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.AttachmentLoader"), hx::TCanCast< AttachmentLoader_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void AttachmentLoader_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
