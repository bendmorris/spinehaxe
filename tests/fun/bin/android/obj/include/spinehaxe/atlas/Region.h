#ifndef INCLUDED_spinehaxe_atlas_Region
#define INCLUDED_spinehaxe_atlas_Region

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,atlas,Page)
HX_DECLARE_CLASS2(spinehaxe,atlas,Region)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  Region_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Region_obj OBJ_;
		Region_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Region_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Region_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Region"); }

		::spinehaxe::atlas::Page page;
		int index;
		::String name;
		Float offsetX;
		Float offsetY;
		int originalWidth;
		int originalHeight;
		bool rotate;
		int left;
		int top;
		int width;
		int height;
		bool flip;
		Array< int > splits;
		Array< int > pads;
};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_Region */ 
