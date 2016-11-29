/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

package spinehaxe;

import haxe.ds.Vector;
import spinehaxe.attachments.PathAttachment;

class PathConstraint implements Constraint {
	static inline var NONE:Int = -1;
	static inline var BEFORE:Int = -2;
	static inline var AFTER:Int = -3;

	@:allow(spinehaxe) var _data:PathConstraintData;
	@:allow(spinehaxe) var _bones:Array<Bone>;
	public var data(get, never):PathConstraintData;
	public var bones(get, never):Array<Bone>;
	public var target:Slot;
	public var position:Float;
	public var spacing:Float;
	public var rotateMix:Float;
	public var translateMix:Float;

	var _spaces:Array<Float> = new Array<Float>();
	var _positions:Array<Float> = new Array<Float>();
	var _world:Array<Float> = new Array<Float>();
	var _curves:Array<Float> = new Array<Float>();
	var _lengths:Array<Float> = new Array<Float>();
	var _segments:Vector<Float> = new Vector<Float>(10);

	public function new(data:PathConstraintData, skeleton:Skeleton) {
		if (data == null) throw "data cannot be null.";
		if (skeleton == null) throw "skeleton cannot be null.";
		_data = data;
		_bones = new Array();
		for (boneData in data.bones)
			_bones.push(skeleton.findBone(boneData.name));
		target = skeleton.findSlot(data.target.name);
		position = data.position;
		spacing = data.spacing;
		rotateMix = data.rotateMix;
		translateMix = data.translateMix;
	}

	public function apply():Void {
		update();
	}

	public function update ():Void {
		var attachment:PathAttachment = cast target.attachment;
		if (attachment == null) return;

		var rotateMix:Float = this.rotateMix, translateMix:Float = this.translateMix;
		var translate:Bool = translateMix > 0, rotate:Bool = rotateMix > 0;
		if (!translate && !rotate) return;

		var data:PathConstraintData = this._data;
		var spacingMode:SpacingMode = data.spacingMode;
		var lengthSpacing:Bool = spacingMode == SpacingMode.length;
		var rotateMode:RotateMode = data.rotateMode;
		var tangents:Bool = rotateMode == RotateMode.tangent, scale:Bool = rotateMode == RotateMode.chainScale;
		var boneCount:Int = this._bones.length, spacesCount:Int = tangents ? boneCount : boneCount + 1;
		var bones:Array<Bone> = this._bones;
		ArrayUtils.setLength(this._spaces, spacesCount);
		var spaces:Array<Float> = this._spaces, lengths:Array<Float> = null;
		var spacing:Float = this.spacing;
		if (scale || lengthSpacing) {
			if (scale) {
				ArrayUtils.setLength(this._lengths, boneCount);
				lengths = this._lengths;
			}
			for (i in 0 ... spacesCount - 1) {
				var bone:Bone = bones[i];
				var length:Float = bone.data.length, x:Float = length * bone.a, y:Float = length * bone.c;
				length = Math.sqrt(x * x + y * y);
				if (scale) lengths[i] = length;
				spaces[i + 1] = lengthSpacing ? Math.max(0, length + spacing):spacing;
			}
		} else {
			for (i in 1 ... spacesCount)
				spaces[i] = spacing;
		}

		var positions:Array<Float> = computeWorldPositions(attachment, spacesCount, tangents,
			data.positionMode == PositionMode.percent, spacingMode == SpacingMode.percent);
		var boneX:Float = positions[0], boneY:Float = positions[1], offsetRotation:Float = data.offsetRotation;
		var tip:Bool = false;
		if (offsetRotation == 0)
			tip = rotateMode == RotateMode.chain;
		else {
			tip = false;
			var pa:Bone = target.bone;
			offsetRotation *= pa.a * pa.d - pa.b * pa.c > 0 ? MathUtils.degRad : -MathUtils.degRad;
		}
		var p:Int = 3;
		for (i in 0 ... bones.length) {
			var bone = bones[i];
			bone._worldX += (boneX - bone.worldX) * translateMix;
			bone._worldY += (boneY - bone.worldY) * translateMix;
			var x:Float = positions[p];
			var y:Float = positions[p + 1];
			var dx:Float = x - boneX,
				dy:Float = y - boneY;
			if (scale) {
				var length = lengths[i];
				if (length != 0) {
					var s:Float = (Math.sqrt(dx * dx + dy * dy) / length - 1) * rotateMix + 1;
					bone._a *= s;
					bone._c *= s;
				}
			}
			boneX = x;
			boneY = y;
			if (rotate) {
				var a:Float = bone.a, b:Float = bone.b, c:Float = bone.c, d:Float = bone.d, r:Float, cos:Float, sin:Float;
				if (tangents)
					r = positions[p - 1];
				else if (spaces[i + 1] == 0)
					r = positions[p + 2];
				else
					r = Math.atan2(dy, dx);
				r -= Math.atan2(c, a);
				if (tip) {
					cos = Math.cos(r);
					sin = Math.sin(r);
					var length = bone.data.length;
					boneX += (length * (cos * a - sin * c) - dx) * rotateMix;
					boneY += (length * (sin * a + cos * c) - dy) * rotateMix;
				} else {
					r += offsetRotation;
				}
				if (r > Math.PI)
					r -= (Math.PI * 2);
				else if (r < -Math.PI) //
					r += (Math.PI * 2);
				r *= rotateMix;
				cos = Math.cos(r);
				sin = Math.sin(r);
				bone._a = cos * a - sin * c;
				bone._b = cos * b - sin * d;
				bone._c = sin * a + cos * c;
				bone._d = sin * b + cos * d;
			}
			bone.appliedValid = false;
			p += 3;
		}
	}

