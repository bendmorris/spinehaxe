#ifndef INCLUDED_spinehaxe_attachments_AttachmentLoader
#define INCLUDED_spinehaxe_attachments_AttachmentLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentLoader)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentType)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  AttachmentLoader_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef AttachmentLoader_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::spinehaxe::attachments::Attachment newAttachment( ::spinehaxe::Skin skin,::spinehaxe::attachments::AttachmentType type,::String name)=0;
		Dynamic newAttachment_dyn();
};

#define DELEGATE_spinehaxe_attachments_AttachmentLoader \
virtual ::spinehaxe::attachments::Attachment newAttachment( ::spinehaxe::Skin skin,::spinehaxe::attachments::AttachmentType type,::String name) { return mDelegate->newAttachment(skin,type,name);}  \
virtual Dynamic newAttachment_dyn() { return mDelegate->newAttachment_dyn();}  \


template<typename IMPL>
class AttachmentLoader_delegate_ : public AttachmentLoader_obj
{
	protected:
		IMPL *mDelegate;
	public:
		AttachmentLoader_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_spinehaxe_attachments_AttachmentLoader
};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_AttachmentLoader */ 
