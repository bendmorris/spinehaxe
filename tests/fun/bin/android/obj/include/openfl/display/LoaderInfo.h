#ifndef INCLUDED_openfl_display_LoaderInfo
#define INCLUDED_openfl_display_LoaderInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/net/URLLoader.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
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
HX_DECLARE_CLASS2(openfl,events,UncaughtErrorEvents)
HX_DECLARE_CLASS2(openfl,net,URLLoader)
HX_DECLARE_CLASS2(openfl,net,URLRequest)
HX_DECLARE_CLASS2(openfl,system,ApplicationDomain)
HX_DECLARE_CLASS2(openfl,utils,ByteArray)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  LoaderInfo_obj : public ::openfl::net::URLLoader_obj{
	public:
		typedef ::openfl::net::URLLoader_obj super;
		typedef LoaderInfo_obj OBJ_;
		LoaderInfo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LoaderInfo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LoaderInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LoaderInfo"); }

		::openfl::system::ApplicationDomain applicationDomain;
		::openfl::utils::ByteArray bytes;
		bool childAllowsParent;
		::openfl::display::DisplayObject content;
		::String contentType;
		Float frameRate;
		int height;
		::openfl::display::Loader loader;
		::String loaderURL;
		Dynamic parameters;
		bool parentAllowsChild;
		bool sameDomain;
		::openfl::events::EventDispatcher sharedEvents;
		::String url;
		int width;
		::openfl::events::UncaughtErrorEvents uncaughtErrorEvents;
		::String __pendingURL;
		virtual Void load( ::openfl::net::URLRequest request);

		virtual Void this_onComplete( ::openfl::events::Event event);
		Dynamic this_onComplete_dyn();

		virtual ::openfl::utils::ByteArray get_bytes( );
		Dynamic get_bytes_dyn();

		static ::openfl::display::LoaderInfo create( ::openfl::display::Loader loader);
		static Dynamic create_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_LoaderInfo */ 
