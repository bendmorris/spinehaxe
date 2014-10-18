#ifndef INCLUDED_spinehaxe_attachments_Modes
#define INCLUDED_spinehaxe_attachments_Modes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,attachments,Mode)
HX_DECLARE_CLASS2(spinehaxe,attachments,Modes)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  Modes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Modes_obj OBJ_;
		Modes_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Modes_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Modes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Modes"); }

		static ::spinehaxe::attachments::Mode valueOf( ::String t,::spinehaxe::attachments::Mode def);
		static Dynamic valueOf_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_Modes */ 
