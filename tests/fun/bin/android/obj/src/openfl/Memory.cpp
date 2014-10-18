#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_Memory
#include <openfl/Memory.h>
#endif
#ifndef INCLUDED_openfl_utils_ByteArray
#include <openfl/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataInput
#include <openfl/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataOutput
#include <openfl/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace openfl{

Void Memory_obj::__construct()
{
	return null();
}

//Memory_obj::~Memory_obj() { }

Dynamic Memory_obj::__CreateEmpty() { return  new Memory_obj; }
hx::ObjectPtr< Memory_obj > Memory_obj::__new()
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

Dynamic Memory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

::openfl::utils::ByteArray Memory_obj::gcRef;

int Memory_obj::len;

Void Memory_obj::select( ::openfl::utils::ByteArray bytes){
{
		HX_STACK_FRAME("openfl.Memory","select",0x59db434b,"openfl.Memory.select","openfl/Memory.hx",23,0x3e66e7be)
		HX_STACK_ARG(bytes,"bytes")
		HX_STACK_LINE(38)
		::openfl::Memory_obj::gcRef = bytes;
		HX_STACK_LINE(39)
		if (((bytes == null()))){
			HX_STACK_LINE(41)
			::__hxcpp_memory_clear();
		}
		else{
			HX_STACK_LINE(45)
			::__hxcpp_memory_select(bytes->b);
		}
		HX_STACK_LINE(50)
		if (((bytes == null()))){
			HX_STACK_LINE(52)
			::openfl::Memory_obj::len = (int)0;
		}
		else{
			HX_STACK_LINE(56)
			::openfl::Memory_obj::len = bytes->length;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,select,(void))

int Memory_obj::getByte( int addr){
	HX_STACK_FRAME("openfl.Memory","getByte",0xd720eb8f,"openfl.Memory.getByte","openfl/Memory.hx",220,0x3e66e7be)
	HX_STACK_ARG(addr,"addr")
	HX_STACK_LINE(220)
	return ::__hxcpp_memory_get_byte(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getByte,return )

Float Memory_obj::getDouble( int addr){
	HX_STACK_FRAME("openfl.Memory","getDouble",0x9d3a6758,"openfl.Memory.getDouble","openfl/Memory.hx",228,0x3e66e7be)
	HX_STACK_ARG(addr,"addr")
	HX_STACK_LINE(228)
	return ::__hxcpp_memory_get_double(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getDouble,return )

Float Memory_obj::getFloat( int addr){
	HX_STACK_FRAME("openfl.Memory","getFloat",0xaaabef35,"openfl.Memory.getFloat","openfl/Memory.hx",236,0x3e66e7be)
	HX_STACK_ARG(addr,"addr")
	HX_STACK_LINE(236)
	return ::__hxcpp_memory_get_float(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getFloat,return )

int Memory_obj::getI32( int addr){
	HX_STACK_FRAME("openfl.Memory","getI32",0x92c73aa1,"openfl.Memory.getI32","openfl/Memory.hx",244,0x3e66e7be)
	HX_STACK_ARG(addr,"addr")
	HX_STACK_LINE(244)
	return ::__hxcpp_memory_get_i32(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getI32,return )

int Memory_obj::getUI16( int addr){
	HX_STACK_FRAME("openfl.Memory","getUI16",0xe38b52a0,"openfl.Memory.getUI16","openfl/Memory.hx",252,0x3e66e7be)
	HX_STACK_ARG(addr,"addr")
	HX_STACK_LINE(252)
	return ::__hxcpp_memory_get_ui16(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getUI16,return )

Void Memory_obj::setByte( int addr,int v){
{
		HX_STACK_FRAME("openfl.Memory","setByte",0xca227c9b,"openfl.Memory.setByte","openfl/Memory.hx",260,0x3e66e7be)
		HX_STACK_ARG(addr,"addr")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(260)
		::__hxcpp_memory_set_byte(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setByte,(void))

Void Memory_obj::setDouble( int addr,Float v){
{
		HX_STACK_FRAME("openfl.Memory","setDouble",0x808b5364,"openfl.Memory.setDouble","openfl/Memory.hx",268,0x3e66e7be)
		HX_STACK_ARG(addr,"addr")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(268)
		::__hxcpp_memory_set_double(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setDouble,(void))

Void Memory_obj::setFloat( int addr,Float v){
{
		HX_STACK_FRAME("openfl.Memory","setFloat",0x590948a9,"openfl.Memory.setFloat","openfl/Memory.hx",276,0x3e66e7be)
		HX_STACK_ARG(addr,"addr")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(276)
		::__hxcpp_memory_set_float(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setFloat,(void))

Void Memory_obj::setI16( int addr,int v){
{
		HX_STACK_FRAME("openfl.Memory","setI16",0x5f0f8d5b,"openfl.Memory.setI16","openfl/Memory.hx",284,0x3e66e7be)
		HX_STACK_ARG(addr,"addr")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(284)
		::__hxcpp_memory_set_i16(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setI16,(void))

Void Memory_obj::setI32( int addr,int v){
{
		HX_STACK_FRAME("openfl.Memory","setI32",0x5f0f8f15,"openfl.Memory.setI32","openfl/Memory.hx",292,0x3e66e7be)
		HX_STACK_ARG(addr,"addr")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(292)
		::__hxcpp_memory_set_i32(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setI32,(void))


Memory_obj::Memory_obj()
{
}

Dynamic Memory_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"len") ) { return len; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gcRef") ) { return gcRef; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { return select_dyn(); }
		if (HX_FIELD_EQ(inName,"getI32") ) { return getI32_dyn(); }
		if (HX_FIELD_EQ(inName,"setI16") ) { return setI16_dyn(); }
		if (HX_FIELD_EQ(inName,"setI32") ) { return setI32_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getByte") ) { return getByte_dyn(); }
		if (HX_FIELD_EQ(inName,"getUI16") ) { return getUI16_dyn(); }
		if (HX_FIELD_EQ(inName,"setByte") ) { return setByte_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getFloat") ) { return getFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"setFloat") ) { return setFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getDouble") ) { return getDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"setDouble") ) { return setDouble_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Memory_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"len") ) { len=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gcRef") ) { gcRef=inValue.Cast< ::openfl::utils::ByteArray >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Memory_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("gcRef"),
	HX_CSTRING("len"),
	HX_CSTRING("select"),
	HX_CSTRING("getByte"),
	HX_CSTRING("getDouble"),
	HX_CSTRING("getFloat"),
	HX_CSTRING("getI32"),
	HX_CSTRING("getUI16"),
	HX_CSTRING("setByte"),
	HX_CSTRING("setDouble"),
	HX_CSTRING("setFloat"),
	HX_CSTRING("setI16"),
	HX_CSTRING("setI32"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Memory_obj::gcRef,"gcRef");
	HX_MARK_MEMBER_NAME(Memory_obj::len,"len");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Memory_obj::gcRef,"gcRef");
	HX_VISIT_MEMBER_NAME(Memory_obj::len,"len");
};

#endif

Class Memory_obj::__mClass;

void Memory_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.Memory"), hx::TCanCast< Memory_obj> ,sStaticFields,sMemberFields,
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

void Memory_obj::__boot()
{
}

} // end namespace openfl
