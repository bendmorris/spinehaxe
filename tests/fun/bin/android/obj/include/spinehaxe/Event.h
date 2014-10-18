#ifndef INCLUDED_spinehaxe_Event
#define INCLUDED_spinehaxe_Event

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,EventData)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  Event_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Event_obj OBJ_;
		Event_obj();
		Void __construct(::spinehaxe::EventData data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Event_obj > __new(::spinehaxe::EventData data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Event_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Event"); }

		::spinehaxe::EventData data;
		int intValue;
		Float floatValue;
		::String stringValue;
		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_Event */ 
