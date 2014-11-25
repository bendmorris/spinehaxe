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
import spinehaxe.attachments.Attachment;
import openfl.Vector;

class FfdTimeline extends CurveTimeline {
	public var slotIndex:Int;
	public var frames:Vector<Float>;
	public var frameVertices:Vector<Vector<Float>>;
	public var attachment:Attachment;

	public function new (frameCount:Int) {
		super(frameCount);
		frames = ArrayUtils.allocFloat(frameCount, true);
		frameVertices = new Vector<Vector<Float>>(frameCount, true);
	}

	/** Sets the time and value of the specified keyframe. */
	public function setFrame (frameIndex:Int, time:Float, vertices:Vector<Float>) : Void {
		frames[frameIndex] = time;
		frameVertices[frameIndex] = vertices;
	}

	override public function apply (skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float) : Void {
		var slot:Slot = skeleton.slots[slotIndex];
		if (slot.attachment != attachment) return;
		var frames:Vector<Float> = this.frames;
		if (time < frames[0]) 
		{
			return; // Time is before first frame.
		}
		
		var frameVertices:Vector<Vector<Float>> = this.frameVertices;
		var vertexCount:Int = frameVertices[0].length;
		var vertices:Vector<Float> = slot.attachmentVertices;
		if (vertices.length != vertexCount) alpha = 1; // Don't mix from uninitialized slot vertices.
		
		if (time >= frames[frames.length - 1]) { // Time is after last frame.
			var lastVertices:Vector<Float> = frameVertices[frames.length - 1];
			if (alpha < 1) {
				for (i in 0 ... vertexCount)
					vertices[i] += (lastVertices[i] - vertices[i]) * alpha;
			} else {
				for (i in 0 ... vertexCount)
					vertices[i] = lastVertices[i];
			}
			
			return;
		}
		
		// Interpolate between the previous frame and the current frame.
		var frameIndex:Int = Animation.binarySearch1(frames, time);
		var frameTime:Float = frames[frameIndex];
		var percent:Float = 1 - (time - frameTime) / (frames[frameIndex - 1] - frameTime);
		percent = getCurvePercent(frameIndex - 1, percent < 0 ? 0 : (percent > 1 ? 1 : percent));
		
		var prevVertices:Vector<Float> = frameVertices[frameIndex - 1];
		var nextVertices:Vector<Float> = frameVertices[frameIndex];

		var prev:Float;
		if (alpha < 1) {
			for (i in 0 ... vertexCount) {
				prev = prevVertices[i];
				vertices[i] += (prev + (nextVertices[i] - prev) * percent - vertices[i]) * alpha;
			}
		} else {
			for (i in 0 ... vertexCount) {
				prev = prevVertices[i];
				vertices[i] = prev + (nextVertices[i] - prev) * percent;
			}
		}
	}
}
