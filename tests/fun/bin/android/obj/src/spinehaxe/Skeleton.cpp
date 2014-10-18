#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_Skin
#include <spinehaxe/Skin.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_SlotData
#include <spinehaxe/SlotData.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
namespace spinehaxe{

Void Skeleton_obj::__construct(::spinehaxe::SkeletonData data)
{
HX_STACK_FRAME("spinehaxe.Skeleton","new",0xf8023ae4,"spinehaxe.Skeleton.new","spinehaxe/Skeleton.hx",36,0x74391aab)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
{
	HX_STACK_LINE(53)
	this->y = (int)0;
	HX_STACK_LINE(52)
	this->x = (int)0;
	HX_STACK_LINE(49)
	this->time = (int)0;
	HX_STACK_LINE(48)
	this->a = (int)1;
	HX_STACK_LINE(47)
	this->b = (int)1;
	HX_STACK_LINE(46)
	this->g = (int)1;
	HX_STACK_LINE(45)
	this->r = (int)1;
	HX_STACK_LINE(55)
	if (((data == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("data cannot be null.")));
	}
	HX_STACK_LINE(57)
	this->data = data;
	HX_STACK_LINE(59)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(59)
	this->bones = _g;
	HX_STACK_LINE(60)
	{
		HX_STACK_LINE(60)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(60)
		Array< ::Dynamic > _g11 = data->bones;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(60)
		while((true)){
			HX_STACK_LINE(60)
			if ((!(((_g1 < _g11->length))))){
				HX_STACK_LINE(60)
				break;
			}
			HX_STACK_LINE(60)
			::spinehaxe::BoneData boneData = _g11->__get(_g1).StaticCast< ::spinehaxe::BoneData >();		HX_STACK_VAR(boneData,"boneData");
			HX_STACK_LINE(60)
			++(_g1);
			HX_STACK_LINE(61)
			::spinehaxe::Bone parent;		HX_STACK_VAR(parent,"parent");
			HX_STACK_LINE(61)
			if (((boneData->parent == null()))){
				HX_STACK_LINE(61)
				parent = null();
			}
			else{
				HX_STACK_LINE(61)
				int _g12 = ::spinehaxe::ArrayUtils_obj::indexOf(data->bones,boneData->parent);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(61)
				parent = this->bones->__get(_g12).StaticCast< ::spinehaxe::Bone >();
			}
			HX_STACK_LINE(62)
			this->bones[this->bones->length] = ::spinehaxe::Bone_obj::__new(boneData,parent);
		}
	}
	HX_STACK_LINE(65)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(65)
	this->slots = _g2;
	HX_STACK_LINE(66)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(66)
	this->drawOrder = _g3;
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		Array< ::Dynamic > _g11 = data->slots;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(67)
		while((true)){
			HX_STACK_LINE(67)
			if ((!(((_g1 < _g11->length))))){
				HX_STACK_LINE(67)
				break;
			}
			HX_STACK_LINE(67)
			::spinehaxe::SlotData slotData = _g11->__get(_g1).StaticCast< ::spinehaxe::SlotData >();		HX_STACK_VAR(slotData,"slotData");
			HX_STACK_LINE(67)
			++(_g1);
			HX_STACK_LINE(68)
			int _g4 = ::spinehaxe::ArrayUtils_obj::indexOf(data->bones,slotData->boneData);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(68)
			::spinehaxe::Bone bone = this->bones->__get(_g4).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(69)
			::spinehaxe::Slot slot = ::spinehaxe::Slot_obj::__new(slotData,hx::ObjectPtr<OBJ_>(this),bone);		HX_STACK_VAR(slot,"slot");
			HX_STACK_LINE(70)
			this->slots[this->slots->length] = slot;
			HX_STACK_LINE(71)
			this->drawOrder[this->drawOrder->length] = slot;
		}
	}
}
;
	return null();
}

//Skeleton_obj::~Skeleton_obj() { }

