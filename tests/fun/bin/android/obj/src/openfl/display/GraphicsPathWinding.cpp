#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_GraphicsPathWinding
#include <openfl/display/GraphicsPathWinding.h>
#endif
namespace openfl{
namespace display{

::openfl::display::GraphicsPathWinding GraphicsPathWinding_obj::EVEN_ODD;

::openfl::display::GraphicsPathWinding GraphicsPathWinding_obj::NON_ZERO;

HX_DEFINE_CREATE_ENUM(GraphicsPathWinding_obj)

int GraphicsPathWinding_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EVEN_ODD")) return 0;
	if (inName==HX_CSTRING("NON_ZERO")) return 1;
	return super::__FindIndex(inName);
}

int GraphicsPathWinding_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EVEN_ODD")) return 0;
	if (inName==HX_CSTRING("NON_ZERO")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GraphicsPathWinding_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("EVEN_ODD")) return EVEN_ODD;
	if (inName==HX_CSTRING("NON_ZERO")) return NON_ZERO;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("EVEN_ODD"),
	HX_CSTRING("NON_ZERO"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicsPathWinding_obj::EVEN_ODD,"EVEN_ODD");
	HX_MARK_MEMBER_NAME(GraphicsPathWinding_obj::NON_ZERO,"NON_ZERO");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::EVEN_ODD,"EVEN_ODD");
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::NON_ZERO,"NON_ZERO");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class GraphicsPathWinding_obj::__mClass;

Dynamic __Create_GraphicsPathWinding_obj() { return new GraphicsPathWinding_obj; }

void GraphicsPathWinding_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.GraphicsPathWinding"), hx::TCanCast< GraphicsPathWinding_obj >,sStaticFields,sMemberFields,
	&__Create_GraphicsPathWinding_obj, &__Create,
	&super::__SGetClass(), &CreateGraphicsPathWinding_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void GraphicsPathWinding_obj::__boot()
{
hx::Static(EVEN_ODD) = hx::CreateEnum< GraphicsPathWinding_obj >(HX_CSTRING("EVEN_ODD"),0);
hx::Static(NON_ZERO) = hx::CreateEnum< GraphicsPathWinding_obj >(HX_CSTRING("NON_ZERO"),1);
}


} // end namespace openfl
} // end namespace display
