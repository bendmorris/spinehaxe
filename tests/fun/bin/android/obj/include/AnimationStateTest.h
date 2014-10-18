#ifndef INCLUDED_AnimationStateTest
#define INCLUDED_AnimationStateTest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/Sprite.h>
HX_DECLARE_CLASS0(AnimationStateTest)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(spinehaxe,Bone)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,AnimationState)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlas)
HX_DECLARE_CLASS4(spinehaxe,platform,nme,renderers,SkeletonRenderer)


class HXCPP_CLASS_ATTRIBUTES  AnimationStateTest_obj : public ::openfl::display::Sprite_obj{
	public:
		typedef ::openfl::display::Sprite_obj super;
		typedef AnimationStateTest_obj OBJ_;
		AnimationStateTest_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AnimationStateTest_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AnimationStateTest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AnimationStateTest"); }

		::spinehaxe::platform::nme::renderers::SkeletonRenderer renderer;
		::spinehaxe::atlas::TextureAtlas atlas;
		::spinehaxe::Skeleton skeleton;
		::spinehaxe::Bone root_;
		::spinehaxe::animation::AnimationState state;
		Float lastTime;
		int mode;
		virtual Void added( ::openfl::events::Event e);
		Dynamic added_dyn();

		virtual Void onClick( ::openfl::events::Event e);
		Dynamic onClick_dyn();

		virtual Void render( ::openfl::events::Event e);
		Dynamic render_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_AnimationStateTest */ 
