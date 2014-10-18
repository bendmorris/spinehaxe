#ifndef INCLUDED_openfl_display_Shape
#define INCLUDED_openfl_display_Shape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/DisplayObject.h>
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,Shape)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  Shape_obj : public ::openfl::display::DisplayObject_obj{
	public:
		typedef ::openfl::display::DisplayObject_obj super;
		typedef Shape_obj OBJ_;
		Shape_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Shape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Shape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Shape"); }

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_Shape */ 
