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
import haxe.ds.Vector;

class FlipXTimeline implements Timeline {
	public var boneIndex:Int;
	public var frames:Vector<Float>; // time, flip, ...
	public var frameCount(get, never):Int;

	public function new (frameCount:Int) {
		frames = ArrayUtils.allocFloat(frameCount * 2);
	}

	public function get_frameCount() : Int {
		return Std.int(frames.length / 2);
	}

	/** Sets the time and angle of the specified keyframe. */
	public function setFrame (frameIndex:Int, time:Float, flip:Bool):Void {
		frameIndex *= 2;
		frames[frameIndex] = time;
		frames[frameIndex + 1] = flip ? 1 : 0;
	}

	public function apply (skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
		if (time < frames[0]) {
			if (lastTime > time) apply(skeleton, lastTime, spinehaxe.MathUtils.MAX_INT, null, 0);
			return;
		} else if (lastTime > time) //
			lastTime = -1;

		var frameIndex:Int = (time >= frames[frames.length - 2] ? frames.length : Animation.binarySearch(frames, time, 2)) - 2;
		if (frames[frameIndex] < lastTime) return;

		setFlip(skeleton.bones[boneIndex], frames[frameIndex + 1] != 0);
	}

	function setFlip (bone:Bone, flip:Bool):Void {
		bone.flipX = flip;
	}
}
