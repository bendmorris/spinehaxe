#include <hxcpp.h>

#ifndef INCLUDED_AnimationStateTest
#include <AnimationStateTest.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
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
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonJson
#include <spinehaxe/SkeletonJson.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_AnimationState
#include <spinehaxe/animation/AnimationState.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_AnimationStateData
#include <spinehaxe/animation/AnimationStateData.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntry
#include <spinehaxe/animation/TrackEntry.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlas
#include <spinehaxe/atlas/TextureAtlas.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureLoader
#include <spinehaxe/atlas/TextureLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_BitmapDataTextureLoader
#include <spinehaxe/platform/nme/BitmapDataTextureLoader.h>
#endif
#ifndef INCLUDED_spinehaxe_platform_nme_renderers_SkeletonRenderer
#include <spinehaxe/platform/nme/renderers/SkeletonRenderer.h>
#endif

Void AnimationStateTest_obj::__construct()
{
HX_STACK_FRAME("AnimationStateTest","new",0xbe3e27f1,"AnimationStateTest.new","AnimationStateTest.hx",19,0x234ae09f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	this->mode = (int)1;
	HX_STACK_LINE(27)
	this->lastTime = 0.0;
	HX_STACK_LINE(32)
	super::__construct();
	HX_STACK_LINE(33)
	Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->lastTime = _g;
	HX_STACK_LINE(35)
	::String _g1 = ::openfl::Assets_obj::getText(HX_CSTRING("assets/spineboy.atlas"));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	::spinehaxe::platform::nme::BitmapDataTextureLoader _g2 = ::spinehaxe::platform::nme::BitmapDataTextureLoader_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(35)
	::spinehaxe::atlas::TextureAtlas _g3 = ::spinehaxe::atlas::TextureAtlas_obj::create(_g1,HX_CSTRING("assets/"),_g2,null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(35)
	this->atlas = _g3;
	HX_STACK_LINE(36)
	::spinehaxe::SkeletonJson json = ::spinehaxe::SkeletonJson_obj::create(this->atlas);		HX_STACK_VAR(json,"json");
	HX_STACK_LINE(37)
	json->scale = 0.6;
	HX_STACK_LINE(38)
	::String _g4 = ::openfl::Assets_obj::getText(HX_CSTRING("assets/spineboy.json"));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(38)
	::spinehaxe::SkeletonData skeletonData = json->readSkeletonData(_g4,HX_CSTRING("spineboy"));		HX_STACK_VAR(skeletonData,"skeletonData");
	HX_STACK_LINE(41)
	::spinehaxe::animation::AnimationStateData stateData = ::spinehaxe::animation::AnimationStateData_obj::__new(skeletonData);		HX_STACK_VAR(stateData,"stateData");
	HX_STACK_LINE(42)
	stateData->setMixByName(HX_CSTRING("walk"),HX_CSTRING("jump"),0.2);
	HX_STACK_LINE(43)
	stateData->setMixByName(HX_CSTRING("jump"),HX_CSTRING("walk"),0.4);
	HX_STACK_LINE(44)
	stateData->setMixByName(HX_CSTRING("jump"),HX_CSTRING("jump"),0.2);
	HX_STACK_LINE(46)
	::spinehaxe::animation::AnimationState _g5 = ::spinehaxe::animation::AnimationState_obj::__new(stateData);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(46)
	this->state = _g5;
	HX_STACK_LINE(47)
	this->state->setAnimationByName((int)0,HX_CSTRING("walk"),true);
	HX_STACK_LINE(49)
	::spinehaxe::Skeleton _g6 = ::spinehaxe::Skeleton_obj::__new(skeletonData);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(49)
	this->skeleton = _g6;
	HX_STACK_LINE(51)
	this->skeleton->x = (int)150;
	HX_STACK_LINE(52)
	this->skeleton->y = (int)450;
	HX_STACK_LINE(53)
	this->skeleton->flipY = true;
	HX_STACK_LINE(55)
	this->skeleton->updateWorldTransform();
	HX_STACK_LINE(57)
	Float _g7 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(57)
	this->lastTime = _g7;
	HX_STACK_LINE(59)
	::spinehaxe::platform::nme::renderers::SkeletonRenderer _g8 = ::spinehaxe::platform::nme::renderers::SkeletonRenderer_obj::__new(this->skeleton);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(59)
	this->renderer = _g8;
	HX_STACK_LINE(60)
	this->addChild(this->renderer);
	HX_STACK_LINE(61)
	::openfl::display::FPS _g9 = ::openfl::display::FPS_obj::__new(null(),null(),null());		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(61)
	this->addChild(_g9);
	HX_STACK_LINE(63)
	::openfl::Lib_obj::get_current()->addEventListener(::openfl::events::Event_obj::ENTER_FRAME,this->render_dyn(),null(),null(),null());
	HX_STACK_LINE(64)
	this->addEventListener(::openfl::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null(),null(),null());
}
;
	return null();
}

//AnimationStateTest_obj::~AnimationStateTest_obj() { }

Dynamic AnimationStateTest_obj::__CreateEmpty() { return  new AnimationStateTest_obj; }
hx::ObjectPtr< AnimationStateTest_obj > AnimationStateTest_obj::__new()
{  hx::ObjectPtr< AnimationStateTest_obj > result = new AnimationStateTest_obj();
	result->__construct();
	return result;}

Dynamic AnimationStateTest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationStateTest_obj > result = new AnimationStateTest_obj();
	result->__construct();
	return result;}

