#ifndef INCLUDED_spinehaxe_atlas_AtlasRegion
#define INCLUDED_spinehaxe_atlas_AtlasRegion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <spinehaxe/atlas/TextureRegion.h>
HX_DECLARE_CLASS2(spinehaxe,atlas,AtlasRegion)
HX_DECLARE_CLASS2(spinehaxe,atlas,Texture)
HX_DECLARE_CLASS2(spinehaxe,atlas,TextureRegion)
namespace spinehaxe{
namespace atlas{


class HXCPP_CLASS_ATTRIBUTES  AtlasRegion_obj : public ::spinehaxe::atlas::TextureRegion_obj{
	public:
		typedef ::spinehaxe::atlas::TextureRegion_obj super;
		typedef AtlasRegion_obj OBJ_;
		AtlasRegion_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AtlasRegion_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AtlasRegion_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AtlasRegion"); }

		int index;
		::String name;
		Float offsetX;
		Float offsetY;
		int packedWidth;
		int packedHeight;
		int originalWidth;
		int originalHeight;
		bool rotate;
		Array< int > splits;
		Array< int > pads;
		virtual Void flip( bool x,bool y);

		virtual Float getRotatedPackedWidth( );
		Dynamic getRotatedPackedWidth_dyn();

		virtual Float getRotatedPackedHeight( );
		Dynamic getRotatedPackedHeight_dyn();

		static ::spinehaxe::atlas::AtlasRegion create( ::spinehaxe::atlas::Texture texture,int x,int y,int width,int height);
		static Dynamic create_dyn();

		static ::spinehaxe::atlas::AtlasRegion copy( ::spinehaxe::atlas::AtlasRegion region);
		static Dynamic copy_dyn();

};

} // end namespace spinehaxe
} // end namespace atlas

#endif /* INCLUDED_spinehaxe_atlas_AtlasRegion */ 
