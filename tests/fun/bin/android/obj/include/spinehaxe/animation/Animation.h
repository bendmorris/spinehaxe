#ifndef INCLUDED_spinehaxe_animation_Animation
#define INCLUDED_spinehaxe_animation_Animation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,Animation)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  Animation_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Animation_obj OBJ_;
		Animation_obj();
		Void __construct(::String name,Array< ::spinehaxe::animation::Timeline > timelines,Float duration);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Animation_obj > __new(::String name,Array< ::spinehaxe::animation::Timeline > timelines,Float duration);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Animation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Animation"); }

		Array< ::spinehaxe::animation::Timeline > timelines;
		::String name;
		Float duration;
		virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,bool loop,Array< ::Dynamic > events);
		Dynamic apply_dyn();

		virtual Void mix( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,bool loop,Array< ::Dynamic > events,Float alpha);
		Dynamic mix_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static int binarySearch( Array< Float > values,Float target,int step);
		static Dynamic binarySearch_dyn();

		static int linearSearch( Array< Float > values,Float target,int step);
		static Dynamic linearSearch_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_Animation */ 
