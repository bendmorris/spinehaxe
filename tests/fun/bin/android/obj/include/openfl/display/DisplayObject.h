#ifndef INCLUDED_openfl_display_DisplayObject
#define INCLUDED_openfl_display_DisplayObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/events/EventDispatcher.h>
#include <openfl/display/IBitmapDrawable.h>
HX_DECLARE_CLASS2(openfl,display,BlendMode)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,Graphics)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,LoaderInfo)
HX_DECLARE_CLASS2(openfl,display,PixelSnapping)
HX_DECLARE_CLASS2(openfl,display,Stage)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,geom,ColorTransform)
HX_DECLARE_CLASS2(openfl,geom,Matrix)
HX_DECLARE_CLASS2(openfl,geom,Point)
HX_DECLARE_CLASS2(openfl,geom,Rectangle)
HX_DECLARE_CLASS2(openfl,geom,Transform)
HX_DECLARE_CLASS2(openfl,net,URLLoader)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  DisplayObject_obj : public ::openfl::events::EventDispatcher_obj{
	public:
		typedef ::openfl::events::EventDispatcher_obj super;
		typedef DisplayObject_obj OBJ_;
		DisplayObject_obj();
		Void __construct(Dynamic handle,::String type);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DisplayObject_obj > __new(Dynamic handle,::String type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DisplayObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::openfl::display::IBitmapDrawable_obj *()
			{ return new ::openfl::display::IBitmapDrawable_delegate_< DisplayObject_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("DisplayObject"); }

		::openfl::display::Graphics graphics;
		::openfl::display::LoaderInfo loaderInfo;
		::openfl::display::DisplayObject mask;
		Float mouseX;
		Float mouseY;
		::openfl::display::DisplayObjectContainer parent;
		::openfl::display::DisplayObject root;
		::openfl::display::Stage stage;
		Dynamic __handle;
		Dynamic __filters;
		::openfl::display::Graphics __graphicsCache;
		int __id;
		::openfl::display::DisplayObjectContainer __parent;
		::openfl::geom::Rectangle __scale9Grid;
		::openfl::geom::Rectangle __scrollRect;
		virtual bool dispatchEvent( ::openfl::events::Event event);

		virtual ::openfl::geom::Rectangle getBounds( ::openfl::display::DisplayObject targetCoordinateSpace);
		Dynamic getBounds_dyn();

		virtual ::openfl::geom::Rectangle getRect( ::openfl::display::DisplayObject targetCoordinateSpace);
		Dynamic getRect_dyn();

		virtual ::openfl::geom::Point globalToLocal( ::openfl::geom::Point point);
		Dynamic globalToLocal_dyn();

		virtual bool hitTestObject( ::openfl::display::DisplayObject object);
		Dynamic hitTestObject_dyn();

		virtual bool hitTestPoint( Float x,Float y,hx::Null< bool >  shapeFlag);
		Dynamic hitTestPoint_dyn();

		virtual ::openfl::geom::Point localToGlobal( ::openfl::geom::Point point);
		Dynamic localToGlobal_dyn();

		virtual ::String toString( );

		virtual ::openfl::display::InteractiveObject __asInteractiveObject( );
		Dynamic __asInteractiveObject_dyn();

		virtual Void __broadcast( ::openfl::events::Event event);
		Dynamic __broadcast_dyn();

		virtual bool __contains( ::openfl::display::DisplayObject child);
		Dynamic __contains_dyn();

		virtual bool __dispatchEvent( ::openfl::events::Event event);
		Dynamic __dispatchEvent_dyn();

		virtual Void __drawToSurface( Dynamic surface,::openfl::geom::Matrix matrix,::openfl::geom::ColorTransform colorTransform,::String blendMode,::openfl::geom::Rectangle clipRect,bool smoothing);
		Dynamic __drawToSurface_dyn();

		virtual ::openfl::display::DisplayObject __findByID( int id);
		Dynamic __findByID_dyn();

		virtual Void __fireEvent( ::openfl::events::Event event);
		Dynamic __fireEvent_dyn();

		virtual ::openfl::geom::ColorTransform __getColorTransform( );
		Dynamic __getColorTransform_dyn();

		virtual ::openfl::geom::ColorTransform __getConcatenatedColorTransform( );
		Dynamic __getConcatenatedColorTransform_dyn();

		virtual ::openfl::geom::Matrix __getConcatenatedMatrix( );
		Dynamic __getConcatenatedMatrix_dyn();

		virtual Void __getInteractiveObjectStack( Array< ::Dynamic > stack);
		Dynamic __getInteractiveObjectStack_dyn();

		virtual ::openfl::geom::Matrix __getMatrix( );
		Dynamic __getMatrix_dyn();

		virtual Void __getObjectsUnderPoint( ::openfl::geom::Point point,Array< ::Dynamic > result);
		Dynamic __getObjectsUnderPoint_dyn();

		virtual ::openfl::geom::Rectangle __getPixelBounds( );
		Dynamic __getPixelBounds_dyn();

		virtual Void __onAdded( ::openfl::display::DisplayObject object,bool isOnStage);
		Dynamic __onAdded_dyn();

		virtual Void __onRemoved( ::openfl::display::DisplayObject object,bool wasOnStage);
		Dynamic __onRemoved_dyn();

		virtual Void __setColorTransform( ::openfl::geom::ColorTransform colorTransform);
		Dynamic __setColorTransform_dyn();

		virtual Void __setMatrix( ::openfl::geom::Matrix matrix);
		Dynamic __setMatrix_dyn();

		virtual ::openfl::display::DisplayObjectContainer __setParent( ::openfl::display::DisplayObjectContainer parent);
		Dynamic __setParent_dyn();

		virtual Float get_alpha( );
		Dynamic get_alpha_dyn();

		virtual Float set_alpha( Float value);
		Dynamic set_alpha_dyn();

		virtual Dynamic get_opaqueBackground( );
		Dynamic get_opaqueBackground_dyn();

		virtual Dynamic set_opaqueBackground( Dynamic value);
		Dynamic set_opaqueBackground_dyn();

		virtual ::openfl::display::BlendMode get_blendMode( );
		Dynamic get_blendMode_dyn();

		virtual ::openfl::display::BlendMode set_blendMode( ::openfl::display::BlendMode value);
		Dynamic set_blendMode_dyn();

		virtual bool get_cacheAsBitmap( );
		Dynamic get_cacheAsBitmap_dyn();

		virtual bool set_cacheAsBitmap( bool value);
		Dynamic set_cacheAsBitmap_dyn();

		virtual bool get_pedanticBitmapCaching( );
		Dynamic get_pedanticBitmapCaching_dyn();

		virtual bool set_pedanticBitmapCaching( bool value);
		Dynamic set_pedanticBitmapCaching_dyn();

		virtual ::openfl::display::PixelSnapping get_pixelSnapping( );
		Dynamic get_pixelSnapping_dyn();

		virtual ::openfl::display::PixelSnapping set_pixelSnapping( ::openfl::display::PixelSnapping value);
		Dynamic set_pixelSnapping_dyn();

		virtual Dynamic get_filters( );
		Dynamic get_filters_dyn();

		virtual Dynamic set_filters( Dynamic value);
		Dynamic set_filters_dyn();

		virtual ::openfl::display::Graphics get_graphics( );
		Dynamic get_graphics_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float value);
		Dynamic set_height_dyn();

		virtual ::openfl::display::DisplayObject set_mask( ::openfl::display::DisplayObject value);
		Dynamic set_mask_dyn();

		virtual Float get_mouseX( );
		Dynamic get_mouseX_dyn();

		virtual Float get_mouseY( );
		Dynamic get_mouseY_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual ::String set_name( ::String value);
		Dynamic set_name_dyn();

		virtual ::openfl::display::DisplayObjectContainer get_parent( );
		Dynamic get_parent_dyn();

		virtual ::openfl::display::DisplayObject get_root( );
		Dynamic get_root_dyn();

		virtual Float get_rotation( );
		Dynamic get_rotation_dyn();

		virtual Float set_rotation( Float value);
		Dynamic set_rotation_dyn();

		virtual ::openfl::geom::Rectangle get_scale9Grid( );
		Dynamic get_scale9Grid_dyn();

		virtual ::openfl::geom::Rectangle set_scale9Grid( ::openfl::geom::Rectangle value);
		Dynamic set_scale9Grid_dyn();

		virtual Float get_scaleX( );
		Dynamic get_scaleX_dyn();

		virtual Float set_scaleX( Float value);
		Dynamic set_scaleX_dyn();

		virtual Float get_scaleY( );
		Dynamic get_scaleY_dyn();

		virtual Float set_scaleY( Float value);
		Dynamic set_scaleY_dyn();

		virtual ::openfl::geom::Rectangle get_scrollRect( );
		Dynamic get_scrollRect_dyn();

		virtual ::openfl::geom::Rectangle set_scrollRect( ::openfl::geom::Rectangle value);
		Dynamic set_scrollRect_dyn();

		virtual ::openfl::display::Stage get_stage( );
		Dynamic get_stage_dyn();

		virtual ::openfl::geom::Transform get_transform( );
		Dynamic get_transform_dyn();

		virtual ::openfl::geom::Transform set_transform( ::openfl::geom::Transform value);
		Dynamic set_transform_dyn();

		virtual bool get_visible( );
		Dynamic get_visible_dyn();

		virtual bool set_visible( bool value);
		Dynamic set_visible_dyn();

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual Float set_width( Float value);
		Dynamic set_width_dyn();

		virtual Float get_x( );
		Dynamic get_x_dyn();

		virtual Float set_x( Float value);
		Dynamic set_x_dyn();

		virtual Float get_y( );
		Dynamic get_y_dyn();

		virtual Float set_y( Float value);
		Dynamic set_y_dyn();

		virtual Float get_z( );
		Dynamic get_z_dyn();

		virtual Float set_z( Float value);
		Dynamic set_z_dyn();

		static Dynamic lime_create_display_object;
		static Dynamic &lime_create_display_object_dyn() { return lime_create_display_object;}
		static Dynamic lime_display_object_get_graphics;
		static Dynamic &lime_display_object_get_graphics_dyn() { return lime_display_object_get_graphics;}
		static Dynamic lime_display_object_draw_to_surface;
		static Dynamic &lime_display_object_draw_to_surface_dyn() { return lime_display_object_draw_to_surface;}
		static Dynamic lime_display_object_get_id;
		static Dynamic &lime_display_object_get_id_dyn() { return lime_display_object_get_id;}
		static Dynamic lime_display_object_get_x;
		static Dynamic &lime_display_object_get_x_dyn() { return lime_display_object_get_x;}
		static Dynamic lime_display_object_set_x;
		static Dynamic &lime_display_object_set_x_dyn() { return lime_display_object_set_x;}
		static Dynamic lime_display_object_get_y;
		static Dynamic &lime_display_object_get_y_dyn() { return lime_display_object_get_y;}
		static Dynamic lime_display_object_set_y;
		static Dynamic &lime_display_object_set_y_dyn() { return lime_display_object_set_y;}
		static Dynamic lime_display_object_get_z;
		static Dynamic &lime_display_object_get_z_dyn() { return lime_display_object_get_z;}
		static Dynamic lime_display_object_set_z;
		static Dynamic &lime_display_object_set_z_dyn() { return lime_display_object_set_z;}
		static Dynamic lime_display_object_get_scale_x;
		static Dynamic &lime_display_object_get_scale_x_dyn() { return lime_display_object_get_scale_x;}
		static Dynamic lime_display_object_set_scale_x;
		static Dynamic &lime_display_object_set_scale_x_dyn() { return lime_display_object_set_scale_x;}
		static Dynamic lime_display_object_get_scale_y;
		static Dynamic &lime_display_object_get_scale_y_dyn() { return lime_display_object_get_scale_y;}
		static Dynamic lime_display_object_set_scale_y;
		static Dynamic &lime_display_object_set_scale_y_dyn() { return lime_display_object_set_scale_y;}
		static Dynamic lime_display_object_get_mouse_x;
		static Dynamic &lime_display_object_get_mouse_x_dyn() { return lime_display_object_get_mouse_x;}
		static Dynamic lime_display_object_get_mouse_y;
		static Dynamic &lime_display_object_get_mouse_y_dyn() { return lime_display_object_get_mouse_y;}
		static Dynamic lime_display_object_get_rotation;
		static Dynamic &lime_display_object_get_rotation_dyn() { return lime_display_object_get_rotation;}
		static Dynamic lime_display_object_set_rotation;
		static Dynamic &lime_display_object_set_rotation_dyn() { return lime_display_object_set_rotation;}
		static Dynamic lime_display_object_get_bg;
		static Dynamic &lime_display_object_get_bg_dyn() { return lime_display_object_get_bg;}
		static Dynamic lime_display_object_set_bg;
		static Dynamic &lime_display_object_set_bg_dyn() { return lime_display_object_set_bg;}
		static Dynamic lime_display_object_get_name;
		static Dynamic &lime_display_object_get_name_dyn() { return lime_display_object_get_name;}
		static Dynamic lime_display_object_set_name;
		static Dynamic &lime_display_object_set_name_dyn() { return lime_display_object_set_name;}
		static Dynamic lime_display_object_get_width;
		static Dynamic &lime_display_object_get_width_dyn() { return lime_display_object_get_width;}
		static Dynamic lime_display_object_set_width;
		static Dynamic &lime_display_object_set_width_dyn() { return lime_display_object_set_width;}
		static Dynamic lime_display_object_get_height;
		static Dynamic &lime_display_object_get_height_dyn() { return lime_display_object_get_height;}
		static Dynamic lime_display_object_set_height;
		static Dynamic &lime_display_object_set_height_dyn() { return lime_display_object_set_height;}
		static Dynamic lime_display_object_get_alpha;
		static Dynamic &lime_display_object_get_alpha_dyn() { return lime_display_object_get_alpha;}
		static Dynamic lime_display_object_set_alpha;
		static Dynamic &lime_display_object_set_alpha_dyn() { return lime_display_object_set_alpha;}
		static Dynamic lime_display_object_get_blend_mode;
		static Dynamic &lime_display_object_get_blend_mode_dyn() { return lime_display_object_get_blend_mode;}
		static Dynamic lime_display_object_set_blend_mode;
		static Dynamic &lime_display_object_set_blend_mode_dyn() { return lime_display_object_set_blend_mode;}
		static Dynamic lime_display_object_get_cache_as_bitmap;
		static Dynamic &lime_display_object_get_cache_as_bitmap_dyn() { return lime_display_object_get_cache_as_bitmap;}
		static Dynamic lime_display_object_set_cache_as_bitmap;
		static Dynamic &lime_display_object_set_cache_as_bitmap_dyn() { return lime_display_object_set_cache_as_bitmap;}
		static Dynamic lime_display_object_get_pedantic_bitmap_caching;
		static Dynamic &lime_display_object_get_pedantic_bitmap_caching_dyn() { return lime_display_object_get_pedantic_bitmap_caching;}
		static Dynamic lime_display_object_set_pedantic_bitmap_caching;
		static Dynamic &lime_display_object_set_pedantic_bitmap_caching_dyn() { return lime_display_object_set_pedantic_bitmap_caching;}
		static Dynamic lime_display_object_get_pixel_snapping;
		static Dynamic &lime_display_object_get_pixel_snapping_dyn() { return lime_display_object_get_pixel_snapping;}
		static Dynamic lime_display_object_set_pixel_snapping;
		static Dynamic &lime_display_object_set_pixel_snapping_dyn() { return lime_display_object_set_pixel_snapping;}
		static Dynamic lime_display_object_get_visible;
		static Dynamic &lime_display_object_get_visible_dyn() { return lime_display_object_get_visible;}
		static Dynamic lime_display_object_set_visible;
		static Dynamic &lime_display_object_set_visible_dyn() { return lime_display_object_set_visible;}
		static Dynamic lime_display_object_set_filters;
		static Dynamic &lime_display_object_set_filters_dyn() { return lime_display_object_set_filters;}
		static Dynamic lime_display_object_global_to_local;
		static Dynamic &lime_display_object_global_to_local_dyn() { return lime_display_object_global_to_local;}
		static Dynamic lime_display_object_local_to_global;
		static Dynamic &lime_display_object_local_to_global_dyn() { return lime_display_object_local_to_global;}
		static Dynamic lime_display_object_set_scale9_grid;
		static Dynamic &lime_display_object_set_scale9_grid_dyn() { return lime_display_object_set_scale9_grid;}
		static Dynamic lime_display_object_set_scroll_rect;
		static Dynamic &lime_display_object_set_scroll_rect_dyn() { return lime_display_object_set_scroll_rect;}
		static Dynamic lime_display_object_set_mask;
		static Dynamic &lime_display_object_set_mask_dyn() { return lime_display_object_set_mask;}
		static Dynamic lime_display_object_set_matrix;
		static Dynamic &lime_display_object_set_matrix_dyn() { return lime_display_object_set_matrix;}
		static Dynamic lime_display_object_get_matrix;
		static Dynamic &lime_display_object_get_matrix_dyn() { return lime_display_object_get_matrix;}
		static Dynamic lime_display_object_get_color_transform;
		static Dynamic &lime_display_object_get_color_transform_dyn() { return lime_display_object_get_color_transform;}
		static Dynamic lime_display_object_set_color_transform;
		static Dynamic &lime_display_object_set_color_transform_dyn() { return lime_display_object_set_color_transform;}
		static Dynamic lime_display_object_get_pixel_bounds;
		static Dynamic &lime_display_object_get_pixel_bounds_dyn() { return lime_display_object_get_pixel_bounds;}
		static Dynamic lime_display_object_get_bounds;
		static Dynamic &lime_display_object_get_bounds_dyn() { return lime_display_object_get_bounds;}
		static Dynamic lime_display_object_hit_test_point;
		static Dynamic &lime_display_object_hit_test_point_dyn() { return lime_display_object_hit_test_point;}
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_DisplayObject */ 
