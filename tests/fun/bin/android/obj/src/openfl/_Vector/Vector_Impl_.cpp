#include <hxcpp.h>

#ifndef INCLUDED_openfl__Vector_Vector_Impl_
#include <openfl/_Vector/Vector_Impl_.h>
#endif
namespace openfl{
namespace _Vector{

Void Vector_Impl__obj::__construct()
{
	return null();
}

//Vector_Impl__obj::~Vector_Impl__obj() { }

Dynamic Vector_Impl__obj::__CreateEmpty() { return  new Vector_Impl__obj; }
hx::ObjectPtr< Vector_Impl__obj > Vector_Impl__obj::__new()
{  hx::ObjectPtr< Vector_Impl__obj > result = new Vector_Impl__obj();
	result->__construct();
	return result;}

Dynamic Vector_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector_Impl__obj > result = new Vector_Impl__obj();
	result->__construct();
	return result;}

Dynamic Vector_Impl__obj::_new( Dynamic length,Dynamic fixed){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","_new",0x72cc24a2,"openfl._Vector.Vector_Impl_._new","openfl/Vector.hx",759,0x4a01873c)
	HX_STACK_ARG(length,"length")
	HX_STACK_ARG(fixed,"fixed")
	HX_STACK_LINE(759)
	Dynamic this1;		HX_STACK_VAR(this1,"this1");
	HX_STACK_LINE(761)
	Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(761)
	this1 = _g;
	HX_STACK_LINE(759)
	return this1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,_new,return )

Dynamic Vector_Impl__obj::concat( Dynamic this1,Dynamic a){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","concat",0x0c502a95,"openfl._Vector.Vector_Impl_.concat","openfl/Vector.hx",768,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(768)
	return this1->__Field(HX_CSTRING("concat"),true)(a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,concat,return )

Dynamic Vector_Impl__obj::copy( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","copy",0x7571caf6,"openfl._Vector.Vector_Impl_.copy","openfl/Vector.hx",775,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(775)
	return this1->__Field(HX_CSTRING("copy"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,copy,return )

Dynamic Vector_Impl__obj::iterator( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","iterator",0x11868daf,"openfl._Vector.Vector_Impl_.iterator","openfl/Vector.hx",782,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(782)
	return this1->__Field(HX_CSTRING("iterator"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,iterator,return )

::String Vector_Impl__obj::join( Dynamic this1,::String sep){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","join",0x7a12432b,"openfl._Vector.Vector_Impl_.join","openfl/Vector.hx",789,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(sep,"sep")
	HX_STACK_LINE(789)
	return this1->__Field(HX_CSTRING("join"),true)(sep);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,join,return )

Dynamic Vector_Impl__obj::pop( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","pop",0x4571b170,"openfl._Vector.Vector_Impl_.pop","openfl/Vector.hx",796,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(796)
	return this1->__Field(HX_CSTRING("pop"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,pop,return )

int Vector_Impl__obj::push( Dynamic this1,Dynamic x){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","push",0x7e0e211b,"openfl._Vector.Vector_Impl_.push","openfl/Vector.hx",803,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(803)
	return this1->__Field(HX_CSTRING("push"),true)(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,push,return )

Void Vector_Impl__obj::reverse( Dynamic this1){
{
		HX_STACK_FRAME("openfl._Vector.Vector_Impl_","reverse",0xc6996881,"openfl._Vector.Vector_Impl_.reverse","openfl/Vector.hx",810,0x4a01873c)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_LINE(810)
		this1->__Field(HX_CSTRING("reverse"),true)();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,reverse,(void))

Dynamic Vector_Impl__obj::shift( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","shift",0x7fe33621,"openfl._Vector.Vector_Impl_.shift","openfl/Vector.hx",817,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(817)
	return this1->__Field(HX_CSTRING("shift"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,shift,return )

Void Vector_Impl__obj::unshift( Dynamic this1,Dynamic x){
{
		HX_STACK_FRAME("openfl._Vector.Vector_Impl_","unshift",0x245112e8,"openfl._Vector.Vector_Impl_.unshift","openfl/Vector.hx",824,0x4a01873c)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(824)
		this1->__Field(HX_CSTRING("unshift"),true)(x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,unshift,(void))

Dynamic Vector_Impl__obj::slice( Dynamic this1,Dynamic pos,Dynamic end){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","slice",0x82880df1,"openfl._Vector.Vector_Impl_.slice","openfl/Vector.hx",831,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(end,"end")
	HX_STACK_LINE(831)
	return this1->__Field(HX_CSTRING("slice"),true)(pos,end);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,slice,return )

Void Vector_Impl__obj::sort( Dynamic this1,Dynamic f){
{
		HX_STACK_FRAME("openfl._Vector.Vector_Impl_","sort",0x8005369f,"openfl._Vector.Vector_Impl_.sort","openfl/Vector.hx",838,0x4a01873c)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(f,"f")
		HX_STACK_LINE(838)
		this1->__Field(HX_CSTRING("sort"),true)(f);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,sort,(void))

Dynamic Vector_Impl__obj::splice( Dynamic this1,int pos,int len){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","splice",0x041ea6fd,"openfl._Vector.Vector_Impl_.splice","openfl/Vector.hx",845,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(845)
	return this1->__Field(HX_CSTRING("splice"),true)(pos,len);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,splice,return )

::String Vector_Impl__obj::toString( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","toString",0xb65b146d,"openfl._Vector.Vector_Impl_.toString","openfl/Vector.hx",852,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(852)
	return this1->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,toString,return )

int Vector_Impl__obj::indexOf( Dynamic this1,Dynamic x,Dynamic __o_from){
Dynamic from = __o_from.Default(0);
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","indexOf",0x8c5c7828,"openfl._Vector.Vector_Impl_.indexOf","openfl/Vector.hx",859,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(from,"from")
{
		HX_STACK_LINE(859)
		return this1->__Field(HX_CSTRING("indexOf"),true)(x,from);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,indexOf,return )

int Vector_Impl__obj::lastIndexOf( Dynamic this1,Dynamic x,Dynamic from){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","lastIndexOf",0x5bdcc7f2,"openfl._Vector.Vector_Impl_.lastIndexOf","openfl/Vector.hx",866,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(from,"from")
	HX_STACK_LINE(866)
	return this1->__Field(HX_CSTRING("lastIndexOf"),true)(x,from);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,lastIndexOf,return )

Dynamic Vector_Impl__obj::get( Dynamic this1,int index){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","get",0x456ad475,"openfl._Vector.Vector_Impl_.get","openfl/Vector.hx",876,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(876)
	return this1->__GetItem(index);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,get,return )

Dynamic Vector_Impl__obj::set( Dynamic this1,int index,Dynamic value){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","set",0x4573ef81,"openfl._Vector.Vector_Impl_.set","openfl/Vector.hx",887,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(index,"index")
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(887)
	return hx::IndexRef((this1).mPtr,index) = value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,set,return )

Dynamic Vector_Impl__obj::ofArray( Dynamic a){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","ofArray",0x348f5861,"openfl._Vector.Vector_Impl_.ofArray","openfl/Vector.hx",895,0x4a01873c)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(895)
	Dynamic this1;		HX_STACK_VAR(this1,"this1");
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/Vector.hx",895,0x4a01873c)
			{
				HX_STACK_LINE(895)
				Dynamic this2;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(895)
				Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() )->__Field(HX_CSTRING("__SetSizeExact"),true)(null());		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(895)
				this2 = _g;
				HX_STACK_LINE(895)
				return this2;
			}
			return null();
		}
	};
	HX_STACK_LINE(895)
	this1 = _Function_1_1::Block();
	HX_STACK_LINE(895)
	return this1->__Field(HX_CSTRING("concat"),true)(a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,ofArray,return )

Dynamic Vector_Impl__obj::convert( Dynamic v){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","convert",0xc6672d52,"openfl._Vector.Vector_Impl_.convert","openfl/Vector.hx",902,0x4a01873c)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(902)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,convert,return )

Dynamic Vector_Impl__obj::fromHaxeVector( Dynamic value){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","fromHaxeVector",0x36245614,"openfl._Vector.Vector_Impl_.fromHaxeVector","openfl/Vector.hx",909,0x4a01873c)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(909)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,fromHaxeVector,return )

Dynamic Vector_Impl__obj::toHaxeVector( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","toHaxeVector",0x8e47e325,"openfl._Vector.Vector_Impl_.toHaxeVector","openfl/Vector.hx",916,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(916)
	return this1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,toHaxeVector,return )

int Vector_Impl__obj::get_length( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","get_length",0x93e47ab0,"openfl._Vector.Vector_Impl_.get_length","openfl/Vector.hx",930,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(930)
	return this1->__Field(HX_CSTRING("length"),true);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,get_length,return )

int Vector_Impl__obj::set_length( Dynamic this1,int value){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","set_length",0x97621924,"openfl._Vector.Vector_Impl_.set_length","openfl/Vector.hx",935,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(937)
	this1->__Field(HX_CSTRING("__SetSizeExact"),true)(value);
	HX_STACK_LINE(938)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,set_length,return )

bool Vector_Impl__obj::get_fixed( Dynamic this1){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","get_fixed",0xf51a5aea,"openfl._Vector.Vector_Impl_.get_fixed","openfl/Vector.hx",945,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(945)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,get_fixed,return )

bool Vector_Impl__obj::set_fixed( Dynamic this1,bool value){
	HX_STACK_FRAME("openfl._Vector.Vector_Impl_","set_fixed",0xd86b46f6,"openfl._Vector.Vector_Impl_.set_fixed","openfl/Vector.hx",952,0x4a01873c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(952)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,set_fixed,return )


Vector_Impl__obj::Vector_Impl__obj()
{
}

Dynamic Vector_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"join") ) { return join_dyn(); }
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"sort") ) { return sort_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shift") ) { return shift_dyn(); }
		if (HX_FIELD_EQ(inName,"slice") ) { return slice_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		if (HX_FIELD_EQ(inName,"splice") ) { return splice_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse_dyn(); }
		if (HX_FIELD_EQ(inName,"unshift") ) { return unshift_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
		if (HX_FIELD_EQ(inName,"ofArray") ) { return ofArray_dyn(); }
		if (HX_FIELD_EQ(inName,"convert") ) { return convert_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_fixed") ) { return get_fixed_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fixed") ) { return set_fixed_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"set_length") ) { return set_length_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"lastIndexOf") ) { return lastIndexOf_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"toHaxeVector") ) { return toHaxeVector_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fromHaxeVector") ) { return fromHaxeVector_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_new"),
	HX_CSTRING("concat"),
	HX_CSTRING("copy"),
	HX_CSTRING("iterator"),
	HX_CSTRING("join"),
	HX_CSTRING("pop"),
	HX_CSTRING("push"),
	HX_CSTRING("reverse"),
	HX_CSTRING("shift"),
	HX_CSTRING("unshift"),
	HX_CSTRING("slice"),
	HX_CSTRING("sort"),
	HX_CSTRING("splice"),
	HX_CSTRING("toString"),
	HX_CSTRING("indexOf"),
	HX_CSTRING("lastIndexOf"),
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("ofArray"),
	HX_CSTRING("convert"),
	HX_CSTRING("fromHaxeVector"),
	HX_CSTRING("toHaxeVector"),
	HX_CSTRING("get_length"),
	HX_CSTRING("set_length"),
	HX_CSTRING("get_fixed"),
	HX_CSTRING("set_fixed"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector_Impl__obj::__mClass,"__mClass");
};

#endif

Class Vector_Impl__obj::__mClass;

void Vector_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._Vector.Vector_Impl_"), hx::TCanCast< Vector_Impl__obj> ,sStaticFields,sMemberFields,
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

void Vector_Impl__obj::__boot()
{
}

} // end namespace openfl
} // end namespace _Vector
