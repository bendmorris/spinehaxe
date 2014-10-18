#ifndef INCLUDED_spinehaxe_atlas_TextureAtlas
#define INCLUDED_spinehaxe_atlas_TextureAtlas

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,atlas,AtlasRegion)
HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlas)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureAtlasData)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureLoader)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureRegion)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  TextureAtlas_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextureAtlas_obj OBJ_;
		TextureAtlas_obj();
		Void __construct(::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureAtlas_obj > __new(::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureAtlas_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextureAtlas"); }

		Array< ::spinehaxe::atlas::Texture > textures;
		Array< ::Dynamic > regions;
		virtual Void addTexture( ::spinehaxe::atlas::Texture texture);
		Dynamic addTexture_dyn();

		virtual Void load( ::spinehaxe::atlas::TextureAtlasData data,::spinehaxe::atlas::TextureLoader textureLoader);
		Dynamic load_dyn();

		virtual ::spinehaxe::atlas::AtlasRegion addRegion( ::String name,::spinehaxe::atlas::Texture texture,int x,int y,int width,int height);
		Dynamic addRegion_dyn();

		virtual ::spinehaxe::atlas::AtlasRegion addRegionTex( ::String name,::spinehaxe::atlas::TextureRegion textureRegion);
		Dynamic addRegionTex_dyn();

		virtual Array< ::Dynamic > getRegions( );
		Dynamic getRegions_dyn();

		virtual ::spinehaxe::atlas::AtlasRegion findRegion( ::String name);
		Dynamic findRegion_dyn();

		virtual ::spinehaxe::atlas::AtlasRegion findRegionIdx( ::String name,int index);
		Dynamic findRegionIdx_dyn();

		virtual Array< ::Dynamic > findRegions( ::String name);
		Dynamic findRegions_dyn();

		virtual Array< ::spinehaxe::atlas::Texture > getTextures( );
		Dynamic getTextures_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		static ::spinehaxe::atlas::TextureAtlas create( ::String packFileData,::String imagesDir,::spinehaxe::atlas::TextureLoader textureLoader,hx::Null< bool >  flip);
		static Dynamic create_dyn();

};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_TextureAtlas */ 
