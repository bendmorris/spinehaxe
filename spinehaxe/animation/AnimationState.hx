/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

package spinehaxe.animation;

import haxe.ds.Vector;
import spinehaxe.Bone;
import spinehaxe.Pool;
import spinehaxe.Event;
import spinehaxe.Skeleton;

class AnimationState {
	static var emptyAnimation:Animation = new Animation("<empty>", new Array(), 0);

	public var data:AnimationStateData;
	public var tracks:Array<TrackEntry> = new Array();
	public var events:Array<Event> = new Array();
	public var onStart:Listeners = new Listeners();
	public var onInterrupt:Listeners = new Listeners();
	public var onEnd:Listeners = new Listeners();
	public var onDispose:Listeners = new Listeners();
	public var onComplete:Listeners = new Listeners();
	public var onEvent:Listeners = new Listeners();
	var queue:EventQueue;
	var propertyIDs:Map<String, String> = new Map();
	@:allow(spinehaxe) var animationsChanged:Bool;
	public var timeScale:Float = 1;
	@:allow(spinehaxe) var trackEntryPool:Pool<TrackEntry>;

	public function new(data:AnimationStateData) {
		if (data == null) throw "data can not be null";
		this.data = data;
		this.queue = new EventQueue(this);
		this.trackEntryPool = new Pool(function() return new TrackEntry());
	}

	public function update(delta:Float):Void {
		delta *= timeScale;
		for (i in 0 ... tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current == null) continue;

			current.animationLast = current.nextAnimationLast;
			current.trackLast = current.nextTrackLast;

			var currentDelta:Float = delta * current.timeScale;

			if (current.delay > 0) {
				current.delay -= currentDelta;
				if (current.delay > 0) continue;
				currentDelta = -current.delay;
				current.delay = 0;
			}

			var next:TrackEntry = current.next;
			if (next != null) {
				// When the next entry's delay is passed, change to the next entry, preserving leftover time.
				var nextTime:Float = current.trackLast - next.delay;
				if (nextTime >= 0) {
					next.delay = 0;
					next.trackTime = nextTime + delta * next.timeScale;
					current.trackTime += currentDelta;
					setCurrent(i, next);
					while (next.mixingFrom != null) {
						next.mixTime += currentDelta;
						next = next.mixingFrom;
					}
					continue;
				}
			} else {
				// Clear the track when there is no next entry, the track end time is reached, and there is no mixingFrom.
				if (current.trackLast >= current.trackEnd && current.mixingFrom == null) {
					tracks[i] = null;
					queue.end(current);
					disposeNext(current);
					continue;
				}
			}
			updateMixingFrom(current, delta);

			current.trackTime += currentDelta;
		}

