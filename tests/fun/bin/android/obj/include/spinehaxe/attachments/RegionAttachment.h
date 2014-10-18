#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#define INCLUDED_spinehaxe_attachments_RegionAttachment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/attachments/Attachment.h>
HX_DECLARE_CLASS1(spinehaxe,Slot)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureRegion)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,RegionAttachment)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  RegionAttachment_obj : public ::spinehaxe::attachments::Attachment_obj{
	public:
		typedef ::spinehaxe::attachments::Attachment_obj super;
		typedef RegionAttachment_obj OBJ_;
		RegionAttachment_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RegionAttachment_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RegionAttachment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RegionAttachment"); }

		::spinehaxe::atlas::TextureRegion region;
		Float x;
		Float y;
		Float scaleX;
		Float scaleY;
		Float rotation;
		Float width;
		Float height;
		Float r;
		Float g;
		Float b;
		Float a;
		::String path;
		Array< Float > vertices;
		Array< Float > offset;
		virtual Void updateOffset( );
		Dynamic updateOffset_dyn();

		virtual Void setRegion( ::spinehaxe::atlas::TextureRegion region);
		Dynamic setRegion_dyn();

		virtual Void updateVertices( ::spinehaxe::Slot slot);
		Dynamic updateVertices_dyn();

		static int X1;
		static int Y1;
		static int C1;
		static int U1;
		static int V1;
		static int X2;
		static int Y2;
		static int C2;
		static int U2;
		static int V2;
		static int X3;
		static int Y3;
		static int C3;
		static int U3;
		static int V3;
		static int X4;
		static int Y4;
		static int C4;
		static int U4;
		static int V4;
};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_RegionAttachment */ 