Dynamic Skeleton_obj::__CreateEmpty() { return  new Skeleton_obj; }
hx::ObjectPtr< Skeleton_obj > Skeleton_obj::__new(::spinehaxe::SkeletonData data)
{  hx::ObjectPtr< Skeleton_obj > result = new Skeleton_obj();
	result->__construct(data);
	return result;}

Dynamic Skeleton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Skeleton_obj > result = new Skeleton_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Skeleton_obj::updateWorldTransform( ){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","updateWorldTransform",0x4a2cd59f,"spinehaxe.Skeleton.updateWorldTransform","spinehaxe/Skeleton.hx",77,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_LINE(77)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(77)
		Array< ::Dynamic > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(77)
		while((true)){
			HX_STACK_LINE(77)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(77)
				break;
			}
			HX_STACK_LINE(77)
			::spinehaxe::Bone bone = _g1->__get(_g).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(77)
			++(_g);
			HX_STACK_LINE(78)
			bone->updateWorldTransform(this->flipX,this->flipY);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,updateWorldTransform,(void))

Void Skeleton_obj::setToSetupPose( ){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","setToSetupPose",0xc8b8ebed,"spinehaxe.Skeleton.setToSetupPose","spinehaxe/Skeleton.hx",82,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		this->setBonesToSetupPose();
		HX_STACK_LINE(84)
		this->setSlotsToSetupPose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,setToSetupPose,(void))

Void Skeleton_obj::setBonesToSetupPose( ){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","setBonesToSetupPose",0xa314924a,"spinehaxe.Skeleton.setBonesToSetupPose","spinehaxe/Skeleton.hx",88,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_LINE(88)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		Array< ::Dynamic > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			::spinehaxe::Bone bone = _g1->__get(_g).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(88)
			++(_g);
			HX_STACK_LINE(89)
			bone->setToSetupPose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,setBonesToSetupPose,(void))

Void Skeleton_obj::setSlotsToSetupPose( ){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","setSlotsToSetupPose",0xf7491c04,"spinehaxe.Skeleton.setSlotsToSetupPose","spinehaxe/Skeleton.hx",92,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_LINE(93)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(94)
		{
			HX_STACK_LINE(94)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(94)
			Array< ::Dynamic > _g1 = this->slots;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(94)
			while((true)){
				HX_STACK_LINE(94)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(94)
					break;
				}
				HX_STACK_LINE(94)
				::spinehaxe::Slot slot = _g1->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
				HX_STACK_LINE(94)
				++(_g);
				HX_STACK_LINE(95)
				int _g2 = (i)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(95)
				this->drawOrder[_g2] = slot;
				HX_STACK_LINE(96)
				slot->setToSetupPose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,setSlotsToSetupPose,(void))

::spinehaxe::Bone Skeleton_obj::get_rootBone( ){
	HX_STACK_FRAME("spinehaxe.Skeleton","get_rootBone",0x2c062f8b,"spinehaxe.Skeleton.get_rootBone","spinehaxe/Skeleton.hx",100,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_LINE(101)
	if (((this->bones->length == (int)0))){
		HX_STACK_LINE(102)
		return null();
	}
	HX_STACK_LINE(103)
	return this->bones->__get((int)0).StaticCast< ::spinehaxe::Bone >();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,get_rootBone,return )

::spinehaxe::Bone Skeleton_obj::findBone( ::String boneName){
	HX_STACK_FRAME("spinehaxe.Skeleton","findBone",0xa09c8719,"spinehaxe.Skeleton.findBone","spinehaxe/Skeleton.hx",107,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(boneName,"boneName")
	HX_STACK_LINE(108)
	if (((boneName == null()))){
		HX_STACK_LINE(109)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("boneName cannot be null.")));
	}
	HX_STACK_LINE(110)
	{
		HX_STACK_LINE(110)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(110)
		Array< ::Dynamic > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(110)
		while((true)){
			HX_STACK_LINE(110)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(110)
				break;
			}
			HX_STACK_LINE(110)
			::spinehaxe::Bone bone = _g1->__get(_g).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(110)
			++(_g);
			HX_STACK_LINE(111)
			if (((bone->data->name == boneName))){
				HX_STACK_LINE(112)
				return bone;
			}
		}
	}
	HX_STACK_LINE(113)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,findBone,return )

