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
import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.VertexAttachment;
import spinehaxe.Event;
import spinehaxe.Skeleton;
import spinehaxe.Slot;

class DeformTimeline extends CurveTimeline {
	public var slotIndex:Int;
	public var frames:Vector<Float>;
	public var frameVertices:Vector<Array<Float>>;
	public var attachment:VertexAttachment;

	public function new(frameCount:Int) {
		super(frameCount);
		frames = ArrayUtils.allocFloat(frameCount);
		frameVertices = new Vector<Array<Float>>(frameCount);
	}
	
	override public function getPropertyId():Int {
		return (TimelineType.deform << 24) + slotIndex;
	}

	/** Sets the time and value of the specified keyframe. */
	public function setFrame(frameIndex:Int, time:Float, vertices:Array<Float>):Void {
		frames[frameIndex] = time;
		frameVertices[frameIndex] = vertices;
	}

	override public function apply (skeleton:Skeleton, lastTime:Float, time:Float, firedEvents:Array<Event>, alpha:Float, setupPose:Bool, mixingOut:Bool):Void {
		var slot:Slot = skeleton.slots[slotIndex];
		var slotAttachment:Attachment = slot.attachment;
		if (!Std.is(slotAttachment, VertexAttachment) || !(cast(slotAttachment, VertexAttachment).applyDeform(attachment))) return;

		var verticesArray:Array<Float> = slot.attachmentVertices;
		if (time < frames[0]) {
			if (setupPose) ArrayUtils.clearArray(verticesArray);
			return;
		}

		var frameVertices:Vector<Array<Float>> = this.frameVertices;
		var vertexCount:Int = frameVertices[0].length;
		
		if (verticesArray.length != vertexCount) alpha = 1; // Don't mix from uninitialized slot vertices.
		ArrayUtils.setLength(verticesArray, vertexCount);
		var vertices:Array<Float> = verticesArray;

		var i:Int, n:Int;
		var vertexAttachment:VertexAttachment;
		var setupVertices:Array<Float>;
		var setup:Float, prev:Float;
		if (time >= frames[frames.length - 1]) { // Time is after last frame.
			var lastVertices:Array<Float> = frameVertices[frames.length - 1];
			if (alpha == 1) {
				// Vertex positions or deform offsets, no alpha.
				for (i in 0 ... vertexCount)
					vertices[i] = lastVertices[i];
			} else if (setupPose) {
				vertexAttachment = cast slotAttachment;
				if (vertexAttachment.bones == null) {
					// Unweighted vertex positions, with alpha.
					setupVertices = vertexAttachment.vertices;
					for (i in 0 ... vertexCount) {
						setup = setupVertices[i];
						vertices[i] = setup + (lastVertices[i] - setup) * alpha;
					}
				} else {
					// Weighted deform offsets, with alpha.
					for (i in 0 ... vertexCount)
						vertices[i] = lastVertices[i] * alpha;
				}
			} else {
				// Vertex positions or deform offsets, with alpha.
				for (i in 0 ... vertexCount)
					vertices[i] += (lastVertices[i] - vertices[i]) * alpha;
			}
			return;
		}

		// Interpolate between the previous frame and the current frame.
		var frame:Int = Animation.binarySearch1(frames, time);
		var prevVertices:Array<Float> = frameVertices[frame - 1];
		var nextVertices:Array<Float> = frameVertices[frame];
		var frameTime:Float = frames[frame];
		var percent:Float = getCurvePercent(frame - 1, 1 - (time - frameTime) / (frames[frame - 1] - frameTime));

		if (alpha == 1) {
			// Vertex positions or deform offsets, no alpha.
			for (i in 0 ... vertexCount) {
				prev = prevVertices[i];
				vertices[i] = prev + (nextVertices[i] - prev) * percent;
			}
		} else if (setupPose) {
			vertexAttachment = cast slotAttachment;
			if (vertexAttachment.bones == null) {
				// Unweighted vertex positions, with alpha.
				setupVertices = vertexAttachment.vertices;
				for (i in 0 ... vertexCount) {
					prev = prevVertices[i];
					setup = setupVertices[i];
					vertices[i] = setup + (prev + (nextVertices[i] - prev) * percent - setup) * alpha;
				}
			} else {
				// Weighted deform offsets, with alpha.
				for (i in 0 ... vertexCount) {
					prev = prevVertices[i];
					vertices[i] = (prev + (nextVertices[i] - prev) * percent) * alpha;
				}
			}
		} else {
			// Vertex positions or deform offsets, with alpha.
			for (i in 0 ... vertexCount) {
				prev = prevVertices[i];
				vertices[i] += (prev + (nextVertices[i] - prev) * percent - vertices[i]) * alpha;
			}
		}
	}
}
