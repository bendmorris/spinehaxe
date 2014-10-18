#ifndef INCLUDED_spinehaxe_animation_AnimationState
#define INCLUDED_spinehaxe_animation_AnimationState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,Animation)
HX_DECLARE_CLASS2(spinehaxe,animation,AnimationState)
HX_DECLARE_CLASS2(spinehaxe,animation,AnimationStateData)
HX_DECLARE_CLASS2(spinehaxe,animation,Listeners)
HX_DECLARE_CLASS2(spinehaxe,animation,TrackEntry)
HX_DECLARE_CLASS2(spinehaxe,animation,TrackEntryPool)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  AnimationState_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AnimationState_obj OBJ_;
		AnimationState_obj();
		Void __construct(::spinehaxe::animation::AnimationStateData data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AnimationState_obj > __new(::spinehaxe::animation::AnimationStateData data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AnimationState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AnimationState"); }

		::spinehaxe::animation::AnimationStateData data;
		Array< ::Dynamic > tracks;
		::spinehaxe::animation::TrackEntryPool trackEntryPool;
		Array< ::Dynamic > events;
		::spinehaxe::animation::Listeners onStart;
		::spinehaxe::animation::Listeners onEnd;
		::spinehaxe::animation::Listeners onComplete;
		::spinehaxe::animation::Listeners onEvent;
		Float timeScale;
		bool clearWhenFinished;
		virtual Void update( Float delta);
		Dynamic update_dyn();

		virtual Void apply( ::spinehaxe::Skeleton skeleton);
		Dynamic apply_dyn();

		virtual Void clearTracks( );
		Dynamic clearTracks_dyn();

		virtual Void clearTrack( int trackIndex);
		Dynamic clearTrack_dyn();

		virtual Void freeAll( ::spinehaxe::animation::TrackEntry entry);
		Dynamic freeAll_dyn();

		virtual ::spinehaxe::animation::TrackEntry expandToIndex( int index);
		Dynamic expandToIndex_dyn();

		virtual Void setCurrent( int index,::spinehaxe::animation::TrackEntry entry);
		Dynamic setCurrent_dyn();

		virtual ::spinehaxe::animation::TrackEntry setAnimationByName( int trackIndex,::String animationName,bool loop);
		Dynamic setAnimationByName_dyn();

		virtual ::spinehaxe::animation::TrackEntry setAnimation( int trackIndex,::spinehaxe::animation::Animation animation,bool loop);
		Dynamic setAnimation_dyn();

		virtual ::spinehaxe::animation::TrackEntry addAnimationByName( int trackIndex,::String animationName,bool loop,Float delay);
		Dynamic addAnimationByName_dyn();

		virtual ::spinehaxe::animation::TrackEntry addAnimation( int trackIndex,::spinehaxe::animation::Animation animation,bool loop,Float delay);
		Dynamic addAnimation_dyn();

		virtual ::spinehaxe::animation::TrackEntry getCurrent( int trackIndex);
		Dynamic getCurrent_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_AnimationState */ 
