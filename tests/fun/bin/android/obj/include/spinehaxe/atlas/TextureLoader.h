#ifndef INCLUDED_spinehaxe_atlas_TextureLoader
#define INCLUDED_spinehaxe_atlas_TextureLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureLoader)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  TextureLoader_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef TextureLoader_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::spinehaxe::atlas::Texture loadTexture( ::String textureFile,::String format,bool useMipMaps)=0;
		Dynamic loadTexture_dyn();
};

#define DELEGATE_spinehaxe_atlas_TextureLoader \
virtual ::spinehaxe::atlas::Texture loadTexture( ::String textureFile,::String format,bool useMipMaps) { return mDelegate->loadTexture(textureFile,format,useMipMaps);}  \
virtual Dynamic loadTexture_dyn() { return mDelegate->loadTexture_dyn();}  \


template<typename IMPL>
class TextureLoader_delegate_ : public TextureLoader_obj
{
	protected:
		IMPL *mDelegate;
	public:
		TextureLoader_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_spinehaxe_atlas_TextureLoader
};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_TextureLoader */ 
