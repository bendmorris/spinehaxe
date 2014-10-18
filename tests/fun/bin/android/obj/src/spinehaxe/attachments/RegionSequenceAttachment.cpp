#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Mode
#include <spinehaxe/attachments/Mode.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#include <spinehaxe/attachments/RegionAttachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionSequenceAttachment
#include <spinehaxe/attachments/RegionSequenceAttachment.h>
#endif
namespace spinehaxe{
namespace attachments{

Void RegionSequenceAttachment_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","new",0x0904fbad,"spinehaxe.attachments.RegionSequenceAttachment.new","spinehaxe/attachments/RegionSequenceAttachment.hx",35,0xd9590221)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(35)
	super::__construct(name);
}
;
	return null();
}

//RegionSequenceAttachment_obj::~RegionSequenceAttachment_obj() { }

Dynamic RegionSequenceAttachment_obj::__CreateEmpty() { return  new RegionSequenceAttachment_obj; }
hx::ObjectPtr< RegionSequenceAttachment_obj > RegionSequenceAttachment_obj::__new(::String name)
{  hx::ObjectPtr< RegionSequenceAttachment_obj > result = new RegionSequenceAttachment_obj();
	result->__construct(name);
	return result;}

Dynamic RegionSequenceAttachment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RegionSequenceAttachment_obj > result = new RegionSequenceAttachment_obj();
	result->__construct(inArgs[0]);
	return result;}

Void RegionSequenceAttachment_obj::updateVertices( ::spinehaxe::Slot slot){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","updateVertices",0x502c60f5,"spinehaxe.attachments.RegionSequenceAttachment.updateVertices","spinehaxe/attachments/RegionSequenceAttachment.hx",38,0xd9590221)
		HX_STACK_THIS(this)
		HX_STACK_ARG(slot,"slot")
		HX_STACK_LINE(39)
		if (((this->regions == null()))){
			HX_STACK_LINE(39)
			::String _g = ::Std_obj::string(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(39)
			::String _g1 = (HX_CSTRING("Regions have not been set: ") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(39)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(_g1));
		}
		HX_STACK_LINE(41)
		Float _g2 = slot->get_attachmentTime();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(41)
		Float _g3 = (Float(_g2) / Float(this->frameTime));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(41)
		int frameIndex = ::Math_obj::floor(_g3);		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			::spinehaxe::attachments::Mode _g = this->mode;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(44)
					int a = (this->regions->length - (int)1);		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(44)
					if (((a < frameIndex))){
						HX_STACK_LINE(44)
						frameIndex = a;
					}
					else{
						HX_STACK_LINE(44)
						frameIndex = frameIndex;
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(46)
					frameIndex = hx::Mod(frameIndex,this->regions->length);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(48)
					frameIndex = hx::Mod(frameIndex,((this->regions->length * (int)2)));
					HX_STACK_LINE(49)
					if (((frameIndex >= this->regions->length))){
						HX_STACK_LINE(49)
						frameIndex = ((this->regions->length - (int)1) - ((frameIndex - this->regions->length)));
					}
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(51)
					Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(51)
					Float _g5 = (((this->regions->length - (int)1)) * _g4);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(51)
					int _g6 = ::Math_obj::round(_g5);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(51)
					frameIndex = _g6;
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(53)
					int a = ((this->regions->length - frameIndex) - (int)1);		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(53)
					if (((a > (int)0))){
						HX_STACK_LINE(53)
						frameIndex = a;
					}
					else{
						HX_STACK_LINE(53)
						frameIndex = (int)0;
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(55)
					frameIndex = hx::Mod(frameIndex,this->regions->length);
					HX_STACK_LINE(56)
					frameIndex = ((this->regions->length - frameIndex) - (int)1);
				}
				;break;
			}
		}
		HX_STACK_LINE(58)
		this->setRegion(this->regions->__get(frameIndex).StaticCast< ::spinehaxe::atlas::TextureRegion >());
		HX_STACK_LINE(60)
		this->super::updateVertices(slot);
	}
return null();
}


