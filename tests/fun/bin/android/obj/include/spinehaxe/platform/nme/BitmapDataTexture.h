#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTexture
#define INCLUDED_spinehaxe_platform_nme_BitmapDataTexture

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/atlas/Texture.h>
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
HX_DECLARE_CLASS3(spinehaxe,platform,nme,BitmapDataTexture)
namespace spinehaxe{
namespace platform{
namespace nme{


class HXCPP_CLASS_ATTRIBUTES  BitmapDataTexture_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapDataTexture_obj OBJ_;
		BitmapDataTexture_obj();
		Void __construct(::String textureFile);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BitmapDataTexture_obj > __new(::String textureFile);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BitmapDataTexture_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::spinehaxe::atlas::Texture_obj *()
			{ return new ::spinehaxe::atlas::Texture_delegate_< BitmapDataTexture_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("BitmapDataTexture"); }

		::openfl::display::BitmapData bd;
		virtual int get_width( );
		Dynamic get_width_dyn();

		virtual int get_height( );
		Dynamic get_height_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void setWrap( ::String uWrap,::String vWrap);
		Dynamic setWrap_dyn();

		virtual Void setFilter( ::String minFilter,::String magFilter);
		Dynamic setFilter_dyn();

};

} // end namespace spinehaxe
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_spinehaxe_platform_nme_BitmapDataTexture */ 
