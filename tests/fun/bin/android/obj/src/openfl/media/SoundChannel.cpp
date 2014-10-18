#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_SampleDataEvent
#include <openfl/events/SampleDataEvent.h>
#endif
#ifndef INCLUDED_openfl_media_AudioThreadState
#include <openfl/media/AudioThreadState.h>
#endif
#ifndef INCLUDED_openfl_media_InternalAudioType
#include <openfl/media/InternalAudioType.h>
#endif
#ifndef INCLUDED_openfl_media_Sound
#include <openfl/media/Sound.h>
#endif
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl_media_SoundTransform
#include <openfl/media/SoundTransform.h>
#endif
#ifndef INCLUDED_openfl_utils_ByteArray
#include <openfl/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataInput
#include <openfl/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataOutput
#include <openfl/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace openfl{
namespace media{

Void SoundChannel_obj::__construct(Dynamic handle,Float startTime,int loops,::openfl::media::SoundTransform soundTransform)
{
HX_STACK_FRAME("openfl.media.SoundChannel","new",0xfc94e2ae,"openfl.media.SoundChannel.new","openfl/media/SoundChannel.hx",24,0xa4290000)
HX_STACK_THIS(this)
HX_STACK_ARG(handle,"handle")
HX_STACK_ARG(startTime,"startTime")
HX_STACK_ARG(loops,"loops")
HX_STACK_ARG(soundTransform,"soundTransform")
{
	HX_STACK_LINE(49)
	this->__addedToThread = false;
	HX_STACK_LINE(48)
	this->__thread_completed = false;
	HX_STACK_LINE(56)
	super::__construct(null());
	HX_STACK_LINE(58)
	if (((soundTransform != null()))){
		HX_STACK_LINE(60)
		::openfl::media::SoundTransform _g = soundTransform->clone();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		this->__transform = _g;
	}
	HX_STACK_LINE(64)
	if (((handle != null()))){
		HX_STACK_LINE(66)
		Dynamic _g1 = ::openfl::media::SoundChannel_obj::lime_sound_channel_create(handle,startTime,loops,this->__transform);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(66)
		this->__handle = _g1;
	}
	HX_STACK_LINE(70)
	if (((this->__handle != null()))){
		HX_STACK_LINE(72)
		::openfl::media::SoundChannel_obj::__incompleteList->push(hx::ObjectPtr<OBJ_>(this));
	}
}
;
	return null();
}

//SoundChannel_obj::~SoundChannel_obj() { }

Dynamic SoundChannel_obj::__CreateEmpty() { return  new SoundChannel_obj; }
hx::ObjectPtr< SoundChannel_obj > SoundChannel_obj::__new(Dynamic handle,Float startTime,int loops,::openfl::media::SoundTransform soundTransform)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(handle,startTime,loops,soundTransform);
	return result;}

