#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_zip_Compress
#include <haxe/zip/Compress.h>
#endif
#ifndef INCLUDED_haxe_zip_Uncompress
#include <haxe/zip/Uncompress.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_errors_EOFError
#include <openfl/errors/EOFError.h>
#endif
#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif
#ifndef INCLUDED_openfl_utils_ByteArray
#include <openfl/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl_utils_CompressionAlgorithm
#include <openfl/utils/CompressionAlgorithm.h>
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
namespace utils{

Void ByteArray_obj::__construct(hx::Null< int >  __o_size)
{
HX_STACK_FRAME("openfl.utils.ByteArray","new",0x3de617e8,"openfl.utils.ByteArray.new","openfl/utils/ByteArray.hx",39,0xaa5cee4a)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_size,"size")
int size = __o_size.Default(0);
{
	HX_STACK_LINE(41)
	this->bigEndian = true;
	HX_STACK_LINE(42)
	this->position = (int)0;
	HX_STACK_LINE(44)
	if (((size >= (int)0))){
		HX_STACK_LINE(58)
		Array< unsigned char > data = Array_obj< unsigned char >::__new();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(60)
		if (((size > (int)0))){
			HX_STACK_LINE(62)
			data[(size - (int)1)] = (int)0;
		}
		HX_STACK_LINE(66)
		super::__construct(size,data);
	}
}
;
	return null();
}

//ByteArray_obj::~ByteArray_obj() { }

Dynamic ByteArray_obj::__CreateEmpty() { return  new ByteArray_obj; }
hx::ObjectPtr< ByteArray_obj > ByteArray_obj::__new(hx::Null< int >  __o_size)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(__o_size);
	return result;}

Dynamic ByteArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *ByteArray_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::openfl::utils::IDataOutput_obj)) return operator ::openfl::utils::IDataOutput_obj *();
	if (inType==typeid( ::openfl::utils::IMemoryRange_obj)) return operator ::openfl::utils::IMemoryRange_obj *();
	if (inType==typeid( ::openfl::utils::IDataInput_obj)) return operator ::openfl::utils::IDataInput_obj *();
	return super::__ToInterface(inType);
}