		queue.drain();
	}

	function updateMixingFrom(entry:TrackEntry, delta:Float):Void {
		var _from:TrackEntry = entry.mixingFrom;
		if (_from == null) return;

		updateMixingFrom(_from, delta);

		if (entry.mixTime >= entry.mixDuration && _from.mixingFrom == null && entry.mixTime > 0) {
			entry.mixingFrom = null;
			queue.end(_from);
			return;
		}

		_from.animationLast = _from.nextAnimationLast;
		_from.trackLast = _from.nextTrackLast;
		_from.trackTime += delta * _from.timeScale;
		entry.mixTime += delta * entry.timeScale;
	}

	public function apply(skeleton:Skeleton):Void {
		if (skeleton == null) throw "skeleton cannot be null.";
		if (animationsChanged) _animationsChanged();

		var events:Array<Event> = this.events;

		for (i in 0 ... tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current == null || current.delay > 0) continue;

			// Apply mixing from entries first.
			var mix:Float = current.alpha;
			if (current.mixingFrom != null)
				mix *= applyMixingFrom(current, skeleton);
			else if (current.trackTime >= current.trackEnd)
				mix = 0;

			// Apply current entry.
			var animationLast:Float = current.animationLast, animationTime:Float = current.getAnimationTime();
			var timelineCount:Int = current.animation.timelines.length;
			var timelines:Array<Timeline> = current.animation.timelines;
			var ii:Int = 0;
			if (mix == 1) {
				for (ii in 0 ... timelineCount)
					timelines[ii].apply(skeleton, animationLast, animationTime, events, 1, true, false);
			} else {
				var firstFrame:Bool = current.timelinesRotation.length == 0;
				if (firstFrame) ArrayUtils.setLength(current.timelinesRotation, timelineCount << 1);
				var timelinesRotation:Array<Float> = current.timelinesRotation;

				var timelinesFirst:Array<Bool> = current.timelinesFirst;
				for (ii in 0 ... timelineCount) {
					var timeline:Timeline = timelines[ii];
					if (Std.is(timeline, RotateTimeline)) {
						applyRotateTimeline(timeline, skeleton, animationTime, mix, timelinesFirst[ii], timelinesRotation, ii << 1,
							firstFrame);
					} else
						timeline.apply(skeleton, animationLast, animationTime, events, mix, timelinesFirst[ii], false);
				}
			}
			queueEvents(current, animationTime);
			current.nextAnimationLast = animationTime;
			current.nextTrackLast = current.trackTime;
		}

		queue.drain();
	}

	function applyMixingFrom(entry:TrackEntry, skeleton:Skeleton):Float {
		var _from:TrackEntry = entry.mixingFrom;
		if (_from.mixingFrom != null) applyMixingFrom(_from, skeleton);

		var mix:Float = 0;
		if (entry.mixDuration == 0) // Single frame mix to undo mixingFrom changes.
			mix = 1;
		else {
			mix = entry.mixTime / entry.mixDuration;
			if (mix > 1) mix = 1;
		}

		var events:Array<Event> = mix < _from.eventThreshold ? this.events : null;
		var attachments:Bool = mix < _from.attachmentThreshold, drawOrder:Bool = mix < _from.drawOrderThreshold;
		var animationLast:Float = _from.animationLast, animationTime:Float = _from.getAnimationTime();
		var timelineCount:Int = _from.animation.timelines.length;
		var timelines:Array<Timeline> = _from.animation.timelines;
		var timelinesFirst:Array<Bool> = _from.timelinesFirst;
		var alpha:Float = _from.alpha * entry.mixAlpha * (1 - mix);

		var firstFrame:Bool = _from.timelinesRotation.length == 0;
		if (firstFrame) ArrayUtils.setLength(_from.timelinesRotation, timelineCount << 1);
		var timelinesRotation:Array<Float> = _from.timelinesRotation;

		for (i in 0 ... timelineCount) {
			var timeline:Timeline = timelines[i];
			var setupPose:Bool = timelinesFirst[i];
			if (Std.is(timeline, RotateTimeline))
				applyRotateTimeline(timeline, skeleton, animationTime, alpha, setupPose, timelinesRotation, i << 1, firstFrame);
			else {
				if (!setupPose) {
					if (!attachments && Std.is(timeline, AttachmentTimeline)) continue;
					if (!drawOrder && Std.is(timeline, DrawOrderTimeline)) continue;
				}
				timeline.apply(skeleton, animationLast, animationTime, events, alpha, setupPose, true);
			}
		}

		queueEvents(_from, animationTime);
		_from.nextAnimationLast = animationTime;
		_from.nextTrackLast = _from.trackTime;

		return mix;
	}

	function applyRotateTimeline(timeline:Timeline, skeleton:Skeleton, time:Float, alpha:Float, setupPose:Bool,
		timelinesRotation:Array<Float>, i:Int, firstFrame:Bool):Void {
		if (alpha == 1) {
			timeline.apply(skeleton, 0, time, null, 1, setupPose, false);
			return;
		}

		var rotateTimeline:RotateTimeline = cast timeline;
		var frames:Vector<Float> = rotateTimeline.frames;
		var bone:Bone = skeleton.bones[rotateTimeline.boneIndex];
		if (time < frames[0]) {
			if (setupPose) bone.rotation = bone.data.rotation;
			return;
		}

		var r2:Float;
		if (time >= frames[frames.length - RotateTimeline.ENTRIES]) // Time is after last frame.
			r2 = bone.data.rotation + frames[frames.length + RotateTimeline.PREV_ROTATION];
		else {
			// Interpolate between the previous frame and the current frame.
			var frame:Int = Animation.binarySearch(frames, time, RotateTimeline.ENTRIES);
			var prevRotation:Float = frames[frame + RotateTimeline.PREV_ROTATION];
			var frameTime:Float = frames[frame];
			var percent:Float = rotateTimeline.getCurvePercent((frame >> 1) - 1,
				1 - (time - frameTime) / (frames[frame + RotateTimeline.PREV_TIME] - frameTime));

			r2 = frames[frame + RotateTimeline.ROTATION] - prevRotation;
			r2 -= (16384 - Std.int((16384.499999999996 - r2 / 360))) * 360;
			r2 = prevRotation + r2 * percent + bone.data.rotation;
			r2 -= (16384 - Std.int((16384.499999999996 - r2 / 360))) * 360;
		}

		// Mix between rotations using the direction of the shortest route on the first frame while detecting crosses.
		var r1:Float = setupPose ? bone.data.rotation : bone.rotation;
		var total:Float, diff:Float = r2 - r1;
		if (diff == 0) {
			if (firstFrame) {
				timelinesRotation[i] = 0;
				total = 0;
			} else
				total = timelinesRotation[i];
		} else {
			diff -= (16384 - Std.int((16384.499999999996 - diff / 360))) * 360;
			var lastTotal:Float, lastDiff:Float;
			if (firstFrame) {
				lastTotal = 0;
				lastDiff = diff;
			} else {
				lastTotal = timelinesRotation[i]; // Angle and direction of mix, including loops.
				lastDiff = timelinesRotation[i + 1]; // Difference between bones.
			}
			var current:Bool = diff > 0, dir:Bool = lastTotal >= 0;
			// Detect cross at 0 (not 180).
			if (MathUtils.signum(lastDiff) != MathUtils.signum(diff) && Math.abs(lastDiff) <= 90) {
				// A cross after a 360 rotation is a loop.
				if (Math.abs(lastTotal) > 180) lastTotal += 360 * MathUtils.signum(lastTotal);
				dir = current;
			}
			total = diff + lastTotal - lastTotal % 360; // Store loops as part of lastTotal.
			if (dir != current) total += 360 * MathUtils.signum(lastTotal);
			timelinesRotation[i] = total;
		}
		timelinesRotation[i + 1] = diff;
		r1 += total * alpha;
		bone.rotation = r1 - (16384 - Std.int((16384.499999999996 - r1 / 360))) * 360;
	}

	function queueEvents (entry:TrackEntry, animationTime:Float):Void {
		var animationStart:Float = entry.animationStart, animationEnd:Float = entry.animationEnd;
		var duration:Float = animationEnd - animationStart;
		var trackLastWrapped:Float = entry.trackLast % duration;

		// Queue events before complete.
		var events:Array<Event> = this.events;
		var event:Event;
		var i:Int = 0, n:Int = events.length;
		while (i < n) {
			event = events[i];
			if (event.time < trackLastWrapped) break;
			if (event.time > animationEnd) continue; // Discard events outside animation start/end.
			queue.event(entry, event);
			i++;
		}

		// Queue complete if completed a loop iteration or the animation.
		if (entry.loop ? (trackLastWrapped > entry.trackTime % duration)
			: (animationTime >= animationEnd && entry.animationLast < animationEnd)) {
			queue.complete(entry);
		}

		// Queue events after complete.
		while (i < n) {
			event = events[i];
			if (event.time < animationStart) continue; // Discard events outside animation start/end.
			queue.event(entry, events[i]);
			i++;
		}
		ArrayUtils.clearArray(events);
	}

	public function clearTracks ():Void {
		queue.drainDisabled = true;
		for (i in 0 ... tracks.length)
			clearTrack(i);
		ArrayUtils.clearArray(tracks);
		queue.drainDisabled = false;
		queue.drain();
	}

	public function clearTrack (trackIndex:Int):Void {
		if (trackIndex >= tracks.length) return;
		var current:TrackEntry = tracks[trackIndex];
		if (current == null) return;

		queue.end(current);

		disposeNext(current);

		var entry:TrackEntry = current;
		while (true) {
			var _from:TrackEntry = entry.mixingFrom;
			if (_from == null) break;
			queue.end(_from);
			entry.mixingFrom = null;
			entry = _from;
		}

		tracks[current.trackIndex] = null;

		queue.drain();
	}


	function setCurrent (index:Int, current:TrackEntry):Void {
		var _from:TrackEntry = expandToIndex(index);
		tracks[index] = current;

		if (_from != null) {
			queue.interrupt(_from);
			current.mixingFrom = _from;
			current.mixTime = 0;

			ArrayUtils.clearArray(_from.timelinesRotation);

			// If not completely mixed in, set mixAlpha so mixing out happens from current mix to zero.
			if (_from.mixingFrom != null) current.mixAlpha *= Math.min(_from.mixTime / _from.mixDuration, 1);
		}

		queue.start(current);
	}

	public function setAnimationByName (trackIndex:Int, animationName:String, loop:Bool):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if (animation == null) throw "Animation not found: " + animationName;
		return setAnimation(trackIndex, animation, loop);
	}

	public function setAnimation (trackIndex:Int, animation:Animation, loop:Bool):TrackEntry {
		if (animation == null) throw "animation cannot be null.";
		var current:TrackEntry = expandToIndex(trackIndex);
		if (current != null) {
			if (current.nextTrackLast == -1) {
				// Don't mix from an entry that was never applied.
				tracks[trackIndex] = current.mixingFrom;
				queue.interrupt(current);
				queue.end(current);
				disposeNext(current);
				current = current.mixingFrom;
			} else
				disposeNext(current);
		}
		var entry:TrackEntry = trackEntry(trackIndex, animation, loop, current);
		setCurrent(trackIndex, entry);
		queue.drain();
		return entry;
	}

	public function addAnimationByName (trackIndex:Int, animationName:String, loop:Bool, delay:Float):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if (animation == null) throw "Animation not found: " + animationName;
		return addAnimation(trackIndex, animation, loop, delay);
	}

	public function addAnimation (trackIndex:Int, animation:Animation, loop:Bool, delay:Float):TrackEntry {
		if (animation == null) throw "animation cannot be null.";

		var last:TrackEntry = expandToIndex(trackIndex);
		if (last != null) {
			while (last.next != null)
				last = last.next;
		}

		var entry:TrackEntry = trackEntry(trackIndex, animation, loop, last);

		if (last == null) {
			setCurrent(trackIndex, entry);
			queue.drain();
		} else {
			last.next = entry;
			if (delay <= 0) {
				var duration:Float = last.animationEnd - last.animationStart;
				if (duration != 0)
					delay += duration * (1 + Std.int(last.trackTime / duration)) - data.getMix(last.animation, animation);
				else
					delay = 0;
			}
		}

		entry.delay = delay;
		return entry;
	}

	public function setEmptyAnimation (trackIndex:Int, mixDuration:Float):TrackEntry {
		var entry:TrackEntry = setAnimation(trackIndex, emptyAnimation, false);
		entry.mixDuration = mixDuration;
		entry.trackEnd = mixDuration;
		return entry;
	}

	public function addEmptyAnimation (trackIndex:Int, mixDuration:Float, delay:Float):TrackEntry {
		if (delay <= 0) delay -= mixDuration;
		var entry:TrackEntry = addAnimation(trackIndex, emptyAnimation, false, delay);
		entry.mixDuration = mixDuration;
		entry.trackEnd = mixDuration;
		return entry;
	}

	public function setEmptyAnimations (mixDuration:Float):Void {
		queue.drainDisabled = true;
		for (i in 0 ... tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current != null) setEmptyAnimation(current.trackIndex, mixDuration);
		}
		queue.drainDisabled = false;
		queue.drain();
	}

	function expandToIndex (index:Int):TrackEntry {
		if (index < tracks.length) return tracks[index];
		ArrayUtils.setLength(tracks, index + 1);
		return null;
	}

	function trackEntry(trackIndex:Int, animation:Animation, loop:Bool, last:TrackEntry):TrackEntry {
		var entry:TrackEntry = trackEntryPool.obtain();
		entry.trackIndex = trackIndex;
		entry.animation = animation;
		entry.loop = loop;

		entry.eventThreshold = 0;
		entry.attachmentThreshold = 0;
		entry.drawOrderThreshold = 0;

		entry.animationStart = 0;
		entry.animationEnd = animation.duration;
		entry.animationLast = -1;
		entry.nextAnimationLast = -1;

		entry.delay = 0;
		entry.trackTime = 0;
		entry.trackLast = -1;
		entry.nextTrackLast = -1;
		entry.trackEnd = loop ? MathUtils.MAX_INT : entry.animationEnd;
		entry.timeScale = 1;

		entry.alpha = 1;
		entry.mixAlpha = 1;
		entry.mixTime = 0;
		entry.mixDuration = last == null ? 0 : data.getMix(last.animation, animation);
		return entry;
	}

	function disposeNext (entry:TrackEntry):Void{
		var next:TrackEntry = entry.next;
		while (next != null) {
			queue.dispose(next);
			next = next.next;
		}
		entry.next = null;
	}

	function _animationsChanged ():Void {
		animationsChanged = false;

		var propertyIDs:Map<String, String> = this.propertyIDs = new Map();

		// Compute timelinesFirst from lowest to highest track entries.
		var i:Int = 0, n:Int = tracks.length;
		for (key in propertyIDs) {
			propertyIDs.remove(key);
		}
		var entry:TrackEntry;
		while (i < n) { // Find first non-null entry.
			entry = tracks[i];
			if (entry == null) {
				i++;
				continue;
			}
			setTimelinesFirst(entry);
			break;
		}
		while (i < n) { // Rest of entries.
			entry = tracks[i];
			if (entry != null) checkTimelinesFirst(entry);
			i++;
		}
	}

	function setTimelinesFirst (entry:TrackEntry):Void {
		if (entry.mixingFrom != null) {
			setTimelinesFirst(entry.mixingFrom);
			checkTimelinesUsage(entry, entry.timelinesFirst);
			return;
		}
		var propertyIDs:Map<String, String> = this.propertyIDs;
		var timelines:Array<Timeline> = entry.animation.timelines;
		var n:Int = timelines.length;
		var usage:Array<Bool> = entry.timelinesFirst;
		ArrayUtils.setLength(usage, n);
		for (i in 0 ... n) {
			var id:String = Std.string(timelines[i].getPropertyId());
			propertyIDs[id] = id;
			usage[i] = true;
		}
	}

	function checkTimelinesFirst (entry:TrackEntry):Void {
		if (entry.mixingFrom != null) checkTimelinesFirst(entry.mixingFrom);
		checkTimelinesUsage(entry, entry.timelinesFirst);
	}

	function checkTimelinesUsage (entry:TrackEntry, usageArray:Array<Bool>):Void {
		var propertyIDs:Map<String, String> = this.propertyIDs;
		var timelines:Array<Timeline> = entry.animation.timelines;
		var n:Int = timelines.length;
		var usage:Array<Bool> = usageArray;
		ArrayUtils.setLength(usageArray, n);
		for (i in 0 ... n) {
			var id:String = Std.string(timelines[i].getPropertyId());
			usage[i] = !propertyIDs.exists(id);
			propertyIDs[id] = id;
		}
	}

	public function getCurrent (trackIndex:Int):TrackEntry {
		if (trackIndex >= tracks.length) return null;
		return tracks[trackIndex];
	}

	public function clearListeners ():Void {
		ArrayUtils.clearArray(onStart._listeners);
		ArrayUtils.clearArray(onInterrupt._listeners);
		ArrayUtils.clearArray(onEnd._listeners);
		ArrayUtils.clearArray(onDispose._listeners);
		ArrayUtils.clearArray(onComplete._listeners);
		ArrayUtils.clearArray(onEvent._listeners);
	}

	public function clearListenerNotifications():Void {
		queue.clear();
	}
}
