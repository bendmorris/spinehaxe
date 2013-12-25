/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
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
 ******************************************************************************/

package spinehaxe.attachments;
import spinehaxe.atlas.TextureRegion;
import spinehaxe.Exception;
import spinehaxe.atlas.TextureAtlas;
import spinehaxe.ArrayUtils;
import haxe.ds.Vector;

class RegionAttachment extends Attachment {
    public static inline var X1 = 0;
    public static inline var Y1 = 1;
    public static inline var C1 = 2;
    public static inline var U1 = 3;
    public static inline var V1 = 4;
    public static inline var X2 = 5;
    public static inline var Y2 = 6;
    public static inline var C2 = 7;
    public static inline var U2 = 8;
    public static inline var V2 = 9;
    public static inline var X3 = 10;
    public static inline var Y3 = 11;
    public static inline var C3 = 12;
    public static inline var U3 = 13;
    public static inline var V3 = 14;
    public static inline var X4 = 15;
    public static inline var Y4 = 16;
    public static inline var C4 = 17;
    public static inline var U4 = 18;
    public static inline var V4 = 19;

    public var region:TextureRegion;
    public var x:Float = 0;
    public var y:Float = 0;
    public var scaleX:Float = 1;
    public var scaleY:Float = 1;
    public var rotation:Float = 0;
    public var width:Float = 0;
    public var height:Float = 0;
    public var vertices:Vector<Float>;
    public var offset:Vector<Float>;

	public function new (name:String) {
		super(name);
        vertices = ArrayUtils.allocFloat(20);
        offset = ArrayUtils.allocFloat(8);
	}

	public function updateOffset ():Void {
		var localX2:Float = width / 2;
		var localY2:Float = height / 2;
		var localX:Float = -localX2;
		var localY:Float = -localY2;
		if (Std.is(region, AtlasRegion)) {
			var region:AtlasRegion = cast(this.region, AtlasRegion);
			if (region.rotate) {
				localX += region.offsetX / region.originalWidth * height;
				localY += region.offsetY / region.originalHeight * width;
				localX2 -= (region.originalWidth - region.offsetX - region.packedHeight) / region.originalWidth * height;
				localY2 -= (region.originalHeight - region.offsetY - region.packedWidth) / region.originalHeight * width;
			} else {
                localX += region.offsetX / region.originalWidth * width;
				localY += region.offsetY / region.originalHeight * height;
				localX2 -= (region.originalWidth - region.offsetX - region.packedWidth) / region.originalWidth * width;
				localY2 -= (region.originalHeight - region.offsetY - region.packedHeight) / region.originalHeight * height;
            }
        }
		localX *= scaleX;
		localY *= scaleY;
		localX2 *= scaleX;
		localY2 *= scaleY;
		var rotation:Float = MathUtils.degToRad(rotation);
		var cos:Float = Math.cos(rotation);
		var sin:Float = Math.sin(rotation);
		var localXCos:Float = localX * cos + x;
		var localXSin:Float = localX * sin;
		var localYCos:Float = localY * cos + y;
		var localYSin:Float = localY * sin;
		var localX2Cos:Float = localX2 * cos + x;
		var localX2Sin:Float = localX2 * sin;
		var localY2Cos:Float = localY2 * cos + y;
		var localY2Sin:Float = localY2 * sin;
		offset[0] = localXCos - localYSin;
		offset[1] = localYCos + localXSin;
		offset[2] = localXCos - localY2Sin;
		offset[3] = localY2Cos + localXSin;
		offset[4] = localX2Cos - localY2Sin;
		offset[5] = localY2Cos + localX2Sin;
		offset[6] = localX2Cos - localYSin;
		offset[7] = localYCos + localX2Sin;
	}

	public function setRegion (region:TextureRegion):Void {
		if (region == null) throw new IllegalArgumentException("region cannot be null.");
		this.region = region;
		if (Std.is(region, AtlasRegion) && (cast(region,AtlasRegion)).rotate) {
			vertices[U2] = region.u;
			vertices[V2] = region.v2;
			vertices[U3] = region.u;
			vertices[V3] = region.v;
			vertices[U4] = region.u2;
			vertices[V4] = region.v;
			vertices[U1] = region.u2;
			vertices[V1] = region.v2;
		} else {
			vertices[U1] = region.u;
			vertices[V1] = region.v2;
			vertices[U2] = region.u;
			vertices[V2] = region.v;
			vertices[U3] = region.u2;
			vertices[V3] = region.v;
			vertices[U4] = region.u2;
			vertices[V4] = region.v2;
		}
		updateOffset();
	}

	public function updateVertices (slot:Slot):Void {
		var skeleton:Skeleton = slot.skeleton;
		/*var skeletonColor:Color = skeleton.color;
		var slotColor:Color = slot.color;
		var color:Float = NumberUtils.intToFloatColor( //
			(Math.floor(255 * skeletonColor.a * slotColor.a) << 24) //
				| (Math.floor(255 * skeletonColor.b * slotColor.b) << 16) //
				| (Math.floor(255 * skeletonColor.g * slotColor.g) << 8) //
				| (Math.floor(255 * skeletonColor.r * slotColor.r)));*/
		var color:Float = 1;
		vertices[C1] = color;
		vertices[C2] = color;
		vertices[C3] = color;
		vertices[C4] = color;

		var bone:Bone = slot.bone;
		var x:Float = bone.worldX + skeleton.x;
		var y:Float = bone.worldY + skeleton.y;
		var m00:Float = bone.m00;
		var m01:Float = bone.m01;
		var m10:Float = bone.m10;
		var m11:Float = bone.m11;
		vertices[X1] = offset[0] * m00 + offset[1] * m01 + x;
		vertices[Y1] = offset[0] * m10 + offset[1] * m11 + y;
		vertices[X2] = offset[2] * m00 + offset[3] * m01 + x;
		vertices[Y2] = offset[2] * m10 + offset[3] * m11 + y;
		vertices[X3] = offset[4] * m00 + offset[5] * m01 + x;
		vertices[Y3] = offset[4] * m10 + offset[5] * m11 + y;
		vertices[X4] = offset[6] * m00 + offset[7] * m01 + x;
		vertices[Y4] = offset[6] * m10 + offset[7] * m11 + y;
	}
}

class NumberUtils {
    public static function intToFloatColor(value:Int):Float {
        return value;//TODO
    }
}

