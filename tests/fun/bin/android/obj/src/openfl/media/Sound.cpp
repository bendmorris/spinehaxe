#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif
#ifndef INCLUDED_openfl_events_ErrorEvent
#include <openfl/events/ErrorEvent.h>
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
#ifndef INCLUDED_openfl_events_IOErrorEvent
#include <openfl/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_openfl_events_SampleDataEvent
#include <openfl/events/SampleDataEvent.h>
#endif
#ifndef INCLUDED_openfl_events_TextEvent
#include <openfl/events/TextEvent.h>
#endif
#ifndef INCLUDED_openfl_media_ID3Info
#include <openfl/media/ID3Info.h>
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
#ifndef INCLUDED_openfl_media_SoundLoaderContext
#include <openfl/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_openfl_media_SoundTransform
#include <openfl/media/SoundTransform.h>
#endif
#ifndef INCLUDED_openfl_net_URLRequest
#include <openfl/net/URLRequest.h>
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

Void Sound_obj::__construct(::openfl::net::URLRequest stream,::openfl::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic)
{
HX_STACK_FRAME("openfl.media.Sound","new",0xfdfd1c39,"openfl.media.Sound.new","openfl/media/Sound.hx",33,0x46a01619)
HX_STACK_THIS(this)
HX_STACK_ARG(stream,"stream")
HX_STACK_ARG(context,"context")
HX_STACK_ARG(__o_forcePlayAsMusic,"forcePlayAsMusic")
bool forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
{
	HX_STACK_LINE(35)
	super::__construct(null());
	HX_STACK_LINE(37)
	if ((forcePlayAsMusic)){
		HX_STACK_LINE(37)
		this->__audioType = ::openfl::media::InternalAudioType_obj::MUSIC;
	}
	else{
		HX_STACK_LINE(37)
		this->__audioType = ::openfl::media::InternalAudioType_obj::SOUND;
	}
	HX_STACK_LINE(39)
	this->bytesLoaded = (int)0;
	HX_STACK_LINE(40)
	this->bytesTotal = (int)0;
	HX_STACK_LINE(41)
	this->__loading = false;
	HX_STACK_LINE(42)
	this->__dynamicSound = false;
	HX_STACK_LINE(44)
	if (((stream != null()))){
		HX_STACK_LINE(46)
		this->load(stream,context,forcePlayAsMusic);
	}
}
;
	return null();
}

//Sound_obj::~Sound_obj() { }

Dynamic Sound_obj::__CreateEmpty() { return  new Sound_obj; }
hx::ObjectPtr< Sound_obj > Sound_obj::__new(::openfl::net::URLRequest stream,::openfl::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(stream,context,__o_forcePlayAsMusic);
	return result;}

Dynamic Sound_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Sound_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture,hx::Null< int >  __o_priority,hx::Null< bool >  __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_STACK_FRAME("openfl.media.Sound","addEventListener",0xaa738c54,"openfl.media.Sound.addEventListener","openfl/media/Sound.hx",53,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(useCapture,"useCapture")
	HX_STACK_ARG(priority,"priority")
	HX_STACK_ARG(useWeakReference,"useWeakReference")
{
		HX_STACK_LINE(55)
		this->super::addEventListener(type,listener,useCapture,priority,useWeakReference);
		HX_STACK_LINE(57)
		if (((type == ::openfl::events::SampleDataEvent_obj::SAMPLE_DATA))){
			HX_STACK_LINE(59)
			if (((this->__handle != null()))){
				HX_STACK_LINE(61)
				HX_STACK_DO_THROW(HX_CSTRING("Can't use dynamic sound once file loaded"));
			}
			HX_STACK_LINE(65)
			this->__dynamicSound = true;
			HX_STACK_LINE(66)
			this->__loading = false;
		}
	}
return null();
}


