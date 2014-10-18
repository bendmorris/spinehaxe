#ifndef INCLUDED_openfl_display_FPS
#define INCLUDED_openfl_display_FPS

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/text/TextField.h>
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,FPS)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,text,TextField)
namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  FPS_obj : public ::openfl::text::TextField_obj{
	public:
		typedef ::openfl::text::TextField_obj super;
		typedef FPS_obj OBJ_;
		FPS_obj();
		Void __construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FPS_obj > __new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FPS_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FPS"); }

		Float currentFPS;
		int cacheCount;
		Array< Float > times;
		virtual Void this_onEnterFrame( ::openfl::events::Event event);
		Dynamic this_onEnterFrame_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_FPS */ 
