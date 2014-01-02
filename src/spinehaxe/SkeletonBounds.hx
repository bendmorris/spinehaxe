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

import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.BoundingBoxAttachment;

class SkeletonBounds {
	public var width(getWidth, never) : Float;
	public var height(getHeight, never) : Float;

	var polygonPool : Vector<Polygon>;
	public var boundingBoxes : Vector<BoundingBoxAttachment>;
	public var polygons : Vector<Polygon>;
	public var minX : Float;
	public var minY : Float;
	public var maxX : Float;
	public var maxY : Float;
	public function update(skeleton : Skeleton, updateAabb : Bool) : Void {
		var slots : Vector<Slot> = skeleton.slots;
		var slotCount : Int = slots.length;
		var x : Float = skeleton.x;
		var y : Float = skeleton.y;
		boundingBoxes.length = 0;
		for(polygon in polygons/* AS3HX WARNING could not determine type for var: polygon exp: EIdent(polygons) type: Vector<Polygon>*/)
			polygonPool[polygonPool.length] = polygon;
		polygons.length = 0;
		var i : Int = 0;
		while(i < slotCount) {
			var slot : Slot = slots[i];
			var boundingBox : BoundingBoxAttachment = try cast(slot.attachment, BoundingBoxAttachment) catch(e:Dynamic) null;
			if(boundingBox == null) 
				 {
				i++;
				continue;
			}
;
			boundingBoxes[boundingBoxes.length] = boundingBox;
			var poolCount : Int = polygonPool.length;
			if(poolCount > 0)  {
				polygon = polygonPool[poolCount - 1];
				polygonPool.splice(poolCount - 1, 1);
			}

			else polygon = new Polygon();
			polygons[polygons.length] = polygon;
			polygon.vertices.length = boundingBox.vertices.length;
			boundingBox.computeWorldVertices(x, y, slot.bone, polygon.vertices);
			i++;
		}
		if(updateAabb) 
			aabbCompute();
	}

	function aabbCompute() : Void {
		var minX : Float = int.MAX_VALUE;
		var minY : Float = int.MAX_VALUE;
		var maxX : Float = int.MIN_VALUE;
		var maxY : Float = int.MIN_VALUE;
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			var polygon : Polygon = polygons[i];
			var vertices : Vector<Float> = polygon.vertices;
			var ii : Int = 0;
			var nn : Int = vertices.length;
			while(ii < nn) {
				var x : Float = vertices[ii];
				var y : Float = vertices[ii + 1];
				minX = Math.min(minX, x);
				minY = Math.min(minY, y);
				maxX = Math.max(maxX, x);
				maxY = Math.max(maxY, y);
				ii += 2;
			}
			i++;
		}
		this.minX = minX;
		this.minY = minY;
		this.maxX = maxX;
		this.maxY = maxY;
	}

	/** Returns true if the axis aligned bounding box contains the point. */	public function aabbContainsPoint(x : Float, y : Float) : Bool {
		return x >= minX && x <= maxX && y >= minY && y <= maxY;
	}

	/** Returns true if the axis aligned bounding box intersects the line segment. */	public function aabbIntersectsSegment(x1 : Float, y1 : Float, x2 : Float, y2 : Float) : Bool {
		if((x1 <= minX && x2 <= minX) || (y1 <= minY && y2 <= minY) || (x1 >= maxX && x2 >= maxX) || (y1 >= maxY && y2 >= maxY)) 
			return false;
		var m : Float = (y2 - y1) / (x2 - x1);
		var y : Float = m * (minX - x1) + y1;
		if(y > minY && y < maxY) 
			return true;
		y = m * (maxX - x1) + y1;
		if(y > minY && y < maxY) 
			return true;
		var x : Float = (minY - y1) / m + x1;
		if(x > minX && x < maxX) 
			return true;
		x = (maxY - y1) / m + x1;
		if(x > minX && x < maxX) 
			return true;
		return false;
	}

	/** Returns true if the axis aligned bounding box intersects the axis aligned bounding box of the specified bounds. */	public function aabbIntersectsSkeleton(bounds : SkeletonBounds) : Bool {
		return minX < bounds.maxX && maxX > bounds.minX && minY < bounds.maxY && maxY > bounds.minY;
	}

	/** Returns the first bounding box attachment that contains the point, or null. When doing many checks, it is usually more
	 * efficient to only call this method if {@link #aabbContainsPoint(float, float)} returns true. */	public function containsPoint(x : Float, y : Float) : BoundingBoxAttachment {
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			if(polygons[i].containsPoint(x, y)) 
				return boundingBoxes[i];
			i++;
		}
		return null;
	}

	/** Returns the first bounding box attachment that contains the line segment, or null. When doing many checks, it is usually
	 * more efficient to only call this method if {@link #aabbIntersectsSegment(float, float, float, float)} returns true. */	public function intersectsSegment(x1 : Float, y1 : Float, x2 : Float, y2 : Float) : BoundingBoxAttachment {
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			if(polygons[i].intersectsSegment(x1, y1, x2, y2)) 
				return boundingBoxes[i];
			i++;
		}
		return null;
	}

	public function getPolygon(attachment : BoundingBoxAttachment) : Polygon {
		var index : Int = ArrayUtils.indexOf(boundingBoxes, attachment);
		return index == -(1) ? null : polygons[index];
	}

	public function getWidth() : Float {
		return maxX - minX;
	}

	public function getHeight() : Float {
		return maxY - minY;
	}


	public function new() {
		polygonPool = new Vector<Polygon>();
		boundingBoxes = new Vector<BoundingBoxAttachment>();
		polygons = new Vector<Polygon>();
	}
}

