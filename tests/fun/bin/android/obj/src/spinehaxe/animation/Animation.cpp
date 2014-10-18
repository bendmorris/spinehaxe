#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void Animation_obj::__construct(::String name,Array< ::spinehaxe::animation::Timeline > timelines,Float duration)
{
HX_STACK_FRAME("spinehaxe.animation.Animation","new",0x5b5efd87,"spinehaxe.animation.Animation.new","spinehaxe/animation/Animation.hx",37,0x247e960b)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
HX_STACK_ARG(timelines,"timelines")
HX_STACK_ARG(duration,"duration")
{
	HX_STACK_LINE(41)
	this->duration = (int)0;
	HX_STACK_LINE(43)
	if (((name == null()))){
		HX_STACK_LINE(44)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(45)
	if (((timelines == null()))){
		HX_STACK_LINE(46)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("timelines cannot be null.")));
	}
	HX_STACK_LINE(47)
	this->name = name;
	HX_STACK_LINE(48)
	this->timelines = timelines;
	HX_STACK_LINE(49)
	this->duration = duration;
}
;
	return null();
}

//Animation_obj::~Animation_obj() { }

Dynamic Animation_obj::__CreateEmpty() { return  new Animation_obj; }
hx::ObjectPtr< Animation_obj > Animation_obj::__new(::String name,Array< ::spinehaxe::animation::Timeline > timelines,Float duration)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(name,timelines,duration);
	return result;}

Dynamic Animation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Animation_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,bool loop,Array< ::Dynamic > events){
{
		HX_STACK_FRAME("spinehaxe.animation.Animation","apply",0xba498a55,"spinehaxe.animation.Animation.apply","spinehaxe/animation/Animation.hx",53,0x247e960b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(loop,"loop")
		HX_STACK_ARG(events,"events")
		HX_STACK_LINE(54)
		if (((skeleton == null()))){
			HX_STACK_LINE(55)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("skeleton cannot be null.")));
		}
		HX_STACK_LINE(56)
		if (((bool(loop) && bool((this->duration != (int)0))))){
			HX_STACK_LINE(57)
			hx::ModEq(time,this->duration);
			HX_STACK_LINE(58)
			hx::ModEq(lastTime,this->duration);
		}
		HX_STACK_LINE(60)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(61)
		int n = this->timelines->length;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(62)
		while((true)){
			HX_STACK_LINE(62)
			if ((!(((i < n))))){
				HX_STACK_LINE(62)
				break;
			}
			HX_STACK_LINE(63)
			this->timelines->__get(i)->apply(skeleton,lastTime,time,events,(int)1);
			HX_STACK_LINE(64)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Animation_obj,apply,(void))

Void Animation_obj::mix( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,bool loop,Array< ::Dynamic > events,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.Animation","mix",0x5b5e3ec3,"spinehaxe.animation.Animation.mix","spinehaxe/animation/Animation.hx",70,0x247e960b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(loop,"loop")
		HX_STACK_ARG(events,"events")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(71)
		if (((skeleton == null()))){
			HX_STACK_LINE(72)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("skeleton cannot be null.")));
		}
		HX_STACK_LINE(73)
		if (((bool(loop) && bool((this->duration != (int)0))))){
			HX_STACK_LINE(74)
			hx::ModEq(time,this->duration);
			HX_STACK_LINE(75)
			hx::ModEq(lastTime,this->duration);
		}
		HX_STACK_LINE(77)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(78)
		int n = this->timelines->length;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(79)
		while((true)){
			HX_STACK_LINE(79)
			if ((!(((i < n))))){
				HX_STACK_LINE(79)
				break;
			}
			HX_STACK_LINE(80)
			this->timelines->__get(i)->apply(skeleton,lastTime,time,events,alpha);
			HX_STACK_LINE(81)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Animation_obj,mix,(void))

