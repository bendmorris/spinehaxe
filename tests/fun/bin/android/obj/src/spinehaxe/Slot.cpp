#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
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

Void Slot_obj::__construct(::spinehaxe::SlotData data,::spinehaxe::Skeleton skeleton,::spinehaxe::Bone bone)
{
HX_STACK_FRAME("spinehaxe.Slot","new",0xe0ce9d15,"spinehaxe.Slot.new","spinehaxe/Slot.hx",36,0x85f8ce1a)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
HX_STACK_ARG(skeleton,"skeleton")
HX_STACK_ARG(bone,"bone")
{
	HX_STACK_LINE(48)
	this->attachmentVertices = Array_obj< Float >::__new();
	HX_STACK_LINE(51)
	if (((data == null()))){
		HX_STACK_LINE(52)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("data cannot be null.")));
	}
	HX_STACK_LINE(53)
	if (((skeleton == null()))){
		HX_STACK_LINE(54)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("skeleton cannot be null.")));
	}
	HX_STACK_LINE(55)
	if (((bone == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("bone cannot be null.")));
	}
	HX_STACK_LINE(57)
	this->data = data;
	HX_STACK_LINE(58)
	this->skeleton = skeleton;
	HX_STACK_LINE(59)
	this->bone = bone;
	HX_STACK_LINE(60)
	this->setToSetupPose();
}
;
	return null();
}

//Slot_obj::~Slot_obj() { }

Dynamic Slot_obj::__CreateEmpty() { return  new Slot_obj; }
hx::ObjectPtr< Slot_obj > Slot_obj::__new(::spinehaxe::SlotData data,::spinehaxe::Skeleton skeleton,::spinehaxe::Bone bone)
{  hx::ObjectPtr< Slot_obj > result = new Slot_obj();
	result->__construct(data,skeleton,bone);
	return result;}