	function computeWorldPositions(path:PathAttachment, spacesCount:Int, tangents:Bool, percentPosition:Bool,
		percentSpacing:Bool):Array<Float> {
		var target:Slot = this.target;
		var position:Float = this.position;
		var spaces:Array<Float> = this._spaces;
		ArrayUtils.setLength(this._positions, spacesCount * 3 + 2);
		var out:Array<Float> = this._positions, world:Array<Float>;
		var closed:Bool = path.closed;
		var verticesLength:Int = path.worldVerticesLength, curveCount:Int = Std.int(verticesLength / 6), prevCurve:Int = NONE;

		if (!path.constantSpeed) {
			var lengths:Array<Float> = path.lengths;
			curveCount -= closed ? 1 : 2;
			var pathLength:Float = lengths[curveCount];
			if (percentPosition) position *= pathLength;
			if (percentSpacing) {
				for (i in 0 ... spacesCount)
					spaces[i] *= pathLength;
			}
			ArrayUtils.setLength(this._world, 8);
			world = this._world;
			var i = 0, o = 0, curve = 0;
			while (i < spacesCount) {
				var space:Float = spaces[i];
				position += space;
				var p:Float = position;

				if (closed) {
					p %= pathLength;
					if (p < 0) p += pathLength;
					curve = 0;
				} else if (p < 0) {
					if (prevCurve != BEFORE) {
						prevCurve = BEFORE;
						path.computeWorldVertices2(target, 2, 4, world, 0);
					}
					addBeforePosition(p, world, 0, out, o);
					i++;
					o += 3;
					continue;
				} else if (p > pathLength) {
					if (prevCurve != AFTER) {
						prevCurve = AFTER;
						path.computeWorldVertices2(target, verticesLength - 6, 4, world, 0);
					}
					addAfterPosition(p - pathLength, world, 0, out, o);
					i++;
					o += 3;
					continue;
				}

				// Determine curve containing position.
				while (true) {
					var length:Float = lengths[curve];
					if (p > length) {
						curve++;
						continue;
					}
					if (curve == 0)
						p /= length;
					else {
						var prev:Float = lengths[curve - 1];
						p = (p - prev) / (length - prev);
					}
					break;
				}
				if (curve != prevCurve) {
					prevCurve = curve;
					if (closed && curve == curveCount) {
						path.computeWorldVertices2(target, verticesLength - 4, 4, world, 0);
						path.computeWorldVertices2(target, 0, 4, world, 4);
					} else
						path.computeWorldVertices2(target, curve * 6 + 2, 8, world, 0);
				}
				addCurvePosition(p, world[0], world[1], world[2], world[3], world[4], world[5], world[6], world[7], out, o,
					tangents || (i > 0 && space == 0));
				i++;
				o += 3;
			}
			return out;
		}

		// World vertices.
		if (closed) {
			verticesLength += 2;
			ArrayUtils.setLength(this._world, verticesLength);
			world = this._world;
			path.computeWorldVertices2(target, 2, verticesLength - 4, world, 0);
			path.computeWorldVertices2(target, 0, 2, world, verticesLength - 4);
			world[verticesLength - 2] = world[0];
			world[verticesLength - 1] = world[1];
		} else {
			curveCount--;
			verticesLength -= 4;
			ArrayUtils.setLength(this._world, verticesLength);
			world = this._world;
			path.computeWorldVertices2(target, 2, verticesLength, world, 0);
		}

		// Curve lengths.
		ArrayUtils.setLength(this._curves, curveCount);
		var curves:Array<Float> = this._curves;
		var pathLength:Float = 0;
		var x1:Float = world[0], y1:Float = world[1], cx1:Float = 0, cy1:Float = 0, cx2:Float = 0, cy2:Float = 0, x2:Float = 0, y2:Float = 0;
		var tmpx:Float, tmpy:Float, dddfx:Float, dddfy:Float, ddfx:Float, ddfy:Float, dfx:Float, dfy:Float;
		var i:Int = 0, w:Int = 2;
		while (i < curveCount) {
			cx1 = world[w];
			cy1 = world[w + 1];
			cx2 = world[w + 2];
			cy2 = world[w + 3];
			x2 = world[w + 4];
			y2 = world[w + 5];
			tmpx = (x1 - cx1 * 2 + cx2) * 0.1875;
			tmpy = (y1 - cy1 * 2 + cy2) * 0.1875;
			dddfx = ((cx1 - cx2) * 3 - x1 + x2) * 0.09375;
			dddfy = ((cy1 - cy2) * 3 - y1 + y2) * 0.09375;
			ddfx = tmpx * 2 + dddfx;
			ddfy = tmpy * 2 + dddfy;
			dfx = (cx1 - x1) * 0.75 + tmpx + dddfx * 0.16666667;
			dfy = (cy1 - y1) * 0.75 + tmpy + dddfy * 0.16666667;
			pathLength += Math.sqrt(dfx * dfx + dfy * dfy);
			dfx += ddfx;
			dfy += ddfy;
			ddfx += dddfx;
			ddfy += dddfy;
			pathLength += Math.sqrt(dfx * dfx + dfy * dfy);
			dfx += ddfx;
			dfy += ddfy;
			pathLength += Math.sqrt(dfx * dfx + dfy * dfy);
			dfx += ddfx + dddfx;
			dfy += ddfy + dddfy;
			pathLength += Math.sqrt(dfx * dfx + dfy * dfy);
			curves[i] = pathLength;
			x1 = x2;
			y1 = y2;
			i++;
			w += 6;
		}
		if (percentPosition) position *= pathLength;
		if (percentSpacing) {
			for (i in 0 ... spacesCount)
				spaces[i] *= pathLength;
		}

		var segments:Vector<Float> = this._segments;
		var curveLength:Float = 0;
		var o:Int = 0, curve:Int = 0, segment:Int = 0;
		for (i in 0 ... spacesCount) {
			var space = spaces[i];
			position += space;
			var p = position;

			if (closed) {
				p %= pathLength;
				if (p < 0) p += pathLength;
				curve = 0;
			} else if (p < 0) {
				addBeforePosition(p, world, 0, out, o);
				o += 3;
				continue;
			} else if (p > pathLength) {
				addAfterPosition(p - pathLength, world, verticesLength - 4, out, o);
				o += 3;
				continue;
			}

			// Determine curve containing position.
			while (true) {
				var length = curves[curve];
				if (p > length) {
					curve++;
					continue;
				}
				if (curve == 0)
					p /= length;
				else {
					var prev = curves[curve - 1];
					p = (p - prev) / (length - prev);
				}
				break;
			}

			// Curve segment lengths.
			if (curve != prevCurve) {
				prevCurve = curve;
				var ii:Int = curve * 6;
				x1 = world[ii];
				y1 = world[ii + 1];
				cx1 = world[ii + 2];
				cy1 = world[ii + 3];
				cx2 = world[ii + 4];
				cy2 = world[ii + 5];
				x2 = world[ii + 6];
				y2 = world[ii + 7];
				tmpx = (x1 - cx1 * 2 + cx2) * 0.03;
				tmpy = (y1 - cy1 * 2 + cy2) * 0.03;
				dddfx = ((cx1 - cx2) * 3 - x1 + x2) * 0.006;
				dddfy = ((cy1 - cy2) * 3 - y1 + y2) * 0.006;
				ddfx = tmpx * 2 + dddfx;
				ddfy = tmpy * 2 + dddfy;
				dfx = (cx1 - x1) * 0.3 + tmpx + dddfx * 0.16666667;
				dfy = (cy1 - y1) * 0.3 + tmpy + dddfy * 0.16666667;
				curveLength = Math.sqrt(dfx * dfx + dfy * dfy);
				segments[0] = curveLength;
				ii = 1;
				while (ii < 8) {
					dfx += ddfx;
					dfy += ddfy;
					ddfx += dddfx;
					ddfy += dddfy;
					curveLength += Math.sqrt(dfx * dfx + dfy * dfy);
					segments[ii] = curveLength;
					ii++;
				}
				dfx += ddfx;
				dfy += ddfy;
				curveLength += Math.sqrt(dfx * dfx + dfy * dfy);
				segments[8] = curveLength;
				dfx += ddfx + dddfx;
				dfy += ddfy + dddfy;
				curveLength += Math.sqrt(dfx * dfx + dfy * dfy);
				segments[9] = curveLength;
				segment = 0;
			}

			// Weight by segment length.
			p *= curveLength;
			while (true) {
				var length = segments[segment];
				if (p > length) {
					segment++;
					continue;
				}
				if (segment == 0)
					p /= length;
				else {
					var prev = segments[segment - 1];
					p = segment + (p - prev) / (length - prev);
				}
				break;
			}
			addCurvePosition(p * 0.1, x1, y1, cx1, cy1, cx2, cy2, x2, y2, out, o, tangents || (i > 0 && space == 0));

			o += 3;
		}
		return out;
	}