::String Animation_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.animation.Animation","toString",0x9cab9625,"spinehaxe.animation.Animation.toString","spinehaxe/animation/Animation.hx",86,0x247e960b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(86)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,toString,return )

int Animation_obj::binarySearch( Array< Float > values,Float target,int step){
	HX_STACK_FRAME("spinehaxe.animation.Animation","binarySearch",0x19a1bc42,"spinehaxe.animation.Animation.binarySearch","spinehaxe/animation/Animation.hx",90,0x247e960b)
	HX_STACK_ARG(values,"values")
	HX_STACK_ARG(target,"target")
	HX_STACK_ARG(step,"step")
	HX_STACK_LINE(91)
	int low = (int)0;		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(92)
	int high = ::Std_obj::_int(((Float(values->length) / Float(step)) - (int)2));		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(93)
	if (((high == (int)0))){
		HX_STACK_LINE(94)
		return step;
	}
	HX_STACK_LINE(95)
	int current = hx::UShr(high,(int)1);		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(96)
	while((true)){
		HX_STACK_LINE(97)
		Float _g = values->__unsafe_get((((current + (int)1)) * step));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(97)
		if (((_g <= target))){
			HX_STACK_LINE(98)
			low = (current + (int)1);
		}
		else{
			HX_STACK_LINE(99)
			high = current;
		}
		HX_STACK_LINE(100)
		if (((low == high))){
			HX_STACK_LINE(101)
			return (((low + (int)1)) * step);
		}
		HX_STACK_LINE(102)
		current = hx::UShr((low + high),(int)1);
	}
	HX_STACK_LINE(105)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Animation_obj,binarySearch,return )

int Animation_obj::linearSearch( Array< Float > values,Float target,int step){
	HX_STACK_FRAME("spinehaxe.animation.Animation","linearSearch",0x0771d526,"spinehaxe.animation.Animation.linearSearch","spinehaxe/animation/Animation.hx",108,0x247e960b)
	HX_STACK_ARG(values,"values")
	HX_STACK_ARG(target,"target")
	HX_STACK_ARG(step,"step")
	HX_STACK_LINE(109)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(110)
	int last = (values->length - step);		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(111)
	while((true)){
		HX_STACK_LINE(111)
		if ((!(((i <= last))))){
			HX_STACK_LINE(111)
			break;
		}
		HX_STACK_LINE(112)
		if (((values->__get(i) > target))){
			HX_STACK_LINE(113)
			return i;
		}
		HX_STACK_LINE(114)
		hx::AddEq(i,step);
	}
	HX_STACK_LINE(116)
	return (int)-1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Animation_obj,linearSearch,return )


Animation_obj::Animation_obj()
{
}

void Animation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animation);
	HX_MARK_MEMBER_NAME(timelines,"timelines");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void Animation_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(timelines,"timelines");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic Animation_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mix") ) { return mix_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timelines") ) { return timelines; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"binarySearch") ) { return binarySearch_dyn(); }
		if (HX_FIELD_EQ(inName,"linearSearch") ) { return linearSearch_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timelines") ) { timelines=inValue.Cast< Array< ::spinehaxe::animation::Timeline > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animation_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("timelines"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("binarySearch"),
	HX_CSTRING("linearSearch"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::spinehaxe::animation::Timeline >*/ ,(int)offsetof(Animation_obj,timelines),HX_CSTRING("timelines")},
	{hx::fsString,(int)offsetof(Animation_obj,name),HX_CSTRING("name")},
	{hx::fsFloat,(int)offsetof(Animation_obj,duration),HX_CSTRING("duration")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("timelines"),
	HX_CSTRING("name"),
	HX_CSTRING("duration"),
	HX_CSTRING("apply"),
	HX_CSTRING("mix"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
};

#endif

Class Animation_obj::__mClass;

void Animation_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.Animation"), hx::TCanCast< Animation_obj> ,sStaticFields,sMemberFields,
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

void Animation_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
