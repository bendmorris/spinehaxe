#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_EventData
#include <spinehaxe/EventData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_Skin
#include <spinehaxe/Skin.h>
#endif
#ifndef INCLUDED_spinehaxe_SlotData
#include <spinehaxe/SlotData.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
namespace spinehaxe{

Void SkeletonData_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.SkeletonData","new",0xe7078b2e,"spinehaxe.SkeletonData.new","spinehaxe/SkeletonData.hx",185,0x1e529d21)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(186)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(186)
	this->bones = _g;
	HX_STACK_LINE(187)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(187)
	this->slots = _g1;
	HX_STACK_LINE(188)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(188)
	this->skins = _g2;
	HX_STACK_LINE(189)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(189)
	this->events = _g3;
	HX_STACK_LINE(190)
	Array< ::Dynamic > _g4 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(190)
	this->animations = _g4;
}
;
	return null();
}

//SkeletonData_obj::~SkeletonData_obj() { }

Dynamic SkeletonData_obj::__CreateEmpty() { return  new SkeletonData_obj; }
hx::ObjectPtr< SkeletonData_obj > SkeletonData_obj::__new()
{  hx::ObjectPtr< SkeletonData_obj > result = new SkeletonData_obj();
	result->__construct();
	return result;}

Dynamic SkeletonData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkeletonData_obj > result = new SkeletonData_obj();
	result->__construct();
	return result;}

Void SkeletonData_obj::addBone( ::spinehaxe::BoneData bone){
{
		HX_STACK_FRAME("spinehaxe.SkeletonData","addBone",0x5dfcffd3,"spinehaxe.SkeletonData.addBone","spinehaxe/SkeletonData.hx",47,0x1e529d21)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bone,"bone")
		HX_STACK_LINE(48)
		if (((bone == null()))){
			HX_STACK_LINE(49)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("bone cannot be null.")));
		}
		HX_STACK_LINE(50)
		this->bones[this->bones->length] = bone;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,addBone,(void))

::spinehaxe::BoneData SkeletonData_obj::findBone( ::String boneName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findBone",0x42bdea8f,"spinehaxe.SkeletonData.findBone","spinehaxe/SkeletonData.hx",54,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(boneName,"boneName")
	HX_STACK_LINE(55)
	if (((boneName == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("boneName cannot be null.")));
	}
	HX_STACK_LINE(57)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(58)
	int n = this->bones->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(59)
	while((true)){
		HX_STACK_LINE(59)
		if ((!(((i < n))))){
			HX_STACK_LINE(59)
			break;
		}
		HX_STACK_LINE(60)
		::spinehaxe::BoneData bone = this->bones->__get(i).StaticCast< ::spinehaxe::BoneData >();		HX_STACK_VAR(bone,"bone");
		HX_STACK_LINE(61)
		if (((bone->name == boneName))){
			HX_STACK_LINE(62)
			return bone;
		}
		HX_STACK_LINE(63)
		(i)++;
	}
	HX_STACK_LINE(65)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findBone,return )

int SkeletonData_obj::findBoneIndex( ::String boneName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findBoneIndex",0xb0dc7a03,"spinehaxe.SkeletonData.findBoneIndex","spinehaxe/SkeletonData.hx",69,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(boneName,"boneName")
	HX_STACK_LINE(70)
	if (((boneName == null()))){
		HX_STACK_LINE(71)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("boneName cannot be null.")));
	}
	HX_STACK_LINE(72)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(73)
	int n = this->bones->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(74)
	while((true)){
		HX_STACK_LINE(74)
		if ((!(((i < n))))){
			HX_STACK_LINE(74)
			break;
		}
		HX_STACK_LINE(75)
		if (((this->bones->__get(i).StaticCast< ::spinehaxe::BoneData >()->name == boneName))){
			HX_STACK_LINE(76)
			return i;
		}
		HX_STACK_LINE(77)
		(i)++;
	}
	HX_STACK_LINE(79)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findBoneIndex,return )

