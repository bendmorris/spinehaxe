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

package spinehaxe.attachments;

import spinehaxe.Bone;
import spinehaxe.Skeleton;
import spinehaxe.Slot;

class VertexAttachment extends Attachment {
	public var bones:Array<Int>;
	public var vertices:Array<Float>;
	public var worldVerticesLength:Int;

	public function new(name:String) {
		super(name);
	}

	public function computeWorldVertices(slot:Slot, worldVertices:Array<Float>):Void {
		computeWorldVertices2(slot, 0, worldVerticesLength, worldVertices, 0);
	}

	/** Transforms local vertices to world coordinates.
	 * @param start The index of the first local vertex value to transform. Each vertex has 2 values, x and y.
	 * @param count The number of world vertex values to output. Must be <= {@link #getWorldVerticesLength()} - start.
	 * @param worldVertices The output world vertices. Must have a length >= offset + count.
	 * @param offset The worldVertices index to begin writing values. */
	public function computeWorldVertices2(slot:Slot, start:Int, count:Int, worldVertices:Array<Float>, offset:Int):Void {
		count += offset;
		var skeleton:Skeleton = slot.skeleton;
		var deformArray:Array<Float> = slot.attachmentVertices;
		var vertices:Array<Float> = this.vertices;
		var bones:Array<Int> = this.bones;
		var deform:Array<Float>;

		var v:Int, w:Int, n:Int, i:Int, skip:Int, b:Int, f:Int;
		var vx:Float, vy:Float;
		var wx:Float, wy:Float;
		var bone:Bone;

		if (bones == null) {
			if (deformArray.length > 0) vertices = deformArray;
			bone = slot.bone;
			var x:Float = bone.worldX;
			var y:Float = bone.worldY;
			var a:Float = bone.a, bb:Float = bone.b, c:Float = bone.c, d:Float = bone.d;
			v = start;
			w = offset;
			while (w < count) {
				vx = vertices[v];
				vy = vertices[v + 1];
				worldVertices[w] = vx * a + vy * bb + x;
				worldVertices[w + 1] = vx * c + vy * d + y;
				v += 2;
				w += 2;
			}
			return;
		}
		v = 0;
		skip = 0;
		i = 0;
		while (i < start) {
			n = bones[v];
			v += n + 1;
			skip += n;
			i += 2;
		}
		var skeletonBones:Array<Bone> = skeleton.bones;
		if (deformArray.length == 0) {
			w = offset;
			b = skip * 3;
			while (w < count) {
				wx = 0;
				wy = 0;
				n = bones[v++];
				n += v;
				while (v < n) {
					bone = skeletonBones[bones[v]];
					vx = vertices[b]; vy = vertices[b + 1];
					var weight:Float = vertices[b + 2];
					wx += (vx * bone.a + vy * bone.b + bone.worldX) * weight;
					wy += (vx * bone.c + vy * bone.d + bone.worldY) * weight;
					v++;
					b += 3;
				}
				worldVertices[w] = wx;
				worldVertices[w + 1] = wy;
				w += 2;
			}
		} else {
			deform = deformArray;
			w = offset;
			b = skip * 3;
			f = skip << 1;
			while (w < count) {
				wx = 0; wy = 0;
				n = bones[v++];
				n += v;
				while (v < n) {
					bone = skeletonBones[bones[v]];
					vx = vertices[b] + deform[f];
					vy = vertices[b + 1] + deform[f + 1];
					var weight:Float = vertices[b + 2];
					wx += (vx * bone.a + vy * bone.b + bone.worldX) * weight;
					wy += (vx * bone.c + vy * bone.d + bone.worldY) * weight;
					v++;
					b += 3;
					f += 2;
				}
				worldVertices[w] = wx;
				worldVertices[w + 1] = wy;
				w += 2;
			}
		}
	}

	/** Returns true if a deform originally applied to the specified attachment should be applied to this attachment. */
	public function applyDeform (sourceAttachment:VertexAttachment):Bool {
		return this == sourceAttachment;
	}
}
