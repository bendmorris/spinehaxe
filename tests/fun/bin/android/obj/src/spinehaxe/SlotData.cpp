#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_SlotData
#include <spinehaxe/SlotData.h>
#endif
namespace spinehaxe{

Void SlotData_obj::__construct(::String name,::spinehaxe::BoneData boneData)
{
HX_STACK_FRAME("spinehaxe.SlotData","new",0xa14f59df,"spinehaxe.SlotData.new","spinehaxe/SlotData.hx",44,0x1ee23410)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
HX_STACK_ARG(boneData,"boneData")
{
	HX_STACK_LINE(45)
	this->r = (int)1;
	HX_STACK_LINE(46)
	this->g = (int)1;
	HX_STACK_LINE(47)
	this->b = (int)1;
	HX_STACK_LINE(48)
	this->a = (int)1;
	HX_STACK_LINE(49)
	if (((name == null()))){
		HX_STACK_LINE(50)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(51)
	if (((boneData == null()))){
		HX_STACK_LINE(52)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("boneData cannot be null.")));
	}
	HX_STACK_LINE(53)
	this->name = name;
	HX_STACK_LINE(54)
	this->boneData = boneData;
}
;
	return null();
}

//SlotData_obj::~SlotData_obj() { }

Dynamic SlotData_obj::__CreateEmpty() { return  new SlotData_obj; }
hx::ObjectPtr< SlotData_obj > SlotData_obj::__new(::String name,::spinehaxe::BoneData boneData)
{  hx::ObjectPtr< SlotData_obj > result = new SlotData_obj();
	result->__construct(name,boneData);
	return result;}

Dynamic SlotData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SlotData_obj > result = new SlotData_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String SlotData_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.SlotData","toString",0xd5557acd,"spinehaxe.SlotData.toString","spinehaxe/SlotData.hx",58,0x1ee23410)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(SlotData_obj,toString,return )


SlotData_obj::SlotData_obj()
{
}

void SlotData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SlotData);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(boneData,"boneData");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(attachmentName,"attachmentName");
	HX_MARK_MEMBER_NAME(additiveBlending,"additiveBlending");
	HX_MARK_END_CLASS();
}

void SlotData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(boneData,"boneData");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(g,"g");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(attachmentName,"attachmentName");
	HX_VISIT_MEMBER_NAME(additiveBlending,"additiveBlending");
}

Dynamic SlotData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"boneData") ) { return boneData; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"attachmentName") ) { return attachmentName; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"additiveBlending") ) { return additiveBlending; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SlotData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"boneData") ) { boneData=inValue.Cast< ::spinehaxe::BoneData >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"attachmentName") ) { attachmentName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"additiveBlending") ) { additiveBlending=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SlotData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("boneData"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("attachmentName"));
	outFields->push(HX_CSTRING("additiveBlending"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(SlotData_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::spinehaxe::BoneData*/ ,(int)offsetof(SlotData_obj,boneData),HX_CSTRING("boneData")},
	{hx::fsFloat,(int)offsetof(SlotData_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(SlotData_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(SlotData_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(SlotData_obj,a),HX_CSTRING("a")},
	{hx::fsString,(int)offsetof(SlotData_obj,attachmentName),HX_CSTRING("attachmentName")},
	{hx::fsBool,(int)offsetof(SlotData_obj,additiveBlending),HX_CSTRING("additiveBlending")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("boneData"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("attachmentName"),
	HX_CSTRING("additiveBlending"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SlotData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SlotData_obj::__mClass,"__mClass");
};

#endif

Class SlotData_obj::__mClass;

void SlotData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.SlotData"), hx::TCanCast< SlotData_obj> ,sStaticFields,sMemberFields,
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

void SlotData_obj::__boot()
{
}

} // end namespace spinehaxe
