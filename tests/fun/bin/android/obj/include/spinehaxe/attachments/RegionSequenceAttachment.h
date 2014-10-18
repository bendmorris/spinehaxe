#ifndef INCLUDED_spinehaxe_attachments_RegionSequenceAttachment
#define INCLUDED_spinehaxe_attachments_RegionSequenceAttachment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/attachments/RegionAttachment.h>
HX_DECLARE_CLASS1(spinehaxe,Slot)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureRegion)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,Mode)
HX_DECLARE_CLASS2(spinehaxe,attachments,RegionAttachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,RegionSequenceAttachment)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  RegionSequenceAttachment_obj : public ::spinehaxe::attachments::RegionAttachment_obj{
	public:
		typedef ::spinehaxe::attachments::RegionAttachment_obj super;
		typedef RegionSequenceAttachment_obj OBJ_;
		RegionSequenceAttachment_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RegionSequenceAttachment_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RegionSequenceAttachment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RegionSequenceAttachment"); }

		::spinehaxe::attachments::Mode mode;
		Float frameTime;
		Array< ::Dynamic > regions;
		virtual Void updateVertices( ::spinehaxe::Slot slot);

		virtual Array< ::Dynamic > getRegions( );
		Dynamic getRegions_dyn();

		virtual Void setRegions( Array< ::Dynamic > regions);
		Dynamic setRegions_dyn();

		virtual Void setFrameTime( Float frameTime);
		Dynamic setFrameTime_dyn();

		virtual Void setMode( ::spinehaxe::attachments::Mode mode);
		Dynamic setMode_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_RegionSequenceAttachment */ 
