#ifndef INCLUDED_spinehaxe_animation_EventTimeline
#define INCLUDED_spinehaxe_animation_EventTimeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/animation/Timeline.h>
HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,EventTimeline)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  EventTimeline_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventTimeline_obj OBJ_;
		EventTimeline_obj();
		Void __construct(int frameCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EventTimeline_obj > __new(int frameCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventTimeline_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::spinehaxe::animation::Timeline_obj *()
			{ return new ::spinehaxe::animation::Timeline_delegate_< EventTimeline_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("EventTimeline"); }

		Array< Float > frames;
		Array< ::Dynamic > events;
		virtual int get_frameCount( );
		Dynamic get_frameCount_dyn();

		virtual Void setFrame( int frameIndex,Float time,::spinehaxe::Event event);
		Dynamic setFrame_dyn();

		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha);
		Dynamic apply_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_EventTimeline */ 
