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
#ifndef INCLUDED_spinehaxe_animation_AttachmentTimeline
#include <spinehaxe/animation/AttachmentTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
namespace spinehaxe{
namespace animation{

Void AttachmentTimeline_obj::__construct(int frameCount)
{
HX_STACK_FRAME("spinehaxe.animation.AttachmentTimeline","new",0x78abeac5,"spinehaxe.animation.AttachmentTimeline.new","spinehaxe/animation/AttachmentTimeline.hx",43,0x910935c9)
HX_STACK_THIS(this)
HX_STACK_ARG(frameCount,"frameCount")
{
	HX_STACK_LINE(44)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat(frameCount);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	this->frames = _g;
	HX_STACK_LINE(45)
	Array< ::String > _g2;		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_1{
		inline static Array< ::String > Block( int &frameCount){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/animation/AttachmentTimeline.hx",45,0x910935c9)
			{
				HX_STACK_LINE(45)
				Array< ::String > this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(45)
				Array< ::String > _g1 = Array_obj< ::String >::__new()->__SetSizeExact(frameCount);		HX_STACK_VAR(_g1,"_g1");
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
	this->attachmentNames = _g2;
}
;
	return null();
}

//AttachmentTimeline_obj::~AttachmentTimeline_obj() { }

Dynamic AttachmentTimeline_obj::__CreateEmpty() { return  new AttachmentTimeline_obj; }
hx::ObjectPtr< AttachmentTimeline_obj > AttachmentTimeline_obj::__new(int frameCount)
{  hx::ObjectPtr< AttachmentTimeline_obj > result = new AttachmentTimeline_obj();
	result->__construct(frameCount);
	return result;}

Dynamic AttachmentTimeline_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AttachmentTimeline_obj > result = new AttachmentTimeline_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *AttachmentTimeline_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::animation::Timeline_obj)) return operator ::spinehaxe::animation::Timeline_obj *();
	return super::__ToInterface(inType);
}

int AttachmentTimeline_obj::get_frameCount( ){
	HX_STACK_FRAME("spinehaxe.animation.AttachmentTimeline","get_frameCount",0x3bcf6766,"spinehaxe.animation.AttachmentTimeline.get_frameCount","spinehaxe/animation/AttachmentTimeline.hx",49,0x910935c9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	return this->frames->length;
}


HX_DEFINE_DYNAMIC_FUNC0(AttachmentTimeline_obj,get_frameCount,return )

Void AttachmentTimeline_obj::setFrame( int frameIndex,Float time,::String attachmentName){
{
		HX_STACK_FRAME("spinehaxe.animation.AttachmentTimeline","setFrame",0x06ccf8a6,"spinehaxe.animation.AttachmentTimeline.setFrame","spinehaxe/animation/AttachmentTimeline.hx",52,0x910935c9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(time,"time")
		HX_STACK_ARG(attachmentName,"attachmentName")
		HX_STACK_LINE(53)
		this->frames->__unsafe_set(frameIndex,time);
		HX_STACK_LINE(54)
		this->attachmentNames->__unsafe_set(frameIndex,attachmentName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AttachmentTimeline_obj,setFrame,(void))

Void AttachmentTimeline_obj::apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha){
{
		HX_STACK_FRAME("spinehaxe.animation.AttachmentTimeline","apply",0x769ac313,"spinehaxe.animation.AttachmentTimeline.apply","spinehaxe/animation/AttachmentTimeline.hx",57,0x910935c9)
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
		::String attachmentName = this->attachmentNames->__unsafe_get(frameIndex);		HX_STACK_VAR(attachmentName,"attachmentName");
		HX_STACK_LINE(67)
		::spinehaxe::attachments::Attachment _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(67)
		if (((attachmentName == null()))){
			HX_STACK_LINE(67)
			_g4 = null();
		}
		else{
			HX_STACK_LINE(67)
			_g4 = skeleton->getAttachmentForSlotIndex(this->slotIndex,attachmentName);
		}
		HX_STACK_LINE(67)
		skeleton->slots->__get(this->slotIndex).StaticCast< ::spinehaxe::Slot >()->set_attachment(_g4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AttachmentTimeline_obj,apply,(void))


AttachmentTimeline_obj::AttachmentTimeline_obj()
{
}

void AttachmentTimeline_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AttachmentTimeline);
	HX_MARK_MEMBER_NAME(slotIndex,"slotIndex");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(attachmentNames,"attachmentNames");
	HX_MARK_END_CLASS();
}

void AttachmentTimeline_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(slotIndex,"slotIndex");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(attachmentNames,"attachmentNames");
}

Dynamic AttachmentTimeline_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return get_frameCount(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_frameCount") ) { return get_frameCount_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"attachmentNames") ) { return attachmentNames; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AttachmentTimeline_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"slotIndex") ) { slotIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"attachmentNames") ) { attachmentNames=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AttachmentTimeline_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frameCount"));
	outFields->push(HX_CSTRING("slotIndex"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("attachmentNames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(AttachmentTimeline_obj,slotIndex),HX_CSTRING("slotIndex")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(AttachmentTimeline_obj,frames),HX_CSTRING("frames")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(AttachmentTimeline_obj,attachmentNames),HX_CSTRING("attachmentNames")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("slotIndex"),
	HX_CSTRING("frames"),
	HX_CSTRING("attachmentNames"),
	HX_CSTRING("get_frameCount"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AttachmentTimeline_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttachmentTimeline_obj::__mClass,"__mClass");
};

#endif

Class AttachmentTimeline_obj::__mClass;

void AttachmentTimeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.AttachmentTimeline"), hx::TCanCast< AttachmentTimeline_obj> ,sStaticFields,sMemberFields,
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

void AttachmentTimeline_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
