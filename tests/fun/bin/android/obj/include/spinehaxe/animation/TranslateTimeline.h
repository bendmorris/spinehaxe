#ifndef INCLUDED_spinehaxe_animation_TranslateTimeline
#define INCLUDED_spinehaxe_animation_TranslateTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/CurveTimeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,CurveTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
HX_DECLARE_CLASS2(spinehaxe,animation,TranslateTimeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  TranslateTimeline_obj : public ::spinehaxe::animation::CurveTimeline_obj{
	public:
		typedef ::spinehaxe::animation::CurveTimeline_obj super;
		typedef TranslateTimeline_obj OBJ_;
		TranslateTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TranslateTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TranslateTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TranslateTimeline"); }

		int boneIndex;
		Array< Float > frames;
		virtual Void setFrame( int frameIndex,Float time,Float x,Float y);
		Dynamic setFrame_dyn();

		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);

		static int PREV_FRAME_TIME;
		static int FRAME_X;
		static int FRAME_Y;
};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_TranslateTimeline */ 