void ByteArray_obj::__init__() {
HX_STACK_FRAME("openfl.utils.ByteArray","__init__",0x47d148c8,"openfl.utils.ByteArray.__init__","openfl/utils/ByteArray.hx",738,0xaa5cee4a)
{

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	::openfl::utils::ByteArray run(int length){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","openfl/utils/ByteArray.hx",740,0xaa5cee4a)
		HX_STACK_ARG(length,"length")
		{
			HX_STACK_LINE(740)
			return ::openfl::utils::ByteArray_obj::__new(length);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(740)
	Dynamic factory =  Dynamic(new _Function_1_1());		HX_STACK_VAR(factory,"factory");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::openfl::utils::ByteArray bytes,int length){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","openfl/utils/ByteArray.hx",741,0xaa5cee4a)
		HX_STACK_ARG(bytes,"bytes")
		HX_STACK_ARG(length,"length")
		{
			HX_STACK_LINE(743)
			if (((length > (int)0))){
				HX_STACK_LINE(745)
				bytes->__Field(HX_CSTRING("ensureElem"),true)((length - (int)1),true);
			}
			HX_STACK_LINE(749)
			bytes->__FieldRef(HX_CSTRING("length")) = length;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(741)
	Dynamic resize =  Dynamic(new _Function_1_2());		HX_STACK_VAR(resize,"resize");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
	Array< unsigned char > run(::openfl::utils::ByteArray bytes){
		HX_STACK_FRAME("*","_Function_1_3",0x5200ed39,"*._Function_1_3","openfl/utils/ByteArray.hx",753,0xaa5cee4a)
		HX_STACK_ARG(bytes,"bytes")
		{
			HX_STACK_LINE(753)
			if (((bytes == null()))){
				HX_STACK_LINE(753)
				return null();
			}
			else{
				HX_STACK_LINE(753)
				return bytes->__Field(HX_CSTRING("b"),true);
			}
			HX_STACK_LINE(753)
			return null();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(753)
	Dynamic bytes =  Dynamic(new _Function_1_3());		HX_STACK_VAR(bytes,"bytes");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_4)
	int run(::openfl::utils::ByteArray bytes1){
		HX_STACK_FRAME("*","_Function_1_4",0x5200ed3a,"*._Function_1_4","openfl/utils/ByteArray.hx",754,0xaa5cee4a)
		HX_STACK_ARG(bytes1,"bytes1")
		{
			HX_STACK_LINE(754)
			if (((bytes1 == null()))){
				HX_STACK_LINE(754)
				return (int)0;
			}
			else{
				HX_STACK_LINE(754)
				return bytes1->__Field(HX_CSTRING("length"),true);
			}
			HX_STACK_LINE(754)
			return (int)0;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(754)
	Dynamic slen =  Dynamic(new _Function_1_4());		HX_STACK_VAR(slen,"slen");
	HX_STACK_LINE(756)
	Dynamic init = ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_byte_array_init"),(int)4);		HX_STACK_VAR(init,"init");
	HX_STACK_LINE(757)
	init(factory,slen,resize,bytes);
}
}

::String ByteArray_obj::asString( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","asString",0xa85b9edb,"openfl.utils.ByteArray.asString","openfl/utils/ByteArray.hx",77,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return this->readUTFBytes(this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,asString,return )

Void ByteArray_obj::checkData( int length){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","checkData",0xd8abbc9a,"openfl.utils.ByteArray.checkData","openfl/utils/ByteArray.hx",84,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(length,"length")
		HX_STACK_LINE(84)
		if ((((length + this->position) > this->length))){
			HX_STACK_LINE(86)
			this->__throwEOFi();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,checkData,(void))

Void ByteArray_obj::clear( ){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","clear",0xc4b4ab15,"openfl.utils.ByteArray.clear","openfl/utils/ByteArray.hx",93,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(95)
		this->position = (int)0;
		HX_STACK_LINE(96)
		this->length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,clear,(void))

Void ByteArray_obj::compress( ::openfl::utils::CompressionAlgorithm algorithm){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","compress",0x8c14b31a,"openfl.utils.ByteArray.compress","openfl/utils/ByteArray.hx",101,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(algorithm,"algorithm")
		HX_STACK_LINE(106)
		::openfl::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(109)
		if (((algorithm == null()))){
			HX_STACK_LINE(111)
			algorithm = ::openfl::utils::CompressionAlgorithm_obj::ZLIB;
		}
		HX_STACK_LINE(115)
		::haxe::io::Bytes result;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(117)
		if (((algorithm == ::openfl::utils::CompressionAlgorithm_obj::LZMA))){
			HX_STACK_LINE(119)
			Array< unsigned char > _g = ::openfl::utils::ByteArray_obj::lime_lzma_encode(src->b);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(119)
			::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::ofData(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(119)
			result = _g1;
		}
		else{
			HX_STACK_LINE(123)
			int windowBits;		HX_STACK_VAR(windowBits,"windowBits");
			HX_STACK_LINE(123)
			switch( (int)(algorithm->__Index())){
				case (int)0: {
					HX_STACK_LINE(125)
					windowBits = (int)-15;
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(126)
					windowBits = (int)31;
				}
				;break;
				default: {
					HX_STACK_LINE(127)
					windowBits = (int)15;
				}
			}
			HX_STACK_LINE(134)
			::haxe::io::Bytes _g2 = ::haxe::zip::Compress_obj::run(src,(int)8);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(134)
			result = _g2;
		}
		HX_STACK_LINE(139)
		this->b = result->b;
		HX_STACK_LINE(140)
		this->length = result->length;
		HX_STACK_LINE(141)
		this->position = this->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,compress,(void))

Void ByteArray_obj::deflate( ){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","deflate",0xd33ab6f3,"openfl.utils.ByteArray.deflate","openfl/utils/ByteArray.hx",151,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(151)
		this->compress(::openfl::utils::CompressionAlgorithm_obj::DEFLATE);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,deflate,(void))

Void ByteArray_obj::ensureElem( int size,bool updateLength){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","ensureElem",0xf74beae5,"openfl.utils.ByteArray.ensureElem","openfl/utils/ByteArray.hx",156,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(size,"size")
		HX_STACK_ARG(updateLength,"updateLength")
		HX_STACK_LINE(157)
		int len = (size + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(169)
		if (((this->b->length < len))){
			HX_STACK_LINE(171)
			this->b->__SetSize(len);
		}
		HX_STACK_LINE(176)
		if (((bool(updateLength) && bool((this->length < len))))){
			HX_STACK_LINE(178)
			this->length = len;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,ensureElem,(void))

::openfl::utils::ByteArray ByteArray_obj::getByteBuffer( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","getByteBuffer",0xd305a3e6,"openfl.utils.ByteArray.getByteBuffer","openfl/utils/ByteArray.hx",196,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(196)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getByteBuffer,return )

int ByteArray_obj::getLength( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","getLength",0x5dc6bba4,"openfl.utils.ByteArray.getLength","openfl/utils/ByteArray.hx",203,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(203)
	return this->length;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getLength,return )

Dynamic ByteArray_obj::getNativePointer( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","getNativePointer",0x27b4dce8,"openfl.utils.ByteArray.getNativePointer","openfl/utils/ByteArray.hx",210,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(210)
	return ::openfl::utils::ByteArray_obj::lime_byte_array_get_native_pointer(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getNativePointer,return )

int ByteArray_obj::getStart( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","getStart",0xec37ef64,"openfl.utils.ByteArray.getStart","openfl/utils/ByteArray.hx",217,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(217)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getStart,return )

Void ByteArray_obj::inflate( ){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","inflate",0x3c5c480f,"openfl.utils.ByteArray.inflate","openfl/utils/ByteArray.hx",224,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(224)
		this->uncompress(::openfl::utils::CompressionAlgorithm_obj::DEFLATE);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,inflate,(void))

bool ByteArray_obj::readBoolean( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readBoolean",0xf4db8d7a,"openfl.utils.ByteArray.readBoolean","openfl/utils/ByteArray.hx",231,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(231)
	if (((this->position < this->length))){
		HX_STACK_LINE(231)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(231)
		{
			HX_STACK_LINE(231)
			int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(231)
			_g = this->b->__get(pos);
		}
		HX_STACK_LINE(231)
		return (_g != (int)0);
	}
	else{
		HX_STACK_LINE(231)
		int _g1 = this->__throwEOFi();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(231)
		return (_g1 != (int)0);
	}
	HX_STACK_LINE(231)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readBoolean,return )

int ByteArray_obj::readByte( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readByte",0x717064f6,"openfl.utils.ByteArray.readByte","openfl/utils/ByteArray.hx",236,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(238)
	int value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(238)
	if (((this->position < this->length))){
		HX_STACK_LINE(238)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(238)
		value = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(238)
		value = this->__throwEOFi();
	}
	HX_STACK_LINE(239)
	if (((((int(value) & int((int)128))) != (int)0))){
		HX_STACK_LINE(239)
		return (value - (int)256);
	}
	else{
		HX_STACK_LINE(239)
		return value;
	}
	HX_STACK_LINE(239)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readByte,return )

Void ByteArray_obj::readBytes( ::openfl::utils::ByteArray data,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_FRAME("openfl.utils.ByteArray","readBytes",0xd0e7f2bd,"openfl.utils.ByteArray.readBytes","openfl/utils/ByteArray.hx",244,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(data,"data")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(length,"length")
{
		HX_STACK_LINE(246)
		if (((length == (int)0))){
			HX_STACK_LINE(248)
			length = (this->length - this->position);
		}
		HX_STACK_LINE(252)
		if ((((this->position + length) > this->length))){
			HX_STACK_LINE(254)
			this->__throwEOFi();
		}
		HX_STACK_LINE(258)
		if (((data->length < (offset + length)))){
			HX_STACK_LINE(260)
			data->ensureElem(((offset + length) - (int)1),true);
		}
		HX_STACK_LINE(267)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(268)
		Array< unsigned char > b2 = data->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(269)
		int p = this->position;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(270)
		{
			HX_STACK_LINE(270)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(270)
			while((true)){
				HX_STACK_LINE(270)
				if ((!(((_g < length))))){
					HX_STACK_LINE(270)
					break;
				}
				HX_STACK_LINE(270)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(272)
				b2[(offset + i)] = b1->__get((p + i));
			}
		}
		HX_STACK_LINE(277)
		hx::AddEq(this->position,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,readBytes,(void))

Float ByteArray_obj::readDouble( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readDouble",0x0568487f,"openfl.utils.ByteArray.readDouble","openfl/utils/ByteArray.hx",282,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(284)
	if ((((this->position + (int)8) > this->length))){
		HX_STACK_LINE(286)
		this->__throwEOFi();
	}
	HX_STACK_LINE(293)
	Array< unsigned char > _g = this->b->slice(this->position,(this->position + (int)8));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(293)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)8,_g);		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(302)
	hx::AddEq(this->position,(int)8);
	HX_STACK_LINE(303)
	return ::openfl::utils::ByteArray_obj::_double_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readDouble,return )

Float ByteArray_obj::readFloat( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readFloat",0x15e6afee,"openfl.utils.ByteArray.readFloat","openfl/utils/ByteArray.hx",319,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(321)
	if ((((this->position + (int)4) > this->length))){
		HX_STACK_LINE(323)
		this->__throwEOFi();
	}
	HX_STACK_LINE(330)
	Array< unsigned char > _g = this->b->slice(this->position,(this->position + (int)4));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(330)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)4,_g);		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(339)
	hx::AddEq(this->position,(int)4);
	HX_STACK_LINE(340)
	return ::openfl::utils::ByteArray_obj::_float_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readFloat,return )

int ByteArray_obj::readInt( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readInt",0x330a5ec1,"openfl.utils.ByteArray.readInt","openfl/utils/ByteArray.hx",345,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(347)
	int ch1;		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(347)
	if (((this->position < this->length))){
		HX_STACK_LINE(347)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(347)
		ch1 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(347)
		ch1 = this->__throwEOFi();
	}
	HX_STACK_LINE(348)
	int ch2;		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(348)
	if (((this->position < this->length))){
		HX_STACK_LINE(348)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(348)
		ch2 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(348)
		ch2 = this->__throwEOFi();
	}
	HX_STACK_LINE(349)
	int ch3;		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(349)
	if (((this->position < this->length))){
		HX_STACK_LINE(349)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(349)
		ch3 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(349)
		ch3 = this->__throwEOFi();
	}
	HX_STACK_LINE(350)
	int ch4;		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(350)
	if (((this->position < this->length))){
		HX_STACK_LINE(350)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(350)
		ch4 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(350)
		ch4 = this->__throwEOFi();
	}
	HX_STACK_LINE(352)
	if ((this->bigEndian)){
		HX_STACK_LINE(352)
		return (int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4));
	}
	else{
		HX_STACK_LINE(352)
		return (int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1));
	}
	HX_STACK_LINE(352)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readInt,return )

::String ByteArray_obj::readMultiByte( int length,::String charSet){
	HX_STACK_FRAME("openfl.utils.ByteArray","readMultiByte",0xe3c38173,"openfl.utils.ByteArray.readMultiByte","openfl/utils/ByteArray.hx",359,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(length,"length")
	HX_STACK_ARG(charSet,"charSet")
	HX_STACK_LINE(359)
	return this->readUTFBytes(length);
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,readMultiByte,return )

Void ByteArray_obj::writeMultiByte( ::String value,::String charSet){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeMultiByte",0x58ecbaba,"openfl.utils.ByteArray.writeMultiByte","openfl/utils/ByteArray.hx",364,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_ARG(charSet,"charSet")
		HX_STACK_LINE(364)
		this->writeUTFBytes(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,writeMultiByte,(void))

int ByteArray_obj::readShort( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readShort",0x8f776ece,"openfl.utils.ByteArray.readShort","openfl/utils/ByteArray.hx",367,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(369)
	int ch1;		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(369)
	if (((this->position < this->length))){
		HX_STACK_LINE(369)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(369)
		ch1 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(369)
		ch1 = this->__throwEOFi();
	}
	HX_STACK_LINE(370)
	int ch2;		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(370)
	if (((this->position < this->length))){
		HX_STACK_LINE(370)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(370)
		ch2 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(370)
		ch2 = this->__throwEOFi();
	}
	HX_STACK_LINE(372)
	int value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(372)
	if ((this->bigEndian)){
		HX_STACK_LINE(372)
		value = (int((int(ch1) << int((int)8))) | int(ch2));
	}
	else{
		HX_STACK_LINE(372)
		value = (int((int(ch2) << int((int)8))) | int(ch1));
	}
	HX_STACK_LINE(374)
	if (((((int(value) & int((int)32768))) != (int)0))){
		HX_STACK_LINE(374)
		return (value - (int)65536);
	}
	else{
		HX_STACK_LINE(374)
		return value;
	}
	HX_STACK_LINE(374)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readShort,return )

int ByteArray_obj::readUnsignedByte( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readUnsignedByte",0x492fae8b,"openfl.utils.ByteArray.readUnsignedByte","openfl/utils/ByteArray.hx",381,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(381)
	if (((this->position < this->length))){
		HX_STACK_LINE(381)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(381)
		return this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(381)
		return this->__throwEOFi();
	}
	HX_STACK_LINE(381)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedByte,return )

int ByteArray_obj::readUnsignedInt( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readUnsignedInt",0xc6f31ecc,"openfl.utils.ByteArray.readUnsignedInt","openfl/utils/ByteArray.hx",386,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(388)
	int ch1;		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(388)
	if (((this->position < this->length))){
		HX_STACK_LINE(388)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(388)
		ch1 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(388)
		ch1 = this->__throwEOFi();
	}
	HX_STACK_LINE(389)
	int ch2;		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(389)
	if (((this->position < this->length))){
		HX_STACK_LINE(389)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(389)
		ch2 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(389)
		ch2 = this->__throwEOFi();
	}
	HX_STACK_LINE(390)
	int ch3;		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(390)
	if (((this->position < this->length))){
		HX_STACK_LINE(390)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(390)
		ch3 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(390)
		ch3 = this->__throwEOFi();
	}
	HX_STACK_LINE(391)
	int ch4;		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(391)
	if (((this->position < this->length))){
		HX_STACK_LINE(391)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(391)
		ch4 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(391)
		ch4 = this->__throwEOFi();
	}
	HX_STACK_LINE(393)
	if ((this->bigEndian)){
		HX_STACK_LINE(393)
		return (int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4));
	}
	else{
		HX_STACK_LINE(393)
		return (int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1));
	}
	HX_STACK_LINE(393)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedInt,return )

int ByteArray_obj::readUnsignedShort( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readUnsignedShort",0x7f188799,"openfl.utils.ByteArray.readUnsignedShort","openfl/utils/ByteArray.hx",398,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(400)
	int ch1;		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(400)
	if (((this->position < this->length))){
		HX_STACK_LINE(400)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(400)
		ch1 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(400)
		ch1 = this->__throwEOFi();
	}
	HX_STACK_LINE(401)
	int ch2;		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(401)
	if (((this->position < this->length))){
		HX_STACK_LINE(401)
		int pos = (this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(401)
		ch2 = this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(401)
		ch2 = this->__throwEOFi();
	}
	HX_STACK_LINE(403)
	if ((this->bigEndian)){
		HX_STACK_LINE(403)
		return (int((int(ch1) << int((int)8))) | int(ch2));
	}
	else{
		HX_STACK_LINE(403)
		return (((int(ch2) << int((int)8))) + ch1);
	}
	HX_STACK_LINE(403)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedShort,return )

::String ByteArray_obj::readUTF( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","readUTF",0x331362f9,"openfl.utils.ByteArray.readUTF","openfl/utils/ByteArray.hx",408,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(410)
	int len = this->readUnsignedShort();		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(411)
	return this->readUTFBytes(len);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUTF,return )

::String ByteArray_obj::readUTFBytes( int length){
	HX_STACK_FRAME("openfl.utils.ByteArray","readUTFBytes",0xa10baeb2,"openfl.utils.ByteArray.readUTFBytes","openfl/utils/ByteArray.hx",416,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(length,"length")
	HX_STACK_LINE(418)
	if ((((this->position + length) > this->length))){
		HX_STACK_LINE(420)
		this->__throwEOFi();
	}
	HX_STACK_LINE(424)
	int p = this->position;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(425)
	hx::AddEq(this->position,length);
	HX_STACK_LINE(434)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(435)
	::__hxcpp_string_of_bytes(this->b,result,p,length);
	HX_STACK_LINE(436)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readUTFBytes,return )

Void ByteArray_obj::setLength( int length){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","setLength",0x4117a7b0,"openfl.utils.ByteArray.setLength","openfl/utils/ByteArray.hx",446,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(length,"length")
		HX_STACK_LINE(448)
		if (((length > (int)0))){
			HX_STACK_LINE(450)
			this->ensureElem((length - (int)1),false);
		}
		HX_STACK_LINE(454)
		this->length = length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,setLength,(void))

::openfl::utils::ByteArray ByteArray_obj::slice( int begin,Dynamic end){
	HX_STACK_FRAME("openfl.utils.ByteArray","slice",0xfb20fdda,"openfl.utils.ByteArray.slice","openfl/utils/ByteArray.hx",459,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(begin,"begin")
	HX_STACK_ARG(end,"end")
	HX_STACK_LINE(461)
	if (((begin < (int)0))){
		HX_STACK_LINE(463)
		hx::AddEq(begin,this->length);
		HX_STACK_LINE(465)
		if (((begin < (int)0))){
			HX_STACK_LINE(467)
			begin = (int)0;
		}
	}
	HX_STACK_LINE(473)
	if (((end == null()))){
		HX_STACK_LINE(475)
		end = this->length;
	}
	HX_STACK_LINE(479)
	if (((end < (int)0))){
		HX_STACK_LINE(481)
		hx::AddEq(end,this->length);
		HX_STACK_LINE(483)
		if (((end < (int)0))){
			HX_STACK_LINE(485)
			end = (int)0;
		}
	}
	HX_STACK_LINE(491)
	if (((begin >= end))){
		HX_STACK_LINE(493)
		return ::openfl::utils::ByteArray_obj::__new(null());
	}
	HX_STACK_LINE(497)
	::openfl::utils::ByteArray result = ::openfl::utils::ByteArray_obj::__new((end - begin));		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(499)
	int opos = this->position;		HX_STACK_VAR(opos,"opos");
	HX_STACK_LINE(500)
	result->blit((int)0,hx::ObjectPtr<OBJ_>(this),begin,(end - begin));
	HX_STACK_LINE(502)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,slice,return )

Void ByteArray_obj::uncompress( ::openfl::utils::CompressionAlgorithm algorithm){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","uncompress",0xe2a46873,"openfl.utils.ByteArray.uncompress","openfl/utils/ByteArray.hx",507,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(algorithm,"algorithm")
		HX_STACK_LINE(509)
		if (((algorithm == null()))){
			HX_STACK_LINE(509)
			algorithm = ::openfl::utils::CompressionAlgorithm_obj::ZLIB;
		}
		HX_STACK_LINE(514)
		::openfl::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(517)
		::haxe::io::Bytes result;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(519)
		if (((algorithm == ::openfl::utils::CompressionAlgorithm_obj::LZMA))){
			HX_STACK_LINE(521)
			Array< unsigned char > _g = ::openfl::utils::ByteArray_obj::lime_lzma_decode(src->b);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(521)
			::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::ofData(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(521)
			result = _g1;
		}
		else{
			HX_STACK_LINE(525)
			int windowBits;		HX_STACK_VAR(windowBits,"windowBits");
			HX_STACK_LINE(525)
			switch( (int)(algorithm->__Index())){
				case (int)0: {
					HX_STACK_LINE(527)
					windowBits = (int)-15;
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(528)
					windowBits = (int)31;
				}
				;break;
				default: {
					HX_STACK_LINE(529)
					windowBits = (int)15;
				}
			}
			HX_STACK_LINE(536)
			::haxe::io::Bytes _g2 = ::haxe::zip::Uncompress_obj::run(src,null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(536)
			result = _g2;
		}
		HX_STACK_LINE(541)
		this->b = result->b;
		HX_STACK_LINE(542)
		this->length = result->length;
		HX_STACK_LINE(543)
		this->position = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,uncompress,(void))

Void ByteArray_obj::write_uncheck( int byte){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","write_uncheck",0x33e9ceb7,"openfl.utils.ByteArray.write_uncheck","openfl/utils/ByteArray.hx",551,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(byte,"byte")
		HX_STACK_LINE(554)
		int _g = (this->position)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(554)
		this->b->__unsafe_set(_g,byte);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,write_uncheck,(void))

Void ByteArray_obj::writeBoolean( bool value){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeBoolean",0x922a1701,"openfl.utils.ByteArray.writeBoolean","openfl/utils/ByteArray.hx",566,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(566)
		this->ensureElem(this->position,true);
		HX_STACK_LINE(566)
		int _g = (this->position)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(566)
		if ((value)){
			HX_STACK_LINE(566)
			this->b[_g] = (int)1;
		}
		else{
			HX_STACK_LINE(566)
			this->b[_g] = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeBoolean,(void))

Void ByteArray_obj::writeObject( Dynamic object){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeObject",0xce29e086,"openfl.utils.ByteArray.writeObject","openfl/utils/ByteArray.hx",569,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeObject,(void))

Void ByteArray_obj::writeByte( int value){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeByte",0x8c3fb10f,"openfl.utils.ByteArray.writeByte","openfl/utils/ByteArray.hx",574,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(576)
		this->ensureElem(this->position,true);
		HX_STACK_LINE(581)
		int _g = (this->position)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(581)
		this->b[_g] = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeByte,(void))

Void ByteArray_obj::writeBytes( ::haxe::io::Bytes bytes,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_FRAME("openfl.utils.ByteArray","writeBytes",0x2b7b3c84,"openfl.utils.ByteArray.writeBytes","openfl/utils/ByteArray.hx",589,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(length,"length")
{
		HX_STACK_LINE(591)
		if (((length == (int)0))){
			HX_STACK_LINE(591)
			length = (bytes->length - offset);
		}
		HX_STACK_LINE(592)
		this->ensureElem(((this->position + length) - (int)1),true);
		HX_STACK_LINE(593)
		int opos = this->position;		HX_STACK_VAR(opos,"opos");
		HX_STACK_LINE(594)
		hx::AddEq(this->position,length);
		HX_STACK_LINE(595)
		this->blit(opos,bytes,offset,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,writeBytes,(void))

Void ByteArray_obj::writeDouble( Float x){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeDouble",0xebb58cd8,"openfl.utils.ByteArray.writeDouble","openfl/utils/ByteArray.hx",600,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(605)
		Array< unsigned char > _g = ::openfl::utils::ByteArray_obj::_double_bytes(x,this->bigEndian);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(605)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(_g);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(608)
		this->writeBytes(bytes,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeDouble,(void))

Void ByteArray_obj::writeFile( ::String path){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeFile",0x8ed86083,"openfl.utils.ByteArray.writeFile","openfl/utils/ByteArray.hx",617,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(path,"path")
		HX_STACK_LINE(617)
		::openfl::utils::ByteArray_obj::lime_byte_array_overwrite_file(path,hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFile,(void))

Void ByteArray_obj::writeFloat( Float x){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeFloat",0x7079f9b5,"openfl.utils.ByteArray.writeFloat","openfl/utils/ByteArray.hx",624,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(627)
		Array< unsigned char > _g = ::openfl::utils::ByteArray_obj::_float_bytes(x,this->bigEndian);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(627)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(_g);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(632)
		this->writeBytes(bytes,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFloat,(void))

Void ByteArray_obj::writeInt( int value){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeInt",0x2c45d8c8,"openfl.utils.ByteArray.writeInt","openfl/utils/ByteArray.hx",637,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(639)
		this->ensureElem((this->position + (int)3),true);
		HX_STACK_LINE(641)
		if ((this->bigEndian)){
			HX_STACK_LINE(643)
			{
				HX_STACK_LINE(643)
				int _g = (this->position)++;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(643)
				this->b->__unsafe_set(_g,(int(value) >> int((int)24)));
			}
			HX_STACK_LINE(644)
			{
				HX_STACK_LINE(644)
				int _g1 = (this->position)++;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(644)
				this->b->__unsafe_set(_g1,(int(value) >> int((int)16)));
			}
			HX_STACK_LINE(645)
			{
				HX_STACK_LINE(645)
				int _g2 = (this->position)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(645)
				this->b->__unsafe_set(_g2,(int(value) >> int((int)8)));
			}
			HX_STACK_LINE(646)
			{
				HX_STACK_LINE(646)
				int _g3 = (this->position)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(646)
				this->b->__unsafe_set(_g3,value);
			}
		}
		else{
			HX_STACK_LINE(650)
			{
				HX_STACK_LINE(650)
				int _g4 = (this->position)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(650)
				this->b->__unsafe_set(_g4,value);
			}
			HX_STACK_LINE(651)
			{
				HX_STACK_LINE(651)
				int _g5 = (this->position)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(651)
				this->b->__unsafe_set(_g5,(int(value) >> int((int)8)));
			}
			HX_STACK_LINE(652)
			{
				HX_STACK_LINE(652)
				int _g6 = (this->position)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(652)
				this->b->__unsafe_set(_g6,(int(value) >> int((int)16)));
			}
			HX_STACK_LINE(653)
			{
				HX_STACK_LINE(653)
				int _g7 = (this->position)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(653)
				this->b->__unsafe_set(_g7,(int(value) >> int((int)24)));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeInt,(void))

Void ByteArray_obj::writeShort( int value){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeShort",0xea0ab895,"openfl.utils.ByteArray.writeShort","openfl/utils/ByteArray.hx",660,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(662)
		this->ensureElem((this->position + (int)1),true);
		HX_STACK_LINE(664)
		if ((this->bigEndian)){
			HX_STACK_LINE(666)
			{
				HX_STACK_LINE(666)
				int _g = (this->position)++;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(666)
				this->b->__unsafe_set(_g,(int(value) >> int((int)8)));
			}
			HX_STACK_LINE(667)
			{
				HX_STACK_LINE(667)
				int _g1 = (this->position)++;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(667)
				this->b->__unsafe_set(_g1,value);
			}
		}
		else{
			HX_STACK_LINE(671)
			{
				HX_STACK_LINE(671)
				int _g2 = (this->position)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(671)
				this->b->__unsafe_set(_g2,value);
			}
			HX_STACK_LINE(672)
			{
				HX_STACK_LINE(672)
				int _g3 = (this->position)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(672)
				this->b->__unsafe_set(_g3,(int(value) >> int((int)8)));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeShort,(void))

Void ByteArray_obj::writeUnsignedInt( int value){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeUnsignedInt",0xc3d277d3,"openfl.utils.ByteArray.writeUnsignedInt","openfl/utils/ByteArray.hx",681,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(681)
		this->writeInt(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUnsignedInt,(void))

Void ByteArray_obj::writeUTF( ::String s){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeUTF",0x2c4edd00,"openfl.utils.ByteArray.writeUTF","openfl/utils/ByteArray.hx",686,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(691)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(694)
		this->writeShort(bytes->length);
		HX_STACK_LINE(695)
		this->writeBytes(bytes,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTF,(void))

Void ByteArray_obj::writeUTFBytes( ::String s){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","writeUTFBytes",0xa8757b4b,"openfl.utils.ByteArray.writeUTFBytes","openfl/utils/ByteArray.hx",700,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(705)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(708)
		this->writeBytes(bytes,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTFBytes,(void))

Void ByteArray_obj::__fromBytes( ::haxe::io::Bytes bytes){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","__fromBytes",0xc43e4b09,"openfl.utils.ByteArray.__fromBytes","openfl/utils/ByteArray.hx",713,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bytes,"bytes")
		HX_STACK_LINE(715)
		this->b = bytes->b;
		HX_STACK_LINE(716)
		this->length = bytes->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__fromBytes,(void))

int ByteArray_obj::__get( int pos){
	HX_STACK_FRAME("openfl.utils.ByteArray","__get",0x6e841afe,"openfl.utils.ByteArray.__get","openfl/utils/ByteArray.hx",728,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pos,"pos")
	HX_STACK_LINE(728)
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__get,return )

Void ByteArray_obj::__set( int pos,int v){
{
		HX_STACK_FRAME("openfl.utils.ByteArray","__set",0x6e8d360a,"openfl.utils.ByteArray.__set","openfl/utils/ByteArray.hx",767,0xaa5cee4a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pos,"pos")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(767)
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,__set,(void))

int ByteArray_obj::__throwEOFi( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","__throwEOFi",0xbcb228db,"openfl.utils.ByteArray.__throwEOFi","openfl/utils/ByteArray.hx",775,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(777)
	HX_STACK_DO_THROW(::openfl::errors::EOFError_obj::__new());
	HX_STACK_LINE(778)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,__throwEOFi,return )

int ByteArray_obj::get_bytesAvailable( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","get_bytesAvailable",0x3ae29e1f,"openfl.utils.ByteArray.get_bytesAvailable","openfl/utils/ByteArray.hx",790,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(790)
	return (this->length - this->position);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_bytesAvailable,return )

int ByteArray_obj::get_byteLength( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","get_byteLength",0x59c8fbcf,"openfl.utils.ByteArray.get_byteLength","openfl/utils/ByteArray.hx",791,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(791)
	return this->length;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_byteLength,return )

::String ByteArray_obj::get_endian( ){
	HX_STACK_FRAME("openfl.utils.ByteArray","get_endian",0xc43141dc,"openfl.utils.ByteArray.get_endian","openfl/utils/ByteArray.hx",792,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(792)
	if ((this->bigEndian)){
		HX_STACK_LINE(792)
		return HX_CSTRING("bigEndian");
	}
	else{
		HX_STACK_LINE(792)
		return HX_CSTRING("littleEndian");
	}
	HX_STACK_LINE(792)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_endian,return )

::String ByteArray_obj::set_endian( ::String value){
	HX_STACK_FRAME("openfl.utils.ByteArray","set_endian",0xc7aee050,"openfl.utils.ByteArray.set_endian","openfl/utils/ByteArray.hx",793,0xaa5cee4a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(793)
	this->bigEndian = (value == HX_CSTRING("bigEndian"));
	HX_STACK_LINE(793)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,set_endian,return )

::openfl::utils::ByteArray ByteArray_obj::fromBytes( ::haxe::io::Bytes bytes){
	HX_STACK_FRAME("openfl.utils.ByteArray","fromBytes",0xb4899029,"openfl.utils.ByteArray.fromBytes","openfl/utils/ByteArray.hx",185,0xaa5cee4a)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_LINE(187)
	::openfl::utils::ByteArray result = ::openfl::utils::ByteArray_obj::__new((int)-1);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(188)
	{
		HX_STACK_LINE(188)
		result->b = bytes->b;
		HX_STACK_LINE(188)
		result->length = bytes->length;
	}
	HX_STACK_LINE(189)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,fromBytes,return )

::openfl::utils::ByteArray ByteArray_obj::readFile( ::String path){
	HX_STACK_FRAME("openfl.utils.ByteArray","readFile",0x7409146a,"openfl.utils.ByteArray.readFile","openfl/utils/ByteArray.hx",312,0xaa5cee4a)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(312)
	return ::openfl::utils::ByteArray_obj::lime_byte_array_read_file(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readFile,return )

Dynamic ByteArray_obj::_double_bytes;

Dynamic ByteArray_obj::_double_of_bytes;

Dynamic ByteArray_obj::_float_bytes;

Dynamic ByteArray_obj::_float_of_bytes;

Dynamic ByteArray_obj::lime_byte_array_overwrite_file;

Dynamic ByteArray_obj::lime_byte_array_read_file;

Dynamic ByteArray_obj::lime_byte_array_get_native_pointer;

Dynamic ByteArray_obj::lime_lzma_encode;

Dynamic ByteArray_obj::lime_lzma_decode;


ByteArray_obj::ByteArray_obj()
{
}

Dynamic ByteArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"slice") ) { return slice_dyn(); }
		if (HX_FIELD_EQ(inName,"__get") ) { return __get_dyn(); }
		if (HX_FIELD_EQ(inName,"__set") ) { return __set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return get_endian(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"deflate") ) { return deflate_dyn(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt") ) { return readInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readUTF") ) { return readUTF_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readFile") ) { return readFile_dyn(); }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"asString") ) { return asString_dyn(); }
		if (HX_FIELD_EQ(inName,"compress") ) { return compress_dyn(); }
		if (HX_FIELD_EQ(inName,"getStart") ) { return getStart_dyn(); }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt") ) { return writeInt_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTF") ) { return writeUTF_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromBytes") ) { return fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		if (HX_FIELD_EQ(inName,"checkData") ) { return checkData_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readShort") ) { return readShort_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength") ) { return setLength_dyn(); }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFile") ) { return writeFile_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"byteLength") ) { return inCallProp ? get_byteLength() : byteLength; }
		if (HX_FIELD_EQ(inName,"ensureElem") ) { return ensureElem_dyn(); }
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"uncompress") ) { return uncompress_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeShort") ) { return writeShort_dyn(); }
		if (HX_FIELD_EQ(inName,"get_endian") ) { return get_endian_dyn(); }
		if (HX_FIELD_EQ(inName,"set_endian") ) { return set_endian_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"readBoolean") ) { return readBoolean_dyn(); }
		if (HX_FIELD_EQ(inName,"writeObject") ) { return writeObject_dyn(); }
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"__fromBytes") ) { return __fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"__throwEOFi") ) { return __throwEOFi_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { return _float_bytes; }
		if (HX_FIELD_EQ(inName,"readUTFBytes") ) { return readUTFBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBoolean") ) { return writeBoolean_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { return _double_bytes; }
		if (HX_FIELD_EQ(inName,"getByteBuffer") ) { return getByteBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"readMultiByte") ) { return readMultiByte_dyn(); }
		if (HX_FIELD_EQ(inName,"write_uncheck") ) { return write_uncheck_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTFBytes") ) { return writeUTFBytes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { return inCallProp ? get_bytesAvailable() : bytesAvailable; }
		if (HX_FIELD_EQ(inName,"writeMultiByte") ) { return writeMultiByte_dyn(); }
		if (HX_FIELD_EQ(inName,"get_byteLength") ) { return get_byteLength_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { return _float_of_bytes; }
		if (HX_FIELD_EQ(inName,"readUnsignedInt") ) { return readUnsignedInt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { return _double_of_bytes; }
		if (HX_FIELD_EQ(inName,"lime_lzma_encode") ) { return lime_lzma_encode; }
		if (HX_FIELD_EQ(inName,"lime_lzma_decode") ) { return lime_lzma_decode; }
		if (HX_FIELD_EQ(inName,"getNativePointer") ) { return getNativePointer_dyn(); }
		if (HX_FIELD_EQ(inName,"readUnsignedByte") ) { return readUnsignedByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUnsignedInt") ) { return writeUnsignedInt_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"readUnsignedShort") ) { return readUnsignedShort_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_bytesAvailable") ) { return get_bytesAvailable_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_byte_array_read_file") ) { return lime_byte_array_read_file; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_byte_array_overwrite_file") ) { return lime_byte_array_overwrite_file; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_byte_array_get_native_pointer") ) { return lime_byte_array_get_native_pointer; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ByteArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return set_endian(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { bigEndian=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"byteLength") ) { byteLength=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { bytesAvailable=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_lzma_encode") ) { lime_lzma_encode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_lzma_decode") ) { lime_lzma_decode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_byte_array_read_file") ) { lime_byte_array_read_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_byte_array_overwrite_file") ) { lime_byte_array_overwrite_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_byte_array_get_native_pointer") ) { lime_byte_array_get_native_pointer=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ByteArray_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bigEndian"));
	outFields->push(HX_CSTRING("bytesAvailable"));
	outFields->push(HX_CSTRING("endian"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("byteLength"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromBytes"),
	HX_CSTRING("readFile"),
	HX_CSTRING("_double_bytes"),
	HX_CSTRING("_double_of_bytes"),
	HX_CSTRING("_float_bytes"),
	HX_CSTRING("_float_of_bytes"),
	HX_CSTRING("lime_byte_array_overwrite_file"),
	HX_CSTRING("lime_byte_array_read_file"),
	HX_CSTRING("lime_byte_array_get_native_pointer"),
	HX_CSTRING("lime_lzma_encode"),
	HX_CSTRING("lime_lzma_decode"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(ByteArray_obj,bigEndian),HX_CSTRING("bigEndian")},
	{hx::fsInt,(int)offsetof(ByteArray_obj,bytesAvailable),HX_CSTRING("bytesAvailable")},
	{hx::fsInt,(int)offsetof(ByteArray_obj,position),HX_CSTRING("position")},
	{hx::fsInt,(int)offsetof(ByteArray_obj,byteLength),HX_CSTRING("byteLength")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bigEndian"),
	HX_CSTRING("bytesAvailable"),
	HX_CSTRING("position"),
	HX_CSTRING("byteLength"),
	HX_CSTRING("asString"),
	HX_CSTRING("checkData"),
	HX_CSTRING("clear"),
	HX_CSTRING("compress"),
	HX_CSTRING("deflate"),
	HX_CSTRING("ensureElem"),
	HX_CSTRING("getByteBuffer"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getNativePointer"),
	HX_CSTRING("getStart"),
	HX_CSTRING("inflate"),
	HX_CSTRING("readBoolean"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readInt"),
	HX_CSTRING("readMultiByte"),
	HX_CSTRING("writeMultiByte"),
	HX_CSTRING("readShort"),
	HX_CSTRING("readUnsignedByte"),
	HX_CSTRING("readUnsignedInt"),
	HX_CSTRING("readUnsignedShort"),
	HX_CSTRING("readUTF"),
	HX_CSTRING("readUTFBytes"),
	HX_CSTRING("setLength"),
	HX_CSTRING("slice"),
	HX_CSTRING("uncompress"),
	HX_CSTRING("write_uncheck"),
	HX_CSTRING("writeBoolean"),
	HX_CSTRING("writeObject"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeFile"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeInt"),
	HX_CSTRING("writeShort"),
	HX_CSTRING("writeUnsignedInt"),
	HX_CSTRING("writeUTF"),
	HX_CSTRING("writeUTFBytes"),
	HX_CSTRING("__fromBytes"),
	HX_CSTRING("__get"),
	HX_CSTRING("__set"),
	HX_CSTRING("__throwEOFi"),
	HX_CSTRING("get_bytesAvailable"),
	HX_CSTRING("get_byteLength"),
	HX_CSTRING("get_endian"),
	HX_CSTRING("set_endian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::lime_byte_array_overwrite_file,"lime_byte_array_overwrite_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::lime_byte_array_read_file,"lime_byte_array_read_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::lime_byte_array_get_native_pointer,"lime_byte_array_get_native_pointer");
	HX_MARK_MEMBER_NAME(ByteArray_obj::lime_lzma_encode,"lime_lzma_encode");
	HX_MARK_MEMBER_NAME(ByteArray_obj::lime_lzma_decode,"lime_lzma_decode");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::lime_byte_array_overwrite_file,"lime_byte_array_overwrite_file");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::lime_byte_array_read_file,"lime_byte_array_read_file");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::lime_byte_array_get_native_pointer,"lime_byte_array_get_native_pointer");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::lime_lzma_encode,"lime_lzma_encode");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::lime_lzma_decode,"lime_lzma_decode");
};

#endif

Class ByteArray_obj::__mClass;

void ByteArray_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.utils.ByteArray"), hx::TCanCast< ByteArray_obj> ,sStaticFields,sMemberFields,
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

void ByteArray_obj::__boot()
{
	_double_bytes= ::openfl::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_bytes"),(int)2);
	_double_of_bytes= ::openfl::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_of_bytes"),(int)2);
	_float_bytes= ::openfl::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_bytes"),(int)2);
	_float_of_bytes= ::openfl::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_of_bytes"),(int)2);
	lime_byte_array_overwrite_file= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_byte_array_overwrite_file"),(int)2);
	lime_byte_array_read_file= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_byte_array_read_file"),(int)1);
	lime_byte_array_get_native_pointer= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_byte_array_get_native_pointer"),(int)1);
	lime_lzma_encode= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_lzma_encode"),(int)1);
	lime_lzma_decode= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_lzma_decode"),(int)1);
}

} // end namespace openfl
} // end namespace utils
