/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *	list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *	this list of conditions and the following disclaimer in the documentation
 *	and/or other materials provided with the distribution.
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

package spinehaxe.platform.nme.renderers;

import spinehaxe.atlas.TextureAtlas.AtlasRegion;
import spinehaxe.atlas.TextureRegion;
import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.RegionAttachment;
import flash.display.Sprite;
import flash.display.BitmapData;
import flash.display.Bitmap;
import flash.display.TriangleCulling;
import flash.geom.Rectangle;
import flash.geom.Point;
import flash.Vector;

import haxe.ds.ObjectMap;

class SkeletonRenderer extends Sprite {
	var skeleton:Skeleton;

	#if (flash || cpp || neko)
	var vs:Vector<Float>;
	var idx:Vector<Int>;
	var uvt:Vector<Float>;
	var bd:BitmapData;
	var filled:Bool = false;

	public function new (skeleton:Skeleton) {
		super();
		this.skeleton = skeleton;

		vs = new Vector<Float>();
		idx = new Vector<Int>();
		uvt = new Vector<Float>();
	}

	public function clearBuffers () {

		vs = new Vector<Float>();
		idx = new Vector<Int>();
		uvt = new Vector<Float>();
		filled = false;
	}

	public function draw () {
		var vi:Int = 0;
		var vii:Int = 0;
		var ii:Int = 0;
		graphics.clear();
		var drawOrder:Array<Slot> = skeleton.drawOrder;
		for (slot in drawOrder) {
			var attachment:Attachment = slot.attachment;
			if (Std.is(attachment, RegionAttachment)) {
				var regionAttachment:RegionAttachment = cast(attachment, RegionAttachment);
				regionAttachment.updateVertices(slot);
				var vertices = regionAttachment.getVertices();
				var region:TextureRegion = regionAttachment.getRegion();
				var texture:BitmapDataTexture = cast(region.getTexture(), BitmapDataTexture);
				if (bd == null) {
					bd = texture.bd;
				} else if (bd!=texture.bd) {
					throw ("Too many textures");
					continue;
				}

				vs[vi+0] = vertices[RegionAttachment.X1]; vs[vi+1] = vertices[RegionAttachment.Y1];
				vs[vi+2] = vertices[RegionAttachment.X2]; vs[vi+3] = vertices[RegionAttachment.Y2];
				vs[vi+4] = vertices[RegionAttachment.X3]; vs[vi+5] = vertices[RegionAttachment.Y3];
				vs[vi+6] = vertices[RegionAttachment.X4]; vs[vi+7] = vertices[RegionAttachment.Y4];

				if (!filled) {
					idx[ii+0] = vii+0; idx[ii+1] = vii+1; idx[ii+2] = vii+2;
					idx[ii+3] = vii+2; idx[ii+4] = vii+3; idx[ii+5] = vii+0;

					uvt[vi+0] = vertices[RegionAttachment.U1]; uvt[vi+1] = vertices[RegionAttachment.V1];
					uvt[vi+2] = vertices[RegionAttachment.U2]; uvt[vi+3] = vertices[RegionAttachment.V2];
					uvt[vi+4] = vertices[RegionAttachment.U3]; uvt[vi+5] = vertices[RegionAttachment.V3];
					uvt[vi+6] = vertices[RegionAttachment.U4]; uvt[vi+7] = vertices[RegionAttachment.V4];
				}
				vi += 8;
				vii += 4;
				ii += 6;
			}
		}
		filled = true;
		if (bd != null) {
			graphics.beginBitmapFill(bd, null, true, true);
			graphics.drawTriangles(vs, idx, uvt, TriangleCulling.NONE);
			graphics.endFill();
		}
	 }

	#else

	public var sprites:ObjectMap<RegionAttachment, Sprite> ;

	public function new (skeleton:Skeleton) {
		super();
		this.skeleton = skeleton;
		sprites = new ObjectMap<RegionAttachment, Sprite>();
	}

	public function clearBuffers () {
		for (s in sprites)s.visible = false;
	}

	// TODO fix flipx
	public function draw () {
		graphics.clear();
		var drawOrder:Array<Slot> = skeleton.drawOrder;
		var flipX:Int = (skeleton.flipX) ? -1 : 1;
		var flipY:Int = (skeleton.flipY) ? 1 : -1;
		var flip:Int = flipX * flipY;
		var skeletonX:Float = skeleton.getX();
		var skeletonY:Float = skeleton.getY();
		for (slot in drawOrder) {
			var attachment:Attachment = slot.attachment;
			if (Std.is(attachment, RegionAttachment)) {
				var regionAttachment:RegionAttachment = cast(attachment, RegionAttachment);
				regionAttachment.updateVertices(slot);
				var vertices = regionAttachment.getVertices();

				var wrapper:Sprite = get(regionAttachment);

				var region:AtlasRegion = cast regionAttachment.getRegion();
				var bone:Bone = slot.getBone();
				var x:Float = regionAttachment.x - region.offsetX;
				var y:Float = regionAttachment.y - region.offsetY;
				wrapper.x = skeletonX + bone.worldX + x * bone.m00 + y * bone.m01;
				wrapper.y = skeletonY + bone.worldY + x * bone.m10 + y * bone.m11;
				wrapper.rotation = -(bone.worldRotation + regionAttachment.rotation) * flip;
				wrapper.scaleX = (bone.worldScaleX + regionAttachment.scaleX - 1) * flipX;
				wrapper.scaleY = (bone.worldScaleY + regionAttachment.scaleY - 1) * flipY;

				wrapper.visible = true;
			}
		}
	}

	public function get (regionAttachment:RegionAttachment):Sprite {
		var wrapper:Sprite = sprites.get(regionAttachment);
		if (wrapper == null) {
			var region:AtlasRegion = cast regionAttachment.getRegion();
			var texture:BitmapDataTexture = cast(region.getTexture(), BitmapDataTexture);

			var bitmapData:BitmapData = texture.bd;
			var regionData:BitmapData;
			if (region.rotate) {
				regionData = new BitmapData(region.getRegionHeight(), region.getRegionWidth());
				regionData.copyPixels(bitmapData, //
				new Rectangle(region.getRegionX(), region.getRegionY(), region.getRegionHeight(), region.getRegionWidth()), //
				new Point());
			} else {
				regionData = new BitmapData(region.getRegionWidth(), region.getRegionHeight());
				regionData.copyPixels(bitmapData, //
				new Rectangle(region.getRegionX(), region.getRegionY(), region.getRegionWidth(), region.getRegionHeight()), //
				new Point());
			}

			var bitmap:Bitmap = new Bitmap(regionData);
			bitmap.smoothing = true;
			bitmap.x = -regionAttachment.width / 2; // Registration point.
			bitmap.y = -regionAttachment.height / 2;
			if (region.rotate) {
				bitmap.rotation = 90;
				bitmap.x += region.getRegionWidth();
			}

			wrapper = new Sprite();
			wrapper.addChild(bitmap);

			sprites.set(regionAttachment, wrapper);
			addChild(wrapper);
		}
		return wrapper;
	}
	#end
}
