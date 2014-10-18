#ifndef INCLUDED_openfl_display_Sprite
#define INCLUDED_openfl_display_Sprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,geom,Rectangle)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  Sprite_obj : public ::openfl::display::DisplayObjectContainer_obj{
	public:
		typedef ::openfl::display::DisplayObjectContainer_obj super;
		typedef Sprite_obj OBJ_;
		Sprite_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Sprite_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Sprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Sprite"); }

		bool buttonMode;
		bool useHandCursor;
		virtual Void startDrag( hx::Null< bool >  lockCenter,::openfl::geom::Rectangle bounds);
		Dynamic startDrag_dyn();

		virtual Void stopDrag( );
		Dynamic stopDrag_dyn();

		virtual ::String __getType( );
		Dynamic __getType_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_Sprite */ 
