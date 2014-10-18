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
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TranslateTimeline
#include <spinehaxe/animation/TranslateTimeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void TranslateTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.TranslateTimeline","new",0x7895d8f2,"spinehaxe.animation.TranslateTimeline.new","spinehaxe/animation/TranslateTimeline.hx",45,0xc65e6300)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(46)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat((frameCount * (int)3));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(46)
	this->frames = _g;
	HX_STACK_LINE(47)
	super::__construct(frameCount);
}
;
	return null();
}

//TranslateTimeline_obj::~TranslateTimeline_obj() { }

Dynamic TranslateTimeline_obj::__CreateEmpty() { return  new TranslateTimeline_obj; }
hx::ObjectPtr< TranslateTimeline_obj > TranslateTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< TranslateTimeline_obj > result = new TranslateTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic TranslateTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TranslateTimeline_obj > result = new TranslateTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TranslateTimeline_obj::setFrame( int frameIndex,Float time,Float x,Float y){
{
		HX_STACK_FRAME("spinehaxe.animation.TranslateTimeline","setFrame",0xa8338759,"spinehaxe.animation.TranslateTimeline.setFrame","spinehaxe/animation/TranslateTimeline.hx",51,0xc65e6300)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(52)
		hx::MultEq(frameIndex,(int)3);
		HX_STACK_LINE(53)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(54)
		this->frames->__unsafe_set((frameIndex + (int)1),x);
		HX_STACK_LINE(55)
		this->frames->__unsafe_set((frameIndex + (int)2),y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(TranslateTimeline_obj,setFrame,(void))

Void TranslateTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.TranslateTimeline","apply",0xb77e5680,"spinehaxe.animation.TranslateTimeline.apply","spinehaxe/animation/TranslateTimeline.hx",58,0xc65e6300)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(59)
		Float _g = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(59)
		if (((time < _g))){
			HX_STACK_LINE(60)
			return null();
		}
		HX_STACK_LINE(62)
		::spinehaxe::Bone bone = skeleton->bones->__get(this->boneIndex).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
		HX_STACK_LINE(63)
		Float _g1 = this->frames->__unsafe_get((this->frames->length - (int)3));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(63)
		if (((time >= _g1))){
			HX_STACK_LINE(65)
			Float _g2 = this->frames->__unsafe_get((this->frames->length - (int)2));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(65)
			Float _g3 = (bone->data->x + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(65)
			Float _g4 = (_g3 - bone->x);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(65)
			Float _g5 = (_g4 * alpha);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(65)
			hx::AddEq(bone->x,_g5);
			HX_STACK_LINE(66)
			Float _g6 = this->frames->__unsafe_get((this->frames->length - (int)1));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(66)
			Float _g7 = (bone->data->y + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(66)
			Float _g8 = (_g7 - bone->y);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(66)
			Float _g9 = (_g8 * alpha);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(66)
			hx::AddEq(bone->y,_g9);
			HX_STACK_LINE(67)
			return null();
		}
		HX_STACK_LINE(70)
		int frameIndex = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,time,(int)3);		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(71)
		Float prevFrameX = this->frames->__unsafe_get((frameIndex - (int)2));		HX_STACK_VAR(prevFrameX,"prevFrameX");
		HX_STACK_LINE(72)
		Float prevFrameY = this->frames->__unsafe_get((frameIndex - (int)1));		HX_STACK_VAR(prevFrameY,"prevFrameY");
		HX_STACK_LINE(73)
		Float frameTime = this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(frameTime,"frameTime");
		HX_STACK_LINE(74)
		Float _g10 = this->frames->__unsafe_get((frameIndex + (int)-3));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(74)
		Float _g11 = (_g10 - frameTime);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(74)
		Float _g12 = (Float(((time - frameTime))) / Float(_g11));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(74)
		Float percent = ((int)1 - _g12);		HX_STACK_VAR(percent,"percent");
		HX_STACK_LINE(75)
		int _g13 = ::Math_obj::floor(((Float(frameIndex) / Float((int)3)) - (int)1));		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(75)
		Float _g14 = this->getCurvePercent(_g13,(  (((percent < (int)0))) ? Float((int)0) : Float((  (((percent > (int)1))) ? Float((int)1) : Float(percent) )) ));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(75)
		percent = _g14;
		HX_STACK_LINE(76)
		Float _g15 = this->frames->__unsafe_get((frameIndex + (int)1));		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(76)
		Float _g16 = (_g15 - prevFrameX);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(76)
		Float _g17 = (_g16 * percent);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(76)
		Float _g18 = ((bone->data->x + prevFrameX) + _g17);		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(76)
		Float _g19 = (_g18 - bone->x);		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(76)
		Float _g20 = (_g19 * alpha);		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(76)
		hx::AddEq(bone->x,_g20);
		HX_STACK_LINE(77)
		Float _g21 = this->frames->__unsafe_get((frameIndex + (int)2));		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(77)
		Float _g22 = (_g21 - prevFrameY);		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(77)
		Float _g23 = (_g22 * percent);		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(77)
		Float _g24 = ((bone->data->y + prevFrameY) + _g23);		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(77)
		Float _g25 = (_g24 - bone->y);		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(77)
		Float _g26 = (_g25 * alpha);		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(77)
		hx::AddEq(bone->y,_g26);
	}
return null();
}


int TranslateTimeline_obj::PREV_FRAME_TIME;

int TranslateTimeline_obj::FRAME_X;

int TranslateTimeline_obj::FRAME_Y;


TranslateTimeline_obj::TranslateTimeline_obj()
{
}

void TranslateTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TranslateTimeline);
	HX_MARK_MEMBER_NAME(boneIndex,"boneIndex");
	HX_MARK_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TranslateTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(boneIndex,"boneIndex");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Visit(HX_VISIT_ARG);
}

Dynamic TranslateTimeline_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic TranslateTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void TranslateTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("boneIndex"));
	outFields->push(HX_CSTRING("frames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PREV_FRAME_TIME"),
	HX_CSTRING("FRAME_X"),
	HX_CSTRING("FRAME_Y"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(TranslateTimeline_obj,boneIndex),HX_CSTRING("boneIndex")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(TranslateTimeline_obj,frames),HX_CSTRING("frames")},
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
	HX_MARK_MEMBER_NAME(TranslateTimeline_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TranslateTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_MARK_MEMBER_NAME(TranslateTimeline_obj::FRAME_X,"FRAME_X");
	HX_MARK_MEMBER_NAME(TranslateTimeline_obj::FRAME_Y,"FRAME_Y");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TranslateTimeline_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TranslateTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_VISIT_MEMBER_NAME(TranslateTimeline_obj::FRAME_X,"FRAME_X");
	HX_VISIT_MEMBER_NAME(TranslateTimeline_obj::FRAME_Y,"FRAME_Y");
};

#endif

Class TranslateTimeline_obj::__mClass;

void TranslateTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.TranslateTimeline"), hx::TCanCast< TranslateTimeline_obj> ,sStaticFields,sMemberFields,
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

void TranslateTimeline_obj::__boot()
{
	PREV_FRAME_TIME= (int)-3;
	FRAME_X= (int)1;
	FRAME_Y= (int)2;
}

} // end namespace spinehaxe
} // end namespace animation
