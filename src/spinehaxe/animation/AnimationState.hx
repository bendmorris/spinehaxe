/******************************************************************************
 * Spine Runtime Software License - Version 1.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Essential, Professional, Enterprise, or Education License must
 *    be purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
package spinehaxe.animation;

import spinehaxe.Event;
import spinehaxe.Skeleton;
import spinehaxe.Exception;
using Lambda;

class AnimationState {
	public var data:AnimationStateData;
	public var tracks:Array<TrackEntry>;
	public var events:Array<Event>;
	public var onStart:Listeners;
	public var onEnd:Listeners;
	public var onComplete:Listeners;
	public var onEvent:Listeners;
	public var timeScale:Float;
	public var clearWhenFinished:Bool=true;
	public function new(data:AnimationStateData) {
		tracks = new Array<TrackEntry>();
		events = new Array<Event>();
		onStart = new Listeners();
		onEnd = new Listeners();
		onComplete = new Listeners();
		onEvent = new Listeners();
		timeScale = 1;
		if(data == null) 
			throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
	}

	public function update(delta:Float):Void {
		delta *= timeScale;
		var i:Int = 0;
		while(i < tracks.length) {
			var current:TrackEntry = tracks[i];
			if(current == null) {
				i++;
				continue;
			}

			var trackDelta:Float = delta * current.timeScale;
			current.time += trackDelta;
			if(current.previous != null)  {
				current.previous.time += trackDelta;
				current.mixTime += trackDelta;
			}
			var next:TrackEntry = current.next;
			if(next != null)  {
				if(current.lastTime >= next.delay) 
					setCurrent(i, next);
			}

			else  {
				// End non-looping animation when it reaches its end time and there is no next entry.
				if(clearWhenFinished && !current.loop && current.lastTime >= current.endTime) 
					clearTrack(i);
			}

			i++;
		}
	}
	
	public function apply(skeleton:Skeleton):Void {
		var i:Int = 0;
		while(i < tracks.length) {
			var current:TrackEntry = tracks[i];
			if(current == null) {
				i++;
				continue;
			}

			events = new Array();
			var time:Float = current.time;
			var lastTime:Float = current.lastTime;
			var endTime:Float = current.endTime;
			var loop:Bool = current.loop;
			if(!loop && time > endTime) 
				time = endTime;
			var previous:TrackEntry = current.previous;
			if(previous == null) 
				current.animation.apply(skeleton, current.lastTime, time, loop, events)
			else  {
				var previousTime:Float = previous.time;
				if(!previous.loop && previousTime > previous.endTime) 
					previousTime = previous.endTime;
				previous.animation.apply(skeleton, previousTime, previousTime, previous.loop, null);
				var alpha:Float = current.mixTime / current.mixDuration;
				if(alpha >= 1)  {
					alpha = 1;
					current.previous = null;
				}
				current.animation.mix(skeleton, current.lastTime, time, loop, events, alpha);
			}

			for(event in events) {
				if(current.onEvent != null) 
					current.onEvent(i, event);
				onEvent.invoke(i, event);
			}

			// Check if completed the animation or a loop iteration.
			if((loop) ? (lastTime % endTime > time % endTime):(lastTime < endTime && time >= endTime))  {
				var count:Int = cast(time / endTime);
				if(current.onComplete != null) 
					current.onComplete(i, count);
				onComplete.invoke(i, count);
			}
;
			current.lastTime = current.time;
			i++;
		}
	}

	public function clearTracks():Void {
		var i:Int = 0;
		var n:Int = tracks.length;
		while(i < n) {
			clearTrack(i);
			i++;
		}
		tracks = new Array();
	}

	public function clearTrack(trackIndex:Int):Void {
		if(trackIndex >= tracks.length) 
			return;
		var current:TrackEntry = tracks[trackIndex];
		if(current == null) 
			return;
		if(current.onEnd != null) 
			current.onEnd(trackIndex);
		onEnd.invoke(trackIndex);
		tracks[trackIndex] = null;
	}

	function expandToIndex(index:Int):TrackEntry {
		if(index < tracks.length) 
			return tracks[index];
		while(index >= tracks.length)tracks[tracks.length] = null;
		return null;
	}

	function setCurrent(index:Int, entry:TrackEntry):Void {
		var current:TrackEntry = expandToIndex(index);
		if(current != null)  {
			current.previous = null;
			if(current.onEnd != null) 
				current.onEnd(index);
			onEnd.invoke(index);
			entry.mixDuration = data.getMix(current.animation, entry.animation);
			if(entry.mixDuration > 0)  {
				entry.mixTime = 0;
				entry.previous = current;
			}
		}
		tracks[index] = entry;
		if(entry.onStart != null) 
			entry.onStart(index);
		onStart.invoke(index);
	}

	public function setAnimationByName(trackIndex:Int, animationName:String, loop:Bool):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if(animation == null) 
			throw new IllegalArgumentException("Animation not found: " + animationName);
		return setAnimation(trackIndex, animation, loop);
	}

	/** Set the current animation. Any queued animations are cleared. */
	public function setAnimation(trackIndex:Int, animation:Animation, loop:Bool):TrackEntry {
		var entry:TrackEntry = new TrackEntry();
		entry.animation = animation;
		entry.loop = loop;
		entry.endTime = animation.duration;
		setCurrent(trackIndex, entry);
		return entry;
	}

	public function addAnimationByName(trackIndex:Int, animationName:String, loop:Bool, delay:Float):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if(animation == null) 
			throw new IllegalArgumentException("Animation not found: " + animationName);
		return addAnimation(trackIndex, animation, loop, delay);
	}

	/** Adds an animation to be played delay seconds after the current or last queued animation.
	 * @param delay May be <= 0 to use duration of previous animation minus any mix duration plus the negative delay. */
	public function addAnimation(trackIndex:Int, animation:Animation, loop:Bool, delay:Float):TrackEntry {
		var entry:TrackEntry = new TrackEntry();
		entry.animation = animation;
		entry.loop = loop;
		entry.endTime = animation.duration;
		var last:TrackEntry = expandToIndex(trackIndex);
		if(last != null)  {
			while(last.next != null)last = last.next;
			last.next = entry;
		}

		else tracks[trackIndex] = entry;
		if(delay <= 0)  {
			if(last != null) 
				delay += last.endTime - data.getMix(last.animation, animation)
			else delay = 0;
		}
		entry.delay = delay;
		return entry;
	}

	/** May be null. */
	public function getCurrent(trackIndex:Int):TrackEntry {
		if(trackIndex >= tracks.length) 
			return null;
		return tracks[trackIndex];
	}

	public function toString():String {
		var buffer:String = "";
		for(entry in tracks) {
			if(entry == null) 
				continue;
			if(buffer.length > 0) 
				buffer += ", ";
			buffer += entry.toString();
		}

		if(buffer.length == 0) 
			return "<none>";
		return buffer;
	}
}

