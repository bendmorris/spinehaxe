#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_Color
#include <spinehaxe/Color.h>
#endif
#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_EventData
#include <spinehaxe/EventData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_JsonUtils
#include <spinehaxe/JsonUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonJson
#include <spinehaxe/SkeletonJson.h>
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
#ifndef INCLUDED_spinehaxe_animation_AttachmentTimeline
#include <spinehaxe/animation/AttachmentTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_ColorTimeline
#include <spinehaxe/animation/ColorTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_CurveTimeline
#include <spinehaxe/animation/CurveTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_DrawOrderTimeline
#include <spinehaxe/animation/DrawOrderTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_EventTimeline
#include <spinehaxe/animation/EventTimeline.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_RotateTimeline
#include <spinehaxe/animation/RotateTimeline.h>
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
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlas
#include <spinehaxe/atlas/TextureAtlas.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AtlasAttachmentLoader
#include <spinehaxe/attachments/AtlasAttachmentLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentLoader
#include <spinehaxe/attachments/AttachmentLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentType
#include <spinehaxe/attachments/AttachmentType.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_AttachmentTypes
#include <spinehaxe/attachments/AttachmentTypes.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#include <spinehaxe/attachments/RegionAttachment.h>
#endif
namespace spinehaxe{

Void SkeletonJson_obj::__construct(::spinehaxe::attachments::AttachmentLoader attachmentLoader)
{
HX_STACK_FRAME("spinehaxe.SkeletonJson","new",0xa7254e2c,"spinehaxe.SkeletonJson.new","spinehaxe/SkeletonJson.hx",68,0x71d6c3e3)
HX_STACK_THIS(this)
HX_STACK_ARG(attachmentLoader,"attachmentLoader")
{
	HX_STACK_LINE(69)
	this->scale = (int)1;
	HX_STACK_LINE(70)
	this->attachmentLoader = attachmentLoader;
}
;
	return null();
}

//SkeletonJson_obj::~SkeletonJson_obj() { }

Dynamic SkeletonJson_obj::__CreateEmpty() { return  new SkeletonJson_obj; }
hx::ObjectPtr< SkeletonJson_obj > SkeletonJson_obj::__new(::spinehaxe::attachments::AttachmentLoader attachmentLoader)
{  hx::ObjectPtr< SkeletonJson_obj > result = new SkeletonJson_obj();
	result->__construct(attachmentLoader);
	return result;}

Dynamic SkeletonJson_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkeletonJson_obj > result = new SkeletonJson_obj();
	result->__construct(inArgs[0]);
	return result;}