Array< ::Dynamic > RegionSequenceAttachment_obj::getRegions( ){
	HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","getRegions",0x56c4235c,"spinehaxe.attachments.RegionSequenceAttachment.getRegions","spinehaxe/attachments/RegionSequenceAttachment.hx",63,0xd9590221)
	HX_STACK_THIS(this)
	HX_STACK_LINE(64)
	if (((this->regions == null()))){
		HX_STACK_LINE(64)
		::String _g = ::Std_obj::string(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		::String _g1 = (HX_CSTRING("Regions have not been set: ") + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(64)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(_g1));
	}
	HX_STACK_LINE(65)
	return this->regions;
}


HX_DEFINE_DYNAMIC_FUNC0(RegionSequenceAttachment_obj,getRegions,return )

Void RegionSequenceAttachment_obj::setRegions( Array< ::Dynamic > regions){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","setRegions",0x5a41c1d0,"spinehaxe.attachments.RegionSequenceAttachment.setRegions","spinehaxe/attachments/RegionSequenceAttachment.hx",69,0xd9590221)
		HX_STACK_THIS(this)
		HX_STACK_ARG(regions,"regions")
		HX_STACK_LINE(69)
		this->regions = regions;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RegionSequenceAttachment_obj,setRegions,(void))

Void RegionSequenceAttachment_obj::setFrameTime( Float frameTime){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","setFrameTime",0x9084cdeb,"spinehaxe.attachments.RegionSequenceAttachment.setFrameTime","spinehaxe/attachments/RegionSequenceAttachment.hx",74,0xd9590221)
		HX_STACK_THIS(this)
		HX_STACK_ARG(frameTime,"frameTime")
		HX_STACK_LINE(74)
		this->frameTime = frameTime;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RegionSequenceAttachment_obj,setFrameTime,(void))

Void RegionSequenceAttachment_obj::setMode( ::spinehaxe::attachments::Mode mode){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionSequenceAttachment","setMode",0x53e269f2,"spinehaxe.attachments.RegionSequenceAttachment.setMode","spinehaxe/attachments/RegionSequenceAttachment.hx",78,0xd9590221)
		HX_STACK_THIS(this)
		HX_STACK_ARG(mode,"mode")
		HX_STACK_LINE(78)
		this->mode = mode;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RegionSequenceAttachment_obj,setMode,(void))


RegionSequenceAttachment_obj::RegionSequenceAttachment_obj()
{
}

void RegionSequenceAttachment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RegionSequenceAttachment);
	HX_MARK_MEMBER_NAME(mode,"mode");
	HX_MARK_MEMBER_NAME(frameTime,"frameTime");
	HX_MARK_MEMBER_NAME(regions,"regions");
	::spinehaxe::attachments::RegionAttachment_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RegionSequenceAttachment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mode,"mode");
	HX_VISIT_MEMBER_NAME(frameTime,"frameTime");
	HX_VISIT_MEMBER_NAME(regions,"regions");
	::spinehaxe::attachments::RegionAttachment_obj::__Visit(HX_VISIT_ARG);
}

Dynamic RegionSequenceAttachment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { return regions; }
		if (HX_FIELD_EQ(inName,"setMode") ) { return setMode_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameTime") ) { return frameTime; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getRegions") ) { return getRegions_dyn(); }
		if (HX_FIELD_EQ(inName,"setRegions") ) { return setRegions_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setFrameTime") ) { return setFrameTime_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateVertices") ) { return updateVertices_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RegionSequenceAttachment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { mode=inValue.Cast< ::spinehaxe::attachments::Mode >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { regions=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameTime") ) { frameTime=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RegionSequenceAttachment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mode"));
	outFields->push(HX_CSTRING("frameTime"));
	outFields->push(HX_CSTRING("regions"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::attachments::Mode*/ ,(int)offsetof(RegionSequenceAttachment_obj,mode),HX_CSTRING("mode")},
	{hx::fsFloat,(int)offsetof(RegionSequenceAttachment_obj,frameTime),HX_CSTRING("frameTime")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(RegionSequenceAttachment_obj,regions),HX_CSTRING("regions")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mode"),
	HX_CSTRING("frameTime"),
	HX_CSTRING("regions"),
	HX_CSTRING("updateVertices"),
	HX_CSTRING("getRegions"),
	HX_CSTRING("setRegions"),
	HX_CSTRING("setFrameTime"),
	HX_CSTRING("setMode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RegionSequenceAttachment_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RegionSequenceAttachment_obj::__mClass,"__mClass");
};

#endif

Class RegionSequenceAttachment_obj::__mClass;

void RegionSequenceAttachment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.RegionSequenceAttachment"), hx::TCanCast< RegionSequenceAttachment_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void RegionSequenceAttachment_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace attachments