Void SkeletonData_obj::addSlot( ::spinehaxe::SlotData slot){
{
		HX_STACK_FRAME("spinehaxe.SkeletonData","addSlot",0x69375a8d,"spinehaxe.SkeletonData.addSlot","spinehaxe/SkeletonData.hx",83,0x1e529d21)
		HX_STACK_THIS(this)
		HX_STACK_ARG(slot,"slot")
		HX_STACK_LINE(84)
		if (((slot == null()))){
			HX_STACK_LINE(85)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slot cannot be null.")));
		}
		HX_STACK_LINE(86)
		this->slots[this->slots->length] = slot;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,addSlot,(void))

::spinehaxe::SlotData SkeletonData_obj::findSlot( ::String slotName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findSlot",0x4df84549,"spinehaxe.SkeletonData.findSlot","spinehaxe/SkeletonData.hx",90,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotName,"slotName")
	HX_STACK_LINE(91)
	if (((slotName == null()))){
		HX_STACK_LINE(92)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slotName cannot be null.")));
	}
	HX_STACK_LINE(93)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(94)
	int n = this->slots->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(95)
	while((true)){
		HX_STACK_LINE(95)
		if ((!(((i < n))))){
			HX_STACK_LINE(95)
			break;
		}
		HX_STACK_LINE(96)
		::spinehaxe::SlotData slot = this->slots->__get(i).StaticCast< ::spinehaxe::SlotData >();		HX_STACK_VAR(slot,"slot");
		HX_STACK_LINE(97)
		if (((slot->name == slotName))){
			HX_STACK_LINE(98)
			return slot;
		}
		HX_STACK_LINE(99)
		(i)++;
	}
	HX_STACK_LINE(101)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findSlot,return )

int SkeletonData_obj::findSlotIndex( ::String slotName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findSlotIndex",0x303cfd09,"spinehaxe.SkeletonData.findSlotIndex","spinehaxe/SkeletonData.hx",105,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotName,"slotName")
	HX_STACK_LINE(106)
	if (((slotName == null()))){
		HX_STACK_LINE(107)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slotName cannot be null.")));
	}
	HX_STACK_LINE(108)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(109)
	int n = this->slots->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(110)
	while((true)){
		HX_STACK_LINE(110)
		if ((!(((i < n))))){
			HX_STACK_LINE(110)
			break;
		}
		HX_STACK_LINE(111)
		if (((this->slots->__get(i).StaticCast< ::spinehaxe::SlotData >()->name == slotName))){
			HX_STACK_LINE(112)
			return i;
		}
		HX_STACK_LINE(113)
		(i)++;
	}
	HX_STACK_LINE(115)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findSlotIndex,return )

Void SkeletonData_obj::addSkin( ::spinehaxe::Skin skin){
{
		HX_STACK_FRAME("spinehaxe.SkeletonData","addSkin",0x6936930c,"spinehaxe.SkeletonData.addSkin","spinehaxe/SkeletonData.hx",119,0x1e529d21)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skin,"skin")
		HX_STACK_LINE(120)
		if (((skin == null()))){
			HX_STACK_LINE(121)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("skin cannot be null.")));
		}
		HX_STACK_LINE(122)
		this->skins[this->skins->length] = skin;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,addSkin,(void))

::spinehaxe::Skin SkeletonData_obj::findSkin( ::String skinName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findSkin",0x4df77dc8,"spinehaxe.SkeletonData.findSkin","spinehaxe/SkeletonData.hx",126,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(skinName,"skinName")
	HX_STACK_LINE(127)
	if (((skinName == null()))){
		HX_STACK_LINE(128)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("skinName cannot be null.")));
	}
	HX_STACK_LINE(129)
	{
		HX_STACK_LINE(129)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(129)
		Array< ::Dynamic > _g1 = this->skins;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(129)
		while((true)){
			HX_STACK_LINE(129)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(129)
				break;
			}
			HX_STACK_LINE(129)
			::spinehaxe::Skin skin = _g1->__get(_g).StaticCast< ::spinehaxe::Skin >();		HX_STACK_VAR(skin,"skin");
			HX_STACK_LINE(129)
			++(_g);
			HX_STACK_LINE(130)
			if (((skin->name == skinName))){
				HX_STACK_LINE(131)
				return skin;
			}
		}
	}
	HX_STACK_LINE(132)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findSkin,return )

