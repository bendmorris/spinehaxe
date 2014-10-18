#ifndef INCLUDED_spinehaxe_platform_nme_renderers_SkeletonRenderer
#define INCLUDED_spinehaxe_platform_nme_renderers_SkeletonRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/Sprite.h>
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS4(spinehaxe,platform,nme,renderers,SkeletonRenderer)
namespace spinehaxe{
namespace platform{
namespace nme{
namespace renderers{


class HXCPP_CLASS_ATTRIBUTES  SkeletonRenderer_obj : public ::openfl::display::Sprite_obj{
	public:
		typedef ::openfl::display::Sprite_obj super;
		typedef SkeletonRenderer_obj OBJ_;
		SkeletonRenderer_obj();
		Void __construct(::spinehaxe::Skeleton skeleton);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SkeletonRenderer_obj > __new(::spinehaxe::Skeleton skeleton);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SkeletonRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SkeletonRenderer"); }

		::spinehaxe::Skeleton skeleton;
		Array< Float > vs;
		Array< int > idx;
		Array< Float > uvt;
		::openfl::display::BitmapData bd;
		bool filled;
		virtual Void clearBuffers( );
		Dynamic clearBuffers_dyn();

		virtual Void draw( );
		Dynamic draw_dyn();

};

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme
} // end namespace renderers

#endif /* INCLUDED_spinehaxe_platform_nme_renderers_SkeletonRenderer */ 