	function addBeforePosition(p:Float, temp:Array<Float>, i:Int, out:Array<Float>, o:Int):Void {
		var x1:Float = temp[i], y1:Float = temp[i + 1], dx:Float = temp[i + 2] - x1, dy:Float = temp[i + 3] - y1, r:Float = Math.atan2(dy, dx);
		out[o] = x1 + p * Math.cos(r);
		out[o + 1] = y1 + p * Math.sin(r);
		out[o + 2] = r;
	}

	function addAfterPosition(p:Float, temp:Array<Float>, i:Int, out:Array<Float>, o:Int):Void {
		var x1:Float = temp[i + 2], y1:Float = temp[i + 3], dx:Float = x1 - temp[i], dy:Float = y1 - temp[i + 1], r:Float = Math.atan2(dy, dx);
		out[o] = x1 + p * Math.cos(r);
		out[o + 1] = y1 + p * Math.sin(r);
		out[o + 2] = r;
	}

	function addCurvePosition(p:Float, x1:Float, y1:Float, cx1:Float, cy1:Float, cx2:Float, cy2:Float, x2:Float, y2:Float,
		out:Array<Float>, o:Int, tangents:Bool):Void {
		if (p == 0 || Math.isNaN(p)) p = 0.0001;
		var tt:Float = p * p, ttt:Float = tt * p, u:Float = 1 - p, uu:Float = u * u, uuu:Float = uu * u;
		var ut:Float = u * p, ut3:Float = ut * 3, uut3:Float = u * ut3, utt3:Float = ut3 * p;
		var x:Float = x1 * uuu + cx1 * uut3 + cx2 * utt3 + x2 * ttt, y:Float = y1 * uuu + cy1 * uut3 + cy2 * utt3 + y2 * ttt;
		out[o] = x;
		out[o + 1] = y;
		if (tangents) out[o + 2] = Math.atan2(y - (y1 * uu + cy1 * ut * 2 + cy2 * tt), x - (x1 * uu + cx1 * ut * 2 + cx2 * tt));
	}

	inline function get_bones():Array<Bone> {
		return _bones;
	}

	inline function get_data():PathConstraintData {
		return _data;
	}

	public function getOrder():Float {
		return _data.order;
	}

	public function toString():String {
		return _data.name;
	}
}
