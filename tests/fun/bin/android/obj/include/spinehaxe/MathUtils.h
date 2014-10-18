#ifndef INCLUDED_spinehaxe_MathUtils
#define INCLUDED_spinehaxe_MathUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,MathUtils)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  MathUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MathUtils_obj OBJ_;
		MathUtils_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MathUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MathUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("MathUtils"); }

		static Float radToDeg( Float rad);
		static Dynamic radToDeg_dyn();

		static Float degToRad( Float deg);
		static Dynamic degToRad_dyn();

		static Float clamp( Float value,Float min,Float max);
		static Dynamic clamp_dyn();

		static int random( int max);
		static Dynamic random_dyn();

		static int minInt( int a,int b);
		static Dynamic minInt_dyn();

		static int maxInt( int a,int b);
		static Dynamic maxInt_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_MathUtils */ 
