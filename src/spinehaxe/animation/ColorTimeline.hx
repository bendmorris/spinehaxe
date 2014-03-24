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
import spinehaxe.Slot;
import haxe.ds.Vector;

class ColorTimeline extends CurveTimeline {

	static inline var PREV_FRAME_TIME:Int = -5;
	static inline var FRAME_R:Int = 1;
	static inline var FRAME_G:Int = 2;
	static inline var FRAME_B:Int = 3;
	static inline var FRAME_A:Int = 4;
	public var slotIndex:Int;
	public var frames:Vector<Float>;
	// time, r, g, b, a, ...
	public function new(frameCount:Int) {
		frames = ArrayUtils.allocFloat(frameCount*5);
		super(frameCount);
	}

	/** Sets the time and value of the specified keyframe. */	public function setFrame(frameIndex:Int, time:Float, r:Float, g:Float, b:Float, a:Float):Void {
		frameIndex *= 5;
		frames[frameIndex] = time;
		frames[frameIndex + 1] = r;
		frames[frameIndex + 2] = g;
		frames[frameIndex + 3] = b;
		frames[frameIndex + 4] = a;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
		if(time < frames[0]) 
			return;
		// Time is before first frame.
		var slot:Slot = skeleton.slots[slotIndex];
		if(time >= frames[frames.length - 5])  {
			// Time is after last frame.
			var i:Int = frames.length - 1;
			slot.r = frames[i - 3];
			slot.g = frames[i - 2];
			slot.b = frames[i - 1];
			slot.a = frames[i];
			return;
		}
		// Interpolate between the previous frame and the current frame.
		var frameIndex:Int = Animation.binarySearch(frames, time, 5);
		var prevFrameR:Float = frames[frameIndex - 4];
		var prevFrameG:Float = frames[frameIndex - 3];
		var prevFrameB:Float = frames[frameIndex - 2];
		var prevFrameA:Float = frames[frameIndex - 1];
		var frameTime:Float = frames[frameIndex];
		var percent:Float = 1 - (time - frameTime) / (frames[frameIndex + PREV_FRAME_TIME] - frameTime);
		percent = getCurvePercent(Math.floor(frameIndex / 5 - 1), percent < (0) ? 0:(percent > (1) ? 1:percent));
		var r:Float = prevFrameR + (frames[frameIndex + FRAME_R] - prevFrameR) * percent;
		var g:Float = prevFrameG + (frames[frameIndex + FRAME_G] - prevFrameG) * percent;
		var b:Float = prevFrameB + (frames[frameIndex + FRAME_B] - prevFrameB) * percent;
		var a:Float = prevFrameA + (frames[frameIndex + FRAME_A] - prevFrameA) * percent;
		if(alpha < 1)  {
			slot.r += (r - slot.r) * alpha;
			slot.g += (g - slot.g) * alpha;
			slot.b += (b - slot.b) * alpha;
			slot.a += (a - slot.a) * alpha;
		}

		else  {
			slot.r = r;
			slot.g = g;
			slot.b = b;
			slot.a = a;
		}

	}

}

