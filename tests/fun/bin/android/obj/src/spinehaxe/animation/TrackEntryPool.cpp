#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntry
#include <spinehaxe/animation/TrackEntry.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntryPool
#include <spinehaxe/animation/TrackEntryPool.h>
#endif
namespace spinehaxe{
namespace animation{

Void TrackEntryPool_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.animation.TrackEntryPool","new",0xc0b9d3a4,"spinehaxe.animation.TrackEntryPool.new","spinehaxe/animation/TrackEntry.hx",66,0x80903a46)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(66)
	this->objs = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//TrackEntryPool_obj::~TrackEntryPool_obj() { }

Dynamic TrackEntryPool_obj::__CreateEmpty() { return  new TrackEntryPool_obj; }
hx::ObjectPtr< TrackEntryPool_obj > TrackEntryPool_obj::__new()
{  hx::ObjectPtr< TrackEntryPool_obj > result = new TrackEntryPool_obj();
	result->__construct();
	return result;}

Dynamic TrackEntryPool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TrackEntryPool_obj > result = new TrackEntryPool_obj();
	result->__construct();
	return result;}

Void TrackEntryPool_obj::free( ::spinehaxe::animation::TrackEntry obj){
{
		HX_STACK_FRAME("spinehaxe.animation.TrackEntryPool","free",0xdc9f74e8,"spinehaxe.animation.TrackEntryPool.free","spinehaxe/animation/TrackEntry.hx",69,0x80903a46)
		HX_STACK_THIS(this)
		HX_STACK_ARG(obj,"obj")
		HX_STACK_LINE(70)
		::spinehaxe::animation::TrackEntry _g = obj->previous = null();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(70)
		obj->next = _g;
		HX_STACK_LINE(71)
		obj->animation = null();
		HX_STACK_LINE(72)
		Dynamic _g1 = obj->onEvent = null();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(72)
		Dynamic _g2 = obj->onComplete = _g1;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(72)
		Dynamic _g3 = obj->onEnd = _g2;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(72)
		obj->onStart = _g3;
		HX_STACK_LINE(73)
		obj->lastTime = (int)-1;
		HX_STACK_LINE(74)
		obj->timeScale = (int)1;
		HX_STACK_LINE(75)
		obj->time = (int)0;
		HX_STACK_LINE(76)
		this->objs->push(obj);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TrackEntryPool_obj,free,(void))

::spinehaxe::animation::TrackEntry TrackEntryPool_obj::get( ){
	HX_STACK_FRAME("spinehaxe.animation.TrackEntryPool","get",0xc0b483da,"spinehaxe.animation.TrackEntryPool.get","spinehaxe/animation/TrackEntry.hx",79,0x80903a46)
	HX_STACK_THIS(this)
	HX_STACK_LINE(80)
	if (((this->objs->length > (int)0))){
		HX_STACK_LINE(81)
		return this->objs->pop().StaticCast< ::spinehaxe::animation::TrackEntry >();
	}
	HX_STACK_LINE(83)
	return ::spinehaxe::animation::TrackEntry_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(TrackEntryPool_obj,get,return )


TrackEntryPool_obj::TrackEntryPool_obj()
{
}

void TrackEntryPool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TrackEntryPool);
	HX_MARK_MEMBER_NAME(objs,"objs");
	HX_MARK_END_CLASS();
}

void TrackEntryPool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(objs,"objs");
}

Dynamic TrackEntryPool_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"objs") ) { return objs; }
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TrackEntryPool_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"objs") ) { objs=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TrackEntryPool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("objs"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TrackEntryPool_obj,objs),HX_CSTRING("objs")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("objs"),
	HX_CSTRING("free"),
	HX_CSTRING("get"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TrackEntryPool_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TrackEntryPool_obj::__mClass,"__mClass");
};

#endif

Class TrackEntryPool_obj::__mClass;

void TrackEntryPool_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.TrackEntryPool"), hx::TCanCast< TrackEntryPool_obj> ,sStaticFields,sMemberFields,
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

void TrackEntryPool_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
