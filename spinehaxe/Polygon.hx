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

class Polygon {

	public var vertices : Array<Float>;
	
	public function new()
	{
		vertices = new Array<Float>();
	}
	
	/** Returns true if the polygon contains the point. */	
	public function containsPoint(x : Float, y : Float) : Bool {
		var nn : Int = vertices.length;
		var prevIndex : Int = nn - 2;
		var inside : Bool = false;
		var ii : Int = 0;
		while(ii < nn) {
			var vertexY : Float = vertices[ii + 1];
			var prevY : Float = vertices[prevIndex + 1];
			if ((vertexY < y && prevY >= y) || (prevY < y && vertexY >= y)) {
				var vertexX : Float = vertices[ii];
				if (vertexX + (y - vertexY) / (prevY - vertexY) * (vertices[prevIndex] - vertexX) < x)
					inside = !inside;
			}
			prevIndex = ii;
			ii += 2;
		}
		return inside;
	}

	/** Returns true if the polygon contains the line segment. */	
	public function intersectsSegment(x1 : Float, y1 : Float, x2 : Float, y2 : Float) : Bool {
		var nn : Int = vertices.length;
		var width12 : Float = x1 - x2;
		var height12 : Float = y1 - y2;
		var det1 : Float = x1 * y2 - y1 * x2;
		var x3 : Float = vertices[nn - 2];
		var y3 : Float = vertices[nn - 1];
		var ii : Int = 0;
		while(ii < nn) {
			var x4 : Float = vertices[ii];
			var y4 : Float = vertices[ii + 1];
			var det2 : Float = x3 * y4 - y3 * x4;
			var width34 : Float = x3 - x4;
			var height34 : Float = y3 - y4;
			var det3 : Float = width12 * height34 - height12 * width34;
			var x : Float = (det1 * width34 - width12 * det2) / det3;
			if (((x >= x3 && x <= x4) || (x >= x4 && x <= x3)) && ((x >= x1 && x <= x2) || (x >= x2 && x <= x1))) {
				var y : Float = (det1 * height34 - height12 * det2) / det3;
				if (((y >= y3 && y <= y4) || (y >= y4 && y <= y3)) && ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)))
					return true;
			}
			x3 = x4;
			y3 = y4;
			ii += 2;
		}
		return false;
	}
}
