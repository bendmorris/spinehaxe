#ifndef INCLUDED_spinehaxe_attachments_BoundingBoxAttachment
#define INCLUDED_spinehaxe_attachments_BoundingBoxAttachment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/attachments/Attachment.h>
HX_DECLARE_CLASS1(spinehaxe,Bone)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,BoundingBoxAttachment)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  BoundingBoxAttachment_obj : public ::spinehaxe::attachments::Attachment_obj{
	public:
		typedef ::spinehaxe::attachments::Attachment_obj super;
		typedef BoundingBoxAttachment_obj OBJ_;
		BoundingBoxAttachment_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BoundingBoxAttachment_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BoundingBoxAttachment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoundingBoxAttachment"); }

		Array< Float > vertices;
		virtual Void computeWorldVertices( Float x,Float y,::spinehaxe::Bone bone,Array< Float > worldVertices);
		Dynamic computeWorldVertices_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_BoundingBoxAttachment */ 
