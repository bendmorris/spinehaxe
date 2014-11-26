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

import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.BoundingBoxAttachment;
import spinehaxe.Polygon;

class SkeletonBounds {
	public var width(get, never):Float;
	public var height(get, never):Float;

	public var boundingBoxes:Array<BoundingBoxAttachment>;
	public var polygons:Array<Polygon>;

	public var minX:Float;
	public var minY:Float;
	public var maxX:Float;
	public var maxY:Float;

	private var polygonPool:Array<Polygon>;

	public function new() {
		polygonPool = new Array<Polygon>();
		boundingBoxes = new Array<BoundingBoxAttachment>();
		polygons = new Array<Polygon>();
	}

	public function update(skeleton : Skeleton, updateAabb : Bool) : Void {
		var slots : Array<Slot> = skeleton.slots;
		var slotCount : Int = slots.length;
		var x : Float = skeleton.x;
		var y : Float = skeleton.y;
    boundingBoxes = new Array<BoundingBoxAttachment>();
		for (polygon in polygons)
      polygonPool.push(polygon);
    polygons = new Array<Polygon>();

		for (i in 0...slotCount) {
			var slot : Slot = slots[i];
			var boundingBox:BoundingBoxAttachment = try cast(slot.attachment, BoundingBoxAttachment) catch(e:Dynamic) null;
			if (boundingBox == null)
				continue;

      boundingBoxes.push(boundingBox);
      var polygon:Polygon;
      if (polygonPool.length > 0)
          polygon = polygonPool.pop();
			else polygon = new Polygon();

			polygons.push(polygon);
			boundingBox.computeWorldVertices(x, y, slot.bone, polygon.vertices);
		}
		if (updateAabb)
			aabbCompute();
	}

	function aabbCompute() : Void {
		var minX : Float = spinehaxe.MathUtils.MAX_INT;
		var minY : Float = spinehaxe.MathUtils.MAX_INT;
		var maxX : Float = -100000;
		var maxY : Float = -100000;
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			var polygon : Polygon = polygons[i];
			var vertices : Array<Float> = polygon.vertices;
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

	/** Returns true if the axis aligned bounding box contains the point. */
	public function aabbContainsPoint(x : Float, y : Float) : Bool {
		return x >= minX && x <= maxX && y >= minY && y <= maxY;
	}

	/** Returns true if the axis aligned bounding box intersects the line segment. */
	public function aabbIntersectsSegment(x1 : Float, y1 : Float, x2 : Float, y2 : Float) : Bool {
		if ((x1 <= minX && x2 <= minX) || (y1 <= minY && y2 <= minY) || (x1 >= maxX && x2 >= maxX) || (y1 >= maxY && y2 >= maxY))
			return false;
		var m : Float = (y2 - y1) / (x2 - x1);
		var y : Float = m * (minX - x1) + y1;
		if (y > minY && y < maxY)
			return true;
		y = m * (maxX - x1) + y1;
		if (y > minY && y < maxY)
			return true;
		var x : Float = (minY - y1) / m + x1;
		if (x > minX && x < maxX)
			return true;
		x = (maxY - y1) / m + x1;
		if (x > minX && x < maxX)
			return true;
		return false;
	}

	/** Returns true if the axis aligned bounding box intersects the axis aligned bounding box of the specified bounds. */
	public function aabbIntersectsSkeleton(bounds : SkeletonBounds) : Bool {
		return minX < bounds.maxX && maxX > bounds.minX && minY < bounds.maxY && maxY > bounds.minY;
	}

	/** Returns the first bounding box attachment that contains the point, or null. When doing many checks, it is usually more
	 * efficient to only call this method if {@link #aabbContainsPoint(float, float)} returns true. */
	public function containsPoint(x : Float, y : Float) : BoundingBoxAttachment {
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			if (polygons[i].containsPoint(x, y))
				return boundingBoxes[i];
			i++;
		}
		return null;
	}

	/** Returns the first bounding box attachment that contains the line segment, or null. When doing many checks, it is usually
	 * more efficient to only call this method if {@link #aabbIntersectsSegment(float, float, float, float)} returns true. */
	public function intersectsSegment(x1 : Float, y1 : Float, x2 : Float, y2 : Float) : BoundingBoxAttachment {
		var i : Int = 0;
		var n : Int = polygons.length;
		while(i < n) {
			if (polygons[i].intersectsSegment(x1, y1, x2, y2))
				return boundingBoxes[i];
			i++;
		}
		return null;
	}

	public function getPolygon(attachment : BoundingBoxAttachment) : Polygon {
		var index : Int = boundingBoxes.indexOf(attachment);
		return index == -(1) ? null : polygons[index];
	}

	private function get_width() : Float {
		return maxX - minX;
	}

	private function get_height() : Float {
		return maxY - minY;
	}


}
