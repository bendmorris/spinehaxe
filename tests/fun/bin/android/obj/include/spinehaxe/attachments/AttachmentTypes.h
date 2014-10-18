#ifndef INCLUDED_spinehaxe_attachments_AttachmentTypes
#define INCLUDED_spinehaxe_attachments_AttachmentTypes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentType)
HX_DECLARE_CLASS2(spinehaxe,attachments,AttachmentTypes)
namespace spinehaxe{
namespace attachments{


class HXCPP_CLASS_ATTRIBUTES  AttachmentTypes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AttachmentTypes_obj OBJ_;
		AttachmentTypes_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AttachmentTypes_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AttachmentTypes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("AttachmentTypes"); }

		static ::spinehaxe::attachments::AttachmentType valueOf( ::String t,::spinehaxe::attachments::AttachmentType def);
		static Dynamic valueOf_dyn();

};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_AttachmentTypes */ 
