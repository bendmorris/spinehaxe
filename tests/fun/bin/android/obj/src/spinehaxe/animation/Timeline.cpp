#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Timeline
#include <spinehaxe/animation/Timeline.h>
#endif
namespace spinehaxe{
namespace animation{

HX_DEFINE_DYNAMIC_FUNC5(Timeline_obj,apply,)


static ::String sMemberFields[] = {
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timeline_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Timeline_obj::__mClass,"__mClass");
};

#endif

Class Timeline_obj::__mClass;

void Timeline_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.Timeline"), hx::TCanCast< Timeline_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Timeline_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
