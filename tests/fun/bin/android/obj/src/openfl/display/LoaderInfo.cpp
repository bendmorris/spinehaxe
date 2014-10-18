#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_openfl_display_Loader
#include <openfl/display/Loader.h>
#endif
#ifndef INCLUDED_openfl_display_LoaderInfo
#include <openfl/display/LoaderInfo.h>
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
#ifndef INCLUDED_openfl_events_UncaughtErrorEvents
#include <openfl/events/UncaughtErrorEvents.h>
#endif
#ifndef INCLUDED_openfl_net_URLLoader
#include <openfl/net/URLLoader.h>
#endif
#ifndef INCLUDED_openfl_net_URLLoaderDataFormat
#include <openfl/net/URLLoaderDataFormat.h>
#endif
#ifndef INCLUDED_openfl_net_URLRequest
#include <openfl/net/URLRequest.h>
#endif
#ifndef INCLUDED_openfl_system_ApplicationDomain
#include <openfl/system/ApplicationDomain.h>
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
namespace display{

Void LoaderInfo_obj::__construct()
{
HX_STACK_FRAME("openfl.display.LoaderInfo","new",0xaabc917d,"openfl.display.LoaderInfo.new","openfl/display/LoaderInfo.hx",37,0x88528a51)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(39)
	super::__construct(null());
	HX_STACK_LINE(41)
	this->applicationDomain = ::openfl::system::ApplicationDomain_obj::currentDomain;
	HX_STACK_LINE(42)
	this->childAllowsParent = true;
	HX_STACK_LINE(43)
	this->frameRate = (int)0;
	HX_STACK_LINE(44)
	this->dataFormat = ::openfl::net::URLLoaderDataFormat_obj::BINARY;
	HX_STACK_LINE(45)
	this->loaderURL = null();
	HX_STACK_LINE(46)
	this->addEventListener(::openfl::events::Event_obj::COMPLETE,this->this_onComplete_dyn(),null(),null(),null());
}
;
	return null();
}

//LoaderInfo_obj::~LoaderInfo_obj() { }

Dynamic LoaderInfo_obj::__CreateEmpty() { return  new LoaderInfo_obj; }
hx::ObjectPtr< LoaderInfo_obj > LoaderInfo_obj::__new()
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

Dynamic LoaderInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

Void LoaderInfo_obj::load( ::openfl::net::URLRequest request){
{
		HX_STACK_FRAME("openfl.display.LoaderInfo","load",0xb8f7d269,"openfl.display.LoaderInfo.load","openfl/display/LoaderInfo.hx",68,0x88528a51)
		HX_STACK_THIS(this)
		HX_STACK_ARG(request,"request")
		HX_STACK_LINE(70)
		this->__pendingURL = request->url;
		HX_STACK_LINE(71)
		int dot = this->__pendingURL.lastIndexOf(HX_CSTRING("."),null());		HX_STACK_VAR(dot,"dot");
		HX_STACK_LINE(72)
		::String extension;		HX_STACK_VAR(extension,"extension");
		HX_STACK_LINE(72)
		if (((dot > (int)0))){
			HX_STACK_LINE(72)
			extension = this->__pendingURL.substr((dot + (int)1),null()).toLowerCase();
		}
		else{
			HX_STACK_LINE(72)
			extension = HX_CSTRING("");
		}
		HX_STACK_LINE(74)
		::String _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(74)
		::String _switch_1 = (extension);
		if (  ( _switch_1==HX_CSTRING("swf"))){
			HX_STACK_LINE(76)
			_g = HX_CSTRING("application/x-shockwave-flash");
		}
		else if (  ( _switch_1==HX_CSTRING("jpg")) ||  ( _switch_1==HX_CSTRING("jpeg"))){
			HX_STACK_LINE(77)
			_g = HX_CSTRING("image/jpeg");
		}
		else if (  ( _switch_1==HX_CSTRING("png"))){
			HX_STACK_LINE(78)
			_g = HX_CSTRING("image/png");
		}
		else if (  ( _switch_1==HX_CSTRING("gif"))){
			HX_STACK_LINE(79)
			_g = HX_CSTRING("image/gif");
		}
		else  {
			HX_STACK_LINE(81)
			HX_STACK_DO_THROW((HX_CSTRING("Unrecognized file ") + this->__pendingURL));
		}
;
;
		HX_STACK_LINE(74)
		this->contentType = _g;
		HX_STACK_LINE(85)
		this->url = null();
		HX_STACK_LINE(87)
		this->super::load(request);
	}
return null();
}


