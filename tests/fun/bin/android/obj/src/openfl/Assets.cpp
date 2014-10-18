#include <hxcpp.h>

#ifndef INCLUDED_DefaultAssetLibrary
#include <DefaultAssetLibrary.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_AssetCache
#include <openfl/AssetCache.h>
#endif
#ifndef INCLUDED_openfl_AssetLibrary
#include <openfl/AssetLibrary.h>
#endif
#ifndef INCLUDED_openfl_AssetType
#include <openfl/AssetType.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_Sound
#include <openfl/media/Sound.h>
#endif
#ifndef INCLUDED_openfl_text_Font
#include <openfl/text/Font.h>
#endif
#ifndef INCLUDED_openfl_utils_ByteArray
#include <openfl/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataInput
#include <openfl/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataOutput
#include <openfl/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace openfl{

Void Assets_obj::__construct()
{
	return null();
}

//Assets_obj::~Assets_obj() { }

Dynamic Assets_obj::__CreateEmpty() { return  new Assets_obj; }
hx::ObjectPtr< Assets_obj > Assets_obj::__new()
{  hx::ObjectPtr< Assets_obj > result = new Assets_obj();
	result->__construct();
	return result;}

Dynamic Assets_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Assets_obj > result = new Assets_obj();
	result->__construct();
	return result;}

::openfl::AssetCache Assets_obj::cache;

::haxe::ds::StringMap Assets_obj::libraries;

::openfl::events::EventDispatcher Assets_obj::dispatcher;

bool Assets_obj::initialized;

Void Assets_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture,hx::Null< int >  __o_priority,hx::Null< bool >  __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_STACK_FRAME("openfl.Assets","addEventListener",0x08307d1a,"openfl.Assets.addEventListener","openfl/Assets.hx",45,0x989d477c)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(useCapture,"useCapture")
	HX_STACK_ARG(priority,"priority")
	HX_STACK_ARG(useWeakReference,"useWeakReference")
{
		HX_STACK_LINE(47)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(49)
		::openfl::Assets_obj::dispatcher->addEventListener(type,listener,useCapture,priority,useWeakReference);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Assets_obj,addEventListener,(void))

bool Assets_obj::dispatchEvent( ::openfl::events::Event event){
	HX_STACK_FRAME("openfl.Assets","dispatchEvent",0xff6e3393,"openfl.Assets.dispatchEvent","openfl/Assets.hx",54,0x989d477c)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(56)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(58)
	return ::openfl::Assets_obj::dispatcher->dispatchEvent(event);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,dispatchEvent,return )

bool Assets_obj::exists( ::String id,::openfl::AssetType type){
	HX_STACK_FRAME("openfl.Assets","exists",0xd3fc5ce9,"openfl.Assets.exists","openfl/Assets.hx",63,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(65)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(69)
	if (((type == null()))){
		HX_STACK_LINE(71)
		type = ::openfl::AssetType_obj::BINARY;
	}
	HX_STACK_LINE(75)
	int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(75)
	::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
	HX_STACK_LINE(76)
	int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(76)
	int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(76)
	::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
	HX_STACK_LINE(77)
	::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
	HX_STACK_LINE(79)
	if (((library != null()))){
		HX_STACK_LINE(81)
		return library->exists(symbolName,type);
	}
	HX_STACK_LINE(87)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,exists,return )

::openfl::display::BitmapData Assets_obj::getBitmapData( ::String id,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","getBitmapData",0xc93c7e82,"openfl.Assets.getBitmapData","openfl/Assets.hx",99,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(101)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(105)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->bitmapData->exists(id)) : bool(false) ))){
			HX_STACK_LINE(107)
			::openfl::display::BitmapData bitmapData = ::openfl::Assets_obj::cache->bitmapData->get(id);		HX_STACK_VAR(bitmapData,"bitmapData");
			HX_STACK_LINE(109)
			if ((::openfl::Assets_obj::isValidBitmapData(bitmapData))){
				HX_STACK_LINE(111)
				return bitmapData;
			}
		}
		HX_STACK_LINE(117)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(118)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(118)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(118)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(119)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(121)
		if (((library != null()))){
			HX_STACK_LINE(123)
			if ((library->exists(symbolName,::openfl::AssetType_obj::IMAGE))){
				HX_STACK_LINE(125)
				if ((library->isLocal(symbolName,::openfl::AssetType_obj::IMAGE))){
					HX_STACK_LINE(127)
					::openfl::display::BitmapData bitmapData = library->getBitmapData(symbolName);		HX_STACK_VAR(bitmapData,"bitmapData");
					HX_STACK_LINE(129)
					if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){
						HX_STACK_LINE(131)
						::openfl::Assets_obj::cache->bitmapData->set(id,bitmapData);
					}
					HX_STACK_LINE(135)
					return bitmapData;
				}
				else{
					HX_STACK_LINE(139)
					::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] BitmapData asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),139,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBitmapData")));
				}
			}
			else{
				HX_STACK_LINE(145)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no BitmapData asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),145,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBitmapData")));
			}
		}
		else{
			HX_STACK_LINE(151)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),151,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBitmapData")));
		}
		HX_STACK_LINE(157)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,getBitmapData,return )

