#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_cpp_vm_Mutex
#include <cpp/vm/Mutex.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_AudioThreadState
#include <openfl/media/AudioThreadState.h>
#endif
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
namespace openfl{
namespace media{

Void AudioThreadState_obj::__construct()
{
HX_STACK_FRAME("openfl.media.AudioThreadState","new",0xe1fb372b,"openfl.media.AudioThreadState.new","openfl/media/SoundChannel.hx",325,0xa4290000)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(327)
	::cpp::vm::Mutex _g = ::cpp::vm::Mutex_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(327)
	this->mutex = _g;
	HX_STACK_LINE(328)
	this->channelList = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//AudioThreadState_obj::~AudioThreadState_obj() { }

Dynamic AudioThreadState_obj::__CreateEmpty() { return  new AudioThreadState_obj; }
hx::ObjectPtr< AudioThreadState_obj > AudioThreadState_obj::__new()
{  hx::ObjectPtr< AudioThreadState_obj > result = new AudioThreadState_obj();
	result->__construct();
	return result;}

Dynamic AudioThreadState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AudioThreadState_obj > result = new AudioThreadState_obj();
	result->__construct();
	return result;}

Void AudioThreadState_obj::add( ::openfl::media::SoundChannel channel){
{
		HX_STACK_FRAME("openfl.media.AudioThreadState","add",0xe1f158ec,"openfl.media.AudioThreadState.add","openfl/media/SoundChannel.hx",335,0xa4290000)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_LINE(335)
		if ((!(::Lambda_obj::has(this->channelList,channel)))){
			HX_STACK_LINE(337)
			this->channelList->push(channel);
			HX_STACK_LINE(338)
			::openfl::media::SoundChannel_obj::__audioThreadIsIdle = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AudioThreadState_obj,add,(void))

Void AudioThreadState_obj::remove( ::openfl::media::SoundChannel channel){
{
		HX_STACK_FRAME("openfl.media.AudioThreadState","remove",0x57334659,"openfl.media.AudioThreadState.remove","openfl/media/SoundChannel.hx",345,0xa4290000)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_LINE(347)
		this->mutex->acquire();
		HX_STACK_LINE(349)
		if ((::Lambda_obj::has(this->channelList,channel))){
			HX_STACK_LINE(352)
			channel->__addedToThread = false;
			HX_STACK_LINE(355)
			channel->__thread_completed = true;
			HX_STACK_LINE(358)
			this->channelList->remove(channel);
			HX_STACK_LINE(361)
			if (((this->channelList->length == (int)0))){
				HX_STACK_LINE(363)
				::openfl::media::SoundChannel_obj::__audioThreadIsIdle = true;
			}
		}
		HX_STACK_LINE(369)
		this->mutex->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AudioThreadState_obj,remove,(void))

Void AudioThreadState_obj::updateComplete( ){
{
		HX_STACK_FRAME("openfl.media.AudioThreadState","updateComplete",0x5f243af7,"openfl.media.AudioThreadState.updateComplete","openfl/media/SoundChannel.hx",374,0xa4290000)
		HX_STACK_THIS(this)
		HX_STACK_LINE(376)
		this->mutex->acquire();
		HX_STACK_LINE(378)
		{
			HX_STACK_LINE(378)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(378)
			Array< ::Dynamic > _g1 = this->channelList;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(378)
			while((true)){
				HX_STACK_LINE(378)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(378)
					break;
				}
				HX_STACK_LINE(378)
				::openfl::media::SoundChannel channel = _g1->__get(_g).StaticCast< ::openfl::media::SoundChannel >();		HX_STACK_VAR(channel,"channel");
				HX_STACK_LINE(378)
				++(_g);
				HX_STACK_LINE(380)
				if (((channel != null()))){
					HX_STACK_LINE(382)
					if ((channel->__runCheckComplete())){
						HX_STACK_LINE(383)
						this->remove(channel);
					}
				}
				else{
					HX_STACK_LINE(388)
					this->channelList->remove(channel);
				}
			}
		}
		HX_STACK_LINE(394)
		this->mutex->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AudioThreadState_obj,updateComplete,(void))


AudioThreadState_obj::AudioThreadState_obj()
{
}

void AudioThreadState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AudioThreadState);
	HX_MARK_MEMBER_NAME(audioThread,"audioThread");
	HX_MARK_MEMBER_NAME(channelList,"channelList");
	HX_MARK_MEMBER_NAME(mainThread,"mainThread");
	HX_MARK_MEMBER_NAME(mutex,"mutex");
	HX_MARK_END_CLASS();
}

void AudioThreadState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(audioThread,"audioThread");
	HX_VISIT_MEMBER_NAME(channelList,"channelList");
	HX_VISIT_MEMBER_NAME(mainThread,"mainThread");
	HX_VISIT_MEMBER_NAME(mutex,"mutex");
}

Dynamic AudioThreadState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { return mutex; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mainThread") ) { return mainThread; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"audioThread") ) { return audioThread; }
		if (HX_FIELD_EQ(inName,"channelList") ) { return channelList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateComplete") ) { return updateComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AudioThreadState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { mutex=inValue.Cast< ::cpp::vm::Mutex >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mainThread") ) { mainThread=inValue.Cast< ::cpp::vm::Thread >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"audioThread") ) { audioThread=inValue.Cast< ::cpp::vm::Thread >(); return inValue; }
		if (HX_FIELD_EQ(inName,"channelList") ) { channelList=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AudioThreadState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("audioThread"));
	outFields->push(HX_CSTRING("channelList"));
	outFields->push(HX_CSTRING("mainThread"));
	outFields->push(HX_CSTRING("mutex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::cpp::vm::Thread*/ ,(int)offsetof(AudioThreadState_obj,audioThread),HX_CSTRING("audioThread")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AudioThreadState_obj,channelList),HX_CSTRING("channelList")},
	{hx::fsObject /*::cpp::vm::Thread*/ ,(int)offsetof(AudioThreadState_obj,mainThread),HX_CSTRING("mainThread")},
	{hx::fsObject /*::cpp::vm::Mutex*/ ,(int)offsetof(AudioThreadState_obj,mutex),HX_CSTRING("mutex")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("audioThread"),
	HX_CSTRING("channelList"),
	HX_CSTRING("mainThread"),
	HX_CSTRING("mutex"),
	HX_CSTRING("add"),
	HX_CSTRING("remove"),
	HX_CSTRING("updateComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AudioThreadState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AudioThreadState_obj::__mClass,"__mClass");
};

#endif

Class AudioThreadState_obj::__mClass;

void AudioThreadState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.media.AudioThreadState"), hx::TCanCast< AudioThreadState_obj> ,sStaticFields,sMemberFields,
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

void AudioThreadState_obj::__boot()
{
}

} // end namespace openfl
} // end namespace media
