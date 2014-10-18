#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntry
#include <spinehaxe/animation/TrackEntry.h>
#endif
namespace spinehaxe{
namespace animation{

Void TrackEntry_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.animation.TrackEntry","new",0x5fa465a8,"spinehaxe.animation.TrackEntry.new","spinehaxe/animation/TrackEntry.hx",36,0x80903a46)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(49)
	this->mix = (int)1;
	HX_STACK_LINE(46)
	this->timeScale = (int)1;
	HX_STACK_LINE(44)
	this->lastTime = (int)-1;
	HX_STACK_LINE(43)
	this->time = (int)0;
}
;
	return null();
}

//TrackEntry_obj::~TrackEntry_obj() { }

Dynamic TrackEntry_obj::__CreateEmpty() { return  new TrackEntry_obj; }
hx::ObjectPtr< TrackEntry_obj > TrackEntry_obj::__new()
{  hx::ObjectPtr< TrackEntry_obj > result = new TrackEntry_obj();
	result->__construct();
	return result;}

Dynamic TrackEntry_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TrackEntry_obj > result = new TrackEntry_obj();
	result->__construct();
	return result;}

::String TrackEntry_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.animation.TrackEntry","toString",0x4d941664,"spinehaxe.animation.TrackEntry.toString","spinehaxe/animation/TrackEntry.hx",55,0x80903a46)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	if (((this->animation == null()))){
		HX_STACK_LINE(55)
		return HX_CSTRING("<none>");
	}
	else{
		HX_STACK_LINE(55)
		return this->animation->name;
	}
	HX_STACK_LINE(55)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TrackEntry_obj,toString,return )


TrackEntry_obj::TrackEntry_obj()
{
}

void TrackEntry_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TrackEntry);
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_MEMBER_NAME(previous,"previous");
	HX_MARK_MEMBER_NAME(animation,"animation");
	HX_MARK_MEMBER_NAME(loop,"loop");
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(lastTime,"lastTime");
	HX_MARK_MEMBER_NAME(endTime,"endTime");
	HX_MARK_MEMBER_NAME(timeScale,"timeScale");
	HX_MARK_MEMBER_NAME(mixTime,"mixTime");
	HX_MARK_MEMBER_NAME(mixDuration,"mixDuration");
	HX_MARK_MEMBER_NAME(mix,"mix");
	HX_MARK_MEMBER_NAME(onStart,"onStart");
	HX_MARK_MEMBER_NAME(onEnd,"onEnd");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(onEvent,"onEvent");
	HX_MARK_END_CLASS();
}

void TrackEntry_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(next,"next");
	HX_VISIT_MEMBER_NAME(previous,"previous");
	HX_VISIT_MEMBER_NAME(animation,"animation");
	HX_VISIT_MEMBER_NAME(loop,"loop");
	HX_VISIT_MEMBER_NAME(delay,"delay");
	HX_VISIT_MEMBER_NAME(time,"time");
	HX_VISIT_MEMBER_NAME(lastTime,"lastTime");
	HX_VISIT_MEMBER_NAME(endTime,"endTime");
	HX_VISIT_MEMBER_NAME(timeScale,"timeScale");
	HX_VISIT_MEMBER_NAME(mixTime,"mixTime");
	HX_VISIT_MEMBER_NAME(mixDuration,"mixDuration");
	HX_VISIT_MEMBER_NAME(mix,"mix");
	HX_VISIT_MEMBER_NAME(onStart,"onStart");
	HX_VISIT_MEMBER_NAME(onEnd,"onEnd");
	HX_VISIT_MEMBER_NAME(onComplete,"onComplete");
	HX_VISIT_MEMBER_NAME(onEvent,"onEvent");
}