Void LoaderInfo_obj::this_onComplete( ::openfl::events::Event event){
{
		HX_STACK_FRAME("openfl.display.LoaderInfo","this_onComplete",0x993d1516,"openfl.display.LoaderInfo.this_onComplete","openfl/display/LoaderInfo.hx",101,0x88528a51)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(101)
		this->url = this->__pendingURL;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,this_onComplete,(void))

::openfl::utils::ByteArray LoaderInfo_obj::get_bytes( ){
	HX_STACK_FRAME("openfl.display.LoaderInfo","get_bytes",0xce1f599f,"openfl.display.LoaderInfo.get_bytes","openfl/display/LoaderInfo.hx",115,0x88528a51)
	HX_STACK_THIS(this)
	HX_STACK_LINE(115)
	return this->data;
}


HX_DEFINE_DYNAMIC_FUNC0(LoaderInfo_obj,get_bytes,return )

::openfl::display::LoaderInfo LoaderInfo_obj::create( ::openfl::display::Loader loader){
	HX_STACK_FRAME("openfl.display.LoaderInfo","create",0xe80075ff,"openfl.display.LoaderInfo.create","openfl/display/LoaderInfo.hx",51,0x88528a51)
	HX_STACK_ARG(loader,"loader")
	HX_STACK_LINE(53)
	::openfl::display::LoaderInfo loaderInfo = ::openfl::display::LoaderInfo_obj::__new();		HX_STACK_VAR(loaderInfo,"loaderInfo");
	HX_STACK_LINE(54)
	loaderInfo->loader = loader;
	HX_STACK_LINE(55)
	::openfl::events::UncaughtErrorEvents _g = ::openfl::events::UncaughtErrorEvents_obj::__new(null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(55)
	loaderInfo->uncaughtErrorEvents = _g;
	HX_STACK_LINE(57)
	if (((loader == null()))){
		HX_STACK_LINE(59)
		loaderInfo->url = HX_CSTRING("");
	}
	HX_STACK_LINE(63)
	return loaderInfo;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,create,return )


LoaderInfo_obj::LoaderInfo_obj()
{
}

void LoaderInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoaderInfo);
	HX_MARK_MEMBER_NAME(applicationDomain,"applicationDomain");
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(childAllowsParent,"childAllowsParent");
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(contentType,"contentType");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(loaderURL,"loaderURL");
	HX_MARK_MEMBER_NAME(parameters,"parameters");
	HX_MARK_MEMBER_NAME(parentAllowsChild,"parentAllowsChild");
	HX_MARK_MEMBER_NAME(sameDomain,"sameDomain");
	HX_MARK_MEMBER_NAME(sharedEvents,"sharedEvents");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(uncaughtErrorEvents,"uncaughtErrorEvents");
	HX_MARK_MEMBER_NAME(__pendingURL,"__pendingURL");
	::openfl::net::URLLoader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LoaderInfo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(applicationDomain,"applicationDomain");
	HX_VISIT_MEMBER_NAME(bytes,"bytes");
	HX_VISIT_MEMBER_NAME(childAllowsParent,"childAllowsParent");
	HX_VISIT_MEMBER_NAME(content,"content");
	HX_VISIT_MEMBER_NAME(contentType,"contentType");
	HX_VISIT_MEMBER_NAME(frameRate,"frameRate");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(loader,"loader");
	HX_VISIT_MEMBER_NAME(loaderURL,"loaderURL");
	HX_VISIT_MEMBER_NAME(parameters,"parameters");
	HX_VISIT_MEMBER_NAME(parentAllowsChild,"parentAllowsChild");
	HX_VISIT_MEMBER_NAME(sameDomain,"sameDomain");
	HX_VISIT_MEMBER_NAME(sharedEvents,"sharedEvents");
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(uncaughtErrorEvents,"uncaughtErrorEvents");
	HX_VISIT_MEMBER_NAME(__pendingURL,"__pendingURL");
	::openfl::net::URLLoader_obj::__Visit(HX_VISIT_ARG);
}

