#ifndef INCLUDED_openfl_media_InternalAudioType
#define INCLUDED_openfl_media_InternalAudioType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,media,InternalAudioType)
namespace openfl{
namespace media{


class InternalAudioType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef InternalAudioType_obj OBJ_;

	public:
		InternalAudioType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("openfl.media.InternalAudioType"); }
		::String __ToString() const { return HX_CSTRING("InternalAudioType.") + tag; }

		static ::openfl::media::InternalAudioType MUSIC;
		static inline ::openfl::media::InternalAudioType MUSIC_dyn() { return MUSIC; }
		static ::openfl::media::InternalAudioType SOUND;
		static inline ::openfl::media::InternalAudioType SOUND_dyn() { return SOUND; }
		static ::openfl::media::InternalAudioType UNKNOWN;
		static inline ::openfl::media::InternalAudioType UNKNOWN_dyn() { return UNKNOWN; }
};

} // end namespace openfl
} // end namespace media

#endif /* INCLUDED_openfl_media_InternalAudioType */ 
