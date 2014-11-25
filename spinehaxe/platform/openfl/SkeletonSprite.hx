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

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.BlendMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.geom.ColorTransform;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import openfl.Vector;
import spinehaxe.attachments.MeshAttachment;
import spinehaxe.attachments.SkinnedMeshAttachment;

import spinehaxe.Bone;
import spinehaxe.Skeleton;
import spinehaxe.SkeletonData;
import spinehaxe.Slot;
import spinehaxe.atlas.AtlasRegion;
import spinehaxe.attachments.RegionAttachment;

class SkeletonSprite extends Sprite {
	static private var tempPoint:Point = new Point();
	static private var tempMatrix:Matrix = new Matrix();

	public var skeleton:Skeleton;
	public var timeScale:Float = 1;
	private var lastTime:Int = 0;
	
	public var renderMeshes(default, set):Bool;
	
	private var _tempVertices:Vector<Float>;
	private var _quadTriangles:Vector<Int>;
	
	public function new (skeletonData:SkeletonData, renderMeshes:Bool = false) {
		super();
		
		this.renderMeshes = renderMeshes;
		
		if (renderMeshes)
		{
			_tempVertices = new Vector<Float>(8);		
			_quadTriangles = new Vector<Int>();
			_quadTriangles[0] = 0;// = Vector.fromArray([0, 1, 2, 2, 3, 0]);
			_quadTriangles[1] = 1;
			_quadTriangles[2] = 2;
			_quadTriangles[3] = 2;
			_quadTriangles[4] = 3;
			_quadTriangles[5] = 0;
		}

		Bone.yDown = true;

		skeleton = new Skeleton(skeletonData);
		skeleton.updateWorldTransform();

		addEventListener(Event.ENTER_FRAME, enterFrame);
	}

	private function enterFrame (event:Event) : Void {
		var time:Int = Std.int(haxe.Timer.stamp() * 1000);
		advanceTime((time - lastTime) / 1000);
		lastTime = time;
	}

	public function advanceTime (delta:Float) : Void {
		skeleton.update(delta * timeScale);

		if (!renderMeshes)
		{
			renderRegions();
		}
		else
		{
			renderTriangles();
		}
	}
	
	private function renderRegions():Void
	{
		removeChildren();
		var drawOrder:Array<Slot> = skeleton.drawOrder;
		for (i in 0 ... drawOrder.length) {
			var slot:Slot = drawOrder[i];
			if (slot.attachment == null || !Std.is(slot.attachment, RegionAttachment)) continue;
			var regionAttachment:RegionAttachment = cast(slot.attachment, RegionAttachment);
			if (regionAttachment != null) {
				var wrapper:Sprite = regionAttachment.wrapper;
				var region:AtlasRegion = cast regionAttachment.rendererObject;
				if (wrapper == null) {
					var bitmapData:BitmapData = cast region.page.rendererObject;
					var regionWidth:Float = region.rotate ? region.height : region.width;
					var regionHeight:Float = region.rotate ? region.width : region.height;
					var regionData:BitmapData = new BitmapData(Std.int(regionWidth), Std.int(regionHeight));
					regionData.copyPixels(bitmapData, new Rectangle(region.x, region.y, regionWidth, regionHeight), new Point());

					var bitmap:Bitmap = new Bitmap(regionData);
					bitmap.smoothing = true;

					// Rotate and scale using default registration point (top left corner, y-down, CW) instead of image center.
					bitmap.rotation = -regionAttachment.rotation;
					bitmap.scaleX = regionAttachment.scaleX * (regionAttachment.width / region.width);
					bitmap.scaleY = regionAttachment.scaleY * (regionAttachment.height / region.height);
					

					// Position using attachment translation, shifted as if scale and rotation were at image center.
					var radians:Float = -regionAttachment.rotation * Math.PI / 180;
					var cos:Float = Math.cos(radians);
					var sin:Float = Math.sin(radians);
					var shiftX:Float = -regionAttachment.width / 2 * regionAttachment.scaleX;
					var shiftY:Float = -regionAttachment.height / 2 * regionAttachment.scaleY;
					if (region.rotate) {
						bitmap.rotation += 90;
						shiftX += regionHeight * (regionAttachment.width / region.width);
					}
					bitmap.x = regionAttachment.x + shiftX * cos - shiftY * sin;
					bitmap.y = -regionAttachment.y + shiftX * sin + shiftY * cos;

					// Use bone as registration point.
					wrapper = new Sprite();
					wrapper.transform.colorTransform = new ColorTransform();
					wrapper.addChild(bitmap);
					regionAttachment.wrapper = wrapper;
				}

				wrapper.blendMode = slot.data.additiveBlending ? BlendMode.ADD : BlendMode.NORMAL;

				var colorTransform:ColorTransform = wrapper.transform.colorTransform;
				colorTransform.redMultiplier = skeleton.r * slot.r * regionAttachment.r;
				colorTransform.greenMultiplier = skeleton.g * slot.g * regionAttachment.g;
				colorTransform.blueMultiplier = skeleton.b * slot.b * regionAttachment.b;
				colorTransform.alphaMultiplier = skeleton.a * slot.a * regionAttachment.a;
				wrapper.transform.colorTransform = colorTransform;

				var bone:Bone = slot.bone;
				var flipX:Int = skeleton.flipX ? -1 : 1;
				var flipY:Int = skeleton.flipY ? -1 : 1;
				if (bone.flipX) flipX = -flipX;
				if (bone.flipY) flipY = -flipY;

				wrapper.x = bone.worldX;
				wrapper.y = bone.worldY;
				wrapper.rotation = -bone.worldRotation * flipX * flipY;
				wrapper.scaleX = bone.worldScaleX * flipX;
				wrapper.scaleY = bone.worldScaleY * flipY;
				addChild(wrapper);
			}
		}
	}
	
