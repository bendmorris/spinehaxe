#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
namespace spinehaxe{
namespace attachments{

Void Attachment_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.attachments.Attachment","new",0x85588638,"spinehaxe.attachments.Attachment.new","spinehaxe/attachments/Attachment.hx",32,0x8be8e176)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(33)
	if (((name == null()))){
		HX_STACK_LINE(33)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(34)
	this->name = name;
}
;
	return null();
}

//Attachment_obj::~Attachment_obj() { }

Dynamic Attachment_obj::__CreateEmpty() { return  new Attachment_obj; }
hx::ObjectPtr< Attachment_obj > Attachment_obj::__new(::String name)
{  hx::ObjectPtr< Attachment_obj > result = new Attachment_obj();
	result->__construct(name);
	return result;}

Dynamic Attachment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Attachment_obj > result = new Attachment_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Attachment_obj::getName( ){
	HX_STACK_FRAME("spinehaxe.attachments.Attachment","getName",0x5812a3d9,"spinehaxe.attachments.Attachment.getName","spinehaxe/attachments/Attachment.hx",38,0x8be8e176)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Attachment_obj,getName,return )

::String Attachment_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.attachments.Attachment","toString",0xfa4febd4,"spinehaxe.attachments.Attachment.toString","spinehaxe/attachments/Attachment.hx",42,0x8be8e176)
	HX_STACK_THIS(this)
	HX_STACK_LINE(42)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Attachment_obj,toString,return )


Attachment_obj::Attachment_obj()
{
}

void Attachment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Attachment);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

void Attachment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
}

Dynamic Attachment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getName") ) { return getName_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Attachment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Attachment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Attachment_obj,name),HX_CSTRING("name")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("getName"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Attachment_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Attachment_obj::__mClass,"__mClass");
};

#endif

Class Attachment_obj::__mClass;

void Attachment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.Attachment"), hx::TCanCast< Attachment_obj> ,sStaticFields,sMemberFields,
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

void Attachment_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