Dynamic LoaderInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { return inCallProp ? get_bytes() : bytes; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"loader") ) { return loader; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		if (HX_FIELD_EQ(inName,"loaderURL") ) { return loaderURL; }
		if (HX_FIELD_EQ(inName,"get_bytes") ) { return get_bytes_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parameters") ) { return parameters; }
		if (HX_FIELD_EQ(inName,"sameDomain") ) { return sameDomain; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { return contentType; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { return sharedEvents; }
		if (HX_FIELD_EQ(inName,"__pendingURL") ) { return __pendingURL; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"this_onComplete") ) { return this_onComplete_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"applicationDomain") ) { return applicationDomain; }
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { return childAllowsParent; }
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { return parentAllowsChild; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"uncaughtErrorEvents") ) { return uncaughtErrorEvents; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LoaderInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast< ::openfl::utils::ByteArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast< ::openfl::display::Loader >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::openfl::display::DisplayObject >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { frameRate=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loaderURL") ) { loaderURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parameters") ) { parameters=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sameDomain") ) { sameDomain=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { contentType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { sharedEvents=inValue.Cast< ::openfl::events::EventDispatcher >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__pendingURL") ) { __pendingURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"applicationDomain") ) { applicationDomain=inValue.Cast< ::openfl::system::ApplicationDomain >(); return inValue; }
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { childAllowsParent=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { parentAllowsChild=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"uncaughtErrorEvents") ) { uncaughtErrorEvents=inValue.Cast< ::openfl::events::UncaughtErrorEvents >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoaderInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("applicationDomain"));
	outFields->push(HX_CSTRING("bytes"));
	outFields->push(HX_CSTRING("childAllowsParent"));
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("contentType"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("loader"));
	outFields->push(HX_CSTRING("loaderURL"));
	outFields->push(HX_CSTRING("parameters"));
	outFields->push(HX_CSTRING("parentAllowsChild"));
	outFields->push(HX_CSTRING("sameDomain"));
	outFields->push(HX_CSTRING("sharedEvents"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("uncaughtErrorEvents"));
	outFields->push(HX_CSTRING("__pendingURL"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::system::ApplicationDomain*/ ,(int)offsetof(LoaderInfo_obj,applicationDomain),HX_CSTRING("applicationDomain")},
	{hx::fsObject /*::openfl::utils::ByteArray*/ ,(int)offsetof(LoaderInfo_obj,bytes),HX_CSTRING("bytes")},
	{hx::fsBool,(int)offsetof(LoaderInfo_obj,childAllowsParent),HX_CSTRING("childAllowsParent")},
	{hx::fsObject /*::openfl::display::DisplayObject*/ ,(int)offsetof(LoaderInfo_obj,content),HX_CSTRING("content")},
	{hx::fsString,(int)offsetof(LoaderInfo_obj,contentType),HX_CSTRING("contentType")},
	{hx::fsFloat,(int)offsetof(LoaderInfo_obj,frameRate),HX_CSTRING("frameRate")},
	{hx::fsInt,(int)offsetof(LoaderInfo_obj,height),HX_CSTRING("height")},
	{hx::fsObject /*::openfl::display::Loader*/ ,(int)offsetof(LoaderInfo_obj,loader),HX_CSTRING("loader")},
	{hx::fsString,(int)offsetof(LoaderInfo_obj,loaderURL),HX_CSTRING("loaderURL")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(LoaderInfo_obj,parameters),HX_CSTRING("parameters")},
	{hx::fsBool,(int)offsetof(LoaderInfo_obj,parentAllowsChild),HX_CSTRING("parentAllowsChild")},
	{hx::fsBool,(int)offsetof(LoaderInfo_obj,sameDomain),HX_CSTRING("sameDomain")},
	{hx::fsObject /*::openfl::events::EventDispatcher*/ ,(int)offsetof(LoaderInfo_obj,sharedEvents),HX_CSTRING("sharedEvents")},
	{hx::fsString,(int)offsetof(LoaderInfo_obj,url),HX_CSTRING("url")},
	{hx::fsInt,(int)offsetof(LoaderInfo_obj,width),HX_CSTRING("width")},
	{hx::fsObject /*::openfl::events::UncaughtErrorEvents*/ ,(int)offsetof(LoaderInfo_obj,uncaughtErrorEvents),HX_CSTRING("uncaughtErrorEvents")},
	{hx::fsString,(int)offsetof(LoaderInfo_obj,__pendingURL),HX_CSTRING("__pendingURL")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("applicationDomain"),
	HX_CSTRING("bytes"),
	HX_CSTRING("childAllowsParent"),
	HX_CSTRING("content"),
	HX_CSTRING("contentType"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("height"),
	HX_CSTRING("loader"),
	HX_CSTRING("loaderURL"),
	HX_CSTRING("parameters"),
	HX_CSTRING("parentAllowsChild"),
	HX_CSTRING("sameDomain"),
	HX_CSTRING("sharedEvents"),
	HX_CSTRING("url"),
	HX_CSTRING("width"),
	HX_CSTRING("uncaughtErrorEvents"),
	HX_CSTRING("__pendingURL"),
	HX_CSTRING("load"),
	HX_CSTRING("this_onComplete"),
	HX_CSTRING("get_bytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LoaderInfo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LoaderInfo_obj::__mClass,"__mClass");
};

#endif

Class LoaderInfo_obj::__mClass;

void LoaderInfo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.LoaderInfo"), hx::TCanCast< LoaderInfo_obj> ,sStaticFields,sMemberFields,
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

void LoaderInfo_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
