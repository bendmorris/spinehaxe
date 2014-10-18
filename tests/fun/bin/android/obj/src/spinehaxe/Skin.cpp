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
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_Skin
#include <spinehaxe/Skin.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
namespace spinehaxe{

Void Skin_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.Skin","new",0xdcad8114,"spinehaxe.Skin.new","spinehaxe/Skin.hx",40,0xa73eaefb)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(41)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	this->attachments = _g;
	HX_STACK_LINE(42)
	if (((name == null()))){
		HX_STACK_LINE(43)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(44)
	this->name = name;
}
;
	return null();
}

//Skin_obj::~Skin_obj() { }

Dynamic Skin_obj::__CreateEmpty() { return  new Skin_obj; }
hx::ObjectPtr< Skin_obj > Skin_obj::__new(::String name)
{  hx::ObjectPtr< Skin_obj > result = new Skin_obj();
	result->__construct(name);
	return result;}

Dynamic Skin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Skin_obj > result = new Skin_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Skin_obj::addAttachment( int slotIndex,::String name,::spinehaxe::attachments::Attachment attachment){
{
		HX_STACK_FRAME("spinehaxe.Skin","addAttachment",0xf3756b18,"spinehaxe.Skin.addAttachment","spinehaxe/Skin.hx",47,0xa73eaefb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(slotIndex,"slotIndex")
		HX_STACK_ARG(name,"name")
		HX_STACK_ARG(attachment,"attachment")
		HX_STACK_LINE(48)
		if (((attachment == null()))){
			HX_STACK_LINE(49)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("attachment cannot be null.")));
		}
		HX_STACK_LINE(50)
		{
			HX_STACK_LINE(50)
			this->attachments->set(((slotIndex + HX_CSTRING(":")) + name),attachment);
			HX_STACK_LINE(50)
			attachment;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Skin_obj,addAttachment,(void))

::spinehaxe::attachments::Attachment Skin_obj::getAttachment( int slotIndex,::String name){
	HX_STACK_FRAME("spinehaxe.Skin","getAttachment",0xe59e7dcd,"spinehaxe.Skin.getAttachment","spinehaxe/Skin.hx",54,0xa73eaefb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slotIndex,"slotIndex")
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(54)
	return this->attachments->get(((slotIndex + HX_CSTRING(":")) + name));
}


HX_DEFINE_DYNAMIC_FUNC2(Skin_obj,getAttachment,return )

::String Skin_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Skin","toString",0xc1341378,"spinehaxe.Skin.toString","spinehaxe/Skin.hx",58,0xa73eaefb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Skin_obj,toString,return )

Void Skin_obj::attachAll( ::spinehaxe::Skeleton skeleton,::spinehaxe::Skin oldSkin){
{
		HX_STACK_FRAME("spinehaxe.Skin","attachAll",0xe21cce10,"spinehaxe.Skin.attachAll","spinehaxe/Skin.hx",62,0xa73eaefb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_ARG(oldSkin,"oldSkin")
		HX_STACK_LINE(62)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(62)
		Array< ::String > _g1 = ::Reflect_obj::fields(oldSkin->attachments);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		while((true)){
			HX_STACK_LINE(62)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(62)
				break;
			}
			HX_STACK_LINE(62)
			::String key = _g1->__get(_g);		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(62)
			++(_g);
			HX_STACK_LINE(63)
			int colon = key.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(colon,"colon");
			HX_STACK_LINE(64)
			::String _g2 = key.substring((int)0,colon);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(64)
			int slotIndex = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(slotIndex,"slotIndex");
			HX_STACK_LINE(65)
			::String name = key.substring((colon + (int)1),null());		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(66)
			::spinehaxe::Slot slot = skeleton->slots->__get(slotIndex).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
			HX_STACK_LINE(67)
			if (((bool((slot->attachment != null())) && bool((slot->attachment->name == name))))){
				HX_STACK_LINE(68)
				::spinehaxe::attachments::Attachment attachment = this->getAttachment(slotIndex,name);		HX_STACK_VAR(attachment,"attachment");
				HX_STACK_LINE(69)
				if (((attachment != null()))){
					HX_STACK_LINE(70)
					slot->set_attachment(attachment);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Skin_obj,attachAll,(void))


Skin_obj::Skin_obj()
{
}

void Skin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Skin);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(attachments,"attachments");
	HX_MARK_END_CLASS();
}

void Skin_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(attachments,"attachments");
}

Dynamic Skin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"attachAll") ) { return attachAll_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"attachments") ) { return attachments; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"addAttachment") ) { return addAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttachment") ) { return getAttachment_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Skin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"attachments") ) { attachments=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Skin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("attachments"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Skin_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Skin_obj,attachments),HX_CSTRING("attachments")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("attachments"),
	HX_CSTRING("addAttachment"),
	HX_CSTRING("getAttachment"),
	HX_CSTRING("toString"),
	HX_CSTRING("attachAll"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Skin_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Skin_obj::__mClass,"__mClass");
};

#endif

Class Skin_obj::__mClass;

void Skin_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Skin"), hx::TCanCast< Skin_obj> ,sStaticFields,sMemberFields,
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

void Skin_obj::__boot()
{
}

} // end namespace spinehaxe
