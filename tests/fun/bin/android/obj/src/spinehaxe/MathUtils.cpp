#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_MathUtils
#include <spinehaxe/MathUtils.h>
#endif
namespace spinehaxe{

Void MathUtils_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.MathUtils","new",0xfce38f76,"spinehaxe.MathUtils.new","spinehaxe/MathUtils.hx",4,0xb0800e3b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//MathUtils_obj::~MathUtils_obj() { }

Dynamic MathUtils_obj::__CreateEmpty() { return  new MathUtils_obj; }
hx::ObjectPtr< MathUtils_obj > MathUtils_obj::__new()
{  hx::ObjectPtr< MathUtils_obj > result = new MathUtils_obj();
	result->__construct();
	return result;}

Dynamic MathUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MathUtils_obj > result = new MathUtils_obj();
	result->__construct();
	return result;}

Float MathUtils_obj::radToDeg( Float rad){
	HX_STACK_FRAME("spinehaxe.MathUtils","radToDeg",0xefda1220,"spinehaxe.MathUtils.radToDeg","spinehaxe/MathUtils.hx",12,0xb0800e3b)
	HX_STACK_ARG(rad,"rad")
	HX_STACK_LINE(12)
	return ((Float((int)180) / Float(::Math_obj::PI)) * rad);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MathUtils_obj,radToDeg,return )

Float MathUtils_obj::degToRad( Float deg){
	HX_STACK_FRAME("spinehaxe.MathUtils","degToRad",0xa88a609e,"spinehaxe.MathUtils.degToRad","spinehaxe/MathUtils.hx",20,0xb0800e3b)
	HX_STACK_ARG(deg,"deg")
	HX_STACK_LINE(20)
	return ((Float(::Math_obj::PI) / Float((int)180)) * deg);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MathUtils_obj,degToRad,return )

Float MathUtils_obj::clamp( Float value,Float min,Float max){
	HX_STACK_FRAME("spinehaxe.MathUtils","clamp",0x57a6a391,"spinehaxe.MathUtils.clamp","spinehaxe/MathUtils.hx",31,0xb0800e3b)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(min,"min")
	HX_STACK_ARG(max,"max")
	HX_STACK_LINE(31)
	if (((value < min))){
		HX_STACK_LINE(32)
		return min;
	}
	else{
		HX_STACK_LINE(33)
		if (((value > max))){
			HX_STACK_LINE(34)
			return max;
		}
		else{
			HX_STACK_LINE(36)
			return value;
		}
	}
	HX_STACK_LINE(31)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MathUtils_obj,clamp,return )

int MathUtils_obj::random( int max){
	HX_STACK_FRAME("spinehaxe.MathUtils","random",0x0cab74ad,"spinehaxe.MathUtils.random","spinehaxe/MathUtils.hx",39,0xb0800e3b)
	HX_STACK_ARG(max,"max")
	HX_STACK_LINE(40)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	Float _g1 = (max * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	return ::Math_obj::round(_g1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MathUtils_obj,random,return )

int MathUtils_obj::minInt( int a,int b){
	HX_STACK_FRAME("spinehaxe.MathUtils","minInt",0xa802cd27,"spinehaxe.MathUtils.minInt","spinehaxe/MathUtils.hx",44,0xb0800e3b)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(44)
	if (((a < b))){
		HX_STACK_LINE(44)
		return a;
	}
	else{
		HX_STACK_LINE(44)
		return b;
	}
	HX_STACK_LINE(44)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(MathUtils_obj,minInt,return )

int MathUtils_obj::maxInt( int a,int b){
	HX_STACK_FRAME("spinehaxe.MathUtils","maxInt",0x136a4b55,"spinehaxe.MathUtils.maxInt","spinehaxe/MathUtils.hx",48,0xb0800e3b)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(48)
	if (((a > b))){
		HX_STACK_LINE(48)
		return a;
	}
	else{
		HX_STACK_LINE(48)
		return b;
	}
	HX_STACK_LINE(48)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(MathUtils_obj,maxInt,return )


MathUtils_obj::MathUtils_obj()
{
}

Dynamic MathUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clamp") ) { return clamp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		if (HX_FIELD_EQ(inName,"minInt") ) { return minInt_dyn(); }
		if (HX_FIELD_EQ(inName,"maxInt") ) { return maxInt_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"radToDeg") ) { return radToDeg_dyn(); }
		if (HX_FIELD_EQ(inName,"degToRad") ) { return degToRad_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MathUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MathUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("radToDeg"),
	HX_CSTRING("degToRad"),
	HX_CSTRING("clamp"),
	HX_CSTRING("random"),
	HX_CSTRING("minInt"),
	HX_CSTRING("maxInt"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MathUtils_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MathUtils_obj::__mClass,"__mClass");
};

#endif

Class MathUtils_obj::__mClass;

void MathUtils_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.MathUtils"), hx::TCanCast< MathUtils_obj> ,sStaticFields,sMemberFields,
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

void MathUtils_obj::__boot()
{
}

} // end namespace spinehaxe
