#ifndef INCLUDED_openfl_events_HTTPStatusEvent
#define INCLUDED_openfl_events_HTTPStatusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/events/Event.h>
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,HTTPStatusEvent)
HX_DECLARE_CLASS2(openfl,net,URLRequestHeader)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  HTTPStatusEvent_obj : public ::openfl::events::Event_obj{
	public:
		typedef ::openfl::events::Event_obj super;
		typedef HTTPStatusEvent_obj OBJ_;
		HTTPStatusEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HTTPStatusEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HTTPStatusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTTPStatusEvent"); }

		int status;
		Array< ::Dynamic > responseHeaders;
		::String responseURL;
		virtual ::openfl::events::Event clone( );

		virtual ::String toString( );

		static ::String HTTP_STATUS;
};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_HTTPStatusEvent */ 
