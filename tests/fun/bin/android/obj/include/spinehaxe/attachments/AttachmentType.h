#ifndef INCLUDED_spinehaxe_attachments_AttachmentType
#define INCLUDED_spinehaxe_attachments_AttachmentType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentType)
namespace spinehaxe{
namespace attachments{


class AttachmentType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AttachmentType_obj OBJ_;

	public:
		AttachmentType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("spinehaxe.attachments.AttachmentType"); }
		::String __ToString() const { return HX_CSTRING("AttachmentType.") + tag; }

		static ::spinehaxe::attachments::AttachmentType boundingbox;
		static inline ::spinehaxe::attachments::AttachmentType boundingbox_dyn() { return boundingbox; }
		static ::spinehaxe::attachments::AttachmentType region;
		static inline ::spinehaxe::attachments::AttachmentType region_dyn() { return region; }
		static ::spinehaxe::attachments::AttachmentType regionSequence;
		static inline ::spinehaxe::attachments::AttachmentType regionSequence_dyn() { return regionSequence; }
};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_AttachmentType */ 