::openfl::utils::ByteArray Assets_obj::getBytes( ::String id){
	HX_STACK_FRAME("openfl.Assets","getBytes",0xa062f442,"openfl.Assets.getBytes","openfl/Assets.hx",168,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(170)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(174)
	int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(174)
	::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
	HX_STACK_LINE(175)
	int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(175)
	int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(175)
	::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
	HX_STACK_LINE(176)
	::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
	HX_STACK_LINE(178)
	if (((library != null()))){
		HX_STACK_LINE(180)
		if ((library->exists(symbolName,::openfl::AssetType_obj::BINARY))){
			HX_STACK_LINE(182)
			if ((library->isLocal(symbolName,::openfl::AssetType_obj::BINARY))){
				HX_STACK_LINE(184)
				return library->getBytes(symbolName);
			}
			else{
				HX_STACK_LINE(188)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] String or ByteArray asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),188,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBytes")));
			}
		}
		else{
			HX_STACK_LINE(194)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no String or ByteArray asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),194,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBytes")));
		}
	}
	else{
		HX_STACK_LINE(200)
		::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),200,HX_CSTRING("openfl.Assets"),HX_CSTRING("getBytes")));
	}
	HX_STACK_LINE(206)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getBytes,return )

::openfl::text::Font Assets_obj::getFont( ::String id,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","getFont",0x9addf9d8,"openfl.Assets.getFont","openfl/Assets.hx",217,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(219)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(223)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->font->exists(id)) : bool(false) ))){
			HX_STACK_LINE(225)
			return ::openfl::Assets_obj::cache->font->get(id);
		}
		HX_STACK_LINE(229)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(229)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(230)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(230)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(230)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(231)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(233)
		if (((library != null()))){
			HX_STACK_LINE(235)
			if ((library->exists(symbolName,::openfl::AssetType_obj::FONT))){
				HX_STACK_LINE(237)
				if ((library->isLocal(symbolName,::openfl::AssetType_obj::FONT))){
					HX_STACK_LINE(239)
					::openfl::text::Font font = library->getFont(symbolName);		HX_STACK_VAR(font,"font");
					HX_STACK_LINE(241)
					if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){
						HX_STACK_LINE(243)
						::openfl::Assets_obj::cache->font->set(id,font);
					}
					HX_STACK_LINE(247)
					return font;
				}
				else{
					HX_STACK_LINE(251)
					::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] Font asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),251,HX_CSTRING("openfl.Assets"),HX_CSTRING("getFont")));
				}
			}
			else{
				HX_STACK_LINE(257)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Font asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),257,HX_CSTRING("openfl.Assets"),HX_CSTRING("getFont")));
			}
		}
		else{
			HX_STACK_LINE(263)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),263,HX_CSTRING("openfl.Assets"),HX_CSTRING("getFont")));
		}
		HX_STACK_LINE(269)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,getFont,return )

::openfl::AssetLibrary Assets_obj::getLibrary( ::String name){
	HX_STACK_FRAME("openfl.Assets","getLibrary",0x9baef692,"openfl.Assets.getLibrary","openfl/Assets.hx",274,0x989d477c)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(276)
	if (((bool((name == null())) || bool((name == HX_CSTRING("")))))){
		HX_STACK_LINE(278)
		name = HX_CSTRING("default");
	}
	HX_STACK_LINE(282)
	return ::openfl::Assets_obj::libraries->get(name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getLibrary,return )

::openfl::display::MovieClip Assets_obj::getMovieClip( ::String id){
	HX_STACK_FRAME("openfl.Assets","getMovieClip",0x1d5e25f7,"openfl.Assets.getMovieClip","openfl/Assets.hx",293,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(295)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(299)
	int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(299)
	::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
	HX_STACK_LINE(300)
	int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(300)
	int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(300)
	::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
	HX_STACK_LINE(301)
	::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
	HX_STACK_LINE(303)
	if (((library != null()))){
		HX_STACK_LINE(305)
		if ((library->exists(symbolName,::openfl::AssetType_obj::MOVIE_CLIP))){
			HX_STACK_LINE(307)
			if ((library->isLocal(symbolName,::openfl::AssetType_obj::MOVIE_CLIP))){
				HX_STACK_LINE(309)
				return library->getMovieClip(symbolName);
			}
			else{
				HX_STACK_LINE(313)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] MovieClip asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),313,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMovieClip")));
			}
		}
		else{
			HX_STACK_LINE(319)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no MovieClip asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),319,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMovieClip")));
		}
	}
	else{
		HX_STACK_LINE(325)
		::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),325,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMovieClip")));
	}
	HX_STACK_LINE(331)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getMovieClip,return )

::openfl::media::Sound Assets_obj::getMusic( ::String id,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","getMusic",0xf325bc7c,"openfl.Assets.getMusic","openfl/Assets.hx",342,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(344)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(348)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->sound->exists(id)) : bool(false) ))){
			HX_STACK_LINE(350)
			::openfl::media::Sound sound = ::openfl::Assets_obj::cache->sound->get(id);		HX_STACK_VAR(sound,"sound");
			HX_STACK_LINE(352)
			if ((::openfl::Assets_obj::isValidSound(sound))){
				HX_STACK_LINE(354)
				return sound;
			}
		}
		HX_STACK_LINE(360)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(360)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(361)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(361)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(361)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(362)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(364)
		if (((library != null()))){
			HX_STACK_LINE(366)
			if ((library->exists(symbolName,::openfl::AssetType_obj::MUSIC))){
				HX_STACK_LINE(368)
				if ((library->isLocal(symbolName,::openfl::AssetType_obj::MUSIC))){
					HX_STACK_LINE(370)
					::openfl::media::Sound sound = library->getMusic(symbolName);		HX_STACK_VAR(sound,"sound");
					HX_STACK_LINE(372)
					if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){
						HX_STACK_LINE(374)
						::openfl::Assets_obj::cache->sound->set(id,sound);
					}
					HX_STACK_LINE(378)
					return sound;
				}
				else{
					HX_STACK_LINE(382)
					::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] Sound asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),382,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMusic")));
				}
			}
			else{
				HX_STACK_LINE(388)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Sound asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),388,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMusic")));
			}
		}
		else{
			HX_STACK_LINE(394)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),394,HX_CSTRING("openfl.Assets"),HX_CSTRING("getMusic")));
		}
		HX_STACK_LINE(400)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,getMusic,return )

