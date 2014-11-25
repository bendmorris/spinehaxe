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

package spinehaxe.attachments;

import spinehaxe.Slot;
import spinehaxe.Bone;
import openfl.Vector;

class SkinnedMeshAttachment extends Attachment implements Dynamic<Dynamic> {
	public var bones:Array<Int>;
	public var weights:Array<Float>;
	public var uvs:Vector<Float>;
	public var regionUVs:Vector<Float>;
	public var triangles:Vector<Int>;
	public var hullLength:Int;
	public var r:Float = 1;
	public var g:Float = 1;
	public var b:Float = 1;
	public var a:Float = 1;

	public var path:String;
	public var rendererObject:Dynamic;
	public var regionU:Float = 0;
	public var regionV:Float = 0;
	public var regionU2:Float = 0;
	public var regionV2:Float = 0;
	public var regionRotate:Bool = false;
	public var regionOffsetX:Float = 0; // Pixels stripped from the bottom left, unrotated.
	public var regionOffsetY:Float = 0;
	public var regionWidth:Float = 0; // Unrotated, stripped size.
	public var regionHeight:Float = 0;
	public var regionOriginalWidth:Float = 0; // Unrotated, unstripped size.
	public var regionOriginalHeight:Float = 0;

	// Nonessential.
	public var edges:Array<Int>;
	public var width:Float = 0;
	public var height:Float = 0;

	public function new (name:String) {
		super(name);
	}

	public function updateUVs() : Void {
		var width:Float = regionU2 - regionU, height:Float = regionV2 - regionV;
		var i:Int, n:Int = regionUVs.length;
		if (uvs == null || uvs.length != n) uvs = ArrayUtils.allocFloat(n, true);
		if (regionRotate) {
			var i = 0;
			while (i < n) {
				uvs[i] = regionU + regionUVs[i + 1] * width;
				uvs[i + 1] = regionV + height - regionUVs[i] * height;
				i += 2;
			}
		} else {
			var i = 0;
			while (i < n) {
				uvs[i] = regionU + regionUVs[i] * width;
				uvs[i + 1] = regionV + regionUVs[i + 1] * height;
				i += 2;
			}
		}
	}

	public function computeWorldVertices (x:Float, y:Float, slot:Slot, worldVertices:Vector<Float>) : Void {
		var skeletonBones:Array<Bone> = slot.skeleton.bones;
		var weights:Array<Float> = this.weights;
		var bones:Array<Int> = this.bones;
		
		var w:Int = 0, v:Int = 0, b:Int = 0, f:Int = 0, n:Int = bones.length, nn:Int = 0;
		var wx:Float = 0, wy:Float = 0, bone:Bone, vx:Float = 0, vy:Float = 0, weight:Float = 0;
		if (slot.attachmentVertices.length == 0) {
			while (v < n) {
				wx = 0;
				wy = 0;
				nn = bones[v++] + v;
				while (v < nn) {
					bone = skeletonBones[bones[v]];
					vx = weights[b];
					vy = weights[b + 1];
					weight = weights[b + 2];
					wx += (vx * bone.m00 + vy * bone.m01 + bone.worldX) * weight;
					wy += (vx * bone.m10 + vy * bone.m11 + bone.worldY) * weight;
					v++;
					b += 3;
				}
				worldVertices[w] = wx + x;
				worldVertices[w + 1] = wy + y;
				w += 2;
			}
		} else {
			var ffd:Vector<Float> = slot.attachmentVertices;
			while (v < n) {
				wx = 0;
				wy = 0;
				nn = bones[v++] + v;
				while (v < nn) {
					bone = skeletonBones[bones[v]];
					vx = weights[b] + ffd[f];
					vy = weights[b + 1] + ffd[f + 1];
					weight = weights[b + 2];
					wx += (vx * bone.m00 + vy * bone.m01 + bone.worldX) * weight;
					wy += (vx * bone.m10 + vy * bone.m11 + bone.worldY) * weight;
					v++;
					b += 3;
					f += 2;
				}
				worldVertices[w] = wx + x;
				worldVertices[w + 1] = wy + y;
				w += 2;
			}
		}
	}
}
