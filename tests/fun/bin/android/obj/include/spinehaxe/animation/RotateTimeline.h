#ifndef INCLUDED_spinehaxe_animation_RotateTimeline
#define INCLUDED_spinehaxe_animation_RotateTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/CurveTimeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,CurveTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,RotateTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  RotateTimeline_obj : public ::spinehaxe::animation::CurveTimeline_obj{
	public:
		typedef ::spinehaxe::animation::CurveTimeline_obj super;
		typedef RotateTimeline_obj OBJ_;
		RotateTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RotateTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RotateTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RotateTimeline"); }

		int boneIndex;
		Array< Float > frames;
		virtual Void setFrame( int frameIndex,Float time,Float angle);
		Dynamic setFrame_dyn();

		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);

		static int PREV_FRAME_TIME;
		static int FRAME_VALUE;
};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_RotateTimeline */ 
