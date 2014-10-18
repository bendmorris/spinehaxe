#ifndef INCLUDED_haxe_io_Output
#define INCLUDED_haxe_io_Output

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Output)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Output_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Output_obj OBJ_;
		Output_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Output_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Output_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Output"); }

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Output */ 
