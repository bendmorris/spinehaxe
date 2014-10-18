#ifndef INCLUDED_openfl_AssetLibrary
#define INCLUDED_openfl_AssetLibrary

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(openfl,AssetLibrary)
HX_DECLARE_CLASS1(openfl,AssetType)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,MovieClip)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,media,Sound)
HX_DECLARE_CLASS2(openfl,text,Font)
HX_DECLARE_CLASS2(openfl,utils,ByteArray)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace openfl{


class HXCPP_CLASS_ATTRIBUTES  AssetLibrary_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AssetLibrary_obj OBJ_;
		AssetLibrary_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AssetLibrary_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AssetLibrary_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetLibrary"); }

		Dynamic eventCallback;
		virtual bool exists( ::String id,::openfl::AssetType type);
		Dynamic exists_dyn();

		virtual ::openfl::display::BitmapData getBitmapData( ::String id);
		Dynamic getBitmapData_dyn();

		virtual ::openfl::utils::ByteArray getBytes( ::String id);
		Dynamic getBytes_dyn();

		virtual ::openfl::text::Font getFont( ::String id);
		Dynamic getFont_dyn();

		virtual ::openfl::display::MovieClip getMovieClip( ::String id);
		Dynamic getMovieClip_dyn();

		virtual ::openfl::media::Sound getMusic( ::String id);
		Dynamic getMusic_dyn();

		virtual ::String getPath( ::String id);
		Dynamic getPath_dyn();

		virtual ::openfl::media::Sound getSound( ::String id);
		Dynamic getSound_dyn();

		virtual ::String getText( ::String id);
		Dynamic getText_dyn();

		virtual bool isLocal( ::String id,::openfl::AssetType type);
		Dynamic isLocal_dyn();

		virtual Array< ::String > list( ::openfl::AssetType type);
		Dynamic list_dyn();

		virtual Void load( Dynamic handler);
		Dynamic load_dyn();

		virtual Void loadBitmapData( ::String id,Dynamic handler);
		Dynamic loadBitmapData_dyn();

		virtual Void loadBytes( ::String id,Dynamic handler);
		Dynamic loadBytes_dyn();

		virtual Void loadFont( ::String id,Dynamic handler);
		Dynamic loadFont_dyn();

		virtual Void loadMovieClip( ::String id,Dynamic handler);
		Dynamic loadMovieClip_dyn();

		virtual Void loadMusic( ::String id,Dynamic handler);
		Dynamic loadMusic_dyn();

		virtual Void loadSound( ::String id,Dynamic handler);
		Dynamic loadSound_dyn();

		virtual Void loadText( ::String id,Dynamic handler);
		Dynamic loadText_dyn();

};

} // end namespace openfl

#endif /* INCLUDED_openfl_AssetLibrary */ 
