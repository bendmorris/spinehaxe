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
#ifndef INCLUDED_spinehaxe_animation_DrawOrderTimeline
#include <spinehaxe/animation/DrawOrderTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void DrawOrderTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.DrawOrderTimeline","new",0x25cba18e,"spinehaxe.animation.DrawOrderTimeline.new","spinehaxe/animation/DrawOrderTimeline.hx",43,0xfe3fa1e4)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(44)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat(frameCount);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	this->frames = _g;
	HX_STACK_LINE(45)
	Array< ::Dynamic > _g2;		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_1{
		inline static Array< ::Dynamic > Block( int &frameCount){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/animation/DrawOrderTimeline.hx",45,0xfe3fa1e4)
			{
				HX_STACK_LINE(45)
				Array< ::Dynamic > this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(45)
				Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new()->__SetSizeExact(frameCount);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(45)
				this1 = _g1;
				HX_STACK_LINE(45)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(45)
	_g2 = _Function_1_1::Block(frameCount);
	HX_STACK_LINE(45)
	this->drawOrders = _g2;
}
;
	return null();
}

//DrawOrderTimeline_obj::~DrawOrderTimeline_obj() { }

Dynamic DrawOrderTimeline_obj::__CreateEmpty() { return  new DrawOrderTimeline_obj; }
hx::ObjectPtr< DrawOrderTimeline_obj > DrawOrderTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< DrawOrderTimeline_obj > result = new DrawOrderTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic DrawOrderTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DrawOrderTimeline_obj > result = new DrawOrderTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *DrawOrderTimeline_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::animation::Timeline_obj)) return operator ::spinehaxe::animation::Timeline_obj *();
	return super::__ToInterface(inType);
}

int DrawOrderTimeline_obj::get_frameCount( ){
	HX_STACK_FRAME("spinehaxe.animation.DrawOrderTimeline","get_frameCount",0xac4c833d,"spinehaxe.animation.DrawOrderTimeline.get_frameCount","spinehaxe/animation/DrawOrderTimeline.hx",49,0xfe3fa1e4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	return this->frames->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DrawOrderTimeline_obj,get_frameCount,return )

Void DrawOrderTimeline_obj::setFrame( int frameIndex,Float time,Array< int > drawOrder){
{
		HX_STACK_FRAME("spinehaxe.animation.DrawOrderTimeline","setFrame",0xbab5093d,"spinehaxe.animation.DrawOrderTimeline.setFrame","spinehaxe/animation/DrawOrderTimeline.hx",52,0xfe3fa1e4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(drawOrder,"drawOrder")
		HX_STACK_LINE(53)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(54)
		this->drawOrders->__unsafe_set(frameIndex,drawOrder);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DrawOrderTimeline_obj,setFrame,(void))

Void DrawOrderTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.DrawOrderTimeline","apply",0x742c7e1c,"spinehaxe.animation.DrawOrderTimeline.apply","spinehaxe/animation/DrawOrderTimeline.hx",57,0xfe3fa1e4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(58)
		Float _g = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		if (((time < _g))){
			HX_STACK_LINE(59)
			return null();
		}
		HX_STACK_LINE(61)
		int frameIndex;		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(62)
		Float _g1 = this->frames->__unsafe_get((this->frames->length - (int)1));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		if (((time >= _g1))){
			HX_STACK_LINE(64)
			frameIndex = (this->frames->length - (int)1);
		}
		else{
			HX_STACK_LINE(65)
			int _g2 = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,time,(int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(65)
			int _g3 = (_g2 - (int)1);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(65)
			frameIndex = _g3;
		}
		HX_STACK_LINE(66)
		Array< ::Dynamic > drawOrder = skeleton->drawOrder;		HX_STACK_VAR(drawOrder,"drawOrder");
		HX_STACK_LINE(67)
		Array< ::Dynamic > slots = skeleton->slots;		HX_STACK_VAR(slots,"slots");
		HX_STACK_LINE(68)
		Array< int > drawOrderToSetupIndex = this->drawOrders->__unsafe_get(frameIndex);		HX_STACK_VAR(drawOrderToSetupIndex,"drawOrderToSetupIndex");
		HX_STACK_LINE(69)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(70)
		if (((drawOrderToSetupIndex == null()))){
			HX_STACK_LINE(71)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(71)
			Array< ::Dynamic > _g11 = skeleton->slots;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(71)
			while((true)){
				HX_STACK_LINE(71)
				if ((!(((_g2 < _g11->length))))){
					HX_STACK_LINE(71)
					break;
				}
				HX_STACK_LINE(71)
				::spinehaxe::Slot slot = _g11->__get(_g2).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
				HX_STACK_LINE(71)
				++(_g2);
				HX_STACK_LINE(72)
				int _g4 = (i)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(72)
				drawOrder[_g4] = slot;
			}
		}
		else{
			HX_STACK_LINE(76)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(76)
			while((true)){
				HX_STACK_LINE(76)
				if ((!(((_g2 < drawOrderToSetupIndex->length))))){
					HX_STACK_LINE(76)
					break;
				}
				HX_STACK_LINE(76)
				Dynamic setupIndex = drawOrderToSetupIndex->__unsafe_get(_g2);		HX_STACK_VAR(setupIndex,"setupIndex");
				HX_STACK_LINE(76)
				++(_g2);
				HX_STACK_LINE(77)
				int _g5 = (i)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(77)
				drawOrder[_g5] = skeleton->slots->__get(setupIndex).StaticCast< ::spinehaxe::Slot >();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(DrawOrderTimeline_obj,apply,(void))


DrawOrderTimeline_obj::DrawOrderTimeline_obj()
{
}

void DrawOrderTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DrawOrderTimeline);
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(drawOrders,"drawOrders");
	HX_MARK_END_CLASS();
}

void DrawOrderTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(drawOrders,"drawOrders");
}

Dynamic DrawOrderTimeline_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return get_frameCount(); }
		if (HX_FIELD_EQ(inName,"drawOrders") ) { return drawOrders; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_frameCount") ) { return get_frameCount_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DrawOrderTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawOrders") ) { drawOrders=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DrawOrderTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frameCount"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("drawOrders"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(DrawOrderTimeline_obj,frames),HX_CSTRING("frames")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DrawOrderTimeline_obj,drawOrders),HX_CSTRING("drawOrders")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("frames"),
	HX_CSTRING("drawOrders"),
	HX_CSTRING("get_frameCount"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DrawOrderTimeline_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DrawOrderTimeline_obj::__mClass,"__mClass");
};

#endif

Class DrawOrderTimeline_obj::__mClass;

void DrawOrderTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.DrawOrderTimeline"), hx::TCanCast< DrawOrderTimeline_obj> ,sStaticFields,sMemberFields,
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

void DrawOrderTimeline_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
