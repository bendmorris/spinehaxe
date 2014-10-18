#ifndef INCLUDED_spinehaxe_animation_CurveTimeline
#define INCLUDED_spinehaxe_animation_CurveTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/Timeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,CurveTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  CurveTimeline_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CurveTimeline_obj OBJ_;
		CurveTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CurveTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CurveTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::spinehaxe::animation::Timeline_obj *()
			{ return new ::spinehaxe::animation::Timeline_delegate_< CurveTimeline_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("CurveTimeline"); }

		Array< Float > curves;
		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);
		Dynamic apply_dyn();

		virtual int get_frameCount( );
		Dynamic get_frameCount_dyn();

		virtual Void setLinear( int frameIndex);
		Dynamic setLinear_dyn();

		virtual Void setStepped( int frameIndex);
		Dynamic setStepped_dyn();

		virtual Void setCurve( int frameIndex,Float cx1,Float cy1,Float cx2,Float cy2);
		Dynamic setCurve_dyn();

		virtual Float getCurvePercent( int frameIndex,Float percent);
		Dynamic getCurvePercent_dyn();

		static Float LINEAR;
		static Float STEPPED;
		static int BEZIER_SEGMENTS;
};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_CurveTimeline */ 