Void SkeletonData_obj::addEvent( ::spinehaxe::EventData eventData){
{
		HX_STACK_FRAME("spinehaxe.SkeletonData","addEvent",0x9e3048ab,"spinehaxe.SkeletonData.addEvent","spinehaxe/SkeletonData.hx",136,0x1e529d21)
		HX_STACK_THIS(this)
		HX_STACK_ARG(eventData,"eventData")
		HX_STACK_LINE(137)
		if (((eventData == null()))){
			HX_STACK_LINE(138)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("eventData cannot be null.")));
		}
		HX_STACK_LINE(139)
		this->events[this->events->length] = eventData;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,addEvent,(void))

::spinehaxe::EventData SkeletonData_obj::findEvent( ::String eventName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findEvent",0xe23cc26f,"spinehaxe.SkeletonData.findEvent","spinehaxe/SkeletonData.hx",143,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(eventName,"eventName")
	HX_STACK_LINE(144)
	if (((eventName == null()))){
		HX_STACK_LINE(145)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("eventName cannot be null.")));
	}
	HX_STACK_LINE(146)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(147)
	int n = this->events->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(148)
	while((true)){
		HX_STACK_LINE(148)
		if ((!(((i < n))))){
			HX_STACK_LINE(148)
			break;
		}
		HX_STACK_LINE(149)
		::spinehaxe::EventData eventData = this->events->__get(i).StaticCast< ::spinehaxe::EventData >();		HX_STACK_VAR(eventData,"eventData");
		HX_STACK_LINE(150)
		if (((eventData->name == eventName))){
			HX_STACK_LINE(151)
			return eventData;
		}
		HX_STACK_LINE(152)
		(i)++;
	}
	HX_STACK_LINE(154)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findEvent,return )

Void SkeletonData_obj::addAnimation( ::spinehaxe::animation::Animation animation){
{
		HX_STACK_FRAME("spinehaxe.SkeletonData","addAnimation",0x4c7a8c15,"spinehaxe.SkeletonData.addAnimation","spinehaxe/SkeletonData.hx",158,0x1e529d21)
		HX_STACK_THIS(this)
		HX_STACK_ARG(animation,"animation")
		HX_STACK_LINE(159)
		if (((animation == null()))){
			HX_STACK_LINE(160)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("animation cannot be null.")));
		}
		HX_STACK_LINE(161)
		this->animations[this->animations->length] = animation;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,addAnimation,(void))

::spinehaxe::animation::Animation SkeletonData_obj::findAnimation( ::String animationName){
	HX_STACK_FRAME("spinehaxe.SkeletonData","findAnimation",0xdd4137d9,"spinehaxe.SkeletonData.findAnimation","spinehaxe/SkeletonData.hx",165,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_ARG(animationName,"animationName")
	HX_STACK_LINE(166)
	if (((animationName == null()))){
		HX_STACK_LINE(167)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("animationName cannot be null.")));
	}
	HX_STACK_LINE(168)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(169)
	int n = this->animations->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(170)
	while((true)){
		HX_STACK_LINE(170)
		if ((!(((i < n))))){
			HX_STACK_LINE(170)
			break;
		}
		HX_STACK_LINE(171)
		::spinehaxe::animation::Animation animation = this->animations->__get(i).StaticCast< ::spinehaxe::animation::Animation >();		HX_STACK_VAR(animation,"animation");
		HX_STACK_LINE(172)
		if (((animation->name == animationName))){
			HX_STACK_LINE(173)
			return animation;
		}
		HX_STACK_LINE(174)
		(i)++;
	}
	HX_STACK_LINE(176)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,findAnimation,return )

::String SkeletonData_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.SkeletonData","toString",0xe77d2b1e,"spinehaxe.SkeletonData.toString","spinehaxe/SkeletonData.hx",181,0x1e529d21)
	HX_STACK_THIS(this)
	HX_STACK_LINE(181)
	if (((this->name != null()))){
		HX_STACK_LINE(181)
		return this->name;
	}
	else{
		HX_STACK_LINE(181)
		::String _g = ::Std_obj::string(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(181)
		return (HX_CSTRING("") + _g);
	}
	HX_STACK_LINE(181)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonData_obj,toString,return )


