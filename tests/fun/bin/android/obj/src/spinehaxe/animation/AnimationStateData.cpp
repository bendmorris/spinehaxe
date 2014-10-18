#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_AnimationStateData
#include <spinehaxe/animation/AnimationStateData.h>
#endif
namespace spinehaxe{
namespace animation{

Void AnimationStateData_obj::__construct(::spinehaxe::SkeletonData skeletonData)
{
HX_STACK_FRAME("spinehaxe.animation.AnimationStateData","new",0x29dab7f8,"spinehaxe.animation.AnimationStateData.new","spinehaxe/animation/AnimationStateData.hx",40,0x8af14ff6)
HX_STACK_THIS(this)
HX_STACK_ARG(skeletonData,"skeletonData")
{
	HX_STACK_LINE(41)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	this->animationToMixTime = _g;
	HX_STACK_LINE(42)
	this->defaultMix = (int)0;
	HX_STACK_LINE(43)
	this->skeletonData = skeletonData;
}
;
	return null();
}

//AnimationStateData_obj::~AnimationStateData_obj() { }

Dynamic AnimationStateData_obj::__CreateEmpty() { return  new AnimationStateData_obj; }
hx::ObjectPtr< AnimationStateData_obj > AnimationStateData_obj::__new(::spinehaxe::SkeletonData skeletonData)
{  hx::ObjectPtr< AnimationStateData_obj > result = new AnimationStateData_obj();
	result->__construct(skeletonData);
	return result;}

Dynamic AnimationStateData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationStateData_obj > result = new AnimationStateData_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AnimationStateData_obj::setMixByName( ::String fromName,::String toName,Float duration){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationStateData","setMixByName",0xffd7f3e4,"spinehaxe.animation.AnimationStateData.setMixByName","spinehaxe/animation/AnimationStateData.hx",46,0x8af14ff6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fromName,"fromName")
		HX_STACK_ARG(toName,"toName")
		HX_STACK_ARG(duration,"duration")
		HX_STACK_LINE(47)
		::spinehaxe::animation::Animation from = this->skeletonData->findAnimation(fromName);		HX_STACK_VAR(from,"from");
		HX_STACK_LINE(48)
		if (((from == null()))){
			HX_STACK_LINE(49)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Animation not found: ") + fromName)));
		}
		HX_STACK_LINE(50)
		::spinehaxe::animation::Animation to = this->skeletonData->findAnimation(toName);		HX_STACK_VAR(to,"to");
		HX_STACK_LINE(51)
		if (((to == null()))){
			HX_STACK_LINE(52)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Animation not found: ") + toName)));
		}
		HX_STACK_LINE(53)
		this->setMix(from,to,duration);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AnimationStateData_obj,setMixByName,(void))

Void AnimationStateData_obj::setMix( ::spinehaxe::animation::Animation from,::spinehaxe::animation::Animation to,Float duration){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationStateData","setMix",0x92668682,"spinehaxe.animation.AnimationStateData.setMix","spinehaxe/animation/AnimationStateData.hx",56,0x8af14ff6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(from,"from")
		HX_STACK_ARG(to,"to")
		HX_STACK_ARG(duration,"duration")
		HX_STACK_LINE(57)
		if (((from == null()))){
			HX_STACK_LINE(58)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("from cannot be null.")));
		}
		HX_STACK_LINE(59)
		if (((to == null()))){
			HX_STACK_LINE(60)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("to cannot be null.")));
		}
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			this->animationToMixTime->set(((from->name + HX_CSTRING(":")) + to->name),duration);
			HX_STACK_LINE(61)
			duration;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AnimationStateData_obj,setMix,(void))

Float AnimationStateData_obj::getMix( ::spinehaxe::animation::Animation from,::spinehaxe::animation::Animation to){
	HX_STACK_FRAME("spinehaxe.animation.AnimationStateData","getMix",0xc61e320e,"spinehaxe.animation.AnimationStateData.getMix","spinehaxe/animation/AnimationStateData.hx",64,0x8af14ff6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(from,"from")
	HX_STACK_ARG(to,"to")
	HX_STACK_LINE(65)
	::String key = ((from->name + HX_CSTRING(":")) + to->name);		HX_STACK_VAR(key,"key");
	HX_STACK_LINE(66)
	if ((!(this->animationToMixTime->exists(key)))){
		HX_STACK_LINE(67)
		return this->defaultMix;
	}
	HX_STACK_LINE(68)
	Dynamic time = this->animationToMixTime->get(key);		HX_STACK_VAR(time,"time");
	HX_STACK_LINE(69)
	return time;
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationStateData_obj,getMix,return )


AnimationStateData_obj::AnimationStateData_obj()
{
}

void AnimationStateData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationStateData);
	HX_MARK_MEMBER_NAME(skeletonData,"skeletonData");
	HX_MARK_MEMBER_NAME(animationToMixTime,"animationToMixTime");
	HX_MARK_MEMBER_NAME(defaultMix,"defaultMix");
	HX_MARK_END_CLASS();
}

void AnimationStateData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(skeletonData,"skeletonData");
	HX_VISIT_MEMBER_NAME(animationToMixTime,"animationToMixTime");
	HX_VISIT_MEMBER_NAME(defaultMix,"defaultMix");
}

Dynamic AnimationStateData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"setMix") ) { return setMix_dyn(); }
		if (HX_FIELD_EQ(inName,"getMix") ) { return getMix_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"defaultMix") ) { return defaultMix; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"skeletonData") ) { return skeletonData; }
		if (HX_FIELD_EQ(inName,"setMixByName") ) { return setMixByName_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"animationToMixTime") ) { return animationToMixTime; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationStateData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"defaultMix") ) { defaultMix=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"skeletonData") ) { skeletonData=inValue.Cast< ::spinehaxe::SkeletonData >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"animationToMixTime") ) { animationToMixTime=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationStateData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("skeletonData"));
	outFields->push(HX_CSTRING("animationToMixTime"));
	outFields->push(HX_CSTRING("defaultMix"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::SkeletonData*/ ,(int)offsetof(AnimationStateData_obj,skeletonData),HX_CSTRING("skeletonData")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(AnimationStateData_obj,animationToMixTime),HX_CSTRING("animationToMixTime")},
	{hx::fsFloat,(int)offsetof(AnimationStateData_obj,defaultMix),HX_CSTRING("defaultMix")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("skeletonData"),
	HX_CSTRING("animationToMixTime"),
	HX_CSTRING("defaultMix"),
	HX_CSTRING("setMixByName"),
	HX_CSTRING("setMix"),
	HX_CSTRING("getMix"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationStateData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationStateData_obj::__mClass,"__mClass");
};

#endif

Class AnimationStateData_obj::__mClass;

void AnimationStateData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.AnimationStateData"), hx::TCanCast< AnimationStateData_obj> ,sStaticFields,sMemberFields,
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

void AnimationStateData_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
