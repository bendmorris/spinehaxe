/******************************************************************************
 * Spine Runtimes Software License
 * Version 2.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to install, execute and perform the Spine Runtimes
 * Software (the "Software") solely for internal use. Without the written
 * permission of Esoteric Software (typically granted by licensing Spine), you
 * may not (a) modify, translate, adapt or otherwise create derivative works,
 * improvements of the Software or develop new applications using the Software
 * or (b) remove, delete, alter or obscure any trademarks or any copyright,
 * trademark, patent or other intellectual property or proprietary rights
 * notices on or in the Software, including any copy thereof. Redistributions
 * in binary or source form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
package spinehaxe.animation;

import spinehaxe.Event;
import spinehaxe.Skeleton;
import spinehaxe.Slot;
import openfl.Vector;

class ColorTimeline extends CurveTimeline {

	static inline var PREV_FRAME_TIME:Int = -5;
	static inline var FRAME_R:Int = 1;
	static inline var FRAME_G:Int = 2;
	static inline var FRAME_B:Int = 3;
	static inline var FRAME_A:Int = 4;
	
	public var slotIndex:Int;
	public var frames:Vector<Float>; // time, r, g, b, a, ...

	public function new(frameCount:Int) {
		super(frameCount);
		frames = ArrayUtils.allocFloat(frameCount * 5, true);
	}

	/** Sets the time and value of the specified keyframe. */
	public function setFrame(frameIndex:Int, time:Float, r:Float, g:Float, b:Float, a:Float):Void {
		frameIndex *= 5;
		frames[frameIndex] = time;
		frames[frameIndex + 1] = r;
		frames[frameIndex + 2] = g;
		frames[frameIndex + 3] = b;
		frames[frameIndex + 4] = a;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
		if (time < frames[0])
			return; // Time is before first frame.

		var r:Float, g:Float, b:Float, a:Float;
		if (time >= frames[frames.length - 5]) {
			// Time is after last frame.
			var i:Int = frames.length - 1;
			r = frames[i - 3];
			g = frames[i - 2];
			b = frames[i - 1];
			a = frames[i];
		} else {
			// Interpolate between the previous frame and the current frame.
			var frameIndex:Int = Animation.binarySearch(frames, time, 5);
			var prevFrameR:Float = frames[frameIndex - 4];
			var prevFrameG:Float = frames[frameIndex - 3];
			var prevFrameB:Float = frames[frameIndex - 2];
			var prevFrameA:Float = frames[frameIndex - 1];
			var frameTime:Float = frames[frameIndex];
			var percent:Float = 1 - (time - frameTime) / (frames[frameIndex + PREV_FRAME_TIME] - frameTime);
			percent = getCurvePercent(Std.int(frameIndex / 5 - 1), percent < 0 ? 0 : (percent > 1 ? 1 : percent));
			
			r = prevFrameR + (frames[frameIndex + FRAME_R] - prevFrameR) * percent;
			g = prevFrameG + (frames[frameIndex + FRAME_G] - prevFrameG) * percent;
			b = prevFrameB + (frames[frameIndex + FRAME_B] - prevFrameB) * percent;
			a = prevFrameA + (frames[frameIndex + FRAME_A] - prevFrameA) * percent;
		}
		var slot:Slot = skeleton.slots[slotIndex];
		if (alpha < 1) {
			slot.r += (r - slot.r) * alpha;
			slot.g += (g - slot.g) * alpha;
			slot.b += (b - slot.b) * alpha;
			slot.a += (a - slot.a) * alpha;
		} else {
			slot.r = r;
			slot.g = g;
			slot.b = b;
			slot.a = a;
		}
	}
}