::String Assets_obj::getPath( ::String id){
	HX_STACK_FRAME("openfl.Assets","getPath",0xa16f81ae,"openfl.Assets.getPath","openfl/Assets.hx",411,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(413)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(417)
	int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(417)
	::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
	HX_STACK_LINE(418)
	int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(418)
	int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(418)
	::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
	HX_STACK_LINE(419)
	::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
	HX_STACK_LINE(421)
	if (((library != null()))){
		HX_STACK_LINE(423)
		if ((library->exists(symbolName,null()))){
			HX_STACK_LINE(425)
			return library->getPath(symbolName);
		}
		else{
			HX_STACK_LINE(429)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),429,HX_CSTRING("openfl.Assets"),HX_CSTRING("getPath")));
		}
	}
	else{
		HX_STACK_LINE(435)
		::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),435,HX_CSTRING("openfl.Assets"),HX_CSTRING("getPath")));
	}
	HX_STACK_LINE(441)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getPath,return )

::openfl::media::Sound Assets_obj::getSound( ::String id,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","getSound",0x639778a6,"openfl.Assets.getSound","openfl/Assets.hx",452,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(454)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(458)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->sound->exists(id)) : bool(false) ))){
			HX_STACK_LINE(460)
			::openfl::media::Sound sound = ::openfl::Assets_obj::cache->sound->get(id);		HX_STACK_VAR(sound,"sound");
			HX_STACK_LINE(462)
			if ((::openfl::Assets_obj::isValidSound(sound))){
				HX_STACK_LINE(464)
				return sound;
			}
		}
		HX_STACK_LINE(470)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(470)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(471)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(471)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(471)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(472)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(474)
		if (((library != null()))){
			HX_STACK_LINE(476)
			if ((library->exists(symbolName,::openfl::AssetType_obj::SOUND))){
				HX_STACK_LINE(478)
				if ((library->isLocal(symbolName,::openfl::AssetType_obj::SOUND))){
					HX_STACK_LINE(480)
					::openfl::media::Sound sound = library->getSound(symbolName);		HX_STACK_VAR(sound,"sound");
					HX_STACK_LINE(482)
					if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){
						HX_STACK_LINE(484)
						::openfl::Assets_obj::cache->sound->set(id,sound);
					}
					HX_STACK_LINE(488)
					return sound;
				}
				else{
					HX_STACK_LINE(492)
					::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] Sound asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),492,HX_CSTRING("openfl.Assets"),HX_CSTRING("getSound")));
				}
			}
			else{
				HX_STACK_LINE(498)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Sound asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),498,HX_CSTRING("openfl.Assets"),HX_CSTRING("getSound")));
			}
		}
		else{
			HX_STACK_LINE(504)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),504,HX_CSTRING("openfl.Assets"),HX_CSTRING("getSound")));
		}
		HX_STACK_LINE(510)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,getSound,return )

::String Assets_obj::getText( ::String id){
	HX_STACK_FRAME("openfl.Assets","getText",0xa41768b6,"openfl.Assets.getText","openfl/Assets.hx",521,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(523)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(527)
	int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(527)
	::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
	HX_STACK_LINE(528)
	int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(528)
	int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(528)
	::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
	HX_STACK_LINE(529)
	::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
	HX_STACK_LINE(531)
	if (((library != null()))){
		HX_STACK_LINE(533)
		if ((library->exists(symbolName,::openfl::AssetType_obj::TEXT))){
			HX_STACK_LINE(535)
			if ((library->isLocal(symbolName,::openfl::AssetType_obj::TEXT))){
				HX_STACK_LINE(537)
				return library->getText(symbolName);
			}
			else{
				HX_STACK_LINE(541)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] String asset \"") + id) + HX_CSTRING("\" exists, but only asynchronously")),hx::SourceInfo(HX_CSTRING("Assets.hx"),541,HX_CSTRING("openfl.Assets"),HX_CSTRING("getText")));
			}
		}
		else{
			HX_STACK_LINE(547)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no String asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),547,HX_CSTRING("openfl.Assets"),HX_CSTRING("getText")));
		}
	}
	else{
		HX_STACK_LINE(553)
		::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),553,HX_CSTRING("openfl.Assets"),HX_CSTRING("getText")));
	}
	HX_STACK_LINE(559)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getText,return )

bool Assets_obj::hasEventListener( ::String type){
	HX_STACK_FRAME("openfl.Assets","hasEventListener",0x23b6a041,"openfl.Assets.hasEventListener","openfl/Assets.hx",564,0x989d477c)
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(566)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(568)
	return ::openfl::Assets_obj::dispatcher->hasEventListener(type);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,hasEventListener,return )

