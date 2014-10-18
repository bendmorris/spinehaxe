#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTextureLoader
#define INCLUDED_spinehaxe_platform_nme_BitmapDataTextureLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/atlas/TextureLoader.h>
HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureLoader)
HX_DECLARE_CLASS3(spinehaxe,platform,nme,BitmapDataTextureLoader)
namespace spinehaxe{
namespace platform{
namespace nme{


class HXCPP_CLASS_ATTRIBUTES  BitmapDataTextureLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapDataTextureLoader_obj OBJ_;
		BitmapDataTextureLoader_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BitmapDataTextureLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BitmapDataTextureLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		inline operator ::spinehaxe::atlas::TextureLoader_obj *()
			{ return new ::spinehaxe::atlas::TextureLoader_delegate_< BitmapDataTextureLoader_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("BitmapDataTextureLoader"); }

		virtual ::spinehaxe::atlas::Texture loadTexture( ::String textureFile,::String format,bool useMipMaps);
		Dynamic loadTexture_dyn();

};

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_spinehaxe_platform_nme_BitmapDataTextureLoader */ 
