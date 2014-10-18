#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_spinehaxe_JsonUtils
#include <spinehaxe/JsonUtils.h>
#endif
namespace spinehaxe{

Void JsonUtils_obj::__construct()
{
	return null();
}

//JsonUtils_obj::~JsonUtils_obj() { }

Dynamic JsonUtils_obj::__CreateEmpty() { return  new JsonUtils_obj; }
hx::ObjectPtr< JsonUtils_obj > JsonUtils_obj::__new()
{  hx::ObjectPtr< JsonUtils_obj > result = new JsonUtils_obj();
	result->__construct();
	return result;}

Dynamic JsonUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JsonUtils_obj > result = new JsonUtils_obj();
	result->__construct();
	return result;}

Dynamic JsonUtils_obj::parse( ::String data){
	HX_STACK_FRAME("spinehaxe.JsonUtils","parse",0xeb9adc69,"spinehaxe.JsonUtils.parse","spinehaxe/JsonUtils.hx",10,0x2b196e9b)
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(10)
	return ::haxe::format::JsonParser_obj::__new(data)->parseRec();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonUtils_obj,parse,return )

Array< ::String > JsonUtils_obj::fields( Dynamic node){
	HX_STACK_FRAME("spinehaxe.JsonUtils","fields",0xceebf183,"spinehaxe.JsonUtils.fields","spinehaxe/JsonUtils.hx",14,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_LINE(14)
	return ::Reflect_obj::fields(node);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonUtils_obj,fields,return )

Dynamic JsonUtils_obj::getNode( Dynamic node,::String field){
	HX_STACK_FRAME("spinehaxe.JsonUtils","getNode",0x5ee5ff6e,"spinehaxe.JsonUtils.getNode","spinehaxe/JsonUtils.hx",18,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_LINE(18)
	return (  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(JsonUtils_obj,getNode,return )

Dynamic JsonUtils_obj::getDynamic( Dynamic node,::String field){
	HX_STACK_FRAME("spinehaxe.JsonUtils","getDynamic",0x33c3d593,"spinehaxe.JsonUtils.getDynamic","spinehaxe/JsonUtils.hx",22,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_LINE(22)
	return (  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(JsonUtils_obj,getDynamic,return )

Dynamic JsonUtils_obj::getNodesArray( Dynamic node,::String field){
	HX_STACK_FRAME("spinehaxe.JsonUtils","getNodesArray",0x8befa214,"spinehaxe.JsonUtils.getNodesArray","spinehaxe/JsonUtils.hx",26,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_LINE(26)
	return hx::TCastToArray((  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(JsonUtils_obj,getNodesArray,return )

int JsonUtils_obj::getInt( Dynamic node,::String field,hx::Null< int >  __o_defaultValue){
int defaultValue = __o_defaultValue.Default(0);
	HX_STACK_FRAME("spinehaxe.JsonUtils","getInt",0xf17ca903,"spinehaxe.JsonUtils.getInt","spinehaxe/JsonUtils.hx",29,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_ARG(defaultValue,"defaultValue")
{
		HX_STACK_LINE(30)
		Dynamic value;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(30)
		value = (  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) );
		HX_STACK_LINE(31)
		if (((value == null()))){
			HX_STACK_LINE(31)
			return defaultValue;
		}
		HX_STACK_LINE(32)
		return hx::TCast< Int >::cast(value);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonUtils_obj,getInt,return )

Float JsonUtils_obj::getFloat( Dynamic node,::String field,hx::Null< Float >  __o_defaultValue){
Float defaultValue = __o_defaultValue.Default(0);
	HX_STACK_FRAME("spinehaxe.JsonUtils","getFloat",0x0d318eb0,"spinehaxe.JsonUtils.getFloat","spinehaxe/JsonUtils.hx",35,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_ARG(defaultValue,"defaultValue")
{
		HX_STACK_LINE(36)
		Dynamic value = ::spinehaxe::JsonUtils_obj::getDynamic(node,field);		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(37)
		if (((value == null()))){
			HX_STACK_LINE(37)
			return defaultValue;
		}
		HX_STACK_LINE(38)
		if ((::Std_obj::is(value,hx::ClassOf< ::Int >()))){
			HX_STACK_LINE(38)
			return hx::TCast< Int >::cast(value);
		}
		HX_STACK_LINE(39)
		return hx::TCast< Float >::cast(value);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonUtils_obj,getFloat,return )

::String JsonUtils_obj::getStr( Dynamic node,::String field,::String defaultValue){
	HX_STACK_FRAME("spinehaxe.JsonUtils","getStr",0xf18444c5,"spinehaxe.JsonUtils.getStr","spinehaxe/JsonUtils.hx",42,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_ARG(defaultValue,"defaultValue")
	HX_STACK_LINE(43)
	Dynamic value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(43)
	value = (  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) );
	HX_STACK_LINE(44)
	if (((value == null()))){
		HX_STACK_LINE(44)
		return defaultValue;
	}
	HX_STACK_LINE(45)
	return hx::TCast< String >::cast(value);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonUtils_obj,getStr,return )

bool JsonUtils_obj::getBool( Dynamic node,::String field,hx::Null< bool >  __o_defaultValue){
bool defaultValue = __o_defaultValue.Default(false);
	HX_STACK_FRAME("spinehaxe.JsonUtils","getBool",0x56f77996,"spinehaxe.JsonUtils.getBool","spinehaxe/JsonUtils.hx",48,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_ARG(defaultValue,"defaultValue")
{
		HX_STACK_LINE(49)
		Dynamic value;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(49)
		value = (  (((node == null()))) ? Dynamic(null()) : Dynamic(node->__Field(field,true)) );
		HX_STACK_LINE(50)
		if (((value == null()))){
			HX_STACK_LINE(51)
			return defaultValue;
		}
		HX_STACK_LINE(53)
		return value;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonUtils_obj,getBool,return )

bool JsonUtils_obj::hasOwnProperty( Dynamic node,::String field){
	HX_STACK_FRAME("spinehaxe.JsonUtils","hasOwnProperty",0x6aa41c8b,"spinehaxe.JsonUtils.hasOwnProperty","spinehaxe/JsonUtils.hx",57,0x2b196e9b)
	HX_STACK_ARG(node,"node")
	HX_STACK_ARG(field,"field")
	HX_STACK_LINE(57)
	return ::Reflect_obj::hasField(node,field);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(JsonUtils_obj,hasOwnProperty,return )


JsonUtils_obj::JsonUtils_obj()
{
}

Dynamic JsonUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { return fields_dyn(); }
		if (HX_FIELD_EQ(inName,"getInt") ) { return getInt_dyn(); }
		if (HX_FIELD_EQ(inName,"getStr") ) { return getStr_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getNode") ) { return getNode_dyn(); }
		if (HX_FIELD_EQ(inName,"getBool") ) { return getBool_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getFloat") ) { return getFloat_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getDynamic") ) { return getDynamic_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getNodesArray") ) { return getNodesArray_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hasOwnProperty") ) { return hasOwnProperty_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JsonUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void JsonUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("parse"),
	HX_CSTRING("fields"),
	HX_CSTRING("getNode"),
	HX_CSTRING("getDynamic"),
	HX_CSTRING("getNodesArray"),
	HX_CSTRING("getInt"),
	HX_CSTRING("getFloat"),
	HX_CSTRING("getStr"),
	HX_CSTRING("getBool"),
	HX_CSTRING("hasOwnProperty"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JsonUtils_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(JsonUtils_obj::__mClass,"__mClass");
};

#endif

Class JsonUtils_obj::__mClass;

void JsonUtils_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.JsonUtils"), hx::TCanCast< JsonUtils_obj> ,sStaticFields,sMemberFields,
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

void JsonUtils_obj::__boot()
{
}

} // end namespace spinehaxe