Void Assets_obj::initialize( ){
{
		HX_STACK_FRAME("openfl.Assets","initialize",0xf9987add,"openfl.Assets.initialize","openfl/Assets.hx",575,0x989d477c)
		HX_STACK_LINE(575)
		if ((!(::openfl::Assets_obj::initialized))){
			HX_STACK_LINE(579)
			::DefaultAssetLibrary _g = ::DefaultAssetLibrary_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(579)
			::openfl::Assets_obj::registerLibrary(HX_CSTRING("default"),_g);
			HX_STACK_LINE(583)
			::openfl::Assets_obj::initialized = true;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Assets_obj,initialize,(void))

bool Assets_obj::isLocal( ::String id,::openfl::AssetType type,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","isLocal",0x9a115974,"openfl.Assets.isLocal","openfl/Assets.hx",590,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(592)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(596)
		if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){
			HX_STACK_LINE(598)
			if (((bool((type == ::openfl::AssetType_obj::IMAGE)) || bool((type == null()))))){
				HX_STACK_LINE(600)
				if ((::openfl::Assets_obj::cache->bitmapData->exists(id))){
					HX_STACK_LINE(600)
					return true;
				}
			}
			HX_STACK_LINE(604)
			if (((bool((type == ::openfl::AssetType_obj::FONT)) || bool((type == null()))))){
				HX_STACK_LINE(606)
				if ((::openfl::Assets_obj::cache->font->exists(id))){
					HX_STACK_LINE(606)
					return true;
				}
			}
			HX_STACK_LINE(610)
			if (((bool((bool((type == ::openfl::AssetType_obj::SOUND)) || bool((type == ::openfl::AssetType_obj::MUSIC)))) || bool((type == null()))))){
				HX_STACK_LINE(612)
				if ((::openfl::Assets_obj::cache->sound->exists(id))){
					HX_STACK_LINE(612)
					return true;
				}
			}
		}
		HX_STACK_LINE(618)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(618)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(619)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(619)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(619)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(620)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(622)
		if (((library != null()))){
			HX_STACK_LINE(624)
			return library->isLocal(symbolName,type);
		}
		HX_STACK_LINE(630)
		return false;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,isLocal,return )

bool Assets_obj::isValidBitmapData( ::openfl::display::BitmapData bitmapData){
	HX_STACK_FRAME("openfl.Assets","isValidBitmapData",0xc2fb171e,"openfl.Assets.isValidBitmapData","openfl/Assets.hx",635,0x989d477c)
	HX_STACK_ARG(bitmapData,"bitmapData")
	HX_STACK_LINE(640)
	return (bitmapData->__handle != null());
	HX_STACK_LINE(661)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,isValidBitmapData,return )

bool Assets_obj::isValidSound( ::openfl::media::Sound sound){
	HX_STACK_FRAME("openfl.Assets","isValidSound",0x9717a58a,"openfl.Assets.isValidSound","openfl/Assets.hx",666,0x989d477c)
	HX_STACK_ARG(sound,"sound")
	HX_STACK_LINE(671)
	return (bool((sound->__handle != null())) && bool((sound->__handle != (int)0)));
	HX_STACK_LINE(676)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,isValidSound,return )

Array< ::String > Assets_obj::list( ::openfl::AssetType type){
	HX_STACK_FRAME("openfl.Assets","list",0xb0f58e2b,"openfl.Assets.list","openfl/Assets.hx",681,0x989d477c)
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(683)
	::openfl::Assets_obj::initialize();
	HX_STACK_LINE(685)
	Array< ::String > items = Array_obj< ::String >::__new();		HX_STACK_VAR(items,"items");
	HX_STACK_LINE(687)
	for(::cpp::FastIterator_obj< ::openfl::AssetLibrary > *__it = ::cpp::CreateFastIterator< ::openfl::AssetLibrary >(::openfl::Assets_obj::libraries->iterator());  __it->hasNext(); ){
		::openfl::AssetLibrary library = __it->next();
		{
			HX_STACK_LINE(689)
			Array< ::String > libraryItems = library->list(type);		HX_STACK_VAR(libraryItems,"libraryItems");
			HX_STACK_LINE(691)
			if (((libraryItems != null()))){
				HX_STACK_LINE(693)
				Array< ::String > _g = items->concat(libraryItems);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(693)
				items = _g;
			}
		}
;
	}
	HX_STACK_LINE(699)
	return items;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,list,return )

Void Assets_obj::loadBitmapData( ::String id,Dynamic handler,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","loadBitmapData",0x79a7538c,"openfl.Assets.loadBitmapData","openfl/Assets.hx",704,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(704)
		Dynamic handler1 = Dynamic( Array_obj<Dynamic>::__new().Add(handler));		HX_STACK_VAR(handler1,"handler1");
		HX_STACK_LINE(704)
		Array< ::String > id1 = Array_obj< ::String >::__new().Add(id);		HX_STACK_VAR(id1,"id1");
		HX_STACK_LINE(706)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(710)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->bitmapData->exists(id1->__get((int)0))) : bool(false) ))){
			HX_STACK_LINE(712)
			::openfl::display::BitmapData bitmapData = ::openfl::Assets_obj::cache->bitmapData->get(id1->__get((int)0));		HX_STACK_VAR(bitmapData,"bitmapData");
			HX_STACK_LINE(714)
			if ((::openfl::Assets_obj::isValidBitmapData(bitmapData))){
				HX_STACK_LINE(716)
				handler1->__GetItem((int)0)(bitmapData).Cast< Void >();
				HX_STACK_LINE(717)
				return null();
			}
		}
		HX_STACK_LINE(723)
		int _g = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(723)
		::String libraryName = id1->__get((int)0).substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(724)
		int _g1 = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(724)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(724)
		::String symbolName = id1->__get((int)0).substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(725)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(727)
		if (((library != null()))){
			HX_STACK_LINE(729)
			if ((library->exists(symbolName,::openfl::AssetType_obj::IMAGE))){
				HX_STACK_LINE(731)
				if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,handler1,Array< ::String >,id1)
					Void run(::openfl::display::BitmapData bitmapData){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","openfl/Assets.hx",733,0x989d477c)
						HX_STACK_ARG(bitmapData,"bitmapData")
						{
							HX_STACK_LINE(735)
							::openfl::Assets_obj::cache->bitmapData->set(id1->__get((int)0),bitmapData);
							HX_STACK_LINE(736)
							handler1->__GetItem((int)0)(bitmapData).Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(733)
					library->loadBitmapData(symbolName, Dynamic(new _Function_4_1(handler1,id1)));
				}
				else{
					HX_STACK_LINE(742)
					library->loadBitmapData(symbolName,handler1->__GetItem((int)0));
				}
				HX_STACK_LINE(746)
				return null();
			}
			else{
				HX_STACK_LINE(750)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no BitmapData asset with an ID of \"") + id1->__get((int)0)) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),750,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadBitmapData")));
			}
		}
		else{
			HX_STACK_LINE(756)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),756,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadBitmapData")));
		}
		HX_STACK_LINE(762)
		handler1->__GetItem((int)0)(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,loadBitmapData,(void))

