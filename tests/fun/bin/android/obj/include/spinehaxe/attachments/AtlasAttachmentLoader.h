#ifndef INCLUDED_spinehaxe_attachments_AtlasAttachmentLoader
#define INCLUDED_spinehaxe_attachments_AtlasAttachmentLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/attachments/AttachmentLoader.h>
HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlas)
HX_DECLARE_CLASS2(spinehaxe,attachments,AtlasAttachmentLoader)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentLoader)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentType)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  AtlasAttachmentLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AtlasAttachmentLoader_obj OBJ_;
		AtlasAttachmentLoader_obj();
		Void __construct(::spinehaxe::atlas::TextureAtlas atlas);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AtlasAttachmentLoader_obj > __new(::spinehaxe::atlas::TextureAtlas atlas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AtlasAttachmentLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::spinehaxe::attachments::AttachmentLoader_obj *()
			{ return new ::spinehaxe::attachments::AttachmentLoader_delegate_< AtlasAttachmentLoader_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("AtlasAttachmentLoader"); }

		::spinehaxe::atlas::TextureAtlas atlas;
		virtual ::spinehaxe::attachments::Attachment newAttachment( ::spinehaxe::Skin skin,::spinehaxe::attachments::AttachmentType type,::String name);
		Dynamic newAttachment_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_AtlasAttachmentLoader */ 
