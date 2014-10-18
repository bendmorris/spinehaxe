#include <hxcpp.h>

#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
namespace openfl{
namespace display{

Void InteractiveObject_obj::__construct(Dynamic handle,::String type)
{
HX_STACK_FRAME("openfl.display.InteractiveObject","new",0x042d7309,"openfl.display.InteractiveObject.new","openfl/display/InteractiveObject.hx",18,0x983a3689)
HX_STACK_THIS(this)
HX_STACK_ARG(handle,"handle")
HX_STACK_ARG(type,"type")
{
	HX_STACK_LINE(20)
	this->doubleClickEnabled = false;
	HX_STACK_LINE(21)
	this->__mouseEnabled = true;
	HX_STACK_LINE(23)
	super::__construct(handle,type);
}
;
	return null();
}

//InteractiveObject_obj::~InteractiveObject_obj() { }

Dynamic InteractiveObject_obj::__CreateEmpty() { return  new InteractiveObject_obj; }
hx::ObjectPtr< InteractiveObject_obj > InteractiveObject_obj::__new(Dynamic handle,::String type)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(handle,type);
	return result;}

Dynamic InteractiveObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool InteractiveObject_obj::__dismissSoftKeyboard( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","__dismissSoftKeyboard",0xaa9793e4,"openfl.display.InteractiveObject.__dismissSoftKeyboard","openfl/display/InteractiveObject.hx",30,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(30)
	return ::openfl::display::InteractiveObject_obj::lime_display_object_dismiss_soft_keyboard(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,__dismissSoftKeyboard,return )

bool InteractiveObject_obj::requestSoftKeyboard( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","requestSoftKeyboard",0x985d3a49,"openfl.display.InteractiveObject.requestSoftKeyboard","openfl/display/InteractiveObject.hx",37,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return ::openfl::display::InteractiveObject_obj::lime_display_object_request_soft_keyboard(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,requestSoftKeyboard,return )

::openfl::display::InteractiveObject InteractiveObject_obj::__asInteractiveObject( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","__asInteractiveObject",0xe90b22b8,"openfl.display.InteractiveObject.__asInteractiveObject","openfl/display/InteractiveObject.hx",44,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(44)
	return hx::ObjectPtr<OBJ_>(this);
}


bool InteractiveObject_obj::get_mouseEnabled( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","get_mouseEnabled",0x602a691c,"openfl.display.InteractiveObject.get_mouseEnabled","openfl/display/InteractiveObject.hx",56,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	return this->__mouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,get_mouseEnabled,return )

bool InteractiveObject_obj::set_mouseEnabled( bool value){
	HX_STACK_FRAME("openfl.display.InteractiveObject","set_mouseEnabled",0xb66c5690,"openfl.display.InteractiveObject.set_mouseEnabled","openfl/display/InteractiveObject.hx",57,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(59)
	this->__mouseEnabled = value;
	HX_STACK_LINE(60)
	::openfl::display::InteractiveObject_obj::lime_display_object_set_mouse_enabled(this->__handle,value);
	HX_STACK_LINE(61)
	return this->__mouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,set_mouseEnabled,return )

bool InteractiveObject_obj::set_moveForSoftKeyboard( bool value){
	HX_STACK_FRAME("openfl.display.InteractiveObject","set_moveForSoftKeyboard",0xa0762915,"openfl.display.InteractiveObject.set_moveForSoftKeyboard","openfl/display/InteractiveObject.hx",66,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(68)
	::openfl::display::InteractiveObject_obj::lime_display_object_set_moves_for_soft_keyboard(this->__handle,value);
	HX_STACK_LINE(69)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,set_moveForSoftKeyboard,return )

bool InteractiveObject_obj::get_moveForSoftKeyboard( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","get_moveForSoftKeyboard",0x9e14c009,"openfl.display.InteractiveObject.get_moveForSoftKeyboard","openfl/display/InteractiveObject.hx",76,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(76)
	return ::openfl::display::InteractiveObject_obj::lime_display_object_get_moves_for_soft_keyboard(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,get_moveForSoftKeyboard,return )

bool InteractiveObject_obj::set_needsSoftKeyboard( bool value){
	HX_STACK_FRAME("openfl.display.InteractiveObject","set_needsSoftKeyboard",0x06e69c7a,"openfl.display.InteractiveObject.set_needsSoftKeyboard","openfl/display/InteractiveObject.hx",81,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(83)
	::openfl::display::InteractiveObject_obj::lime_display_object_set_needs_soft_keyboard(this->__handle,value);
	HX_STACK_LINE(84)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,set_needsSoftKeyboard,return )

bool InteractiveObject_obj::get_needsSoftKeyboard( ){
	HX_STACK_FRAME("openfl.display.InteractiveObject","get_needsSoftKeyboard",0xb2ddce6e,"openfl.display.InteractiveObject.get_needsSoftKeyboard","openfl/display/InteractiveObject.hx",91,0x983a3689)
	HX_STACK_THIS(this)
	HX_STACK_LINE(91)
	return ::openfl::display::InteractiveObject_obj::lime_display_object_get_needs_soft_keyboard(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,get_needsSoftKeyboard,return )

Dynamic InteractiveObject_obj::lime_display_object_set_mouse_enabled;

Dynamic InteractiveObject_obj::lime_display_object_set_needs_soft_keyboard;

Dynamic InteractiveObject_obj::lime_display_object_get_needs_soft_keyboard;

Dynamic InteractiveObject_obj::lime_display_object_set_moves_for_soft_keyboard;

Dynamic InteractiveObject_obj::lime_display_object_get_moves_for_soft_keyboard;

Dynamic InteractiveObject_obj::lime_display_object_dismiss_soft_keyboard;

Dynamic InteractiveObject_obj::lime_display_object_request_soft_keyboard;


InteractiveObject_obj::InteractiveObject_obj()
{
}

Dynamic InteractiveObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return get_mouseEnabled(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__mouseEnabled") ) { return __mouseEnabled; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_mouseEnabled") ) { return get_mouseEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mouseEnabled") ) { return set_mouseEnabled_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { return get_needsSoftKeyboard(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { return doubleClickEnabled; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { return get_moveForSoftKeyboard(); }
		if (HX_FIELD_EQ(inName,"requestSoftKeyboard") ) { return requestSoftKeyboard_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"__dismissSoftKeyboard") ) { return __dismissSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"__asInteractiveObject") ) { return __asInteractiveObject_dyn(); }
		if (HX_FIELD_EQ(inName,"set_needsSoftKeyboard") ) { return set_needsSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"get_needsSoftKeyboard") ) { return get_needsSoftKeyboard_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"set_moveForSoftKeyboard") ) { return set_moveForSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"get_moveForSoftKeyboard") ) { return get_moveForSoftKeyboard_dyn(); }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mouse_enabled") ) { return lime_display_object_set_mouse_enabled; }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"lime_display_object_dismiss_soft_keyboard") ) { return lime_display_object_dismiss_soft_keyboard; }
		if (HX_FIELD_EQ(inName,"lime_display_object_request_soft_keyboard") ) { return lime_display_object_request_soft_keyboard; }
		break;
	case 43:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_needs_soft_keyboard") ) { return lime_display_object_set_needs_soft_keyboard; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_needs_soft_keyboard") ) { return lime_display_object_get_needs_soft_keyboard; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_moves_for_soft_keyboard") ) { return lime_display_object_set_moves_for_soft_keyboard; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_moves_for_soft_keyboard") ) { return lime_display_object_get_moves_for_soft_keyboard; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InteractiveObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return set_mouseEnabled(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__mouseEnabled") ) { __mouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { return set_needsSoftKeyboard(inValue); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { doubleClickEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { return set_moveForSoftKeyboard(inValue); }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mouse_enabled") ) { lime_display_object_set_mouse_enabled=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"lime_display_object_dismiss_soft_keyboard") ) { lime_display_object_dismiss_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_request_soft_keyboard") ) { lime_display_object_request_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 43:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_needs_soft_keyboard") ) { lime_display_object_set_needs_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_needs_soft_keyboard") ) { lime_display_object_get_needs_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_set_moves_for_soft_keyboard") ) { lime_display_object_set_moves_for_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_moves_for_soft_keyboard") ) { lime_display_object_get_moves_for_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InteractiveObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("doubleClickEnabled"));
	outFields->push(HX_CSTRING("mouseEnabled"));
	outFields->push(HX_CSTRING("moveForSoftKeyboard"));
	outFields->push(HX_CSTRING("needsSoftKeyboard"));
	outFields->push(HX_CSTRING("__mouseEnabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lime_display_object_set_mouse_enabled"),
	HX_CSTRING("lime_display_object_set_needs_soft_keyboard"),
	HX_CSTRING("lime_display_object_get_needs_soft_keyboard"),
	HX_CSTRING("lime_display_object_set_moves_for_soft_keyboard"),
	HX_CSTRING("lime_display_object_get_moves_for_soft_keyboard"),
	HX_CSTRING("lime_display_object_dismiss_soft_keyboard"),
	HX_CSTRING("lime_display_object_request_soft_keyboard"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(InteractiveObject_obj,doubleClickEnabled),HX_CSTRING("doubleClickEnabled")},
	{hx::fsBool,(int)offsetof(InteractiveObject_obj,__mouseEnabled),HX_CSTRING("__mouseEnabled")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("doubleClickEnabled"),
	HX_CSTRING("__mouseEnabled"),
	HX_CSTRING("__dismissSoftKeyboard"),
	HX_CSTRING("requestSoftKeyboard"),
	HX_CSTRING("__asInteractiveObject"),
	HX_CSTRING("get_mouseEnabled"),
	HX_CSTRING("set_mouseEnabled"),
	HX_CSTRING("set_moveForSoftKeyboard"),
	HX_CSTRING("get_moveForSoftKeyboard"),
	HX_CSTRING("set_needsSoftKeyboard"),
	HX_CSTRING("get_needsSoftKeyboard"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_mouse_enabled,"lime_display_object_set_mouse_enabled");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_needs_soft_keyboard,"lime_display_object_set_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_get_needs_soft_keyboard,"lime_display_object_get_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_moves_for_soft_keyboard,"lime_display_object_set_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_get_moves_for_soft_keyboard,"lime_display_object_get_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_dismiss_soft_keyboard,"lime_display_object_dismiss_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::lime_display_object_request_soft_keyboard,"lime_display_object_request_soft_keyboard");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_mouse_enabled,"lime_display_object_set_mouse_enabled");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_needs_soft_keyboard,"lime_display_object_set_needs_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_get_needs_soft_keyboard,"lime_display_object_get_needs_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_set_moves_for_soft_keyboard,"lime_display_object_set_moves_for_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_get_moves_for_soft_keyboard,"lime_display_object_get_moves_for_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_dismiss_soft_keyboard,"lime_display_object_dismiss_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::lime_display_object_request_soft_keyboard,"lime_display_object_request_soft_keyboard");
};

#endif

Class InteractiveObject_obj::__mClass;

void InteractiveObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.InteractiveObject"), hx::TCanCast< InteractiveObject_obj> ,sStaticFields,sMemberFields,
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

void InteractiveObject_obj::__boot()
{
	lime_display_object_set_mouse_enabled= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_mouse_enabled"),(int)2);
	lime_display_object_set_needs_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_needs_soft_keyboard"),(int)2);
	lime_display_object_get_needs_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_needs_soft_keyboard"),(int)1);
	lime_display_object_set_moves_for_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_moves_for_soft_keyboard"),(int)2);
	lime_display_object_get_moves_for_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_moves_for_soft_keyboard"),(int)1);
	lime_display_object_dismiss_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_dismiss_soft_keyboard"),(int)1);
	lime_display_object_request_soft_keyboard= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_request_soft_keyboard"),(int)1);
}

} // end namespace openfl
} // end namespace display
