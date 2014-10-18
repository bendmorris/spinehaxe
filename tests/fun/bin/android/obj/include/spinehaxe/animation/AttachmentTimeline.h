#ifndef INCLUDED_spinehaxe_animation_AttachmentTimeline
#define INCLUDED_spinehaxe_animation_AttachmentTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/Timeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,AttachmentTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  AttachmentTimeline_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AttachmentTimeline_obj OBJ_;
		AttachmentTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AttachmentTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AttachmentTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::spinehaxe::animation::Timeline_obj *()
			{ return new ::spinehaxe::animation::Timeline_delegate_< AttachmentTimeline_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("AttachmentTimeline"); }

		int slotIndex;
		Array< Float > frames;
		Array< ::String > attachmentNames;
		virtual int get_frameCount( );
		Dynamic get_frameCount_dyn();

		virtual Void setFrame( int frameIndex,Float time,::String attachmentName);
		Dynamic setFrame_dyn();

		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);
		Dynamic apply_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_AttachmentTimeline */ 
