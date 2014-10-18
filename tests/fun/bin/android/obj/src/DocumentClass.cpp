#include <hxcpp.h>

#ifndef INCLUDED_AnimationStateTest
#include <AnimationStateTest.h>
#endif
#ifndef INCLUDED_DocumentClass
#include <DocumentClass.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
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
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif

Void DocumentClass_obj::__construct()
{
HX_STACK_FRAME("DocumentClass","new",0x4aeb0a6f,"DocumentClass.new","ApplicationMain.hx",128,0x0780ded5)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(128)
	super::__construct();
}
;
	return null();
}

//DocumentClass_obj::~DocumentClass_obj() { }

Dynamic DocumentClass_obj::__CreateEmpty() { return  new DocumentClass_obj; }
hx::ObjectPtr< DocumentClass_obj > DocumentClass_obj::__new()
{  hx::ObjectPtr< DocumentClass_obj > result = new DocumentClass_obj();
	result->__construct();
	return result;}

Dynamic DocumentClass_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DocumentClass_obj > result = new DocumentClass_obj();
	result->__construct();
	return result;}

::openfl::display::Stage DocumentClass_obj::get_stage( ){
	HX_STACK_FRAME("DocumentClass","get_stage",0xea357664,"DocumentClass.get_stage","ApplicationMain.hx",154,0x0780ded5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(154)
	return ::openfl::Lib_obj::get_current()->get_stage();
}



DocumentClass_obj::DocumentClass_obj()
{
}

Dynamic DocumentClass_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DocumentClass_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DocumentClass_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_stage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DocumentClass_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DocumentClass_obj::__mClass,"__mClass");
};

#endif

Class DocumentClass_obj::__mClass;

void DocumentClass_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("DocumentClass"), hx::TCanCast< DocumentClass_obj> ,sStaticFields,sMemberFields,
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

void DocumentClass_obj::__boot()
{
}

