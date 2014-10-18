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
#ifndef INCLUDED_spinehaxe_animation_CurveTimeline
#include <spinehaxe/animation/CurveTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void CurveTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","new",0x646d7f53,"spinehaxe.animation.CurveTimeline.new","spinehaxe/animation/CurveTimeline.hx",44,0xd5019abf)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(45)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat((frameCount * (int)6));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	this->curves = _g;
}
;
	return null();
}

//CurveTimeline_obj::~CurveTimeline_obj() { }

Dynamic CurveTimeline_obj::__CreateEmpty() { return  new CurveTimeline_obj; }
hx::ObjectPtr< CurveTimeline_obj > CurveTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< CurveTimeline_obj > result = new CurveTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic CurveTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CurveTimeline_obj > result = new CurveTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *CurveTimeline_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::animation::Timeline_obj)) return operator ::spinehaxe::animation::Timeline_obj *();
	return super::__ToInterface(inType);
}

Void CurveTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","apply",0x05551721,"spinehaxe.animation.CurveTimeline.apply","spinehaxe/animation/CurveTimeline.hx",48,0xd5019abf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(CurveTimeline_obj,apply,(void))

int CurveTimeline_obj::get_frameCount( ){
	HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","get_frameCount",0xf93d2198,"spinehaxe.animation.CurveTimeline.get_frameCount","spinehaxe/animation/CurveTimeline.hx",52,0xd5019abf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(52)
	return (Float(this->curves->length) / Float((int)6));
}


HX_DEFINE_DYNAMIC_FUNC0(CurveTimeline_obj,get_frameCount,return )

