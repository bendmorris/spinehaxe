#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_AtlasRegion
#include <spinehaxe/atlas/AtlasRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Page
#include <spinehaxe/atlas/Page.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Region
#include <spinehaxe/atlas/Region.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlas
#include <spinehaxe/atlas/TextureAtlas.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlasData
#include <spinehaxe/atlas/TextureAtlasData.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureLoader
#include <spinehaxe/atlas/TextureLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
namespace spinehaxe{
namespace atlas{

Void TextureAtlas_obj::__construct(::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader)
{
HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","new",0x7e8523ca,"spinehaxe.atlas.TextureAtlas.new","spinehaxe/atlas/TextureAtlas.hx",264,0xde245664)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
HX_STACK_ARG(textureLoader,"textureLoader")
{
	HX_STACK_LINE(265)
	Array< ::spinehaxe::atlas::Texture > _g = Array_obj< ::spinehaxe::atlas::Texture >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(265)
	this->textures = _g;
	HX_STACK_LINE(266)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(266)
	this->regions = _g1;
	HX_STACK_LINE(267)
	if (((data != null()))){
		HX_STACK_LINE(268)
		this->load(data,textureLoader);
	}
}
;
	return null();
}

//TextureAtlas_obj::~TextureAtlas_obj() { }

Dynamic TextureAtlas_obj::__CreateEmpty() { return  new TextureAtlas_obj; }
hx::ObjectPtr< TextureAtlas_obj > TextureAtlas_obj::__new(::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader)
{  hx::ObjectPtr< TextureAtlas_obj > result = new TextureAtlas_obj();
	result->__construct(data,textureLoader);
	return result;}

Dynamic TextureAtlas_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureAtlas_obj > result = new TextureAtlas_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void TextureAtlas_obj::addTexture( ::spinehaxe::atlas::Texture texture){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","addTexture",0x2a3d4290,"spinehaxe.atlas.TextureAtlas.addTexture","spinehaxe/atlas/TextureAtlas.hx",228,0xde245664)
		HX_STACK_THIS(this)
		HX_STACK_ARG(texture,"texture")
		HX_STACK_LINE(229)
		int _g = ::spinehaxe::ArrayUtils_obj::indexOf(this->textures,texture);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(229)
		if (((_g == (int)-1))){
			HX_STACK_LINE(230)
			this->textures->push(texture);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureAtlas_obj,addTexture,(void))

Void TextureAtlas_obj::load( ::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","load",0x34af437c,"spinehaxe.atlas.TextureAtlas.load","spinehaxe/atlas/TextureAtlas.hx",272,0xde245664)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_ARG(textureLoader,"textureLoader")
		HX_STACK_LINE(273)
		::haxe::ds::ObjectMap pageToTexture = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(pageToTexture,"pageToTexture");
		HX_STACK_LINE(274)
		{
			HX_STACK_LINE(274)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(274)
			Array< ::Dynamic > _g1 = data->pages;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(274)
			while((true)){
				HX_STACK_LINE(274)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(274)
					break;
				}
				HX_STACK_LINE(274)
				::spinehaxe::atlas::Page page = _g1->__get(_g).StaticCast< ::spinehaxe::atlas::Page >();		HX_STACK_VAR(page,"page");
				HX_STACK_LINE(274)
				++(_g);
				HX_STACK_LINE(275)
				::spinehaxe::atlas::Texture texture = null();		HX_STACK_VAR(texture,"texture");
				HX_STACK_LINE(276)
				if (((page->texture == null()))){
					HX_STACK_LINE(277)
					::spinehaxe::atlas::Texture _g2 = textureLoader->loadTexture(page->textureFile,page->format,page->useMipMaps);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(277)
					texture = _g2;
					HX_STACK_LINE(278)
					texture->setFilter(page->minFilter,page->magFilter);
					HX_STACK_LINE(279)
					texture->setWrap(page->uWrap,page->vWrap);
				}
				else{
					HX_STACK_LINE(281)
					texture = page->texture;
					HX_STACK_LINE(282)
					texture->setFilter(page->minFilter,page->magFilter);
					HX_STACK_LINE(283)
					texture->setWrap(page->uWrap,page->vWrap);
				}
				HX_STACK_LINE(285)
				this->addTexture(texture);
				HX_STACK_LINE(286)
				pageToTexture->set(page,texture);
			}
		}
		HX_STACK_LINE(289)
		{
			HX_STACK_LINE(289)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(289)
			Array< ::Dynamic > _g1 = data->regions;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(289)
			while((true)){
				HX_STACK_LINE(289)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(289)
					break;
				}
				HX_STACK_LINE(289)
				::spinehaxe::atlas::Region region = _g1->__get(_g).StaticCast< ::spinehaxe::atlas::Region >();		HX_STACK_VAR(region,"region");
				HX_STACK_LINE(289)
				++(_g);
				HX_STACK_LINE(290)
				int width = region->width;		HX_STACK_VAR(width,"width");
				HX_STACK_LINE(291)
				int height = region->height;		HX_STACK_VAR(height,"height");
				HX_STACK_LINE(292)
				::spinehaxe::atlas::Texture _g11 = pageToTexture->get(region->page);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(292)
				::spinehaxe::atlas::AtlasRegion atlasRegion = ::spinehaxe::atlas::AtlasRegion_obj::create(_g11,region->left,region->top,(  ((region->rotate)) ? int(height) : int(width) ),(  ((region->rotate)) ? int(width) : int(height) ));		HX_STACK_VAR(atlasRegion,"atlasRegion");
				HX_STACK_LINE(294)
				atlasRegion->index = region->index;
				HX_STACK_LINE(295)
				atlasRegion->name = region->name;
				HX_STACK_LINE(296)
				atlasRegion->offsetX = region->offsetX;
				HX_STACK_LINE(297)
				atlasRegion->offsetY = region->offsetY;
				HX_STACK_LINE(298)
				atlasRegion->originalHeight = region->originalHeight;
				HX_STACK_LINE(299)
				atlasRegion->originalWidth = region->originalWidth;
				HX_STACK_LINE(300)
				atlasRegion->rotate = region->rotate;
				HX_STACK_LINE(301)
				atlasRegion->splits = region->splits;
				HX_STACK_LINE(302)
				atlasRegion->pads = region->pads;
				HX_STACK_LINE(303)
				if ((region->flip)){
					HX_STACK_LINE(303)
					atlasRegion->flip(false,true);
				}
				HX_STACK_LINE(304)
				this->regions->push(atlasRegion);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureAtlas_obj,load,(void))

::spinehaxe::atlas::AtlasRegion TextureAtlas_obj::addRegion( ::String name,::spinehaxe::atlas::Texture texture,int x,int y,int width,int height){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","addRegion",0x1f05b4df,"spinehaxe.atlas.TextureAtlas.addRegion","spinehaxe/atlas/TextureAtlas.hx",309,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(310)
	this->addTexture(texture);
	HX_STACK_LINE(311)
	::spinehaxe::atlas::AtlasRegion region = ::spinehaxe::atlas::AtlasRegion_obj::create(texture,x,y,width,height);		HX_STACK_VAR(region,"region");
	HX_STACK_LINE(312)
	region->name = name;
	HX_STACK_LINE(313)
	region->originalWidth = width;
	HX_STACK_LINE(314)
	region->originalHeight = height;
	HX_STACK_LINE(315)
	region->index = (int)-1;
	HX_STACK_LINE(316)
	this->regions->push(region);
	HX_STACK_LINE(317)
	return region;
}


HX_DEFINE_DYNAMIC_FUNC6(TextureAtlas_obj,addRegion,return )

::spinehaxe::atlas::AtlasRegion TextureAtlas_obj::addRegionTex( ::String name,::spinehaxe::atlas::TextureRegion textureRegion){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","addRegionTex",0xe0297648,"spinehaxe.atlas.TextureAtlas.addRegionTex","spinehaxe/atlas/TextureAtlas.hx",321,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(textureRegion,"textureRegion")
	HX_STACK_LINE(322)
	int _g = textureRegion->get_regionX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(322)
	int _g1 = textureRegion->get_regionY();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(322)
	return this->addRegion(name,textureRegion->texture,_g,_g1,textureRegion->regionWidth,textureRegion->regionHeight);
}


HX_DEFINE_DYNAMIC_FUNC2(TextureAtlas_obj,addRegionTex,return )

Array< ::Dynamic > TextureAtlas_obj::getRegions( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","getRegions",0xedcfe8df,"spinehaxe.atlas.TextureAtlas.getRegions","spinehaxe/atlas/TextureAtlas.hx",328,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(328)
	return this->regions;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureAtlas_obj,getRegions,return )

::spinehaxe::atlas::AtlasRegion TextureAtlas_obj::findRegion( ::String name){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","findRegion",0x4db2c3e3,"spinehaxe.atlas.TextureAtlas.findRegion","spinehaxe/atlas/TextureAtlas.hx",334,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(335)
	{
		HX_STACK_LINE(335)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(335)
		Array< ::Dynamic > _g1 = this->regions;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(335)
		while((true)){
			HX_STACK_LINE(335)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(335)
				break;
			}
			HX_STACK_LINE(335)
			::spinehaxe::atlas::AtlasRegion region = _g1->__get(_g).StaticCast< ::spinehaxe::atlas::AtlasRegion >();		HX_STACK_VAR(region,"region");
			HX_STACK_LINE(335)
			++(_g);
			HX_STACK_LINE(336)
			if (((region->name == name))){
				HX_STACK_LINE(336)
				return region;
			}
		}
	}
	HX_STACK_LINE(337)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureAtlas_obj,findRegion,return )

::spinehaxe::atlas::AtlasRegion TextureAtlas_obj::findRegionIdx( ::String name,int index){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","findRegionIdx",0x486c481a,"spinehaxe.atlas.TextureAtlas.findRegionIdx","spinehaxe/atlas/TextureAtlas.hx",343,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(344)
	{
		HX_STACK_LINE(344)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(344)
		Array< ::Dynamic > _g1 = this->regions;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(344)
		while((true)){
			HX_STACK_LINE(344)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(344)
				break;
			}
			HX_STACK_LINE(344)
			::spinehaxe::atlas::AtlasRegion region = _g1->__get(_g).StaticCast< ::spinehaxe::atlas::AtlasRegion >();		HX_STACK_VAR(region,"region");
			HX_STACK_LINE(344)
			++(_g);
			HX_STACK_LINE(345)
			if (((bool((region->name == name)) && bool((region->index == index))))){
				HX_STACK_LINE(346)
				return region;
			}
		}
	}
	HX_STACK_LINE(348)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureAtlas_obj,findRegionIdx,return )

Array< ::Dynamic > TextureAtlas_obj::findRegions( ::String name){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","findRegions",0xaeb8a330,"spinehaxe.atlas.TextureAtlas.findRegions","spinehaxe/atlas/TextureAtlas.hx",353,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(354)
	Array< ::Dynamic > matched = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(matched,"matched");
	HX_STACK_LINE(355)
	{
		HX_STACK_LINE(355)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(355)
		Array< ::Dynamic > _g1 = this->regions;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(355)
		while((true)){
			HX_STACK_LINE(355)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(355)
				break;
			}
			HX_STACK_LINE(355)
			::spinehaxe::atlas::AtlasRegion region = _g1->__get(_g).StaticCast< ::spinehaxe::atlas::AtlasRegion >();		HX_STACK_VAR(region,"region");
			HX_STACK_LINE(355)
			++(_g);
			HX_STACK_LINE(356)
			if (((region->name == name))){
				HX_STACK_LINE(356)
				::spinehaxe::atlas::AtlasRegion _g2 = ::spinehaxe::atlas::AtlasRegion_obj::copy(region);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(356)
				matched->push(_g2);
			}
		}
	}
	HX_STACK_LINE(358)
	return matched;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureAtlas_obj,findRegions,return )

