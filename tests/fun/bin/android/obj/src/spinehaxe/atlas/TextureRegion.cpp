#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Texture
#include <spinehaxe/atlas/Texture.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
namespace spinehaxe{
namespace atlas{

Void TextureRegion_obj::__construct()
{
HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","new",0xe3674339,"spinehaxe.atlas.TextureRegion.new","spinehaxe/atlas/TextureRegion.hx",39,0x69316119)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//TextureRegion_obj::~TextureRegion_obj() { }

Dynamic TextureRegion_obj::__CreateEmpty() { return  new TextureRegion_obj; }
hx::ObjectPtr< TextureRegion_obj > TextureRegion_obj::__new()
{  hx::ObjectPtr< TextureRegion_obj > result = new TextureRegion_obj();
	result->__construct();
	return result;}

Dynamic TextureRegion_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureRegion_obj > result = new TextureRegion_obj();
	result->__construct();
	return result;}

Void TextureRegion_obj::setRegionTex( ::spinehaxe::atlas::Texture texture){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionTex",0x58d10f58,"spinehaxe.atlas.TextureRegion.setRegionTex","spinehaxe/atlas/TextureRegion.hx",93,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(texture,"texture")
		HX_STACK_LINE(94)
		this->texture = texture;
		HX_STACK_LINE(95)
		int _g = texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(95)
		int _g1 = texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(95)
		this->setRegionXYWH((int)0,(int)0,_g,_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setRegionTex,(void))

Void TextureRegion_obj::setRegionXYWH( int x,int y,int width,int height){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionXYWH",0x60b800a1,"spinehaxe.atlas.TextureRegion.setRegionXYWH","spinehaxe/atlas/TextureRegion.hx",100,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(101)
		int _g = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(101)
		Float invTexWidth = (Float(1.0) / Float(_g));		HX_STACK_VAR(invTexWidth,"invTexWidth");
		HX_STACK_LINE(102)
		int _g1 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(102)
		Float invTexHeight = (Float(1.0) / Float(_g1));		HX_STACK_VAR(invTexHeight,"invTexHeight");
		HX_STACK_LINE(103)
		this->setRegionUV((x * invTexWidth),(y * invTexHeight),(((x + width)) * invTexWidth),(((y + height)) * invTexHeight));
		HX_STACK_LINE(104)
		Float _g2 = ::Math_obj::abs(width);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(104)
		int _g3 = ::Math_obj::floor(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(104)
		this->regionWidth = _g3;
		HX_STACK_LINE(105)
		Float _g4 = ::Math_obj::abs(height);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(105)
		int _g5 = ::Math_obj::floor(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(105)
		this->regionHeight = _g5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(TextureRegion_obj,setRegionXYWH,(void))

Void TextureRegion_obj::setRegionUV( Float u,Float v,Float u2,Float v2){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionUV",0xfbce6df0,"spinehaxe.atlas.TextureRegion.setRegionUV","spinehaxe/atlas/TextureRegion.hx",108,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u,"u")
		HX_STACK_ARG(v,"v")
		HX_STACK_ARG(u2,"u2")
		HX_STACK_ARG(v2,"v2")
		HX_STACK_LINE(109)
		this->u = u;
		HX_STACK_LINE(110)
		this->v = v;
		HX_STACK_LINE(111)
		this->u2 = u2;
		HX_STACK_LINE(112)
		this->v2 = v2;
		HX_STACK_LINE(113)
		Float _g = ::Math_obj::abs((u2 - u));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(113)
		int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(113)
		Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(113)
		int _g3 = ::Math_obj::round(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(113)
		this->regionWidth = _g3;
		HX_STACK_LINE(114)
		Float _g4 = ::Math_obj::abs((v2 - v));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(114)
		int _g5 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(114)
		Float _g6 = (_g4 * _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(114)
		int _g7 = ::Math_obj::round(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(114)
		this->regionHeight = _g7;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(TextureRegion_obj,setRegionUV,(void))

Void TextureRegion_obj::setRegionCopy( ::spinehaxe::atlas::TextureRegion region){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionCopy",0x52e74d24,"spinehaxe.atlas.TextureRegion.setRegionCopy","spinehaxe/atlas/TextureRegion.hx",118,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(region,"region")
		HX_STACK_LINE(119)
		this->texture = region->texture;
		HX_STACK_LINE(120)
		this->setRegionUV(region->u,region->v,region->u2,region->v2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setRegionCopy,(void))

Void TextureRegion_obj::setRegionRelXYWH( ::spinehaxe::atlas::TextureRegion region,int x,int y,int width,int height){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionRelXYWH",0x41bc531c,"spinehaxe.atlas.TextureRegion.setRegionRelXYWH","spinehaxe/atlas/TextureRegion.hx",124,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(region,"region")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(125)
		this->texture = region->texture;
		HX_STACK_LINE(126)
		int _g = region->get_regionX();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(126)
		int _g1 = (_g + x);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(126)
		int _g2 = region->get_regionY();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(126)
		int _g3 = (_g2 + y);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(126)
		this->setRegionXYWH(_g1,_g3,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(TextureRegion_obj,setRegionRelXYWH,(void))

Float TextureRegion_obj::getU( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getU",0x12530e06,"spinehaxe.atlas.TextureRegion.getU","spinehaxe/atlas/TextureRegion.hx",130,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(130)
	return this->u;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getU,return )

Void TextureRegion_obj::setU( Float u){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setU",0x1a419d7a,"spinehaxe.atlas.TextureRegion.setU","spinehaxe/atlas/TextureRegion.hx",133,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(134)
		this->u = u;
		HX_STACK_LINE(135)
		Float _g = ::Math_obj::abs((this->u2 - u));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(135)
		int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(135)
		Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(135)
		int _g3 = ::Math_obj::round(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(135)
		this->regionWidth = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setU,(void))

Float TextureRegion_obj::getV( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getV",0x12530e07,"spinehaxe.atlas.TextureRegion.getV","spinehaxe/atlas/TextureRegion.hx",139,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(139)
	return this->v;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getV,return )

Void TextureRegion_obj::setV( Float v){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setV",0x1a419d7b,"spinehaxe.atlas.TextureRegion.setV","spinehaxe/atlas/TextureRegion.hx",142,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(143)
		this->v = v;
		HX_STACK_LINE(144)
		Float _g = ::Math_obj::abs((this->v2 - v));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(144)
		int _g1 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(144)
		Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(144)
		int _g3 = ::Math_obj::round(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(144)
		this->regionHeight = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setV,(void))

Float TextureRegion_obj::getU2( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getU2",0xf659376c,"spinehaxe.atlas.TextureRegion.getU2","spinehaxe/atlas/TextureRegion.hx",148,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(148)
	return this->u2;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getU2,return )

Void TextureRegion_obj::setU2( Float u2){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setU2",0xdf282d78,"spinehaxe.atlas.TextureRegion.setU2","spinehaxe/atlas/TextureRegion.hx",151,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u2,"u2")
		HX_STACK_LINE(152)
		this->u2 = u2;
		HX_STACK_LINE(153)
		Float _g = ::Math_obj::abs((u2 - this->u));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(153)
		int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(153)
		Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(153)
		int _g3 = ::Math_obj::round(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(153)
		this->regionWidth = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setU2,(void))

Float TextureRegion_obj::getV2( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getV2",0xf659384b,"spinehaxe.atlas.TextureRegion.getV2","spinehaxe/atlas/TextureRegion.hx",157,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(157)
	return this->v2;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getV2,return )

Void TextureRegion_obj::setV2( Float v2){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setV2",0xdf282e57,"spinehaxe.atlas.TextureRegion.setV2","spinehaxe/atlas/TextureRegion.hx",160,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v2,"v2")
		HX_STACK_LINE(161)
		this->v2 = v2;
		HX_STACK_LINE(162)
		Float _g = ::Math_obj::abs((v2 - this->v));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(162)
		int _g1 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(162)
		Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(162)
		int _g3 = ::Math_obj::round(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(162)
		this->regionHeight = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setV2,(void))

int TextureRegion_obj::get_regionX( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","get_regionX",0xfe0de8d4,"spinehaxe.atlas.TextureRegion.get_regionX","spinehaxe/atlas/TextureRegion.hx",165,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(166)
	int _g = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(166)
	Float _g1 = (this->u * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(166)
	return ::Math_obj::round(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,get_regionX,return )

int TextureRegion_obj::set_regionX( int x){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","set_regionX",0x087aefe0,"spinehaxe.atlas.TextureRegion.set_regionX","spinehaxe/atlas/TextureRegion.hx",169,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(170)
	Float _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(170)
	_g = hx::TCast< Float >::cast(x);
	HX_STACK_LINE(170)
	int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(170)
	Float _g2 = (Float(_g) / Float(_g1));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(170)
	this->setU(_g2);
	HX_STACK_LINE(171)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,set_regionX,return )

int TextureRegion_obj::get_regionY( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","get_regionY",0xfe0de8d5,"spinehaxe.atlas.TextureRegion.get_regionY","spinehaxe/atlas/TextureRegion.hx",174,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(175)
	int _g = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(175)
	Float _g1 = (this->v * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(175)
	return ::Math_obj::round(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,get_regionY,return )

int TextureRegion_obj::set_regionY( int y){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","set_regionY",0x087aefe1,"spinehaxe.atlas.TextureRegion.set_regionY","spinehaxe/atlas/TextureRegion.hx",178,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(179)
	Float _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(179)
	_g = hx::TCast< Float >::cast(y);
	HX_STACK_LINE(179)
	int _g1 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(179)
	Float _g2 = (Float(_g) / Float(_g1));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(179)
	this->setV(_g2);
	HX_STACK_LINE(180)
	return y;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,set_regionY,return )

int TextureRegion_obj::getRegionWidth( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getRegionWidth",0x975f7d43,"spinehaxe.atlas.TextureRegion.getRegionWidth","spinehaxe/atlas/TextureRegion.hx",185,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(185)
	return this->regionWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getRegionWidth,return )

Void TextureRegion_obj::setRegionWidth( int width){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionWidth",0xb77f65b7,"spinehaxe.atlas.TextureRegion.setRegionWidth","spinehaxe/atlas/TextureRegion.hx",188,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(width,"width")
		HX_STACK_LINE(189)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(189)
		_g = hx::TCast< Float >::cast(width);
		HX_STACK_LINE(189)
		int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(189)
		Float _g2 = (Float(_g) / Float(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(189)
		Float _g3 = (this->u + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(189)
		this->setU2(_g3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setRegionWidth,(void))

int TextureRegion_obj::getRegionHeight( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","getRegionHeight",0x927d960a,"spinehaxe.atlas.TextureRegion.getRegionHeight","spinehaxe/atlas/TextureRegion.hx",194,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(194)
	return this->regionHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,getRegionHeight,return )

Void TextureRegion_obj::setRegionHeight( int height){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","setRegionHeight",0x8e491316,"spinehaxe.atlas.TextureRegion.setRegionHeight","spinehaxe/atlas/TextureRegion.hx",197,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(198)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(198)
		_g = hx::TCast< Float >::cast(height);
		HX_STACK_LINE(198)
		int _g1 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(198)
		Float _g2 = (Float(_g) / Float(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(198)
		Float _g3 = (this->v + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(198)
		this->setV2(_g3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,setRegionHeight,(void))

Void TextureRegion_obj::flip( bool x,bool y){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","flip",0x11af1db4,"spinehaxe.atlas.TextureRegion.flip","spinehaxe/atlas/TextureRegion.hx",201,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(202)
		if ((x)){
			HX_STACK_LINE(203)
			Float temp = this->u;		HX_STACK_VAR(temp,"temp");
			HX_STACK_LINE(204)
			this->u = this->u2;
			HX_STACK_LINE(205)
			this->u2 = temp;
		}
		HX_STACK_LINE(207)
		if ((y)){
			HX_STACK_LINE(208)
			Float temp = this->v;		HX_STACK_VAR(temp,"temp");
			HX_STACK_LINE(209)
			this->v = this->v2;
			HX_STACK_LINE(210)
			this->v2 = temp;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureRegion_obj,flip,(void))

bool TextureRegion_obj::isFlipX( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","isFlipX",0xa7c03c1a,"spinehaxe.atlas.TextureRegion.isFlipX","spinehaxe/atlas/TextureRegion.hx",215,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(215)
	return (this->u > this->u2);
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,isFlipX,return )

bool TextureRegion_obj::isFlipY( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","isFlipY",0xa7c03c1b,"spinehaxe.atlas.TextureRegion.isFlipY","spinehaxe/atlas/TextureRegion.hx",219,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_LINE(219)
	return (this->v > this->v2);
}


HX_DEFINE_DYNAMIC_FUNC0(TextureRegion_obj,isFlipY,return )

Void TextureRegion_obj::scroll( Float xAmount,Float yAmount){
{
		HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","scroll",0x3bf3f2d4,"spinehaxe.atlas.TextureRegion.scroll","spinehaxe/atlas/TextureRegion.hx",226,0x69316119)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xAmount,"xAmount")
		HX_STACK_ARG(yAmount,"yAmount")
		HX_STACK_LINE(227)
		if (((xAmount != (int)0))){
			HX_STACK_LINE(228)
			int _g = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(228)
			Float width = (((this->u2 - this->u)) * _g);		HX_STACK_VAR(width,"width");
			HX_STACK_LINE(229)
			this->u = hx::Mod(((this->u + xAmount)),(int)1);
			HX_STACK_LINE(230)
			int _g1 = this->texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(230)
			Float _g2 = (Float(width) / Float(_g1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(230)
			Float _g3 = (this->u + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(230)
			this->u2 = _g3;
		}
		HX_STACK_LINE(232)
		if (((yAmount != (int)0))){
			HX_STACK_LINE(233)
			int _g4 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(233)
			Float height = (((this->v2 - this->v)) * _g4);		HX_STACK_VAR(height,"height");
			HX_STACK_LINE(234)
			this->v = hx::Mod(((this->v + yAmount)),(int)1);
			HX_STACK_LINE(235)
			int _g5 = this->texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(235)
			Float _g6 = (Float(height) / Float(_g5));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(235)
			Float _g7 = (this->v + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(235)
			this->v2 = _g7;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureRegion_obj,scroll,(void))

Array< ::Dynamic > TextureRegion_obj::split( int tileWidth,int tileHeight){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","split",0xe66785f3,"spinehaxe.atlas.TextureRegion.split","spinehaxe/atlas/TextureRegion.hx",246,0x69316119)
	HX_STACK_THIS(this)
	HX_STACK_ARG(tileWidth,"tileWidth")
	HX_STACK_ARG(tileHeight,"tileHeight")
	HX_STACK_LINE(247)
	int x = this->get_regionX();		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(248)
	int y = this->get_regionY();		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(249)
	int width = this->regionWidth;		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(250)
	int height = this->regionHeight;		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(252)
	int rows = ::Math_obj::floor((Float(height) / Float(tileHeight)));		HX_STACK_VAR(rows,"rows");
	HX_STACK_LINE(253)
	int cols = ::Math_obj::floor((Float(width) / Float(tileWidth)));		HX_STACK_VAR(cols,"cols");
	HX_STACK_LINE(255)
	int startX = x;		HX_STACK_VAR(startX,"startX");
	HX_STACK_LINE(256)
	Array< ::Dynamic > tiles = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(tiles,"tiles");
	HX_STACK_LINE(257)
	{
		HX_STACK_LINE(257)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(257)
		while((true)){
			HX_STACK_LINE(257)
			if ((!(((_g < rows))))){
				HX_STACK_LINE(257)
				break;
			}
			HX_STACK_LINE(257)
			int rowIdx = (_g)++;		HX_STACK_VAR(rowIdx,"rowIdx");
			HX_STACK_LINE(258)
			Array< ::Dynamic > row = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(259)
			tiles[rowIdx] = row;
			HX_STACK_LINE(260)
			x = startX;
			HX_STACK_LINE(261)
			{
				HX_STACK_LINE(261)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(261)
				while((true)){
					HX_STACK_LINE(261)
					if ((!(((_g1 < cols))))){
						HX_STACK_LINE(261)
						break;
					}
					HX_STACK_LINE(261)
					int colIdx = (_g1)++;		HX_STACK_VAR(colIdx,"colIdx");
					HX_STACK_LINE(262)
					row[colIdx] = ::spinehaxe::atlas::TextureRegion_obj::fromTextureXYWH(this->texture,x,y,tileWidth,tileHeight);
					HX_STACK_LINE(263)
					hx::AddEq(x,tileWidth);
				}
			}
			HX_STACK_LINE(265)
			hx::AddEq(y,tileHeight);
		}
	}
	HX_STACK_LINE(268)
	return tiles;
}


HX_DEFINE_DYNAMIC_FUNC2(TextureRegion_obj,split,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::fromTexture( ::spinehaxe::atlas::Texture texture){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","fromTexture",0x3498a06a,"spinehaxe.atlas.TextureRegion.fromTexture","spinehaxe/atlas/TextureRegion.hx",43,0x69316119)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_LINE(44)
	if (((texture == null()))){
		HX_STACK_LINE(44)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("texture cannot be null.")));
	}
	HX_STACK_LINE(45)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(46)
	t->texture = texture;
	HX_STACK_LINE(47)
	int _g = texture->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	int _g1 = texture->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(47)
	t->setRegionXYWH((int)0,(int)0,_g,_g1);
	HX_STACK_LINE(48)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,fromTexture,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::fromTextureWH( ::spinehaxe::atlas::Texture texture,int width,int height){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","fromTextureWH",0x04515afb,"spinehaxe.atlas.TextureRegion.fromTextureWH","spinehaxe/atlas/TextureRegion.hx",53,0x69316119)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(54)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(55)
	t->texture = texture;
	HX_STACK_LINE(56)
	t->setRegionXYWH((int)0,(int)0,width,height);
	HX_STACK_LINE(57)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(TextureRegion_obj,fromTextureWH,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::fromTextureXYWH( ::spinehaxe::atlas::Texture texture,int x,int y,int width,int height){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","fromTextureXYWH",0xc050b8bc,"spinehaxe.atlas.TextureRegion.fromTextureXYWH","spinehaxe/atlas/TextureRegion.hx",62,0x69316119)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(63)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(64)
	t->texture = texture;
	HX_STACK_LINE(65)
	t->setRegionXYWH(x,y,width,height);
	HX_STACK_LINE(66)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(TextureRegion_obj,fromTextureXYWH,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::fromTextureUVUV( ::spinehaxe::atlas::Texture texture,Float u,Float v,Float u2,Float v2){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","fromTextureUVUV",0xbe52cc6c,"spinehaxe.atlas.TextureRegion.fromTextureUVUV","spinehaxe/atlas/TextureRegion.hx",69,0x69316119)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(u,"u")
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(u2,"u2")
	HX_STACK_ARG(v2,"v2")
	HX_STACK_LINE(70)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(71)
	t->texture = texture;
	HX_STACK_LINE(72)
	t->setRegionUV(u,v,u2,v2);
	HX_STACK_LINE(73)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(TextureRegion_obj,fromTextureUVUV,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::copy( ::spinehaxe::atlas::TextureRegion region){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","copy",0x0fb5c6bc,"spinehaxe.atlas.TextureRegion.copy","spinehaxe/atlas/TextureRegion.hx",77,0x69316119)
	HX_STACK_ARG(region,"region")
	HX_STACK_LINE(78)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(79)
	t->setRegionCopy(region);
	HX_STACK_LINE(80)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureRegion_obj,copy,return )

::spinehaxe::atlas::TextureRegion TextureRegion_obj::createRelXYWH( ::spinehaxe::atlas::TextureRegion region,int x,int y,int width,int height){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","createRelXYWH",0x19b149a8,"spinehaxe.atlas.TextureRegion.createRelXYWH","spinehaxe/atlas/TextureRegion.hx",86,0x69316119)
	HX_STACK_ARG(region,"region")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(87)
	::spinehaxe::atlas::TextureRegion t = ::spinehaxe::atlas::TextureRegion_obj::__new();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(88)
	t->setRegionRelXYWH(region,x,y,width,height);
	HX_STACK_LINE(89)
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(TextureRegion_obj,createRelXYWH,return )

Array< ::Dynamic > TextureRegion_obj::splitTex( ::spinehaxe::atlas::Texture texture,int tileWidth,int tileHeight){
	HX_STACK_FRAME("spinehaxe.atlas.TextureRegion","splitTex",0x5e3889b4,"spinehaxe.atlas.TextureRegion.splitTex","spinehaxe/atlas/TextureRegion.hx",279,0x69316119)
	HX_STACK_ARG(texture,"texture")
	HX_STACK_ARG(tileWidth,"tileWidth")
	HX_STACK_ARG(tileHeight,"tileHeight")
	HX_STACK_LINE(280)
	::spinehaxe::atlas::TextureRegion region = ::spinehaxe::atlas::TextureRegion_obj::fromTexture(texture);		HX_STACK_VAR(region,"region");
	HX_STACK_LINE(281)
	return region->split(tileWidth,tileHeight);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(TextureRegion_obj,splitTex,return )


TextureRegion_obj::TextureRegion_obj()
{
}

void TextureRegion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextureRegion);
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(u,"u");
	HX_MARK_MEMBER_NAME(v,"v");
	HX_MARK_MEMBER_NAME(u2,"u2");
	HX_MARK_MEMBER_NAME(v2,"v2");
	HX_MARK_MEMBER_NAME(regionWidth,"regionWidth");
	HX_MARK_MEMBER_NAME(regionHeight,"regionHeight");
	HX_MARK_END_CLASS();
}

void TextureRegion_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(u,"u");
	HX_VISIT_MEMBER_NAME(v,"v");
	HX_VISIT_MEMBER_NAME(u2,"u2");
	HX_VISIT_MEMBER_NAME(v2,"v2");
	HX_VISIT_MEMBER_NAME(regionWidth,"regionWidth");
	HX_VISIT_MEMBER_NAME(regionHeight,"regionHeight");
}

Dynamic TextureRegion_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"u") ) { return u; }
		if (HX_FIELD_EQ(inName,"v") ) { return v; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"u2") ) { return u2; }
		if (HX_FIELD_EQ(inName,"v2") ) { return v2; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"getU") ) { return getU_dyn(); }
		if (HX_FIELD_EQ(inName,"setU") ) { return setU_dyn(); }
		if (HX_FIELD_EQ(inName,"getV") ) { return getV_dyn(); }
		if (HX_FIELD_EQ(inName,"setV") ) { return setV_dyn(); }
		if (HX_FIELD_EQ(inName,"flip") ) { return flip_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"getU2") ) { return getU2_dyn(); }
		if (HX_FIELD_EQ(inName,"setU2") ) { return setU2_dyn(); }
		if (HX_FIELD_EQ(inName,"getV2") ) { return getV2_dyn(); }
		if (HX_FIELD_EQ(inName,"setV2") ) { return setV2_dyn(); }
		if (HX_FIELD_EQ(inName,"split") ) { return split_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		if (HX_FIELD_EQ(inName,"regionX") ) { return get_regionX(); }
		if (HX_FIELD_EQ(inName,"regionY") ) { return get_regionY(); }
		if (HX_FIELD_EQ(inName,"isFlipX") ) { return isFlipX_dyn(); }
		if (HX_FIELD_EQ(inName,"isFlipY") ) { return isFlipY_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"splitTex") ) { return splitTex_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fromTexture") ) { return fromTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"regionWidth") ) { return regionWidth; }
		if (HX_FIELD_EQ(inName,"setRegionUV") ) { return setRegionUV_dyn(); }
		if (HX_FIELD_EQ(inName,"get_regionX") ) { return get_regionX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_regionX") ) { return set_regionX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_regionY") ) { return get_regionY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_regionY") ) { return set_regionY_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regionHeight") ) { return regionHeight; }
		if (HX_FIELD_EQ(inName,"setRegionTex") ) { return setRegionTex_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fromTextureWH") ) { return fromTextureWH_dyn(); }
		if (HX_FIELD_EQ(inName,"createRelXYWH") ) { return createRelXYWH_dyn(); }
		if (HX_FIELD_EQ(inName,"setRegionXYWH") ) { return setRegionXYWH_dyn(); }
		if (HX_FIELD_EQ(inName,"setRegionCopy") ) { return setRegionCopy_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRegionWidth") ) { return getRegionWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setRegionWidth") ) { return setRegionWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"fromTextureXYWH") ) { return fromTextureXYWH_dyn(); }
		if (HX_FIELD_EQ(inName,"fromTextureUVUV") ) { return fromTextureUVUV_dyn(); }
		if (HX_FIELD_EQ(inName,"getRegionHeight") ) { return getRegionHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setRegionHeight") ) { return setRegionHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setRegionRelXYWH") ) { return setRegionRelXYWH_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureRegion_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"u") ) { u=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v") ) { v=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"u2") ) { u2=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v2") ) { v2=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::spinehaxe::atlas::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"regionX") ) { return set_regionX(inValue); }
		if (HX_FIELD_EQ(inName,"regionY") ) { return set_regionY(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"regionWidth") ) { regionWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regionHeight") ) { regionHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureRegion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("texture"));
	outFields->push(HX_CSTRING("u"));
	outFields->push(HX_CSTRING("v"));
	outFields->push(HX_CSTRING("u2"));
	outFields->push(HX_CSTRING("v2"));
	outFields->push(HX_CSTRING("regionWidth"));
	outFields->push(HX_CSTRING("regionHeight"));
	outFields->push(HX_CSTRING("regionX"));
	outFields->push(HX_CSTRING("regionY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromTexture"),
	HX_CSTRING("fromTextureWH"),
	HX_CSTRING("fromTextureXYWH"),
	HX_CSTRING("fromTextureUVUV"),
	HX_CSTRING("copy"),
	HX_CSTRING("createRelXYWH"),
	HX_CSTRING("splitTex"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::atlas::Texture*/ ,(int)offsetof(TextureRegion_obj,texture),HX_CSTRING("texture")},
	{hx::fsFloat,(int)offsetof(TextureRegion_obj,u),HX_CSTRING("u")},
	{hx::fsFloat,(int)offsetof(TextureRegion_obj,v),HX_CSTRING("v")},
	{hx::fsFloat,(int)offsetof(TextureRegion_obj,u2),HX_CSTRING("u2")},
	{hx::fsFloat,(int)offsetof(TextureRegion_obj,v2),HX_CSTRING("v2")},
	{hx::fsInt,(int)offsetof(TextureRegion_obj,regionWidth),HX_CSTRING("regionWidth")},
	{hx::fsInt,(int)offsetof(TextureRegion_obj,regionHeight),HX_CSTRING("regionHeight")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("texture"),
	HX_CSTRING("u"),
	HX_CSTRING("v"),
	HX_CSTRING("u2"),
	HX_CSTRING("v2"),
	HX_CSTRING("regionWidth"),
	HX_CSTRING("regionHeight"),
	HX_CSTRING("setRegionTex"),
	HX_CSTRING("setRegionXYWH"),
	HX_CSTRING("setRegionUV"),
	HX_CSTRING("setRegionCopy"),
	HX_CSTRING("setRegionRelXYWH"),
	HX_CSTRING("getU"),
	HX_CSTRING("setU"),
	HX_CSTRING("getV"),
	HX_CSTRING("setV"),
	HX_CSTRING("getU2"),
	HX_CSTRING("setU2"),
	HX_CSTRING("getV2"),
	HX_CSTRING("setV2"),
	HX_CSTRING("get_regionX"),
	HX_CSTRING("set_regionX"),
	HX_CSTRING("get_regionY"),
	HX_CSTRING("set_regionY"),
	HX_CSTRING("getRegionWidth"),
	HX_CSTRING("setRegionWidth"),
	HX_CSTRING("getRegionHeight"),
	HX_CSTRING("setRegionHeight"),
	HX_CSTRING("flip"),
	HX_CSTRING("isFlipX"),
	HX_CSTRING("isFlipY"),
	HX_CSTRING("scroll"),
	HX_CSTRING("split"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureRegion_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureRegion_obj::__mClass,"__mClass");
};

#endif

Class TextureRegion_obj::__mClass;

void TextureRegion_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.TextureRegion"), hx::TCanCast< TextureRegion_obj> ,sStaticFields,sMemberFields,
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

void TextureRegion_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
