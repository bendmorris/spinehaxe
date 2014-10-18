#ifndef INCLUDED_spinehaxe_EventData
#define INCLUDED_spinehaxe_EventData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,EventData)
namespace spinehaxe{


class HXCPP_CLASS_ATTRIBUTES  EventData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventData_obj OBJ_;
		EventData_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EventData_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventData"); }

		::String name;
		int intValue;
		Float floatValue;
		::String stringValue;
		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace spinehaxe

#endif /* INCLUDED_spinehaxe_EventData */ 
