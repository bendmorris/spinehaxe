#ifndef INCLUDED_spinehaxe_SkeletonJson
#define INCLUDED_spinehaxe_SkeletonJson

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(spinehaxe,SkeletonData)
HX_DECLARE_CLASS1(spinehaxe,SkeletonJson)
HX_DECLARE_CLASS1(spinehaxe,Skin)
HX_DECLARE_CLASS2(spinehaxe,animation,CurveTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlas)
HX_DECLARE_CLASS2(spinehaxe,attachments,Attachment)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentLoader)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  SkeletonJson_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SkeletonJson_obj OBJ_;
		SkeletonJson_obj();
		Void __construct(::spinehaxe::attachments::AttachmentLoader attachmentLoader);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SkeletonJson_obj > __new(::spinehaxe::attachments::AttachmentLoader attachmentLoader);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SkeletonJson_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SkeletonJson"); }

		::spinehaxe::attachments::AttachmentLoader attachmentLoader;
		Float scale;
		virtual ::spinehaxe::SkeletonData readSkeletonData( ::String fileData,::String name);
		Dynamic readSkeletonData_dyn();

		virtual ::spinehaxe::attachments::Attachment readAttachment( ::spinehaxe::Skin skin,::String name,Dynamic map);
		Dynamic readAttachment_dyn();

		virtual Void readAnimation( ::String name,Dynamic map,::spinehaxe::SkeletonData skeletonData);
		Dynamic readAnimation_dyn();

		virtual Void readCurve( ::spinehaxe::animation::CurveTimeline timeline,int frameIndex,Dynamic valueMap);
		Dynamic readCurve_dyn();

		static ::String TIMELINE_SCALE;
		static ::String TIMELINE_ROTATE;
		static ::String TIMELINE_TRANSLATE;
		static ::String TIMELINE_ATTACHMENT;
		static ::String TIMELINE_COLOR;
		static ::haxe::ds::StringMap parsedJson;
		static ::spinehaxe::SkeletonJson create( ::spinehaxe::atlas::TextureAtlas atlas);
		static Dynamic create_dyn();

		static Float toColor( ::String hexString,int colorIndex);
		static Dynamic toColor_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_SkeletonJson */ 
