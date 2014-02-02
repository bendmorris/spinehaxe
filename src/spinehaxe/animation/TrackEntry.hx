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
import spinehaxe.animation.Listeners;

class TrackEntry {

	public var next:TrackEntry;
	public var previous:TrackEntry;
	public var animation:Animation;
	public var loop:Bool;
	public var delay:Float;
	public var time:Float;
	public var lastTime:Float;
	public var endTime:Float;
	public var timeScale:Float;
	public var mixTime:Float;
	public var mixDuration:Float;
	public var onStart:Function;
	public var onEnd:Function;
	public var onComplete:Function;
	public var onEvent:Function;
	public function toString():String {
		return animation == (null) ? "<none>" : animation.name;
	}

	public function new() {
		time = 0;
		lastTime = -1;
		timeScale = 1;
	}
}

class TrackEntryPool {
	var objs:Array<TrackEntry>;
	
	public function new() {
		objs = [];
	}
	
	public function free(obj:TrackEntry) {
		obj.next = obj.previous = null;
		obj.animation = null;
		obj.onStart = obj.onEnd = obj.onComplete = obj.onEvent = null;
		obj.lastTime = -1;
		obj.timeScale = 1;
		obj.time = 0;
		objs.push(obj);
	}
	
	public function get() {
		if (objs.length > 0) {
			return objs.pop();
		}
		return new TrackEntry();
	}
}