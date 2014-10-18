#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
#endif
#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_CurveTimeline
#include <spinehaxe/animation/CurveTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_RotateTimeline
#include <spinehaxe/animation/RotateTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void RotateTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.RotateTimeline","new",0xa863e9bd,"spinehaxe.animation.RotateTimeline.new","spinehaxe/animation/RotateTimeline.hx",44,0x76ce26d1)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(45)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat((frameCount * (int)2));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	this->frames = _g;
	HX_STACK_LINE(46)
	super::__construct(frameCount);
}
;
	return null();
}

//RotateTimeline_obj::~RotateTimeline_obj() { }

Dynamic RotateTimeline_obj::__CreateEmpty() { return  new RotateTimeline_obj; }
hx::ObjectPtr< RotateTimeline_obj > RotateTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< RotateTimeline_obj > result = new RotateTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic RotateTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RotateTimeline_obj > result = new RotateTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

Void RotateTimeline_obj::setFrame( int frameIndex,Float time,Float angle){
{
		HX_STACK_FRAME("spinehaxe.animation.RotateTimeline","setFrame",0x4dddb6ae,"spinehaxe.animation.RotateTimeline.setFrame","spinehaxe/animation/RotateTimeline.hx",50,0x76ce26d1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(angle,"angle")
		HX_STACK_LINE(51)
		hx::MultEq(frameIndex,(int)2);
		HX_STACK_LINE(52)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(53)
		this->frames->__unsafe_set((frameIndex + (int)1),angle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(RotateTimeline_obj,setFrame,(void))

Void RotateTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.RotateTimeline","apply",0x038a700b,"spinehaxe.animation.RotateTimeline.apply","spinehaxe/animation/RotateTimeline.hx",56,0x76ce26d1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(57)
		Float _g = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		if (((time < _g))){
			HX_STACK_LINE(58)
			return null();
		}
		HX_STACK_LINE(60)
		::spinehaxe::Bone bone = skeleton->bones->__get(this->boneIndex).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
		HX_STACK_LINE(61)
		Float amount;		HX_STACK_VAR(amount,"amount");
		HX_STACK_LINE(62)
		Float _g1 = this->frames->__unsafe_get((this->frames->length - (int)2));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		if (((time >= _g1))){
			HX_STACK_LINE(64)
			Float _g2 = this->frames->__unsafe_get((this->frames->length - (int)1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(64)
			Float _g3 = (bone->data->rotation + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(64)
			Float _g4 = (_g3 - bone->rotation);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(64)
			amount = _g4;
			HX_STACK_LINE(65)
			while((true)){
				HX_STACK_LINE(65)
				if ((!(((amount > (int)180))))){
					HX_STACK_LINE(65)
					break;
				}
				HX_STACK_LINE(65)
				hx::SubEq(amount,(int)360);
			}
			HX_STACK_LINE(66)
			while((true)){
				HX_STACK_LINE(66)
				if ((!(((amount < (int)-180))))){
					HX_STACK_LINE(66)
					break;
				}
				HX_STACK_LINE(66)
				hx::AddEq(amount,(int)360);
			}
			HX_STACK_LINE(67)
			hx::AddEq(bone->rotation,(amount * alpha));
			HX_STACK_LINE(68)
			return null();
		}
		HX_STACK_LINE(71)
		int frameIndex = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,time,(int)2);		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(72)
		Float prevFrameValue = this->frames->__unsafe_get((frameIndex - (int)1));		HX_STACK_VAR(prevFrameValue,"prevFrameValue");
		HX_STACK_LINE(73)
		Float frameTime = this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(frameTime,"frameTime");
		HX_STACK_LINE(74)
		Float _g5 = this->frames->__unsafe_get((frameIndex + (int)-2));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(74)
		Float _g6 = (_g5 - frameTime);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(74)
		Float _g7 = (Float(((time - frameTime))) / Float(_g6));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(74)
		Float percent = ((int)1 - _g7);		HX_STACK_VAR(percent,"percent");
		HX_STACK_LINE(75)
		int _g8 = ::Math_obj::floor(((Float(frameIndex) / Float((int)2)) - (int)1));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(75)
		Float _g9 = this->getCurvePercent(_g8,(  (((percent < (int)0))) ? Float((int)0) : Float((  (((percent > (int)1))) ? Float((int)1) : Float(percent) )) ));		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(75)
		percent = _g9;
		HX_STACK_LINE(76)
		Float _g10 = this->frames->__unsafe_get((frameIndex + (int)1));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(76)
		Float _g11 = (_g10 - prevFrameValue);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(76)
		amount = _g11;
		HX_STACK_LINE(77)
		while((true)){
			HX_STACK_LINE(77)
			if ((!(((amount > (int)180))))){
				HX_STACK_LINE(77)
				break;
			}
			HX_STACK_LINE(77)
			hx::SubEq(amount,(int)360);
		}
		HX_STACK_LINE(78)
		while((true)){
			HX_STACK_LINE(78)
			if ((!(((amount < (int)-180))))){
				HX_STACK_LINE(78)
				break;
			}
			HX_STACK_LINE(78)
			hx::AddEq(amount,(int)360);
		}
		HX_STACK_LINE(79)
		amount = ((bone->data->rotation + ((prevFrameValue + (amount * percent)))) - bone->rotation);
		HX_STACK_LINE(80)
		while((true)){
			HX_STACK_LINE(80)
			if ((!(((amount > (int)180))))){
				HX_STACK_LINE(80)
				break;
			}
			HX_STACK_LINE(80)
			hx::SubEq(amount,(int)360);
		}
		HX_STACK_LINE(81)
		while((true)){
			HX_STACK_LINE(81)
			if ((!(((amount < (int)-180))))){
				HX_STACK_LINE(81)
				break;
			}
			HX_STACK_LINE(81)
			hx::AddEq(amount,(int)360);
		}
		HX_STACK_LINE(82)
		hx::AddEq(bone->rotation,(amount * alpha));
	}
return null();
}


int RotateTimeline_obj::PREV_FRAME_TIME;

int RotateTimeline_obj::FRAME_VALUE;


RotateTimeline_obj::RotateTimeline_obj()
{
}

void RotateTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RotateTimeline);
	HX_MARK_MEMBER_NAME(boneIndex,"boneIndex");
	HX_MARK_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RotateTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(boneIndex,"boneIndex");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Visit(HX_VISIT_ARG);
}

Dynamic RotateTimeline_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setFrame") ) { return setFrame_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"boneIndex") ) { return boneIndex; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RotateTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"boneIndex") ) { boneIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RotateTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("boneIndex"));
	outFields->push(HX_CSTRING("frames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PREV_FRAME_TIME"),
	HX_CSTRING("FRAME_VALUE"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(RotateTimeline_obj,boneIndex),HX_CSTRING("boneIndex")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(RotateTimeline_obj,frames),HX_CSTRING("frames")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("boneIndex"),
	HX_CSTRING("frames"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RotateTimeline_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(RotateTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_MARK_MEMBER_NAME(RotateTimeline_obj::FRAME_VALUE,"FRAME_VALUE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RotateTimeline_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(RotateTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_VISIT_MEMBER_NAME(RotateTimeline_obj::FRAME_VALUE,"FRAME_VALUE");
};

#endif

Class RotateTimeline_obj::__mClass;

void RotateTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.RotateTimeline"), hx::TCanCast< RotateTimeline_obj> ,sStaticFields,sMemberFields,
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

void RotateTimeline_obj::__boot()
{
	PREV_FRAME_TIME= (int)-2;
	FRAME_VALUE= (int)1;
}

} // end namespace spinehaxe
} // end namespace animation
