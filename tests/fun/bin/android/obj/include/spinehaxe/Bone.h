#ifndef INCLUDED_spinehaxe_Bone
#define INCLUDED_spinehaxe_Bone

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Bone)
HX_DECLARE_CLASS1(spinehaxe,BoneData)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Bone_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bone_obj OBJ_;
		Bone_obj();
		Void __construct(::spinehaxe::BoneData data,::spinehaxe::Bone parent);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Bone_obj > __new(::spinehaxe::BoneData data,::spinehaxe::Bone parent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Bone_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bone"); }

		::spinehaxe::BoneData data;
		::spinehaxe::Bone parent;
		Float m00;
		Float m01;
		Float m10;
		Float m11;
		Float worldX;
		Float worldY;
		Float worldRotation;
		Float worldScaleX;
		Float worldScaleY;
		Float x;
		Float y;
		Float rotation;
		Float scaleX;
		Float scaleY;
		virtual Void updateWorldTransform( bool flipX,bool flipY);
		Dynamic updateWorldTransform_dyn();

		virtual Void setToSetupPose( );
		Dynamic setToSetupPose_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static bool yDown;
};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Bone */ 