Array< ::spinehaxe::atlas::Texture > TextureAtlas_obj::getTextures( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","getTextures",0xbff48758,"spinehaxe.atlas.TextureAtlas.getTextures","spinehaxe/atlas/TextureAtlas.hx",441,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(441)
	return this->textures;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureAtlas_obj,getTextures,return )

Void TextureAtlas_obj::dispose( ){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","dispose",0xf09cd109,"spinehaxe.atlas.TextureAtlas.dispose","spinehaxe/atlas/TextureAtlas.hx",446,0xde245664)
		HX_STACK_THIS(this)
		HX_STACK_LINE(447)
		{
			HX_STACK_LINE(447)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(447)
			Array< ::spinehaxe::atlas::Texture > _g1 = this->textures;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(447)
			while((true)){
				HX_STACK_LINE(447)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(447)
					break;
				}
				HX_STACK_LINE(447)
				::spinehaxe::atlas::Texture texture = _g1->__get(_g);		HX_STACK_VAR(texture,"texture");
				HX_STACK_LINE(447)
				++(_g);
				HX_STACK_LINE(448)
				texture->dispose();
			}
		}
		HX_STACK_LINE(449)
		Array< ::spinehaxe::atlas::Texture > _g = Array_obj< ::spinehaxe::atlas::Texture >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(449)
		this->textures = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureAtlas_obj,dispose,(void))

