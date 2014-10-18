#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_BoundingBoxAttachment
#include <spinehaxe/attachments/BoundingBoxAttachment.h>
#endif
namespace spinehaxe{
namespace attachments{

Void BoundingBoxAttachment_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.attachments.BoundingBoxAttachment","new",0x925702b9,"spinehaxe.attachments.BoundingBoxAttachment.new","spinehaxe/attachments/BoundingBoxAttachment.hx",37,0xf7b0ea59)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(38)
	Array< Float > _g = Array_obj< Float >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(38)
	this->vertices = _g;
	HX_STACK_LINE(39)
	super::__construct(name);
}
;
	return null();
}

//BoundingBoxAttachment_obj::~BoundingBoxAttachment_obj() { }

Dynamic BoundingBoxAttachment_obj::__CreateEmpty() { return  new BoundingBoxAttachment_obj; }
hx::ObjectPtr< BoundingBoxAttachment_obj > BoundingBoxAttachment_obj::__new(::String name)
{  hx::ObjectPtr< BoundingBoxAttachment_obj > result = new BoundingBoxAttachment_obj();
	result->__construct(name);
	return result;}

Dynamic BoundingBoxAttachment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoundingBoxAttachment_obj > result = new BoundingBoxAttachment_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BoundingBoxAttachment_obj::computeWorldVertices( Float x,Float y,::spinehaxe::Bone bone,Array< Float > worldVertices){
{
		HX_STACK_FRAME("spinehaxe.attachments.BoundingBoxAttachment","computeWorldVertices",0x8931b7fb,"spinehaxe.attachments.BoundingBoxAttachment.computeWorldVertices","spinehaxe/attachments/BoundingBoxAttachment.hx",42,0xf7b0ea59)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(bone,"bone")
		HX_STACK_ARG(worldVertices,"worldVertices")
		HX_STACK_LINE(43)
		hx::AddEq(x,bone->worldX);
		HX_STACK_LINE(44)
		hx::AddEq(y,bone->worldY);
		HX_STACK_LINE(45)
		Float m00 = bone->m00;		HX_STACK_VAR(m00,"m00");
		HX_STACK_LINE(46)
		Float m01 = bone->m01;		HX_STACK_VAR(m01,"m01");
		HX_STACK_LINE(47)
		Float m10 = bone->m10;		HX_STACK_VAR(m10,"m10");
		HX_STACK_LINE(48)
		Float m11 = bone->m11;		HX_STACK_VAR(m11,"m11");
		HX_STACK_LINE(49)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(50)
		int n = this->vertices->length;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(51)
		while((true)){
			HX_STACK_LINE(51)
			if ((!(((i < n))))){
				HX_STACK_LINE(51)
				break;
			}
			HX_STACK_LINE(52)
			int ii = (i + (int)1);		HX_STACK_VAR(ii,"ii");
			HX_STACK_LINE(53)
			Float px = this->vertices->__get(i);		HX_STACK_VAR(px,"px");
			HX_STACK_LINE(54)
			Float py = this->vertices->__get(ii);		HX_STACK_VAR(py,"py");
			HX_STACK_LINE(55)
			worldVertices->__unsafe_set(i,(((px * m00) + (py * m01)) + x));
			HX_STACK_LINE(56)
			worldVertices->__unsafe_set(ii,(((px * m10) + (py * m11)) + y));
			HX_STACK_LINE(57)
			hx::AddEq(i,(int)2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BoundingBoxAttachment_obj,computeWorldVertices,(void))


BoundingBoxAttachment_obj::BoundingBoxAttachment_obj()
{
}

void BoundingBoxAttachment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoundingBoxAttachment);
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	::spinehaxe::attachments::Attachment_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BoundingBoxAttachment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(vertices,"vertices");
	::spinehaxe::attachments::Attachment_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BoundingBoxAttachment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeWorldVertices") ) { return computeWorldVertices_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoundingBoxAttachment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoundingBoxAttachment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("vertices"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(BoundingBoxAttachment_obj,vertices),HX_CSTRING("vertices")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("vertices"),
	HX_CSTRING("computeWorldVertices"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoundingBoxAttachment_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoundingBoxAttachment_obj::__mClass,"__mClass");
};

#endif

Class BoundingBoxAttachment_obj::__mClass;

void BoundingBoxAttachment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.BoundingBoxAttachment"), hx::TCanCast< BoundingBoxAttachment_obj> ,sStaticFields,sMemberFields,
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

void BoundingBoxAttachment_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