Void CurveTimeline_obj::setLinear( int frameIndex){
{
		HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","setLinear",0x58b7ae5a,"spinehaxe.animation.CurveTimeline.setLinear","spinehaxe/animation/CurveTimeline.hx",56,0xd5019abf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_LINE(56)
		this->curves->__unsafe_set((frameIndex * (int)6),(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CurveTimeline_obj,setLinear,(void))

Void CurveTimeline_obj::setStepped( int frameIndex){
{
		HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","setStepped",0xa9b98eee,"spinehaxe.animation.CurveTimeline.setStepped","spinehaxe/animation/CurveTimeline.hx",60,0xd5019abf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_LINE(60)
		this->curves->__unsafe_set((frameIndex * (int)6),(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CurveTimeline_obj,setStepped,(void))

Void CurveTimeline_obj::setCurve( int frameIndex,Float cx1,Float cy1,Float cx2,Float cy2){
{
		HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","setCurve",0xbf54f5da,"spinehaxe.animation.CurveTimeline.setCurve","spinehaxe/animation/CurveTimeline.hx",65,0xd5019abf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(cx1,"cx1")
		HX_STACK_ARG(cy1,"cy1")
		HX_STACK_ARG(cx2,"cx2")
		HX_STACK_ARG(cy2,"cy2")
		HX_STACK_LINE(66)
		Float subdiv_step = 0.1;		HX_STACK_VAR(subdiv_step,"subdiv_step");
		HX_STACK_LINE(67)
		Float subdiv_step2 = (subdiv_step * subdiv_step);		HX_STACK_VAR(subdiv_step2,"subdiv_step2");
		HX_STACK_LINE(68)
		Float subdiv_step3 = (subdiv_step2 * subdiv_step);		HX_STACK_VAR(subdiv_step3,"subdiv_step3");
		HX_STACK_LINE(69)
		Float pre1 = ((int)3 * subdiv_step);		HX_STACK_VAR(pre1,"pre1");
		HX_STACK_LINE(70)
		Float pre2 = ((int)3 * subdiv_step2);		HX_STACK_VAR(pre2,"pre2");
		HX_STACK_LINE(71)
		Float pre4 = ((int)6 * subdiv_step2);		HX_STACK_VAR(pre4,"pre4");
		HX_STACK_LINE(72)
		Float pre5 = ((int)6 * subdiv_step3);		HX_STACK_VAR(pre5,"pre5");
		HX_STACK_LINE(73)
		Float tmp1x = ((-(cx1) * (int)2) + cx2);		HX_STACK_VAR(tmp1x,"tmp1x");
		HX_STACK_LINE(74)
		Float tmp1y = ((-(cy1) * (int)2) + cy2);		HX_STACK_VAR(tmp1y,"tmp1y");
		HX_STACK_LINE(75)
		Float tmp2x = ((((cx1 - cx2)) * (int)3) + (int)1);		HX_STACK_VAR(tmp2x,"tmp2x");
		HX_STACK_LINE(76)
		Float tmp2y = ((((cy1 - cy2)) * (int)3) + (int)1);		HX_STACK_VAR(tmp2y,"tmp2y");
		HX_STACK_LINE(77)
		int i = (frameIndex * (int)6);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(78)
		this->curves->__unsafe_set(i,(((cx1 * pre1) + (tmp1x * pre2)) + (tmp2x * subdiv_step3)));
		HX_STACK_LINE(79)
		this->curves->__unsafe_set((i + (int)1),(((cy1 * pre1) + (tmp1y * pre2)) + (tmp2y * subdiv_step3)));
		HX_STACK_LINE(80)
		this->curves->__unsafe_set((i + (int)2),((tmp1x * pre4) + (tmp2x * pre5)));
		HX_STACK_LINE(81)
		this->curves->__unsafe_set((i + (int)3),((tmp1y * pre4) + (tmp2y * pre5)));
		HX_STACK_LINE(82)
		this->curves->__unsafe_set((i + (int)4),(tmp2x * pre5));
		HX_STACK_LINE(83)
		this->curves->__unsafe_set((i + (int)5),(tmp2y * pre5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(CurveTimeline_obj,setCurve,(void))

Float CurveTimeline_obj::getCurvePercent( int frameIndex,Float percent){
	HX_STACK_FRAME("spinehaxe.animation.CurveTimeline","getCurvePercent",0xd9b92eff,"spinehaxe.animation.CurveTimeline.getCurvePercent","spinehaxe/animation/CurveTimeline.hx",86,0xd5019abf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(frameIndex,"frameIndex")
	HX_STACK_ARG(percent,"percent")
	HX_STACK_LINE(87)
	int curveIndex = (frameIndex * (int)6);		HX_STACK_VAR(curveIndex,"curveIndex");
	HX_STACK_LINE(88)
	Float dfx = this->curves->__unsafe_get(curveIndex);		HX_STACK_VAR(dfx,"dfx");
	HX_STACK_LINE(89)
	if (((dfx == (int)0))){
		HX_STACK_LINE(90)
		return percent;
	}
	HX_STACK_LINE(91)
	if (((dfx == (int)-1))){
		HX_STACK_LINE(92)
		return (int)0;
	}
	HX_STACK_LINE(93)
	Float dfy = this->curves->__unsafe_get((curveIndex + (int)1));		HX_STACK_VAR(dfy,"dfy");
	HX_STACK_LINE(94)
	Float ddfx = this->curves->__unsafe_get((curveIndex + (int)2));		HX_STACK_VAR(ddfx,"ddfx");
	HX_STACK_LINE(95)
	Float ddfy = this->curves->__unsafe_get((curveIndex + (int)3));		HX_STACK_VAR(ddfy,"ddfy");
	HX_STACK_LINE(96)
	Float dddfx = this->curves->__unsafe_get((curveIndex + (int)4));		HX_STACK_VAR(dddfx,"dddfx");
	HX_STACK_LINE(97)
	Float dddfy = this->curves->__unsafe_get((curveIndex + (int)5));		HX_STACK_VAR(dddfy,"dddfy");
	HX_STACK_LINE(98)
	Float x = dfx;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(99)
	Float y = dfy;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(100)
	int i = (int)8;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(101)
	while((true)){
		HX_STACK_LINE(102)
		if (((x >= percent))){
			HX_STACK_LINE(103)
			Float prevX = (x - dfx);		HX_STACK_VAR(prevX,"prevX");
			HX_STACK_LINE(104)
			Float prevY = (y - dfy);		HX_STACK_VAR(prevY,"prevY");
			HX_STACK_LINE(105)
			return (prevY + (Float((((y - prevY)) * ((percent - prevX)))) / Float(((x - prevX)))));
		}
		HX_STACK_LINE(107)
		if (((i == (int)0))){
			HX_STACK_LINE(108)
			break;
		}
		HX_STACK_LINE(109)
		(i)--;
		HX_STACK_LINE(110)
		hx::AddEq(dfx,ddfx);
		HX_STACK_LINE(111)
		hx::AddEq(dfy,ddfy);
		HX_STACK_LINE(112)
		hx::AddEq(ddfx,dddfx);
		HX_STACK_LINE(113)
		hx::AddEq(ddfy,dddfy);
		HX_STACK_LINE(114)
		hx::AddEq(x,dfx);
		HX_STACK_LINE(115)
		hx::AddEq(y,dfy);
	}
	HX_STACK_LINE(118)
	return (y + (Float(((((int)1 - y)) * ((percent - x)))) / Float((((int)1 - x)))));
}


HX_DEFINE_DYNAMIC_FUNC2(CurveTimeline_obj,getCurvePercent,return )

Float CurveTimeline_obj::LINEAR;

Float CurveTimeline_obj::STEPPED;

int CurveTimeline_obj::BEZIER_SEGMENTS;


CurveTimeline_obj::CurveTimeline_obj()
{
}

void CurveTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CurveTimeline);
	HX_MARK_MEMBER_NAME(curves,"curves");
	HX_MARK_END_CLASS();
}

void CurveTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(curves,"curves");
}

Dynamic CurveTimeline_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"curves") ) { return curves; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setCurve") ) { return setCurve_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLinear") ) { return setLinear_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return get_frameCount(); }
		if (HX_FIELD_EQ(inName,"setStepped") ) { return setStepped_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_frameCount") ) { return get_frameCount_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getCurvePercent") ) { return getCurvePercent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CurveTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"curves") ) { curves=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CurveTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frameCount"));
	outFields->push(HX_CSTRING("curves"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("LINEAR"),
	HX_CSTRING("STEPPED"),
	HX_CSTRING("BEZIER_SEGMENTS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(CurveTimeline_obj,curves),HX_CSTRING("curves")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("curves"),
	HX_CSTRING("apply"),
	HX_CSTRING("get_frameCount"),
	HX_CSTRING("setLinear"),
	HX_CSTRING("setStepped"),
	HX_CSTRING("setCurve"),
	HX_CSTRING("getCurvePercent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CurveTimeline_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(CurveTimeline_obj::LINEAR,"LINEAR");
	HX_MARK_MEMBER_NAME(CurveTimeline_obj::STEPPED,"STEPPED");
	HX_MARK_MEMBER_NAME(CurveTimeline_obj::BEZIER_SEGMENTS,"BEZIER_SEGMENTS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CurveTimeline_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CurveTimeline_obj::LINEAR,"LINEAR");
	HX_VISIT_MEMBER_NAME(CurveTimeline_obj::STEPPED,"STEPPED");
	HX_VISIT_MEMBER_NAME(CurveTimeline_obj::BEZIER_SEGMENTS,"BEZIER_SEGMENTS");
};

#endif

Class CurveTimeline_obj::__mClass;

void CurveTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.CurveTimeline"), hx::TCanCast< CurveTimeline_obj> ,sStaticFields,sMemberFields,
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

void CurveTimeline_obj::__boot()
{
	LINEAR= (int)0;
	STEPPED= (int)-1;
	BEZIER_SEGMENTS= (int)10;
}

} // end namespace spinehaxe
} // end namespace animation
