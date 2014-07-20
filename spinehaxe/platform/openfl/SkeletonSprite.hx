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

package spinehaxe.platform.openfl;

import haxe.ds.Vector;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.BlendMode;
import flash.display.DisplayObject;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.events.Event;
import flash.geom.ColorTransform;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.geom.Rectangle;

import spinehaxe.Bone;
import spinehaxe.Skeleton;
import spinehaxe.SkeletonData;
import spinehaxe.Slot;
import spinehaxe.atlas.TextureAtlas;
import spinehaxe.attachments.RegionAttachment;

class SkeletonSprite extends Sprite {
	static private var tempPoint:Point = new Point();
	static private var tempMatrix:Matrix = new Matrix();

	public var skeleton:Skeleton;
	public var timeScale:Float = 1;
	private var lastTime:Float = 0;

	var wrappers:Map<RegionAttachment, Sprite> = new Map();

	public function new (skeletonData:SkeletonData) {
		super();

		Bone.yDown = true;

		skeleton = new Skeleton(skeletonData);
		skeleton.updateWorldTransform();

		addEventListener(Event.ENTER_FRAME, enterFrame);
	}

	private function enterFrame (event:Event) : Void {
		var time:Float = haxe.Timer.stamp();
		advanceTime((time - lastTime) / 1000);
		lastTime = time;
	}

	public function advanceTime (delta:Float) : Void {
		skeleton.update(delta * timeScale);

		removeChildren();
		var drawOrder:Array<Slot> = skeleton.drawOrder;
		var i:Int = 0, n:Int = drawOrder.length;
		while (i < n) {
			var slot:Slot = drawOrder[i];
			if (slot.attachment == null)
			{
				i++;
				continue;
			}
			var regionAttachment:RegionAttachment = cast slot.attachment;
			if (regionAttachment != null) {
				var wrapper:Sprite = wrappers[regionAttachment];
				var region:AtlasRegion = cast regionAttachment.region;
				if (wrapper == null) {
					var bitmapData:BitmapData = cast (region.texture, BitmapDataTexture).bd;
					var regionWidth:Float = region.rotate ? region.regionHeight : region.regionWidth;
					var regionHeight:Float = region.rotate ? region.regionWidth : region.regionHeight;
					var regionData:BitmapData = new BitmapData(Std.int(region.regionWidth), Std.int(region.regionHeight));
					regionData.copyPixels(bitmapData, new Rectangle(region.regionX, region.regionY, region.regionWidth, region.regionHeight), new Point());

					var bitmap:Bitmap = new Bitmap(regionData);
					bitmap.smoothing = true;

					// Rotate and scale using default registration point (top left corner, y-down, CW) instead of image center.
					bitmap.rotation = -regionAttachment.rotation;
					bitmap.scaleX = regionAttachment.scaleX * (regionAttachment.width / regionWidth);
					bitmap.scaleY = regionAttachment.scaleY * (regionAttachment.height / regionHeight);

					// Position using attachment translation, shifted as if scale and rotation were at image center.
					var radians:Float = -regionAttachment.rotation * Math.PI / 180;
					var cos:Float = Math.cos(radians);
					var sin:Float = Math.sin(radians);
					var shiftX:Float = -regionAttachment.width / 2 * regionAttachment.scaleX;
					var shiftY:Float = -regionAttachment.height / 2 * regionAttachment.scaleY;
					if (region.rotate) {
						bitmap.rotation += 90;
						shiftX += regionHeight * (regionAttachment.width / region.regionWidth);
					}
					bitmap.x = regionAttachment.x + shiftX * cos - shiftY * sin;
					bitmap.y = -regionAttachment.y + shiftX * sin + shiftY * cos;

					// Use bone as registration point.
					wrapper = new Sprite();
					wrapper.transform.colorTransform = new ColorTransform();
					wrapper.addChild(bitmap);
					wrappers[regionAttachment] = wrapper;
				}

				wrapper.blendMode = slot.data.additiveBlending ? BlendMode.ADD : BlendMode.NORMAL;

				var colorTransform:ColorTransform = wrapper.transform.colorTransform;
				colorTransform.redMultiplier = skeleton.r * slot.r * regionAttachment.r;
				colorTransform.greenMultiplier = skeleton.g * slot.g * regionAttachment.g;
				colorTransform.blueMultiplier = skeleton.b * slot.b * regionAttachment.b;
				colorTransform.alphaMultiplier = skeleton.a * slot.a * regionAttachment.a;
				wrapper.transform.colorTransform = colorTransform;

				var flipX:Int = skeleton.flipX ? -1 : 1;
				var flipY:Int = skeleton.flipY ? -1 : 1;

				var bone:Bone = slot.bone;
				wrapper.x = bone.worldX;
				wrapper.y = bone.worldY;
				wrapper.rotation = -bone.worldRotation * flipX * flipY;
				wrapper.scaleX = bone.worldScaleX * flipX;
				wrapper.scaleY = bone.worldScaleY * flipY;
				addChild(wrapper);
			}

			i++;
		}
	}
}