Void Assets_obj::loadBytes( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.Assets","loadBytes",0xeb3c3b78,"openfl.Assets.loadBytes","openfl/Assets.hx",767,0x989d477c)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(769)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(773)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(773)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(774)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(774)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(774)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(775)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(777)
		if (((library != null()))){
			HX_STACK_LINE(779)
			if ((library->exists(symbolName,::openfl::AssetType_obj::BINARY))){
				HX_STACK_LINE(781)
				library->loadBytes(symbolName,handler);
				HX_STACK_LINE(782)
				return null();
			}
			else{
				HX_STACK_LINE(786)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no String or ByteArray asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),786,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadBytes")));
			}
		}
		else{
			HX_STACK_LINE(792)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),792,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadBytes")));
		}
		HX_STACK_LINE(798)
		handler(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,loadBytes,(void))

Void Assets_obj::loadFont( ::String id,Dynamic handler,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","loadFont",0x37540b62,"openfl.Assets.loadFont","openfl/Assets.hx",803,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(803)
		Dynamic handler1 = Dynamic( Array_obj<Dynamic>::__new().Add(handler));		HX_STACK_VAR(handler1,"handler1");
		HX_STACK_LINE(803)
		Array< ::String > id1 = Array_obj< ::String >::__new().Add(id);		HX_STACK_VAR(id1,"id1");
		HX_STACK_LINE(805)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(809)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->font->exists(id1->__get((int)0))) : bool(false) ))){
			HX_STACK_LINE(811)
			::openfl::text::Font _g = ::openfl::Assets_obj::cache->font->get(id1->__get((int)0));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(811)
			handler1->__GetItem((int)0)(_g).Cast< Void >();
			HX_STACK_LINE(812)
			return null();
		}
		HX_STACK_LINE(816)
		int _g1 = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(816)
		::String libraryName = id1->__get((int)0).substring((int)0,_g1);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(817)
		int _g2 = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(817)
		int _g3 = (_g2 + (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(817)
		::String symbolName = id1->__get((int)0).substr(_g3,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(818)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(820)
		if (((library != null()))){
			HX_STACK_LINE(822)
			if ((library->exists(symbolName,::openfl::AssetType_obj::FONT))){
				HX_STACK_LINE(824)
				if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,handler1,Array< ::String >,id1)
					Void run(::openfl::text::Font font){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","openfl/Assets.hx",826,0x989d477c)
						HX_STACK_ARG(font,"font")
						{
							HX_STACK_LINE(828)
							::openfl::Assets_obj::cache->font->set(id1->__get((int)0),font);
							HX_STACK_LINE(829)
							handler1->__GetItem((int)0)(font).Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(826)
					library->loadFont(symbolName, Dynamic(new _Function_4_1(handler1,id1)));
				}
				else{
					HX_STACK_LINE(835)
					library->loadFont(symbolName,handler1->__GetItem((int)0));
				}
				HX_STACK_LINE(839)
				return null();
			}
			else{
				HX_STACK_LINE(843)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Font asset with an ID of \"") + id1->__get((int)0)) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),843,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadFont")));
			}
		}
		else{
			HX_STACK_LINE(849)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),849,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadFont")));
		}
		HX_STACK_LINE(855)
		handler1->__GetItem((int)0)(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,loadFont,(void))

