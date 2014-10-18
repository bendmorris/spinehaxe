#ifndef INCLUDED_spinehaxe_attachments_Mode
#define INCLUDED_spinehaxe_attachments_Mode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(spinehaxe,attachments,Mode)
namespace spinehaxe{
namespace attachments{


class Mode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Mode_obj OBJ_;

	public:
		Mode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("spinehaxe.attachments.Mode"); }
		::String __ToString() const { return HX_CSTRING("Mode.") + tag; }

		static ::spinehaxe::attachments::Mode backward;
		static inline ::spinehaxe::attachments::Mode backward_dyn() { return backward; }
		static ::spinehaxe::attachments::Mode backwardLoop;
		static inline ::spinehaxe::attachments::Mode backwardLoop_dyn() { return backwardLoop; }
		static ::spinehaxe::attachments::Mode forward;
		static inline ::spinehaxe::attachments::Mode forward_dyn() { return forward; }
		static ::spinehaxe::attachments::Mode forwardLoop;
		static inline ::spinehaxe::attachments::Mode forwardLoop_dyn() { return forwardLoop; }
		static ::spinehaxe::attachments::Mode pingPong;
		static inline ::spinehaxe::attachments::Mode pingPong_dyn() { return pingPong; }
		static ::spinehaxe::attachments::Mode random;
		static inline ::spinehaxe::attachments::Mode random_dyn() { return random; }
};

} // end namespace spinehaxe
} // end namespace attachments

#endif /* INCLUDED_spinehaxe_attachments_Mode */ 
