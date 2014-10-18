#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_Color
#include <spinehaxe/Color.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
namespace spinehaxe{

Void BoneData_obj::__construct(::String name,::spinehaxe::BoneData parent)
{
HX_STACK_FRAME("spinehaxe.BoneData","new",0xa9c4b525,"spinehaxe.BoneData.new","spinehaxe/BoneData.hx",35,0xa416638a)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
HX_STACK_ARG(parent,"parent")
{
	HX_STACK_LINE(51)
	this->color = ::spinehaxe::Color_obj::__new(0.61,0.61,0.61,(int)1);
	HX_STACK_LINE(55)
	if (((name == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("name cannot be null.")));
	}
	HX_STACK_LINE(57)
	this->scaleX = (int)1;
	HX_STACK_LINE(58)
	this->scaleY = (int)1;
	HX_STACK_LINE(59)
	this->inheritScale = true;
	HX_STACK_LINE(60)
	this->inheritRotation = true;
	HX_STACK_LINE(61)
	this->name = name;
	HX_STACK_LINE(62)
	this->parent = parent;
}
;
	return null();
}

//BoneData_obj::~BoneData_obj() { }

Dynamic BoneData_obj::__CreateEmpty() { return  new BoneData_obj; }
hx::ObjectPtr< BoneData_obj > BoneData_obj::__new(::String name,::spinehaxe::BoneData parent)
{  hx::ObjectPtr< BoneData_obj > result = new BoneData_obj();
	result->__construct(name,parent);
	return result;}

Dynamic BoneData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoneData_obj > result = new BoneData_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String BoneData_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.BoneData","toString",0x7b9181c7,"spinehaxe.BoneData.toString","spinehaxe/BoneData.hx",82,0xa416638a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(BoneData_obj,toString,return )

::spinehaxe::Color BoneData_obj::getColor( ){
	HX_STACK_FRAME("spinehaxe.BoneData","getColor",0xed563208,"spinehaxe.BoneData.getColor","spinehaxe/BoneData.hx",86,0xa416638a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(86)
	return this->color;
}


HX_DEFINE_DYNAMIC_FUNC0(BoneData_obj,getColor,return )


BoneData_obj::BoneData_obj()
{
}

void BoneData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoneData);
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(inheritScale,"inheritScale");
	HX_MARK_MEMBER_NAME(inheritRotation,"inheritRotation");
	HX_MARK_MEMBER_NAME(flipX,"flipX");
	HX_MARK_MEMBER_NAME(flipY,"flipY");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_END_CLASS();
}

void BoneData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(inheritScale,"inheritScale");
	HX_VISIT_MEMBER_NAME(inheritRotation,"inheritRotation");
	HX_VISIT_MEMBER_NAME(flipX,"flipX");
	HX_VISIT_MEMBER_NAME(flipY,"flipY");
	HX_VISIT_MEMBER_NAME(color,"color");
}

Dynamic BoneData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flipX") ) { return flipX; }
		if (HX_FIELD_EQ(inName,"flipY") ) { return flipY; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"getColor") ) { return getColor_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"inheritScale") ) { return inheritScale; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"inheritRotation") ) { return inheritRotation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoneData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flipX") ) { flipX=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flipY") ) { flipY=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::spinehaxe::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::spinehaxe::BoneData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"inheritScale") ) { inheritScale=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"inheritRotation") ) { inheritRotation=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoneData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("inheritScale"));
	outFields->push(HX_CSTRING("inheritRotation"));
	outFields->push(HX_CSTRING("flipX"));
	outFields->push(HX_CSTRING("flipY"));
	outFields->push(HX_CSTRING("color"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::BoneData*/ ,(int)offsetof(BoneData_obj,parent),HX_CSTRING("parent")},
	{hx::fsString,(int)offsetof(BoneData_obj,name),HX_CSTRING("name")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,length),HX_CSTRING("length")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,scaleX),HX_CSTRING("scaleX")},
	{hx::fsFloat,(int)offsetof(BoneData_obj,scaleY),HX_CSTRING("scaleY")},
	{hx::fsBool,(int)offsetof(BoneData_obj,inheritScale),HX_CSTRING("inheritScale")},
	{hx::fsBool,(int)offsetof(BoneData_obj,inheritRotation),HX_CSTRING("inheritRotation")},
	{hx::fsBool,(int)offsetof(BoneData_obj,flipX),HX_CSTRING("flipX")},
	{hx::fsBool,(int)offsetof(BoneData_obj,flipY),HX_CSTRING("flipY")},
	{hx::fsObject /*::spinehaxe::Color*/ ,(int)offsetof(BoneData_obj,color),HX_CSTRING("color")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("parent"),
	HX_CSTRING("name"),
	HX_CSTRING("length"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("rotation"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("inheritScale"),
	HX_CSTRING("inheritRotation"),
	HX_CSTRING("flipX"),
	HX_CSTRING("flipY"),
	HX_CSTRING("color"),
	HX_CSTRING("toString"),
	HX_CSTRING("getColor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoneData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoneData_obj::__mClass,"__mClass");
};

#endif

Class BoneData_obj::__mClass;

void BoneData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.BoneData"), hx::TCanCast< BoneData_obj> ,sStaticFields,sMemberFields,
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

void BoneData_obj::__boot()
{
}

} // end namespace spinehaxe
