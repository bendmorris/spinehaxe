#ifndef INCLUDED_openfl_events_EventDispatcher
#define INCLUDED_openfl_events_EventDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/events/IEventDispatcher.h>
HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,Listener)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  EventDispatcher_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventDispatcher_obj OBJ_;
		EventDispatcher_obj();
		Void __construct(::openfl::events::IEventDispatcher target);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EventDispatcher_obj > __new(::openfl::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventDispatcher_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::openfl::events::IEventDispatcher_obj *()
			{ return new ::openfl::events::IEventDispatcher_delegate_< EventDispatcher_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("EventDispatcher"); }

		::haxe::ds::StringMap __eventMap;
		::openfl::events::IEventDispatcher __target;
		virtual Void addEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture,hx::Null< int >  priority,hx::Null< bool >  useWeakReference);
		Dynamic addEventListener_dyn();

		virtual bool dispatchEvent( ::openfl::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual bool hasEventListener( ::String type);
		Dynamic hasEventListener_dyn();

		virtual Void removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  capture);
		Dynamic removeEventListener_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual bool willTrigger( ::String type);
		Dynamic willTrigger_dyn();

		virtual Void __dispatchCompleteEvent( );
		Dynamic __dispatchCompleteEvent_dyn();

		virtual Void __dispatchIOErrorEvent( );
		Dynamic __dispatchIOErrorEvent_dyn();

		static int __sortEvents( ::openfl::events::Listener a,::openfl::events::Listener b);
		static Dynamic __sortEvents_dyn();

};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_EventDispatcher */ 