::spinehaxe::SkeletonData SkeletonJson_obj::readSkeletonData( ::String fileData,::String name){
	HX_STACK_FRAME("spinehaxe.SkeletonJson","readSkeletonData",0x42c7f1c1,"spinehaxe.SkeletonJson.readSkeletonData","spinehaxe/SkeletonJson.hx",77,0x71d6c3e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fileData,"fileData")
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(78)
	::spinehaxe::SkeletonData skeletonData = ::spinehaxe::SkeletonData_obj::__new();		HX_STACK_VAR(skeletonData,"skeletonData");
	HX_STACK_LINE(79)
	skeletonData->name = name;
	HX_STACK_LINE(80)
	if ((!(::spinehaxe::SkeletonJson_obj::parsedJson->exists(name)))){
		HX_STACK_LINE(80)
		Dynamic v = ::spinehaxe::JsonUtils_obj::parse(fileData);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(80)
		::spinehaxe::SkeletonJson_obj::parsedJson->set(name,v);
		HX_STACK_LINE(80)
		v;
	}
	HX_STACK_LINE(81)
	Dynamic root = ::spinehaxe::SkeletonJson_obj::parsedJson->get(name);		HX_STACK_VAR(root,"root");
	HX_STACK_LINE(84)
	::spinehaxe::BoneData boneData;		HX_STACK_VAR(boneData,"boneData");
	HX_STACK_LINE(85)
	{
		HX_STACK_LINE(85)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(85)
		Dynamic _g1 = ::spinehaxe::JsonUtils_obj::getNodesArray(root,HX_CSTRING("bones"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(85)
		while((true)){
			HX_STACK_LINE(85)
			if ((!(((_g < _g1->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(85)
				break;
			}
			HX_STACK_LINE(85)
			Dynamic boneMap = _g1->__GetItem(_g);		HX_STACK_VAR(boneMap,"boneMap");
			HX_STACK_LINE(85)
			++(_g);
			HX_STACK_LINE(86)
			::spinehaxe::BoneData parent = null();		HX_STACK_VAR(parent,"parent");
			HX_STACK_LINE(87)
			::String parentName = ::spinehaxe::JsonUtils_obj::getStr(boneMap,HX_CSTRING("parent"),null());		HX_STACK_VAR(parentName,"parentName");
			HX_STACK_LINE(88)
			if (((parentName != null()))){
				HX_STACK_LINE(89)
				::spinehaxe::BoneData _g2 = skeletonData->findBone(parentName);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(89)
				parent = _g2;
				HX_STACK_LINE(90)
				if (((parent == null()))){
					HX_STACK_LINE(91)
					HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Parent bone not found: ") + parentName)));
				}
			}
			HX_STACK_LINE(93)
			::String _g11 = ::spinehaxe::JsonUtils_obj::getStr(boneMap,HX_CSTRING("name"),null());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(93)
			::spinehaxe::BoneData _g2 = ::spinehaxe::BoneData_obj::__new(_g11,parent);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(93)
			boneData = _g2;
			HX_STACK_LINE(94)
			Float _g3 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("length"),(int)0);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(94)
			Float _g4 = (_g3 * this->scale);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(94)
			boneData->length = _g4;
			HX_STACK_LINE(95)
			Float _g5 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("x"),(int)0);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(95)
			Float _g6 = (_g5 * this->scale);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(95)
			boneData->x = _g6;
			HX_STACK_LINE(96)
			Float _g7 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("y"),(int)0);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(96)
			Float _g8 = (_g7 * this->scale);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(96)
			boneData->y = _g8;
			HX_STACK_LINE(97)
			Float _g9 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("rotation"),(int)0);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(97)
			boneData->rotation = _g9;
			HX_STACK_LINE(98)
			Float _g10 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("scaleX"),(int)1);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(98)
			boneData->scaleX = _g10;
			HX_STACK_LINE(99)
			Float _g111 = ::spinehaxe::JsonUtils_obj::getFloat(boneMap,HX_CSTRING("scaleY"),(int)1);		HX_STACK_VAR(_g111,"_g111");
			HX_STACK_LINE(99)
			boneData->scaleY = _g111;
			HX_STACK_LINE(100)
			bool _g12 = ::spinehaxe::JsonUtils_obj::getBool(boneMap,HX_CSTRING("flipX"),false);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(100)
			boneData->flipX = _g12;
			HX_STACK_LINE(101)
			bool _g13 = ::spinehaxe::JsonUtils_obj::getBool(boneMap,HX_CSTRING("flipY"),false);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(101)
			boneData->flipY = _g13;
			HX_STACK_LINE(102)
			bool _g14 = ::spinehaxe::JsonUtils_obj::getBool(boneMap,HX_CSTRING("inheritScale"),true);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(102)
			boneData->inheritScale = _g14;
			HX_STACK_LINE(103)
			bool _g15 = ::spinehaxe::JsonUtils_obj::getBool(boneMap,HX_CSTRING("inheritRotation"),true);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(103)
			boneData->inheritRotation = _g15;
			HX_STACK_LINE(105)
			::String color_str = ::spinehaxe::JsonUtils_obj::getStr(boneMap,HX_CSTRING("color"),null());		HX_STACK_VAR(color_str,"color_str");
			HX_STACK_LINE(106)
			if (((color_str != null()))){
				HX_STACK_LINE(106)
				::spinehaxe::Color _g16 = ::spinehaxe::Color_obj::fromString(color_str);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(106)
				boneData->color = _g16;
			}
			HX_STACK_LINE(108)
			skeletonData->addBone(boneData);
		}
	}
	HX_STACK_LINE(112)
	Dynamic slots = ::spinehaxe::JsonUtils_obj::getNodesArray(root,HX_CSTRING("slots"));		HX_STACK_VAR(slots,"slots");
	HX_STACK_LINE(113)
	if (((slots != null()))){
		HX_STACK_LINE(114)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(114)
		while((true)){
			HX_STACK_LINE(114)
			if ((!(((_g < slots->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(114)
				break;
			}
			HX_STACK_LINE(114)
			Dynamic slotMap = slots->__GetItem(_g);		HX_STACK_VAR(slotMap,"slotMap");
			HX_STACK_LINE(114)
			++(_g);
			HX_STACK_LINE(115)
			::String boneName = ::spinehaxe::JsonUtils_obj::getStr(slotMap,HX_CSTRING("bone"),null());		HX_STACK_VAR(boneName,"boneName");
			HX_STACK_LINE(116)
			::spinehaxe::BoneData _g17 = skeletonData->findBone(boneName);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(116)
			boneData = _g17;
			HX_STACK_LINE(117)
			if (((boneData == null()))){
				HX_STACK_LINE(118)
				HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Slot bone not found: ") + boneName)));
			}
			HX_STACK_LINE(119)
			::String _g18 = ::spinehaxe::JsonUtils_obj::getStr(slotMap,HX_CSTRING("name"),null());		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(119)
			::spinehaxe::SlotData slotData = ::spinehaxe::SlotData_obj::__new(_g18,boneData);		HX_STACK_VAR(slotData,"slotData");
			HX_STACK_LINE(120)
			::String color = ::spinehaxe::JsonUtils_obj::getStr(slotMap,HX_CSTRING("color"),null());		HX_STACK_VAR(color,"color");
			HX_STACK_LINE(121)
			if (((color != null()))){
				HX_STACK_LINE(122)
				Float _g19 = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)0);		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(122)
				slotData->r = _g19;
				HX_STACK_LINE(123)
				Float _g20 = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)1);		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(123)
				slotData->g = _g20;
				HX_STACK_LINE(124)
				Float _g21 = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)2);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(124)
				slotData->b = _g21;
				HX_STACK_LINE(125)
				Float _g22 = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)3);		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(125)
				slotData->a = _g22;
			}
			HX_STACK_LINE(127)
			::String _g23 = ::spinehaxe::JsonUtils_obj::getStr(slotMap,HX_CSTRING("attachment"),null());		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(127)
			slotData->attachmentName = _g23;
			HX_STACK_LINE(128)
			bool _g24 = ::spinehaxe::JsonUtils_obj::getBool(slotMap,HX_CSTRING("additive"),false);		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(128)
			slotData->additiveBlending = _g24;
			HX_STACK_LINE(129)
			skeletonData->addSlot(slotData);
		}
	}
	HX_STACK_LINE(133)
	::haxe::Log_obj::trace(HX_CSTRING("read slots"),hx::SourceInfo(HX_CSTRING("SkeletonJson.hx"),133,HX_CSTRING("spinehaxe.SkeletonJson"),HX_CSTRING("readSkeletonData")));
	HX_STACK_LINE(135)
	Dynamic skins = ::spinehaxe::JsonUtils_obj::getNode(root,HX_CSTRING("skins"));		HX_STACK_VAR(skins,"skins");
	HX_STACK_LINE(136)
	if (((skins != null()))){
		HX_STACK_LINE(137)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(137)
		Array< ::String > _g1 = ::spinehaxe::JsonUtils_obj::fields(skins);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(137)
		while((true)){
			HX_STACK_LINE(137)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(137)
				break;
			}
			HX_STACK_LINE(137)
			::String skinName = _g1->__get(_g);		HX_STACK_VAR(skinName,"skinName");
			HX_STACK_LINE(137)
			++(_g);
			HX_STACK_LINE(138)
			Dynamic skinValue = ::spinehaxe::JsonUtils_obj::getNode(skins,skinName);		HX_STACK_VAR(skinValue,"skinValue");
			HX_STACK_LINE(139)
			::spinehaxe::Skin skin = ::spinehaxe::Skin_obj::__new(skinName);		HX_STACK_VAR(skin,"skin");
			HX_STACK_LINE(140)
			{
				HX_STACK_LINE(140)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(140)
				Array< ::String > _g3 = ::spinehaxe::JsonUtils_obj::fields(skinValue);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(140)
				while((true)){
					HX_STACK_LINE(140)
					if ((!(((_g2 < _g3->length))))){
						HX_STACK_LINE(140)
						break;
					}
					HX_STACK_LINE(140)
					::String slotName = _g3->__get(_g2);		HX_STACK_VAR(slotName,"slotName");
					HX_STACK_LINE(140)
					++(_g2);
					HX_STACK_LINE(141)
					Dynamic slotValue = ::spinehaxe::JsonUtils_obj::getNode(skinValue,slotName);		HX_STACK_VAR(slotValue,"slotValue");
					HX_STACK_LINE(142)
					int slotIndex = skeletonData->findSlotIndex(slotName);		HX_STACK_VAR(slotIndex,"slotIndex");
					HX_STACK_LINE(143)
					{
						HX_STACK_LINE(143)
						int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(143)
						Array< ::String > _g5 = ::spinehaxe::JsonUtils_obj::fields(slotValue);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(143)
						while((true)){
							HX_STACK_LINE(143)
							if ((!(((_g4 < _g5->length))))){
								HX_STACK_LINE(143)
								break;
							}
							HX_STACK_LINE(143)
							::String attachmentName = _g5->__get(_g4);		HX_STACK_VAR(attachmentName,"attachmentName");
							HX_STACK_LINE(143)
							++(_g4);
							HX_STACK_LINE(144)
							Dynamic attachmentValue = ::spinehaxe::JsonUtils_obj::getNode(slotValue,attachmentName);		HX_STACK_VAR(attachmentValue,"attachmentValue");
							HX_STACK_LINE(145)
							::spinehaxe::attachments::Attachment attachment = this->readAttachment(skin,attachmentName,attachmentValue);		HX_STACK_VAR(attachment,"attachment");
							HX_STACK_LINE(146)
							if (((attachment != null()))){
								HX_STACK_LINE(147)
								skin->addAttachment(slotIndex,attachmentName,attachment);
							}
						}
					}
				}
			}
			HX_STACK_LINE(152)
			skeletonData->addSkin(skin);
			HX_STACK_LINE(153)
			if (((skin->name == HX_CSTRING("default")))){
				HX_STACK_LINE(154)
				skeletonData->defaultSkin = skin;
			}
		}
	}
	HX_STACK_LINE(157)
	::haxe::Log_obj::trace(HX_CSTRING("read skins"),hx::SourceInfo(HX_CSTRING("SkeletonJson.hx"),157,HX_CSTRING("spinehaxe.SkeletonJson"),HX_CSTRING("readSkeletonData")));
	HX_STACK_LINE(160)
	Dynamic events = ::spinehaxe::JsonUtils_obj::getNode(root,HX_CSTRING("events"));		HX_STACK_VAR(events,"events");
	HX_STACK_LINE(161)
	if (((events != null()))){
		HX_STACK_LINE(162)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(162)
		Array< ::String > _g1 = ::spinehaxe::JsonUtils_obj::fields(events);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(162)
		while((true)){
			HX_STACK_LINE(162)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(162)
				break;
			}
			HX_STACK_LINE(162)
			::String eventName = _g1->__get(_g);		HX_STACK_VAR(eventName,"eventName");
			HX_STACK_LINE(162)
			++(_g);
			HX_STACK_LINE(163)
			Dynamic eventMap = ::spinehaxe::JsonUtils_obj::getNode(events,eventName);		HX_STACK_VAR(eventMap,"eventMap");
			HX_STACK_LINE(164)
			::spinehaxe::EventData eventData = ::spinehaxe::EventData_obj::__new(eventName);		HX_STACK_VAR(eventData,"eventData");
			HX_STACK_LINE(165)
			int _g25 = ::spinehaxe::JsonUtils_obj::getInt(eventMap,HX_CSTRING("int"),(int)0);		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(165)
			eventData->intValue = _g25;
			HX_STACK_LINE(166)
			Float _g26 = ::spinehaxe::JsonUtils_obj::getFloat(eventMap,HX_CSTRING("float"),(int)0);		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(166)
			eventData->floatValue = _g26;
			HX_STACK_LINE(167)
			::String _g27 = ::spinehaxe::JsonUtils_obj::getStr(eventMap,HX_CSTRING("string"),null());		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(167)
			eventData->stringValue = _g27;
			HX_STACK_LINE(168)
			skeletonData->addEvent(eventData);
		}
	}
	HX_STACK_LINE(174)
	Dynamic animations = ::spinehaxe::JsonUtils_obj::getNode(root,HX_CSTRING("animations"));		HX_STACK_VAR(animations,"animations");
	HX_STACK_LINE(175)
	{
		HX_STACK_LINE(175)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(175)
		Array< ::String > _g1 = ::spinehaxe::JsonUtils_obj::fields(animations);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(175)
		while((true)){
			HX_STACK_LINE(175)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(175)
				break;
			}
			HX_STACK_LINE(175)
			::String animationName = _g1->__get(_g);		HX_STACK_VAR(animationName,"animationName");
			HX_STACK_LINE(175)
			++(_g);
			HX_STACK_LINE(176)
			Dynamic _g28 = ::spinehaxe::JsonUtils_obj::getNode(animations,animationName);		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(176)
			this->readAnimation(animationName,_g28,skeletonData);
		}
	}
	HX_STACK_LINE(178)
	return skeletonData;
}


