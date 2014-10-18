#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skin
#include <spinehaxe/Skin.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_AtlasRegion
#include <spinehaxe/atlas/AtlasRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlas
#include <spinehaxe/atlas/TextureAtlas.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
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
#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#include <spinehaxe/attachments/RegionAttachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionSequenceAttachment
#include <spinehaxe/attachments/RegionSequenceAttachment.h>
#endif
namespace spinehaxe{
namespace attachments{

Void AtlasAttachmentLoader_obj::__construct(::spinehaxe::atlas::TextureAtlas atlas)
{
HX_STACK_FRAME("spinehaxe.attachments.AtlasAttachmentLoader","new",0x6475fa30,"spinehaxe.attachments.AtlasAttachmentLoader.new","spinehaxe/attachments/AtlasAttachmentLoader.hx",34,0x9959cec2)
HX_STACK_THIS(this)
HX_STACK_ARG(atlas,"atlas")
{
	HX_STACK_LINE(35)
	if (((atlas == null()))){
		HX_STACK_LINE(35)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("atlas cannot be null.")));
	}
	HX_STACK_LINE(36)
	this->atlas = atlas;
}
;
	return null();
}

//AtlasAttachmentLoader_obj::~AtlasAttachmentLoader_obj() { }

Dynamic AtlasAttachmentLoader_obj::__CreateEmpty() { return  new AtlasAttachmentLoader_obj; }
hx::ObjectPtr< AtlasAttachmentLoader_obj > AtlasAttachmentLoader_obj::__new(::spinehaxe::atlas::TextureAtlas atlas)
{  hx::ObjectPtr< AtlasAttachmentLoader_obj > result = new AtlasAttachmentLoader_obj();
	result->__construct(atlas);
	return result;}

Dynamic AtlasAttachmentLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AtlasAttachmentLoader_obj > result = new AtlasAttachmentLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *AtlasAttachmentLoader_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::spinehaxe::attachments::AttachmentLoader_obj)) return operator ::spinehaxe::attachments::AttachmentLoader_obj *();
	return super::__ToInterface(inType);
}

::spinehaxe::attachments::Attachment AtlasAttachmentLoader_obj::newAttachment( ::spinehaxe::Skin skin,::spinehaxe::attachments::AttachmentType type,::String name){
	HX_STACK_FRAME("spinehaxe.attachments.AtlasAttachmentLoader","newAttachment",0x9b4aa233,"spinehaxe.attachments.AtlasAttachmentLoader.newAttachment","spinehaxe/attachments/AtlasAttachmentLoader.hx",39,0x9959cec2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(skin,"skin")
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(40)
	::spinehaxe::attachments::Attachment attachment = null();		HX_STACK_VAR(attachment,"attachment");
	HX_STACK_LINE(41)
	switch( (int)(type->__Index())){
		case (int)0: {
			HX_STACK_LINE(43)
			::spinehaxe::attachments::RegionAttachment _g = ::spinehaxe::attachments::RegionAttachment_obj::__new(name);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(43)
			attachment = _g;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(45)
			::spinehaxe::attachments::RegionSequenceAttachment _g1 = ::spinehaxe::attachments::RegionSequenceAttachment_obj::__new(name);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			attachment = _g1;
		}
		;break;
		default: {
			HX_STACK_LINE(47)
			::String _g2 = ::Std_obj::string(type);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(47)
			::String _g3 = (HX_CSTRING("Unknown attachment type: ") + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(47)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(_g3));
		}
	}
	HX_STACK_LINE(50)
	if ((::Std_obj::is(attachment,hx::ClassOf< ::spinehaxe::attachments::RegionAttachment >()))){
		HX_STACK_LINE(51)
		::spinehaxe::atlas::AtlasRegion region = this->atlas->findRegion(attachment->name);		HX_STACK_VAR(region,"region");
		HX_STACK_LINE(52)
		if (((region == null()))){
			HX_STACK_LINE(53)
			::String _g4 = ::Std_obj::string(attachment);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(53)
			::String _g5 = (HX_CSTRING("Region not found in atlas: ") + _g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(53)
			::String _g6 = (_g5 + HX_CSTRING(" ("));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(53)
			::String _g7 = ::Std_obj::string(type);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(53)
			::String _g8 = (_g6 + _g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(53)
			::String _g9 = (_g8 + HX_CSTRING(" attachment: "));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(53)
			::String _g10 = (_g9 + name);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(53)
			::String _g11 = (_g10 + HX_CSTRING(")"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(53)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(_g11));
		}
		HX_STACK_LINE(54)
		(hx::TCast< spinehaxe::attachments::RegionAttachment >::cast(attachment))->setRegion(region);
	}
	HX_STACK_LINE(57)
	return attachment;
}


HX_DEFINE_DYNAMIC_FUNC3(AtlasAttachmentLoader_obj,newAttachment,return )


AtlasAttachmentLoader_obj::AtlasAttachmentLoader_obj()
{
}

void AtlasAttachmentLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AtlasAttachmentLoader);
	HX_MARK_MEMBER_NAME(atlas,"atlas");
	HX_MARK_END_CLASS();
}

void AtlasAttachmentLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(atlas,"atlas");
}

Dynamic AtlasAttachmentLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { return atlas; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"newAttachment") ) { return newAttachment_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AtlasAttachmentLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { atlas=inValue.Cast< ::spinehaxe::atlas::TextureAtlas >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AtlasAttachmentLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("atlas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::atlas::TextureAtlas*/ ,(int)offsetof(AtlasAttachmentLoader_obj,atlas),HX_CSTRING("atlas")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("atlas"),
	HX_CSTRING("newAttachment"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AtlasAttachmentLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AtlasAttachmentLoader_obj::__mClass,"__mClass");
};

#endif

Class AtlasAttachmentLoader_obj::__mClass;

void AtlasAttachmentLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.AtlasAttachmentLoader"), hx::TCanCast< AtlasAttachmentLoader_obj> ,sStaticFields,sMemberFields,
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

void AtlasAttachmentLoader_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
