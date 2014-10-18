#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_Bitmap
#include <openfl/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
namespace openfl{
namespace display{

Void Bitmap_obj::__construct(::openfl::display::BitmapData bitmapData,::openfl::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{
HX_STACK_FRAME("openfl.display.Bitmap","new",0x8bc0314b,"openfl.display.Bitmap.new","openfl/display/Bitmap.hx",15,0x461b2743)
HX_STACK_THIS(this)
HX_STACK_ARG(bitmapData,"bitmapData")
HX_STACK_ARG(pixelSnapping,"pixelSnapping")
HX_STACK_ARG(__o_smoothing,"smoothing")
bool smoothing = __o_smoothing.Default(false);
{
	HX_STACK_LINE(17)
	Dynamic _g = ::openfl::display::DisplayObject_obj::lime_create_display_object();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(17)
	super::__construct(_g,HX_CSTRING("Bitmap"));
	HX_STACK_LINE(19)
	this->set_pixelSnapping((  (((pixelSnapping == null()))) ? ::openfl::display::PixelSnapping(::openfl::display::PixelSnapping_obj::AUTO) : ::openfl::display::PixelSnapping(pixelSnapping) ));
	HX_STACK_LINE(20)
	this->set_smoothing(smoothing);
	HX_STACK_LINE(22)
	if (((bitmapData != null()))){
		HX_STACK_LINE(24)
		this->set_bitmapData(bitmapData);
	}
	else{
		HX_STACK_LINE(26)
		if (((this->bitmapData != null()))){
			HX_STACK_LINE(28)
			this->__rebuild();
		}
	}
}
;
	return null();
}

//Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::openfl::display::BitmapData bitmapData,::openfl::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(bitmapData,pixelSnapping,__o_smoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Bitmap_obj::__rebuild( ){
{
		HX_STACK_FRAME("openfl.display.Bitmap","__rebuild",0x3ffbe2a6,"openfl.display.Bitmap.__rebuild","openfl/display/Bitmap.hx",37,0x461b2743)
		HX_STACK_THIS(this)
		HX_STACK_LINE(37)
		if (((this->__handle != null()))){
			HX_STACK_LINE(39)
			::openfl::display::Graphics gfx = this->get_graphics();		HX_STACK_VAR(gfx,"gfx");
			HX_STACK_LINE(40)
			gfx->clear();
			HX_STACK_LINE(42)
			if (((this->bitmapData != null()))){
				HX_STACK_LINE(44)
				gfx->beginBitmapFill(this->bitmapData,null(),false,this->smoothing);
				HX_STACK_LINE(45)
				int _g = this->bitmapData->get_width();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(45)
				int _g1 = this->bitmapData->get_height();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(45)
				gfx->drawRect((int)0,(int)0,_g,_g1);
				HX_STACK_LINE(46)
				gfx->endFill();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,__rebuild,(void))

::openfl::display::BitmapData Bitmap_obj::set_bitmapData( ::openfl::display::BitmapData value){
	HX_STACK_FRAME("openfl.display.Bitmap","set_bitmapData",0x81bf676b,"openfl.display.Bitmap.set_bitmapData","openfl/display/Bitmap.hx",62,0x461b2743)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(64)
	this->bitmapData = value;
	HX_STACK_LINE(65)
	this->__rebuild();
	HX_STACK_LINE(67)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,set_bitmapData,return )

bool Bitmap_obj::set_smoothing( bool value){
	HX_STACK_FRAME("openfl.display.Bitmap","set_smoothing",0xdb1c6002,"openfl.display.Bitmap.set_smoothing","openfl/display/Bitmap.hx",72,0x461b2743)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(74)
	this->smoothing = value;
	HX_STACK_LINE(75)
	this->__rebuild();
	HX_STACK_LINE(77)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,set_smoothing,return )


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(smoothing,"smoothing");
	::openfl::display::DisplayObject_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Bitmap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	HX_VISIT_MEMBER_NAME(smoothing,"smoothing");
	::openfl::display::DisplayObject_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Bitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { return smoothing; }
		if (HX_FIELD_EQ(inName,"__rebuild") ) { return __rebuild_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_smoothing") ) { return set_smoothing_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_bitmapData") ) { return set_bitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { if (inCallProp) return set_smoothing(inValue);smoothing=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { if (inCallProp) return set_bitmapData(inValue);bitmapData=inValue.Cast< ::openfl::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("smoothing"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::display::BitmapData*/ ,(int)offsetof(Bitmap_obj,bitmapData),HX_CSTRING("bitmapData")},
	{hx::fsBool,(int)offsetof(Bitmap_obj,smoothing),HX_CSTRING("smoothing")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bitmapData"),
	HX_CSTRING("smoothing"),
	HX_CSTRING("__rebuild"),
	HX_CSTRING("set_bitmapData"),
	HX_CSTRING("set_smoothing"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

#endif

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
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

void Bitmap_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
