#include <hxcpp.h>

#ifndef INCLUDED_spinehaxe_Event
#include <spinehaxe/Event.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_SkeletonData
#include <spinehaxe/SkeletonData.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Animation
#include <spinehaxe/animation/Animation.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_AnimationState
#include <spinehaxe/animation/AnimationState.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_AnimationStateData
#include <spinehaxe/animation/AnimationStateData.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_Listeners
#include <spinehaxe/animation/Listeners.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntry
#include <spinehaxe/animation/TrackEntry.h>
#endif
#ifndef INCLUDED_spinehaxe_animation_TrackEntryPool
#include <spinehaxe/animation/TrackEntryPool.h>
#endif
namespace spinehaxe{
namespace animation{

Void AnimationState_obj::__construct(::spinehaxe::animation::AnimationStateData data)
{
HX_STACK_FRAME("spinehaxe.animation.AnimationState","new",0x3538baae,"spinehaxe.animation.AnimationState.new","spinehaxe/animation/AnimationState.hx",38,0xd3467f00)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
{
	HX_STACK_LINE(48)
	this->clearWhenFinished = true;
	HX_STACK_LINE(47)
	this->timeScale = (int)0;
	HX_STACK_LINE(50)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(50)
	this->tracks = _g;
	HX_STACK_LINE(51)
	::spinehaxe::animation::TrackEntryPool _g1 = ::spinehaxe::animation::TrackEntryPool_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(51)
	this->trackEntryPool = _g1;
	HX_STACK_LINE(52)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(52)
	this->events = _g2;
	HX_STACK_LINE(53)
	::spinehaxe::animation::Listeners _g3 = ::spinehaxe::animation::Listeners_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(53)
	this->onStart = _g3;
	HX_STACK_LINE(54)
	::spinehaxe::animation::Listeners _g4 = ::spinehaxe::animation::Listeners_obj::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(54)
	this->onEnd = _g4;
	HX_STACK_LINE(55)
	::spinehaxe::animation::Listeners _g5 = ::spinehaxe::animation::Listeners_obj::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(55)
	this->onComplete = _g5;
	HX_STACK_LINE(56)
	::spinehaxe::animation::Listeners _g6 = ::spinehaxe::animation::Listeners_obj::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(56)
	this->onEvent = _g6;
	HX_STACK_LINE(57)
	this->timeScale = (int)1;
	HX_STACK_LINE(58)
	if (((data == null()))){
		HX_STACK_LINE(59)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("data cannot be null.")));
	}
	HX_STACK_LINE(60)
	this->data = data;
}
;
	return null();
}

//AnimationState_obj::~AnimationState_obj() { }

Dynamic AnimationState_obj::__CreateEmpty() { return  new AnimationState_obj; }
hx::ObjectPtr< AnimationState_obj > AnimationState_obj::__new(::spinehaxe::animation::AnimationStateData data)
{  hx::ObjectPtr< AnimationState_obj > result = new AnimationState_obj();
	result->__construct(data);
	return result;}

