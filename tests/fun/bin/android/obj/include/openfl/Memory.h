#ifndef INCLUDED_openfl_Memory
#define INCLUDED_openfl_Memory

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(openfl,Memory)
HX_DECLARE_CLASS2(openfl,utils,ByteArray)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace openfl{


class HXCPP_CLASS_ATTRIBUTES  Memory_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Memory_obj OBJ_;
		Memory_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Memory_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Memory_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Memory"); }

		static ::openfl::utils::ByteArray gcRef;
		static int len;
		static Void select( ::openfl::utils::ByteArray bytes);
		static Dynamic select_dyn();

		static int getByte( int addr);
		static Dynamic getByte_dyn();

		static Float getDouble( int addr);
		static Dynamic getDouble_dyn();

		static Float getFloat( int addr);
		static Dynamic getFloat_dyn();

		static int getI32( int addr);
		static Dynamic getI32_dyn();

		static int getUI16( int addr);
		static Dynamic getUI16_dyn();

		static Void setByte( int addr,int v);
		static Dynamic setByte_dyn();

		static Void setDouble( int addr,Float v);
		static Dynamic setDouble_dyn();

		static Void setFloat( int addr,Float v);
		static Dynamic setFloat_dyn();

		static Void setI16( int addr,int v);
		static Dynamic setI16_dyn();

		static Void setI32( int addr,int v);
		static Dynamic setI32_dyn();

};

} // end namespace openfl

#endif /* INCLUDED_openfl_Memory */ 
