#ifndef INCLUDED_spinehaxe_animation_TrackEntryPool
#define INCLUDED_spinehaxe_animation_TrackEntryPool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,animation,TrackEntry)
HX_DECLARE_CLASS2(spinehaxe,animation,TrackEntryPool)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  TrackEntryPool_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TrackEntryPool_obj OBJ_;
		TrackEntryPool_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TrackEntryPool_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TrackEntryPool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TrackEntryPool"); }

		Array< ::Dynamic > objs;
		virtual Void free( ::spinehaxe::animation::TrackEntry obj);
		Dynamic free_dyn();

		virtual ::spinehaxe::animation::TrackEntry get( );
		Dynamic get_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_TrackEntryPool */ 
