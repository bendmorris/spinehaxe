#ifndef INCLUDED_spinehaxe_Skeleton
#define INCLUDED_spinehaxe_Skeleton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Bone)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS1(spinehaxe,SkeletonData)
HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS1(spinehaxe,Slot)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Skeleton_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Skeleton_obj OBJ_;
		Skeleton_obj();
		Void __construct(::spinehaxe::SkeletonData data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Skeleton_obj > __new(::spinehaxe::SkeletonData data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Skeleton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Skeleton"); }

		::spinehaxe::SkeletonData data;
		Array< ::Dynamic > bones;
		Array< ::Dynamic > slots;
		Array< ::Dynamic > drawOrder;
		::spinehaxe::Skin skin;
		Float r;
		Float g;
		Float b;
		Float a;
		Float time;
		bool flipX;
		bool flipY;
		Float x;
		Float y;
		virtual Void updateWorldTransform( );
		Dynamic updateWorldTransform_dyn();

		virtual Void setToSetupPose( );
		Dynamic setToSetupPose_dyn();

		virtual Void setBonesToSetupPose( );
		Dynamic setBonesToSetupPose_dyn();

		virtual Void setSlotsToSetupPose( );
		Dynamic setSlotsToSetupPose_dyn();

		virtual ::spinehaxe::Bone get_rootBone( );
		Dynamic get_rootBone_dyn();

		virtual ::spinehaxe::Bone findBone( ::String boneName);
		Dynamic findBone_dyn();

		virtual int findBoneIndex( ::String boneName);
		Dynamic findBoneIndex_dyn();

		virtual ::spinehaxe::Slot findSlot( ::String slotName);
		Dynamic findSlot_dyn();

		virtual int findSlotIndex( ::String slotName);
		Dynamic findSlotIndex_dyn();

		virtual ::String set_skinName( ::String skinName);
		Dynamic set_skinName_dyn();

		virtual ::spinehaxe::Skin setSkin( ::spinehaxe::Skin newSkin);
		Dynamic setSkin_dyn();

		virtual ::spinehaxe::attachments::Attachment getAttachmentForSlotName( ::String slotName,::String attachmentName);
		Dynamic getAttachmentForSlotName_dyn();

		virtual ::spinehaxe::attachments::Attachment getAttachmentForSlotIndex( int slotIndex,::String attachmentName);
		Dynamic getAttachmentForSlotIndex_dyn();

		virtual Void setAttachment( ::String slotName,::String attachmentName);
		Dynamic setAttachment_dyn();

		virtual Void update( Float delta);
		Dynamic update_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Skeleton */ 
