#ifndef INCLUDED_spinehaxe_Slot
#define INCLUDED_spinehaxe_Slot

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Bone)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS1(spinehaxe,Slot)
HX_DECLARE_CLASS1(spinehaxe,SlotData)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Slot_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Slot_obj OBJ_;
		Slot_obj();
		Void __construct(::spinehaxe::SlotData data,::spinehaxe::Skeleton skeleton,::spinehaxe::Bone bone);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Slot_obj > __new(::spinehaxe::SlotData data,::spinehaxe::Skeleton skeleton,::spinehaxe::Bone bone);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Slot_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Slot"); }

		::spinehaxe::SlotData data;
		::spinehaxe::Skeleton skeleton;
		::spinehaxe::Bone bone;
		::spinehaxe::attachments::Attachment attachment;
		Float r;
		Float g;
		Float b;
		Float a;
		Float _attachmentTime;
		Array< Float > attachmentVertices;
		virtual ::spinehaxe::attachments::Attachment set_attachment( ::spinehaxe::attachments::Attachment attachment);
		Dynamic set_attachment_dyn();

		virtual Float set_attachmentTime( Float time);
		Dynamic set_attachmentTime_dyn();

		virtual Float get_attachmentTime( );
		Dynamic get_attachmentTime_dyn();

		virtual Void setToSetupPose( );
		Dynamic setToSetupPose_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Slot */ 
