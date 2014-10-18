#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Listeners
#include <spinehaxe/animation/Listeners.h>
#endif
namespace spinehaxe{
namespace animation{

Void Listeners_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.animation.Listeners","new",0xbef4cd82,"spinehaxe.animation.Listeners.new","spinehaxe/animation/Listeners.hx",52,0xca401e70)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(53)
	Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(53)
	this->listeners = _g;
}
;
	return null();
}

//Listeners_obj::~Listeners_obj() { }

Dynamic Listeners_obj::__CreateEmpty() { return  new Listeners_obj; }
hx::ObjectPtr< Listeners_obj > Listeners_obj::__new()
{  hx::ObjectPtr< Listeners_obj > result = new Listeners_obj();
	result->__construct();
	return result;}

Dynamic Listeners_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Listeners_obj > result = new Listeners_obj();
	result->__construct();
	return result;}

Void Listeners_obj::add( Dynamic listener){
{
		HX_STACK_FRAME("spinehaxe.animation.Listeners","add",0xbeeaef43,"spinehaxe.animation.Listeners.add","spinehaxe/animation/Listeners.hx",39,0xca401e70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(listener,"listener")
		HX_STACK_LINE(40)
		if (((listener == null()))){
			HX_STACK_LINE(41)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("listener cannot be null.")));
		}
		HX_STACK_LINE(42)
		this->listeners->__Field(HX_CSTRING("push"),true)(listener);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Listeners_obj,add,(void))

Void Listeners_obj::remove( Dynamic listener){
{
		HX_STACK_FRAME("spinehaxe.animation.Listeners","remove",0x7b5d0062,"spinehaxe.animation.Listeners.remove","spinehaxe/animation/Listeners.hx",45,0xca401e70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(listener,"listener")
		HX_STACK_LINE(46)
		if (((listener == null()))){
			HX_STACK_LINE(47)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("listener cannot be null.")));
		}
		HX_STACK_LINE(48)
		this->listeners->__Field(HX_CSTRING("remove"),true)(listener);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Listeners_obj,remove,(void))

Void Listeners_obj::invoke( int i,Dynamic arg){
{
		HX_STACK_FRAME("spinehaxe.animation.Listeners","invoke",0x16b4db96,"spinehaxe.animation.Listeners.invoke","spinehaxe/animation/Listeners.hx",57,0xca401e70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(i,"i")
		HX_STACK_ARG(arg,"arg")
		HX_STACK_LINE(57)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		Dynamic _g1 = this->listeners;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(57)
		while((true)){
			HX_STACK_LINE(57)
			if ((!(((_g < _g1->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(57)
				break;
			}
			HX_STACK_LINE(57)
			Dynamic listener = _g1->__GetItem(_g);		HX_STACK_VAR(listener,"listener");
			HX_STACK_LINE(57)
			++(_g);
			HX_STACK_LINE(58)
			listener(i,arg);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Listeners_obj,invoke,(void))


Listeners_obj::Listeners_obj()
{
}

void Listeners_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Listeners);
	HX_MARK_MEMBER_NAME(listeners,"listeners");
	HX_MARK_END_CLASS();
}

void Listeners_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(listeners,"listeners");
}

Dynamic Listeners_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"invoke") ) { return invoke_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"listeners") ) { return listeners; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Listeners_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"listeners") ) { listeners=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Listeners_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("listeners"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Listeners_obj,listeners),HX_CSTRING("listeners")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("listeners"),
	HX_CSTRING("add"),
	HX_CSTRING("remove"),
	HX_CSTRING("invoke"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Listeners_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Listeners_obj::__mClass,"__mClass");
};

#endif

Class Listeners_obj::__mClass;

void Listeners_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.Listeners"), hx::TCanCast< Listeners_obj> ,sStaticFields,sMemberFields,
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

void Listeners_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
