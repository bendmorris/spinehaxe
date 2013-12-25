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
package spinehaxe;

import spinehaxe.Exception;

class Bone {
	public var data:BoneData;
	public var parent:Bone;
	public var m00:Float;
	public var m01:Float;
	public var m10:Float;
	public var m11:Float;
	public var worldX:Float;
	public var worldY:Float;
	public var worldRotation:Float;
	public var worldScaleX:Float;
	public var worldScaleY:Float;

	static public var yDown:Bool;
	public var x:Float;
	public var y:Float;
	public var rotation:Float;
	public var scaleX:Float;
	public var scaleY:Float;
	/** @param parent May be null. */
	public function new(data:BoneData, parent:Bone) {
		if(data == null) 
			throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.parent = parent;
		setToSetupPose();
	}

	/** Computes the world SRT using the parent bone and the local SRT. */
	public function updateWorldTransform(flipX:Bool, flipY:Bool):Void {
		if(parent != null)  {
			worldX = x * parent.m00 + y * parent.m01 + parent.worldX;
			worldY = x * parent.m10 + y * parent.m11 + parent.worldY;
			if(data.inheritScale)  {
				worldScaleX = parent.worldScaleX * scaleX;
				worldScaleY = parent.worldScaleY * scaleY;
			}

			else  {
				worldScaleX = scaleX;
				worldScaleY = scaleY;
			}

			worldRotation = (data.inheritRotation) ? parent.worldRotation + rotation : rotation;
		}

		else  {
			worldX = (flipX) ? -x : x;
			worldY = ((flipY && Bone.yDown != flipY)) ? -y : y;
			worldScaleX = scaleX;
			worldScaleY = scaleY;
			worldRotation = rotation;
		}

		var radians:Float = worldRotation * (Math.PI / 180);
		var cos:Float = Math.cos(radians);
		var sin:Float = Math.sin(radians);
		m00 = cos * worldScaleX;
		m10 = sin * worldScaleX;
		m01 = -sin * worldScaleY;
		m11 = cos * worldScaleY;
		if(flipX)  {
			m00 = -m00;
			m01 = -m01;
		}
		if(flipY != yDown)  {
			m10 = -m10;
			m11 = -m11;
		}
	}

	public function setToSetupPose():Void {
		x = data.x;
		y = data.y;
		rotation = data.rotation;
		scaleX = data.scaleX;
		scaleY = data.scaleY;
	}

	public function toString():String {
		return data.name;
	}

}

