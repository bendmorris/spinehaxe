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
package spinehaxe;

import spinehaxe.Exception;
import haxe.ds.Vector;

class Bone {
	public static var yDown:Bool = false;

	public var data:BoneData;
	public var skeleton:Skeleton;
	public var parent:Bone;
	public var m00:Float = 0;
	public var m01:Float = 0;
	public var m10:Float = 0;
	public var m11:Float = 0;
	public var worldX:Float = 0;
	public var worldY:Float = 0;
	public var worldRotation:Float = 0;
	public var worldScaleX:Float = 0;
	public var worldScaleY:Float = 0;
	public var worldFlipX:Bool = false;
	public var worldFlipY:Bool = false;

	public var x:Float = 0;
	public var y:Float = 0;
	public var rotation:Float = 0;
	public var rotationIK:Float = 0;
	public var scaleX:Float = 0;
	public var scaleY:Float = 0;
	public var flipX:Bool = false;
	public var flipY:Bool = false;

	/** @param parent May be null. */
	public function new(data:BoneData, skeleton:Skeleton, parent:Bone) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		this.data = data;
		this.skeleton = skeleton;
		this.parent = parent;
		setToSetupPose();
	}

	/** Computes the world SRT using the parent bone and the local SRT. */
	public function updateWorldTransform():Void {
		if (parent != null) {
			worldX = x * parent.m00 + y * parent.m01 + parent.worldX;
			worldY = x * parent.m10 + y * parent.m11 + parent.worldY;
			if (data.inheritScale) {
				worldScaleX = parent.worldScaleX * scaleX;
				worldScaleY = parent.worldScaleY * scaleY;
			}
			else  {
				worldScaleX = scaleX;
				worldScaleY = scaleY;
			}

			worldRotation = (data.inheritRotation) ? parent.worldRotation + rotationIK : rotationIK;
			worldFlipX = parent.worldFlipX != flipX;
			worldFlipY = parent.worldFlipY != flipY;
		}
		else  {
			var skeletonFlipX:Bool = skeleton.flipX, skeletonFlipY:Bool = skeleton.flipY;
			worldX = skeletonFlipX ? -x : x;
			worldY = skeletonFlipY != yDown ? -y : y;
			worldScaleX = scaleX;
			worldScaleY = scaleY;
			worldRotation = rotationIK;
			worldFlipX = skeletonFlipX != flipX;
			worldFlipY = skeletonFlipY != flipY;
		}

		var radians:Float = worldRotation * (Math.PI / 180);
		var cos:Float = Math.cos(radians);
		var sin:Float = Math.sin(radians);

		if (worldFlipX) {
			m00 = -cos * worldScaleX;
			m01 = sin * worldScaleY;
		} else {
			m00 = cos * worldScaleX;
			m01 = -sin * worldScaleY;
		}
		if (worldFlipY != yDown) {
			m10 = -sin * worldScaleX;
			m11 = -cos * worldScaleY;
		} else {
			m10 = sin * worldScaleX;
			m11 = cos * worldScaleY;
		}
	}

	public function setToSetupPose():Void {
		x = data.x;
		y = data.y;
		rotation = data.rotation;
		rotationIK = rotation;
		scaleX = data.scaleX;
		scaleY = data.scaleY;
		flipX = data.flipX;
		flipY = data.flipY;
	}

	public function worldToLocal (world:Vector<Float>) : Void {
		var dx:Float = world[0] - worldX, dy:Float = world[1] - worldY;
		var m00:Float = m00, m10:Float = m10, m01:Float = m01, m11:Float = m11;
		if (worldFlipX != (worldFlipY != yDown)) {
			m00 = -m00;
			m11 = -m11;
		}
		var invDet:Float = 1 / (m00 * m11 - m01 * m10);
		world[0] = (dx * m00 * invDet - dy * m01 * invDet);
		world[1] = (dy * m11 * invDet - dx * m10 * invDet);
	}

	public function localToWorld (local:Vector<Float>) : Void {
		var localX:Float = local[0], localY:Float = local[1];
		local[0] = localX * m00 + localY * m01 + worldX;
		local[1] = localX * m10 + localY * m11 + worldY;
	}

	public function toString():String {
		return data.name;
	}

}