int Skeleton_obj::findBoneIndex( ::String boneName){
	HX_STACK_FRAME("spinehaxe.Skeleton","findBoneIndex",0x27c82939,"spinehaxe.Skeleton.findBoneIndex","spinehaxe/Skeleton.hx",117,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(boneName,"boneName")
	HX_STACK_LINE(118)
	if (((boneName == null()))){
		HX_STACK_LINE(119)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("boneName cannot be null.")));
	}
	HX_STACK_LINE(120)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(121)
	{
		HX_STACK_LINE(121)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(121)
		Array< ::Dynamic > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(121)
		while((true)){
			HX_STACK_LINE(121)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(121)
				break;
			}
			HX_STACK_LINE(121)
			::spinehaxe::Bone bone = _g1->__get(_g).StaticCast< ::spinehaxe::Bone >();		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(121)
			++(_g);
			HX_STACK_LINE(122)
			if (((bone->data->name == boneName))){
				HX_STACK_LINE(123)
				return i;
			}
			HX_STACK_LINE(124)
			(i)++;
		}
	}
	HX_STACK_LINE(127)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,findBoneIndex,return )

::spinehaxe::Slot Skeleton_obj::findSlot( ::String slotName){
	HX_STACK_FRAME("spinehaxe.Skeleton","findSlot",0xabd6e1d3,"spinehaxe.Skeleton.findSlot","spinehaxe/Skeleton.hx",131,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotName,"slotName")
	HX_STACK_LINE(132)
	if (((slotName == null()))){
		HX_STACK_LINE(133)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slotName cannot be null.")));
	}
	HX_STACK_LINE(134)
	{
		HX_STACK_LINE(134)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(134)
		Array< ::Dynamic > _g1 = this->slots;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(134)
		while((true)){
			HX_STACK_LINE(134)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(134)
				break;
			}
			HX_STACK_LINE(134)
			::spinehaxe::Slot slot = _g1->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
			HX_STACK_LINE(134)
			++(_g);
			HX_STACK_LINE(135)
			if (((slot->data->name == slotName))){
				HX_STACK_LINE(136)
				return slot;
			}
		}
	}
	HX_STACK_LINE(137)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,findSlot,return )

int Skeleton_obj::findSlotIndex( ::String slotName){
	HX_STACK_FRAME("spinehaxe.Skeleton","findSlotIndex",0xa728ac3f,"spinehaxe.Skeleton.findSlotIndex","spinehaxe/Skeleton.hx",141,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotName,"slotName")
	HX_STACK_LINE(142)
	if (((slotName == null()))){
		HX_STACK_LINE(143)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slotName cannot be null.")));
	}
	HX_STACK_LINE(144)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(145)
	{
		HX_STACK_LINE(145)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(145)
		Array< ::Dynamic > _g1 = this->slots;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(145)
		while((true)){
			HX_STACK_LINE(145)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(145)
				break;
			}
			HX_STACK_LINE(145)
			::spinehaxe::Slot slot = _g1->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
			HX_STACK_LINE(145)
			++(_g);
			HX_STACK_LINE(146)
			if (((slot->data->name == slotName))){
				HX_STACK_LINE(147)
				return i;
			}
			HX_STACK_LINE(148)
			(i)++;
		}
	}
	HX_STACK_LINE(151)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,findSlotIndex,return )

