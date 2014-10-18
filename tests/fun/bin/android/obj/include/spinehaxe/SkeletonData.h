#ifndef INCLUDED_spinehaxe_SkeletonData
#define INCLUDED_spinehaxe_SkeletonData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,BoneData)
HX_DECLARE_CLASS1(spinehaxe,EventData)
HX_DECLARE_CLASS1(spinehaxe,SkeletonData)
HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS1(spinehaxe,SlotData)
HX_DECLARE_CLASS2(spinehaxe,animation,Animation)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  SkeletonData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SkeletonData_obj OBJ_;
		SkeletonData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SkeletonData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SkeletonData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SkeletonData"); }

		::String name;
		Array< ::Dynamic > bones;
		Array< ::Dynamic > slots;
		Array< ::Dynamic > skins;
		::spinehaxe::Skin defaultSkin;
		Array< ::Dynamic > events;
		Array< ::Dynamic > animations;
		virtual Void addBone( ::spinehaxe::BoneData bone);
		Dynamic addBone_dyn();

		virtual ::spinehaxe::BoneData findBone( ::String boneName);
		Dynamic findBone_dyn();

		virtual int findBoneIndex( ::String boneName);
		Dynamic findBoneIndex_dyn();

		virtual Void addSlot( ::spinehaxe::SlotData slot);
		Dynamic addSlot_dyn();

		virtual ::spinehaxe::SlotData findSlot( ::String slotName);
		Dynamic findSlot_dyn();

		virtual int findSlotIndex( ::String slotName);
		Dynamic findSlotIndex_dyn();

		virtual Void addSkin( ::spinehaxe::Skin skin);
		Dynamic addSkin_dyn();

		virtual ::spinehaxe::Skin findSkin( ::String skinName);
		Dynamic findSkin_dyn();

		virtual Void addEvent( ::spinehaxe::EventData eventData);
		Dynamic addEvent_dyn();

		virtual ::spinehaxe::EventData findEvent( ::String eventName);
		Dynamic findEvent_dyn();

		virtual Void addAnimation( ::spinehaxe::animation::Animation animation);
		Dynamic addAnimation_dyn();

		virtual ::spinehaxe::animation::Animation findAnimation( ::String animationName);
		Dynamic findAnimation_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_SkeletonData */ 
