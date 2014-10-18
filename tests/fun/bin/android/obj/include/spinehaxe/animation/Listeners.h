#ifndef INCLUDED_spinehaxe_animation_Listeners
#define INCLUDED_spinehaxe_animation_Listeners

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,animation,Listeners)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  Listeners_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Listeners_obj OBJ_;
		Listeners_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Listeners_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Listeners_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Listeners"); }

		Dynamic listeners;
		virtual Void add( Dynamic listener);
		Dynamic add_dyn();

		virtual Void remove( Dynamic listener);
		Dynamic remove_dyn();

		virtual Void invoke( int i,Dynamic arg);
		Dynamic invoke_dyn();

};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_Listeners */ 