Dynamic Slot_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slot_obj > result = new Slot_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::spinehaxe::attachments::Attachment Slot_obj::set_attachment( ::spinehaxe::attachments::Attachment attachment){
	HX_STACK_FRAME("spinehaxe.Slot","set_attachment",0xd901ae0b,"spinehaxe.Slot.set_attachment","spinehaxe/Slot.hx",65,0x85f8ce1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(attachment,"attachment")
	HX_STACK_LINE(66)
	this->attachment = attachment;
	HX_STACK_LINE(67)
	this->_attachmentTime = this->skeleton->time;
	HX_STACK_LINE(68)
	this->attachmentVertices->splice((int)0,this->attachmentVertices->length);
	HX_STACK_LINE(69)
	return attachment;
}


HX_DEFINE_DYNAMIC_FUNC1(Slot_obj,set_attachment,return )

Float Slot_obj::set_attachmentTime( Float time){
	HX_STACK_FRAME("spinehaxe.Slot","set_attachmentTime",0x33af07b8,"spinehaxe.Slot.set_attachmentTime","spinehaxe/Slot.hx",72,0x85f8ce1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(time,"time")
	HX_STACK_LINE(73)
	this->_attachmentTime = (this->skeleton->time - time);
	HX_STACK_LINE(74)
	return time;
}


HX_DEFINE_DYNAMIC_FUNC1(Slot_obj,set_attachmentTime,return )

Float Slot_obj::get_attachmentTime( ){
	HX_STACK_FRAME("spinehaxe.Slot","get_attachmentTime",0x56ffd544,"spinehaxe.Slot.get_attachmentTime","spinehaxe/Slot.hx",79,0x85f8ce1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(79)
	return (this->skeleton->time - this->_attachmentTime);
}


HX_DEFINE_DYNAMIC_FUNC0(Slot_obj,get_attachmentTime,return )

Void Slot_obj::setToSetupPose( ){
{
		HX_STACK_FRAME("spinehaxe.Slot","setToSetupPose",0x1907c55c,"spinehaxe.Slot.setToSetupPose","spinehaxe/Slot.hx",82,0x85f8ce1a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		int slotIndex = ::spinehaxe::ArrayUtils_obj::indexOf(this->skeleton->data->slots,this->data);		HX_STACK_VAR(slotIndex,"slotIndex");
		HX_STACK_LINE(84)
		this->r = this->data->r;
		HX_STACK_LINE(85)
		this->g = this->data->g;
		HX_STACK_LINE(86)
		this->b = this->data->b;
		HX_STACK_LINE(87)
		this->a = this->data->a;
		HX_STACK_LINE(88)
		::spinehaxe::attachments::Attachment _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		if (((this->data->attachmentName == null()))){
			HX_STACK_LINE(88)
			_g = null();
		}
		else{
			HX_STACK_LINE(88)
			_g = this->skeleton->getAttachmentForSlotIndex(slotIndex,this->data->attachmentName);
		}
		HX_STACK_LINE(88)
		this->set_attachment(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Slot_obj,setToSetupPose,(void))

::String Slot_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Slot","toString",0x89e8d3d7,"spinehaxe.Slot.toString","spinehaxe/Slot.hx",92,0x85f8ce1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(92)
	return this->data->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Slot_obj,toString,return )


Slot_obj::Slot_obj()
{
}

void Slot_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Slot);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(skeleton,"skeleton");
	HX_MARK_MEMBER_NAME(bone,"bone");
	HX_MARK_MEMBER_NAME(attachment,"attachment");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(_attachmentTime,"_attachmentTime");
	HX_MARK_MEMBER_NAME(attachmentVertices,"attachmentVertices");
	HX_MARK_END_CLASS();
}

void Slot_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(skeleton,"skeleton");
	HX_VISIT_MEMBER_NAME(bone,"bone");
	HX_VISIT_MEMBER_NAME(attachment,"attachment");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(g,"g");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(_attachmentTime,"_attachmentTime");
	HX_VISIT_MEMBER_NAME(attachmentVertices,"attachmentVertices");
}

Dynamic Slot_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"bone") ) { return bone; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skeleton") ) { return skeleton; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"attachment") ) { return attachment; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"attachmentTime") ) { return get_attachmentTime(); }
		if (HX_FIELD_EQ(inName,"set_attachment") ) { return set_attachment_dyn(); }
		if (HX_FIELD_EQ(inName,"setToSetupPose") ) { return setToSetupPose_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_attachmentTime") ) { return _attachmentTime; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"attachmentVertices") ) { return attachmentVertices; }
		if (HX_FIELD_EQ(inName,"set_attachmentTime") ) { return set_attachmentTime_dyn(); }
		if (HX_FIELD_EQ(inName,"get_attachmentTime") ) { return get_attachmentTime_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slot_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::spinehaxe::SlotData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bone") ) { bone=inValue.Cast< ::spinehaxe::Bone >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skeleton") ) { skeleton=inValue.Cast< ::spinehaxe::Skeleton >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"attachment") ) { if (inCallProp) return set_attachment(inValue);attachment=inValue.Cast< ::spinehaxe::attachments::Attachment >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"attachmentTime") ) { return set_attachmentTime(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_attachmentTime") ) { _attachmentTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"attachmentVertices") ) { attachmentVertices=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Slot_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("skeleton"));
	outFields->push(HX_CSTRING("bone"));
	outFields->push(HX_CSTRING("attachment"));
	outFields->push(HX_CSTRING("attachmentTime"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("_attachmentTime"));
	outFields->push(HX_CSTRING("attachmentVertices"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::SlotData*/ ,(int)offsetof(Slot_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*::spinehaxe::Skeleton*/ ,(int)offsetof(Slot_obj,skeleton),HX_CSTRING("skeleton")},
	{hx::fsObject /*::spinehaxe::Bone*/ ,(int)offsetof(Slot_obj,bone),HX_CSTRING("bone")},
	{hx::fsObject /*::spinehaxe::attachments::Attachment*/ ,(int)offsetof(Slot_obj,attachment),HX_CSTRING("attachment")},
	{hx::fsFloat,(int)offsetof(Slot_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(Slot_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(Slot_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(Slot_obj,a),HX_CSTRING("a")},
	{hx::fsFloat,(int)offsetof(Slot_obj,_attachmentTime),HX_CSTRING("_attachmentTime")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Slot_obj,attachmentVertices),HX_CSTRING("attachmentVertices")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("skeleton"),
	HX_CSTRING("bone"),
	HX_CSTRING("attachment"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("_attachmentTime"),
	HX_CSTRING("attachmentVertices"),
	HX_CSTRING("set_attachment"),
	HX_CSTRING("set_attachmentTime"),
	HX_CSTRING("get_attachmentTime"),
	HX_CSTRING("setToSetupPose"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slot_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slot_obj::__mClass,"__mClass");
};

#endif

Class Slot_obj::__mClass;

void Slot_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Slot"), hx::TCanCast< Slot_obj> ,sStaticFields,sMemberFields,
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

void Slot_obj::__boot()
{
}

} // end namespace spinehaxe
