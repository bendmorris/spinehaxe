#ifndef INCLUDED_spinehaxe_animation_AnimationStateData
#define INCLUDED_spinehaxe_animation_AnimationStateData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(spinehaxe,SkeletonData)
HX_DECLARE_CLASS2(spinehaxe,animation,Animation)
HX_DECLARE_CLASS2(spinehaxe,animation,AnimationStateData)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  AnimationStateData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AnimationStateData_obj OBJ_;
		AnimationStateData_obj();
		Void __construct(::spinehaxe::SkeletonData skeletonData);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AnimationStateData_obj > __new(::spinehaxe::SkeletonData skeletonData);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AnimationStateData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AnimationStateData"); }

		::spinehaxe::SkeletonData skeletonData;
		::haxe::ds::StringMap animationToMixTime;
		Float defaultMix;
		virtual Void setMixByName( ::String fromName,::String toName,Float duration);
		Dynamic setMixByName_dyn();

		virtual Void setMix( ::spinehaxe::animation::Animation from,::spinehaxe::animation::Animation to,Float duration);
		Dynamic setMix_dyn();

		virtual Float getMix( ::spinehaxe::animation::Animation from,::spinehaxe::animation::Animation to);
		Dynamic getMix_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_AnimationStateData */ 