Void Assets_obj::loadLibrary( ::String name,Dynamic handler){
{
		HX_STACK_FRAME("openfl.Assets","loadLibrary",0x44d0f748,"openfl.Assets.loadLibrary","openfl/Assets.hx",860,0x989d477c)
		HX_STACK_ARG(name,"name")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(862)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(866)
		::String data = ::openfl::Assets_obj::getText(((HX_CSTRING("libraries/") + name) + HX_CSTRING(".dat")));		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(868)
		if (((bool((data != null())) && bool((data != HX_CSTRING("")))))){
			HX_STACK_LINE(870)
			::haxe::Unserializer unserializer = ::haxe::Unserializer_obj::__new(data);		HX_STACK_VAR(unserializer,"unserializer");
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/Assets.hx",871,0x989d477c)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("resolveEnum") , ::openfl::Assets_obj::resolveEnum_dyn(),false);
						__result->Add(HX_CSTRING("resolveClass") , ::openfl::Assets_obj::resolveClass_dyn(),false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(871)
			unserializer->setResolver(_Function_2_1::Block());
			HX_STACK_LINE(873)
			::openfl::AssetLibrary library = unserializer->unserialize();		HX_STACK_VAR(library,"library");
			HX_STACK_LINE(874)
			::openfl::Assets_obj::libraries->set(name,library);
			HX_STACK_LINE(875)
			library->eventCallback = ::openfl::Assets_obj::library_onEvent_dyn();
			HX_STACK_LINE(876)
			library->load(handler);
		}
		else{
			HX_STACK_LINE(880)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + name) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),880,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadLibrary")));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,loadLibrary,(void))

Void Assets_obj::loadMusic( ::String id,Dynamic handler,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","loadMusic",0x3dff03b2,"openfl.Assets.loadMusic","openfl/Assets.hx",889,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(889)
		Dynamic handler1 = Dynamic( Array_obj<Dynamic>::__new().Add(handler));		HX_STACK_VAR(handler1,"handler1");
		HX_STACK_LINE(889)
		Array< ::String > id1 = Array_obj< ::String >::__new().Add(id);		HX_STACK_VAR(id1,"id1");
		HX_STACK_LINE(891)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(895)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->sound->exists(id1->__get((int)0))) : bool(false) ))){
			HX_STACK_LINE(897)
			::openfl::media::Sound sound = ::openfl::Assets_obj::cache->sound->get(id1->__get((int)0));		HX_STACK_VAR(sound,"sound");
			HX_STACK_LINE(899)
			if ((::openfl::Assets_obj::isValidSound(sound))){
				HX_STACK_LINE(901)
				handler1->__GetItem((int)0)(sound).Cast< Void >();
				HX_STACK_LINE(902)
				return null();
			}
		}
		HX_STACK_LINE(908)
		int _g = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(908)
		::String libraryName = id1->__get((int)0).substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(909)
		int _g1 = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(909)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(909)
		::String symbolName = id1->__get((int)0).substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(910)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(912)
		if (((library != null()))){
			HX_STACK_LINE(914)
			if ((library->exists(symbolName,::openfl::AssetType_obj::MUSIC))){
				HX_STACK_LINE(916)
				if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,handler1,Array< ::String >,id1)
					Void run(::openfl::media::Sound sound){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","openfl/Assets.hx",918,0x989d477c)
						HX_STACK_ARG(sound,"sound")
						{
							HX_STACK_LINE(920)
							::openfl::Assets_obj::cache->sound->set(id1->__get((int)0),sound);
							HX_STACK_LINE(921)
							handler1->__GetItem((int)0)(sound).Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(918)
					library->loadMusic(symbolName, Dynamic(new _Function_4_1(handler1,id1)));
				}
				else{
					HX_STACK_LINE(927)
					library->loadMusic(symbolName,handler1->__GetItem((int)0));
				}
				HX_STACK_LINE(931)
				return null();
			}
			else{
				HX_STACK_LINE(935)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Sound asset with an ID of \"") + id1->__get((int)0)) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),935,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadMusic")));
			}
		}
		else{
			HX_STACK_LINE(941)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),941,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadMusic")));
		}
		HX_STACK_LINE(947)
		handler1->__GetItem((int)0)(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,loadMusic,(void))

Void Assets_obj::loadMovieClip( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.Assets","loadMovieClip",0xd38a402d,"openfl.Assets.loadMovieClip","openfl/Assets.hx",952,0x989d477c)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(954)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(958)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(958)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(959)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(959)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(959)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(960)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(962)
		if (((library != null()))){
			HX_STACK_LINE(964)
			if ((library->exists(symbolName,::openfl::AssetType_obj::MOVIE_CLIP))){
				HX_STACK_LINE(966)
				library->loadMovieClip(symbolName,handler);
				HX_STACK_LINE(967)
				return null();
			}
			else{
				HX_STACK_LINE(971)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no MovieClip asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),971,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadMovieClip")));
			}
		}
		else{
			HX_STACK_LINE(977)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),977,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadMovieClip")));
		}
		HX_STACK_LINE(983)
		handler(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,loadMovieClip,(void))