::spinehaxe::atlas::TextureAtlas TextureAtlas_obj::create( ::String packFileData,::String imagesDir,::spinehaxe::atlas::TextureLoader textureLoader,hx::Null< bool >  __o_flip){
bool flip = __o_flip.Default(false);
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlas","create",0x554491d2,"spinehaxe.atlas.TextureAtlas.create","spinehaxe/atlas/TextureAtlas.hx",260,0xde245664)
	HX_STACK_ARG(packFileData,"packFileData")
	HX_STACK_ARG(imagesDir,"imagesDir")
	HX_STACK_ARG(textureLoader,"textureLoader")
	HX_STACK_ARG(flip,"flip")
{
		HX_STACK_LINE(261)
		::spinehaxe::atlas::TextureAtlasData _g = ::spinehaxe::atlas::TextureAtlasData_obj::__new(packFileData,imagesDir,flip);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(261)
		return ::spinehaxe::atlas::TextureAtlas_obj::__new(_g,textureLoader);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(TextureAtlas_obj,create,return )


TextureAtlas_obj::TextureAtlas_obj()
{
}

void TextureAtlas_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextureAtlas);
	HX_MARK_MEMBER_NAME(textures,"textures");
	HX_MARK_MEMBER_NAME(regions,"regions");
	HX_MARK_END_CLASS();
}

