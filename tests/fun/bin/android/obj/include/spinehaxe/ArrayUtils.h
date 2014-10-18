#ifndef INCLUDED_spinehaxe_ArrayUtils
#define INCLUDED_spinehaxe_ArrayUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,ArrayUtils)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  ArrayUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArrayUtils_obj OBJ_;
		ArrayUtils_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ArrayUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ArrayUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ArrayUtils"); }

		static Array< Float > allocFloat( int n);
		static Dynamic allocFloat_dyn();

		static Array< ::String > allocString( int n);
		static Dynamic allocString_dyn();

		static int indexOf( Dynamic arr,Dynamic v);
		static Dynamic indexOf_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_ArrayUtils */ 
