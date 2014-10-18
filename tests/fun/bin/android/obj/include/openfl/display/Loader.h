#ifndef INCLUDED_openfl_display_Loader
#define INCLUDED_openfl_display_Loader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/Sprite.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Loader)
HX_DECLARE_CLASS2(openfl,display,LoaderInfo)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,net,URLLoader)
HX_DECLARE_CLASS2(openfl,net,URLRequest)
HX_DECLARE_CLASS2(openfl,system,LoaderContext)
HX_DECLARE_CLASS2(openfl,utils,ByteArray)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  Loader_obj : public ::openfl::display::Sprite_obj{
	public:
		typedef ::openfl::display::Sprite_obj super;
		typedef Loader_obj OBJ_;
		Loader_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Loader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Loader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Loader"); }

		::openfl::display::DisplayObject content;
		::openfl::display::LoaderInfo contentLoaderInfo;
		::openfl::display::BitmapData __image;
		virtual Void load( ::openfl::net::URLRequest request,::openfl::system::LoaderContext context);
		Dynamic load_dyn();

		virtual Void loadBytes( ::openfl::utils::ByteArray bytes,::openfl::system::LoaderContext context);
		Dynamic loadBytes_dyn();

		virtual Void unload( );
		Dynamic unload_dyn();

		virtual bool __onComplete( ::openfl::utils::ByteArray bytes);
		Dynamic __onComplete_dyn();

		virtual Void contentLoaderInfo_onData( ::openfl::events::Event event);
		Dynamic contentLoaderInfo_onData_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_Loader */ 
