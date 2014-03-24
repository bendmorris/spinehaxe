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
import haxe.ds.Vector;

/** Base class for frames that use an interpolation bezier curve. */class CurveTimeline implements Timeline {
	public var frameCount(get, never):Int;

	static inline var LINEAR:Float = 0;
	static inline var STEPPED:Float = -1;
	static inline var BEZIER_SEGMENTS:Int = 10;
	var curves:Vector<Float>;
	// dfx, dfy, ddfx, ddfy, dddfx, dddfy, ...
	public function new(frameCount:Int) {
		curves = ArrayUtils.allocFloat(frameCount*6);
	}

	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float):Void {
	}

	public function get_frameCount():Int {
		return cast(curves.length / 6);
	}

	public function setLinear(frameIndex:Int):Void {
		curves[frameIndex * 6] = LINEAR;
	}

	public function setStepped(frameIndex:Int):Void {
		curves[frameIndex * 6] = STEPPED;
	}

	/** Sets the control handle positions for an interpolation bezier curve used to transition from this keyframe to the next.
	 * cx1 and cx2 are from 0 to 1, representing the percent of time between the two keyframes. cy1 and cy2 are the percent of
	 * the difference between the keyframe's values. */	public function setCurve(frameIndex:Int, cx1:Float, cy1:Float, cx2:Float, cy2:Float):Void {
		var subdiv_step:Float = 1 / BEZIER_SEGMENTS;
		var subdiv_step2:Float = subdiv_step * subdiv_step;
		var subdiv_step3:Float = subdiv_step2 * subdiv_step;
		var pre1:Float = 3 * subdiv_step;
		var pre2:Float = 3 * subdiv_step2;
		var pre4:Float = 6 * subdiv_step2;
		var pre5:Float = 6 * subdiv_step3;
		var tmp1x:Float = -cx1 * 2 + cx2;
		var tmp1y:Float = -cy1 * 2 + cy2;
		var tmp2x:Float = (cx1 - cx2) * 3 + 1;
		var tmp2y:Float = (cy1 - cy2) * 3 + 1;
		var i:Int = frameIndex * 6;
		curves[i] = cx1 * pre1 + tmp1x * pre2 + tmp2x * subdiv_step3;
		curves[i + 1] = cy1 * pre1 + tmp1y * pre2 + tmp2y * subdiv_step3;
		curves[i + 2] = tmp1x * pre4 + tmp2x * pre5;
		curves[i + 3] = tmp1y * pre4 + tmp2y * pre5;
		curves[i + 4] = tmp2x * pre5;
		curves[i + 5] = tmp2y * pre5;
	}

	public function getCurvePercent(frameIndex:Int, percent:Float):Float {
		var curveIndex:Int = frameIndex * 6;
		var dfx:Float = curves[curveIndex];
		if(dfx == LINEAR) 
			return percent;
		if(dfx == STEPPED) 
			return 0;
		var dfy:Float = curves[curveIndex + 1];
		var ddfx:Float = curves[curveIndex + 2];
		var ddfy:Float = curves[curveIndex + 3];
		var dddfx:Float = curves[curveIndex + 4];
		var dddfy:Float = curves[curveIndex + 5];
		var x:Float = dfx;
		var y:Float = dfy;
		var i:Int = BEZIER_SEGMENTS - 2;
		while(true) {
			if(x >= percent)  {
				var prevX:Float = x - dfx;
				var prevY:Float = y - dfy;
				return prevY + (y - prevY) * (percent - prevX) / (x - prevX);
			}
			if(i == 0) 
				break;
			i--;
			dfx += ddfx;
			dfy += ddfy;
			ddfx += dddfx;
			ddfy += dddfy;
			x += dfx;
			y += dfy;
		}

		return y + (1 - y) * (percent - x) / (1 - x);
	}

}

