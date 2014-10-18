#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
namespace spinehaxe{

Void ArrayUtils_obj::__construct()
{
	return null();
}

//ArrayUtils_obj::~ArrayUtils_obj() { }

Dynamic ArrayUtils_obj::__CreateEmpty() { return  new ArrayUtils_obj; }
hx::ObjectPtr< ArrayUtils_obj > ArrayUtils_obj::__new()
{  hx::ObjectPtr< ArrayUtils_obj > result = new ArrayUtils_obj();
	result->__construct();
	return result;}

Dynamic ArrayUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayUtils_obj > result = new ArrayUtils_obj();
	result->__construct();
	return result;}

Array< Float > ArrayUtils_obj::allocFloat( int n){
	HX_STACK_FRAME("spinehaxe.ArrayUtils","allocFloat",0x603e5178,"spinehaxe.ArrayUtils.allocFloat","spinehaxe/ArrayUtils.hx",11,0x0d493e00)
	HX_STACK_ARG(n,"n")
	struct _Function_1_1{
		inline static Array< Float > Block( int &n){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/ArrayUtils.hx",11,0x0d493e00)
			{
				HX_STACK_LINE(11)
				Array< Float > this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(11)
				Array< Float > _g = Array_obj< Float >::__new()->__SetSizeExact(n);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(11)
				this1 = _g;
				HX_STACK_LINE(11)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(11)
	return _Function_1_1::Block(n);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtils_obj,allocFloat,return )

Array< ::String > ArrayUtils_obj::allocString( int n){
	HX_STACK_FRAME("spinehaxe.ArrayUtils","allocString",0xa622fd75,"spinehaxe.ArrayUtils.allocString","spinehaxe/ArrayUtils.hx",16,0x0d493e00)
	HX_STACK_ARG(n,"n")
	struct _Function_1_1{
		inline static Array< ::String > Block( int &n){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/ArrayUtils.hx",16,0x0d493e00)
			{
				HX_STACK_LINE(16)
				Array< ::String > this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(16)
				Array< ::String > _g = Array_obj< ::String >::__new()->__SetSizeExact(n);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(16)
				this1 = _g;
				HX_STACK_LINE(16)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(16)
	return _Function_1_1::Block(n);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtils_obj,allocString,return )

int ArrayUtils_obj::indexOf( Dynamic arr,Dynamic v){
	HX_STACK_FRAME("spinehaxe.ArrayUtils","indexOf",0x469cab98,"spinehaxe.ArrayUtils.indexOf","spinehaxe/ArrayUtils.hx",20,0x0d493e00)
	HX_STACK_ARG(arr,"arr")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(20)
	return arr->__Field(HX_CSTRING("indexOf"),true)(v,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtils_obj,indexOf,return )


ArrayUtils_obj::ArrayUtils_obj()
{
}

Dynamic ArrayUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"allocFloat") ) { return allocFloat_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"allocString") ) { return allocString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ArrayUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ArrayUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("allocFloat"),
	HX_CSTRING("allocString"),
	HX_CSTRING("indexOf"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ArrayUtils_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ArrayUtils_obj::__mClass,"__mClass");
};

#endif

Class ArrayUtils_obj::__mClass;

void ArrayUtils_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.ArrayUtils"), hx::TCanCast< ArrayUtils_obj> ,sStaticFields,sMemberFields,
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

void ArrayUtils_obj::__boot()
{
}

} // end namespace spinehaxe