SkeletonData_obj::SkeletonData_obj()
{
}

void SkeletonData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkeletonData);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(bones,"bones");
	HX_MARK_MEMBER_NAME(slots,"slots");
	HX_MARK_MEMBER_NAME(skins,"skins");
	HX_MARK_MEMBER_NAME(defaultSkin,"defaultSkin");
	HX_MARK_MEMBER_NAME(events,"events");
	HX_MARK_MEMBER_NAME(animations,"animations");
	HX_MARK_END_CLASS();
}

void SkeletonData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(bones,"bones");
	HX_VISIT_MEMBER_NAME(slots,"slots");
	HX_VISIT_MEMBER_NAME(skins,"skins");
	HX_VISIT_MEMBER_NAME(defaultSkin,"defaultSkin");
	HX_VISIT_MEMBER_NAME(events,"events");
	HX_VISIT_MEMBER_NAME(animations,"animations");
}

Dynamic SkeletonData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { return bones; }
		if (HX_FIELD_EQ(inName,"slots") ) { return slots; }
		if (HX_FIELD_EQ(inName,"skins") ) { return skins; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { return events; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addBone") ) { return addBone_dyn(); }
		if (HX_FIELD_EQ(inName,"addSlot") ) { return addSlot_dyn(); }
		if (HX_FIELD_EQ(inName,"addSkin") ) { return addSkin_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"findBone") ) { return findBone_dyn(); }
		if (HX_FIELD_EQ(inName,"findSlot") ) { return findSlot_dyn(); }
		if (HX_FIELD_EQ(inName,"findSkin") ) { return findSkin_dyn(); }
		if (HX_FIELD_EQ(inName,"addEvent") ) { return addEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"findEvent") ) { return findEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"animations") ) { return animations; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultSkin") ) { return defaultSkin; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addAnimation") ) { return addAnimation_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"findBoneIndex") ) { return findBoneIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"findSlotIndex") ) { return findSlotIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"findAnimation") ) { return findAnimation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkeletonData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { bones=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"slots") ) { slots=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skins") ) { skins=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { events=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"animations") ) { animations=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultSkin") ) { defaultSkin=inValue.Cast< ::spinehaxe::Skin >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkeletonData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("bones"));
	outFields->push(HX_CSTRING("slots"));
	outFields->push(HX_CSTRING("skins"));
	outFields->push(HX_CSTRING("defaultSkin"));
	outFields->push(HX_CSTRING("events"));
	outFields->push(HX_CSTRING("animations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(SkeletonData_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkeletonData_obj,bones),HX_CSTRING("bones")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkeletonData_obj,slots),HX_CSTRING("slots")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkeletonData_obj,skins),HX_CSTRING("skins")},
	{hx::fsObject /*::spinehaxe::Skin*/ ,(int)offsetof(SkeletonData_obj,defaultSkin),HX_CSTRING("defaultSkin")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkeletonData_obj,events),HX_CSTRING("events")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkeletonData_obj,animations),HX_CSTRING("animations")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("bones"),
	HX_CSTRING("slots"),
	HX_CSTRING("skins"),
	HX_CSTRING("defaultSkin"),
	HX_CSTRING("events"),
	HX_CSTRING("animations"),
	HX_CSTRING("addBone"),
	HX_CSTRING("findBone"),
	HX_CSTRING("findBoneIndex"),
	HX_CSTRING("addSlot"),
	HX_CSTRING("findSlot"),
	HX_CSTRING("findSlotIndex"),
	HX_CSTRING("addSkin"),
	HX_CSTRING("findSkin"),
	HX_CSTRING("addEvent"),
	HX_CSTRING("findEvent"),
	HX_CSTRING("addAnimation"),
	HX_CSTRING("findAnimation"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkeletonData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkeletonData_obj::__mClass,"__mClass");
};

#endif

Class SkeletonData_obj::__mClass;

void SkeletonData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.SkeletonData"), hx::TCanCast< SkeletonData_obj> ,sStaticFields,sMemberFields,
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

void SkeletonData_obj::__boot()
{
}

} // end namespace spinehaxe
