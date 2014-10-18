#ifndef INCLUDED_spinehaxe_BoneData
#define INCLUDED_spinehaxe_BoneData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,BoneData)
HX_DECLARE_CLASS1(spinehaxe,Color)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  BoneData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BoneData_obj OBJ_;
		BoneData_obj();
		Void __construct(::String name,::spinehaxe::BoneData parent);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BoneData_obj > __new(::String name,::spinehaxe::BoneData parent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BoneData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoneData"); }

		::spinehaxe::BoneData parent;
		::String name;
		Float length;
		Float x;
		Float y;
		Float rotation;
		Float scaleX;
		Float scaleY;
		bool inheritScale;
		bool inheritRotation;
		bool flipX;
		bool flipY;
		::spinehaxe::Color color;
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::spinehaxe::Color getColor( );
		Dynamic getColor_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_BoneData */ 