Void Sound_obj::close( ){
{
		HX_STACK_FRAME("openfl.media.Sound","close",0xfbd9cbd1,"openfl.media.Sound.close","openfl/media/Sound.hx",73,0x46a01619)
		HX_STACK_THIS(this)
		HX_STACK_LINE(75)
		if (((this->__handle != null()))){
			HX_STACK_LINE(77)
			::openfl::media::Sound_obj::lime_sound_close(this->__handle);
		}
		HX_STACK_LINE(81)
		this->__handle = (int)0;
		HX_STACK_LINE(82)
		this->__loading = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,close,(void))

Void Sound_obj::load( ::openfl::net::URLRequest stream,::openfl::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic){
bool forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
	HX_STACK_FRAME("openfl.media.Sound","load",0x3e30ac2d,"openfl.media.Sound.load","openfl/media/Sound.hx",87,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_ARG(stream,"stream")
	HX_STACK_ARG(context,"context")
	HX_STACK_ARG(forcePlayAsMusic,"forcePlayAsMusic")
{
		HX_STACK_LINE(89)
		this->bytesLoaded = (int)0;
		HX_STACK_LINE(90)
		this->bytesTotal = (int)0;
		HX_STACK_LINE(92)
		Dynamic _g = ::openfl::media::Sound_obj::lime_sound_from_file(stream->url,forcePlayAsMusic);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(92)
		this->__handle = _g;
		HX_STACK_LINE(94)
		if (((this->__handle == null()))){
			HX_STACK_LINE(96)
			::haxe::Log_obj::trace(((HX_CSTRING("Error: Could not load \"") + stream->url) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Sound.hx"),96,HX_CSTRING("openfl.media.Sound"),HX_CSTRING("load")));
		}
		else{
			HX_STACK_LINE(100)
			this->url = stream->url;
			HX_STACK_LINE(101)
			this->__loading = true;
			HX_STACK_LINE(102)
			this->__checkLoading();
			HX_STACK_LINE(103)
			this->__loading = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Sound_obj,load,(void))

Void Sound_obj::loadCompressedDataFromByteArray( ::openfl::utils::ByteArray bytes,int length,hx::Null< bool >  __o_forcePlayAsMusic){
bool forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
	HX_STACK_FRAME("openfl.media.Sound","loadCompressedDataFromByteArray",0x8f237f2f,"openfl.media.Sound.loadCompressedDataFromByteArray","openfl/media/Sound.hx",111,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(length,"length")
	HX_STACK_ARG(forcePlayAsMusic,"forcePlayAsMusic")
{
		HX_STACK_LINE(113)
		this->bytesLoaded = length;
		HX_STACK_LINE(114)
		this->bytesTotal = length;
		HX_STACK_LINE(116)
		Dynamic _g = ::openfl::media::Sound_obj::lime_sound_from_data(bytes,length,forcePlayAsMusic);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(116)
		this->__handle = _g;
		HX_STACK_LINE(118)
		if (((this->__handle == null()))){
			HX_STACK_LINE(120)
			HX_STACK_DO_THROW((HX_CSTRING("Could not load buffer with length: ") + length));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Sound_obj,loadCompressedDataFromByteArray,(void))

Void Sound_obj::loadPCMFromByteArray( ::openfl::utils::ByteArray bytes,int samples,::String __o_format,hx::Null< bool >  __o_stereo,hx::Null< Float >  __o_sampleRate){
::String format = __o_format.Default(HX_CSTRING("float"));
bool stereo = __o_stereo.Default(true);
Float sampleRate = __o_sampleRate.Default(44100.0);
	HX_STACK_FRAME("openfl.media.Sound","loadPCMFromByteArray",0xb6cc217a,"openfl.media.Sound.loadPCMFromByteArray","openfl/media/Sound.hx",127,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(samples,"samples")
	HX_STACK_ARG(format,"format")
	HX_STACK_ARG(stereo,"stereo")
	HX_STACK_ARG(sampleRate,"sampleRate")
{
		HX_STACK_LINE(129)
		::openfl::utils::ByteArray wav = ::openfl::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(wav,"wav");
		HX_STACK_LINE(130)
		wav->set_endian(HX_CSTRING("littleEndian"));
		HX_STACK_LINE(132)
		int audioFormat;		HX_STACK_VAR(audioFormat,"audioFormat");
		HX_STACK_LINE(132)
		::String _switch_1 = (format);
		if (  ( _switch_1==HX_CSTRING("float"))){
			HX_STACK_LINE(134)
			audioFormat = (int)3;
		}
		else if (  ( _switch_1==HX_CSTRING("short"))){
			HX_STACK_LINE(135)
			audioFormat = (int)1;
		}
		else  {
			HX_STACK_LINE(136)
			HX_STACK_DO_THROW(::openfl::errors::Error_obj::__new((HX_CSTRING("Unsupported format ") + format),null()));
		}
;
;
		HX_STACK_LINE(140)
		int numChannels;		HX_STACK_VAR(numChannels,"numChannels");
		HX_STACK_LINE(140)
		if ((stereo)){
			HX_STACK_LINE(140)
			numChannels = (int)2;
		}
		else{
			HX_STACK_LINE(140)
			numChannels = (int)1;
		}
		HX_STACK_LINE(141)
		int sampleRate1 = ::Std_obj::_int(sampleRate);		HX_STACK_VAR(sampleRate1,"sampleRate1");
		HX_STACK_LINE(142)
		int bitsPerSample;		HX_STACK_VAR(bitsPerSample,"bitsPerSample");
		HX_STACK_LINE(142)
		::String _switch_2 = (format);
		if (  ( _switch_2==HX_CSTRING("float"))){
			HX_STACK_LINE(144)
			bitsPerSample = (int)32;
		}
		else if (  ( _switch_2==HX_CSTRING("short"))){
			HX_STACK_LINE(145)
			bitsPerSample = (int)16;
		}
		else  {
			HX_STACK_LINE(146)
			HX_STACK_DO_THROW(::openfl::errors::Error_obj::__new((HX_CSTRING("Unsupported format ") + format),null()));
		}
;
;
		HX_STACK_LINE(150)
		int byteRate = ::Std_obj::_int((Float(((sampleRate1 * numChannels) * bitsPerSample)) / Float((int)8)));		HX_STACK_VAR(byteRate,"byteRate");
		HX_STACK_LINE(151)
		int blockAlign = ::Std_obj::_int((Float((numChannels * bitsPerSample)) / Float((int)8)));		HX_STACK_VAR(blockAlign,"blockAlign");
		HX_STACK_LINE(152)
		int numSamples = ::Std_obj::_int((Float(bytes->length) / Float(blockAlign)));		HX_STACK_VAR(numSamples,"numSamples");
		HX_STACK_LINE(154)
		wav->writeUTFBytes(HX_CSTRING("RIFF"));
		HX_STACK_LINE(155)
		wav->writeInt(((int)36 + bytes->length));
		HX_STACK_LINE(156)
		wav->writeUTFBytes(HX_CSTRING("WAVE"));
		HX_STACK_LINE(157)
		wav->writeUTFBytes(HX_CSTRING("fmt "));
		HX_STACK_LINE(158)
		wav->writeInt((int)16);
		HX_STACK_LINE(159)
		wav->writeShort(audioFormat);
		HX_STACK_LINE(160)
		wav->writeShort(numChannels);
		HX_STACK_LINE(161)
		wav->writeInt(sampleRate1);
		HX_STACK_LINE(162)
		wav->writeInt(byteRate);
		HX_STACK_LINE(163)
		wav->writeShort(blockAlign);
		HX_STACK_LINE(164)
		wav->writeShort(bitsPerSample);
		HX_STACK_LINE(165)
		wav->writeUTFBytes(HX_CSTRING("data"));
		HX_STACK_LINE(166)
		wav->writeInt(bytes->length);
		HX_STACK_LINE(167)
		wav->writeBytes(bytes,(int)0,bytes->length);
		HX_STACK_LINE(169)
		wav->position = (int)0;
		HX_STACK_LINE(170)
		this->loadCompressedDataFromByteArray(wav,wav->length,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Sound_obj,loadPCMFromByteArray,(void))

::openfl::media::SoundChannel Sound_obj::play( hx::Null< Float >  __o_startTime,hx::Null< int >  __o_loops,::openfl::media::SoundTransform soundTransform){
Float startTime = __o_startTime.Default(0);
int loops = __o_loops.Default(0);
	HX_STACK_FRAME("openfl.media.Sound","play",0x40d33ffb,"openfl.media.Sound.play","openfl/media/Sound.hx",175,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_ARG(startTime,"startTime")
	HX_STACK_ARG(loops,"loops")
	HX_STACK_ARG(soundTransform,"soundTransform")
{
		HX_STACK_LINE(177)
		this->__checkLoading();
		HX_STACK_LINE(179)
		if ((this->__dynamicSound)){
			HX_STACK_LINE(181)
			::openfl::events::SampleDataEvent request = ::openfl::events::SampleDataEvent_obj::__new(::openfl::events::SampleDataEvent_obj::SAMPLE_DATA,null(),null());		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(182)
			this->dispatchEvent(request);
			HX_STACK_LINE(184)
			if (((request->data->length > (int)0))){
				HX_STACK_LINE(186)
				Dynamic _g = ::openfl::media::Sound_obj::lime_sound_channel_create_dynamic(request->data,soundTransform);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(186)
				this->__handle = _g;
			}
			HX_STACK_LINE(190)
			if (((this->__handle == null()))){
				HX_STACK_LINE(192)
				::openfl::media::SoundChannel channel = ::openfl::media::SoundChannel_obj::__new(null(),startTime,loops,soundTransform);		HX_STACK_VAR(channel,"channel");
				HX_STACK_LINE(193)
				channel->__soundInstance = hx::ObjectPtr<OBJ_>(this);
				HX_STACK_LINE(195)
				return channel;
			}
			HX_STACK_LINE(199)
			::openfl::media::SoundChannel result = ::openfl::media::SoundChannel_obj::createDynamic(this->__handle,soundTransform,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(result,"result");
			HX_STACK_LINE(200)
			this->__handle = null();
			HX_STACK_LINE(201)
			return result;
		}
		else{
			HX_STACK_LINE(205)
			if (((bool((this->__handle == null())) || bool(this->__loading)))){
				HX_STACK_LINE(207)
				::openfl::media::SoundChannel channel = ::openfl::media::SoundChannel_obj::__new(null(),startTime,loops,soundTransform);		HX_STACK_VAR(channel,"channel");
				HX_STACK_LINE(208)
				channel->__soundInstance = hx::ObjectPtr<OBJ_>(this);
				HX_STACK_LINE(210)
				return channel;
			}
			HX_STACK_LINE(214)
			::openfl::media::SoundChannel channel = ::openfl::media::SoundChannel_obj::__new(this->__handle,startTime,loops,soundTransform);		HX_STACK_VAR(channel,"channel");
			HX_STACK_LINE(215)
			channel->__soundInstance = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(217)
			return channel;
		}
		HX_STACK_LINE(179)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Sound_obj,play,return )

Void Sound_obj::__checkLoading( ){
{
		HX_STACK_FRAME("openfl.media.Sound","__checkLoading",0x68928a7b,"openfl.media.Sound.__checkLoading","openfl/media/Sound.hx",226,0x46a01619)
		HX_STACK_THIS(this)
		HX_STACK_LINE(226)
		if (((bool((bool(!(this->__dynamicSound)) && bool(this->__loading))) && bool((this->__handle != null()))))){
			HX_STACK_LINE(228)
			Dynamic status = ::openfl::media::Sound_obj::lime_sound_get_status(this->__handle);		HX_STACK_VAR(status,"status");
			HX_STACK_LINE(230)
			if (((status == null()))){
				HX_STACK_LINE(232)
				HX_STACK_DO_THROW(HX_CSTRING("Could not get sound status"));
			}
			HX_STACK_LINE(236)
			this->bytesLoaded = status->__Field(HX_CSTRING("bytesLoaded"),true);
			HX_STACK_LINE(237)
			this->bytesTotal = status->__Field(HX_CSTRING("bytesTotal"),true);
			HX_STACK_LINE(238)
			this->__loading = (this->bytesLoaded < this->bytesTotal);
			HX_STACK_LINE(240)
			if (((status->__Field(HX_CSTRING("error"),true) != null()))){
				HX_STACK_LINE(242)
				HX_STACK_DO_THROW(status->__Field(HX_CSTRING("error"),true));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,__checkLoading,(void))

Void Sound_obj::__onError( ::String msg){
{
		HX_STACK_FRAME("openfl.media.Sound","__onError",0xb69aefa2,"openfl.media.Sound.__onError","openfl/media/Sound.hx",251,0x46a01619)
		HX_STACK_THIS(this)
		HX_STACK_ARG(msg,"msg")
		HX_STACK_LINE(253)
		::openfl::events::IOErrorEvent _g = ::openfl::events::IOErrorEvent_obj::__new(::openfl::events::IOErrorEvent_obj::IO_ERROR,true,false,msg,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(253)
		this->dispatchEvent(_g);
		HX_STACK_LINE(254)
		this->__handle = null();
		HX_STACK_LINE(255)
		this->__loading = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,__onError,(void))

::openfl::media::ID3Info Sound_obj::get_id3( ){
	HX_STACK_FRAME("openfl.media.Sound","get_id3",0xac6378e8,"openfl.media.Sound.get_id3","openfl/media/Sound.hx",267,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_LINE(269)
	this->__checkLoading();
	HX_STACK_LINE(271)
	if (((bool((this->__handle == null())) || bool(this->__loading)))){
		HX_STACK_LINE(273)
		return ::openfl::media::ID3Info_obj::__new();
	}
	HX_STACK_LINE(277)
	::openfl::media::ID3Info id3 = ::openfl::media::ID3Info_obj::__new();		HX_STACK_VAR(id3,"id3");
	HX_STACK_LINE(278)
	::openfl::media::Sound_obj::lime_sound_get_id3(this->__handle,id3);
	HX_STACK_LINE(279)
	return id3;
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,get_id3,return )

bool Sound_obj::get_isBuffering( ){
	HX_STACK_FRAME("openfl.media.Sound","get_isBuffering",0x2d0a0b88,"openfl.media.Sound.get_isBuffering","openfl/media/Sound.hx",284,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_LINE(286)
	this->__checkLoading();
	HX_STACK_LINE(287)
	return (bool(this->__loading) && bool((this->__handle == null())));
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,get_isBuffering,return )

Float Sound_obj::get_length( ){
	HX_STACK_FRAME("openfl.media.Sound","get_length",0xcc37d5f6,"openfl.media.Sound.get_length","openfl/media/Sound.hx",292,0x46a01619)
	HX_STACK_THIS(this)
	HX_STACK_LINE(294)
	if (((bool((this->__handle == null())) || bool(this->__loading)))){
		HX_STACK_LINE(296)
		return (int)0;
	}
	HX_STACK_LINE(300)
	return ::openfl::media::Sound_obj::lime_sound_get_length(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,get_length,return )

Dynamic Sound_obj::lime_sound_from_file;

Dynamic Sound_obj::lime_sound_from_data;

Dynamic Sound_obj::lime_sound_get_id3;

Dynamic Sound_obj::lime_sound_get_length;

Dynamic Sound_obj::lime_sound_close;

Dynamic Sound_obj::lime_sound_get_status;

Dynamic Sound_obj::lime_sound_channel_create_dynamic;


Sound_obj::Sound_obj()
{
}

void Sound_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sound);
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(id3,"id3");
	HX_MARK_MEMBER_NAME(isBuffering,"isBuffering");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(__audioType,"__audioType");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(__loading,"__loading");
	HX_MARK_MEMBER_NAME(__dynamicSound,"__dynamicSound");
	::openfl::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Sound_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_VISIT_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_VISIT_MEMBER_NAME(id3,"id3");
	HX_VISIT_MEMBER_NAME(isBuffering,"isBuffering");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(__audioType,"__audioType");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(__loading,"__loading");
	HX_VISIT_MEMBER_NAME(__dynamicSound,"__dynamicSound");
	::openfl::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Sound_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"id3") ) { return inCallProp ? get_id3() : id3; }
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_id3") ) { return get_id3_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__loading") ) { return __loading; }
		if (HX_FIELD_EQ(inName,"__onError") ) { return __onError_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
		if (HX_FIELD_EQ(inName,"isBuffering") ) { return inCallProp ? get_isBuffering() : isBuffering; }
		if (HX_FIELD_EQ(inName,"__audioType") ) { return __audioType; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__dynamicSound") ) { return __dynamicSound; }
		if (HX_FIELD_EQ(inName,"__checkLoading") ) { return __checkLoading_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_isBuffering") ) { return get_isBuffering_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_sound_close") ) { return lime_sound_close; }
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_sound_get_id3") ) { return lime_sound_get_id3; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_sound_from_file") ) { return lime_sound_from_file; }
		if (HX_FIELD_EQ(inName,"lime_sound_from_data") ) { return lime_sound_from_data; }
		if (HX_FIELD_EQ(inName,"loadPCMFromByteArray") ) { return loadPCMFromByteArray_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_sound_get_length") ) { return lime_sound_get_length; }
		if (HX_FIELD_EQ(inName,"lime_sound_get_status") ) { return lime_sound_get_status; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"loadCompressedDataFromByteArray") ) { return loadCompressedDataFromByteArray_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_create_dynamic") ) { return lime_sound_channel_create_dynamic; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sound_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"id3") ) { id3=inValue.Cast< ::openfl::media::ID3Info >(); return inValue; }
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__loading") ) { __loading=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isBuffering") ) { isBuffering=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__audioType") ) { __audioType=inValue.Cast< ::openfl::media::InternalAudioType >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__dynamicSound") ) { __dynamicSound=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_sound_close") ) { lime_sound_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_sound_get_id3") ) { lime_sound_get_id3=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_sound_from_file") ) { lime_sound_from_file=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_sound_from_data") ) { lime_sound_from_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_sound_get_length") ) { lime_sound_get_length=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_sound_get_status") ) { lime_sound_get_status=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"lime_sound_channel_create_dynamic") ) { lime_sound_channel_create_dynamic=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sound_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("id3"));
	outFields->push(HX_CSTRING("isBuffering"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("__audioType"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("__loading"));
	outFields->push(HX_CSTRING("__dynamicSound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lime_sound_from_file"),
	HX_CSTRING("lime_sound_from_data"),
	HX_CSTRING("lime_sound_get_id3"),
	HX_CSTRING("lime_sound_get_length"),
	HX_CSTRING("lime_sound_close"),
	HX_CSTRING("lime_sound_get_status"),
	HX_CSTRING("lime_sound_channel_create_dynamic"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Sound_obj,bytesLoaded),HX_CSTRING("bytesLoaded")},
	{hx::fsInt,(int)offsetof(Sound_obj,bytesTotal),HX_CSTRING("bytesTotal")},
	{hx::fsObject /*::openfl::media::ID3Info*/ ,(int)offsetof(Sound_obj,id3),HX_CSTRING("id3")},
	{hx::fsBool,(int)offsetof(Sound_obj,isBuffering),HX_CSTRING("isBuffering")},
	{hx::fsFloat,(int)offsetof(Sound_obj,length),HX_CSTRING("length")},
	{hx::fsString,(int)offsetof(Sound_obj,url),HX_CSTRING("url")},
	{hx::fsObject /*::openfl::media::InternalAudioType*/ ,(int)offsetof(Sound_obj,__audioType),HX_CSTRING("__audioType")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Sound_obj,__handle),HX_CSTRING("__handle")},
	{hx::fsBool,(int)offsetof(Sound_obj,__loading),HX_CSTRING("__loading")},
	{hx::fsBool,(int)offsetof(Sound_obj,__dynamicSound),HX_CSTRING("__dynamicSound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("id3"),
	HX_CSTRING("isBuffering"),
	HX_CSTRING("length"),
	HX_CSTRING("url"),
	HX_CSTRING("__audioType"),
	HX_CSTRING("__handle"),
	HX_CSTRING("__loading"),
	HX_CSTRING("__dynamicSound"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("close"),
	HX_CSTRING("load"),
	HX_CSTRING("loadCompressedDataFromByteArray"),
	HX_CSTRING("loadPCMFromByteArray"),
	HX_CSTRING("play"),
	HX_CSTRING("__checkLoading"),
	HX_CSTRING("__onError"),
	HX_CSTRING("get_id3"),
	HX_CSTRING("get_isBuffering"),
	HX_CSTRING("get_length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sound_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_from_file,"lime_sound_from_file");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_from_data,"lime_sound_from_data");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_get_id3,"lime_sound_get_id3");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_get_length,"lime_sound_get_length");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_close,"lime_sound_close");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_get_status,"lime_sound_get_status");
	HX_MARK_MEMBER_NAME(Sound_obj::lime_sound_channel_create_dynamic,"lime_sound_channel_create_dynamic");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Sound_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_from_file,"lime_sound_from_file");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_from_data,"lime_sound_from_data");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_get_id3,"lime_sound_get_id3");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_get_length,"lime_sound_get_length");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_close,"lime_sound_close");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_get_status,"lime_sound_get_status");
	HX_VISIT_MEMBER_NAME(Sound_obj::lime_sound_channel_create_dynamic,"lime_sound_channel_create_dynamic");
};

#endif

Class Sound_obj::__mClass;

void Sound_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.media.Sound"), hx::TCanCast< Sound_obj> ,sStaticFields,sMemberFields,
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

void Sound_obj::__boot()
{
	lime_sound_from_file= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_from_file"),(int)2);
	lime_sound_from_data= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_from_data"),(int)3);
	lime_sound_get_id3= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_get_id3"),(int)2);
	lime_sound_get_length= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_get_length"),(int)1);
	lime_sound_close= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_close"),(int)1);
	lime_sound_get_status= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_get_status"),(int)1);
	lime_sound_channel_create_dynamic= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_sound_channel_create_dynamic"),(int)2);
}

} // end namespace openfl
} // end namespace media
