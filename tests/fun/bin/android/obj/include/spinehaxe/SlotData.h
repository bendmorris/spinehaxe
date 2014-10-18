#ifndef INCLUDED_spinehaxe_SlotData
#define INCLUDED_spinehaxe_SlotData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,BoneData)
HX_DECLARE_CLASS1(spinehaxe,SlotData)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  SlotData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SlotData_obj OBJ_;
		SlotData_obj();
		Void __construct(::String name,::spinehaxe::BoneData boneData);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SlotData_obj > __new(::String name,::spinehaxe::BoneData boneData);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SlotData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SlotData"); }

		::String name;
		::spinehaxe::BoneData boneData;
		Float r;
		Float g;
		Float b;
		Float a;
		::String attachmentName;
		bool additiveBlending;
		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_SlotData */ 
