#include <hxcpp.h>

#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
namespace openfl{
namespace geom{

Void Rectangle_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{
HX_STACK_FRAME("openfl.geom.Rectangle","new",0xe1148d6d,"openfl.geom.Rectangle.new","openfl/geom/Rectangle.hx",20,0xf2fb2b03)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_x,"x")
HX_STACK_ARG(__o_y,"y")
HX_STACK_ARG(__o_width,"width")
HX_STACK_ARG(__o_height,"height")
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float width = __o_width.Default(0);
Float height = __o_height.Default(0);
{
	HX_STACK_LINE(22)
	this->x = x;
	HX_STACK_LINE(23)
	this->y = y;
	HX_STACK_LINE(24)
	this->width = width;
	HX_STACK_LINE(25)
	this->height = height;
}
;
	return null();
}

//Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(__o_x,__o_y,__o_width,__o_height);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::openfl::geom::Rectangle Rectangle_obj::clone( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","clone",0x6896edaa,"openfl.geom.Rectangle.clone","openfl/geom/Rectangle.hx",32,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	return ::openfl::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )

bool Rectangle_obj::contains( Float x,Float y){
	HX_STACK_FRAME("openfl.geom.Rectangle","contains",0x39912df2,"openfl.geom.Rectangle.contains","openfl/geom/Rectangle.hx",39,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	struct _Function_1_1{
		inline static bool Block( hx::ObjectPtr< ::openfl::geom::Rectangle_obj > __this,Float &x){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/geom/Rectangle.hx",39,0xf2fb2b03)
			{
				HX_STACK_LINE(39)
				Float _g = __this->get_right();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(39)
				return (x < _g);
			}
			return null();
		}
	};
	HX_STACK_LINE(39)
	if (((  (((bool((x >= this->x)) && bool((y >= this->y))))) ? bool(_Function_1_1::Block(this,x)) : bool(false) ))){
		HX_STACK_LINE(39)
		Float _g1 = this->get_bottom();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(39)
		return (y < _g1);
	}
	else{
		HX_STACK_LINE(39)
		return false;
	}
	HX_STACK_LINE(39)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

bool Rectangle_obj::containsPoint( ::openfl::geom::Point point){
	HX_STACK_FRAME("openfl.geom.Rectangle","containsPoint",0xa42628fe,"openfl.geom.Rectangle.containsPoint","openfl/geom/Rectangle.hx",46,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(46)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::containsRect( ::openfl::geom::Rectangle rect){
	HX_STACK_FRAME("openfl.geom.Rectangle","containsRect",0x6ba48836,"openfl.geom.Rectangle.containsRect","openfl/geom/Rectangle.hx",53,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rect,"rect")
	HX_STACK_LINE(53)
	if (((bool((rect->width <= (int)0)) || bool((rect->height <= (int)0))))){
		struct _Function_2_1{
			inline static bool Block( hx::ObjectPtr< ::openfl::geom::Rectangle_obj > __this,::openfl::geom::Rectangle &rect){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/geom/Rectangle.hx",55,0xf2fb2b03)
				{
					HX_STACK_LINE(55)
					Float _g = rect->get_right();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(55)
					Float _g1 = __this->get_right();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(55)
					return (_g < _g1);
				}
				return null();
			}
		};
		HX_STACK_LINE(55)
		if (((  (((bool((rect->x > this->x)) && bool((rect->y > this->y))))) ? bool(_Function_2_1::Block(this,rect)) : bool(false) ))){
			HX_STACK_LINE(55)
			Float _g2 = rect->get_bottom();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(55)
			Float _g3 = this->get_bottom();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(55)
			return (_g2 < _g3);
		}
		else{
			HX_STACK_LINE(55)
			return false;
		}
	}
	else{
		struct _Function_2_1{
			inline static bool Block( hx::ObjectPtr< ::openfl::geom::Rectangle_obj > __this,::openfl::geom::Rectangle &rect){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/geom/Rectangle.hx",59,0xf2fb2b03)
				{
					HX_STACK_LINE(59)
					Float _g4 = rect->get_right();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(59)
					Float _g5 = __this->get_right();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(59)
					return (_g4 <= _g5);
				}
				return null();
			}
		};
		HX_STACK_LINE(59)
		if (((  (((bool((rect->x >= this->x)) && bool((rect->y >= this->y))))) ? bool(_Function_2_1::Block(this,rect)) : bool(false) ))){
			HX_STACK_LINE(59)
			Float _g6 = rect->get_bottom();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(59)
			Float _g7 = this->get_bottom();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(59)
			return (_g6 <= _g7);
		}
		else{
			HX_STACK_LINE(59)
			return false;
		}
	}
	HX_STACK_LINE(53)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

Void Rectangle_obj::copyFrom( ::openfl::geom::Rectangle sourceRect){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","copyFrom",0xd576df92,"openfl.geom.Rectangle.copyFrom","openfl/geom/Rectangle.hx",66,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(sourceRect,"sourceRect")
		HX_STACK_LINE(68)
		this->x = sourceRect->x;
		HX_STACK_LINE(69)
		this->y = sourceRect->y;
		HX_STACK_LINE(70)
		this->width = sourceRect->width;
		HX_STACK_LINE(71)
		this->height = sourceRect->height;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,copyFrom,(void))

bool Rectangle_obj::equals( ::openfl::geom::Rectangle toCompare){
	HX_STACK_FRAME("openfl.geom.Rectangle","equals",0xcd1e1752,"openfl.geom.Rectangle.equals","openfl/geom/Rectangle.hx",78,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(toCompare,"toCompare")
	HX_STACK_LINE(78)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

Void Rectangle_obj::extendBounds( ::openfl::geom::Rectangle r){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","extendBounds",0xe60e6542,"openfl.geom.Rectangle.extendBounds","openfl/geom/Rectangle.hx",83,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(85)
		Float dx = (this->x - r->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(86)
		if (((dx > (int)0))){
			HX_STACK_LINE(88)
			hx::SubEq(this->x,dx);
			HX_STACK_LINE(89)
			hx::AddEq(this->width,dx);
		}
		HX_STACK_LINE(93)
		Float dy = (this->y - r->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(94)
		if (((dy > (int)0))){
			HX_STACK_LINE(96)
			hx::SubEq(this->y,dy);
			HX_STACK_LINE(97)
			hx::AddEq(this->height,dy);
		}
		HX_STACK_LINE(101)
		Float _g = r->get_right();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(101)
		Float _g1 = this->get_right();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(101)
		if (((_g > _g1))){
			HX_STACK_LINE(103)
			Float _g2 = r->get_right();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(103)
			this->set_right(_g2);
		}
		HX_STACK_LINE(107)
		Float _g3 = r->get_bottom();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(107)
		Float _g4 = this->get_bottom();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(107)
		if (((_g3 > _g4))){
			HX_STACK_LINE(109)
			Float _g5 = r->get_bottom();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(109)
			this->set_bottom(_g5);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))

Void Rectangle_obj::inflate( Float dx,Float dy){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","inflate",0x84b46414,"openfl.geom.Rectangle.inflate","openfl/geom/Rectangle.hx",116,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(dx,"dx")
		HX_STACK_ARG(dy,"dy")
		HX_STACK_LINE(118)
		hx::SubEq(this->x,dx);
		HX_STACK_LINE(119)
		hx::SubEq(this->y,dy);
		HX_STACK_LINE(120)
		hx::AddEq(this->width,(dx * (int)2));
		HX_STACK_LINE(121)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::inflatePoint( ::openfl::geom::Point point){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","inflatePoint",0xf7c1779c,"openfl.geom.Rectangle.inflatePoint","openfl/geom/Rectangle.hx",128,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(128)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

::openfl::geom::Rectangle Rectangle_obj::intersection( ::openfl::geom::Rectangle toIntersect){
	HX_STACK_FRAME("openfl.geom.Rectangle","intersection",0x4de95b9c,"openfl.geom.Rectangle.intersection","openfl/geom/Rectangle.hx",133,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(toIntersect,"toIntersect")
	HX_STACK_LINE(135)
	Float x0;		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(135)
	if (((this->x < toIntersect->x))){
		HX_STACK_LINE(135)
		x0 = toIntersect->x;
	}
	else{
		HX_STACK_LINE(135)
		x0 = this->x;
	}
	HX_STACK_LINE(136)
	Float _g = this->get_right();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(136)
	Float _g1 = toIntersect->get_right();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(136)
	Float x1;		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(136)
	if (((_g > _g1))){
		HX_STACK_LINE(136)
		x1 = toIntersect->get_right();
	}
	else{
		HX_STACK_LINE(136)
		x1 = this->get_right();
	}
	HX_STACK_LINE(137)
	if (((x1 <= x0))){
		HX_STACK_LINE(139)
		return ::openfl::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(143)
	Float y0;		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(143)
	if (((this->y < toIntersect->y))){
		HX_STACK_LINE(143)
		y0 = toIntersect->y;
	}
	else{
		HX_STACK_LINE(143)
		y0 = this->y;
	}
	HX_STACK_LINE(144)
	Float _g2 = this->get_bottom();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(144)
	Float _g3 = toIntersect->get_bottom();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(144)
	Float y1;		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(144)
	if (((_g2 > _g3))){
		HX_STACK_LINE(144)
		y1 = toIntersect->get_bottom();
	}
	else{
		HX_STACK_LINE(144)
		y1 = this->get_bottom();
	}
	HX_STACK_LINE(145)
	if (((y1 <= y0))){
		HX_STACK_LINE(147)
		return ::openfl::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(151)
	return ::openfl::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

bool Rectangle_obj::intersects( ::openfl::geom::Rectangle toIntersect){
	HX_STACK_FRAME("openfl.geom.Rectangle","intersects",0xc0fc7147,"openfl.geom.Rectangle.intersects","openfl/geom/Rectangle.hx",156,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(toIntersect,"toIntersect")
	HX_STACK_LINE(158)
	Float x0;		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(158)
	if (((this->x < toIntersect->x))){
		HX_STACK_LINE(158)
		x0 = toIntersect->x;
	}
	else{
		HX_STACK_LINE(158)
		x0 = this->x;
	}
	HX_STACK_LINE(159)
	Float _g = this->get_right();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(159)
	Float _g1 = toIntersect->get_right();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(159)
	Float x1;		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(159)
	if (((_g > _g1))){
		HX_STACK_LINE(159)
		x1 = toIntersect->get_right();
	}
	else{
		HX_STACK_LINE(159)
		x1 = this->get_right();
	}
	HX_STACK_LINE(160)
	if (((x1 <= x0))){
		HX_STACK_LINE(162)
		return false;
	}
	HX_STACK_LINE(166)
	Float y0;		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(166)
	if (((this->y < toIntersect->y))){
		HX_STACK_LINE(166)
		y0 = toIntersect->y;
	}
	else{
		HX_STACK_LINE(166)
		y0 = this->y;
	}
	HX_STACK_LINE(167)
	Float _g2 = this->get_bottom();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(167)
	Float _g3 = toIntersect->get_bottom();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(167)
	Float y1;		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(167)
	if (((_g2 > _g3))){
		HX_STACK_LINE(167)
		y1 = toIntersect->get_bottom();
	}
	else{
		HX_STACK_LINE(167)
		y1 = this->get_bottom();
	}
	HX_STACK_LINE(168)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

bool Rectangle_obj::isEmpty( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","isEmpty",0x84f8a5d0,"openfl.geom.Rectangle.isEmpty","openfl/geom/Rectangle.hx",175,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(175)
	return (bool((this->width <= (int)0)) || bool((this->height <= (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

Void Rectangle_obj::offset( Float dx,Float dy){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","offset",0x6d6ac0a6,"openfl.geom.Rectangle.offset","openfl/geom/Rectangle.hx",180,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(dx,"dx")
		HX_STACK_ARG(dy,"dy")
		HX_STACK_LINE(182)
		hx::AddEq(this->x,dx);
		HX_STACK_LINE(183)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

Void Rectangle_obj::offsetPoint( ::openfl::geom::Point point){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","offsetPoint",0xf09849ca,"openfl.geom.Rectangle.offsetPoint","openfl/geom/Rectangle.hx",188,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(190)
		hx::AddEq(this->x,point->x);
		HX_STACK_LINE(191)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::setEmpty( ){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","setEmpty",0x8b24775e,"openfl.geom.Rectangle.setEmpty","openfl/geom/Rectangle.hx",196,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(198)
		this->x = (int)0;
		HX_STACK_LINE(199)
		this->y = (int)0;
		HX_STACK_LINE(200)
		this->width = (int)0;
		HX_STACK_LINE(201)
		this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

Void Rectangle_obj::setTo( Float xa,Float ya,Float widtha,Float heighta){
{
		HX_STACK_FRAME("openfl.geom.Rectangle","setTo",0x9a636c0a,"openfl.geom.Rectangle.setTo","openfl/geom/Rectangle.hx",206,0xf2fb2b03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xa,"xa")
		HX_STACK_ARG(ya,"ya")
		HX_STACK_ARG(widtha,"widtha")
		HX_STACK_ARG(heighta,"heighta")
		HX_STACK_LINE(208)
		this->x = xa;
		HX_STACK_LINE(209)
		this->y = ya;
		HX_STACK_LINE(210)
		this->width = widtha;
		HX_STACK_LINE(211)
		this->height = heighta;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Rectangle_obj,setTo,(void))

::String Rectangle_obj::toString( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","toString",0x4584a47f,"openfl.geom.Rectangle.toString","openfl/geom/Rectangle.hx",218,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(218)
	return ((((((((HX_CSTRING("(x=") + this->x) + HX_CSTRING(", y=")) + this->y) + HX_CSTRING(", width=")) + this->width) + HX_CSTRING(", height=")) + this->height) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,toString,return )

::openfl::geom::Rectangle Rectangle_obj::transform( ::openfl::geom::Matrix m){
	HX_STACK_FRAME("openfl.geom.Rectangle","transform",0xab96b239,"openfl.geom.Rectangle.transform","openfl/geom/Rectangle.hx",223,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(m,"m")
	HX_STACK_LINE(225)
	Float tx0 = ((m->a * this->x) + (m->c * this->y));		HX_STACK_VAR(tx0,"tx0");
	HX_STACK_LINE(226)
	Float tx1 = tx0;		HX_STACK_VAR(tx1,"tx1");
	HX_STACK_LINE(227)
	Float ty0 = ((m->b * this->x) + (m->d * this->y));		HX_STACK_VAR(ty0,"ty0");
	HX_STACK_LINE(228)
	Float ty1 = tx0;		HX_STACK_VAR(ty1,"ty1");
	HX_STACK_LINE(230)
	Float tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));		HX_STACK_VAR(tx,"tx");
	HX_STACK_LINE(231)
	Float ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));		HX_STACK_VAR(ty,"ty");
	HX_STACK_LINE(232)
	if (((tx < tx0))){
		HX_STACK_LINE(232)
		tx0 = tx;
	}
	HX_STACK_LINE(233)
	if (((ty < ty0))){
		HX_STACK_LINE(233)
		ty0 = ty;
	}
	HX_STACK_LINE(234)
	if (((tx > tx1))){
		HX_STACK_LINE(234)
		tx1 = tx;
	}
	HX_STACK_LINE(235)
	if (((ty > ty1))){
		HX_STACK_LINE(235)
		ty1 = ty;
	}
	HX_STACK_LINE(237)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(238)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(239)
	if (((tx < tx0))){
		HX_STACK_LINE(239)
		tx0 = tx;
	}
	HX_STACK_LINE(240)
	if (((ty < ty0))){
		HX_STACK_LINE(240)
		ty0 = ty;
	}
	HX_STACK_LINE(241)
	if (((tx > tx1))){
		HX_STACK_LINE(241)
		tx1 = tx;
	}
	HX_STACK_LINE(242)
	if (((ty > ty1))){
		HX_STACK_LINE(242)
		ty1 = ty;
	}
	HX_STACK_LINE(244)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(245)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(246)
	if (((tx < tx0))){
		HX_STACK_LINE(246)
		tx0 = tx;
	}
	HX_STACK_LINE(247)
	if (((ty < ty0))){
		HX_STACK_LINE(247)
		ty0 = ty;
	}
	HX_STACK_LINE(248)
	if (((tx > tx1))){
		HX_STACK_LINE(248)
		tx1 = tx;
	}
	HX_STACK_LINE(249)
	if (((ty > ty1))){
		HX_STACK_LINE(249)
		ty1 = ty;
	}
	HX_STACK_LINE(251)
	return ::openfl::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

::openfl::geom::Rectangle Rectangle_obj::_union( ::openfl::geom::Rectangle toUnion){
	HX_STACK_FRAME("openfl.geom.Rectangle","union",0xc71b3f5c,"openfl.geom.Rectangle.union","openfl/geom/Rectangle.hx",256,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(toUnion,"toUnion")
	HX_STACK_LINE(258)
	Float x0;		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(258)
	if (((this->x > toUnion->x))){
		HX_STACK_LINE(258)
		x0 = toUnion->x;
	}
	else{
		HX_STACK_LINE(258)
		x0 = this->x;
	}
	HX_STACK_LINE(259)
	Float _g = this->get_right();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(259)
	Float _g1 = toUnion->get_right();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(259)
	Float x1;		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(259)
	if (((_g < _g1))){
		HX_STACK_LINE(259)
		x1 = toUnion->get_right();
	}
	else{
		HX_STACK_LINE(259)
		x1 = this->get_right();
	}
	HX_STACK_LINE(260)
	Float y0;		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(260)
	if (((this->y > toUnion->y))){
		HX_STACK_LINE(260)
		y0 = toUnion->y;
	}
	else{
		HX_STACK_LINE(260)
		y0 = this->y;
	}
	HX_STACK_LINE(261)
	Float _g2 = this->get_bottom();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(261)
	Float _g3 = toUnion->get_bottom();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(261)
	Float y1;		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(261)
	if (((_g2 < _g3))){
		HX_STACK_LINE(261)
		y1 = toUnion->get_bottom();
	}
	else{
		HX_STACK_LINE(261)
		y1 = this->get_bottom();
	}
	HX_STACK_LINE(262)
	return ::openfl::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

Float Rectangle_obj::get_bottom( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_bottom",0x33110547,"openfl.geom.Rectangle.get_bottom","openfl/geom/Rectangle.hx",274,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(274)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottom,return )

Float Rectangle_obj::set_bottom( Float value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_bottom",0x368ea3bb,"openfl.geom.Rectangle.set_bottom","openfl/geom/Rectangle.hx",275,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(275)
	this->height = (value - this->y);
	HX_STACK_LINE(275)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottom,return )

::openfl::geom::Point Rectangle_obj::get_bottomRight( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_bottomRight",0xb804f515,"openfl.geom.Rectangle.get_bottomRight","openfl/geom/Rectangle.hx",276,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(276)
	return ::openfl::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottomRight,return )

::openfl::geom::Point Rectangle_obj::set_bottomRight( ::openfl::geom::Point value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_bottomRight",0xb3d07221,"openfl.geom.Rectangle.set_bottomRight","openfl/geom/Rectangle.hx",277,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(277)
	this->width = (value->x - this->x);
	HX_STACK_LINE(277)
	this->height = (value->y - this->y);
	HX_STACK_LINE(277)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottomRight,return )

Float Rectangle_obj::get_left( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_left",0xd4809763,"openfl.geom.Rectangle.get_left","openfl/geom/Rectangle.hx",278,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(278)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_left,return )

Float Rectangle_obj::set_left( Float value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_left",0x82ddf0d7,"openfl.geom.Rectangle.set_left","openfl/geom/Rectangle.hx",279,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(279)
	hx::SubEq(this->width,(value - this->x));
	HX_STACK_LINE(279)
	this->x = value;
	HX_STACK_LINE(279)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_left,return )

Float Rectangle_obj::get_right( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_right",0x9310ed00,"openfl.geom.Rectangle.get_right","openfl/geom/Rectangle.hx",280,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(280)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_right,return )

Float Rectangle_obj::set_right( Float value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_right",0x7661d90c,"openfl.geom.Rectangle.set_right","openfl/geom/Rectangle.hx",281,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(281)
	this->width = (value - this->x);
	HX_STACK_LINE(281)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_right,return )

::openfl::geom::Point Rectangle_obj::get_size( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_size",0xd924301d,"openfl.geom.Rectangle.get_size","openfl/geom/Rectangle.hx",282,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(282)
	return ::openfl::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_size,return )

::openfl::geom::Point Rectangle_obj::set_size( ::openfl::geom::Point value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_size",0x87818991,"openfl.geom.Rectangle.set_size","openfl/geom/Rectangle.hx",283,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(283)
	this->width = value->x;
	HX_STACK_LINE(283)
	this->height = value->y;
	HX_STACK_LINE(283)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_size,return )

Float Rectangle_obj::get_top( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_top",0x9f65f6b9,"openfl.geom.Rectangle.get_top","openfl/geom/Rectangle.hx",284,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(284)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_top,return )

Float Rectangle_obj::set_top( Float value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_top",0x926787c5,"openfl.geom.Rectangle.set_top","openfl/geom/Rectangle.hx",285,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(285)
	hx::SubEq(this->height,(value - this->y));
	HX_STACK_LINE(285)
	this->y = value;
	HX_STACK_LINE(285)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_top,return )

::openfl::geom::Point Rectangle_obj::get_topLeft( ){
	HX_STACK_FRAME("openfl.geom.Rectangle","get_topLeft",0x00437b60,"openfl.geom.Rectangle.get_topLeft","openfl/geom/Rectangle.hx",286,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(286)
	return ::openfl::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_topLeft,return )

::openfl::geom::Point Rectangle_obj::set_topLeft( ::openfl::geom::Point value){
	HX_STACK_FRAME("openfl.geom.Rectangle","set_topLeft",0x0ab0826c,"openfl.geom.Rectangle.set_topLeft","openfl/geom/Rectangle.hx",287,0xf2fb2b03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(287)
	this->x = value->x;
	HX_STACK_LINE(287)
	this->y = value->y;
	HX_STACK_LINE(287)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_topLeft,return )


Rectangle_obj::Rectangle_obj()
{
}

Dynamic Rectangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return get_top(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return get_left(); }
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"setTo") ) { return setTo_dyn(); }
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { return get_bottom(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { return get_topLeft(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return get_bottomRight(); }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"get_topLeft") ) { return get_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_topLeft") ) { return set_topLeft_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_bottomRight") ) { return get_bottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottomRight") ) { return set_bottomRight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return set_top(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return set_left(inValue); }
		if (HX_FIELD_EQ(inName,"size") ) { return set_size(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return set_right(inValue); }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { return set_bottom(inValue); }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { return set_topLeft(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return set_bottomRight(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("bottomRight"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("topLeft"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Rectangle_obj,height),HX_CSTRING("height")},
	{hx::fsFloat,(int)offsetof(Rectangle_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(Rectangle_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Rectangle_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("clone"),
	HX_CSTRING("contains"),
	HX_CSTRING("containsPoint"),
	HX_CSTRING("containsRect"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("equals"),
	HX_CSTRING("extendBounds"),
	HX_CSTRING("inflate"),
	HX_CSTRING("inflatePoint"),
	HX_CSTRING("intersection"),
	HX_CSTRING("intersects"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("offset"),
	HX_CSTRING("offsetPoint"),
	HX_CSTRING("setEmpty"),
	HX_CSTRING("setTo"),
	HX_CSTRING("toString"),
	HX_CSTRING("transform"),
	HX_CSTRING("union"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("get_bottomRight"),
	HX_CSTRING("set_bottomRight"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_size"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_topLeft"),
	HX_CSTRING("set_topLeft"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

#endif

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
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

void Rectangle_obj::__boot()
{
}

} // end namespace openfl
} // end namespace geom
