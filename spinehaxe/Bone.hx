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
import spinehaxe.Skeleton;


class Bone {
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
	public var worldFlipX:Bool;
	public var worldFlipY:Bool;

	static public var yDown:Bool = false;
	public var x:Float = 0;
	public var y:Float = 0;
	public var rotation:Float = 0;
	public var rotationIK:Float = 0;
	public var scaleX:Float = 0;
	public var scaleY:Float = 0;
	public var flipX:Bool;
	public var flipY:Bool;

	/** @param parent May be null. */
	public function new(data:BoneData, parent:Bone) {
		if (data == null)
			throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.parent = parent;
		setToSetupPose();
	}

    /** Computes the world SRT using the parent bone and the local SRT. */
    public function updateWorldTransform(flipX:Bool, flipY:Bool):Void {
        var skeleton:Skeleton = this.skeleton;
        var parent:Bone = this.parent;
        var x:Float = this.x;
        var y:Float = this.y;
        if (parent != null) {
            worldX = x * parent.m00 + y * parent.m01 + parent.worldX;
            worldY = x * parent.m10 + y * parent.m11 + parent.worldY;
            if (data.inheritScale) {
                worldScaleX = parent.worldScaleX * scaleX;
                worldScaleY = parent.worldScaleY * scaleY;
            } else  {
                worldScaleX = scaleX;
                worldScaleY = scaleY;
            }

            worldRotation = (data.inheritRotation) ? parent.worldRotation + rotation : rotation;
        }

        else  {
            worldX = flipX ? -x : x;
            worldY = flipY != yDown ? -y : y;
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
        if (flipX) {
            m00 = -m00;
            m01 = -m01;
        }
        if (flipY != yDown) {
            m10 = -m10;
            m11 = -m11;
        }
    }

	/** Computes the world SRT using the parent bone and the local SRT. */
	//public function updateWorldTransform(flipX:Bool, flipY:Bool):Void {
        //var skeleton:Skeleton = this.skeleton;
		//var parent:Bone = this.parent;
        //var x:Float = this.x;
        //var y:Float = this.y;
		//if (parent != null) {
			//worldX = x * parent.m00 + y * parent.m01 + parent.worldX;
			//worldY = x * parent.m10 + y * parent.m11 + parent.worldY;
			//if (data.inheritScale) {
				//worldScaleX = parent.worldScaleX * scaleX;
				//worldScaleY = parent.worldScaleY * scaleY;
			//} else  {
				//worldScaleX = scaleX;
				//worldScaleY = scaleY;
			//}

			//worldRotation = data.inheritRotation ? parent.worldRotation + rotationIK : rotationIK;
            ////TODO:[Yura] create parent flip
			////worldFlipX = parent.worldFlipX ^ flipX;
			////worldFlipY = parent.worldFlipY ^ flipY;
		//}

		//else  {
			//worldX = flipX ? -x : x;
			//worldY = flipY != yDown ? -y : y;
			//worldScaleX = scaleX;
			//worldScaleY = scaleY;
			//worldRotation = rotationIK;
            ////TODO:[Yura] create parent flip
			////worldFlipX = skeletonFlipX ^ flipX;
			////worldFlipY = skeletonFlipY ^ flipY;
		//}

		//var radians:Float = worldRotation * (Math.PI / 180);
		//var cos:Float = Math.cos(radians);
		//var sin:Float = Math.sin(radians);
        ////TODO:[Yura] remove yDown!!!
        //if (skeleton.flipX) {
            //m00 = -cos * worldScaleX;
            //m01 = sin * worldScaleY;
        //} else {
            //m00 = cos * worldScaleX;
            //m01 = -sin * worldScaleY;
        //}
        //if (skeleton.flipY != yDown) {
            //m10 = -sin * worldScaleX;
            //m11 = -cos * worldScaleY;
        //} else {
            //m10 = sin * worldScaleX;
            //m11 = cos * worldScaleY;
        //}
	//}

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

