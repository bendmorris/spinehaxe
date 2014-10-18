#include <hxcpp.h>

#ifndef INCLUDED_AnimationStateTest
#include <AnimationStateTest.h>
#endif
#ifndef INCLUDED_ApplicationMain
#include <ApplicationMain.h>
#endif
#ifndef INCLUDED_DocumentClass
#include <DocumentClass.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
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
#ifndef INCLUDED_openfl_display_Loader
#include <openfl/display/Loader.h>
#endif
#ifndef INCLUDED_openfl_display_LoaderInfo
#include <openfl/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_net_URLLoader
#include <openfl/net/URLLoader.h>
#endif

Void ApplicationMain_obj::__construct()
{
	return null();
}

//ApplicationMain_obj::~ApplicationMain_obj() { }

Dynamic ApplicationMain_obj::__CreateEmpty() { return  new ApplicationMain_obj; }
hx::ObjectPtr< ApplicationMain_obj > ApplicationMain_obj::__new()
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

Dynamic ApplicationMain_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

::openfl::display::Sprite ApplicationMain_obj::barA;

::openfl::display::Sprite ApplicationMain_obj::barB;

::openfl::display::Sprite ApplicationMain_obj::container;

int ApplicationMain_obj::forceHeight;

int ApplicationMain_obj::forceWidth;

Void ApplicationMain_obj::main( ){
{
		HX_STACK_FRAME("ApplicationMain","main",0x93d2f73e,"ApplicationMain.main","ApplicationMain.hx",17,0x0780ded5)
		HX_STACK_LINE(19)
		::openfl::Lib_obj::setPackage(HX_CSTRING("spinehx"),HX_CSTRING("spinehx-AnimationStateTest"),HX_CSTRING("org.bitbucket.nitrobin.spinehx.AnimationStateTest"),HX_CSTRING("1.0.0"));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","ApplicationMain.hx",32,0x0780ded5)
			{
				HX_STACK_LINE(34)
				::openfl::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
				HX_STACK_LINE(35)
				::openfl::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
				HX_STACK_LINE(36)
				::openfl::Lib_obj::get_current()->loaderInfo = ::openfl::display::LoaderInfo_obj::create(null());
				HX_STACK_LINE(59)
				bool hasMain = false;		HX_STACK_VAR(hasMain,"hasMain");
				HX_STACK_LINE(61)
				{
					HX_STACK_LINE(61)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(61)
					Array< ::String > _g1 = ::Type_obj::getClassFields(hx::ClassOf< ::AnimationStateTest >());		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(61)
					while(((_g < _g1->length))){
						HX_STACK_LINE(61)
						::String methodName = _g1->__get(_g);		HX_STACK_VAR(methodName,"methodName");
						HX_STACK_LINE(61)
						++(_g);
						HX_STACK_LINE(63)
						if (((methodName == HX_CSTRING("main")))){
							HX_STACK_LINE(65)
							hasMain = true;
							HX_STACK_LINE(66)
							break;
						}
					}
				}
				HX_STACK_LINE(72)
				if ((hasMain)){
					HX_STACK_LINE(74)
					::Reflect_obj::callMethod(hx::ClassOf< ::AnimationStateTest >(),::Reflect_obj::field(hx::ClassOf< ::AnimationStateTest >(),HX_CSTRING("main")),Dynamic( Array_obj<Dynamic>::__new()));
				}
				else{
					HX_STACK_LINE(78)
					::DocumentClass instance = ::Type_obj::createInstance(hx::ClassOf< ::DocumentClass >(),Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(instance,"instance");
					HX_STACK_LINE(80)
					if ((::Std_obj::is(instance,hx::ClassOf< ::openfl::display::DisplayObject >()))){
						HX_STACK_LINE(82)
						::openfl::Lib_obj::get_current()->addChild(instance);
					}
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(32)
		::openfl::Lib_obj::create( Dynamic(new _Function_1_1()),(int)0,(int)0,(int)60,(int)16777215,(int((int((int((int((int((int((int((int((int((int(::openfl::Lib_obj::HARDWARE) | int(::openfl::Lib_obj::ALLOW_SHADERS))) | int(::openfl::Lib_obj::REQUIRE_SHADERS))) | int((int)0))) | int((int)0))) | int(::openfl::Lib_obj::RESIZABLE))) | int((int)0))) | int((int)0))) | int(::openfl::Lib_obj::FULLSCREEN))) | int((int)0))) | int((int)0)),HX_CSTRING("spinehx - AnimationStateTest"),null(),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ApplicationMain_obj,main,(void))


ApplicationMain_obj::ApplicationMain_obj()
{
}

Dynamic ApplicationMain_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"barA") ) { return barA; }
		if (HX_FIELD_EQ(inName,"barB") ) { return barB; }
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { return container; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"forceWidth") ) { return forceWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"forceHeight") ) { return forceHeight; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ApplicationMain_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"barA") ) { barA=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"barB") ) { barB=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"forceWidth") ) { forceWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"forceHeight") ) { forceHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ApplicationMain_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("barA"),
	HX_CSTRING("barB"),
	HX_CSTRING("container"),
	HX_CSTRING("forceHeight"),
	HX_CSTRING("forceWidth"),
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::barA,"barA");
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::barB,"barB");
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::container,"container");
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::forceHeight,"forceHeight");
	HX_MARK_MEMBER_NAME(ApplicationMain_obj::forceWidth,"forceWidth");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::barA,"barA");
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::barB,"barB");
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::container,"container");
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::forceHeight,"forceHeight");
	HX_VISIT_MEMBER_NAME(ApplicationMain_obj::forceWidth,"forceWidth");
};

#endif

Class ApplicationMain_obj::__mClass;

void ApplicationMain_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("ApplicationMain"), hx::TCanCast< ApplicationMain_obj> ,sStaticFields,sMemberFields,
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

void ApplicationMain_obj::__boot()
{
}

