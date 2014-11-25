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

import spinehaxe.Bone;
import openfl.Vector;

class RegionAttachment extends Attachment implements Dynamic<Dynamic> {
	public static inline var X1:Int = 0;
	public static inline var Y1:Int = 1;
	public static inline var X2:Int = 2;
	public static inline var Y2:Int = 3;
	public static inline var X3:Int = 4;
	public static inline var Y3:Int = 5;
	public static inline var X4:Int = 6;
	public static inline var Y4:Int = 7;

	public var x:Float = 0;
	public var y:Float = 0;
	public var scaleX:Float = 1;
	public var scaleY:Float = 1;
	public var rotation:Float = 0;
	public var width:Float = 0;
	public var height:Float = 0;
	public var r:Float = 1;
	public var g:Float = 1;
	public var b:Float = 1;
	public var a:Float = 1;

	public var path:String;
	public var rendererObject:Dynamic;
	public var regionOffsetX:Float = 0; // Pixels stripped from the bottom left, unrotated.
	public var regionOffsetY:Float = 0;
	public var regionWidth:Float = 0; // Unrotated, stripped size.
	public var regionHeight:Float = 0;
	public var regionOriginalWidth:Float = 0; // Unrotated, unstripped size.
	public var regionOriginalHeight:Float = 0;

	public var offset:Vector<Float>;
	public var uvs:Vector<Float>;

	public function new (name:String) {
		super(name);
		offset = ArrayUtils.allocFloat(8);
		uvs = ArrayUtils.allocFloat(8);
	}

	public function setUVs (u:Float, v:Float, u2:Float, v2:Float, rotate:Bool) : Void {
		if (rotate) {
			uvs[X2] = u;
			uvs[Y2] = v2;
			uvs[X3] = u;
			uvs[Y3] = v;
			uvs[X4] = u2;
			uvs[Y4] = v;
			uvs[X1] = u2;
			uvs[Y1] = v2;
		} else {
			uvs[X1] = u;
			uvs[Y1] = v2;
			uvs[X2] = u;
			uvs[Y2] = v;
			uvs[X3] = u2;
			uvs[Y3] = v;
			uvs[X4] = u2;
			uvs[Y4] = v2;
		}
	}

	public function updateOffset () : Void {
		var regionScaleX:Float = width / regionOriginalWidth * scaleX;
		var regionScaleY:Float = height / regionOriginalHeight * scaleY;
		var localX:Float = -width / 2 * scaleX + regionOffsetX * regionScaleX;
		var localY:Float = -height / 2 * scaleY + regionOffsetY * regionScaleY;
		var localX2:Float = localX + regionWidth * regionScaleX;
		var localY2:Float = localY + regionHeight * regionScaleY;
		var radians:Float = rotation * Math.PI / 180;
		var cos:Float = Math.cos(radians);
		var sin:Float = Math.sin(radians);
		var localXCos:Float = localX * cos + x;
		var localXSin:Float = localX * sin;
		var localYCos:Float = localY * cos + y;
		var localYSin:Float = localY * sin;
		var localX2Cos:Float = localX2 * cos + x;
		var localX2Sin:Float = localX2 * sin;
		var localY2Cos:Float = localY2 * cos + y;
		var localY2Sin:Float = localY2 * sin;
		offset[X1] = localXCos - localYSin;
		offset[Y1] = localYCos + localXSin;
		offset[X2] = localXCos - localY2Sin;
		offset[Y2] = localY2Cos + localXSin;
		offset[X3] = localX2Cos - localY2Sin;
		offset[Y3] = localY2Cos + localX2Sin;
		offset[X4] = localX2Cos - localYSin;
		offset[Y4] = localYCos + localX2Sin;
	}

	public function computeWorldVertices (x:Float, y:Float, bone:Bone, worldVertices:Vector<Float>) : Void {
		x += bone.worldX;
		y += bone.worldY;
		var m00:Float = bone.m00;
		var m01:Float = bone.m01;
		var m10:Float = bone.m10;
		var m11:Float = bone.m11;
		var x1:Float = offset[X1];
		var y1:Float = offset[Y1];
		var x2:Float = offset[X2];
		var y2:Float = offset[Y2];
		var x3:Float = offset[X3];
		var y3:Float = offset[Y3];
		var x4:Float = offset[X4];
		var y4:Float = offset[Y4];
		
		worldVertices[X1] = x1 * m00 + y1 * m01 + x;
		worldVertices[Y1] = x1 * m10 + y1 * m11 + y;
		worldVertices[X2] = x2 * m00 + y2 * m01 + x;
		worldVertices[Y2] = x2 * m10 + y2 * m11 + y;
		worldVertices[X3] = x3 * m00 + y3 * m01 + x;
		worldVertices[Y3] = x3 * m10 + y3 * m11 + y;
		worldVertices[X4] = x4 * m00 + y4 * m01 + x;
		worldVertices[Y4] = x4 * m10 + y4 * m11 + y;
	}
}
