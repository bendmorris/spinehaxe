#ifndef INCLUDED_spinehaxe_animation_TrackEntry
#define INCLUDED_spinehaxe_animation_TrackEntry

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,animation,Animation)
HX_DECLARE_CLASS2(spinehaxe,animation,TrackEntry)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  TrackEntry_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TrackEntry_obj OBJ_;
		TrackEntry_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TrackEntry_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TrackEntry_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TrackEntry"); }

		::spinehaxe::animation::TrackEntry next;
		::spinehaxe::animation::TrackEntry previous;
		::spinehaxe::animation::Animation animation;
		bool loop;
		Float delay;
		Float time;
		Float lastTime;
		Float endTime;
		Float timeScale;
		Float mixTime;
		Float mixDuration;
		Float mix;
		Dynamic onStart;
		Dynamic onEnd;
		Dynamic onComplete;
		Dynamic onEvent;
		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_TrackEntry */ 
