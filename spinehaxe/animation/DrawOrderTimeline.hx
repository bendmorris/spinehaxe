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
import spinehaxe.Event;
import spinehaxe.Skeleton;
import spinehaxe.Slot;

class DrawOrderTimeline implements Timeline {
	public var frames:Vector<Float>; // time, ...
	public var drawOrders:Vector<Array<Int>>;

	public var frameCount(get, never):Int;

	public function new(frameCount:Int) {
		frames = ArrayUtils.allocFloat(frameCount);
		drawOrders = new Vector<Array<Int>>(frameCount);
	}

	inline function get_frameCount():Int {
		return frames.length;
	}

	public function getPropertyId():Int {
		return TimelineType.drawOrder << 24;
	}

	/** Sets the time and value of the specified keyframe. */
	public function setFrame(frameIndex:Int, time:Float, drawOrder:Array<Int>):Void {
		frames[frameIndex] = time;
		drawOrders[frameIndex] = drawOrder;
	}

	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float, setupPose:Bool, mixingOut:Bool):Void {
		if (mixingOut && setupPose) {
			for (ii in 0 ... skeleton.slots.length)
				skeleton.drawOrder[ii] = skeleton.slots[ii];
			return;
		}

		var drawOrder:Array<Slot> = skeleton.drawOrder;
		var slots:Array<Slot> = skeleton.slots;
		var slot:Slot;
		var i:Int = 0;
		if (time < frames[0]) {
			if (setupPose) {
				for (slot in slots)
					drawOrder[i++] = slot;
			}
			return;
		}

		var frameIndex:Int;
		if (time >= frames[Std.int(frames.length - 1)]) // Time is after last frame.
			frameIndex = frames.length - 1;
		else
			frameIndex = Animation.binarySearch1(frames, time) - 1;

		var drawOrderToSetupIndex:Array<Int> = drawOrders[frameIndex];
		i = 0;
		if (drawOrderToSetupIndex == null) {
			for (slot in slots)
				drawOrder[i++] = slot;
		} else {
			for (setupIndex in drawOrderToSetupIndex)
				drawOrder[i++] = slots[setupIndex];
		}
	}
}
