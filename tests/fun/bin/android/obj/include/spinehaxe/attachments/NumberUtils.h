#ifndef INCLUDED_spinehaxe_attachments_NumberUtils
#define INCLUDED_spinehaxe_attachments_NumberUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,attachments,NumberUtils)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  NumberUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NumberUtils_obj OBJ_;
		NumberUtils_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< NumberUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~NumberUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("NumberUtils"); }

		static Float intToFloatColor( int value);
		static Dynamic intToFloatColor_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_NumberUtils */ 