Void AnimationStateTest_obj::added( ::openfl::events::Event e){
{
		HX_STACK_FRAME("AnimationStateTest","added",0xeb1ff291,"AnimationStateTest.added","AnimationStateTest.hx",67,0x234ae09f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(68)
		this->set_mouseChildren(false);
		HX_STACK_LINE(69)
		this->get_stage()->addEventListener(::openfl::events::MouseEvent_obj::CLICK,this->onClick_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationStateTest_obj,added,(void))

Void AnimationStateTest_obj::onClick( ::openfl::events::Event e){
{
		HX_STACK_FRAME("AnimationStateTest","onClick",0x33180eba,"AnimationStateTest.onClick","AnimationStateTest.hx",71,0x234ae09f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(74)
		this->state->setAnimationByName((int)0,HX_CSTRING("jump"),false);
		HX_STACK_LINE(75)
		this->state->addAnimationByName((int)0,HX_CSTRING("walk"),true,0.5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationStateTest_obj,onClick,(void))

Void AnimationStateTest_obj::render( ::openfl::events::Event e){
{
		HX_STACK_FRAME("AnimationStateTest","render",0x36e76465,"AnimationStateTest.render","AnimationStateTest.hx",78,0x234ae09f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(79)
		Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(79)
		Float _g1 = (_g - this->lastTime);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(79)
		Float delta = (Float(_g1) / Float((int)3));		HX_STACK_VAR(delta,"delta");
		HX_STACK_LINE(80)
		Float _g2 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(80)
		this->lastTime = _g2;
		HX_STACK_LINE(81)
		this->state->update(delta);
		HX_STACK_LINE(82)
		this->state->apply(this->skeleton);
		HX_STACK_LINE(83)
		::spinehaxe::animation::TrackEntry anim = this->state->getCurrent((int)0);		HX_STACK_VAR(anim,"anim");
		HX_STACK_LINE(84)
		::String _g3 = anim->toString();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(84)
		if (((_g3 == HX_CSTRING("walk")))){
			HX_STACK_LINE(86)
			if (((anim->time > (int)2))){
				HX_STACK_LINE(86)
				this->state->setAnimationByName((int)0,HX_CSTRING("jump"),false);
			}
		}
		else{
			HX_STACK_LINE(88)
			if (((anim->time > (int)1))){
				HX_STACK_LINE(88)
				this->state->setAnimationByName((int)0,HX_CSTRING("walk"),true);
			}
		}
		HX_STACK_LINE(91)
		this->skeleton->updateWorldTransform();
		HX_STACK_LINE(93)
		this->renderer->set_visible(true);
		HX_STACK_LINE(94)
		this->renderer->draw();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationStateTest_obj,render,(void))

Void AnimationStateTest_obj::main( ){
{
		HX_STACK_FRAME("AnimationStateTest","main",0xb7787f88,"AnimationStateTest.main","AnimationStateTest.hx",99,0x234ae09f)
		HX_STACK_LINE(100)
		::AnimationStateTest main = ::AnimationStateTest_obj::__new();		HX_STACK_VAR(main,"main");
		HX_STACK_LINE(102)
		::openfl::Lib_obj::get_current()->addChild(main);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AnimationStateTest_obj,main,(void))


AnimationStateTest_obj::AnimationStateTest_obj()
{
}

void AnimationStateTest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationStateTest);
	HX_MARK_MEMBER_NAME(renderer,"renderer");
	HX_MARK_MEMBER_NAME(atlas,"atlas");
	HX_MARK_MEMBER_NAME(skeleton,"skeleton");
	HX_MARK_MEMBER_NAME(root_,"root_");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(lastTime,"lastTime");
	HX_MARK_MEMBER_NAME(mode,"mode");
	::openfl::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AnimationStateTest_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(renderer,"renderer");
	HX_VISIT_MEMBER_NAME(atlas,"atlas");
	HX_VISIT_MEMBER_NAME(skeleton,"skeleton");
	HX_VISIT_MEMBER_NAME(root_,"root_");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(lastTime,"lastTime");
	HX_VISIT_MEMBER_NAME(mode,"mode");
	::openfl::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AnimationStateTest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { return atlas; }
		if (HX_FIELD_EQ(inName,"root_") ) { return root_; }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { return renderer; }
		if (HX_FIELD_EQ(inName,"skeleton") ) { return skeleton; }
		if (HX_FIELD_EQ(inName,"lastTime") ) { return lastTime; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationStateTest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { mode=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { atlas=inValue.Cast< ::spinehaxe::atlas::TextureAtlas >(); return inValue; }
		if (HX_FIELD_EQ(inName,"root_") ) { root_=inValue.Cast< ::spinehaxe::Bone >(); return inValue; }
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::spinehaxe::animation::AnimationState >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { renderer=inValue.Cast< ::spinehaxe::platform::nme::renderers::SkeletonRenderer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skeleton") ) { skeleton=inValue.Cast< ::spinehaxe::Skeleton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastTime") ) { lastTime=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationStateTest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("renderer"));
	outFields->push(HX_CSTRING("atlas"));
	outFields->push(HX_CSTRING("skeleton"));
	outFields->push(HX_CSTRING("root_"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("lastTime"));
	outFields->push(HX_CSTRING("mode"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::platform::nme::renderers::SkeletonRenderer*/ ,(int)offsetof(AnimationStateTest_obj,renderer),HX_CSTRING("renderer")},
	{hx::fsObject /*::spinehaxe::atlas::TextureAtlas*/ ,(int)offsetof(AnimationStateTest_obj,atlas),HX_CSTRING("atlas")},
	{hx::fsObject /*::spinehaxe::Skeleton*/ ,(int)offsetof(AnimationStateTest_obj,skeleton),HX_CSTRING("skeleton")},
	{hx::fsObject /*::spinehaxe::Bone*/ ,(int)offsetof(AnimationStateTest_obj,root_),HX_CSTRING("root_")},
	{hx::fsObject /*::spinehaxe::animation::AnimationState*/ ,(int)offsetof(AnimationStateTest_obj,state),HX_CSTRING("state")},
	{hx::fsFloat,(int)offsetof(AnimationStateTest_obj,lastTime),HX_CSTRING("lastTime")},
	{hx::fsInt,(int)offsetof(AnimationStateTest_obj,mode),HX_CSTRING("mode")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("renderer"),
	HX_CSTRING("atlas"),
	HX_CSTRING("skeleton"),
	HX_CSTRING("root_"),
	HX_CSTRING("state"),
	HX_CSTRING("lastTime"),
	HX_CSTRING("mode"),
	HX_CSTRING("added"),
	HX_CSTRING("onClick"),
	HX_CSTRING("render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationStateTest_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationStateTest_obj::__mClass,"__mClass");
};

#endif

Class AnimationStateTest_obj::__mClass;

void AnimationStateTest_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("AnimationStateTest"), hx::TCanCast< AnimationStateTest_obj> ,sStaticFields,sMemberFields,
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

void AnimationStateTest_obj::__boot()
{
}

