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
import haxe.ds.Vector;

class Animation {
	public var timelines:Array<Timeline>;
	public var name:String;

	public var duration:Float;
	public function new(name:String, timelines:Array<Timeline>, duration:Float) {
		if(name == null) 
			throw new IllegalArgumentException("name cannot be null.");
		if(timelines == null) 
			throw new IllegalArgumentException("timelines cannot be null.");
		this.name = name;
		this.timelines = timelines;
		this.duration = duration;
	}

	/** Poses the skeleton at the specified time for this animation. */
	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, loop:Bool, events:Array<Event>):Void {
		if(skeleton == null) 
			throw new IllegalArgumentException("skeleton cannot be null.");
		if(loop && duration != 0)  {
			time %= duration;
			lastTime %= duration;
		}
		var i:Int = 0;
		var n:Int = timelines.length;
		while(i < n) {
			timelines[i].apply(skeleton, lastTime, time, events, 1);
			i++;
		}
	}

	/** Poses the skeleton at the specified time for this animation mixed with the current pose.
	 * @param alpha The amount of this animation that affects the current pose. */
	public function mix(skeleton:Skeleton, lastTime:Float, time:Float, loop:Bool, events:Array<Event>, alpha:Float):Void {
		if(skeleton == null) 
			throw new IllegalArgumentException("skeleton cannot be null.");
		if(loop && duration != 0)  {
			time %= duration;
			lastTime %= duration;
		}
		var i:Int = 0;
		var n:Int = timelines.length;
		while(i < n) {
			timelines[i].apply(skeleton, lastTime, time, events, alpha);
			i++;
		}
	}

	public function toString():String {
		return name;
	}

	/** @param target After the first and before the last entry. */
	static public function binarySearch(values:Vector<Float>, target:Float, step:Int):Int {
		var low:Int = 0;
		var high:Int = Std.int(values.length / step - 2);
		if(high == 0) 
			return step;
		var current:Int = high >>> 1;
		while(true) {
			if(values[(current + 1) * step] <= target) 
				low = current + 1
			else high = current;
			if(low == high) 
				return (low + 1) * step;
			current = (low + high) >>> 1;
		}

		return 0;
	}

	static public function linearSearch(values:Array<Float>, target:Float, step:Int):Int {
		var i:Int = 0;
		var last:Int = values.length - step;
		while(i <= last) {
			if(values[i] > target) 
				return i;
			i += step;
		}
		return -1;
	}

}

