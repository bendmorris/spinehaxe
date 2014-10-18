#ifndef INCLUDED_spinehaxe_animation_Timeline
#define INCLUDED_spinehaxe_animation_Timeline

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(spinehaxe,Event)
HX_DECLARE_CLASS1(spinehaxe,Skeleton)
HX_DECLARE_CLASS2(spinehaxe,animation,Timeline)
namespace spinehaxe{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  Timeline_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Timeline_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha)=0;
		Dynamic apply_dyn();
};

#define DELEGATE_spinehaxe_animation_Timeline \
virtual Void apply( ::spinehaxe::Skeleton skeleton,Float lastTime,Float time,Array< ::Dynamic > firedEvents,Float alpha) { return mDelegate->apply(skeleton,lastTime,time,firedEvents,alpha);}  \
virtual Dynamic apply_dyn() { return mDelegate->apply_dyn();}  \


template<typename IMPL>
class Timeline_delegate_ : public Timeline_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Timeline_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_spinehaxe_animation_Timeline
};

} // end namespace spinehaxe
} // end namespace animation

#endif /* INCLUDED_spinehaxe_animation_Timeline */ 