Dynamic SoundChannel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void SoundChannel_obj::stop( ){
{
		HX_STACK_FRAME("openfl.media.SoundChannel","stop",0x090ae1f4,"openfl.media.SoundChannel.stop","openfl/media/SoundChannel.hx",94,0xa4290000)
		HX_STACK_THIS(this)
		HX_STACK_LINE(98)
		if (((bool((this->__soundInstance != null())) && bool((this->__soundInstance->__audioType == ::openfl::media::InternalAudioType_obj::MUSIC))))){
			HX_STACK_LINE(100)
			if (((::openfl::media::SoundChannel_obj::__audioState != null()))){
				HX_STACK_LINE(101)
				::openfl::media::SoundChannel_obj::__audioState->remove(hx::ObjectPtr<OBJ_>(this));
			}
		}
		HX_STACK_LINE(108)
		::openfl::media::SoundChannel_obj::lime_sound_channel_stop(this->__handle);
		HX_STACK_LINE(109)
		this->__handle = null();
		HX_STACK_LINE(110)
		this->__soundInstance = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,stop,(void))

bool SoundChannel_obj::__checkComplete( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","__checkComplete",0x930ee5cf,"openfl.media.SoundChannel.__checkComplete","openfl/media/SoundChannel.hx",116,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(116)
	if (((this->__handle != null()))){
		HX_STACK_LINE(118)
		if (((  (((this->__dataProvider != null()))) ? bool(::openfl::media::SoundChannel_obj::lime_sound_channel_needs_data(this->__handle)) : bool(false) ))){
			HX_STACK_LINE(120)
			::openfl::events::SampleDataEvent request = ::openfl::events::SampleDataEvent_obj::__new(::openfl::events::SampleDataEvent_obj::SAMPLE_DATA,null(),null());		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(121)
			Float _g = ::openfl::media::SoundChannel_obj::lime_sound_channel_get_data_position(this->__handle);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(121)
			request->position = _g;
			HX_STACK_LINE(122)
			this->__dataProvider->dispatchEvent(request);
			HX_STACK_LINE(124)
			if (((request->data->length > (int)0))){
				HX_STACK_LINE(126)
				::openfl::media::SoundChannel_obj::lime_sound_channel_add_data(this->__handle,request->data);
			}
		}
		HX_STACK_LINE(134)
		if (((bool(this->__addedToThread) || bool((bool((this->__soundInstance != null())) && bool((this->__soundInstance->__audioType == ::openfl::media::InternalAudioType_obj::MUSIC))))))){
			HX_STACK_LINE(136)
			if (((::openfl::media::SoundChannel_obj::__audioState == null()))){
				HX_STACK_LINE(138)
				::openfl::media::AudioThreadState _g1 = ::openfl::media::AudioThreadState_obj::__new();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(138)
				::openfl::media::SoundChannel_obj::__audioState = _g1;
				HX_STACK_LINE(140)
				::openfl::media::SoundChannel_obj::__audioThreadRunning = true;
				HX_STACK_LINE(141)
				::openfl::media::SoundChannel_obj::__audioThreadIsIdle = false;
				HX_STACK_LINE(143)
				::cpp::vm::Thread _g2 = ::cpp::vm::Thread_obj::current();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(143)
				::openfl::media::SoundChannel_obj::__audioState->mainThread = _g2;
				HX_STACK_LINE(144)
				::cpp::vm::Thread _g3 = ::cpp::vm::Thread_obj::create(::openfl::media::SoundChannel_obj::__checkCompleteBackgroundThread_dyn());		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(144)
				::openfl::media::SoundChannel_obj::__audioState->audioThread = _g3;
			}
			HX_STACK_LINE(148)
			if ((!(this->__addedToThread))){
				HX_STACK_LINE(150)
				::openfl::media::SoundChannel_obj::__audioState->add(hx::ObjectPtr<OBJ_>(this));
				HX_STACK_LINE(151)
				this->__addedToThread = true;
			}
			HX_STACK_LINE(155)
			return this->__thread_completed;
		}
		else{
			HX_STACK_LINE(161)
			if ((this->__runCheckComplete())){
				HX_STACK_LINE(163)
				return true;
			}
		}
		HX_STACK_LINE(167)
		return false;
	}
	else{
		HX_STACK_LINE(171)
		return true;
	}
	HX_STACK_LINE(116)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,__checkComplete,return )

bool SoundChannel_obj::__runCheckComplete( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","__runCheckComplete",0x94ff1be8,"openfl.media.SoundChannel.__runCheckComplete","openfl/media/SoundChannel.hx",230,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(232)
	if ((::openfl::media::SoundChannel_obj::lime_sound_channel_is_complete(this->__handle))){
		HX_STACK_LINE(234)
		this->__soundInstance = null();
		HX_STACK_LINE(235)
		this->__handle = null();
		HX_STACK_LINE(237)
		if (((this->__dataProvider != null()))){
			HX_STACK_LINE(239)
			(::openfl::media::SoundChannel_obj::__dynamicSoundCount)--;
		}
		HX_STACK_LINE(243)
		::openfl::events::Event completeEvent = ::openfl::events::Event_obj::__new(::openfl::events::Event_obj::SOUND_COMPLETE,null(),null());		HX_STACK_VAR(completeEvent,"completeEvent");
		HX_STACK_LINE(244)
		this->dispatchEvent(completeEvent);
		HX_STACK_LINE(246)
		return true;
	}
	HX_STACK_LINE(250)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,__runCheckComplete,return )

Float SoundChannel_obj::get_leftPeak( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","get_leftPeak",0xcd2709c1,"openfl.media.SoundChannel.get_leftPeak","openfl/media/SoundChannel.hx",262,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(262)
	return ::openfl::media::SoundChannel_obj::lime_sound_channel_get_left(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,get_leftPeak,return )

Float SoundChannel_obj::get_rightPeak( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","get_rightPeak",0x954f47c0,"openfl.media.SoundChannel.get_rightPeak","openfl/media/SoundChannel.hx",263,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(263)
	return ::openfl::media::SoundChannel_obj::lime_sound_channel_get_right(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,get_rightPeak,return )

Float SoundChannel_obj::get_position( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","get_position",0x46d188a4,"openfl.media.SoundChannel.get_position","openfl/media/SoundChannel.hx",264,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(264)
	return ::openfl::media::SoundChannel_obj::lime_sound_channel_get_position(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,get_position,return )

Float SoundChannel_obj::set_position( Float value){
	HX_STACK_FRAME("openfl.media.SoundChannel","set_position",0x5bcaac18,"openfl.media.SoundChannel.set_position","openfl/media/SoundChannel.hx",265,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(265)
	Float _g = this->get_position();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(265)
	return ::openfl::media::SoundChannel_obj::lime_sound_channel_set_position(this->__handle,_g);
}


HX_DEFINE_DYNAMIC_FUNC1(SoundChannel_obj,set_position,return )

::openfl::media::SoundTransform SoundChannel_obj::get_soundTransform( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","get_soundTransform",0xc6e884d8,"openfl.media.SoundChannel.get_soundTransform","openfl/media/SoundChannel.hx",268,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_LINE(270)
	if (((this->__transform == null()))){
		HX_STACK_LINE(272)
		::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(272)
		this->__transform = _g;
	}
	HX_STACK_LINE(276)
	return this->__transform->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,get_soundTransform,return )

::openfl::media::SoundTransform SoundChannel_obj::set_soundTransform( ::openfl::media::SoundTransform value){
	HX_STACK_FRAME("openfl.media.SoundChannel","set_soundTransform",0xa397b74c,"openfl.media.SoundChannel.set_soundTransform","openfl/media/SoundChannel.hx",281,0xa4290000)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(283)
	::openfl::media::SoundTransform _g = value->clone();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(283)
	this->__transform = _g;
	HX_STACK_LINE(284)
	::openfl::media::SoundChannel_obj::lime_sound_channel_set_transform(this->__handle,this->__transform);
	HX_STACK_LINE(286)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(SoundChannel_obj,set_soundTransform,return )

int SoundChannel_obj::__dynamicSoundCount;

Array< ::Dynamic > SoundChannel_obj::__incompleteList;

::openfl::media::AudioThreadState SoundChannel_obj::__audioState;

bool SoundChannel_obj::__audioThreadIsIdle;

bool SoundChannel_obj::__audioThreadRunning;

::openfl::media::SoundChannel SoundChannel_obj::createDynamic( Dynamic handle,::openfl::media::SoundTransform soundTransform,::openfl::events::EventDispatcher dataProvider){
	HX_STACK_FRAME("openfl.media.SoundChannel","createDynamic",0x3d28b7b1,"openfl.media.SoundChannel.createDynamic","openfl/media/SoundChannel.hx",79,0xa4290000)
	HX_STACK_ARG(handle,"handle")
	HX_STACK_ARG(soundTransform,"soundTransform")
	HX_STACK_ARG(dataProvider,"dataProvider")
	HX_STACK_LINE(81)
	::openfl::media::SoundChannel result = ::openfl::media::SoundChannel_obj::__new(null(),(int)0,(int)0,soundTransform);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(83)
	result->__dataProvider = dataProvider;
	HX_STACK_LINE(84)
	result->__handle = handle;
	HX_STACK_LINE(85)
	::openfl::media::SoundChannel_obj::__incompleteList->push(result);
	HX_STACK_LINE(87)
	(::openfl::media::SoundChannel_obj::__dynamicSoundCount)++;
	HX_STACK_LINE(89)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(SoundChannel_obj,createDynamic,return )

Void SoundChannel_obj::__checkCompleteBackgroundThread( ){
{
		HX_STACK_FRAME("openfl.media.SoundChannel","__checkCompleteBackgroundThread",0x805ab947,"openfl.media.SoundChannel.__checkCompleteBackgroundThread","openfl/media/SoundChannel.hx",180,0xa4290000)
		HX_STACK_LINE(182)
		while((true)){
			HX_STACK_LINE(182)
			if ((!(::openfl::media::SoundChannel_obj::__audioThreadRunning))){
				HX_STACK_LINE(182)
				break;
			}
			HX_STACK_LINE(184)
			if ((!(::openfl::media::SoundChannel_obj::__audioThreadIsIdle))){
				HX_STACK_LINE(186)
				::openfl::media::SoundChannel_obj::__audioState->updateComplete();
				HX_STACK_LINE(188)
				::Sys_obj::sleep(0.01);
			}
			else{
				HX_STACK_LINE(192)
				::Sys_obj::sleep(0.2);
			}
		}
		HX_STACK_LINE(198)
		::openfl::media::SoundChannel_obj::__audioThreadRunning = false;
		HX_STACK_LINE(199)
		::openfl::media::SoundChannel_obj::__audioThreadIsIdle = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,__checkCompleteBackgroundThread,(void))

bool SoundChannel_obj::__completePending( ){
	HX_STACK_FRAME("openfl.media.SoundChannel","__completePending",0xfd2ba84c,"openfl.media.SoundChannel.__completePending","openfl/media/SoundChannel.hx",208,0xa4290000)
	HX_STACK_LINE(208)
	return (::openfl::media::SoundChannel_obj::__incompleteList->length > (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,__completePending,return )

Void SoundChannel_obj::__pollComplete( ){
{
		HX_STACK_FRAME("openfl.media.SoundChannel","__pollComplete",0x131529aa,"openfl.media.SoundChannel.__pollComplete","openfl/media/SoundChannel.hx",213,0xa4290000)
		HX_STACK_LINE(215)
		int i = ::openfl::media::SoundChannel_obj::__incompleteList->length;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(217)
		while((true)){
			HX_STACK_LINE(217)
			int _g = --(i);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(217)
			if ((!(((_g >= (int)0))))){
				HX_STACK_LINE(217)
				break;
			}
			HX_STACK_LINE(219)
			if ((::openfl::media::SoundChannel_obj::__incompleteList->__get(i).StaticCast< ::openfl::media::SoundChannel >()->__checkComplete())){
				HX_STACK_LINE(221)
				::openfl::media::SoundChannel_obj::__incompleteList->splice(i,(int)1);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,__pollComplete,(void))

Dynamic SoundChannel_obj::lime_sound_channel_is_complete;

Dynamic SoundChannel_obj::lime_sound_channel_get_left;

Dynamic SoundChannel_obj::lime_sound_channel_get_right;

Dynamic SoundChannel_obj::lime_sound_channel_get_position;

Dynamic SoundChannel_obj::lime_sound_channel_set_position;

Dynamic SoundChannel_obj::lime_sound_channel_get_data_position;

Dynamic SoundChannel_obj::lime_sound_channel_stop;

Dynamic SoundChannel_obj::lime_sound_channel_create;

Dynamic SoundChannel_obj::lime_sound_channel_set_transform;

Dynamic SoundChannel_obj::lime_sound_channel_needs_data;

Dynamic SoundChannel_obj::lime_sound_channel_add_data;


SoundChannel_obj::SoundChannel_obj()
{
}

void SoundChannel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundChannel);
	HX_MARK_MEMBER_NAME(leftPeak,"leftPeak");
	HX_MARK_MEMBER_NAME(rightPeak,"rightPeak");
	HX_MARK_MEMBER_NAME(__dataProvider,"__dataProvider");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(__soundInstance,"__soundInstance");
	HX_MARK_MEMBER_NAME(__transform,"__transform");
	HX_MARK_MEMBER_NAME(__thread_completed,"__thread_completed");
	HX_MARK_MEMBER_NAME(__addedToThread,"__addedToThread");
	::openfl::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SoundChannel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(leftPeak,"leftPeak");
	HX_VISIT_MEMBER_NAME(rightPeak,"rightPeak");
	HX_VISIT_MEMBER_NAME(__dataProvider,"__dataProvider");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(__soundInstance,"__soundInstance");
	HX_VISIT_MEMBER_NAME(__transform,"__transform");
	HX_VISIT_MEMBER_NAME(__thread_completed,"__thread_completed");
	HX_VISIT_MEMBER_NAME(__addedToThread,"__addedToThread");
	::openfl::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SoundChannel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftPeak") ) { return inCallProp ? get_leftPeak() : leftPeak; }
		if (HX_FIELD_EQ(inName,"position") ) { return get_position(); }
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightPeak") ) { return inCallProp ? get_rightPeak() : rightPeak; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__transform") ) { return __transform; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__audioState") ) { return __audioState; }
		if (HX_FIELD_EQ(inName,"get_leftPeak") ) { return get_leftPeak_dyn(); }
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return set_position_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createDynamic") ) { return createDynamic_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rightPeak") ) { return get_rightPeak_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__pollComplete") ) { return __pollComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"soundTransform") ) { return get_soundTransform(); }
		if (HX_FIELD_EQ(inName,"__dataProvider") ) { return __dataProvider; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__soundInstance") ) { return __soundInstance; }
		if (HX_FIELD_EQ(inName,"__addedToThread") ) { return __addedToThread; }
		if (HX_FIELD_EQ(inName,"__checkComplete") ) { return __checkComplete_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__incompleteList") ) { return __incompleteList; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__completePending") ) { return __completePending_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"__thread_completed") ) { return __thread_completed; }
		if (HX_FIELD_EQ(inName,"__runCheckComplete") ) { return __runCheckComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"get_soundTransform") ) { return get_soundTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_soundTransform") ) { return set_soundTransform_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"__dynamicSoundCount") ) { return __dynamicSoundCount; }
		if (HX_FIELD_EQ(inName,"__audioThreadIsIdle") ) { return __audioThreadIsIdle; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"__audioThreadRunning") ) { return __audioThreadRunning; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_stop") ) { return lime_sound_channel_stop; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_create") ) { return lime_sound_channel_create; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_left") ) { return lime_sound_channel_get_left; }
		if (HX_FIELD_EQ(inName,"lime_sound_channel_add_data") ) { return lime_sound_channel_add_data; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_right") ) { return lime_sound_channel_get_right; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_needs_data") ) { return lime_sound_channel_needs_data; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_is_complete") ) { return lime_sound_channel_is_complete; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"__checkCompleteBackgroundThread") ) { return __checkCompleteBackgroundThread_dyn(); }
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_position") ) { return lime_sound_channel_get_position; }
		if (HX_FIELD_EQ(inName,"lime_sound_channel_set_position") ) { return lime_sound_channel_set_position; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_set_transform") ) { return lime_sound_channel_set_transform; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_data_position") ) { return lime_sound_channel_get_data_position; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundChannel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"leftPeak") ) { leftPeak=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { return set_position(inValue); }
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightPeak") ) { rightPeak=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__transform") ) { __transform=inValue.Cast< ::openfl::media::SoundTransform >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__audioState") ) { __audioState=inValue.Cast< ::openfl::media::AudioThreadState >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"soundTransform") ) { return set_soundTransform(inValue); }
		if (HX_FIELD_EQ(inName,"__dataProvider") ) { __dataProvider=inValue.Cast< ::openfl::events::EventDispatcher >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__soundInstance") ) { __soundInstance=inValue.Cast< ::openfl::media::Sound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__addedToThread") ) { __addedToThread=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__incompleteList") ) { __incompleteList=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"__thread_completed") ) { __thread_completed=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"__dynamicSoundCount") ) { __dynamicSoundCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__audioThreadIsIdle") ) { __audioThreadIsIdle=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"__audioThreadRunning") ) { __audioThreadRunning=inValue.Cast< bool >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_stop") ) { lime_sound_channel_stop=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_create") ) { lime_sound_channel_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_left") ) { lime_sound_channel_get_left=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_sound_channel_add_data") ) { lime_sound_channel_add_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_right") ) { lime_sound_channel_get_right=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_needs_data") ) { lime_sound_channel_needs_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_is_complete") ) { lime_sound_channel_is_complete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_position") ) { lime_sound_channel_get_position=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_sound_channel_set_position") ) { lime_sound_channel_set_position=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_set_transform") ) { lime_sound_channel_set_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_get_data_position") ) { lime_sound_channel_get_data_position=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundChannel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("leftPeak"));
	outFields->push(HX_CSTRING("rightPeak"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("soundTransform"));
	outFields->push(HX_CSTRING("__dataProvider"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("__soundInstance"));
	outFields->push(HX_CSTRING("__transform"));
	outFields->push(HX_CSTRING("__thread_completed"));
	outFields->push(HX_CSTRING("__addedToThread"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__dynamicSoundCount"),
	HX_CSTRING("__incompleteList"),
	HX_CSTRING("__audioState"),
	HX_CSTRING("__audioThreadIsIdle"),
	HX_CSTRING("__audioThreadRunning"),
	HX_CSTRING("createDynamic"),
	HX_CSTRING("__checkCompleteBackgroundThread"),
	HX_CSTRING("__completePending"),
	HX_CSTRING("__pollComplete"),
	HX_CSTRING("lime_sound_channel_is_complete"),
	HX_CSTRING("lime_sound_channel_get_left"),
	HX_CSTRING("lime_sound_channel_get_right"),
	HX_CSTRING("lime_sound_channel_get_position"),
	HX_CSTRING("lime_sound_channel_set_position"),
	HX_CSTRING("lime_sound_channel_get_data_position"),
	HX_CSTRING("lime_sound_channel_stop"),
	HX_CSTRING("lime_sound_channel_create"),
	HX_CSTRING("lime_sound_channel_set_transform"),
	HX_CSTRING("lime_sound_channel_needs_data"),
	HX_CSTRING("lime_sound_channel_add_data"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(SoundChannel_obj,leftPeak),HX_CSTRING("leftPeak")},
	{hx::fsFloat,(int)offsetof(SoundChannel_obj,rightPeak),HX_CSTRING("rightPeak")},
	{hx::fsObject /*::openfl::events::EventDispatcher*/ ,(int)offsetof(SoundChannel_obj,__dataProvider),HX_CSTRING("__dataProvider")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SoundChannel_obj,__handle),HX_CSTRING("__handle")},
	{hx::fsObject /*::openfl::media::Sound*/ ,(int)offsetof(SoundChannel_obj,__soundInstance),HX_CSTRING("__soundInstance")},
	{hx::fsObject /*::openfl::media::SoundTransform*/ ,(int)offsetof(SoundChannel_obj,__transform),HX_CSTRING("__transform")},
	{hx::fsBool,(int)offsetof(SoundChannel_obj,__thread_completed),HX_CSTRING("__thread_completed")},
	{hx::fsBool,(int)offsetof(SoundChannel_obj,__addedToThread),HX_CSTRING("__addedToThread")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("leftPeak"),
	HX_CSTRING("rightPeak"),
	HX_CSTRING("__dataProvider"),
	HX_CSTRING("__handle"),
	HX_CSTRING("__soundInstance"),
	HX_CSTRING("__transform"),
	HX_CSTRING("__thread_completed"),
	HX_CSTRING("__addedToThread"),
	HX_CSTRING("stop"),
	HX_CSTRING("__checkComplete"),
	HX_CSTRING("__runCheckComplete"),
	HX_CSTRING("get_leftPeak"),
	HX_CSTRING("get_rightPeak"),
	HX_CSTRING("get_position"),
	HX_CSTRING("set_position"),
	HX_CSTRING("get_soundTransform"),
	HX_CSTRING("set_soundTransform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__dynamicSoundCount,"__dynamicSoundCount");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__incompleteList,"__incompleteList");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__audioState,"__audioState");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__audioThreadIsIdle,"__audioThreadIsIdle");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__audioThreadRunning,"__audioThreadRunning");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_is_complete,"lime_sound_channel_is_complete");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_left,"lime_sound_channel_get_left");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_right,"lime_sound_channel_get_right");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_position,"lime_sound_channel_get_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_set_position,"lime_sound_channel_set_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_data_position,"lime_sound_channel_get_data_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_stop,"lime_sound_channel_stop");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_create,"lime_sound_channel_create");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_set_transform,"lime_sound_channel_set_transform");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_needs_data,"lime_sound_channel_needs_data");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_add_data,"lime_sound_channel_add_data");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__dynamicSoundCount,"__dynamicSoundCount");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__incompleteList,"__incompleteList");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__audioState,"__audioState");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__audioThreadIsIdle,"__audioThreadIsIdle");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__audioThreadRunning,"__audioThreadRunning");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_is_complete,"lime_sound_channel_is_complete");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_left,"lime_sound_channel_get_left");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_right,"lime_sound_channel_get_right");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_position,"lime_sound_channel_get_position");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_set_position,"lime_sound_channel_set_position");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_get_data_position,"lime_sound_channel_get_data_position");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_stop,"lime_sound_channel_stop");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_create,"lime_sound_channel_create");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_set_transform,"lime_sound_channel_set_transform");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_needs_data,"lime_sound_channel_needs_data");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::lime_sound_channel_add_data,"lime_sound_channel_add_data");
};

#endif

Class SoundChannel_obj::__mClass;

void SoundChannel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.media.SoundChannel"), hx::TCanCast< SoundChannel_obj> ,sStaticFields,sMemberFields,
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

void SoundChannel_obj::__boot()
{
	__dynamicSoundCount= (int)0;
	__incompleteList= Array_obj< ::Dynamic >::__new();
	__audioThreadIsIdle= true;
	__audioThreadRunning= false;
	lime_sound_channel_is_complete= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_is_complete"),(int)1);
	lime_sound_channel_get_left= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_get_left"),(int)1);
	lime_sound_channel_get_right= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_get_right"),(int)1);
	lime_sound_channel_get_position= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_get_position"),(int)1);
	lime_sound_channel_set_position= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_set_position"),(int)2);
	lime_sound_channel_get_data_position= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_get_data_position"),(int)1);
	lime_sound_channel_stop= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_stop"),(int)1);
	lime_sound_channel_create= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_create"),(int)4);
	lime_sound_channel_set_transform= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_set_transform"),(int)2);
	lime_sound_channel_needs_data= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_needs_data"),(int)1);
	lime_sound_channel_add_data= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_add_data"),(int)2);
}

} // end namespace openfl
} // end namespace media