Dynamic TrackEntry_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mix") ) { return mix; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		if (HX_FIELD_EQ(inName,"loop") ) { return loop; }
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		if (HX_FIELD_EQ(inName,"onEnd") ) { return onEnd; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endTime") ) { return endTime; }
		if (HX_FIELD_EQ(inName,"mixTime") ) { return mixTime; }
		if (HX_FIELD_EQ(inName,"onStart") ) { return onStart; }
		if (HX_FIELD_EQ(inName,"onEvent") ) { return onEvent; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"previous") ) { return previous; }
		if (HX_FIELD_EQ(inName,"lastTime") ) { return lastTime; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { return animation; }
		if (HX_FIELD_EQ(inName,"timeScale") ) { return timeScale; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mixDuration") ) { return mixDuration; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TrackEntry_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mix") ) { mix=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::spinehaxe::animation::TrackEntry >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loop") ) { loop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onEnd") ) { onEnd=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endTime") ) { endTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mixTime") ) { mixTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onStart") ) { onStart=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onEvent") ) { onEvent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"previous") ) { previous=inValue.Cast< ::spinehaxe::animation::TrackEntry >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastTime") ) { lastTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { animation=inValue.Cast< ::spinehaxe::animation::Animation >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeScale") ) { timeScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mixDuration") ) { mixDuration=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TrackEntry_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("next"));
	outFields->push(HX_CSTRING("previous"));
	outFields->push(HX_CSTRING("animation"));
	outFields->push(HX_CSTRING("loop"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("lastTime"));
	outFields->push(HX_CSTRING("endTime"));
	outFields->push(HX_CSTRING("timeScale"));
	outFields->push(HX_CSTRING("mixTime"));
	outFields->push(HX_CSTRING("mixDuration"));
	outFields->push(HX_CSTRING("mix"));
	outFields->push(HX_CSTRING("onStart"));
	outFields->push(HX_CSTRING("onEnd"));
	outFields->push(HX_CSTRING("onComplete"));
	outFields->push(HX_CSTRING("onEvent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::animation::TrackEntry*/ ,(int)offsetof(TrackEntry_obj,next),HX_CSTRING("next")},
	{hx::fsObject /*::spinehaxe::animation::TrackEntry*/ ,(int)offsetof(TrackEntry_obj,previous),HX_CSTRING("previous")},
	{hx::fsObject /*::spinehaxe::animation::Animation*/ ,(int)offsetof(TrackEntry_obj,animation),HX_CSTRING("animation")},
	{hx::fsBool,(int)offsetof(TrackEntry_obj,loop),HX_CSTRING("loop")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,delay),HX_CSTRING("delay")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,time),HX_CSTRING("time")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,lastTime),HX_CSTRING("lastTime")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,endTime),HX_CSTRING("endTime")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,timeScale),HX_CSTRING("timeScale")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,mixTime),HX_CSTRING("mixTime")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,mixDuration),HX_CSTRING("mixDuration")},
	{hx::fsFloat,(int)offsetof(TrackEntry_obj,mix),HX_CSTRING("mix")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(TrackEntry_obj,onStart),HX_CSTRING("onStart")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(TrackEntry_obj,onEnd),HX_CSTRING("onEnd")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(TrackEntry_obj,onComplete),HX_CSTRING("onComplete")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(TrackEntry_obj,onEvent),HX_CSTRING("onEvent")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("next"),
	HX_CSTRING("previous"),
	HX_CSTRING("animation"),
	HX_CSTRING("loop"),
	HX_CSTRING("delay"),
	HX_CSTRING("time"),
	HX_CSTRING("lastTime"),
	HX_CSTRING("endTime"),
	HX_CSTRING("timeScale"),
	HX_CSTRING("mixTime"),
	HX_CSTRING("mixDuration"),
	HX_CSTRING("mix"),
	HX_CSTRING("onStart"),
	HX_CSTRING("onEnd"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("onEvent"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TrackEntry_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TrackEntry_obj::__mClass,"__mClass");
};

#endif

Class TrackEntry_obj::__mClass;

void TrackEntry_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.TrackEntry"), hx::TCanCast< TrackEntry_obj> ,sStaticFields,sMemberFields,
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

void TrackEntry_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
