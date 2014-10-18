#ifndef INCLUDED_openfl_events_TouchEvent
#define INCLUDED_openfl_events_TouchEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/events/MouseEvent.h>
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,events,TouchEvent)
HX_DECLARE_CLASS2(openfl,geom,Point)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  TouchEvent_obj : public ::openfl::events::MouseEvent_obj{
	public:
		typedef ::openfl::events::MouseEvent_obj super;
		typedef TouchEvent_obj OBJ_;
		TouchEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_localX,hx::Null< Float >  __o_localY,hx::Null< Float >  __o_sizeX,hx::Null< Float >  __o_sizeY,::openfl::display::InteractiveObject relatedObject,hx::Null< bool >  __o_ctrlKey,hx::Null< bool >  __o_altKey,hx::Null< bool >  __o_shiftKey,hx::Null< bool >  __o_buttonDown,hx::Null< int >  __o_delta,hx::Null< bool >  __o_commandKey,hx::Null< int >  __o_clickCount);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TouchEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_localX,hx::Null< Float >  __o_localY,hx::Null< Float >  __o_sizeX,hx::Null< Float >  __o_sizeY,::openfl::display::InteractiveObject relatedObject,hx::Null< bool >  __o_ctrlKey,hx::Null< bool >  __o_altKey,hx::Null< bool >  __o_shiftKey,hx::Null< bool >  __o_buttonDown,hx::Null< int >  __o_delta,hx::Null< bool >  __o_commandKey,hx::Null< int >  __o_clickCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TouchEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("TouchEvent"); }

		bool isPrimaryTouchPoint;
		Float pressure;
		Float sizeX;
		Float sizeY;
		int touchPointID;
		virtual ::openfl::events::MouseEvent __createSimilar( ::String type,::openfl::display::InteractiveObject related,::openfl::display::InteractiveObject target);

		static ::String TOUCH_BEGIN;
		static ::String TOUCH_END;
		static ::String TOUCH_MOVE;
		static ::String TOUCH_OUT;
		static ::String TOUCH_OVER;
		static ::String TOUCH_ROLL_OUT;
		static ::String TOUCH_ROLL_OVER;
		static ::String TOUCH_TAP;
		static ::openfl::events::TouchEvent __create( ::String type,Dynamic event,::openfl::geom::Point local,::openfl::display::InteractiveObject target,Float sizeX,Float sizeY);
		static Dynamic __create_dyn();

};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_TouchEvent */ 