::String Skeleton_obj::set_skinName( ::String skinName){
	HX_STACK_FRAME("spinehaxe.Skeleton","set_skinName",0x013433e1,"spinehaxe.Skeleton.set_skinName","spinehaxe/Skeleton.hx",154,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(skinName,"skinName")
	HX_STACK_LINE(155)
	::spinehaxe::Skin skin = this->data->findSkin(skinName);		HX_STACK_VAR(skin,"skin");
	HX_STACK_LINE(156)
	if (((skin == null()))){
		HX_STACK_LINE(157)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Skin not found: ") + skinName)));
	}
	HX_STACK_LINE(158)
	this->skin = skin;
	HX_STACK_LINE(159)
	return skinName;
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,set_skinName,return )

::spinehaxe::Skin Skeleton_obj::setSkin( ::spinehaxe::Skin newSkin){
	HX_STACK_FRAME("spinehaxe.Skeleton","setSkin",0xf2e953c3,"spinehaxe.Skeleton.setSkin","spinehaxe/Skeleton.hx",165,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(newSkin,"newSkin")
	HX_STACK_LINE(166)
	if (((newSkin != null()))){
		HX_STACK_LINE(167)
		if (((this->skin != null()))){
			HX_STACK_LINE(168)
			newSkin->attachAll(hx::ObjectPtr<OBJ_>(this),this->skin);
		}
		else{
			HX_STACK_LINE(170)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(171)
			{
				HX_STACK_LINE(171)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(171)
				Array< ::Dynamic > _g1 = this->slots;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(171)
				while((true)){
					HX_STACK_LINE(171)
					if ((!(((_g < _g1->length))))){
						HX_STACK_LINE(171)
						break;
					}
					HX_STACK_LINE(171)
					::spinehaxe::Slot slot = _g1->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
					HX_STACK_LINE(171)
					++(_g);
					HX_STACK_LINE(172)
					::String name = slot->data->attachmentName;		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(173)
					if (((bool((name != null())) && bool((name != HX_CSTRING("")))))){
						HX_STACK_LINE(174)
						::spinehaxe::attachments::Attachment attachment = newSkin->getAttachment(i,name);		HX_STACK_VAR(attachment,"attachment");
						HX_STACK_LINE(175)
						if (((attachment != null()))){
							HX_STACK_LINE(175)
							slot->set_attachment(attachment);
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(180)
	return this->skin = newSkin;
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,setSkin,return )

::spinehaxe::attachments::Attachment Skeleton_obj::getAttachmentForSlotName( ::String slotName,::String attachmentName){
	HX_STACK_FRAME("spinehaxe.Skeleton","getAttachmentForSlotName",0x84709ef5,"spinehaxe.Skeleton.getAttachmentForSlotName","spinehaxe/Skeleton.hx",184,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotName,"slotName")
	HX_STACK_ARG(attachmentName,"attachmentName")
	HX_STACK_LINE(185)
	int _g = this->data->findSlotIndex(slotName);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(185)
	return this->getAttachmentForSlotIndex(_g,attachmentName);
}


HX_DEFINE_DYNAMIC_FUNC2(Skeleton_obj,getAttachmentForSlotName,return )

::spinehaxe::attachments::Attachment Skeleton_obj::getAttachmentForSlotIndex( int slotIndex,::String attachmentName){
	HX_STACK_FRAME("spinehaxe.Skeleton","getAttachmentForSlotIndex",0x85aa8328,"spinehaxe.Skeleton.getAttachmentForSlotIndex","spinehaxe/Skeleton.hx",189,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotIndex,"slotIndex")
	HX_STACK_ARG(attachmentName,"attachmentName")
	HX_STACK_LINE(190)
	if (((attachmentName == null()))){
		HX_STACK_LINE(191)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("attachmentName cannot be null.")));
	}
	HX_STACK_LINE(192)
	if (((this->skin != null()))){
		HX_STACK_LINE(193)
		::spinehaxe::attachments::Attachment attachment = this->skin->getAttachment(slotIndex,attachmentName);		HX_STACK_VAR(attachment,"attachment");
		HX_STACK_LINE(194)
		if (((attachment != null()))){
			HX_STACK_LINE(195)
			return attachment;
		}
	}
	HX_STACK_LINE(197)
	if (((this->data->defaultSkin != null()))){
		HX_STACK_LINE(198)
		return this->data->defaultSkin->getAttachment(slotIndex,attachmentName);
	}
	HX_STACK_LINE(199)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Skeleton_obj,getAttachmentForSlotIndex,return )

Void Skeleton_obj::setAttachment( ::String slotName,::String attachmentName){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","setAttachment",0xa7317da9,"spinehaxe.Skeleton.setAttachment","spinehaxe/Skeleton.hx",203,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_ARG(slotName,"slotName")
		HX_STACK_ARG(attachmentName,"attachmentName")
		HX_STACK_LINE(204)
		if (((slotName == null()))){
			HX_STACK_LINE(205)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("slotName cannot be null.")));
		}
		HX_STACK_LINE(206)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(207)
		{
			HX_STACK_LINE(207)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(207)
			Array< ::Dynamic > _g1 = this->slots;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(207)
			while((true)){
				HX_STACK_LINE(207)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(207)
					break;
				}
				HX_STACK_LINE(207)
				::spinehaxe::Slot slot = _g1->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
				HX_STACK_LINE(207)
				++(_g);
				HX_STACK_LINE(208)
				if (((slot->data->name == slotName))){
					HX_STACK_LINE(209)
					::spinehaxe::attachments::Attachment attachment = null();		HX_STACK_VAR(attachment,"attachment");
					HX_STACK_LINE(210)
					if (((attachmentName != null()))){
						HX_STACK_LINE(211)
						::spinehaxe::attachments::Attachment _g2 = this->getAttachmentForSlotIndex(i,attachmentName);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(211)
						attachment = _g2;
						HX_STACK_LINE(212)
						if (((attachment == null()))){
							HX_STACK_LINE(213)
							HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((((HX_CSTRING("Attachment not found: ") + attachmentName) + HX_CSTRING(", for slot: ")) + slotName)));
						}
					}
					HX_STACK_LINE(215)
					slot->set_attachment(attachment);
					HX_STACK_LINE(216)
					return null();
				}
				HX_STACK_LINE(218)
				(i)++;
			}
		}
		HX_STACK_LINE(221)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Slot not found: ") + slotName)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Skeleton_obj,setAttachment,(void))

Void Skeleton_obj::update( Float delta){
{
		HX_STACK_FRAME("spinehaxe.Skeleton","update",0x77f58605,"spinehaxe.Skeleton.update","spinehaxe/Skeleton.hx",225,0x74391aab)
		HX_STACK_THIS(this)
		HX_STACK_ARG(delta,"delta")
		HX_STACK_LINE(225)
		hx::AddEq(this->time,delta);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Skeleton_obj,update,(void))

::String Skeleton_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Skeleton","toString",0x455bc7a8,"spinehaxe.Skeleton.toString","spinehaxe/Skeleton.hx",229,0x74391aab)
	HX_STACK_THIS(this)
	HX_STACK_LINE(229)
	if (((this->data->name != null()))){
		HX_STACK_LINE(229)
		return this->data->name;
	}
	else{
		HX_STACK_LINE(229)
		::String _g = ::Std_obj::string(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(229)
		return (HX_CSTRING("") + _g);
	}
	HX_STACK_LINE(229)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Skeleton_obj,toString,return )


Skeleton_obj::Skeleton_obj()
{
}

void Skeleton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Skeleton);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(bones,"bones");
	HX_MARK_MEMBER_NAME(slots,"slots");
	HX_MARK_MEMBER_NAME(drawOrder,"drawOrder");
	HX_MARK_MEMBER_NAME(skin,"skin");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(flipX,"flipX");
	HX_MARK_MEMBER_NAME(flipY,"flipY");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

void Skeleton_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(bones,"bones");
	HX_VISIT_MEMBER_NAME(slots,"slots");
	HX_VISIT_MEMBER_NAME(drawOrder,"drawOrder");
	HX_VISIT_MEMBER_NAME(skin,"skin");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(g,"g");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(time,"time");
	HX_VISIT_MEMBER_NAME(flipX,"flipX");
	HX_VISIT_MEMBER_NAME(flipY,"flipY");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
}

Dynamic Skeleton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"skin") ) { return skin; }
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { return bones; }
		if (HX_FIELD_EQ(inName,"slots") ) { return slots; }
		if (HX_FIELD_EQ(inName,"flipX") ) { return flipX; }
		if (HX_FIELD_EQ(inName,"flipY") ) { return flipY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setSkin") ) { return setSkin_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rootBone") ) { return get_rootBone(); }
		if (HX_FIELD_EQ(inName,"findBone") ) { return findBone_dyn(); }
		if (HX_FIELD_EQ(inName,"findSlot") ) { return findSlot_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawOrder") ) { return drawOrder; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_rootBone") ) { return get_rootBone_dyn(); }
		if (HX_FIELD_EQ(inName,"set_skinName") ) { return set_skinName_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"findBoneIndex") ) { return findBoneIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"findSlotIndex") ) { return findSlotIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttachment") ) { return setAttachment_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setToSetupPose") ) { return setToSetupPose_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"setBonesToSetupPose") ) { return setBonesToSetupPose_dyn(); }
		if (HX_FIELD_EQ(inName,"setSlotsToSetupPose") ) { return setSlotsToSetupPose_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"updateWorldTransform") ) { return updateWorldTransform_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getAttachmentForSlotName") ) { return getAttachmentForSlotName_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getAttachmentForSlotIndex") ) { return getAttachmentForSlotIndex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Skeleton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::spinehaxe::SkeletonData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skin") ) { skin=inValue.Cast< ::spinehaxe::Skin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { bones=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"slots") ) { slots=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flipX") ) { flipX=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flipY") ) { flipY=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skinName") ) { return set_skinName(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawOrder") ) { drawOrder=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Skeleton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("bones"));
	outFields->push(HX_CSTRING("rootBone"));
	outFields->push(HX_CSTRING("slots"));
	outFields->push(HX_CSTRING("drawOrder"));
	outFields->push(HX_CSTRING("skin"));
	outFields->push(HX_CSTRING("skinName"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("flipX"));
	outFields->push(HX_CSTRING("flipY"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::SkeletonData*/ ,(int)offsetof(Skeleton_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Skeleton_obj,bones),HX_CSTRING("bones")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Skeleton_obj,slots),HX_CSTRING("slots")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Skeleton_obj,drawOrder),HX_CSTRING("drawOrder")},
	{hx::fsObject /*::spinehaxe::Skin*/ ,(int)offsetof(Skeleton_obj,skin),HX_CSTRING("skin")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,a),HX_CSTRING("a")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,time),HX_CSTRING("time")},
	{hx::fsBool,(int)offsetof(Skeleton_obj,flipX),HX_CSTRING("flipX")},
	{hx::fsBool,(int)offsetof(Skeleton_obj,flipY),HX_CSTRING("flipY")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Skeleton_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("bones"),
	HX_CSTRING("slots"),
	HX_CSTRING("drawOrder"),
	HX_CSTRING("skin"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("time"),
	HX_CSTRING("flipX"),
	HX_CSTRING("flipY"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("updateWorldTransform"),
	HX_CSTRING("setToSetupPose"),
	HX_CSTRING("setBonesToSetupPose"),
	HX_CSTRING("setSlotsToSetupPose"),
	HX_CSTRING("get_rootBone"),
	HX_CSTRING("findBone"),
	HX_CSTRING("findBoneIndex"),
	HX_CSTRING("findSlot"),
	HX_CSTRING("findSlotIndex"),
	HX_CSTRING("set_skinName"),
	HX_CSTRING("setSkin"),
	HX_CSTRING("getAttachmentForSlotName"),
	HX_CSTRING("getAttachmentForSlotIndex"),
	HX_CSTRING("setAttachment"),
	HX_CSTRING("update"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Skeleton_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Skeleton_obj::__mClass,"__mClass");
};

#endif

Class Skeleton_obj::__mClass;

void Skeleton_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Skeleton"), hx::TCanCast< Skeleton_obj> ,sStaticFields,sMemberFields,
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

void Skeleton_obj::__boot()
{
}

} // end namespace spinehaxe