HX_DEFINE_DYNAMIC_FUNC2(SkeletonJson_obj,readSkeletonData,return )

::spinehaxe::attachments::Attachment SkeletonJson_obj::readAttachment( ::spinehaxe::Skin skin,::String name,Dynamic map){
	HX_STACK_FRAME("spinehaxe.SkeletonJson","readAttachment",0xc0901c8d,"spinehaxe.SkeletonJson.readAttachment","spinehaxe/SkeletonJson.hx",181,0x71d6c3e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(skin,"skin")
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(map,"map")
	HX_STACK_LINE(182)
	::String name2 = ::spinehaxe::JsonUtils_obj::getStr(map,HX_CSTRING("name"),null());		HX_STACK_VAR(name2,"name2");
	HX_STACK_LINE(183)
	if (((name2 != null()))){
		HX_STACK_LINE(183)
		name = name2;
	}
	else{
		HX_STACK_LINE(183)
		name = name;
	}
	HX_STACK_LINE(185)
	::String _g = ::spinehaxe::JsonUtils_obj::getStr(map,HX_CSTRING("type"),HX_CSTRING("region"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(185)
	::spinehaxe::attachments::AttachmentType type = ::spinehaxe::attachments::AttachmentTypes_obj::valueOf(_g,null());		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(186)
	::spinehaxe::attachments::Attachment attachment = this->attachmentLoader->newAttachment(skin,type,name);		HX_STACK_VAR(attachment,"attachment");
	HX_STACK_LINE(187)
	if ((::Std_obj::is(attachment,hx::ClassOf< ::spinehaxe::attachments::RegionAttachment >()))){
		HX_STACK_LINE(188)
		::spinehaxe::attachments::RegionAttachment regionAttachment;		HX_STACK_VAR(regionAttachment,"regionAttachment");
		HX_STACK_LINE(188)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(188)
			regionAttachment = hx::TCast< spinehaxe::attachments::RegionAttachment >::cast(attachment);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(188)
					regionAttachment = null();
				}
			}
		}
		HX_STACK_LINE(189)
		Float _g1 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("x"),(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(189)
		Float _g2 = (_g1 * this->scale);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(189)
		regionAttachment->x = _g2;
		HX_STACK_LINE(190)
		Float _g3 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("y"),(int)0);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(190)
		Float _g4 = (_g3 * this->scale);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(190)
		regionAttachment->y = _g4;
		HX_STACK_LINE(191)
		Float _g5 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("scaleX"),(int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(191)
		regionAttachment->scaleX = _g5;
		HX_STACK_LINE(192)
		Float _g6 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("scaleY"),(int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(192)
		regionAttachment->scaleY = _g6;
		HX_STACK_LINE(193)
		Float _g7 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("rotation"),(int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(193)
		regionAttachment->rotation = _g7;
		HX_STACK_LINE(194)
		Float _g8 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("width"),(int)32);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(194)
		Float _g9 = (_g8 * this->scale);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(194)
		regionAttachment->width = _g9;
		HX_STACK_LINE(195)
		Float _g10 = ::spinehaxe::JsonUtils_obj::getFloat(map,HX_CSTRING("height"),(int)32);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(195)
		Float _g11 = (_g10 * this->scale);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(195)
		regionAttachment->height = _g11;
		HX_STACK_LINE(196)
		regionAttachment->updateOffset();
	}
	HX_STACK_LINE(205)
	return attachment;
}


HX_DEFINE_DYNAMIC_FUNC3(SkeletonJson_obj,readAttachment,return )

Void SkeletonJson_obj::readAnimation( ::String name,Dynamic map,::spinehaxe::SkeletonData skeletonData){
{
		HX_STACK_FRAME("spinehaxe.SkeletonJson","readAnimation",0xe0509d9a,"spinehaxe.SkeletonJson.readAnimation","spinehaxe/SkeletonJson.hx",208,0x71d6c3e3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(name,"name")
		HX_STACK_ARG(map,"map")
		HX_STACK_ARG(skeletonData,"skeletonData")
		HX_STACK_LINE(209)
		Array< ::spinehaxe::animation::Timeline > timelines = Array_obj< ::spinehaxe::animation::Timeline >::__new();		HX_STACK_VAR(timelines,"timelines");
		HX_STACK_LINE(210)
		Float duration = (int)0;		HX_STACK_VAR(duration,"duration");
		HX_STACK_LINE(211)
		Dynamic bones = ::spinehaxe::JsonUtils_obj::getNode(map,HX_CSTRING("bones"));		HX_STACK_VAR(bones,"bones");
		HX_STACK_LINE(212)
		if (((bones != null()))){
			HX_STACK_LINE(213)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(213)
			Array< ::String > _g1 = ::spinehaxe::JsonUtils_obj::fields(bones);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(213)
			while((true)){
				HX_STACK_LINE(213)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(213)
					break;
				}
				HX_STACK_LINE(213)
				::String boneName = _g1->__get(_g);		HX_STACK_VAR(boneName,"boneName");
				HX_STACK_LINE(213)
				++(_g);
				HX_STACK_LINE(214)
				int boneIndex = skeletonData->findBoneIndex(boneName);		HX_STACK_VAR(boneIndex,"boneIndex");
				HX_STACK_LINE(215)
				if (((boneIndex == (int)-1))){
					HX_STACK_LINE(216)
					HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Bone not found: ") + boneName)));
				}
				HX_STACK_LINE(217)
				Dynamic boneMap = ::spinehaxe::JsonUtils_obj::getNode(bones,boneName);		HX_STACK_VAR(boneMap,"boneMap");
				HX_STACK_LINE(218)
				{
					HX_STACK_LINE(218)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(218)
					Array< ::String > _g3 = ::spinehaxe::JsonUtils_obj::fields(boneMap);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(218)
					while((true)){
						HX_STACK_LINE(218)
						if ((!(((_g2 < _g3->length))))){
							HX_STACK_LINE(218)
							break;
						}
						HX_STACK_LINE(218)
						::String timelineName = _g3->__get(_g2);		HX_STACK_VAR(timelineName,"timelineName");
						HX_STACK_LINE(218)
						++(_g2);
						HX_STACK_LINE(219)
						Dynamic values = ::spinehaxe::JsonUtils_obj::getNodesArray(boneMap,timelineName);		HX_STACK_VAR(values,"values");
						HX_STACK_LINE(221)
						if (((timelineName == HX_CSTRING("rotate")))){
							HX_STACK_LINE(222)
							::spinehaxe::animation::RotateTimeline timeline = ::spinehaxe::animation::RotateTimeline_obj::__new(values->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(timeline,"timeline");
							HX_STACK_LINE(223)
							timeline->boneIndex = boneIndex;
							HX_STACK_LINE(225)
							int frameIndex = (int)0;		HX_STACK_VAR(frameIndex,"frameIndex");
							HX_STACK_LINE(226)
							{
								HX_STACK_LINE(226)
								int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(226)
								while((true)){
									HX_STACK_LINE(226)
									if ((!(((_g4 < values->__Field(HX_CSTRING("length"),true)))))){
										HX_STACK_LINE(226)
										break;
									}
									HX_STACK_LINE(226)
									Dynamic valueMap = values->__GetItem(_g4);		HX_STACK_VAR(valueMap,"valueMap");
									HX_STACK_LINE(226)
									++(_g4);
									HX_STACK_LINE(227)
									Float time = ::spinehaxe::JsonUtils_obj::getFloat(valueMap,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
									HX_STACK_LINE(228)
									Float _g5 = ::spinehaxe::JsonUtils_obj::getFloat(valueMap,HX_CSTRING("angle"),null());		HX_STACK_VAR(_g5,"_g5");
									HX_STACK_LINE(228)
									timeline->setFrame(frameIndex,time,_g5);
									HX_STACK_LINE(229)
									this->readCurve(timeline,frameIndex,valueMap);
									HX_STACK_LINE(230)
									(frameIndex)++;
								}
							}
							HX_STACK_LINE(233)
							timelines->push(timeline);
							HX_STACK_LINE(234)
							Dynamic _g4;		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(234)
							{
								HX_STACK_LINE(234)
								int _g11 = timeline->get_frameCount();		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(234)
								int _g21 = (_g11 * (int)2);		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(234)
								int _g31 = (_g21 - (int)2);		HX_STACK_VAR(_g31,"_g31");
								HX_STACK_LINE(234)
								int index = ::Std_obj::_int(_g31);		HX_STACK_VAR(index,"index");
								HX_STACK_LINE(234)
								_g4 = timeline->frames->__unsafe_get(index);
							}
							HX_STACK_LINE(234)
							Float _g5 = ::Math_obj::max(duration,_g4);		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(234)
							duration = _g5;
						}
						else{
							HX_STACK_LINE(237)
							if (((bool((timelineName == HX_CSTRING("translate"))) || bool((timelineName == HX_CSTRING("scale")))))){
								HX_STACK_LINE(238)
								::spinehaxe::animation::TranslateTimeline timeline1;		HX_STACK_VAR(timeline1,"timeline1");
								HX_STACK_LINE(239)
								Float timelineScale = (int)1;		HX_STACK_VAR(timelineScale,"timelineScale");
								HX_STACK_LINE(240)
								if (((timelineName == HX_CSTRING("scale")))){
									HX_STACK_LINE(241)
									::spinehaxe::animation::ScaleTimeline _g6 = ::spinehaxe::animation::ScaleTimeline_obj::__new(values->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(_g6,"_g6");
									HX_STACK_LINE(241)
									timeline1 = _g6;
								}
								else{
									HX_STACK_LINE(243)
									::spinehaxe::animation::TranslateTimeline _g7 = ::spinehaxe::animation::TranslateTimeline_obj::__new(values->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(_g7,"_g7");
									HX_STACK_LINE(243)
									timeline1 = _g7;
									HX_STACK_LINE(244)
									timelineScale = this->scale;
								}
								HX_STACK_LINE(247)
								timeline1->boneIndex = boneIndex;
								HX_STACK_LINE(248)
								int frameIndex1 = (int)0;		HX_STACK_VAR(frameIndex1,"frameIndex1");
								HX_STACK_LINE(249)
								{
									HX_STACK_LINE(249)
									int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
									HX_STACK_LINE(249)
									while((true)){
										HX_STACK_LINE(249)
										if ((!(((_g4 < values->__Field(HX_CSTRING("length"),true)))))){
											HX_STACK_LINE(249)
											break;
										}
										HX_STACK_LINE(249)
										Dynamic valueMap1 = values->__GetItem(_g4);		HX_STACK_VAR(valueMap1,"valueMap1");
										HX_STACK_LINE(249)
										++(_g4);
										HX_STACK_LINE(250)
										Float time = ::spinehaxe::JsonUtils_obj::getFloat(valueMap1,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
										HX_STACK_LINE(251)
										Float _g8 = ::spinehaxe::JsonUtils_obj::getFloat(valueMap1,HX_CSTRING("x"),(int)0);		HX_STACK_VAR(_g8,"_g8");
										HX_STACK_LINE(251)
										Float x = (_g8 * timelineScale);		HX_STACK_VAR(x,"x");
										HX_STACK_LINE(252)
										Float _g9 = ::spinehaxe::JsonUtils_obj::getFloat(valueMap1,HX_CSTRING("y"),(int)0);		HX_STACK_VAR(_g9,"_g9");
										HX_STACK_LINE(252)
										Float y = (_g9 * timelineScale);		HX_STACK_VAR(y,"y");
										HX_STACK_LINE(253)
										timeline1->setFrame(frameIndex1,time,x,y);
										HX_STACK_LINE(254)
										this->readCurve(timeline1,frameIndex1,valueMap1);
										HX_STACK_LINE(255)
										(frameIndex1)++;
									}
								}
								HX_STACK_LINE(258)
								timelines->push(timeline1);
								HX_STACK_LINE(259)
								Dynamic _g13;		HX_STACK_VAR(_g13,"_g13");
								HX_STACK_LINE(259)
								{
									HX_STACK_LINE(259)
									int _g10 = timeline1->get_frameCount();		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(259)
									int _g11 = (_g10 * (int)3);		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(259)
									int _g12 = (_g11 - (int)3);		HX_STACK_VAR(_g12,"_g12");
									HX_STACK_LINE(259)
									int index = ::Std_obj::_int(_g12);		HX_STACK_VAR(index,"index");
									HX_STACK_LINE(259)
									_g13 = timeline1->frames->__unsafe_get(index);
								}
								HX_STACK_LINE(259)
								Float _g14 = ::Math_obj::max(duration,_g13);		HX_STACK_VAR(_g14,"_g14");
								HX_STACK_LINE(259)
								duration = _g14;
							}
							else{
								HX_STACK_LINE(262)
								HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(((((HX_CSTRING("Invalid timeline type for a bone: ") + timelineName) + HX_CSTRING(" (")) + boneName) + HX_CSTRING(")"))));
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(268)
		Dynamic slots = ::spinehaxe::JsonUtils_obj::getNode(map,HX_CSTRING("slots"));		HX_STACK_VAR(slots,"slots");
		HX_STACK_LINE(269)
		if (((slots != null()))){
			HX_STACK_LINE(270)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(270)
			Array< ::String > _g1 = ::spinehaxe::JsonUtils_obj::fields(slots);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(270)
			while((true)){
				HX_STACK_LINE(270)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(270)
					break;
				}
				HX_STACK_LINE(270)
				::String slotName = _g1->__get(_g);		HX_STACK_VAR(slotName,"slotName");
				HX_STACK_LINE(270)
				++(_g);
				HX_STACK_LINE(271)
				Dynamic slotMap = ::spinehaxe::JsonUtils_obj::getNode(slots,slotName);		HX_STACK_VAR(slotMap,"slotMap");
				HX_STACK_LINE(272)
				int slotIndex = skeletonData->findSlotIndex(slotName);		HX_STACK_VAR(slotIndex,"slotIndex");
				HX_STACK_LINE(273)
				{
					HX_STACK_LINE(273)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(273)
					Array< ::String > _g3 = ::spinehaxe::JsonUtils_obj::fields(slotMap);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(273)
					while((true)){
						HX_STACK_LINE(273)
						if ((!(((_g2 < _g3->length))))){
							HX_STACK_LINE(273)
							break;
						}
						HX_STACK_LINE(273)
						::String timelineName2 = _g3->__get(_g2);		HX_STACK_VAR(timelineName2,"timelineName2");
						HX_STACK_LINE(273)
						++(_g2);
						HX_STACK_LINE(274)
						Dynamic values2 = ::spinehaxe::JsonUtils_obj::getNodesArray(slotMap,timelineName2);		HX_STACK_VAR(values2,"values2");
						HX_STACK_LINE(275)
						if (((timelineName2 == HX_CSTRING("color")))){
							HX_STACK_LINE(276)
							::spinehaxe::animation::ColorTimeline timeline2 = ::spinehaxe::animation::ColorTimeline_obj::__new(values2->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(timeline2,"timeline2");
							HX_STACK_LINE(277)
							timeline2->slotIndex = slotIndex;
							HX_STACK_LINE(278)
							int frameIndex2 = (int)0;		HX_STACK_VAR(frameIndex2,"frameIndex2");
							HX_STACK_LINE(279)
							{
								HX_STACK_LINE(279)
								int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(279)
								while((true)){
									HX_STACK_LINE(279)
									if ((!(((_g4 < values2->__Field(HX_CSTRING("length"),true)))))){
										HX_STACK_LINE(279)
										break;
									}
									HX_STACK_LINE(279)
									Dynamic valueMap2 = values2->__GetItem(_g4);		HX_STACK_VAR(valueMap2,"valueMap2");
									HX_STACK_LINE(279)
									++(_g4);
									HX_STACK_LINE(280)
									Float time = ::spinehaxe::JsonUtils_obj::getFloat(valueMap2,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
									HX_STACK_LINE(281)
									::String color = ::spinehaxe::JsonUtils_obj::getStr(valueMap2,HX_CSTRING("color"),null());		HX_STACK_VAR(color,"color");
									HX_STACK_LINE(282)
									Float r = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)0);		HX_STACK_VAR(r,"r");
									HX_STACK_LINE(283)
									Float g = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)1);		HX_STACK_VAR(g,"g");
									HX_STACK_LINE(284)
									Float b = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)2);		HX_STACK_VAR(b,"b");
									HX_STACK_LINE(285)
									Float a = ::spinehaxe::SkeletonJson_obj::toColor(color,(int)3);		HX_STACK_VAR(a,"a");
									HX_STACK_LINE(286)
									timeline2->setFrame(frameIndex2,time,r,g,b,a);
									HX_STACK_LINE(287)
									this->readCurve(timeline2,frameIndex2,valueMap2);
									HX_STACK_LINE(288)
									(frameIndex2)++;
								}
							}
							HX_STACK_LINE(291)
							timelines->push(timeline2);
							HX_STACK_LINE(292)
							Dynamic _g18;		HX_STACK_VAR(_g18,"_g18");
							HX_STACK_LINE(292)
							{
								HX_STACK_LINE(292)
								int _g15 = timeline2->get_frameCount();		HX_STACK_VAR(_g15,"_g15");
								HX_STACK_LINE(292)
								int _g16 = (_g15 * (int)5);		HX_STACK_VAR(_g16,"_g16");
								HX_STACK_LINE(292)
								int _g17 = (_g16 - (int)5);		HX_STACK_VAR(_g17,"_g17");
								HX_STACK_LINE(292)
								int index = ::Std_obj::_int(_g17);		HX_STACK_VAR(index,"index");
								HX_STACK_LINE(292)
								_g18 = timeline2->frames->__unsafe_get(index);
							}
							HX_STACK_LINE(292)
							Float _g19 = ::Math_obj::max(duration,_g18);		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(292)
							duration = _g19;
						}
						else{
							HX_STACK_LINE(295)
							if (((timelineName2 == HX_CSTRING("attachment")))){
								HX_STACK_LINE(296)
								::spinehaxe::animation::AttachmentTimeline timeline3 = ::spinehaxe::animation::AttachmentTimeline_obj::__new(values2->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(timeline3,"timeline3");
								HX_STACK_LINE(297)
								timeline3->slotIndex = slotIndex;
								HX_STACK_LINE(298)
								int frameIndex3 = (int)0;		HX_STACK_VAR(frameIndex3,"frameIndex3");
								HX_STACK_LINE(299)
								{
									HX_STACK_LINE(299)
									int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
									HX_STACK_LINE(299)
									while((true)){
										HX_STACK_LINE(299)
										if ((!(((_g4 < values2->__Field(HX_CSTRING("length"),true)))))){
											HX_STACK_LINE(299)
											break;
										}
										HX_STACK_LINE(299)
										Dynamic valueMap3 = values2->__GetItem(_g4);		HX_STACK_VAR(valueMap3,"valueMap3");
										HX_STACK_LINE(299)
										++(_g4);
										HX_STACK_LINE(300)
										Float time = ::spinehaxe::JsonUtils_obj::getFloat(valueMap3,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
										HX_STACK_LINE(301)
										::String name1 = ::spinehaxe::JsonUtils_obj::getStr(valueMap3,HX_CSTRING("name"),null());		HX_STACK_VAR(name1,"name1");
										HX_STACK_LINE(302)
										int _g20 = (frameIndex3)++;		HX_STACK_VAR(_g20,"_g20");
										HX_STACK_LINE(302)
										timeline3->setFrame(_g20,time,name1);
									}
								}
								HX_STACK_LINE(305)
								timelines->push(timeline3);
								HX_STACK_LINE(306)
								Dynamic _g22;		HX_STACK_VAR(_g22,"_g22");
								HX_STACK_LINE(306)
								{
									HX_STACK_LINE(306)
									int _g21 = timeline3->get_frameCount();		HX_STACK_VAR(_g21,"_g21");
									HX_STACK_LINE(306)
									int index = (_g21 - (int)1);		HX_STACK_VAR(index,"index");
									HX_STACK_LINE(306)
									_g22 = timeline3->frames->__unsafe_get(index);
								}
								HX_STACK_LINE(306)
								Float _g23 = ::Math_obj::max(duration,_g22);		HX_STACK_VAR(_g23,"_g23");
								HX_STACK_LINE(306)
								duration = _g23;
							}
							else{
								HX_STACK_LINE(309)
								HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(((((HX_CSTRING("Invalid timeline type for a slot: ") + timelineName2) + HX_CSTRING(" (")) + slotName) + HX_CSTRING(")"))));
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(315)
		Dynamic eventsMap = ::spinehaxe::JsonUtils_obj::getNode(map,HX_CSTRING("events"));		HX_STACK_VAR(eventsMap,"eventsMap");
		HX_STACK_LINE(316)
		if (((eventsMap != null()))){
			HX_STACK_LINE(317)
			::spinehaxe::animation::EventTimeline timeline4 = ::spinehaxe::animation::EventTimeline_obj::__new(eventsMap->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(timeline4,"timeline4");
			HX_STACK_LINE(318)
			int frameIndex4 = (int)0;		HX_STACK_VAR(frameIndex4,"frameIndex4");
			HX_STACK_LINE(319)
			{
				HX_STACK_LINE(319)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(319)
				Dynamic _g1;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(319)
				_g1 = hx::TCastToArray(eventsMap);
				HX_STACK_LINE(319)
				while((true)){
					HX_STACK_LINE(319)
					if ((!(((_g < _g1->__Field(HX_CSTRING("length"),true)))))){
						HX_STACK_LINE(319)
						break;
					}
					HX_STACK_LINE(319)
					Dynamic eventMap = _g1->__GetItem(_g);		HX_STACK_VAR(eventMap,"eventMap");
					HX_STACK_LINE(319)
					++(_g);
					HX_STACK_LINE(320)
					::String eventMapName = ::spinehaxe::JsonUtils_obj::getStr(eventMap,HX_CSTRING("name"),null());		HX_STACK_VAR(eventMapName,"eventMapName");
					HX_STACK_LINE(321)
					::spinehaxe::EventData eventData = skeletonData->findEvent(eventMapName);		HX_STACK_VAR(eventData,"eventData");
					HX_STACK_LINE(322)
					if (((eventData == null()))){
						HX_STACK_LINE(323)
						HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Event not found: ") + eventMapName)));
					}
					HX_STACK_LINE(324)
					::spinehaxe::Event event = ::spinehaxe::Event_obj::__new(eventData);		HX_STACK_VAR(event,"event");
					HX_STACK_LINE(325)
					int _g24 = ::spinehaxe::JsonUtils_obj::getInt(eventMap,HX_CSTRING("int"),eventData->intValue);		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(325)
					event->intValue = _g24;
					HX_STACK_LINE(326)
					Float _g25 = ::spinehaxe::JsonUtils_obj::getFloat(eventMap,HX_CSTRING("float"),eventData->floatValue);		HX_STACK_VAR(_g25,"_g25");
					HX_STACK_LINE(326)
					event->floatValue = _g25;
					HX_STACK_LINE(327)
					::String _g26 = ::spinehaxe::JsonUtils_obj::getStr(eventMap,HX_CSTRING("string"),eventData->stringValue);		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(327)
					event->stringValue = _g26;
					HX_STACK_LINE(328)
					Float time = ::spinehaxe::JsonUtils_obj::getFloat(eventMap,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
					HX_STACK_LINE(329)
					int _g27 = (frameIndex4)++;		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(329)
					timeline4->setFrame(_g27,time,event);
				}
			}
			HX_STACK_LINE(332)
			timelines->push(timeline4);
			HX_STACK_LINE(333)
			Dynamic _g29;		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(333)
			{
				HX_STACK_LINE(333)
				int _g28 = timeline4->get_frameCount();		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(333)
				int index = (_g28 - (int)1);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(333)
				_g29 = timeline4->frames->__unsafe_get(index);
			}
			HX_STACK_LINE(333)
			Float _g30 = ::Math_obj::max(duration,_g29);		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(333)
			duration = _g30;
		}
		HX_STACK_LINE(336)
		Dynamic drawOrderValues = ::spinehaxe::JsonUtils_obj::getNode(map,HX_CSTRING("draworder"));		HX_STACK_VAR(drawOrderValues,"drawOrderValues");
		HX_STACK_LINE(337)
		if (((drawOrderValues != null()))){
			HX_STACK_LINE(338)
			::spinehaxe::animation::DrawOrderTimeline timeline5 = ::spinehaxe::animation::DrawOrderTimeline_obj::__new(drawOrderValues->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(timeline5,"timeline5");
			HX_STACK_LINE(339)
			int slotCount = skeletonData->slots->length;		HX_STACK_VAR(slotCount,"slotCount");
			HX_STACK_LINE(340)
			int frameIndex5 = (int)0;		HX_STACK_VAR(frameIndex5,"frameIndex5");
			HX_STACK_LINE(341)
			{
				HX_STACK_LINE(341)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(341)
				Dynamic _g1;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(341)
				_g1 = hx::TCastToArray(drawOrderValues);
				HX_STACK_LINE(341)
				while((true)){
					HX_STACK_LINE(341)
					if ((!(((_g < _g1->__Field(HX_CSTRING("length"),true)))))){
						HX_STACK_LINE(341)
						break;
					}
					HX_STACK_LINE(341)
					Dynamic drawOrderMap = _g1->__GetItem(_g);		HX_STACK_VAR(drawOrderMap,"drawOrderMap");
					HX_STACK_LINE(341)
					++(_g);
					HX_STACK_LINE(342)
					Array< int > drawOrder = null();		HX_STACK_VAR(drawOrder,"drawOrder");
					HX_STACK_LINE(343)
					Dynamic offsets = ::spinehaxe::JsonUtils_obj::getNode(drawOrderMap,HX_CSTRING("offsets"));		HX_STACK_VAR(offsets,"offsets");
					HX_STACK_LINE(344)
					if (((offsets != null()))){
						HX_STACK_LINE(345)
						Array< int > _g32;		HX_STACK_VAR(_g32,"_g32");
						struct _Function_5_1{
							inline static Array< int > Block( int &slotCount){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/SkeletonJson.hx",345,0x71d6c3e3)
								{
									HX_STACK_LINE(345)
									Array< int > this1;		HX_STACK_VAR(this1,"this1");
									HX_STACK_LINE(345)
									Array< int > _g31 = Array_obj< int >::__new()->__SetSizeExact(slotCount);		HX_STACK_VAR(_g31,"_g31");
									HX_STACK_LINE(345)
									this1 = _g31;
									HX_STACK_LINE(345)
									return this1;
								}
								return null();
							}
						};
						HX_STACK_LINE(345)
						_g32 = _Function_5_1::Block(slotCount);
						HX_STACK_LINE(345)
						drawOrder = _g32;
						HX_STACK_LINE(346)
						int i = (slotCount - (int)1);		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(347)
						while((true)){
							HX_STACK_LINE(347)
							if ((!(((i >= (int)0))))){
								HX_STACK_LINE(347)
								break;
							}
							HX_STACK_LINE(348)
							drawOrder->__unsafe_set(i,(int)-1);
							HX_STACK_LINE(349)
							(i)--;
						}
						HX_STACK_LINE(351)
						Array< int > unchanged;		HX_STACK_VAR(unchanged,"unchanged");
						HX_STACK_LINE(351)
						{
							HX_STACK_LINE(351)
							int length = ::Math_obj::floor((slotCount - offsets->__Field(HX_CSTRING("length"),true)));		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(351)
							Array< int > this1;		HX_STACK_VAR(this1,"this1");
							HX_STACK_LINE(351)
							Array< int > _g33 = Array_obj< int >::__new()->__SetSizeExact(length);		HX_STACK_VAR(_g33,"_g33");
							HX_STACK_LINE(351)
							this1 = _g33;
							HX_STACK_LINE(351)
							unchanged = this1;
						}
						HX_STACK_LINE(352)
						int originalIndex = (int)0;		HX_STACK_VAR(originalIndex,"originalIndex");
						HX_STACK_LINE(353)
						int unchangedIndex = (int)0;		HX_STACK_VAR(unchangedIndex,"unchangedIndex");
						HX_STACK_LINE(354)
						{
							HX_STACK_LINE(354)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(354)
							Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(354)
							_g3 = hx::TCastToArray(offsets);
							HX_STACK_LINE(354)
							while((true)){
								HX_STACK_LINE(354)
								if ((!(((_g2 < _g3->__Field(HX_CSTRING("length"),true)))))){
									HX_STACK_LINE(354)
									break;
								}
								HX_STACK_LINE(354)
								Dynamic offsetMap = _g3->__GetItem(_g2);		HX_STACK_VAR(offsetMap,"offsetMap");
								HX_STACK_LINE(354)
								++(_g2);
								HX_STACK_LINE(355)
								::String slotName = ::spinehaxe::JsonUtils_obj::getStr(offsetMap,HX_CSTRING("slot"),null());		HX_STACK_VAR(slotName,"slotName");
								HX_STACK_LINE(356)
								int slotIndex2 = skeletonData->findSlotIndex(slotName);		HX_STACK_VAR(slotIndex2,"slotIndex2");
								HX_STACK_LINE(357)
								if (((slotIndex2 == (int)-1))){
									HX_STACK_LINE(358)
									HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Slot not found: ") + slotName)));
								}
								HX_STACK_LINE(360)
								while((true)){
									HX_STACK_LINE(360)
									if ((!(((originalIndex != slotIndex2))))){
										HX_STACK_LINE(360)
										break;
									}
									HX_STACK_LINE(360)
									int index = (unchangedIndex)++;		HX_STACK_VAR(index,"index");
									HX_STACK_LINE(360)
									int val = (originalIndex)++;		HX_STACK_VAR(val,"val");
									HX_STACK_LINE(360)
									unchanged->__unsafe_set(index,val);
								}
								HX_STACK_LINE(362)
								int offset = ::spinehaxe::JsonUtils_obj::getInt(offsetMap,HX_CSTRING("offset"),null());		HX_STACK_VAR(offset,"offset");
								HX_STACK_LINE(363)
								{
									HX_STACK_LINE(363)
									int val = (originalIndex)++;		HX_STACK_VAR(val,"val");
									HX_STACK_LINE(363)
									drawOrder->__unsafe_set((originalIndex + offset),val);
								}
							}
						}
						HX_STACK_LINE(367)
						while((true)){
							HX_STACK_LINE(367)
							if ((!(((originalIndex < slotCount))))){
								HX_STACK_LINE(367)
								break;
							}
							HX_STACK_LINE(367)
							int index = (unchangedIndex)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(367)
							int val = (originalIndex)++;		HX_STACK_VAR(val,"val");
							HX_STACK_LINE(367)
							unchanged->__unsafe_set(index,val);
						}
						HX_STACK_LINE(369)
						i = (slotCount - (int)1);
						HX_STACK_LINE(370)
						while((true)){
							HX_STACK_LINE(370)
							if ((!(((i >= (int)0))))){
								HX_STACK_LINE(370)
								break;
							}
							HX_STACK_LINE(371)
							int _g34 = drawOrder->__unsafe_get(i);		HX_STACK_VAR(_g34,"_g34");
							HX_STACK_LINE(371)
							if (((_g34 == (int)-1))){
								HX_STACK_LINE(372)
								int val;		HX_STACK_VAR(val,"val");
								HX_STACK_LINE(372)
								{
									HX_STACK_LINE(372)
									int index = --(unchangedIndex);		HX_STACK_VAR(index,"index");
									HX_STACK_LINE(372)
									val = unchanged->__unsafe_get(index);
								}
								HX_STACK_LINE(372)
								drawOrder->__unsafe_set(i,val);
							}
							HX_STACK_LINE(373)
							(i)--;
						}
					}
					HX_STACK_LINE(377)
					Float time = ::spinehaxe::JsonUtils_obj::getFloat(drawOrderMap,HX_CSTRING("time"),null());		HX_STACK_VAR(time,"time");
					HX_STACK_LINE(378)
					int _g35 = (frameIndex5)++;		HX_STACK_VAR(_g35,"_g35");
					HX_STACK_LINE(378)
					timeline5->setFrame(_g35,time,drawOrder);
				}
			}
			HX_STACK_LINE(381)
			timelines->push(timeline5);
			HX_STACK_LINE(382)
			Dynamic _g37;		HX_STACK_VAR(_g37,"_g37");
			HX_STACK_LINE(382)
			{
				HX_STACK_LINE(382)
				int _g36 = timeline5->get_frameCount();		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(382)
				int index = (_g36 - (int)1);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(382)
				_g37 = timeline5->frames->__unsafe_get(index);
			}
			HX_STACK_LINE(382)
			Float _g38 = ::Math_obj::max(duration,_g37);		HX_STACK_VAR(_g38,"_g38");
			HX_STACK_LINE(382)
			duration = _g38;
		}
		HX_STACK_LINE(384)
		::spinehaxe::animation::Animation _g39 = ::spinehaxe::animation::Animation_obj::__new(name,timelines,duration);		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(384)
		skeletonData->addAnimation(_g39);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SkeletonJson_obj,readAnimation,(void))

Void SkeletonJson_obj::readCurve( ::spinehaxe::animation::CurveTimeline timeline,int frameIndex,Dynamic valueMap){
{
		HX_STACK_FRAME("spinehaxe.SkeletonJson","readCurve",0x56e77845,"spinehaxe.SkeletonJson.readCurve","spinehaxe/SkeletonJson.hx",387,0x71d6c3e3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(timeline,"timeline")
		HX_STACK_ARG(frameIndex,"frameIndex")
		HX_STACK_ARG(valueMap,"valueMap")
		HX_STACK_LINE(388)
		Dynamic curve = ::Reflect_obj::field(valueMap,HX_CSTRING("curve"));		HX_STACK_VAR(curve,"curve");
		HX_STACK_LINE(389)
		if (((curve == null()))){
			HX_STACK_LINE(390)
			return null();
		}
		HX_STACK_LINE(391)
		if (((curve == HX_CSTRING("stepped")))){
			HX_STACK_LINE(392)
			timeline->setStepped(frameIndex);
		}
		else{
			HX_STACK_LINE(393)
			if ((::Std_obj::is(curve,hx::ClassOf< Array<int> >()))){
				HX_STACK_LINE(394)
				timeline->setCurve(frameIndex,curve->__GetItem((int)0),curve->__GetItem((int)1),curve->__GetItem((int)2),curve->__GetItem((int)3));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SkeletonJson_obj,readCurve,(void))

::String SkeletonJson_obj::TIMELINE_SCALE;

::String SkeletonJson_obj::TIMELINE_ROTATE;

::String SkeletonJson_obj::TIMELINE_TRANSLATE;

::String SkeletonJson_obj::TIMELINE_ATTACHMENT;

::String SkeletonJson_obj::TIMELINE_COLOR;

::haxe::ds::StringMap SkeletonJson_obj::parsedJson;

::spinehaxe::SkeletonJson SkeletonJson_obj::create( ::spinehaxe::atlas::TextureAtlas atlas){
	HX_STACK_FRAME("spinehaxe.SkeletonJson","create",0x546190b0,"spinehaxe.SkeletonJson.create","spinehaxe/SkeletonJson.hx",73,0x71d6c3e3)
	HX_STACK_ARG(atlas,"atlas")
	HX_STACK_LINE(74)
	::spinehaxe::attachments::AtlasAttachmentLoader _g = ::spinehaxe::attachments::AtlasAttachmentLoader_obj::__new(atlas);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	return ::spinehaxe::SkeletonJson_obj::__new(_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SkeletonJson_obj,create,return )

Float SkeletonJson_obj::toColor( ::String hexString,int colorIndex){
	HX_STACK_FRAME("spinehaxe.SkeletonJson","toColor",0x867311b4,"spinehaxe.SkeletonJson.toColor","spinehaxe/SkeletonJson.hx",398,0x71d6c3e3)
	HX_STACK_ARG(hexString,"hexString")
	HX_STACK_ARG(colorIndex,"colorIndex")
	HX_STACK_LINE(399)
	if (((hexString.length != (int)8))){
		HX_STACK_LINE(400)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Color hexidecimal length must be 8, recieved: ") + hexString)));
	}
	HX_STACK_LINE(401)
	::String _g = hexString.substring((colorIndex * (int)2),((colorIndex * (int)2) + (int)2));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(401)
	::String _g1 = (HX_CSTRING("0x") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(401)
	Dynamic _g2 = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(401)
	return (Float(_g2) / Float((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(SkeletonJson_obj,toColor,return )


SkeletonJson_obj::SkeletonJson_obj()
{
}

void SkeletonJson_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkeletonJson);
	HX_MARK_MEMBER_NAME(attachmentLoader,"attachmentLoader");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_END_CLASS();
}

void SkeletonJson_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(attachmentLoader,"attachmentLoader");
	HX_VISIT_MEMBER_NAME(scale,"scale");
}

Dynamic SkeletonJson_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toColor") ) { return toColor_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readCurve") ) { return readCurve_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parsedJson") ) { return parsedJson; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readAnimation") ) { return readAnimation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"readAttachment") ) { return readAttachment_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"attachmentLoader") ) { return attachmentLoader; }
		if (HX_FIELD_EQ(inName,"readSkeletonData") ) { return readSkeletonData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkeletonJson_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parsedJson") ) { parsedJson=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"attachmentLoader") ) { attachmentLoader=inValue.Cast< ::spinehaxe::attachments::AttachmentLoader >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkeletonJson_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("attachmentLoader"));
	outFields->push(HX_CSTRING("scale"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TIMELINE_SCALE"),
	HX_CSTRING("TIMELINE_ROTATE"),
	HX_CSTRING("TIMELINE_TRANSLATE"),
	HX_CSTRING("TIMELINE_ATTACHMENT"),
	HX_CSTRING("TIMELINE_COLOR"),
	HX_CSTRING("parsedJson"),
	HX_CSTRING("create"),
	HX_CSTRING("toColor"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::attachments::AttachmentLoader*/ ,(int)offsetof(SkeletonJson_obj,attachmentLoader),HX_CSTRING("attachmentLoader")},
	{hx::fsFloat,(int)offsetof(SkeletonJson_obj,scale),HX_CSTRING("scale")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("attachmentLoader"),
	HX_CSTRING("scale"),
	HX_CSTRING("readSkeletonData"),
	HX_CSTRING("readAttachment"),
	HX_CSTRING("readAnimation"),
	HX_CSTRING("readCurve"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::TIMELINE_SCALE,"TIMELINE_SCALE");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::TIMELINE_ROTATE,"TIMELINE_ROTATE");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::TIMELINE_TRANSLATE,"TIMELINE_TRANSLATE");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::TIMELINE_ATTACHMENT,"TIMELINE_ATTACHMENT");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::TIMELINE_COLOR,"TIMELINE_COLOR");
	HX_MARK_MEMBER_NAME(SkeletonJson_obj::parsedJson,"parsedJson");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::TIMELINE_SCALE,"TIMELINE_SCALE");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::TIMELINE_ROTATE,"TIMELINE_ROTATE");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::TIMELINE_TRANSLATE,"TIMELINE_TRANSLATE");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::TIMELINE_ATTACHMENT,"TIMELINE_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::TIMELINE_COLOR,"TIMELINE_COLOR");
	HX_VISIT_MEMBER_NAME(SkeletonJson_obj::parsedJson,"parsedJson");
};

#endif

Class SkeletonJson_obj::__mClass;

void SkeletonJson_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.SkeletonJson"), hx::TCanCast< SkeletonJson_obj> ,sStaticFields,sMemberFields,
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

void SkeletonJson_obj::__boot()
{
	TIMELINE_SCALE= HX_CSTRING("scale");
	TIMELINE_ROTATE= HX_CSTRING("rotate");
	TIMELINE_TRANSLATE= HX_CSTRING("translate");
	TIMELINE_ATTACHMENT= HX_CSTRING("attachment");
	TIMELINE_COLOR= HX_CSTRING("color");
	parsedJson= ::haxe::ds::StringMap_obj::__new();
}

} // end namespace spinehaxe
