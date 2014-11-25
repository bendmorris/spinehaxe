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

class MeshAttachment extends Attachment {
	public var vertices:Vector<Float>;
	public var uvs:Vector<Float>;
	public var regionUVs:Vector<Float>;
	public var triangles:Vector<Int>;
	public var hullLength:Int = 0;
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

	public function updateUVs () : Void {
		var width:Float = regionU2 - regionU, height:Float = regionV2 - regionV;
		var n:Int = regionUVs.length;
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
		var bone:Bone = slot.bone;
		x += bone.worldX;
		y += bone.worldY;
		var m00:Float = bone.m00;
		var m01:Float = bone.m01;
		var m10:Float = bone.m10;
		var m11:Float = bone.m11;
		var vertices:Vector<Float> = this.vertices;
		var verticesCount:Int = vertices.length;
		if (slot.attachmentVertices.length == verticesCount) vertices = slot.attachmentVertices;
		var i = 0, ii = 0;
		while (i < verticesCount) {
			var vx:Float = vertices[i];
			var vy:Float = vertices[i + 1];
			worldVertices[ii] = vx * m00 + vy * m01 + x;
			worldVertices[ii + 1] = vx * m10 + vy * m11 + y;
			i += 2;
			ii += 2;
		}
	}
}