	private function renderTriangles():Void
	{
		var drawOrder:Array<Slot> = skeleton.drawOrder;
		var n:Int = drawOrder.length;
		var worldVertices:Vector<Float> = _tempVertices;
		var triangles:Vector<Int> = null;
		var uvs:Vector<Float> = null;
		var verticesLength:Int;
		var atlasRegion:AtlasRegion;
		var bitmapData:BitmapData = null;
		var slot:Slot;
		
		graphics.clear();
		
		for (i in 0...n) 
		{
			slot = drawOrder[i];
			triangles = null;
			uvs = null;
			atlasRegion = null;
			bitmapData = null;
			
			if (slot.attachment != null)
			{
				if (Std.is(slot.attachment, RegionAttachment))
				{
					var region:RegionAttachment = cast slot.attachment;
					verticesLength = 8;
					if (worldVertices.length < verticesLength) worldVertices.length = verticesLength;
					region.computeWorldVertices(0, 0, slot.bone, worldVertices);
					uvs = region.uvs;
					triangles = _quadTriangles;
					atlasRegion = cast(region.rendererObject, AtlasRegion);
				}
				else if (Std.is(slot.attachment, MeshAttachment)) 
				{
					var mesh:MeshAttachment = cast(slot.attachment, MeshAttachment);
					verticesLength = mesh.vertices.length;
					if (worldVertices.length < verticesLength) worldVertices.length = verticesLength;
					mesh.computeWorldVertices(0, 0, slot, worldVertices);
					uvs = mesh.uvs;
					triangles = mesh.triangles;
					atlasRegion = cast(mesh.rendererObject, AtlasRegion);
				}
				else if (Std.is(slot.attachment, SkinnedMeshAttachment))
				{
					var skinnedMesh:SkinnedMeshAttachment = cast(slot.attachment, SkinnedMeshAttachment);
					verticesLength = skinnedMesh.uvs.length;
					if (worldVertices.length < verticesLength) worldVertices.length = verticesLength;
					skinnedMesh.computeWorldVertices(0, 0, slot, worldVertices);
					uvs = skinnedMesh.uvs;
					triangles = skinnedMesh.triangles;
					atlasRegion = cast(skinnedMesh.rendererObject, AtlasRegion);
				}
				
				if (atlasRegion != null)
				{
					bitmapData = cast atlasRegion.page.rendererObject;
					graphics.beginBitmapFill(bitmapData, null, false, true);
					graphics.drawTriangles(worldVertices, triangles, uvs);
					graphics.endFill();
				}
			}
		}
	}
	
	private function set_renderMeshes(value:Bool):Bool
	{
		removeChildren();
		graphics.clear();
		return renderMeshes = value;
	}
}