void TextureAtlas_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(textures,"textures");
	HX_VISIT_MEMBER_NAME(regions,"regions");
}

Dynamic TextureAtlas_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { return regions; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"textures") ) { return textures; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addRegion") ) { return addRegion_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addTexture") ) { return addTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"getRegions") ) { return getRegions_dyn(); }
		if (HX_FIELD_EQ(inName,"findRegion") ) { return findRegion_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"findRegions") ) { return findRegions_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextures") ) { return getTextures_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addRegionTex") ) { return addRegionTex_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"findRegionIdx") ) { return findRegionIdx_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureAtlas_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { regions=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"textures") ) { textures=inValue.Cast< Array< ::spinehaxe::atlas::Texture > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureAtlas_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("textures"));
	outFields->push(HX_CSTRING("regions"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::spinehaxe::atlas::Texture >*/ ,(int)offsetof(TextureAtlas_obj,textures),HX_CSTRING("textures")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TextureAtlas_obj,regions),HX_CSTRING("regions")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("textures"),
	HX_CSTRING("regions"),
	HX_CSTRING("addTexture"),
	HX_CSTRING("load"),
	HX_CSTRING("addRegion"),
	HX_CSTRING("addRegionTex"),
	HX_CSTRING("getRegions"),
	HX_CSTRING("findRegion"),
	HX_CSTRING("findRegionIdx"),
	HX_CSTRING("findRegions"),
	HX_CSTRING("getTextures"),
	HX_CSTRING("dispose"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureAtlas_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureAtlas_obj::__mClass,"__mClass");
};

#endif

Class TextureAtlas_obj::__mClass;

void TextureAtlas_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.TextureAtlas"), hx::TCanCast< TextureAtlas_obj> ,sStaticFields,sMemberFields,
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

void TextureAtlas_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
