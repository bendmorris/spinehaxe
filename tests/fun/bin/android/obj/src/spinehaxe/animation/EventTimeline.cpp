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
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_EventTimeline
#include <spinehaxe/animation/EventTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

Void EventTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.EventTimeline","new",0xa19aef3e,"spinehaxe.animation.EventTimeline.new","spinehaxe/animation/EventTimeline.hx",43,0xc1c3d134)
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
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/animation/EventTimeline.hx",45,0xc1c3d134)
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
	this->events = _g2;
}
;
	return null();
}

//EventTimeline_obj::~EventTimeline_obj() { }

Dynamic EventTimeline_obj::__CreateEmpty() { return  new EventTimeline_obj; }
hx::ObjectPtr< EventTimeline_obj > EventTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< EventTimeline_obj > result = new EventTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic EventTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventTimeline_obj > result = new EventTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *EventTimeline_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::animation::Timeline_obj)) return operator ::spinehaxe::animation::Timeline_obj *();
	return super::__ToInterface(inType);
}

int EventTimeline_obj::get_frameCount( ){
	HX_STACK_FRAME("spinehaxe.animation.EventTimeline","get_frameCount",0x7c71b38d,"spinehaxe.animation.EventTimeline.get_frameCount","spinehaxe/animation/EventTimeline.hx",49,0xc1c3d134)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	return this->frames->length;
}


HX_DEFINE_DYNAMIC_FUNC0(EventTimeline_obj,get_frameCount,return )

Void EventTimeline_obj::setFrame( int frameIndex,Float time,::spinehaxe::Event event){
{
		HX_STACK_FRAME("spinehaxe.animation.EventTimeline","setFrame",0xea1e1d8d,"spinehaxe.animation.EventTimeline.setFrame","spinehaxe/animation/EventTimeline.hx",53,0xc1c3d134)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(54)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(55)
		this->events->__unsafe_set(frameIndex,event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventTimeline_obj,setFrame,(void))

Void EventTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.EventTimeline","apply",0xfcae97cc,"spinehaxe.animation.EventTimeline.apply","spinehaxe/animation/EventTimeline.hx",59,0xc1c3d134)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(lastTime,"lastTime")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(firedEvents,"firedEvents")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(60)
		if (((firedEvents == null()))){
			HX_STACK_LINE(61)
			return null();
		}
		HX_STACK_LINE(62)
		if (((lastTime > time))){
			HX_STACK_LINE(64)
			this->apply(skeleton,lastTime,(int)32767,firedEvents,alpha);
			HX_STACK_LINE(65)
			lastTime = (int)-1;
		}
		else{
			HX_STACK_LINE(68)
			Dynamic _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(68)
			{
				HX_STACK_LINE(68)
				int _g = this->get_frameCount();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(68)
				int index = (_g - (int)1);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(68)
				_g1 = this->frames->__unsafe_get(index);
			}
			HX_STACK_LINE(68)
			if (((lastTime >= _g1))){
				HX_STACK_LINE(70)
				return null();
			}
		}
		HX_STACK_LINE(71)
		Float _g2 = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(71)
		if (((time < _g2))){
			HX_STACK_LINE(72)
			return null();
		}
		HX_STACK_LINE(74)
		int frameIndex;		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(75)
		Float _g3 = this->frames->__unsafe_get((int)0);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(75)
		if (((lastTime < _g3))){
			HX_STACK_LINE(76)
			frameIndex = (int)0;
		}
		else{
			HX_STACK_LINE(78)
			int _g4 = ::spinehaxe::animation::Animation_obj::binarySearch(this->frames,lastTime,(int)1);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(78)
			frameIndex = _g4;
			HX_STACK_LINE(79)
			Float frame = this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(frame,"frame");
			HX_STACK_LINE(80)
			while((true)){
				HX_STACK_LINE(80)
				if ((!(((frameIndex > (int)0))))){
					HX_STACK_LINE(80)
					break;
				}
				HX_STACK_LINE(82)
				Float _g5 = this->frames->__unsafe_get((frameIndex - (int)1));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(82)
				if (((_g5 != frame))){
					HX_STACK_LINE(83)
					break;
				}
				HX_STACK_LINE(84)
				(frameIndex)--;
			}
		}
		HX_STACK_LINE(89)
		while((true)){
			HX_STACK_LINE(89)
			int _g6 = this->get_frameCount();		HX_STACK_VAR(_g6,"_g6");
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::spinehaxe::animation::EventTimeline_obj > __this,Float &time,int &frameIndex){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/animation/EventTimeline.hx",89,0xc1c3d134)
					{
						HX_STACK_LINE(89)
						Float _g7 = __this->frames->__unsafe_get(frameIndex);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(89)
						return (time >= _g7);
					}
					return null();
				}
			};
			HX_STACK_LINE(89)
			if ((!(((  (((frameIndex < _g6))) ? bool(_Function_2_1::Block(this,time,frameIndex)) : bool(false) ))))){
				HX_STACK_LINE(89)
				break;
			}
			HX_STACK_LINE(90)
			::spinehaxe::Event _g8 = this->events->__unsafe_get(frameIndex);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(90)
			firedEvents->push(_g8);
			HX_STACK_LINE(91)
			(frameIndex)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(EventTimeline_obj,apply,(void))


EventTimeline_obj::EventTimeline_obj()
{
}

void EventTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventTimeline);
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(events,"events");
	HX_MARK_END_CLASS();
}

void EventTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(events,"events");
}

Dynamic EventTimeline_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"events") ) { return events; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setFrame") ) { return setFrame_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return get_frameCount(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_frameCount") ) { return get_frameCount_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"events") ) { events=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frameCount"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("events"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(EventTimeline_obj,frames),HX_CSTRING("frames")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(EventTimeline_obj,events),HX_CSTRING("events")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("frames"),
	HX_CSTRING("events"),
	HX_CSTRING("get_frameCount"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventTimeline_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventTimeline_obj::__mClass,"__mClass");
};

#endif

Class EventTimeline_obj::__mClass;

void EventTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.EventTimeline"), hx::TCanCast< EventTimeline_obj> ,sStaticFields,sMemberFields,
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

void EventTimeline_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
