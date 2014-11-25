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
import openfl.Vector;

/** Base class for frames that use an interpolation bezier curve. */
class CurveTimeline implements Timeline {
	static inline var LINEAR:Int = 0;
	static inline var STEPPED:Int = 1;
	static inline var BEZIER:Int = 2;
	static inline var BEZIER_SEGMENTS:Int = 10;
	static inline var BEZIER_SIZE:Int = BEZIER_SEGMENTS * 2 - 1;
	
	public var frameCount(get, never):Int;
	
	var curves:Vector<Float>; // type, x, y, ...

	public function new(frameCount:Int) {
		curves = ArrayUtils.allocFloat((frameCount - 1) * BEZIER_SIZE, true);
	}

	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
	}

	public function get_frameCount():Int {
		return Std.int(curves.length / BEZIER_SIZE + 1);
	}

	public function setLinear(frameIndex:Int):Void {
		curves[frameIndex * BEZIER_SIZE] = LINEAR;
	}

	public function setStepped(frameIndex:Int):Void {
		curves[frameIndex * BEZIER_SIZE] = STEPPED;
	}

	/** Sets the control handle positions for an interpolation bezier curve used to transition from this keyframe to the next.
	 * cx1 and cx2 are from 0 to 1, representing the percent of time between the two keyframes. cy1 and cy2 are the percent of
	 * the difference between the keyframe's values. */
	public function setCurve(frameIndex:Int, cx1:Float, cy1:Float, cx2:Float, cy2:Float):Void {
		var subdiv1:Float = 1 / BEZIER_SEGMENTS, subdiv2:Float = subdiv1 * subdiv1, subdiv3:Float = subdiv2 * subdiv1;
		var pre1:Float = 3 * subdiv1, pre2:Float = 3 * subdiv2, pre4:Float = 6 * subdiv2, pre5:Float = 6 * subdiv3;
		var tmp1x:Float = -cx1 * 2 + cx2, tmp1y:Float = -cy1 * 2 + cy2, tmp2x:Float = (cx1 - cx2) * 3 + 1, tmp2y:Float = (cy1 - cy2) * 3 + 1;
		var dfx:Float = cx1 * pre1 + tmp1x * pre2 + tmp2x * subdiv3, dfy:Float = cy1 * pre1 + tmp1y * pre2 + tmp2y * subdiv3;
		var ddfx:Float = tmp1x * pre4 + tmp2x * pre5, ddfy:Float = tmp1y * pre4 + tmp2y * pre5;
		var dddfx:Float = tmp2x * pre5, dddfy:Float = tmp2y * pre5;
		var i:Int = frameIndex * BEZIER_SIZE;
		var curves:Vector<Float> = this.curves;
		curves[i++] = BEZIER;

		var x:Float = dfx, y:Float = dfy;
		var n:Int = i + BEZIER_SIZE - 1;
		while (i < n) {
			curves[i] = x;
			curves[i + 1] = y;
			dfx += ddfx;
			dfy += ddfy;
			ddfx += dddfx;
			ddfy += dddfy;
			x += dfx;
			y += dfy;
			i += 2;
		}
	}

	public function getCurvePercent (frameIndex:Int, percent:Float):Float {
		var curves:Vector<Float> = this.curves;
		var i:Int = frameIndex * BEZIER_SIZE;
		var type:Float = curves[i];
		if (type == LINEAR) return percent;
		if (type == STEPPED) return 0;
		i++;
		var x:Float = 0;
		var start:Int = i, n:Int = i + BEZIER_SIZE - 1;
		while (i < n) {
			x = curves[i];
			if (x >= percent) {
				var prevX:Float, prevY:Float;
				if (i == start) {
					prevX = 0;
					prevY = 0;
				} else {
					prevX = curves[i - 2];
					prevY = curves[i - 1];
				}
				return prevY + (curves[i + 1] - prevY) * (percent - prevX) / (x - prevX);
			}
			i += 2;
		}
		var y:Float = curves[i - 1];
		return y + (1 - y) * (percent - x) / (1 - x); // Last point is 1,1.
	}
}
