#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_ColorTimeline
#include <spinehaxe/animation/ColorTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_CurveTimeline
#include <spinehaxe/animation/CurveTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void ColorTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.ColorTimeline","new",0x736fe207,"spinehaxe.animation.ColorTimeline.new","spinehaxe/animation/ColorTimeline.hx",47,0x35810a8b)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(48)
	super::__construct(frameCount);
	HX_STACK_LINE(49)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat((frameCount * (int)5));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	this->frames = _g;
}
;
	return null();
}

//ColorTimeline_obj::~ColorTimeline_obj() { }

Dynamic ColorTimeline_obj::__CreateEmpty() { return  new ColorTimeline_obj; }
hx::ObjectPtr< ColorTimeline_obj > ColorTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< ColorTimeline_obj > result = new ColorTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic ColorTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorTimeline_obj > result = new ColorTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ColorTimeline_obj::setFrame( int frameIndex,Float time,Float r,Float g,Float b,Float a){
{
		HX_STACK_FRAME("spinehaxe.animation.ColorTimeline","setFrame",0xb2d77224,"spinehaxe.animation.ColorTimeline.setFrame","spinehaxe/animation/ColorTimeline.hx",53,0x35810a8b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(g,"g")
		HX_STACK_ARG(b,"b")
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(54)
		hx::MultEq(frameIndex,(int)5);
		HX_STACK_LINE(55)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(56)
		this->frames->__unsafe_set((frameIndex + (int)1),r);
		HX_STACK_LINE(57)
		this->frames->__unsafe_set((frameIndex + (int)2),g);
		HX_STACK_LINE(58)
		this->frames->__unsafe_set((frameIndex + (int)3),b);
		HX_STACK_LINE(59)
		this->frames->__unsafe_set((frameIndex + (int)4),a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(ColorTimeline_obj,setFrame,(void))

Void ColorTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.ColorTimeline","apply",0xa3bc8ed5,"spinehaxe.animation.ColorTimeline.apply","spinehaxe/animation/ColorTimeline.hx",62,0x35810a8b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(63)
		Float _g = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(63)
		if (((time < _g))){
			HX_STACK_LINE(64)
			return null();
		}
		HX_STACK_LINE(66)
		Float r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(66)
		Float g;		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(66)
		Float b;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(66)
		Float a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(67)
		Float _g1 = this->frames->__unsafe_get((this->frames->length - (int)5));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		if (((time >= _g1))){
			HX_STACK_LINE(69)
			int i = (this->frames->length - (int)1);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(70)
			Float _g2 = this->frames->__unsafe_get((i - (int)3));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(70)
			r = _g2;
			HX_STACK_LINE(71)
			Float _g3 = this->frames->__unsafe_get((i - (int)2));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(71)
			g = _g3;
			HX_STACK_LINE(72)
			Float _g4 = this->frames->__unsafe_get((i - (int)1));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(72)
			b = _g4;
			HX_STACK_LINE(73)
			Float _g5 = this->frames->__unsafe_get(i);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(73)
			a = _g5;
		}
		else{
			HX_STACK_LINE(76)
			int frameIndex = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,time,(int)5);		HX_STACK_VAR(frameIndex,"frameIndex");
			HX_STACK_LINE(77)
			Float prevFrameR = this->frames->__unsafe_get((frameIndex - (int)4));		HX_STACK_VAR(prevFrameR,"prevFrameR");
			HX_STACK_LINE(78)
			Float prevFrameG = this->frames->__unsafe_get((frameIndex - (int)3));		HX_STACK_VAR(prevFrameG,"prevFrameG");
			HX_STACK_LINE(79)
			Float prevFrameB = this->frames->__unsafe_get((frameIndex - (int)2));		HX_STACK_VAR(prevFrameB,"prevFrameB");
			HX_STACK_LINE(80)
			Float prevFrameA = this->frames->__unsafe_get((frameIndex - (int)1));		HX_STACK_VAR(prevFrameA,"prevFrameA");
			HX_STACK_LINE(81)
			Float frameTime = this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(frameTime,"frameTime");
			HX_STACK_LINE(82)
			Float _g6 = this->frames->__unsafe_get((frameIndex + (int)-5));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(82)
			Float _g7 = (_g6 - frameTime);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(82)
			Float _g8 = (Float(((time - frameTime))) / Float(_g7));		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(82)
			Float percent = ((int)1 - _g8);		HX_STACK_VAR(percent,"percent");
			HX_STACK_LINE(83)
			Float _g9 = this->frames->__unsafe_get((frameIndex + (int)1));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(83)
			Float _g10 = (_g9 - prevFrameR);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(83)
			Float _g11 = (_g10 * percent);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(83)
			Float _g12 = (prevFrameR + _g11);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(83)
			r = _g12;
			HX_STACK_LINE(84)
			Float _g13 = this->frames->__unsafe_get((frameIndex + (int)2));		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(84)
			Float _g14 = (_g13 - prevFrameG);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(84)
			Float _g15 = (_g14 * percent);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(84)
			Float _g16 = (prevFrameG + _g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(84)
			g = _g16;
			HX_STACK_LINE(85)
			Float _g17 = this->frames->__unsafe_get((frameIndex + (int)3));		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(85)
			Float _g18 = (_g17 - prevFrameB);		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(85)
			Float _g19 = (_g18 * percent);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(85)
			Float _g20 = (prevFrameB + _g19);		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(85)
			b = _g20;
			HX_STACK_LINE(86)
			Float _g21 = this->frames->__unsafe_get((frameIndex + (int)4));		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(86)
			Float _g22 = (_g21 - prevFrameA);		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(86)
			Float _g23 = (_g22 * percent);		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(86)
			Float _g24 = (prevFrameA + _g23);		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(86)
			a = _g24;
		}
		HX_STACK_LINE(88)
		::spinehaxe::Slot slot = skeleton->slots->__get(this->slotIndex).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
		HX_STACK_LINE(89)
		if (((alpha < (int)1))){
			HX_STACK_LINE(90)
			hx::AddEq(slot->r,(((r - slot->r)) * alpha));
			HX_STACK_LINE(91)
			hx::AddEq(slot->g,(((g - slot->g)) * alpha));
			HX_STACK_LINE(92)
			hx::AddEq(slot->b,(((b - slot->b)) * alpha));
			HX_STACK_LINE(93)
			hx::AddEq(slot->a,(((a - slot->a)) * alpha));
		}
		else{
			HX_STACK_LINE(95)
			slot->r = r;
			HX_STACK_LINE(96)
			slot->g = g;
			HX_STACK_LINE(97)
			slot->b = b;
			HX_STACK_LINE(98)
			slot->a = a;
		}
	}
return null();
}


int ColorTimeline_obj::PREV_FRAME_TIME;

int ColorTimeline_obj::FRAME_R;

int ColorTimeline_obj::FRAME_G;

int ColorTimeline_obj::FRAME_B;

int ColorTimeline_obj::FRAME_A;


ColorTimeline_obj::ColorTimeline_obj()
{
}

void ColorTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColorTimeline);
	HX_MARK_MEMBER_NAME(slotIndex,"slotIndex");
	HX_MARK_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ColorTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(slotIndex,"slotIndex");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	::spinehaxe::animation::CurveTimeline_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ColorTimeline_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"slotIndex") ) { return slotIndex; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColorTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"slotIndex") ) { slotIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColorTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("slotIndex"));
	outFields->push(HX_CSTRING("frames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PREV_FRAME_TIME"),
	HX_CSTRING("FRAME_R"),
	HX_CSTRING("FRAME_G"),
	HX_CSTRING("FRAME_B"),
	HX_CSTRING("FRAME_A"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(ColorTimeline_obj,slotIndex),HX_CSTRING("slotIndex")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ColorTimeline_obj,frames),HX_CSTRING("frames")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("slotIndex"),
	HX_CSTRING("frames"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::FRAME_R,"FRAME_R");
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::FRAME_G,"FRAME_G");
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::FRAME_B,"FRAME_B");
	HX_MARK_MEMBER_NAME(ColorTimeline_obj::FRAME_A,"FRAME_A");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::PREV_FRAME_TIME,"PREV_FRAME_TIME");
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::FRAME_R,"FRAME_R");
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::FRAME_G,"FRAME_G");
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::FRAME_B,"FRAME_B");
	HX_VISIT_MEMBER_NAME(ColorTimeline_obj::FRAME_A,"FRAME_A");
};

#endif

Class ColorTimeline_obj::__mClass;

void ColorTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.ColorTimeline"), hx::TCanCast< ColorTimeline_obj> ,sStaticFields,sMemberFields,
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

void ColorTimeline_obj::__boot()
{
	PREV_FRAME_TIME= (int)-5;
	FRAME_R= (int)1;
	FRAME_G= (int)2;
	FRAME_B= (int)3;
	FRAME_A= (int)4;
}

} // end namespace spinehaxe
} // end namespace animation
