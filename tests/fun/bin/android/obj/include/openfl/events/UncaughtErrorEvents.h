#ifndef INCLUDED_openfl_events_UncaughtErrorEvents
#define INCLUDED_openfl_events_UncaughtErrorEvents

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/events/EventDispatcher.h>
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,UncaughtErrorEvents)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  UncaughtErrorEvents_obj : public ::openfl::events::EventDispatcher_obj{
	public:
		typedef ::openfl::events::EventDispatcher_obj super;
		typedef UncaughtErrorEvents_obj OBJ_;
		UncaughtErrorEvents_obj();
		Void __construct(::openfl::events::IEventDispatcher target);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UncaughtErrorEvents_obj > __new(::openfl::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UncaughtErrorEvents_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("UncaughtErrorEvents"); }

};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_UncaughtErrorEvents */ 
