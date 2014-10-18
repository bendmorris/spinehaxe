#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_atlas_AtlasRegion
#include <spinehaxe/atlas/AtlasRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
namespace spinehaxe{
namespace atlas{

Void AtlasRegion_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","new",0x30c75da9,"spinehaxe.atlas.AtlasRegion.new","spinehaxe/atlas/TextureAtlas.hx",455,0xde245664)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(484)
	this->originalHeight = (int)0;
	HX_STACK_LINE(481)
	this->originalWidth = (int)0;
	HX_STACK_LINE(478)
	this->packedHeight = (int)0;
	HX_STACK_LINE(475)
	this->packedWidth = (int)0;
	HX_STACK_LINE(472)
	this->offsetY = (int)0;
	HX_STACK_LINE(468)
	this->offsetX = (int)0;
	HX_STACK_LINE(461)
	this->index = (int)0;
	HX_STACK_LINE(496)
	super::__construct();
}
;
	return null();
}

//AtlasRegion_obj::~AtlasRegion_obj() { }

Dynamic AtlasRegion_obj::__CreateEmpty() { return  new AtlasRegion_obj; }
hx::ObjectPtr< AtlasRegion_obj > AtlasRegion_obj::__new()
{  hx::ObjectPtr< AtlasRegion_obj > result = new AtlasRegion_obj();
	result->__construct();
	return result;}

Dynamic AtlasRegion_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AtlasRegion_obj > result = new AtlasRegion_obj();
	result->__construct();
	return result;}

