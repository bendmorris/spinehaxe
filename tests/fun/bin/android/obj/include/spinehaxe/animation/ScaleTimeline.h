#ifndef INCLUDED_spinehaxe_animation_ScaleTimeline
#define INCLUDED_spinehaxe_animation_ScaleTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/TranslateTimeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,CurveTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,ScaleTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
HX_DECLARE_CLASS2(spinehaxe,animation,TranslateTimeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  ScaleTimeline_obj : public ::spinehaxe::animation::TranslateTimeline_obj{
	public:
		typedef ::spinehaxe::animation::TranslateTimeline_obj super;
		typedef ScaleTimeline_obj OBJ_;
		ScaleTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ScaleTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ScaleTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ScaleTimeline"); }

		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_ScaleTimeline */ 
