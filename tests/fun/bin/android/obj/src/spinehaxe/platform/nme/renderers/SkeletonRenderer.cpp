#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_TriangleCulling
#include <openfl/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#include <spinehaxe/attachments/RegionAttachment.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTexture
#include <spinehaxe/platform/nme/BitmapDataTexture.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_renderers_SkeletonRenderer
#include <spinehaxe/platform/nme/renderers/SkeletonRenderer.h>
#endif
namespace spinehaxe{
namespace platform{
namespace nme{
namespace renderers{

Void SkeletonRenderer_obj::__construct(::spinehaxe::Skeleton skeleton)
{
HX_STACK_FRAME("spinehaxe.platform.nme.renderers.SkeletonRenderer","new",0x7aeac1be,"spinehaxe.platform.nme.renderers.SkeletonRenderer.new","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",42,0x50571190)
HX_STACK_THIS(this)
HX_STACK_ARG(skeleton,"skeleton")
{
	HX_STACK_LINE(50)
	this->filled = false;
	HX_STACK_LINE(53)
	super::__construct();
	HX_STACK_LINE(54)
	this->skeleton = skeleton;
	HX_STACK_LINE(56)
	Array< Float > _g1;		HX_STACK_VAR(_g1,"_g1");
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",56,0x50571190)
			{
				HX_STACK_LINE(56)
				Dynamic this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(56)
				Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(56)
				this1 = _g;
				HX_STACK_LINE(56)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(56)
	_g1 = _Function_1_1::Block();
	HX_STACK_LINE(56)
	this->vs = _g1;
	HX_STACK_LINE(57)
	Array< int > _g3;		HX_STACK_VAR(_g3,"_g3");
	struct _Function_1_2{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",57,0x50571190)
			{
				HX_STACK_LINE(57)
				Dynamic this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(57)
				Dynamic _g2 = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(57)
				this1 = _g2;
				HX_STACK_LINE(57)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(57)
	_g3 = _Function_1_2::Block();
	HX_STACK_LINE(57)
	this->idx = _g3;
	HX_STACK_LINE(58)
	Array< Float > _g5;		HX_STACK_VAR(_g5,"_g5");
	struct _Function_1_3{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",58,0x50571190)
			{
				HX_STACK_LINE(58)
				Dynamic this1;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(58)
				Dynamic _g4 = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(58)
				this1 = _g4;
				HX_STACK_LINE(58)
				return this1;
			}
			return null();
		}
	};
	HX_STACK_LINE(58)
	_g5 = _Function_1_3::Block();
	HX_STACK_LINE(58)
	this->uvt = _g5;
}
;
	return null();
}

//SkeletonRenderer_obj::~SkeletonRenderer_obj() { }

Dynamic SkeletonRenderer_obj::__CreateEmpty() { return  new SkeletonRenderer_obj; }
hx::ObjectPtr< SkeletonRenderer_obj > SkeletonRenderer_obj::__new(::spinehaxe::Skeleton skeleton)
{  hx::ObjectPtr< SkeletonRenderer_obj > result = new SkeletonRenderer_obj();
	result->__construct(skeleton);
	return result;}

Dynamic SkeletonRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkeletonRenderer_obj > result = new SkeletonRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SkeletonRenderer_obj::clearBuffers( ){
{
		HX_STACK_FRAME("spinehaxe.platform.nme.renderers.SkeletonRenderer","clearBuffers",0xc5ea4848,"spinehaxe.platform.nme.renderers.SkeletonRenderer.clearBuffers","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",61,0x50571190)
		HX_STACK_THIS(this)
		HX_STACK_LINE(63)
		Array< Float > _g1;		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",63,0x50571190)
				{
					HX_STACK_LINE(63)
					Dynamic this1;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(63)
					Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(63)
					this1 = _g;
					HX_STACK_LINE(63)
					return this1;
				}
				return null();
			}
		};
		HX_STACK_LINE(63)
		_g1 = _Function_1_1::Block();
		HX_STACK_LINE(63)
		this->vs = _g1;
		HX_STACK_LINE(64)
		Array< int > _g3;		HX_STACK_VAR(_g3,"_g3");
		struct _Function_1_2{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",64,0x50571190)
				{
					HX_STACK_LINE(64)
					Dynamic this1;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(64)
					Dynamic _g2 = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(64)
					this1 = _g2;
					HX_STACK_LINE(64)
					return this1;
				}
				return null();
			}
		};
		HX_STACK_LINE(64)
		_g3 = _Function_1_2::Block();
		HX_STACK_LINE(64)
		this->idx = _g3;
		HX_STACK_LINE(65)
		Array< Float > _g5;		HX_STACK_VAR(_g5,"_g5");
		struct _Function_1_3{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",65,0x50571190)
				{
					HX_STACK_LINE(65)
					Dynamic this1;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(65)
					Dynamic _g4 = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(65)
					this1 = _g4;
					HX_STACK_LINE(65)
					return this1;
				}
				return null();
			}
		};
		HX_STACK_LINE(65)
		_g5 = _Function_1_3::Block();
		HX_STACK_LINE(65)
		this->uvt = _g5;
		HX_STACK_LINE(66)
		this->filled = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonRenderer_obj,clearBuffers,(void))

Void SkeletonRenderer_obj::draw( ){
{
		HX_STACK_FRAME("spinehaxe.platform.nme.renderers.SkeletonRenderer","draw",0x0bec6ce6,"spinehaxe.platform.nme.renderers.SkeletonRenderer.draw","spinehaxe/platform/nme/renderers/SkeletonRenderer.hx",69,0x50571190)
		HX_STACK_THIS(this)
		HX_STACK_LINE(70)
		int vi = (int)0;		HX_STACK_VAR(vi,"vi");
		HX_STACK_LINE(71)
		int vii = (int)0;		HX_STACK_VAR(vii,"vii");
		HX_STACK_LINE(72)
		int ii = (int)0;		HX_STACK_VAR(ii,"ii");
		HX_STACK_LINE(73)
		this->get_graphics()->clear();
		HX_STACK_LINE(74)
		Array< ::Dynamic > drawOrder = this->skeleton->drawOrder;		HX_STACK_VAR(drawOrder,"drawOrder");
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			while((true)){
				HX_STACK_LINE(75)
				if ((!(((_g < drawOrder->length))))){
					HX_STACK_LINE(75)
					break;
				}
				HX_STACK_LINE(75)
				::spinehaxe::Slot slot = drawOrder->__get(_g).StaticCast< ::spinehaxe::Slot >();		HX_STACK_VAR(slot,"slot");
				HX_STACK_LINE(75)
				++(_g);
				HX_STACK_LINE(76)
				::spinehaxe::attachments::Attachment attachment = slot->attachment;		HX_STACK_VAR(attachment,"attachment");
				HX_STACK_LINE(77)
				if ((::Std_obj::is(attachment,hx::ClassOf< ::spinehaxe::attachments::RegionAttachment >()))){
					HX_STACK_LINE(78)
					::spinehaxe::attachments::RegionAttachment regionAttachment;		HX_STACK_VAR(regionAttachment,"regionAttachment");
					HX_STACK_LINE(78)
					regionAttachment = hx::TCast< spinehaxe::attachments::RegionAttachment >::cast(attachment);
					HX_STACK_LINE(79)
					regionAttachment->updateVertices(slot);
					HX_STACK_LINE(80)
					Array< Float > vertices = regionAttachment->vertices;		HX_STACK_VAR(vertices,"vertices");
					HX_STACK_LINE(81)
					::spinehaxe::atlas::TextureRegion region = regionAttachment->region;		HX_STACK_VAR(region,"region");
					HX_STACK_LINE(82)
					::spinehaxe::platform::nme::BitmapDataTexture texture;		HX_STACK_VAR(texture,"texture");
					HX_STACK_LINE(82)
					texture = hx::TCast< spinehaxe::platform::nme::BitmapDataTexture >::cast(region->texture);
					HX_STACK_LINE(83)
					if (((this->bd == null()))){
						HX_STACK_LINE(84)
						this->bd = texture->bd;
					}
					else{
						HX_STACK_LINE(85)
						if (((this->bd != texture->bd))){
							HX_STACK_LINE(86)
							HX_STACK_DO_THROW(HX_CSTRING("Too many textures"));
							HX_STACK_LINE(87)
							continue;
						}
					}
					HX_STACK_LINE(90)
					{
						HX_STACK_LINE(90)
						Float value = vertices->__unsafe_get((int)0);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(90)
						this->vs[vi] = value;
					}
					HX_STACK_LINE(90)
					{
						HX_STACK_LINE(90)
						Float value = vertices->__unsafe_get((int)1);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(90)
						this->vs[(vi + (int)1)] = value;
					}
					HX_STACK_LINE(91)
					{
						HX_STACK_LINE(91)
						Float value = vertices->__unsafe_get((int)5);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(91)
						this->vs[(vi + (int)2)] = value;
					}
					HX_STACK_LINE(91)
					{
						HX_STACK_LINE(91)
						Float value = vertices->__unsafe_get((int)6);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(91)
						this->vs[(vi + (int)3)] = value;
					}
					HX_STACK_LINE(92)
					{
						HX_STACK_LINE(92)
						Float value = vertices->__unsafe_get((int)10);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(92)
						this->vs[(vi + (int)4)] = value;
					}
					HX_STACK_LINE(92)
					{
						HX_STACK_LINE(92)
						Float value = vertices->__unsafe_get((int)11);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(92)
						this->vs[(vi + (int)5)] = value;
					}
					HX_STACK_LINE(93)
					{
						HX_STACK_LINE(93)
						Float value = vertices->__unsafe_get((int)15);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(93)
						this->vs[(vi + (int)6)] = value;
					}
					HX_STACK_LINE(93)
					{
						HX_STACK_LINE(93)
						Float value = vertices->__unsafe_get((int)16);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(93)
						this->vs[(vi + (int)7)] = value;
					}
					HX_STACK_LINE(95)
					if ((!(this->filled))){
						HX_STACK_LINE(96)
						this->idx[ii] = vii;
						HX_STACK_LINE(96)
						this->idx[(ii + (int)1)] = (vii + (int)1);
						HX_STACK_LINE(96)
						this->idx[(ii + (int)2)] = (vii + (int)2);
						HX_STACK_LINE(97)
						this->idx[(ii + (int)3)] = (vii + (int)2);
						HX_STACK_LINE(97)
						this->idx[(ii + (int)4)] = (vii + (int)3);
						HX_STACK_LINE(97)
						this->idx[(ii + (int)5)] = vii;
						HX_STACK_LINE(99)
						{
							HX_STACK_LINE(99)
							Float value = vertices->__unsafe_get((int)3);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(99)
							this->uvt[vi] = value;
						}
						HX_STACK_LINE(99)
						{
							HX_STACK_LINE(99)
							Float value = vertices->__unsafe_get((int)4);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(99)
							this->uvt[(vi + (int)1)] = value;
						}
						HX_STACK_LINE(100)
						{
							HX_STACK_LINE(100)
							Float value = vertices->__unsafe_get((int)8);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(100)
							this->uvt[(vi + (int)2)] = value;
						}
						HX_STACK_LINE(100)
						{
							HX_STACK_LINE(100)
							Float value = vertices->__unsafe_get((int)9);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(100)
							this->uvt[(vi + (int)3)] = value;
						}
						HX_STACK_LINE(101)
						{
							HX_STACK_LINE(101)
							Float value = vertices->__unsafe_get((int)13);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(101)
							this->uvt[(vi + (int)4)] = value;
						}
						HX_STACK_LINE(101)
						{
							HX_STACK_LINE(101)
							Float value = vertices->__unsafe_get((int)14);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(101)
							this->uvt[(vi + (int)5)] = value;
						}
						HX_STACK_LINE(102)
						{
							HX_STACK_LINE(102)
							Float value = vertices->__unsafe_get((int)18);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(102)
							this->uvt[(vi + (int)6)] = value;
						}
						HX_STACK_LINE(102)
						{
							HX_STACK_LINE(102)
							Float value = vertices->__unsafe_get((int)19);		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(102)
							this->uvt[(vi + (int)7)] = value;
						}
					}
					HX_STACK_LINE(104)
					hx::AddEq(vi,(int)8);
					HX_STACK_LINE(105)
					hx::AddEq(vii,(int)4);
					HX_STACK_LINE(106)
					hx::AddEq(ii,(int)6);
				}
			}
		}
		HX_STACK_LINE(109)
		this->filled = true;
		HX_STACK_LINE(110)
		if (((this->bd != null()))){
			HX_STACK_LINE(111)
			this->get_graphics()->beginBitmapFill(this->bd,null(),true,true);
			HX_STACK_LINE(112)
			this->get_graphics()->drawTriangles(this->vs,this->idx,this->uvt,::openfl::display::TriangleCulling_obj::NONE,null(),null());
			HX_STACK_LINE(113)
			this->get_graphics()->endFill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonRenderer_obj,draw,(void))


SkeletonRenderer_obj::SkeletonRenderer_obj()
{
}

void SkeletonRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkeletonRenderer);
	HX_MARK_MEMBER_NAME(skeleton,"skeleton");
	HX_MARK_MEMBER_NAME(vs,"vs");
	HX_MARK_MEMBER_NAME(idx,"idx");
	HX_MARK_MEMBER_NAME(uvt,"uvt");
	HX_MARK_MEMBER_NAME(bd,"bd");
	HX_MARK_MEMBER_NAME(filled,"filled");
	::openfl::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SkeletonRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(skeleton,"skeleton");
	HX_VISIT_MEMBER_NAME(vs,"vs");
	HX_VISIT_MEMBER_NAME(idx,"idx");
	HX_VISIT_MEMBER_NAME(uvt,"uvt");
	HX_VISIT_MEMBER_NAME(bd,"bd");
	HX_VISIT_MEMBER_NAME(filled,"filled");
	::openfl::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SkeletonRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"vs") ) { return vs; }
		if (HX_FIELD_EQ(inName,"bd") ) { return bd; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"idx") ) { return idx; }
		if (HX_FIELD_EQ(inName,"uvt") ) { return uvt; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"filled") ) { return filled; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skeleton") ) { return skeleton; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clearBuffers") ) { return clearBuffers_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkeletonRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"vs") ) { vs=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bd") ) { bd=inValue.Cast< ::openfl::display::BitmapData >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"idx") ) { idx=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"uvt") ) { uvt=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"filled") ) { filled=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skeleton") ) { skeleton=inValue.Cast< ::spinehaxe::Skeleton >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkeletonRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("skeleton"));
	outFields->push(HX_CSTRING("vs"));
	outFields->push(HX_CSTRING("idx"));
	outFields->push(HX_CSTRING("uvt"));
	outFields->push(HX_CSTRING("bd"));
	outFields->push(HX_CSTRING("filled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::Skeleton*/ ,(int)offsetof(SkeletonRenderer_obj,skeleton),HX_CSTRING("skeleton")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(SkeletonRenderer_obj,vs),HX_CSTRING("vs")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SkeletonRenderer_obj,idx),HX_CSTRING("idx")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(SkeletonRenderer_obj,uvt),HX_CSTRING("uvt")},
	{hx::fsObject /*::openfl::display::BitmapData*/ ,(int)offsetof(SkeletonRenderer_obj,bd),HX_CSTRING("bd")},
	{hx::fsBool,(int)offsetof(SkeletonRenderer_obj,filled),HX_CSTRING("filled")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("skeleton"),
	HX_CSTRING("vs"),
	HX_CSTRING("idx"),
	HX_CSTRING("uvt"),
	HX_CSTRING("bd"),
	HX_CSTRING("filled"),
	HX_CSTRING("clearBuffers"),
	HX_CSTRING("draw"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkeletonRenderer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkeletonRenderer_obj::__mClass,"__mClass");
};

#endif

Class SkeletonRenderer_obj::__mClass;

void SkeletonRenderer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.platform.nme.renderers.SkeletonRenderer"), hx::TCanCast< SkeletonRenderer_obj> ,sStaticFields,sMemberFields,
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

void SkeletonRenderer_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme
} // end namespace renderers
