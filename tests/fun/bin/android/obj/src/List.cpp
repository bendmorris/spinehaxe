#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif

Void List_obj::__construct()
{
HX_STACK_FRAME("List","new",0xed890070,"List.new","/usr/lib/haxe/std/List.hx",41,0xd5566cff)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(41)
	this->length = (int)0;
}
;
	return null();
}

//List_obj::~List_obj() { }

Dynamic List_obj::__CreateEmpty() { return  new List_obj; }
hx::ObjectPtr< List_obj > List_obj::__new()
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Dynamic List_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Void List_obj::add( Dynamic item){
{
		HX_STACK_FRAME("List","add",0xed7f2231,"List.add","/usr/lib/haxe/std/List.hx",49,0xd5566cff)
		HX_STACK_THIS(this)
		HX_STACK_ARG(item,"item")
		HX_STACK_LINE(50)
		Dynamic x = Dynamic( Array_obj<Dynamic>::__new().Add(item));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(51)
		if (((this->h == null()))){
			HX_STACK_LINE(52)
			this->h = x;
		}
		else{
			HX_STACK_LINE(54)
			hx::IndexRef((this->q).mPtr,(int)1) = x;
		}
		HX_STACK_LINE(55)
		this->q = x;
		HX_STACK_LINE(56)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,add,(void))

Void List_obj::push( Dynamic item){
{
		HX_STACK_FRAME("List","push",0xebb5efca,"List.push","/usr/lib/haxe/std/List.hx",64,0xd5566cff)
		HX_STACK_THIS(this)
		HX_STACK_ARG(item,"item")
		HX_STACK_LINE(68)
		Dynamic x = Dynamic( Array_obj<Dynamic>::__new().Add(item).Add(this->h));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(70)
		this->h = x;
		HX_STACK_LINE(71)
		if (((this->q == null()))){
			HX_STACK_LINE(72)
			this->q = x;
		}
		HX_STACK_LINE(73)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,push,(void))

bool List_obj::isEmpty( ){
	HX_STACK_FRAME("List","isEmpty",0xaa565653,"List.isEmpty","/usr/lib/haxe/std/List.hx",115,0xd5566cff)
	HX_STACK_THIS(this)
	HX_STACK_LINE(115)
	return (this->h == null());
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,isEmpty,return )

bool List_obj::remove( Dynamic v){
	HX_STACK_FRAME("List","remove",0x4b44d634,"List.remove","/usr/lib/haxe/std/List.hx",138,0xd5566cff)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(139)
	Dynamic prev = null();		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(140)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(141)
	while((true)){
		HX_STACK_LINE(141)
		if ((!(((l != null()))))){
			HX_STACK_LINE(141)
			break;
		}
		HX_STACK_LINE(142)
		if (((l->__GetItem((int)0) == v))){
			HX_STACK_LINE(143)
			if (((prev == null()))){
				HX_STACK_LINE(144)
				this->h = l->__GetItem((int)1);
			}
			else{
				HX_STACK_LINE(146)
				hx::IndexRef((prev).mPtr,(int)1) = l->__GetItem((int)1);
			}
			HX_STACK_LINE(147)
			if (((this->q == l))){
				HX_STACK_LINE(148)
				this->q = prev;
			}
			HX_STACK_LINE(149)
			(this->length)--;
			HX_STACK_LINE(150)
			return true;
		}
		HX_STACK_LINE(152)
		prev = l;
		HX_STACK_LINE(153)
		l = l->__GetItem((int)1);
	}
	HX_STACK_LINE(155)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,remove,return )

Dynamic List_obj::iterator( ){
	HX_STACK_FRAME("List","iterator",0x2d4cdfde,"List.iterator","/usr/lib/haxe/std/List.hx",179,0xd5566cff)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( hx::ObjectPtr< ::List_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/List.hx",179,0xd5566cff)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("h") , __this->h,false);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_1)
				Dynamic run(){
					HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","/usr/lib/haxe/std/List.hx",182,0xd5566cff)
					HX_STACK_THIS(__this.mPtr)
					{
						HX_STACK_LINE(182)
						return (__this->__Field(HX_CSTRING("h"),true) != null());
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_2)
				Dynamic run(){
					HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","/usr/lib/haxe/std/List.hx",185,0xd5566cff)
					HX_STACK_THIS(__this.mPtr)
					{
						HX_STACK_LINE(186)
						if (((__this->__Field(HX_CSTRING("h"),true) == null()))){
							HX_STACK_LINE(187)
							return null();
						}
						HX_STACK_LINE(188)
						Dynamic x = __this->__Field(HX_CSTRING("h"),true)->__GetItem((int)0);		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(189)
						__this->__FieldRef(HX_CSTRING("h")) = __this->__Field(HX_CSTRING("h"),true)->__GetItem((int)1);
						HX_STACK_LINE(190)
						return x;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2()),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(179)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,iterator,return )


List_obj::List_obj()
{
}

void List_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(List);
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_MEMBER_NAME(q,"q");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void List_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(h,"h");
	HX_VISIT_MEMBER_NAME(q,"q");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic List_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		if (HX_FIELD_EQ(inName,"q") ) { return q; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic List_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"q") ) { q=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void List_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("h"));
	outFields->push(HX_CSTRING("q"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(List_obj,h),HX_CSTRING("h")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(List_obj,q),HX_CSTRING("q")},
	{hx::fsInt,(int)offsetof(List_obj,length),HX_CSTRING("length")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("h"),
	HX_CSTRING("q"),
	HX_CSTRING("length"),
	HX_CSTRING("add"),
	HX_CSTRING("push"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("remove"),
	HX_CSTRING("iterator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(List_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(List_obj::__mClass,"__mClass");
};

#endif

Class List_obj::__mClass;

void List_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("List"), hx::TCanCast< List_obj> ,sStaticFields,sMemberFields,
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

void List_obj::__boot()
{
}

