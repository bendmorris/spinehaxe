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

import spinehaxe.Bone;
import spinehaxe.Event;
import spinehaxe.Skeleton;
import openfl.Vector;

class TranslateTimeline extends CurveTimeline {

	static inline var PREV_FRAME_TIME:Int = -3;
	static inline var FRAME_X:Int = 1;
	static inline var FRAME_Y:Int = 2;
	public var boneIndex:Int;
	public var frames:Vector<Float>; // time, value, value, ...
	
	public function new(frameCount:Int) {
		frames = ArrayUtils.allocFloat(frameCount * 3, true);
		super(frameCount);
	}

	/** Sets the time and value of the specified keyframe. */
	public function setFrame(frameIndex:Int, time:Float, x:Float, y:Float):Void {
		frameIndex *= 3;
		frames[frameIndex] = time;
		frames[frameIndex + 1] = x;
		frames[frameIndex + 2] = y;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
		if (time < frames[0])
			return;
		// Time is before first frame.
		var bone:Bone = skeleton.bones[boneIndex];
		if (time >= frames[frames.length - 3]) {
			// Time is after last frame.
			bone.x += (bone.data.x + frames[frames.length - 2] - bone.x) * alpha;
			bone.y += (bone.data.y + frames[frames.length - 1] - bone.y) * alpha;
			return;
		}
		// Interpolate between the previous frame and the current frame.
		var frameIndex:Int = Animation.binarySearch(frames, time, 3);
		var prevFrameX:Float = frames[frameIndex - 2];
		var prevFrameY:Float = frames[frameIndex - 1];
		var frameTime:Float = frames[frameIndex];
		var percent:Float = 1 - (time - frameTime) / (frames[frameIndex + PREV_FRAME_TIME] - frameTime);
		percent = getCurvePercent(Std.int(frameIndex / 3 - 1), percent < (0) ? 0 : (percent > (1) ? 1 : percent));
		bone.x += (bone.data.x + prevFrameX + (frames[frameIndex + FRAME_X] - prevFrameX) * percent - bone.x) * alpha;
		bone.y += (bone.data.y + prevFrameY + (frames[frameIndex + FRAME_Y] - prevFrameY) * percent - bone.y) * alpha;
	}
}