Void AtlasRegion_obj::flip( bool x,bool y){
{
		HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","flip",0x78662544,"spinehaxe.atlas.AtlasRegion.flip","spinehaxe/atlas/TextureAtlas.hx",525,0xde245664)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(526)
		this->super::flip(x,y);
		HX_STACK_LINE(527)
		if ((x)){
			HX_STACK_LINE(527)
			Float _g = this->getRotatedPackedWidth();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(527)
			Float _g1 = ((this->originalWidth - this->offsetX) - _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(527)
			this->offsetX = _g1;
		}
		HX_STACK_LINE(528)
		if ((y)){
			HX_STACK_LINE(528)
			Float _g2 = this->getRotatedPackedHeight();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(528)
			Float _g3 = ((this->originalHeight - this->offsetY) - _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(528)
			this->offsetY = _g3;
		}
	}
return null();
}


Float AtlasRegion_obj::getRotatedPackedWidth( ){
	HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","getRotatedPackedWidth",0xc3371e04,"spinehaxe.atlas.AtlasRegion.getRotatedPackedWidth","spinehaxe/atlas/TextureAtlas.hx",534,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(534)
	if ((this->rotate)){
		HX_STACK_LINE(534)
		return this->packedHeight;
	}
	else{
		HX_STACK_LINE(534)
		return this->packedWidth;
	}
	HX_STACK_LINE(534)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasRegion_obj,getRotatedPackedWidth,return )

Float AtlasRegion_obj::getRotatedPackedHeight( ){
	HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","getRotatedPackedHeight",0xc3529e29,"spinehaxe.atlas.AtlasRegion.getRotatedPackedHeight","spinehaxe/atlas/TextureAtlas.hx",540,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(540)
	if ((this->rotate)){
		HX_STACK_LINE(540)
		return this->packedWidth;
	}
	else{
		HX_STACK_LINE(540)
		return this->packedHeight;
	}
	HX_STACK_LINE(540)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasRegion_obj,getRotatedPackedHeight,return )

::spinehaxe::atlas::AtlasRegion AtlasRegion_obj::create( ::spinehaxe::atlas::Texture texture,int x,int y,int width,int height){
	HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","create",0x38d28d53,"spinehaxe.atlas.AtlasRegion.create","spinehaxe/atlas/TextureAtlas.hx",499,0xde245664)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(500)
	::spinehaxe::atlas::AtlasRegion r = ::spinehaxe::atlas::AtlasRegion_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(501)
	r->texture = texture;
	HX_STACK_LINE(502)
	r->setRegionXYWH(x,y,width,height);
	HX_STACK_LINE(503)
	r->packedWidth = width;
	HX_STACK_LINE(504)
	r->packedHeight = height;
	HX_STACK_LINE(505)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(AtlasRegion_obj,create,return )

::spinehaxe::atlas::AtlasRegion AtlasRegion_obj::copy( ::spinehaxe::atlas::AtlasRegion region){
	HX_STACK_FRAME("spinehaxe.atlas.AtlasRegion","copy",0x766cce4c,"spinehaxe.atlas.AtlasRegion.copy","spinehaxe/atlas/TextureAtlas.hx",508,0xde245664)
	HX_STACK_ARG(region,"region")
	HX_STACK_LINE(509)
	::spinehaxe::atlas::AtlasRegion r = ::spinehaxe::atlas::AtlasRegion_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(510)
	r->setRegionCopy(region);
	HX_STACK_LINE(511)
	r->index = region->index;
	HX_STACK_LINE(512)
	r->name = region->name;
	HX_STACK_LINE(513)
	r->offsetX = region->offsetX;
	HX_STACK_LINE(514)
	r->offsetY = region->offsetY;
	HX_STACK_LINE(515)
	r->packedWidth = region->packedWidth;
	HX_STACK_LINE(516)
	r->packedHeight = region->packedHeight;
	HX_STACK_LINE(517)
	r->originalWidth = region->originalWidth;
	HX_STACK_LINE(518)
	r->originalHeight = region->originalHeight;
	HX_STACK_LINE(519)
	r->rotate = region->rotate;
	HX_STACK_LINE(520)
	r->splits = region->splits;
	HX_STACK_LINE(521)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AtlasRegion_obj,copy,return )


AtlasRegion_obj::AtlasRegion_obj()
{
}

void AtlasRegion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AtlasRegion);
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(offsetX,"offsetX");
	HX_MARK_MEMBER_NAME(offsetY,"offsetY");
	HX_MARK_MEMBER_NAME(packedWidth,"packedWidth");
	HX_MARK_MEMBER_NAME(packedHeight,"packedHeight");
	HX_MARK_MEMBER_NAME(originalWidth,"originalWidth");
	HX_MARK_MEMBER_NAME(originalHeight,"originalHeight");
	HX_MARK_MEMBER_NAME(rotate,"rotate");
	HX_MARK_MEMBER_NAME(splits,"splits");
	HX_MARK_MEMBER_NAME(pads,"pads");
	::spinehaxe::atlas::TextureRegion_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AtlasRegion_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(index,"index");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(offsetX,"offsetX");
	HX_VISIT_MEMBER_NAME(offsetY,"offsetY");
	HX_VISIT_MEMBER_NAME(packedWidth,"packedWidth");
	HX_VISIT_MEMBER_NAME(packedHeight,"packedHeight");
	HX_VISIT_MEMBER_NAME(originalWidth,"originalWidth");
	HX_VISIT_MEMBER_NAME(originalHeight,"originalHeight");
	HX_VISIT_MEMBER_NAME(rotate,"rotate");
	HX_VISIT_MEMBER_NAME(splits,"splits");
	HX_VISIT_MEMBER_NAME(pads,"pads");
	::spinehaxe::atlas::TextureRegion_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AtlasRegion_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"pads") ) { return pads; }
		if (HX_FIELD_EQ(inName,"flip") ) { return flip_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate; }
		if (HX_FIELD_EQ(inName,"splits") ) { return splits; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"offsetX") ) { return offsetX; }
		if (HX_FIELD_EQ(inName,"offsetY") ) { return offsetY; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"packedWidth") ) { return packedWidth; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packedHeight") ) { return packedHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"originalWidth") ) { return originalWidth; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"originalHeight") ) { return originalHeight; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getRotatedPackedWidth") ) { return getRotatedPackedWidth_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getRotatedPackedHeight") ) { return getRotatedPackedHeight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AtlasRegion_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pads") ) { pads=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { rotate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"splits") ) { splits=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"offsetX") ) { offsetX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetY") ) { offsetY=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"packedWidth") ) { packedWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packedHeight") ) { packedHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"originalWidth") ) { originalWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"originalHeight") ) { originalHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AtlasRegion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("offsetX"));
	outFields->push(HX_CSTRING("offsetY"));
	outFields->push(HX_CSTRING("packedWidth"));
	outFields->push(HX_CSTRING("packedHeight"));
	outFields->push(HX_CSTRING("originalWidth"));
	outFields->push(HX_CSTRING("originalHeight"));
	outFields->push(HX_CSTRING("rotate"));
	outFields->push(HX_CSTRING("splits"));
	outFields->push(HX_CSTRING("pads"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("copy"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(AtlasRegion_obj,index),HX_CSTRING("index")},
	{hx::fsString,(int)offsetof(AtlasRegion_obj,name),HX_CSTRING("name")},
	{hx::fsFloat,(int)offsetof(AtlasRegion_obj,offsetX),HX_CSTRING("offsetX")},
	{hx::fsFloat,(int)offsetof(AtlasRegion_obj,offsetY),HX_CSTRING("offsetY")},
	{hx::fsInt,(int)offsetof(AtlasRegion_obj,packedWidth),HX_CSTRING("packedWidth")},
	{hx::fsInt,(int)offsetof(AtlasRegion_obj,packedHeight),HX_CSTRING("packedHeight")},
	{hx::fsInt,(int)offsetof(AtlasRegion_obj,originalWidth),HX_CSTRING("originalWidth")},
	{hx::fsInt,(int)offsetof(AtlasRegion_obj,originalHeight),HX_CSTRING("originalHeight")},
	{hx::fsBool,(int)offsetof(AtlasRegion_obj,rotate),HX_CSTRING("rotate")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(AtlasRegion_obj,splits),HX_CSTRING("splits")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(AtlasRegion_obj,pads),HX_CSTRING("pads")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("index"),
	HX_CSTRING("name"),
	HX_CSTRING("offsetX"),
	HX_CSTRING("offsetY"),
	HX_CSTRING("packedWidth"),
	HX_CSTRING("packedHeight"),
	HX_CSTRING("originalWidth"),
	HX_CSTRING("originalHeight"),
	HX_CSTRING("rotate"),
	HX_CSTRING("splits"),
	HX_CSTRING("pads"),
	HX_CSTRING("flip"),
	HX_CSTRING("getRotatedPackedWidth"),
	HX_CSTRING("getRotatedPackedHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AtlasRegion_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AtlasRegion_obj::__mClass,"__mClass");
};

#endif

Class AtlasRegion_obj::__mClass;

void AtlasRegion_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.AtlasRegion"), hx::TCanCast< AtlasRegion_obj> ,sStaticFields,sMemberFields,
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

void AtlasRegion_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
