#ifndef INCLUDED_spinehaxe_Skin
#define INCLUDED_spinehaxe_Skin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Skin_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Skin_obj OBJ_;
		Skin_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Skin_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Skin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Skin"); }

		::String name;
		::haxe::ds::StringMap attachments;
		virtual Void addAttachment( int slotIndex,::String name,::spinehaxe::attachments::Attachment attachment);
		Dynamic addAttachment_dyn();

		virtual ::spinehaxe::attachments::Attachment getAttachment( int slotIndex,::String name);
		Dynamic getAttachment_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void attachAll( ::spinehaxe::Skeleton skeleton,::spinehaxe::Skin oldSkin);
		Dynamic attachAll_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Skin */ 