Void Assets_obj::loadSound( ::String id,Dynamic handler,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_STACK_FRAME("openfl.Assets","loadSound",0xae70bfdc,"openfl.Assets.loadSound","openfl/Assets.hx",988,0x989d477c)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(useCache,"useCache")
{
		HX_STACK_LINE(988)
		Dynamic handler1 = Dynamic( Array_obj<Dynamic>::__new().Add(handler));		HX_STACK_VAR(handler1,"handler1");
		HX_STACK_LINE(988)
		Array< ::String > id1 = Array_obj< ::String >::__new().Add(id);		HX_STACK_VAR(id1,"id1");
		HX_STACK_LINE(990)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(994)
		if (((  (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))) ? bool(::openfl::Assets_obj::cache->sound->exists(id1->__get((int)0))) : bool(false) ))){
			HX_STACK_LINE(996)
			::openfl::media::Sound sound = ::openfl::Assets_obj::cache->sound->get(id1->__get((int)0));		HX_STACK_VAR(sound,"sound");
			HX_STACK_LINE(998)
			if ((::openfl::Assets_obj::isValidSound(sound))){
				HX_STACK_LINE(1000)
				handler1->__GetItem((int)0)(sound).Cast< Void >();
				HX_STACK_LINE(1001)
				return null();
			}
		}
		HX_STACK_LINE(1007)
		int _g = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1007)
		::String libraryName = id1->__get((int)0).substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(1008)
		int _g1 = id1->__get((int)0).indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1008)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1008)
		::String symbolName = id1->__get((int)0).substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(1009)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(1011)
		if (((library != null()))){
			HX_STACK_LINE(1013)
			if ((library->exists(symbolName,::openfl::AssetType_obj::SOUND))){
				HX_STACK_LINE(1015)
				if (((bool(useCache) && bool(::openfl::Assets_obj::cache->enabled)))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,handler1,Array< ::String >,id1)
					Void run(::openfl::media::Sound sound){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","openfl/Assets.hx",1017,0x989d477c)
						HX_STACK_ARG(sound,"sound")
						{
							HX_STACK_LINE(1019)
							::openfl::Assets_obj::cache->sound->set(id1->__get((int)0),sound);
							HX_STACK_LINE(1020)
							handler1->__GetItem((int)0)(sound).Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(1017)
					library->loadSound(symbolName, Dynamic(new _Function_4_1(handler1,id1)));
				}
				else{
					HX_STACK_LINE(1026)
					library->loadSound(symbolName,handler1->__GetItem((int)0));
				}
				HX_STACK_LINE(1030)
				return null();
			}
			else{
				HX_STACK_LINE(1034)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no Sound asset with an ID of \"") + id1->__get((int)0)) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),1034,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadSound")));
			}
		}
		else{
			HX_STACK_LINE(1040)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),1040,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadSound")));
		}
		HX_STACK_LINE(1046)
		handler1->__GetItem((int)0)(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,loadSound,(void))

Void Assets_obj::loadText( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.Assets","loadText",0x408d7a40,"openfl.Assets.loadText","openfl/Assets.hx",1051,0x989d477c)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1053)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(1057)
		int _g = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1057)
		::String libraryName = id.substring((int)0,_g);		HX_STACK_VAR(libraryName,"libraryName");
		HX_STACK_LINE(1058)
		int _g1 = id.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1058)
		int _g2 = (_g1 + (int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1058)
		::String symbolName = id.substr(_g2,null());		HX_STACK_VAR(symbolName,"symbolName");
		HX_STACK_LINE(1059)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::getLibrary(libraryName);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(1061)
		if (((library != null()))){
			HX_STACK_LINE(1063)
			if ((library->exists(symbolName,::openfl::AssetType_obj::TEXT))){
				HX_STACK_LINE(1065)
				library->loadText(symbolName,handler);
				HX_STACK_LINE(1066)
				return null();
			}
			else{
				HX_STACK_LINE(1070)
				::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no String asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),1070,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadText")));
			}
		}
		else{
			HX_STACK_LINE(1076)
			::haxe::Log_obj::trace(((HX_CSTRING("[openfl.Assets] There is no asset library named \"") + libraryName) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),1076,HX_CSTRING("openfl.Assets"),HX_CSTRING("loadText")));
		}
		HX_STACK_LINE(1082)
		handler(null()).Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,loadText,(void))