Dynamic AnimationState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationState_obj > result = new AnimationState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AnimationState_obj::update( Float delta){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","update",0x581d807b,"spinehaxe.animation.AnimationState.update","spinehaxe/animation/AnimationState.hx",63,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_ARG(delta,"delta")
		HX_STACK_LINE(64)
		hx::MultEq(delta,this->timeScale);
		HX_STACK_LINE(65)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(66)
		while((true)){
			HX_STACK_LINE(66)
			if ((!(((i < this->tracks->length))))){
				HX_STACK_LINE(66)
				break;
			}
			HX_STACK_LINE(67)
			::spinehaxe::animation::TrackEntry current = this->tracks->__get(i).StaticCast< ::spinehaxe::animation::TrackEntry >();		HX_STACK_VAR(current,"current");
			HX_STACK_LINE(68)
			if (((current == null()))){
				HX_STACK_LINE(69)
				(i)++;
				HX_STACK_LINE(70)
				continue;
			}
			HX_STACK_LINE(73)
			hx::AddEq(current->time,(delta * current->timeScale));
			HX_STACK_LINE(74)
			if (((current->previous != null()))){
				HX_STACK_LINE(75)
				Float previousDelta = (delta * current->previous->timeScale);		HX_STACK_VAR(previousDelta,"previousDelta");
				HX_STACK_LINE(76)
				hx::AddEq(current->previous->time,previousDelta);
				HX_STACK_LINE(77)
				hx::AddEq(current->mixTime,previousDelta);
			}
			HX_STACK_LINE(80)
			::spinehaxe::animation::TrackEntry next = current->next;		HX_STACK_VAR(next,"next");
			HX_STACK_LINE(81)
			if (((next != null()))){
				HX_STACK_LINE(82)
				next->time = (current->lastTime - next->delay);
				HX_STACK_LINE(83)
				if (((next->time >= (int)0))){
					HX_STACK_LINE(83)
					this->setCurrent(i,next);
				}
			}
			else{
				HX_STACK_LINE(86)
				if (((bool((bool(this->clearWhenFinished) && bool(!(current->loop)))) && bool((current->lastTime >= current->endTime))))){
					HX_STACK_LINE(87)
					this->clearTrack(i);
				}
			}
			HX_STACK_LINE(90)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,update,(void))

Void AnimationState_obj::apply( ::spinehaxe::Skeleton skeleton){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","apply",0x0bea1f3c,"spinehaxe.animation.AnimationState.apply","spinehaxe/animation/AnimationState.hx",94,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_ARG(skeleton,"skeleton")
		HX_STACK_LINE(95)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(96)
		while((true)){
			HX_STACK_LINE(96)
			if ((!(((i < this->tracks->length))))){
				HX_STACK_LINE(96)
				break;
			}
			HX_STACK_LINE(97)
			::spinehaxe::animation::TrackEntry current = this->tracks->__get(i).StaticCast< ::spinehaxe::animation::TrackEntry >();		HX_STACK_VAR(current,"current");
			HX_STACK_LINE(98)
			if (((current == null()))){
				HX_STACK_LINE(99)
				(i)++;
				HX_STACK_LINE(100)
				continue;
			}
			HX_STACK_LINE(103)
			Float time = current->time;		HX_STACK_VAR(time,"time");
			HX_STACK_LINE(104)
			Float lastTime = current->lastTime;		HX_STACK_VAR(lastTime,"lastTime");
			HX_STACK_LINE(105)
			Float endTime = current->endTime;		HX_STACK_VAR(endTime,"endTime");
			HX_STACK_LINE(106)
			bool loop = current->loop;		HX_STACK_VAR(loop,"loop");
			HX_STACK_LINE(107)
			if (((bool(!(loop)) && bool((time > endTime))))){
				HX_STACK_LINE(108)
				time = endTime;
			}
			HX_STACK_LINE(109)
			::spinehaxe::animation::TrackEntry previous = current->previous;		HX_STACK_VAR(previous,"previous");
			HX_STACK_LINE(110)
			if (((previous == null()))){
				HX_STACK_LINE(111)
				if (((current->mix == (int)1))){
					HX_STACK_LINE(112)
					current->animation->apply(skeleton,current->lastTime,time,loop,this->events);
				}
				else{
					HX_STACK_LINE(114)
					current->animation->mix(skeleton,current->lastTime,time,loop,this->events,current->mix);
				}
			}
			else{
				HX_STACK_LINE(116)
				Float previousTime = previous->time;		HX_STACK_VAR(previousTime,"previousTime");
				HX_STACK_LINE(117)
				if (((bool(!(previous->loop)) && bool((previousTime > previous->endTime))))){
					HX_STACK_LINE(118)
					previousTime = previous->endTime;
				}
				HX_STACK_LINE(119)
				previous->animation->apply(skeleton,previousTime,previousTime,previous->loop,null());
				HX_STACK_LINE(121)
				Float alpha = ((Float(current->mixTime) / Float(current->mixDuration)) * current->mix);		HX_STACK_VAR(alpha,"alpha");
				HX_STACK_LINE(122)
				if (((alpha >= (int)1))){
					HX_STACK_LINE(123)
					alpha = (int)1;
					HX_STACK_LINE(124)
					this->trackEntryPool->free(previous);
					HX_STACK_LINE(125)
					current->previous = null();
				}
				HX_STACK_LINE(127)
				current->animation->mix(skeleton,current->lastTime,time,loop,this->events,alpha);
			}
			HX_STACK_LINE(130)
			while((true)){
				HX_STACK_LINE(130)
				if ((!(((this->events->length > (int)0))))){
					HX_STACK_LINE(130)
					break;
				}
				HX_STACK_LINE(131)
				::spinehaxe::Event event = this->events->pop().StaticCast< ::spinehaxe::Event >();		HX_STACK_VAR(event,"event");
				HX_STACK_LINE(132)
				if (((current->onEvent != null()))){
					HX_STACK_LINE(133)
					current->onEvent(i,event);
				}
				HX_STACK_LINE(134)
				this->onEvent->invoke(i,event);
			}
			HX_STACK_LINE(138)
			if (((  ((loop)) ? bool((hx::Mod(lastTime,endTime) > hx::Mod(time,endTime))) : bool((bool((lastTime < endTime)) && bool((time >= endTime)))) ))){
				HX_STACK_LINE(139)
				int count = (Float(time) / Float(endTime));		HX_STACK_VAR(count,"count");
				HX_STACK_LINE(140)
				if (((current->onComplete != null()))){
					HX_STACK_LINE(141)
					current->onComplete(i,count);
				}
				HX_STACK_LINE(142)
				this->onComplete->invoke(i,count);
			}
			HX_STACK_LINE(145)
			current->lastTime = current->time;
			HX_STACK_LINE(146)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,apply,(void))

Void AnimationState_obj::clearTracks( ){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","clearTracks",0x81d72143,"spinehaxe.animation.AnimationState.clearTracks","spinehaxe/animation/AnimationState.hx",150,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_LINE(151)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(152)
		int n = this->tracks->length;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(153)
		while((true)){
			HX_STACK_LINE(153)
			if ((!(((i < n))))){
				HX_STACK_LINE(153)
				break;
			}
			HX_STACK_LINE(154)
			this->clearTrack(i);
			HX_STACK_LINE(155)
			(i)++;
		}
		HX_STACK_LINE(157)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		this->tracks = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationState_obj,clearTracks,(void))

Void AnimationState_obj::clearTrack( int trackIndex){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","clearTrack",0x6474e930,"spinehaxe.animation.AnimationState.clearTrack","spinehaxe/animation/AnimationState.hx",160,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_ARG(trackIndex,"trackIndex")
		HX_STACK_LINE(161)
		if (((trackIndex >= this->tracks->length))){
			HX_STACK_LINE(162)
			return null();
		}
		HX_STACK_LINE(163)
		::spinehaxe::animation::TrackEntry current = this->tracks->__get(trackIndex).StaticCast< ::spinehaxe::animation::TrackEntry >();		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(164)
		if (((current == null()))){
			HX_STACK_LINE(165)
			return null();
		}
		HX_STACK_LINE(166)
		if (((current->onEnd != null()))){
			HX_STACK_LINE(167)
			current->onEnd(trackIndex);
		}
		HX_STACK_LINE(168)
		this->onEnd->invoke(trackIndex,null());
		HX_STACK_LINE(169)
		this->tracks[trackIndex] = null();
		HX_STACK_LINE(170)
		this->freeAll(current);
		HX_STACK_LINE(171)
		if (((current->previous != null()))){
			HX_STACK_LINE(171)
			this->trackEntryPool->free(current->previous);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,clearTrack,(void))

Void AnimationState_obj::freeAll( ::spinehaxe::animation::TrackEntry entry){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","freeAll",0xb48c7123,"spinehaxe.animation.AnimationState.freeAll","spinehaxe/animation/AnimationState.hx",175,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entry,"entry")
		HX_STACK_LINE(175)
		while((true)){
			HX_STACK_LINE(175)
			if ((!(((entry != null()))))){
				HX_STACK_LINE(175)
				break;
			}
			HX_STACK_LINE(176)
			::spinehaxe::animation::TrackEntry next = entry->next;		HX_STACK_VAR(next,"next");
			HX_STACK_LINE(177)
			this->trackEntryPool->free(entry);
			HX_STACK_LINE(178)
			entry = next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,freeAll,(void))

::spinehaxe::animation::TrackEntry AnimationState_obj::expandToIndex( int index){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","expandToIndex",0x333f182b,"spinehaxe.animation.AnimationState.expandToIndex","spinehaxe/animation/AnimationState.hx",182,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(183)
	if (((index < this->tracks->length))){
		HX_STACK_LINE(184)
		return this->tracks->__get(index).StaticCast< ::spinehaxe::animation::TrackEntry >();
	}
	HX_STACK_LINE(185)
	while((true)){
		HX_STACK_LINE(185)
		if ((!(((index >= this->tracks->length))))){
			HX_STACK_LINE(185)
			break;
		}
		HX_STACK_LINE(185)
		this->tracks[this->tracks->length] = null();
	}
	HX_STACK_LINE(186)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,expandToIndex,return )

Void AnimationState_obj::setCurrent( int index,::spinehaxe::animation::TrackEntry entry){
{
		HX_STACK_FRAME("spinehaxe.animation.AnimationState","setCurrent",0x980ddc29,"spinehaxe.animation.AnimationState.setCurrent","spinehaxe/animation/AnimationState.hx",189,0xd3467f00)
		HX_STACK_THIS(this)
		HX_STACK_ARG(index,"index")
		HX_STACK_ARG(entry,"entry")
		HX_STACK_LINE(190)
		::spinehaxe::animation::TrackEntry current = this->expandToIndex(index);		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(191)
		if (((current != null()))){
			HX_STACK_LINE(192)
			::spinehaxe::animation::TrackEntry previous = current->previous;		HX_STACK_VAR(previous,"previous");
			HX_STACK_LINE(193)
			current->previous = null();
			HX_STACK_LINE(195)
			if (((current->onEnd != null()))){
				HX_STACK_LINE(195)
				current->onEnd(index);
			}
			HX_STACK_LINE(196)
			this->onEnd->invoke(index,null());
			HX_STACK_LINE(198)
			Float _g = this->data->getMix(current->animation,entry->animation);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(198)
			entry->mixDuration = _g;
			HX_STACK_LINE(199)
			if (((entry->mixDuration > (int)0))){
				HX_STACK_LINE(200)
				entry->mixTime = (int)0;
				HX_STACK_LINE(201)
				if (((bool((previous != null())) && bool(((Float(current->mixTime) / Float(current->mixDuration)) < 0.5))))){
					HX_STACK_LINE(202)
					entry->previous = previous;
					HX_STACK_LINE(203)
					previous = current;
				}
				else{
					HX_STACK_LINE(205)
					entry->previous = current;
				}
			}
		}
		HX_STACK_LINE(208)
		this->tracks[index] = entry;
		HX_STACK_LINE(209)
		if (((entry->onStart != null()))){
			HX_STACK_LINE(210)
			entry->onStart(index);
		}
		HX_STACK_LINE(211)
		this->onStart->invoke(index,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationState_obj,setCurrent,(void))

::spinehaxe::animation::TrackEntry AnimationState_obj::setAnimationByName( int trackIndex,::String animationName,bool loop){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","setAnimationByName",0x4e9e59d6,"spinehaxe.animation.AnimationState.setAnimationByName","spinehaxe/animation/AnimationState.hx",214,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(trackIndex,"trackIndex")
	HX_STACK_ARG(animationName,"animationName")
	HX_STACK_ARG(loop,"loop")
	HX_STACK_LINE(215)
	::spinehaxe::animation::Animation animation = this->data->skeletonData->findAnimation(animationName);		HX_STACK_VAR(animation,"animation");
	HX_STACK_LINE(216)
	if (((animation == null()))){
		HX_STACK_LINE(217)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Animation not found: ") + animationName)));
	}
	HX_STACK_LINE(218)
	return this->setAnimation(trackIndex,animation,loop);
}


HX_DEFINE_DYNAMIC_FUNC3(AnimationState_obj,setAnimationByName,return )

::spinehaxe::animation::TrackEntry AnimationState_obj::setAnimation( int trackIndex,::spinehaxe::animation::Animation animation,bool loop){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","setAnimation",0x26630af4,"spinehaxe.animation.AnimationState.setAnimation","spinehaxe/animation/AnimationState.hx",222,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(trackIndex,"trackIndex")
	HX_STACK_ARG(animation,"animation")
	HX_STACK_ARG(loop,"loop")
	HX_STACK_LINE(223)
	::spinehaxe::animation::TrackEntry entry = this->trackEntryPool->get();		HX_STACK_VAR(entry,"entry");
	HX_STACK_LINE(224)
	entry->animation = animation;
	HX_STACK_LINE(225)
	entry->loop = loop;
	HX_STACK_LINE(226)
	entry->endTime = animation->duration;
	HX_STACK_LINE(227)
	this->setCurrent(trackIndex,entry);
	HX_STACK_LINE(228)
	return entry;
}


HX_DEFINE_DYNAMIC_FUNC3(AnimationState_obj,setAnimation,return )

::spinehaxe::animation::TrackEntry AnimationState_obj::addAnimationByName( int trackIndex,::String animationName,bool loop,Float delay){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","addAnimationByName",0x0da12a37,"spinehaxe.animation.AnimationState.addAnimationByName","spinehaxe/animation/AnimationState.hx",231,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(trackIndex,"trackIndex")
	HX_STACK_ARG(animationName,"animationName")
	HX_STACK_ARG(loop,"loop")
	HX_STACK_ARG(delay,"delay")
	HX_STACK_LINE(232)
	::spinehaxe::animation::Animation animation = this->data->skeletonData->findAnimation(animationName);		HX_STACK_VAR(animation,"animation");
	HX_STACK_LINE(233)
	if (((animation == null()))){
		HX_STACK_LINE(234)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Animation not found: ") + animationName)));
	}
	HX_STACK_LINE(235)
	return this->addAnimation(trackIndex,animation,loop,delay);
}


HX_DEFINE_DYNAMIC_FUNC4(AnimationState_obj,addAnimationByName,return )

::spinehaxe::animation::TrackEntry AnimationState_obj::addAnimation( int trackIndex,::spinehaxe::animation::Animation animation,bool loop,Float delay){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","addAnimation",0x01676c95,"spinehaxe.animation.AnimationState.addAnimation","spinehaxe/animation/AnimationState.hx",240,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(trackIndex,"trackIndex")
	HX_STACK_ARG(animation,"animation")
	HX_STACK_ARG(loop,"loop")
	HX_STACK_ARG(delay,"delay")
	HX_STACK_LINE(241)
	::spinehaxe::animation::TrackEntry entry = this->trackEntryPool->get();		HX_STACK_VAR(entry,"entry");
	HX_STACK_LINE(242)
	entry->animation = animation;
	HX_STACK_LINE(243)
	entry->loop = loop;
	HX_STACK_LINE(244)
	entry->endTime = animation->duration;
	HX_STACK_LINE(245)
	::spinehaxe::animation::TrackEntry last = this->expandToIndex(trackIndex);		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(246)
	if (((last != null()))){
		HX_STACK_LINE(247)
		while((true)){
			HX_STACK_LINE(247)
			if ((!(((last->next != null()))))){
				HX_STACK_LINE(247)
				break;
			}
			HX_STACK_LINE(247)
			last = last->next;
		}
		HX_STACK_LINE(248)
		last->next = entry;
	}
	else{
		HX_STACK_LINE(251)
		this->tracks[trackIndex] = entry;
	}
	HX_STACK_LINE(252)
	if (((delay <= (int)0))){
		HX_STACK_LINE(253)
		if (((last != null()))){
			HX_STACK_LINE(254)
			Float _g = this->data->getMix(last->animation,animation);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(254)
			Float _g1 = (last->endTime - _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(254)
			hx::AddEq(delay,_g1);
		}
		else{
			HX_STACK_LINE(255)
			delay = (int)0;
		}
	}
	HX_STACK_LINE(257)
	entry->delay = delay;
	HX_STACK_LINE(258)
	return entry;
}


HX_DEFINE_DYNAMIC_FUNC4(AnimationState_obj,addAnimation,return )

::spinehaxe::animation::TrackEntry AnimationState_obj::getCurrent( int trackIndex){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","getCurrent",0x94903db5,"spinehaxe.animation.AnimationState.getCurrent","spinehaxe/animation/AnimationState.hx",262,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(trackIndex,"trackIndex")
	HX_STACK_LINE(263)
	if (((trackIndex >= this->tracks->length))){
		HX_STACK_LINE(264)
		return null();
	}
	HX_STACK_LINE(265)
	return this->tracks->__get(trackIndex).StaticCast< ::spinehaxe::animation::TrackEntry >();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationState_obj,getCurrent,return )

::String AnimationState_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.animation.AnimationState","toString",0x7b4fcb9e,"spinehaxe.animation.AnimationState.toString","spinehaxe/animation/AnimationState.hx",268,0xd3467f00)
	HX_STACK_THIS(this)
	HX_STACK_LINE(269)
	::String buffer = HX_CSTRING("");		HX_STACK_VAR(buffer,"buffer");
	HX_STACK_LINE(270)
	{
		HX_STACK_LINE(270)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(270)
		Array< ::Dynamic > _g1 = this->tracks;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(270)
		while((true)){
			HX_STACK_LINE(270)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(270)
				break;
			}
			HX_STACK_LINE(270)
			::spinehaxe::animation::TrackEntry entry = _g1->__get(_g).StaticCast< ::spinehaxe::animation::TrackEntry >();		HX_STACK_VAR(entry,"entry");
			HX_STACK_LINE(270)
			++(_g);
			HX_STACK_LINE(271)
			if (((entry == null()))){
				HX_STACK_LINE(272)
				continue;
			}
			HX_STACK_LINE(273)
			if (((buffer.length > (int)0))){
				HX_STACK_LINE(274)
				hx::AddEq(buffer,HX_CSTRING(", "));
			}
			HX_STACK_LINE(275)
			::String _g2 = entry->toString();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(275)
			hx::AddEq(buffer,_g2);
		}
	}
	HX_STACK_LINE(278)
	if (((buffer.length == (int)0))){
		HX_STACK_LINE(279)
		return HX_CSTRING("<none>");
	}
	HX_STACK_LINE(280)
	return buffer;
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationState_obj,toString,return )


AnimationState_obj::AnimationState_obj()
{
}

void AnimationState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationState);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(tracks,"tracks");
	HX_MARK_MEMBER_NAME(trackEntryPool,"trackEntryPool");
	HX_MARK_MEMBER_NAME(events,"events");
	HX_MARK_MEMBER_NAME(onStart,"onStart");
	HX_MARK_MEMBER_NAME(onEnd,"onEnd");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(onEvent,"onEvent");
	HX_MARK_MEMBER_NAME(timeScale,"timeScale");
	HX_MARK_MEMBER_NAME(clearWhenFinished,"clearWhenFinished");
	HX_MARK_END_CLASS();
}

void AnimationState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(tracks,"tracks");
	HX_VISIT_MEMBER_NAME(trackEntryPool,"trackEntryPool");
	HX_VISIT_MEMBER_NAME(events,"events");
	HX_VISIT_MEMBER_NAME(onStart,"onStart");
	HX_VISIT_MEMBER_NAME(onEnd,"onEnd");
	HX_VISIT_MEMBER_NAME(onComplete,"onComplete");
	HX_VISIT_MEMBER_NAME(onEvent,"onEvent");
	HX_VISIT_MEMBER_NAME(timeScale,"timeScale");
	HX_VISIT_MEMBER_NAME(clearWhenFinished,"clearWhenFinished");
}

Dynamic AnimationState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"onEnd") ) { return onEnd; }
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tracks") ) { return tracks; }
		if (HX_FIELD_EQ(inName,"events") ) { return events; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onStart") ) { return onStart; }
		if (HX_FIELD_EQ(inName,"onEvent") ) { return onEvent; }
		if (HX_FIELD_EQ(inName,"freeAll") ) { return freeAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { return timeScale; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		if (HX_FIELD_EQ(inName,"clearTrack") ) { return clearTrack_dyn(); }
		if (HX_FIELD_EQ(inName,"setCurrent") ) { return setCurrent_dyn(); }
		if (HX_FIELD_EQ(inName,"getCurrent") ) { return getCurrent_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"clearTracks") ) { return clearTracks_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAnimation") ) { return setAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"addAnimation") ) { return addAnimation_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"expandToIndex") ) { return expandToIndex_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"trackEntryPool") ) { return trackEntryPool; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"clearWhenFinished") ) { return clearWhenFinished; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setAnimationByName") ) { return setAnimationByName_dyn(); }
		if (HX_FIELD_EQ(inName,"addAnimationByName") ) { return addAnimationByName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::spinehaxe::animation::AnimationStateData >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"onEnd") ) { onEnd=inValue.Cast< ::spinehaxe::animation::Listeners >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tracks") ) { tracks=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"events") ) { events=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onStart") ) { onStart=inValue.Cast< ::spinehaxe::animation::Listeners >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onEvent") ) { onEvent=inValue.Cast< ::spinehaxe::animation::Listeners >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { timeScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< ::spinehaxe::animation::Listeners >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"trackEntryPool") ) { trackEntryPool=inValue.Cast< ::spinehaxe::animation::TrackEntryPool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"clearWhenFinished") ) { clearWhenFinished=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("tracks"));
	outFields->push(HX_CSTRING("trackEntryPool"));
	outFields->push(HX_CSTRING("events"));
	outFields->push(HX_CSTRING("onStart"));
	outFields->push(HX_CSTRING("onEnd"));
	outFields->push(HX_CSTRING("onComplete"));
	outFields->push(HX_CSTRING("onEvent"));
	outFields->push(HX_CSTRING("timeScale"));
	outFields->push(HX_CSTRING("clearWhenFinished"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::animation::AnimationStateData*/ ,(int)offsetof(AnimationState_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AnimationState_obj,tracks),HX_CSTRING("tracks")},
	{hx::fsObject /*::spinehaxe::animation::TrackEntryPool*/ ,(int)offsetof(AnimationState_obj,trackEntryPool),HX_CSTRING("trackEntryPool")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AnimationState_obj,events),HX_CSTRING("events")},
	{hx::fsObject /*::spinehaxe::animation::Listeners*/ ,(int)offsetof(AnimationState_obj,onStart),HX_CSTRING("onStart")},
	{hx::fsObject /*::spinehaxe::animation::Listeners*/ ,(int)offsetof(AnimationState_obj,onEnd),HX_CSTRING("onEnd")},
	{hx::fsObject /*::spinehaxe::animation::Listeners*/ ,(int)offsetof(AnimationState_obj,onComplete),HX_CSTRING("onComplete")},
	{hx::fsObject /*::spinehaxe::animation::Listeners*/ ,(int)offsetof(AnimationState_obj,onEvent),HX_CSTRING("onEvent")},
	{hx::fsFloat,(int)offsetof(AnimationState_obj,timeScale),HX_CSTRING("timeScale")},
	{hx::fsBool,(int)offsetof(AnimationState_obj,clearWhenFinished),HX_CSTRING("clearWhenFinished")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("tracks"),
	HX_CSTRING("trackEntryPool"),
	HX_CSTRING("events"),
	HX_CSTRING("onStart"),
	HX_CSTRING("onEnd"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("onEvent"),
	HX_CSTRING("timeScale"),
	HX_CSTRING("clearWhenFinished"),
	HX_CSTRING("update"),
	HX_CSTRING("apply"),
	HX_CSTRING("clearTracks"),
	HX_CSTRING("clearTrack"),
	HX_CSTRING("freeAll"),
	HX_CSTRING("expandToIndex"),
	HX_CSTRING("setCurrent"),
	HX_CSTRING("setAnimationByName"),
	HX_CSTRING("setAnimation"),
	HX_CSTRING("addAnimationByName"),
	HX_CSTRING("addAnimation"),
	HX_CSTRING("getCurrent"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationState_obj::__mClass,"__mClass");
};

#endif

Class AnimationState_obj::__mClass;

void AnimationState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.animation.AnimationState"), hx::TCanCast< AnimationState_obj> ,sStaticFields,sMemberFields,
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

void AnimationState_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace animation
