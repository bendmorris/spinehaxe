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

import spinehaxe.MathUtils;
import spinehaxe.Bone;
import spinehaxe.Event;
import spinehaxe.Skeleton;

class ScaleTimeline extends TranslateTimeline {
	public function new(frameCount:Int) {
		super(frameCount);
	}
	
	override public function getPropertyId():Int {
		return (TimelineType.scale << 24) + boneIndex;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float, setupPose:Bool, mixingOut:Bool):Void {
		var bone:Bone = skeleton.bones[boneIndex];
		
		if (time < frames[0]) {
			if (setupPose) {
				bone.scaleX = bone.data.scaleX;
				bone.scaleY = bone.data.scaleY;	
			}
			return;
		}

		var x:Float, y:Float;
		if (time >= frames[frames.length - TranslateTimeline.ENTRIES]) { // Time is after last frame.
			x = frames[frames.length + TranslateTimeline.PREV_X] * bone.data.scaleX;
			y = frames[frames.length + TranslateTimeline.PREV_Y] * bone.data.scaleY;
		} else {
			// Interpolate between the previous frame and the current frame.
			var frame:Int = Animation.binarySearch(frames, time, TranslateTimeline.ENTRIES);
			x = frames[frame + TranslateTimeline.PREV_X];
			y = frames[frame + TranslateTimeline.PREV_Y];
			var frameTime:Float = frames[frame];
			var percent:Float = getCurvePercent(Std.int(frame / TranslateTimeline.ENTRIES - 1),
				1 - (time - frameTime) / (frames[frame + TranslateTimeline.PREV_TIME] - frameTime));

			x = (x + (frames[frame + TranslateTimeline.X] - x) * percent) * bone.data.scaleX;
			y = (y + (frames[frame + TranslateTimeline.Y] - y) * percent) * bone.data.scaleY;
		}
		if (alpha == 1) {
			bone.scaleX = x;
			bone.scaleY = y;
		} else {
			var bx:Float, by:Float;
			if (setupPose) {
				bx = bone.data.scaleX;
				by = bone.data.scaleY;
			} else {
				bx = bone.scaleX;
				by = bone.scaleY;
			}
			// Mixing out uses sign of setup or current pose, else use sign of key.
			if (mixingOut) {
				x = Math.abs(x) * MathUtils.signum(bx);
				y = Math.abs(y) * MathUtils.signum(by);
			} else {
				bx = Math.abs(bx) * MathUtils.signum(x);
				by = Math.abs(by) * MathUtils.signum(y);
			}
			bone.scaleX = bx + (x - bx) * alpha;
			bone.scaleY = by + (y - by) * alpha;
		}
	}
}
