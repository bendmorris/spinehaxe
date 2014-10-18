#ifndef INCLUDED_spinehaxe_atlas_Page
#define INCLUDED_spinehaxe_atlas_Page

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,atlas,Page)
HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  Page_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Page_obj OBJ_;
		Page_obj();
		Void __construct(::String textureFile,bool useMipMaps,::String format,::String minFilter,::String magFilter,::String uWrap,::String vWrap);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Page_obj > __new(::String textureFile,bool useMipMaps,::String format,::String minFilter,::String magFilter,::String uWrap,::String vWrap);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Page_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Page"); }

		::String textureFile;
		::spinehaxe::atlas::Texture texture;
		bool useMipMaps;
		::String format;
		::String minFilter;
		::String magFilter;
		::String uWrap;
		::String vWrap;
};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_Page */ 
