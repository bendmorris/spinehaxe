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

import spinehaxe.Bone;
import spinehaxe.Event;
import spinehaxe.Skeleton;
import haxe.ds.Vector;

class RotateTimeline extends CurveTimeline {

	static inline var PREV_FRAME_TIME:Int = -2;
	static inline var FRAME_VALUE:Int = 1;
	public var boneIndex:Int;
	public var frames:Vector<Float>;
	// time, value, ...
	public function new(frameCount:Int) {
		frames = ArrayUtils.allocFloat(frameCount*2);
		super(frameCount);
	}

	/** Sets the time and angle of the specified keyframe. */
	public function setFrame(frameIndex:Int, time:Float, angle:Float):Void {
		frameIndex *= 2;
		frames[frameIndex] = time;
		frames[frameIndex + 1] = angle;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
		if(time < frames[0]) 
			return;
		// Time is before first frame.
		var bone:Bone = skeleton.bones[boneIndex];
		var amount:Float;
		if(time >= frames[frames.length - 2])  {
			// Time is after last frame.
			amount = bone.data.rotation + frames[frames.length - 1] - bone.rotation;
			while(amount > 180)amount -= 360;
			while(amount < -180)amount += 360;
			bone.rotation += amount * alpha;
			return;
		}
		// Interpolate between the previous frame and the current frame.
		var frameIndex:Int = Animation.binarySearch(frames, time, 2);
		var prevFrameValue:Float = frames[frameIndex - 1];
		var frameTime:Float = frames[frameIndex];
		var percent:Float = 1 - (time - frameTime) / (frames[frameIndex + PREV_FRAME_TIME] - frameTime);
		percent = getCurvePercent(Math.floor(frameIndex / 2 - 1), percent < (0) ? 0:(percent > (1) ? 1:percent));
		amount = frames[frameIndex + FRAME_VALUE] - prevFrameValue;
		while(amount > 180)amount -= 360;
		while(amount < -180)amount += 360;
		amount = bone.data.rotation + (prevFrameValue + amount * percent) - bone.rotation;
		while(amount > 180)amount -= 360;
		while(amount < -180)amount += 360;
		bone.rotation += amount * alpha;
	}

}

