#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_spinehaxe_animation_ScaleTimeline
#include <spinehaxe/animation/ScaleTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TranslateTimeline
#include <spinehaxe/animation/TranslateTimeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void ScaleTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.ScaleTimeline","new",0x12ccddae,"spinehaxe.animation.ScaleTimeline.new","spinehaxe/animation/ScaleTimeline.hx",40,0x274b80c4)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(40)
	super::__construct(frameCount);
}
;
	return null();
}

//ScaleTimeline_obj::~ScaleTimeline_obj() { }

Dynamic ScaleTimeline_obj::__CreateEmpty() { return  new ScaleTimeline_obj; }
hx::ObjectPtr< ScaleTimeline_obj > ScaleTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< ScaleTimeline_obj > result = new ScaleTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic ScaleTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaleTimeline_obj > result = new ScaleTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ScaleTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.ScaleTimeline","apply",0x910d023c,"spinehaxe.animation.ScaleTimeline.apply","spinehaxe/animation/ScaleTimeline.hx",43,0x274b80c4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(44)
		Float _g = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		if (((time < _g))){
			HX_STACK_LINE(45)
			return null();
		}
		HX_STACK_LINE(47)
		::spinehaxe::Bone bone = skeleton->bones->__get(this->boneIndex).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
		HX_STACK_LINE(48)
		Float _g1 = this->frames->__unsafe_get((this->frames->length - (int)3));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(48)
		if (((time >= _g1))){
			HX_STACK_LINE(50)
			Float _g2 = this->frames->__unsafe_get((this->frames->length - (int)2));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(50)
			Float _g3 = ((bone->data->scaleX - (int)1) + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(50)
			Float _g4 = (_g3 - bone->scaleX);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(50)
			Float _g5 = (_g4 * alpha);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(50)
			hx::AddEq(bone->scaleX,_g5);
			HX_STACK_LINE(51)
			Float _g6 = this->frames->__unsafe_get((this->frames->length - (int)1));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(51)
			Float _g7 = ((bone->data->scaleY - (int)1) + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(51)
			Float _g8 = (_g7 - bone->scaleY);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(51)
			Float _g9 = (_g8 * alpha);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(51)
			hx::AddEq(bone->scaleY,_g9);
			HX_STACK_LINE(52)
			return null();
		}
		HX_STACK_LINE(55)
		int frameIndex = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,time,(int)3);		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(56)
		Float prevFrameX = this->frames->__unsafe_get((frameIndex - (int)2));		HX_STACK_VAR(prevFrameX,"prevFrameX");
		HX_STACK_LINE(57)
		Float prevFrameY = this->frames->__unsafe_get((frameIndex - (int)1));		HX_STACK_VAR(prevFrameY,"prevFrameY");
		HX_STACK_LINE(58)
		Float frameTime = this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(frameTime,"frameTime");
		HX_STACK_LINE(59)
		Float _g10 = this->frames->__unsafe_get((frameIndex + (int)-3));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(59)
		Float _g11 = (_g10 - frameTime);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(59)
		Float _g12 = (Float(((time - frameTime))) / Float(_g11));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(59)
		Float percent = ((int)1 - _g12);		HX_STACK_VAR(percent,"percent");
		HX_STACK_LINE(60)
		int _g13 = ::Math_obj::floor(((Float(frameIndex) / Float((int)3)) - (int)1));		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(60)
		Float _g14 = this->getCurvePercent(_g13,(  (((percent < (int)0))) ? Float((int)0) : Float((  (((percent > (int)1))) ? Float((int)1) : Float(percent) )) ));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(60)
		percent = _g14;
		HX_STACK_LINE(61)
		Float _g15 = this->frames->__unsafe_get((frameIndex + (int)1));		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(61)
		Float _g16 = (_g15 - prevFrameX);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(61)
		Float _g17 = (_g16 * percent);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(61)
		Float _g18 = (((bone->data->scaleX - (int)1) + prevFrameX) + _g17);		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(61)
		Float _g19 = (_g18 - bone->scaleX);		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(61)
		Float _g20 = (_g19 * alpha);		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(61)
		hx::AddEq(bone->scaleX,_g20);
		HX_STACK_LINE(62)
		Float _g21 = this->frames->__unsafe_get((frameIndex + (int)2));		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(62)
		Float _g22 = (_g21 - prevFrameY);		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(62)
		Float _g23 = (_g22 * percent);		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(62)
		Float _g24 = (((bone->data->scaleY - (int)1) + prevFrameY) + _g23);		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(62)
		Float _g25 = (_g24 - bone->scaleY);		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(62)
		Float _g26 = (_g25 * alpha);		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(62)
		hx::AddEq(bone->scaleY,_g26);
	}
return null();
}



ScaleTimeline_obj::ScaleTimeline_obj()
{
}

Dynamic ScaleTimeline_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScaleTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ScaleTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScaleTimeline_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScaleTimeline_obj::__mClass,"__mClass");
};

#endif

Class ScaleTimeline_obj::__mClass;

void ScaleTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.ScaleTimeline"), hx::TCanCast< ScaleTimeline_obj> ,sStaticFields,sMemberFields,
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

void ScaleTimeline_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
