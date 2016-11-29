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

import spinehaxe.Skeleton;
import spinehaxe.Event;
import spinehaxe.PathConstraint;

class PathConstraintSpacingTimeline extends PathConstraintPositionTimeline {
	public function new(frameCount:Int) {
		super(frameCount);
	}
	
	override public function getPropertyId():Int {
		return (TimelineType.pathConstraintSpacing << 24) + pathConstraintIndex;
	}

	override public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float, setupPose:Bool, mixingOut:Bool):Void {
		var constraint:PathConstraint = skeleton.pathConstraints[pathConstraintIndex];
		if (time < frames[0]) {
			if (setupPose) constraint.spacing = constraint.data.spacing;
			return;
		}

		var spacing:Float;
		if (time >= frames[frames.length - PathConstraintPositionTimeline.ENTRIES]) // Time is after last frame.
			spacing = frames[frames.length + PathConstraintPositionTimeline.PREV_VALUE];
		else {
			// Interpolate between the previous frame and the current frame.
			var frame:Int = Animation.binarySearch(frames, time, PathConstraintPositionTimeline.ENTRIES);
			spacing = frames[frame + PathConstraintPositionTimeline.PREV_VALUE];
			var frameTime:Float = frames[frame];
			var percent:Float = getCurvePercent(Std.int(frame / PathConstraintPositionTimeline.ENTRIES - 1),
				1 - (time - frameTime) / (frames[frame + PathConstraintPositionTimeline.PREV_TIME] - frameTime));

			spacing += (frames[frame + PathConstraintPositionTimeline.VALUE] - spacing) * percent;
		}

		if (setupPose)
			constraint.spacing = constraint.data.spacing + (spacing - constraint.data.spacing) * alpha;
		else
			constraint.spacing += (spacing - constraint.spacing) * alpha;
	}
}