Void Assets_obj::registerLibrary( ::String name,::openfl::AssetLibrary library){
{
		HX_STACK_FRAME("openfl.Assets","registerLibrary",0x9230822b,"openfl.Assets.registerLibrary","openfl/Assets.hx",1087,0x989d477c)
		HX_STACK_ARG(name,"name")
		HX_STACK_ARG(library,"library")
		HX_STACK_LINE(1089)
		if ((::openfl::Assets_obj::libraries->exists(name))){
			HX_STACK_LINE(1091)
			::openfl::Assets_obj::unloadLibrary(name);
		}
		HX_STACK_LINE(1095)
		if (((library != null()))){
			HX_STACK_LINE(1097)
			library->eventCallback = ::openfl::Assets_obj::library_onEvent_dyn();
		}
		HX_STACK_LINE(1101)
		::openfl::Assets_obj::libraries->set(name,library);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,registerLibrary,(void))

Void Assets_obj::removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_capture){
bool capture = __o_capture.Default(false);
	HX_STACK_FRAME("openfl.Assets","removeEventListener",0x6a2b249d,"openfl.Assets.removeEventListener","openfl/Assets.hx",1106,0x989d477c)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(capture,"capture")
{
		HX_STACK_LINE(1108)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(1110)
		::openfl::Assets_obj::dispatcher->removeEventListener(type,listener,capture);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Assets_obj,removeEventListener,(void))

::Class Assets_obj::resolveClass( ::String name){
	HX_STACK_FRAME("openfl.Assets","resolveClass",0x76ca4479,"openfl.Assets.resolveClass","openfl/Assets.hx",1117,0x989d477c)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(1117)
	return ::Type_obj::resolveClass(name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,resolveClass,return )

::Enum Assets_obj::resolveEnum( ::String name){
	HX_STACK_FRAME("openfl.Assets","resolveEnum",0x1314a1e0,"openfl.Assets.resolveEnum","openfl/Assets.hx",1122,0x989d477c)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(1124)
	::Enum value = ::Type_obj::resolveEnum(name);		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(1136)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,resolveEnum,return )

Void Assets_obj::unloadLibrary( ::String name){
{
		HX_STACK_FRAME("openfl.Assets","unloadLibrary",0x6a51c84f,"openfl.Assets.unloadLibrary","openfl/Assets.hx",1141,0x989d477c)
		HX_STACK_ARG(name,"name")
		HX_STACK_LINE(1143)
		::openfl::Assets_obj::initialize();
		HX_STACK_LINE(1147)
		::openfl::AssetLibrary library = ::openfl::Assets_obj::libraries->get(name);		HX_STACK_VAR(library,"library");
		HX_STACK_LINE(1149)
		if (((library != null()))){
			HX_STACK_LINE(1151)
			::openfl::Assets_obj::cache->clear((name + HX_CSTRING(":")));
			HX_STACK_LINE(1152)
			library->eventCallback = null();
		}
		HX_STACK_LINE(1156)
		::openfl::Assets_obj::libraries->remove(name);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,unloadLibrary,(void))

Void Assets_obj::library_onEvent( ::openfl::AssetLibrary library,::String type){
{
		HX_STACK_FRAME("openfl.Assets","library_onEvent",0xbd1ed14a,"openfl.Assets.library_onEvent","openfl/Assets.hx",1172,0x989d477c)
		HX_STACK_ARG(library,"library")
		HX_STACK_ARG(type,"type")
		HX_STACK_LINE(1172)
		if (((type == HX_CSTRING("change")))){
			HX_STACK_LINE(1174)
			::openfl::Assets_obj::cache->clear(null());
			HX_STACK_LINE(1175)
			::openfl::events::Event _g = ::openfl::events::Event_obj::__new(::openfl::events::Event_obj::CHANGE,null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1175)
			::openfl::Assets_obj::dispatchEvent(_g);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,library_onEvent,(void))


Assets_obj::Assets_obj()
{
}

Dynamic Assets_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getFont") ) { return getFont_dyn(); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return getPath_dyn(); }
		if (HX_FIELD_EQ(inName,"getText") ) { return getText_dyn(); }
		if (HX_FIELD_EQ(inName,"isLocal") ) { return isLocal_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getMusic") ) { return getMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFont") ) { return loadFont_dyn(); }
		if (HX_FIELD_EQ(inName,"loadText") ) { return loadText_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"libraries") ) { return libraries; }
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return loadBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMusic") ) { return loadMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"loadSound") ) { return loadSound_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatcher") ) { return dispatcher; }
		if (HX_FIELD_EQ(inName,"getLibrary") ) { return getLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { return initialized; }
		if (HX_FIELD_EQ(inName,"loadLibrary") ) { return loadLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"resolveEnum") ) { return resolveEnum_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getMovieClip") ) { return getMovieClip_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidSound") ) { return isValidSound_dyn(); }
		if (HX_FIELD_EQ(inName,"resolveClass") ) { return resolveClass_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMovieClip") ) { return loadMovieClip_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadLibrary") ) { return unloadLibrary_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadBitmapData") ) { return loadBitmapData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"registerLibrary") ) { return registerLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"library_onEvent") ) { return library_onEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		if (HX_FIELD_EQ(inName,"hasEventListener") ) { return hasEventListener_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"isValidBitmapData") ) { return isValidBitmapData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"removeEventListener") ) { return removeEventListener_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Assets_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< ::openfl::AssetCache >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"libraries") ) { libraries=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatcher") ) { dispatcher=inValue.Cast< ::openfl::events::EventDispatcher >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { initialized=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Assets_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("cache"),
	HX_CSTRING("libraries"),
	HX_CSTRING("dispatcher"),
	HX_CSTRING("initialized"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("exists"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("getFont"),
	HX_CSTRING("getLibrary"),
	HX_CSTRING("getMovieClip"),
	HX_CSTRING("getMusic"),
	HX_CSTRING("getPath"),
	HX_CSTRING("getSound"),
	HX_CSTRING("getText"),
	HX_CSTRING("hasEventListener"),
	HX_CSTRING("initialize"),
	HX_CSTRING("isLocal"),
	HX_CSTRING("isValidBitmapData"),
	HX_CSTRING("isValidSound"),
	HX_CSTRING("list"),
	HX_CSTRING("loadBitmapData"),
	HX_CSTRING("loadBytes"),
	HX_CSTRING("loadFont"),
	HX_CSTRING("loadLibrary"),
	HX_CSTRING("loadMusic"),
	HX_CSTRING("loadMovieClip"),
	HX_CSTRING("loadSound"),
	HX_CSTRING("loadText"),
	HX_CSTRING("registerLibrary"),
	HX_CSTRING("removeEventListener"),
	HX_CSTRING("resolveClass"),
	HX_CSTRING("resolveEnum"),
	HX_CSTRING("unloadLibrary"),
	HX_CSTRING("library_onEvent"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Assets_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Assets_obj::cache,"cache");
	HX_MARK_MEMBER_NAME(Assets_obj::libraries,"libraries");
	HX_MARK_MEMBER_NAME(Assets_obj::dispatcher,"dispatcher");
	HX_MARK_MEMBER_NAME(Assets_obj::initialized,"initialized");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Assets_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Assets_obj::cache,"cache");
	HX_VISIT_MEMBER_NAME(Assets_obj::libraries,"libraries");
	HX_VISIT_MEMBER_NAME(Assets_obj::dispatcher,"dispatcher");
	HX_VISIT_MEMBER_NAME(Assets_obj::initialized,"initialized");
};

#endif

Class Assets_obj::__mClass;

void Assets_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.Assets"), hx::TCanCast< Assets_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Assets_obj::__boot()
{
	cache= ::openfl::AssetCache_obj::__new();
	libraries= ::haxe::ds::StringMap_obj::__new();
	dispatcher= ::openfl::events::EventDispatcher_obj::__new(null());
	initialized= false;
}

} // end namespace openfl
