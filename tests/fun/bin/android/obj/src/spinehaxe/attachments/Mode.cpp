#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_attachments_Mode
#include <spinehaxe/attachments/Mode.h>
#endif
namespace spinehaxe{
namespace attachments{

::spinehaxe::attachments::Mode Mode_obj::backward;

::spinehaxe::attachments::Mode Mode_obj::backwardLoop;

::spinehaxe::attachments::Mode Mode_obj::forward;

::spinehaxe::attachments::Mode Mode_obj::forwardLoop;

::spinehaxe::attachments::Mode Mode_obj::pingPong;

::spinehaxe::attachments::Mode Mode_obj::random;

HX_DEFINE_CREATE_ENUM(Mode_obj)

int Mode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("backward")) return 1;
	if (inName==HX_CSTRING("backwardLoop")) return 3;
	if (inName==HX_CSTRING("forward")) return 0;
	if (inName==HX_CSTRING("forwardLoop")) return 2;
	if (inName==HX_CSTRING("pingPong")) return 4;
	if (inName==HX_CSTRING("random")) return 5;
	return super::__FindIndex(inName);
}

int Mode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("backward")) return 0;
	if (inName==HX_CSTRING("backwardLoop")) return 0;
	if (inName==HX_CSTRING("forward")) return 0;
	if (inName==HX_CSTRING("forwardLoop")) return 0;
	if (inName==HX_CSTRING("pingPong")) return 0;
	if (inName==HX_CSTRING("random")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Mode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("backward")) return backward;
	if (inName==HX_CSTRING("backwardLoop")) return backwardLoop;
	if (inName==HX_CSTRING("forward")) return forward;
	if (inName==HX_CSTRING("forwardLoop")) return forwardLoop;
	if (inName==HX_CSTRING("pingPong")) return pingPong;
	if (inName==HX_CSTRING("random")) return random;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("forward"),
	HX_CSTRING("backward"),
	HX_CSTRING("forwardLoop"),
	HX_CSTRING("backwardLoop"),
	HX_CSTRING("pingPong"),
	HX_CSTRING("random"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mode_obj::backward,"backward");
	HX_MARK_MEMBER_NAME(Mode_obj::backwardLoop,"backwardLoop");
	HX_MARK_MEMBER_NAME(Mode_obj::forward,"forward");
	HX_MARK_MEMBER_NAME(Mode_obj::forwardLoop,"forwardLoop");
	HX_MARK_MEMBER_NAME(Mode_obj::pingPong,"pingPong");
	HX_MARK_MEMBER_NAME(Mode_obj::random,"random");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Mode_obj::backward,"backward");
	HX_VISIT_MEMBER_NAME(Mode_obj::backwardLoop,"backwardLoop");
	HX_VISIT_MEMBER_NAME(Mode_obj::forward,"forward");
	HX_VISIT_MEMBER_NAME(Mode_obj::forwardLoop,"forwardLoop");
	HX_VISIT_MEMBER_NAME(Mode_obj::pingPong,"pingPong");
	HX_VISIT_MEMBER_NAME(Mode_obj::random,"random");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class Mode_obj::__mClass;

Dynamic __Create_Mode_obj() { return new Mode_obj; }

void Mode_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.Mode"), hx::TCanCast< Mode_obj >,sStaticFields,sMemberFields,
	&__Create_Mode_obj, &__Create,
	&super::__SGetClass(), &CreateMode_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Mode_obj::__boot()
{
hx::Static(backward) = hx::CreateEnum< Mode_obj >(HX_CSTRING("backward"),1);
hx::Static(backwardLoop) = hx::CreateEnum< Mode_obj >(HX_CSTRING("backwardLoop"),3);
hx::Static(forward) = hx::CreateEnum< Mode_obj >(HX_CSTRING("forward"),0);
hx::Static(forwardLoop) = hx::CreateEnum< Mode_obj >(HX_CSTRING("forwardLoop"),2);
hx::Static(pingPong) = hx::CreateEnum< Mode_obj >(HX_CSTRING("pingPong"),4);
hx::Static(random) = hx::CreateEnum< Mode_obj >(HX_CSTRING("random"),5);
}


} // end namespace spinehaxe
} // end namespace attachments
