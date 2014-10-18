#ifndef INCLUDED_spinehaxe_atlas_TextureAtlasData
#define INCLUDED_spinehaxe_atlas_TextureAtlasData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(spinehaxe,atlas,Page)
HX_DECLARE_CLASS2(spinehaxe,atlas,Region)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlasData)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  TextureAtlasData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextureAtlasData_obj OBJ_;
		TextureAtlasData_obj();
		Void __construct(::String packFileData,::String imagesDir,bool flip);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureAtlasData_obj > __new(::String packFileData,::String imagesDir,bool flip);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureAtlasData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextureAtlasData"); }

		Array< ::Dynamic > pages;
		Array< ::Dynamic > regions;
		Array< ::String > tuple;
		virtual ::String readValue( ::haxe::io::Input reader);
		Dynamic readValue_dyn();

		virtual int readTuple( ::haxe::io::Input reader);
		Dynamic readTuple_dyn();

		virtual Array< ::Dynamic > getPages( );
		Dynamic getPages_dyn();

		virtual Array< ::Dynamic > getRegions( );
		Dynamic getRegions_dyn();

};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_TextureAtlasData */ 
