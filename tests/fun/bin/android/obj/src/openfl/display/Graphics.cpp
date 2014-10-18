#include <hxcpp.h>

#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_CapsStyle
#include <openfl/display/CapsStyle.h>
#endif
#ifndef INCLUDED_openfl_display_GradientType
#include <openfl/display/GradientType.h>
#endif
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsPathWinding
#include <openfl/display/GraphicsPathWinding.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsData
#include <openfl/display/IGraphicsData.h>
#endif
#ifndef INCLUDED_openfl_display_InterpolationMethod
#include <openfl/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_openfl_display_JointStyle
#include <openfl/display/JointStyle.h>
#endif
#ifndef INCLUDED_openfl_display_LineScaleMode
#include <openfl/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_openfl_display_SpreadMethod
#include <openfl/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
#ifndef INCLUDED_openfl_display_TriangleCulling
#include <openfl/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
namespace openfl{
namespace display{

Void Graphics_obj::__construct(Dynamic handle)
{
HX_STACK_FRAME("openfl.display.Graphics","new",0x7fd846a7,"openfl.display.Graphics.new","openfl/display/Graphics.hx",26,0x8d299ce7)
HX_STACK_THIS(this)
HX_STACK_ARG(handle,"handle")
{
	HX_STACK_LINE(26)
	this->__handle = handle;
}
;
	return null();
}

//Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new(Dynamic handle)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(handle);
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Graphics_obj::arcTo( Float controlX,Float controlY,Float x,Float y){
{
		HX_STACK_FRAME("openfl.display.Graphics","arcTo",0xe7c7d674,"openfl.display.Graphics.arcTo","openfl/display/Graphics.hx",33,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(controlX,"controlX")
		HX_STACK_ARG(controlY,"controlY")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(33)
		::openfl::display::Graphics_obj::lime_gfx_arc_to(this->__handle,controlX,controlY,x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,arcTo,(void))

Void Graphics_obj::beginBitmapFill( ::openfl::display::BitmapData bitmap,::openfl::geom::Matrix matrix,hx::Null< bool >  __o_repeat,hx::Null< bool >  __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_STACK_FRAME("openfl.display.Graphics","beginBitmapFill",0x31c80e62,"openfl.display.Graphics.beginBitmapFill","openfl/display/Graphics.hx",40,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bitmap,"bitmap")
	HX_STACK_ARG(matrix,"matrix")
	HX_STACK_ARG(repeat,"repeat")
	HX_STACK_ARG(smooth,"smooth")
{
		HX_STACK_LINE(40)
		::openfl::display::Graphics_obj::lime_gfx_begin_bitmap_fill(this->__handle,bitmap->__handle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,beginBitmapFill,(void))

Void Graphics_obj::beginFill( int color,hx::Null< Float >  __o_alpha){
Float alpha = __o_alpha.Default(1.0);
	HX_STACK_FRAME("openfl.display.Graphics","beginFill",0xf44a92d3,"openfl.display.Graphics.beginFill","openfl/display/Graphics.hx",47,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(color,"color")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(47)
		::openfl::display::Graphics_obj::lime_gfx_begin_fill(this->__handle,color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,beginFill,(void))

Void Graphics_obj::beginGradientFill( ::openfl::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::openfl::geom::Matrix matrix,::openfl::display::SpreadMethod spreadMethod,::openfl::display::InterpolationMethod interpolationMethod,hx::Null< Float >  __o_focalPointRatio){
Float focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_STACK_FRAME("openfl.display.Graphics","beginGradientFill",0x99f380e3,"openfl.display.Graphics.beginGradientFill","openfl/display/Graphics.hx",52,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(colors,"colors")
	HX_STACK_ARG(alphas,"alphas")
	HX_STACK_ARG(ratios,"ratios")
	HX_STACK_ARG(matrix,"matrix")
	HX_STACK_ARG(spreadMethod,"spreadMethod")
	HX_STACK_ARG(interpolationMethod,"interpolationMethod")
	HX_STACK_ARG(focalPointRatio,"focalPointRatio")
{
		HX_STACK_LINE(54)
		if (((matrix == null()))){
			HX_STACK_LINE(56)
			::openfl::geom::Matrix _g = ::openfl::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(56)
			matrix = _g;
			HX_STACK_LINE(57)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_STACK_LINE(61)
		int _g1 = type->__Index();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(61)
		int _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(61)
		if (((spreadMethod == null()))){
			HX_STACK_LINE(61)
			_g2 = (int)0;
		}
		else{
			HX_STACK_LINE(61)
			_g2 = spreadMethod->__Index();
		}
		HX_STACK_LINE(61)
		int _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(61)
		if (((interpolationMethod == null()))){
			HX_STACK_LINE(61)
			_g3 = (int)0;
		}
		else{
			HX_STACK_LINE(61)
			_g3 = interpolationMethod->__Index();
		}
		HX_STACK_LINE(61)
		::openfl::display::Graphics_obj::lime_gfx_begin_gradient_fill(this->__handle,_g1,colors,alphas,ratios,matrix,_g2,_g3,focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,beginGradientFill,(void))

Void Graphics_obj::clear( ){
{
		HX_STACK_FRAME("openfl.display.Graphics","clear",0x0a9f4794,"openfl.display.Graphics.clear","openfl/display/Graphics.hx",68,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(68)
		::openfl::display::Graphics_obj::lime_gfx_clear(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,clear,(void))

Void Graphics_obj::curveTo( Float controlX,Float controlY,Float anchorX,Float anchorY){
{
		HX_STACK_FRAME("openfl.display.Graphics","curveTo",0x89f305d1,"openfl.display.Graphics.curveTo","openfl/display/Graphics.hx",75,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(controlX,"controlX")
		HX_STACK_ARG(controlY,"controlY")
		HX_STACK_ARG(anchorX,"anchorX")
		HX_STACK_ARG(anchorY,"anchorY")
		HX_STACK_LINE(75)
		::openfl::display::Graphics_obj::lime_gfx_curve_to(this->__handle,controlX,controlY,anchorX,anchorY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,curveTo,(void))

Void Graphics_obj::drawCircle( Float x,Float y,Float radius){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawCircle",0xee64ddcd,"openfl.display.Graphics.drawCircle","openfl/display/Graphics.hx",82,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(radius,"radius")
		HX_STACK_LINE(82)
		::openfl::display::Graphics_obj::lime_gfx_draw_ellipse(this->__handle,(x - radius),(y - radius),(radius * (int)2),(radius * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawCircle,(void))

Void Graphics_obj::drawEllipse( Float x,Float y,Float width,Float height){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawEllipse",0xbfad1a81,"openfl.display.Graphics.drawEllipse","openfl/display/Graphics.hx",89,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(89)
		::openfl::display::Graphics_obj::lime_gfx_draw_ellipse(this->__handle,x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawEllipse,(void))

Void Graphics_obj::drawGraphicsData( Array< ::Dynamic > graphicsData){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawGraphicsData",0x60ea9412,"openfl.display.Graphics.drawGraphicsData","openfl/display/Graphics.hx",94,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(graphicsData,"graphicsData")
		HX_STACK_LINE(96)
		Dynamic handles = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(handles,"handles");
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			while((true)){
				HX_STACK_LINE(98)
				if ((!(((_g < graphicsData->length))))){
					HX_STACK_LINE(98)
					break;
				}
				HX_STACK_LINE(98)
				::openfl::display::IGraphicsData datum = graphicsData->__get(_g).StaticCast< ::openfl::display::IGraphicsData >();		HX_STACK_VAR(datum,"datum");
				HX_STACK_LINE(98)
				++(_g);
				HX_STACK_LINE(100)
				handles->__Field(HX_CSTRING("push"),true)(datum->__handle);
			}
		}
		HX_STACK_LINE(104)
		::openfl::display::Graphics_obj::lime_gfx_draw_data(this->__handle,handles);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsData,(void))

Void Graphics_obj::drawGraphicsDatum( ::openfl::display::IGraphicsData graphicsDatum){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawGraphicsDatum",0x6c570d87,"openfl.display.Graphics.drawGraphicsDatum","openfl/display/Graphics.hx",111,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(graphicsDatum,"graphicsDatum")
		HX_STACK_LINE(111)
		::openfl::display::Graphics_obj::lime_gfx_draw_datum(this->__handle,graphicsDatum->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsDatum,(void))

Void Graphics_obj::drawPoints( Array< Float > xy,Array< int > pointRGBA,hx::Null< int >  __o_defaultRGBA,hx::Null< Float >  __o_size){
int defaultRGBA = __o_defaultRGBA.Default(-1);
Float size = __o_size.Default(-1.0);
	HX_STACK_FRAME("openfl.display.Graphics","drawPoints",0x8f857de0,"openfl.display.Graphics.drawPoints","openfl/display/Graphics.hx",118,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xy,"xy")
	HX_STACK_ARG(pointRGBA,"pointRGBA")
	HX_STACK_ARG(defaultRGBA,"defaultRGBA")
	HX_STACK_ARG(size,"size")
{
		HX_STACK_LINE(118)
		::openfl::display::Graphics_obj::lime_gfx_draw_points(this->__handle,xy,pointRGBA,defaultRGBA,false,size);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawPoints,(void))

Void Graphics_obj::drawRect( Float x,Float y,Float width,Float height){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawRect",0xa1f75fa1,"openfl.display.Graphics.drawRect","openfl/display/Graphics.hx",125,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(125)
		::openfl::display::Graphics_obj::lime_gfx_draw_rect(this->__handle,x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawRect,(void))

Void Graphics_obj::drawRoundRect( Float x,Float y,Float width,Float height,Float radiusX,Dynamic radiusY){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawRoundRect",0xb24e78f5,"openfl.display.Graphics.drawRoundRect","openfl/display/Graphics.hx",132,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_ARG(radiusX,"radiusX")
		HX_STACK_ARG(radiusY,"radiusY")
		HX_STACK_LINE(132)
		::openfl::display::Graphics_obj::lime_gfx_draw_round_rect(this->__handle,x,y,width,height,radiusX,(  (((radiusY == null()))) ? Dynamic(radiusX) : Dynamic(radiusY) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawRoundRect,(void))

Void Graphics_obj::drawRoundRectComplex( Float x,Float y,Float width,Float height,Float topLeftRadius,Float topRightRadius,Float bottomLeftRadius,Float bottomRightRadius){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawRoundRectComplex",0x06fa4dbb,"openfl.display.Graphics.drawRoundRectComplex","openfl/display/Graphics.hx",139,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_ARG(topLeftRadius,"topLeftRadius")
		HX_STACK_ARG(topRightRadius,"topRightRadius")
		HX_STACK_ARG(bottomLeftRadius,"bottomLeftRadius")
		HX_STACK_ARG(bottomRightRadius,"bottomRightRadius")
		HX_STACK_LINE(139)
		::openfl::Lib_obj::notImplemented(HX_CSTRING("Graphics.drawRoundRectComplex"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,drawRoundRectComplex,(void))

Void Graphics_obj::drawPath( Array< int > commands,Array< Float > data,::openfl::display::GraphicsPathWinding winding){
{
		HX_STACK_FRAME("openfl.display.Graphics","drawPath",0xa0a1f822,"openfl.display.Graphics.drawPath","openfl/display/Graphics.hx",146,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(commands,"commands")
		HX_STACK_ARG(data,"data")
		HX_STACK_ARG(winding,"winding")
		HX_STACK_LINE(146)
		::openfl::display::Graphics_obj::lime_gfx_draw_path(this->__handle,commands,data,(winding == ::openfl::display::GraphicsPathWinding_obj::EVEN_ODD));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawPath,(void))

Void Graphics_obj::drawTiles( ::openfl::display::Tilesheet sheet,Array< Float > data,hx::Null< bool >  __o_smooth,hx::Null< int >  __o_flags,hx::Null< int >  __o_count){
bool smooth = __o_smooth.Default(false);
int flags = __o_flags.Default(0);
int count = __o_count.Default(-1);
	HX_STACK_FRAME("openfl.display.Graphics","drawTiles",0x3ff51868,"openfl.display.Graphics.drawTiles","openfl/display/Graphics.hx",151,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(sheet,"sheet")
	HX_STACK_ARG(data,"data")
	HX_STACK_ARG(smooth,"smooth")
	HX_STACK_ARG(flags,"flags")
	HX_STACK_ARG(count,"count")
{
		HX_STACK_LINE(153)
		this->beginBitmapFill(sheet->__bitmap,null(),false,smooth);
		HX_STACK_LINE(155)
		if ((smooth)){
			HX_STACK_LINE(157)
			hx::OrEq(flags,(int)4096);
		}
		HX_STACK_LINE(161)
		::openfl::display::Graphics_obj::lime_gfx_draw_tiles(this->__handle,sheet->__handle,data,flags,count);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Graphics_obj,drawTiles,(void))

Void Graphics_obj::drawTriangles( Array< Float > vertices,Array< int > indices,Array< Float > uvtData,::openfl::display::TriangleCulling culling,Array< int > colors,hx::Null< int >  __o_blendMode){
int blendMode = __o_blendMode.Default(0);
	HX_STACK_FRAME("openfl.display.Graphics","drawTriangles",0xae0bf90e,"openfl.display.Graphics.drawTriangles","openfl/display/Graphics.hx",166,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vertices,"vertices")
	HX_STACK_ARG(indices,"indices")
	HX_STACK_ARG(uvtData,"uvtData")
	HX_STACK_ARG(culling,"culling")
	HX_STACK_ARG(colors,"colors")
	HX_STACK_ARG(blendMode,"blendMode")
{
		HX_STACK_LINE(168)
		int cull;		HX_STACK_VAR(cull,"cull");
		HX_STACK_LINE(168)
		if (((culling == null()))){
			HX_STACK_LINE(168)
			cull = (int)0;
		}
		else{
			HX_STACK_LINE(168)
			int _g = culling->__Index();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(168)
			cull = (_g - (int)1);
		}
		HX_STACK_LINE(169)
		::openfl::display::Graphics_obj::lime_gfx_draw_triangles(this->__handle,vertices,indices,uvtData,cull,colors,blendMode);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawTriangles,(void))

Void Graphics_obj::endFill( ){
{
		HX_STACK_FRAME("openfl.display.Graphics","endFill",0xe14b2dc5,"openfl.display.Graphics.endFill","openfl/display/Graphics.hx",176,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(176)
		::openfl::display::Graphics_obj::lime_gfx_end_fill(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,endFill,(void))

Void Graphics_obj::lineBitmapStyle( ::openfl::display::BitmapData bitmap,::openfl::geom::Matrix matrix,hx::Null< bool >  __o_repeat,hx::Null< bool >  __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_STACK_FRAME("openfl.display.Graphics","lineBitmapStyle",0x0ce183f5,"openfl.display.Graphics.lineBitmapStyle","openfl/display/Graphics.hx",183,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bitmap,"bitmap")
	HX_STACK_ARG(matrix,"matrix")
	HX_STACK_ARG(repeat,"repeat")
	HX_STACK_ARG(smooth,"smooth")
{
		HX_STACK_LINE(183)
		::openfl::display::Graphics_obj::lime_gfx_line_bitmap_fill(this->__handle,bitmap->__handle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,lineBitmapStyle,(void))

Void Graphics_obj::lineGradientStyle( ::openfl::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::openfl::geom::Matrix matrix,::openfl::display::SpreadMethod spreadMethod,::openfl::display::InterpolationMethod interpolationMethod,hx::Null< Float >  __o_focalPointRatio){
Float focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_STACK_FRAME("openfl.display.Graphics","lineGradientStyle",0x2de26914,"openfl.display.Graphics.lineGradientStyle","openfl/display/Graphics.hx",188,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(colors,"colors")
	HX_STACK_ARG(alphas,"alphas")
	HX_STACK_ARG(ratios,"ratios")
	HX_STACK_ARG(matrix,"matrix")
	HX_STACK_ARG(spreadMethod,"spreadMethod")
	HX_STACK_ARG(interpolationMethod,"interpolationMethod")
	HX_STACK_ARG(focalPointRatio,"focalPointRatio")
{
		HX_STACK_LINE(190)
		if (((matrix == null()))){
			HX_STACK_LINE(192)
			::openfl::geom::Matrix _g = ::openfl::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(192)
			matrix = _g;
			HX_STACK_LINE(193)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_STACK_LINE(197)
		int _g1 = type->__Index();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(197)
		int _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(197)
		if (((spreadMethod == null()))){
			HX_STACK_LINE(197)
			_g2 = (int)0;
		}
		else{
			HX_STACK_LINE(197)
			_g2 = spreadMethod->__Index();
		}
		HX_STACK_LINE(197)
		int _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(197)
		if (((interpolationMethod == null()))){
			HX_STACK_LINE(197)
			_g3 = (int)0;
		}
		else{
			HX_STACK_LINE(197)
			_g3 = interpolationMethod->__Index();
		}
		HX_STACK_LINE(197)
		::openfl::display::Graphics_obj::lime_gfx_line_gradient_fill(this->__handle,_g1,colors,alphas,ratios,matrix,_g2,_g3,focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineGradientStyle,(void))

Void Graphics_obj::lineStyle( Dynamic thickness,hx::Null< int >  __o_color,hx::Null< Float >  __o_alpha,hx::Null< bool >  __o_pixelHinting,::openfl::display::LineScaleMode scaleMode,::openfl::display::CapsStyle caps,::openfl::display::JointStyle joints,hx::Null< Float >  __o_miterLimit){
int color = __o_color.Default(0);
Float alpha = __o_alpha.Default(1.0);
bool pixelHinting = __o_pixelHinting.Default(false);
Float miterLimit = __o_miterLimit.Default(3);
	HX_STACK_FRAME("openfl.display.Graphics","lineStyle",0x32cd8e24,"openfl.display.Graphics.lineStyle","openfl/display/Graphics.hx",202,0x8d299ce7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(thickness,"thickness")
	HX_STACK_ARG(color,"color")
	HX_STACK_ARG(alpha,"alpha")
	HX_STACK_ARG(pixelHinting,"pixelHinting")
	HX_STACK_ARG(scaleMode,"scaleMode")
	HX_STACK_ARG(caps,"caps")
	HX_STACK_ARG(joints,"joints")
	HX_STACK_ARG(miterLimit,"miterLimit")
{
		HX_STACK_LINE(204)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(204)
		if (((scaleMode == null()))){
			HX_STACK_LINE(204)
			_g = (int)0;
		}
		else{
			HX_STACK_LINE(204)
			_g = scaleMode->__Index();
		}
		HX_STACK_LINE(204)
		int _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(204)
		if (((caps == null()))){
			HX_STACK_LINE(204)
			_g1 = (int)0;
		}
		else{
			HX_STACK_LINE(204)
			_g1 = caps->__Index();
		}
		HX_STACK_LINE(204)
		int _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(204)
		if (((joints == null()))){
			HX_STACK_LINE(204)
			_g2 = (int)0;
		}
		else{
			HX_STACK_LINE(204)
			_g2 = joints->__Index();
		}
		HX_STACK_LINE(204)
		::openfl::display::Graphics_obj::lime_gfx_line_style(this->__handle,thickness,color,alpha,pixelHinting,_g,_g1,_g2,miterLimit);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineStyle,(void))

Void Graphics_obj::lineTo( Float x,Float y){
{
		HX_STACK_FRAME("openfl.display.Graphics","lineTo",0x25b7b6a8,"openfl.display.Graphics.lineTo","openfl/display/Graphics.hx",211,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(211)
		::openfl::display::Graphics_obj::lime_gfx_line_to(this->__handle,x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,lineTo,(void))

Void Graphics_obj::moveTo( Float x,Float y){
{
		HX_STACK_FRAME("openfl.display.Graphics","moveTo",0x05c44305,"openfl.display.Graphics.moveTo","openfl/display/Graphics.hx",218,0x8d299ce7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(218)
		::openfl::display::Graphics_obj::lime_gfx_move_to(this->__handle,x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,moveTo,(void))

int Graphics_obj::TILE_SCALE;

int Graphics_obj::TILE_ROTATION;

int Graphics_obj::TILE_RGB;

int Graphics_obj::TILE_ALPHA;

int Graphics_obj::TILE_TRANS_2x2;

int Graphics_obj::TILE_SMOOTH;

int Graphics_obj::TILE_BLEND_NORMAL;

int Graphics_obj::TILE_BLEND_ADD;

int Graphics_obj::RGBA( int rgb,hx::Null< int >  __o_alpha){
int alpha = __o_alpha.Default(255);
	HX_STACK_FRAME("openfl.display.Graphics","RGBA",0x4acca08d,"openfl.display.Graphics.RGBA","openfl/display/Graphics.hx",225,0x8d299ce7)
	HX_STACK_ARG(rgb,"rgb")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(225)
		return (int(rgb) | int((int(alpha) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,RGBA,return )

Dynamic Graphics_obj::lime_gfx_clear;

Dynamic Graphics_obj::lime_gfx_begin_fill;

Dynamic Graphics_obj::lime_gfx_begin_bitmap_fill;

Dynamic Graphics_obj::lime_gfx_line_bitmap_fill;

Dynamic Graphics_obj::lime_gfx_begin_gradient_fill;

Dynamic Graphics_obj::lime_gfx_line_gradient_fill;

Dynamic Graphics_obj::lime_gfx_end_fill;

Dynamic Graphics_obj::lime_gfx_line_style;

Dynamic Graphics_obj::lime_gfx_move_to;

Dynamic Graphics_obj::lime_gfx_line_to;

Dynamic Graphics_obj::lime_gfx_curve_to;

Dynamic Graphics_obj::lime_gfx_arc_to;

Dynamic Graphics_obj::lime_gfx_draw_ellipse;

Dynamic Graphics_obj::lime_gfx_draw_data;

Dynamic Graphics_obj::lime_gfx_draw_datum;

Dynamic Graphics_obj::lime_gfx_draw_rect;

Dynamic Graphics_obj::lime_gfx_draw_path;

Dynamic Graphics_obj::lime_gfx_draw_tiles;

Dynamic Graphics_obj::lime_gfx_draw_points;

Dynamic Graphics_obj::lime_gfx_draw_round_rect;

Dynamic Graphics_obj::lime_gfx_draw_triangles;


Graphics_obj::Graphics_obj()
{
}

void Graphics_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Graphics);
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_END_CLASS();
}

void Graphics_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
}

Dynamic Graphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"RGBA") ) { return RGBA_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"arcTo") ) { return arcTo_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPath") ) { return drawPath_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPoints") ) { return drawPoints_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"drawRoundRect") ) { return drawRoundRect_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTriangles") ) { return drawTriangles_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lime_gfx_clear") ) { return lime_gfx_clear; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"lime_gfx_arc_to") ) { return lime_gfx_arc_to; }
		if (HX_FIELD_EQ(inName,"beginBitmapFill") ) { return beginBitmapFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineBitmapStyle") ) { return lineBitmapStyle_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_gfx_move_to") ) { return lime_gfx_move_to; }
		if (HX_FIELD_EQ(inName,"lime_gfx_line_to") ) { return lime_gfx_line_to; }
		if (HX_FIELD_EQ(inName,"drawGraphicsData") ) { return drawGraphicsData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"lime_gfx_end_fill") ) { return lime_gfx_end_fill; }
		if (HX_FIELD_EQ(inName,"lime_gfx_curve_to") ) { return lime_gfx_curve_to; }
		if (HX_FIELD_EQ(inName,"beginGradientFill") ) { return beginGradientFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawGraphicsDatum") ) { return drawGraphicsDatum_dyn(); }
		if (HX_FIELD_EQ(inName,"lineGradientStyle") ) { return lineGradientStyle_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_data") ) { return lime_gfx_draw_data; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_rect") ) { return lime_gfx_draw_rect; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_path") ) { return lime_gfx_draw_path; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_fill") ) { return lime_gfx_begin_fill; }
		if (HX_FIELD_EQ(inName,"lime_gfx_line_style") ) { return lime_gfx_line_style; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_datum") ) { return lime_gfx_draw_datum; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_tiles") ) { return lime_gfx_draw_tiles; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_points") ) { return lime_gfx_draw_points; }
		if (HX_FIELD_EQ(inName,"drawRoundRectComplex") ) { return drawRoundRectComplex_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_ellipse") ) { return lime_gfx_draw_ellipse; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_triangles") ) { return lime_gfx_draw_triangles; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_round_rect") ) { return lime_gfx_draw_round_rect; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_gfx_line_bitmap_fill") ) { return lime_gfx_line_bitmap_fill; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_bitmap_fill") ) { return lime_gfx_begin_bitmap_fill; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_gfx_line_gradient_fill") ) { return lime_gfx_line_gradient_fill; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_gradient_fill") ) { return lime_gfx_begin_gradient_fill; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lime_gfx_clear") ) { lime_gfx_clear=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"lime_gfx_arc_to") ) { lime_gfx_arc_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_gfx_move_to") ) { lime_gfx_move_to=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_line_to") ) { lime_gfx_line_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"lime_gfx_end_fill") ) { lime_gfx_end_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_curve_to") ) { lime_gfx_curve_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_data") ) { lime_gfx_draw_data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_rect") ) { lime_gfx_draw_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_path") ) { lime_gfx_draw_path=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_fill") ) { lime_gfx_begin_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_line_style") ) { lime_gfx_line_style=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_datum") ) { lime_gfx_draw_datum=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_tiles") ) { lime_gfx_draw_tiles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_points") ) { lime_gfx_draw_points=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_ellipse") ) { lime_gfx_draw_ellipse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_triangles") ) { lime_gfx_draw_triangles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_gfx_draw_round_rect") ) { lime_gfx_draw_round_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_gfx_line_bitmap_fill") ) { lime_gfx_line_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_bitmap_fill") ) { lime_gfx_begin_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_gfx_line_gradient_fill") ) { lime_gfx_line_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_gfx_begin_gradient_fill") ) { lime_gfx_begin_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__handle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("TILE_TRANS_2x2"),
	HX_CSTRING("TILE_SMOOTH"),
	HX_CSTRING("TILE_BLEND_NORMAL"),
	HX_CSTRING("TILE_BLEND_ADD"),
	HX_CSTRING("RGBA"),
	HX_CSTRING("lime_gfx_clear"),
	HX_CSTRING("lime_gfx_begin_fill"),
	HX_CSTRING("lime_gfx_begin_bitmap_fill"),
	HX_CSTRING("lime_gfx_line_bitmap_fill"),
	HX_CSTRING("lime_gfx_begin_gradient_fill"),
	HX_CSTRING("lime_gfx_line_gradient_fill"),
	HX_CSTRING("lime_gfx_end_fill"),
	HX_CSTRING("lime_gfx_line_style"),
	HX_CSTRING("lime_gfx_move_to"),
	HX_CSTRING("lime_gfx_line_to"),
	HX_CSTRING("lime_gfx_curve_to"),
	HX_CSTRING("lime_gfx_arc_to"),
	HX_CSTRING("lime_gfx_draw_ellipse"),
	HX_CSTRING("lime_gfx_draw_data"),
	HX_CSTRING("lime_gfx_draw_datum"),
	HX_CSTRING("lime_gfx_draw_rect"),
	HX_CSTRING("lime_gfx_draw_path"),
	HX_CSTRING("lime_gfx_draw_tiles"),
	HX_CSTRING("lime_gfx_draw_points"),
	HX_CSTRING("lime_gfx_draw_round_rect"),
	HX_CSTRING("lime_gfx_draw_triangles"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Graphics_obj,__handle),HX_CSTRING("__handle")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__handle"),
	HX_CSTRING("arcTo"),
	HX_CSTRING("beginBitmapFill"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("beginGradientFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawGraphicsData"),
	HX_CSTRING("drawGraphicsDatum"),
	HX_CSTRING("drawPoints"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawRoundRect"),
	HX_CSTRING("drawRoundRectComplex"),
	HX_CSTRING("drawPath"),
	HX_CSTRING("drawTiles"),
	HX_CSTRING("drawTriangles"),
	HX_CSTRING("endFill"),
	HX_CSTRING("lineBitmapStyle"),
	HX_CSTRING("lineGradientStyle"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_TRANS_2x2,"TILE_TRANS_2x2");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SMOOTH,"TILE_SMOOTH");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_clear,"lime_gfx_clear");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_begin_fill,"lime_gfx_begin_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_begin_bitmap_fill,"lime_gfx_begin_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_line_bitmap_fill,"lime_gfx_line_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_begin_gradient_fill,"lime_gfx_begin_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_line_gradient_fill,"lime_gfx_line_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_end_fill,"lime_gfx_end_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_line_style,"lime_gfx_line_style");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_move_to,"lime_gfx_move_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_line_to,"lime_gfx_line_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_curve_to,"lime_gfx_curve_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_arc_to,"lime_gfx_arc_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_ellipse,"lime_gfx_draw_ellipse");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_data,"lime_gfx_draw_data");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_datum,"lime_gfx_draw_datum");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_rect,"lime_gfx_draw_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_path,"lime_gfx_draw_path");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_tiles,"lime_gfx_draw_tiles");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_points,"lime_gfx_draw_points");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_round_rect,"lime_gfx_draw_round_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::lime_gfx_draw_triangles,"lime_gfx_draw_triangles");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_SCALE,"TILE_SCALE");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_RGB,"TILE_RGB");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_TRANS_2x2,"TILE_TRANS_2x2");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_SMOOTH,"TILE_SMOOTH");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_VISIT_MEMBER_NAME(Graphics_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_clear,"lime_gfx_clear");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_begin_fill,"lime_gfx_begin_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_begin_bitmap_fill,"lime_gfx_begin_bitmap_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_line_bitmap_fill,"lime_gfx_line_bitmap_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_begin_gradient_fill,"lime_gfx_begin_gradient_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_line_gradient_fill,"lime_gfx_line_gradient_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_end_fill,"lime_gfx_end_fill");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_line_style,"lime_gfx_line_style");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_move_to,"lime_gfx_move_to");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_line_to,"lime_gfx_line_to");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_curve_to,"lime_gfx_curve_to");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_arc_to,"lime_gfx_arc_to");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_ellipse,"lime_gfx_draw_ellipse");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_data,"lime_gfx_draw_data");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_datum,"lime_gfx_draw_datum");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_rect,"lime_gfx_draw_rect");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_path,"lime_gfx_draw_path");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_tiles,"lime_gfx_draw_tiles");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_points,"lime_gfx_draw_points");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_round_rect,"lime_gfx_draw_round_rect");
	HX_VISIT_MEMBER_NAME(Graphics_obj::lime_gfx_draw_triangles,"lime_gfx_draw_triangles");
};

#endif

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
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

void Graphics_obj::__boot()
{
	TILE_SCALE= (int)1;
	TILE_ROTATION= (int)2;
	TILE_RGB= (int)4;
	TILE_ALPHA= (int)8;
	TILE_TRANS_2x2= (int)16;
	TILE_SMOOTH= (int)4096;
	TILE_BLEND_NORMAL= (int)0;
	TILE_BLEND_ADD= (int)65536;
	lime_gfx_clear= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_clear"),(int)1);
	lime_gfx_begin_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_begin_fill"),(int)3);
	lime_gfx_begin_bitmap_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_begin_bitmap_fill"),(int)5);
	lime_gfx_line_bitmap_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_line_bitmap_fill"),(int)5);
	lime_gfx_begin_gradient_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_begin_gradient_fill"),(int)-1);
	lime_gfx_line_gradient_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_line_gradient_fill"),(int)-1);
	lime_gfx_end_fill= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_end_fill"),(int)1);
	lime_gfx_line_style= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_line_style"),(int)-1);
	lime_gfx_move_to= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_move_to"),(int)3);
	lime_gfx_line_to= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_line_to"),(int)3);
	lime_gfx_curve_to= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_curve_to"),(int)5);
	lime_gfx_arc_to= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_arc_to"),(int)5);
	lime_gfx_draw_ellipse= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_ellipse"),(int)5);
	lime_gfx_draw_data= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_data"),(int)2);
	lime_gfx_draw_datum= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_datum"),(int)2);
	lime_gfx_draw_rect= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_rect"),(int)5);
	lime_gfx_draw_path= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_path"),(int)4);
	lime_gfx_draw_tiles= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_tiles"),(int)5);
	lime_gfx_draw_points= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_points"),(int)-1);
	lime_gfx_draw_round_rect= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_round_rect"),(int)-1);
	lime_gfx_draw_triangles= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_gfx_draw_triangles"),(int)-1);
}

} // end namespace openfl
} // end namespace display
