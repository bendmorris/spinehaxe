#ifndef INCLUDED_haxe_io_BytesInput
#define INCLUDED_haxe_io_BytesInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,BytesInput)
HX_DECLARE_CLASS2(haxe,io,Input)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  BytesInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef BytesInput_obj OBJ_;
		BytesInput_obj();
		Void __construct(::haxe::io::Bytes b,Dynamic pos,Dynamic len);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BytesInput_obj > __new(::haxe::io::Bytes b,Dynamic pos,Dynamic len);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BytesInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BytesInput"); }

		Array< unsigned char > b;
		int pos;
		int len;
		int totlen;
		virtual int readByte( );

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_BytesInput */ 
