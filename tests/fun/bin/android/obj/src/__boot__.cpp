#include <hxcpp.h>

#include <spinehaxe/platform/nme/renderers/SkeletonRenderer.h>
#include <spinehaxe/platform/nme/BitmapDataTextureLoader.h>
#include <spinehaxe/platform/nme/BitmapDataTexture.h>
#include <spinehaxe/attachments/RegionSequenceAttachment.h>
#include <spinehaxe/attachments/NumberUtils.h>
#include <spinehaxe/attachments/RegionAttachment.h>
#include <spinehaxe/attachments/Modes.h>
#include <spinehaxe/attachments/Mode.h>
#include <spinehaxe/attachments/BoundingBoxAttachment.h>
#include <spinehaxe/attachments/AttachmentTypes.h>
#include <spinehaxe/attachments/AttachmentType.h>
#include <spinehaxe/attachments/Attachment.h>
#include <spinehaxe/attachments/AtlasAttachmentLoader.h>
#include <spinehaxe/attachments/AttachmentLoader.h>
#include <spinehaxe/atlas/TextureLoader.h>
#include <spinehaxe/atlas/AtlasRegion.h>
#include <spinehaxe/atlas/TextureRegion.h>
#include <spinehaxe/atlas/TextureAtlas.h>
#include <spinehaxe/atlas/TextureAtlasData.h>
#include <spinehaxe/atlas/Region.h>
#include <spinehaxe/atlas/Page.h>
#include <spinehaxe/atlas/Texture.h>
#include <spinehaxe/animation/TrackEntryPool.h>
#include <spinehaxe/animation/TrackEntry.h>
#include <spinehaxe/animation/ScaleTimeline.h>
#include <spinehaxe/animation/TranslateTimeline.h>
#include <spinehaxe/animation/RotateTimeline.h>
#include <spinehaxe/animation/Listeners.h>
#include <spinehaxe/animation/EventTimeline.h>
#include <spinehaxe/animation/DrawOrderTimeline.h>
#include <spinehaxe/animation/ColorTimeline.h>
#include <spinehaxe/animation/CurveTimeline.h>
#include <spinehaxe/animation/AttachmentTimeline.h>
#include <spinehaxe/animation/Timeline.h>
#include <spinehaxe/animation/AnimationStateData.h>
#include <spinehaxe/animation/AnimationState.h>
#include <spinehaxe/animation/Animation.h>
#include <spinehaxe/SlotData.h>
#include <spinehaxe/Slot.h>
#include <spinehaxe/Skin.h>
#include <spinehaxe/SkeletonJson.h>
#include <spinehaxe/SkeletonData.h>
#include <spinehaxe/Skeleton.h>
#include <spinehaxe/MathUtils.h>
#include <spinehaxe/JsonUtils.h>
#include <spinehaxe/Exception.h>
#include <spinehaxe/EventData.h>
#include <spinehaxe/Event.h>
#include <spinehaxe/Color.h>
#include <spinehaxe/BoneData.h>
#include <spinehaxe/Bone.h>
#include <spinehaxe/ArrayUtils.h>
#include <openfl/utils/WeakRef.h>
#include <openfl/utils/Float32Array.h>
#include <openfl/utils/Endian.h>
#include <openfl/utils/CompressionAlgorithm.h>
#include <openfl/utils/ByteArray.h>
#include <openfl/utils/IDataInput.h>
#include <openfl/utils/IDataOutput.h>
#include <openfl/utils/ArrayBufferView.h>
#include <openfl/utils/IMemoryRange.h>
#include <openfl/ui/Keyboard.h>
#include <openfl/text/TextLineMetrics.h>
#include <openfl/text/TextFormat.h>
#include <openfl/text/TextFieldType.h>
#include <openfl/text/TextFieldAutoSize.h>
#include <openfl/text/GridFitType.h>
#include <openfl/text/FontType.h>
#include <openfl/text/FontStyle.h>
#include <openfl/text/Font.h>
#include <openfl/text/AntiAliasType.h>
#include <openfl/system/SecurityDomain.h>
#include <openfl/system/ScreenMode.h>
#include <openfl/system/PixelFormat.h>
#include <openfl/system/LoaderContext.h>
#include <openfl/system/ApplicationDomain.h>
#include <openfl/net/URLVariables.h>
#include <openfl/net/URLRequestMethod.h>
#include <openfl/net/URLRequestHeader.h>
#include <openfl/net/URLRequest.h>
#include <openfl/net/URLLoaderDataFormat.h>
#include <openfl/media/SoundTransform.h>
#include <openfl/media/SoundLoaderContext.h>
#include <openfl/media/AudioThreadState.h>
#include <openfl/media/SoundChannel.h>
#include <openfl/media/InternalAudioType.h>
#include <openfl/media/Sound.h>
#include <openfl/media/ID3Info.h>
#include <openfl/gl/GLTexture.h>
#include <openfl/gl/GLShader.h>
#include <openfl/gl/GLRenderbuffer.h>
#include <openfl/gl/GLProgram.h>
#include <openfl/gl/GLFramebuffer.h>
#include <openfl/gl/GLBuffer.h>
#include <openfl/gl/GLObject.h>
#include <openfl/gl/_GL/Float32Data_Impl_.h>
#include <openfl/gl/GL.h>
#include <openfl/geom/Vector3D.h>
#include <openfl/geom/Transform.h>
#include <openfl/geom/Rectangle.h>
#include <openfl/geom/Matrix3D.h>
#include <openfl/geom/Matrix.h>
#include <openfl/geom/ColorTransform.h>
#include <openfl/filters/BitmapFilter.h>
#include <openfl/events/UncaughtErrorEvents.h>
#include <openfl/events/UncaughtErrorEvent.h>
#include <openfl/events/SystemEvent.h>
#include <openfl/events/SampleDataEvent.h>
#include <openfl/events/ProgressEvent.h>
#include <openfl/events/KeyboardEvent.h>
#include <openfl/events/JoystickEvent.h>
#include <openfl/events/IOErrorEvent.h>
#include <openfl/events/HTTPStatusEvent.h>
#include <openfl/events/FocusEvent.h>
#include <openfl/events/EventPhase.h>
#include <openfl/events/Listener.h>
#include <openfl/events/ErrorEvent.h>
#include <openfl/events/TextEvent.h>
#include <openfl/errors/RangeError.h>
#include <openfl/errors/EOFError.h>
#include <openfl/errors/ArgumentError.h>
#include <openfl/errors/Error.h>
#include <openfl/display/TriangleCulling.h>
#include <openfl/display/Tilesheet.h>
#include <openfl/geom/Point.h>
#include <openfl/display/StageScaleMode.h>
#include <openfl/display/StageQuality.h>
#include <openfl/display/StageDisplayState.h>
#include <openfl/display/StageAlign.h>
#include <openfl/display/TouchInfo.h>
#include <openfl/display/SpreadMethod.h>
#include <openfl/display/Shape.h>
#include <openfl/display/PixelSnapping.h>
#include <openfl/display/OpenGLView.h>
#include <openfl/display/MovieClip.h>
#include <openfl/display/ManagedStage.h>
#include <openfl/display/Stage.h>
#include <openfl/events/TouchEvent.h>
#include <openfl/events/MouseEvent.h>
#include <openfl/events/Event.h>
#include <openfl/display/LoaderInfo.h>
#include <openfl/net/URLLoader.h>
#include <openfl/display/Loader.h>
#include <openfl/display/LineScaleMode.h>
#include <openfl/display/JointStyle.h>
#include <openfl/display/InterpolationMethod.h>
#include <openfl/display/IGraphicsData.h>
#include <openfl/display/GraphicsPathWinding.h>
#include <openfl/display/Graphics.h>
#include <openfl/display/GradientType.h>
#include <openfl/display/FrameLabel.h>
#include <openfl/display/FPS.h>
#include <openfl/text/TextField.h>
#include <openfl/display/DirectRenderer.h>
#include <openfl/display/CapsStyle.h>
#include <openfl/display/BlendMode.h>
#include <openfl/display/OptimizedPerlin.h>
#include <openfl/display/BitmapData.h>
#include <openfl/display/Bitmap.h>
#include <openfl/_Vector/Vector_Impl_.h>
#include <openfl/Memory.h>
#include <openfl/AssetType.h>
#include <openfl/AssetData.h>
#include <openfl/Assets.h>
#include <openfl/AssetCache.h>
#include <haxe/zip/Uncompress.h>
#include <haxe/zip/FlushMode.h>
#include <haxe/zip/Compress.h>
#include <haxe/io/StringInput.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesInput.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/format/JsonParser.h>
#include <haxe/ds/StringMap.h>
#include <haxe/ds/ObjectMap.h>
#include <haxe/ds/IntMap.h>
#include <haxe/Unserializer.h>
#include <haxe/Timer.h>
#include <haxe/Resource.h>
#include <haxe/Log.h>
#include <haxe/CallStack.h>
#include <haxe/StackItem.h>
#include <cpp/vm/Thread.h>
#include <cpp/vm/Mutex.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <Type.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Reflect.h>
#include <IMap.h>
#include <List.h>
#include <Lambda.h>
#include <EReg.h>
#include <DefaultAssetLibrary.h>
#include <openfl/AssetLibrary.h>
#include <Date.h>
#include <DocumentClass.h>
#include <ApplicationMain.h>
#include <AnimationStateTest.h>
#include <openfl/display/Sprite.h>
#include <openfl/display/DisplayObjectContainer.h>
#include <openfl/display/InteractiveObject.h>
#include <openfl/display/DisplayObject.h>
#include <openfl/Lib.h>
#include <Std.h>
#include <sys/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <haxe/io/Bytes.h>
#include <sys/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <sys/io/Process.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <openfl/display/IBitmapDrawable.h>
#include <openfl/events/EventDispatcher.h>
#include <openfl/events/IEventDispatcher.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::spinehaxe::platform::nme::renderers::SkeletonRenderer_obj::__register();
::spinehaxe::platform::nme::BitmapDataTextureLoader_obj::__register();
::spinehaxe::platform::nme::BitmapDataTexture_obj::__register();
::spinehaxe::attachments::RegionSequenceAttachment_obj::__register();
::spinehaxe::attachments::NumberUtils_obj::__register();
::spinehaxe::attachments::RegionAttachment_obj::__register();
::spinehaxe::attachments::Modes_obj::__register();
::spinehaxe::attachments::Mode_obj::__register();
::spinehaxe::attachments::BoundingBoxAttachment_obj::__register();
::spinehaxe::attachments::AttachmentTypes_obj::__register();
::spinehaxe::attachments::AttachmentType_obj::__register();
::spinehaxe::attachments::Attachment_obj::__register();
::spinehaxe::attachments::AtlasAttachmentLoader_obj::__register();
::spinehaxe::attachments::AttachmentLoader_obj::__register();
::spinehaxe::atlas::TextureLoader_obj::__register();
::spinehaxe::atlas::AtlasRegion_obj::__register();
::spinehaxe::atlas::TextureRegion_obj::__register();
::spinehaxe::atlas::TextureAtlas_obj::__register();
::spinehaxe::atlas::TextureAtlasData_obj::__register();
::spinehaxe::atlas::Region_obj::__register();
::spinehaxe::atlas::Page_obj::__register();
::spinehaxe::atlas::Texture_obj::__register();
::spinehaxe::animation::TrackEntryPool_obj::__register();
::spinehaxe::animation::TrackEntry_obj::__register();
::spinehaxe::animation::ScaleTimeline_obj::__register();
::spinehaxe::animation::TranslateTimeline_obj::__register();
::spinehaxe::animation::RotateTimeline_obj::__register();
::spinehaxe::animation::Listeners_obj::__register();
::spinehaxe::animation::EventTimeline_obj::__register();
::spinehaxe::animation::DrawOrderTimeline_obj::__register();
::spinehaxe::animation::ColorTimeline_obj::__register();
::spinehaxe::animation::CurveTimeline_obj::__register();
::spinehaxe::animation::AttachmentTimeline_obj::__register();
::spinehaxe::animation::Timeline_obj::__register();
::spinehaxe::animation::AnimationStateData_obj::__register();
::spinehaxe::animation::AnimationState_obj::__register();
::spinehaxe::animation::Animation_obj::__register();
::spinehaxe::SlotData_obj::__register();
::spinehaxe::Slot_obj::__register();
::spinehaxe::Skin_obj::__register();
::spinehaxe::SkeletonJson_obj::__register();
::spinehaxe::SkeletonData_obj::__register();
::spinehaxe::Skeleton_obj::__register();
::spinehaxe::MathUtils_obj::__register();
::spinehaxe::JsonUtils_obj::__register();
::spinehaxe::Exception_obj::__register();
::spinehaxe::EventData_obj::__register();
::spinehaxe::Event_obj::__register();
::spinehaxe::Color_obj::__register();
::spinehaxe::BoneData_obj::__register();
::spinehaxe::Bone_obj::__register();
::spinehaxe::ArrayUtils_obj::__register();
::openfl::utils::WeakRef_obj::__register();
::openfl::utils::Float32Array_obj::__register();
::openfl::utils::Endian_obj::__register();
::openfl::utils::CompressionAlgorithm_obj::__register();
::openfl::utils::ByteArray_obj::__register();
::openfl::utils::IDataInput_obj::__register();
::openfl::utils::IDataOutput_obj::__register();
::openfl::utils::ArrayBufferView_obj::__register();
::openfl::utils::IMemoryRange_obj::__register();
::openfl::ui::Keyboard_obj::__register();
::openfl::text::TextLineMetrics_obj::__register();
::openfl::text::TextFormat_obj::__register();
::openfl::text::TextFieldType_obj::__register();
::openfl::text::TextFieldAutoSize_obj::__register();
::openfl::text::GridFitType_obj::__register();
::openfl::text::FontType_obj::__register();
::openfl::text::FontStyle_obj::__register();
::openfl::text::Font_obj::__register();
::openfl::text::AntiAliasType_obj::__register();
::openfl::system::SecurityDomain_obj::__register();
::openfl::system::ScreenMode_obj::__register();
::openfl::system::PixelFormat_obj::__register();
::openfl::system::LoaderContext_obj::__register();
::openfl::system::ApplicationDomain_obj::__register();
::openfl::net::URLVariables_obj::__register();
::openfl::net::URLRequestMethod_obj::__register();
::openfl::net::URLRequestHeader_obj::__register();
::openfl::net::URLRequest_obj::__register();
::openfl::net::URLLoaderDataFormat_obj::__register();
::openfl::media::SoundTransform_obj::__register();
::openfl::media::SoundLoaderContext_obj::__register();
::openfl::media::AudioThreadState_obj::__register();
::openfl::media::SoundChannel_obj::__register();
::openfl::media::InternalAudioType_obj::__register();
::openfl::media::Sound_obj::__register();
::openfl::media::ID3Info_obj::__register();
::openfl::gl::GLTexture_obj::__register();
::openfl::gl::GLShader_obj::__register();
::openfl::gl::GLRenderbuffer_obj::__register();
::openfl::gl::GLProgram_obj::__register();
::openfl::gl::GLFramebuffer_obj::__register();
::openfl::gl::GLBuffer_obj::__register();
::openfl::gl::GLObject_obj::__register();
::openfl::gl::_GL::Float32Data_Impl__obj::__register();
::openfl::gl::GL_obj::__register();
::openfl::geom::Vector3D_obj::__register();
::openfl::geom::Transform_obj::__register();
::openfl::geom::Rectangle_obj::__register();
::openfl::geom::Matrix3D_obj::__register();
::openfl::geom::Matrix_obj::__register();
::openfl::geom::ColorTransform_obj::__register();
::openfl::filters::BitmapFilter_obj::__register();
::openfl::events::UncaughtErrorEvents_obj::__register();
::openfl::events::UncaughtErrorEvent_obj::__register();
::openfl::events::SystemEvent_obj::__register();
::openfl::events::SampleDataEvent_obj::__register();
::openfl::events::ProgressEvent_obj::__register();
::openfl::events::KeyboardEvent_obj::__register();
::openfl::events::JoystickEvent_obj::__register();
::openfl::events::IOErrorEvent_obj::__register();
::openfl::events::HTTPStatusEvent_obj::__register();
::openfl::events::FocusEvent_obj::__register();
::openfl::events::EventPhase_obj::__register();
::openfl::events::Listener_obj::__register();
::openfl::events::ErrorEvent_obj::__register();
::openfl::events::TextEvent_obj::__register();
::openfl::errors::RangeError_obj::__register();
::openfl::errors::EOFError_obj::__register();
::openfl::errors::ArgumentError_obj::__register();
::openfl::errors::Error_obj::__register();
::openfl::display::TriangleCulling_obj::__register();
::openfl::display::Tilesheet_obj::__register();
::openfl::geom::Point_obj::__register();
::openfl::display::StageScaleMode_obj::__register();
::openfl::display::StageQuality_obj::__register();
::openfl::display::StageDisplayState_obj::__register();
::openfl::display::StageAlign_obj::__register();
::openfl::display::TouchInfo_obj::__register();
::openfl::display::SpreadMethod_obj::__register();
::openfl::display::Shape_obj::__register();
::openfl::display::PixelSnapping_obj::__register();
::openfl::display::OpenGLView_obj::__register();
::openfl::display::MovieClip_obj::__register();
::openfl::display::ManagedStage_obj::__register();
::openfl::display::Stage_obj::__register();
::openfl::events::TouchEvent_obj::__register();
::openfl::events::MouseEvent_obj::__register();
::openfl::events::Event_obj::__register();
::openfl::display::LoaderInfo_obj::__register();
::openfl::net::URLLoader_obj::__register();
::openfl::display::Loader_obj::__register();
::openfl::display::LineScaleMode_obj::__register();
::openfl::display::JointStyle_obj::__register();
::openfl::display::InterpolationMethod_obj::__register();
::openfl::display::IGraphicsData_obj::__register();
::openfl::display::GraphicsPathWinding_obj::__register();
::openfl::display::Graphics_obj::__register();
::openfl::display::GradientType_obj::__register();
::openfl::display::FrameLabel_obj::__register();
::openfl::display::FPS_obj::__register();
::openfl::text::TextField_obj::__register();
::openfl::display::DirectRenderer_obj::__register();
::openfl::display::CapsStyle_obj::__register();
::openfl::display::BlendMode_obj::__register();
::openfl::display::OptimizedPerlin_obj::__register();
::openfl::display::BitmapData_obj::__register();
::openfl::display::Bitmap_obj::__register();
::openfl::_Vector::Vector_Impl__obj::__register();
::openfl::Memory_obj::__register();
::openfl::AssetType_obj::__register();
::openfl::AssetData_obj::__register();
::openfl::Assets_obj::__register();
::openfl::AssetCache_obj::__register();
::haxe::zip::Uncompress_obj::__register();
::haxe::zip::FlushMode_obj::__register();
::haxe::zip::Compress_obj::__register();
::haxe::io::StringInput_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesInput_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ds::ObjectMap_obj::__register();
::haxe::ds::IntMap_obj::__register();
::haxe::Unserializer_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Resource_obj::__register();
::haxe::Log_obj::__register();
::haxe::CallStack_obj::__register();
::haxe::StackItem_obj::__register();
::cpp::vm::Thread_obj::__register();
::cpp::vm::Mutex_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::Type_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Reflect_obj::__register();
::IMap_obj::__register();
::List_obj::__register();
::Lambda_obj::__register();
::EReg_obj::__register();
::DefaultAssetLibrary_obj::__register();
::openfl::AssetLibrary_obj::__register();
::Date_obj::__register();
::DocumentClass_obj::__register();
::ApplicationMain_obj::__register();
::AnimationStateTest_obj::__register();
::openfl::display::Sprite_obj::__register();
::openfl::display::DisplayObjectContainer_obj::__register();
::openfl::display::InteractiveObject_obj::__register();
::openfl::display::DisplayObject_obj::__register();
::openfl::Lib_obj::__register();
::Std_obj::__register();
::sys::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::sys::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::sys::io::Process_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::openfl::display::IBitmapDrawable_obj::__register();
::openfl::events::EventDispatcher_obj::__register();
::openfl::events::IEventDispatcher_obj::__register();
::openfl::utils::ByteArray_obj::__init__();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::vm::Mutex_obj::__boot();
::cpp::vm::Thread_obj::__boot();
::haxe::Log_obj::__boot();
::openfl::events::IEventDispatcher_obj::__boot();
::openfl::events::EventDispatcher_obj::__boot();
::openfl::display::IBitmapDrawable_obj::__boot();
::Sys_obj::__boot();
::sys::io::Process_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::_Process::Stdin_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Input_obj::__boot();
::sys::io::_Process::Stdout_obj::__boot();
::Std_obj::__boot();
::openfl::Lib_obj::__boot();
::openfl::display::DisplayObject_obj::__boot();
::openfl::display::InteractiveObject_obj::__boot();
::openfl::display::DisplayObjectContainer_obj::__boot();
::openfl::display::Sprite_obj::__boot();
::AnimationStateTest_obj::__boot();
::ApplicationMain_obj::__boot();
::DocumentClass_obj::__boot();
::Date_obj::__boot();
::openfl::AssetLibrary_obj::__boot();
::DefaultAssetLibrary_obj::__boot();
::Lambda_obj::__boot();
::List_obj::__boot();
::IMap_obj::__boot();
::Reflect_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Type_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::CallStack_obj::__boot();
::haxe::Resource_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::Unserializer_obj::__boot();
::haxe::ds::IntMap_obj::__boot();
::haxe::ds::ObjectMap_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::format::JsonParser_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::BytesInput_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::StringInput_obj::__boot();
::haxe::zip::Compress_obj::__boot();
::haxe::zip::FlushMode_obj::__boot();
::haxe::zip::Uncompress_obj::__boot();
::openfl::AssetCache_obj::__boot();
::openfl::Assets_obj::__boot();
::openfl::AssetData_obj::__boot();
::openfl::AssetType_obj::__boot();
::openfl::Memory_obj::__boot();
::openfl::_Vector::Vector_Impl__obj::__boot();
::openfl::display::Bitmap_obj::__boot();
::openfl::display::BitmapData_obj::__boot();
::openfl::display::OptimizedPerlin_obj::__boot();
::openfl::display::BlendMode_obj::__boot();
::openfl::display::CapsStyle_obj::__boot();
::openfl::display::DirectRenderer_obj::__boot();
::openfl::text::TextField_obj::__boot();
::openfl::display::FPS_obj::__boot();
::openfl::display::FrameLabel_obj::__boot();
::openfl::display::GradientType_obj::__boot();
::openfl::display::Graphics_obj::__boot();
::openfl::display::GraphicsPathWinding_obj::__boot();
::openfl::display::IGraphicsData_obj::__boot();
::openfl::display::InterpolationMethod_obj::__boot();
::openfl::display::JointStyle_obj::__boot();
::openfl::display::LineScaleMode_obj::__boot();
::openfl::display::Loader_obj::__boot();
::openfl::net::URLLoader_obj::__boot();
::openfl::display::LoaderInfo_obj::__boot();
::openfl::events::Event_obj::__boot();
::openfl::events::MouseEvent_obj::__boot();
::openfl::events::TouchEvent_obj::__boot();
::openfl::display::Stage_obj::__boot();
::openfl::display::ManagedStage_obj::__boot();
::openfl::display::MovieClip_obj::__boot();
::openfl::display::OpenGLView_obj::__boot();
::openfl::display::PixelSnapping_obj::__boot();
::openfl::display::Shape_obj::__boot();
::openfl::display::SpreadMethod_obj::__boot();
::openfl::display::TouchInfo_obj::__boot();
::openfl::display::StageAlign_obj::__boot();
::openfl::display::StageDisplayState_obj::__boot();
::openfl::display::StageQuality_obj::__boot();
::openfl::display::StageScaleMode_obj::__boot();
::openfl::geom::Point_obj::__boot();
::openfl::display::Tilesheet_obj::__boot();
::openfl::display::TriangleCulling_obj::__boot();
::openfl::errors::Error_obj::__boot();
::openfl::errors::ArgumentError_obj::__boot();
::openfl::errors::EOFError_obj::__boot();
::openfl::errors::RangeError_obj::__boot();
::openfl::events::TextEvent_obj::__boot();
::openfl::events::ErrorEvent_obj::__boot();
::openfl::events::Listener_obj::__boot();
::openfl::events::EventPhase_obj::__boot();
::openfl::events::FocusEvent_obj::__boot();
::openfl::events::HTTPStatusEvent_obj::__boot();
::openfl::events::IOErrorEvent_obj::__boot();
::openfl::events::JoystickEvent_obj::__boot();
::openfl::events::KeyboardEvent_obj::__boot();
::openfl::events::ProgressEvent_obj::__boot();
::openfl::events::SampleDataEvent_obj::__boot();
::openfl::events::SystemEvent_obj::__boot();
::openfl::events::UncaughtErrorEvent_obj::__boot();
::openfl::events::UncaughtErrorEvents_obj::__boot();
::openfl::filters::BitmapFilter_obj::__boot();
::openfl::geom::ColorTransform_obj::__boot();
::openfl::geom::Matrix_obj::__boot();
::openfl::geom::Matrix3D_obj::__boot();
::openfl::geom::Rectangle_obj::__boot();
::openfl::geom::Transform_obj::__boot();
::openfl::geom::Vector3D_obj::__boot();
::openfl::gl::GL_obj::__boot();
::openfl::gl::_GL::Float32Data_Impl__obj::__boot();
::openfl::gl::GLObject_obj::__boot();
::openfl::gl::GLBuffer_obj::__boot();
::openfl::gl::GLFramebuffer_obj::__boot();
::openfl::gl::GLProgram_obj::__boot();
::openfl::gl::GLRenderbuffer_obj::__boot();
::openfl::gl::GLShader_obj::__boot();
::openfl::gl::GLTexture_obj::__boot();
::openfl::media::ID3Info_obj::__boot();
::openfl::media::Sound_obj::__boot();
::openfl::media::InternalAudioType_obj::__boot();
::openfl::media::SoundChannel_obj::__boot();
::openfl::media::AudioThreadState_obj::__boot();
::openfl::media::SoundLoaderContext_obj::__boot();
::openfl::media::SoundTransform_obj::__boot();
::openfl::net::URLLoaderDataFormat_obj::__boot();
::openfl::net::URLRequest_obj::__boot();
::openfl::net::URLRequestHeader_obj::__boot();
::openfl::net::URLRequestMethod_obj::__boot();
::openfl::net::URLVariables_obj::__boot();
::openfl::system::ApplicationDomain_obj::__boot();
::openfl::system::LoaderContext_obj::__boot();
::openfl::system::PixelFormat_obj::__boot();
::openfl::system::ScreenMode_obj::__boot();
::openfl::system::SecurityDomain_obj::__boot();
::openfl::text::AntiAliasType_obj::__boot();
::openfl::text::Font_obj::__boot();
::openfl::text::FontStyle_obj::__boot();
::openfl::text::FontType_obj::__boot();
::openfl::text::GridFitType_obj::__boot();
::openfl::text::TextFieldAutoSize_obj::__boot();
::openfl::text::TextFieldType_obj::__boot();
::openfl::text::TextFormat_obj::__boot();
::openfl::text::TextLineMetrics_obj::__boot();
::openfl::ui::Keyboard_obj::__boot();
::openfl::utils::IMemoryRange_obj::__boot();
::openfl::utils::ArrayBufferView_obj::__boot();
::openfl::utils::IDataOutput_obj::__boot();
::openfl::utils::IDataInput_obj::__boot();
::openfl::utils::ByteArray_obj::__boot();
::openfl::utils::CompressionAlgorithm_obj::__boot();
::openfl::utils::Endian_obj::__boot();
::openfl::utils::Float32Array_obj::__boot();
::openfl::utils::WeakRef_obj::__boot();
::spinehaxe::ArrayUtils_obj::__boot();
::spinehaxe::Bone_obj::__boot();
::spinehaxe::BoneData_obj::__boot();
::spinehaxe::Color_obj::__boot();
::spinehaxe::Event_obj::__boot();
::spinehaxe::EventData_obj::__boot();
::spinehaxe::Exception_obj::__boot();
::spinehaxe::JsonUtils_obj::__boot();
::spinehaxe::MathUtils_obj::__boot();
::spinehaxe::Skeleton_obj::__boot();
::spinehaxe::SkeletonData_obj::__boot();
::spinehaxe::SkeletonJson_obj::__boot();
::spinehaxe::Skin_obj::__boot();
::spinehaxe::Slot_obj::__boot();
::spinehaxe::SlotData_obj::__boot();
::spinehaxe::animation::Animation_obj::__boot();
::spinehaxe::animation::AnimationState_obj::__boot();
::spinehaxe::animation::AnimationStateData_obj::__boot();
::spinehaxe::animation::Timeline_obj::__boot();
::spinehaxe::animation::AttachmentTimeline_obj::__boot();
::spinehaxe::animation::CurveTimeline_obj::__boot();
::spinehaxe::animation::ColorTimeline_obj::__boot();
::spinehaxe::animation::DrawOrderTimeline_obj::__boot();
::spinehaxe::animation::EventTimeline_obj::__boot();
::spinehaxe::animation::Listeners_obj::__boot();
::spinehaxe::animation::RotateTimeline_obj::__boot();
::spinehaxe::animation::TranslateTimeline_obj::__boot();
::spinehaxe::animation::ScaleTimeline_obj::__boot();
::spinehaxe::animation::TrackEntry_obj::__boot();
::spinehaxe::animation::TrackEntryPool_obj::__boot();
::spinehaxe::atlas::Texture_obj::__boot();
::spinehaxe::atlas::Page_obj::__boot();
::spinehaxe::atlas::Region_obj::__boot();
::spinehaxe::atlas::TextureAtlasData_obj::__boot();
::spinehaxe::atlas::TextureAtlas_obj::__boot();
::spinehaxe::atlas::TextureRegion_obj::__boot();
::spinehaxe::atlas::AtlasRegion_obj::__boot();
::spinehaxe::atlas::TextureLoader_obj::__boot();
::spinehaxe::attachments::AttachmentLoader_obj::__boot();
::spinehaxe::attachments::AtlasAttachmentLoader_obj::__boot();
::spinehaxe::attachments::Attachment_obj::__boot();
::spinehaxe::attachments::AttachmentType_obj::__boot();
::spinehaxe::attachments::AttachmentTypes_obj::__boot();
::spinehaxe::attachments::BoundingBoxAttachment_obj::__boot();
::spinehaxe::attachments::Mode_obj::__boot();
::spinehaxe::attachments::Modes_obj::__boot();
::spinehaxe::attachments::RegionAttachment_obj::__boot();
::spinehaxe::attachments::NumberUtils_obj::__boot();
::spinehaxe::attachments::RegionSequenceAttachment_obj::__boot();
::spinehaxe::platform::nme::BitmapDataTexture_obj::__boot();
::spinehaxe::platform::nme::BitmapDataTextureLoader_obj::__boot();
::spinehaxe::platform::nme::renderers::SkeletonRenderer_obj::__boot();
}

