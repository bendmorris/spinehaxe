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

class TransformConstraint implements Constraint {
	@:allow(spinehaxe) var _data:TransformConstraintData;
	@:allow(spinehaxe) var _bones:Array<Bone>;
	public var data(get, never):TransformConstraintData;
	public var bones(get, never):Array<Bone>;
	public var target:Bone;
	public var rotateMix:Float;
	public var translateMix:Float;
	public var scaleMix:Float;
	public var shearMix:Float;
	var _temp:Vector<Float> = new Vector(2);

	public function new(data:TransformConstraintData, skeleton:Skeleton) {
		if (data == null) throw "data cannot be null.";
		if (skeleton == null) throw "skeleton cannot be null.";
		_data = data;
		rotateMix = data.rotateMix;
		translateMix = data.translateMix;
		scaleMix = data.scaleMix;
		shearMix = data.shearMix;
		_bones = new Array<Bone>();
		for (boneData in data.bones)
			_bones.push(skeleton.findBone(boneData.name));
		target = skeleton.findBone(data.target.name);
	}

	public function apply():Void {
		update();
	}

	public function update():Void {
		var rotateMix:Float = this.rotateMix, translateMix:Float = this.translateMix, scaleMix:Float = this.scaleMix, shearMix:Float = this.shearMix;
		var target:Bone = this.target;
		var ta:Float = target.a, tb:Float = target.b, tc:Float = target.c, td:Float = target.d;
		var degRadReflect:Float = ta * td - tb * tc > 0 ? MathUtils.degRad : -MathUtils.degRad;
		var offsetRotation:Float = data.offsetRotation * degRadReflect;
		var offsetShearY:Float = data.offsetShearY * degRadReflect;
		var bones:Array<Bone> = this._bones;
		for (i in 0 ... bones.length) {
			var bone:Bone = bones[i];
			var modified:Bool = false;

			if (rotateMix != 0) {
				var a:Float = bone.a, b:Float = bone.b, c:Float = bone.c, d:Float = bone.d;
				var r:Float = Math.atan2(tc, ta) - Math.atan2(c, a) + offsetRotation;
				if (r > Math.PI)
					r -= Math.PI * 2;
				else if (r < -Math.PI) r += Math.PI * 2;
				r *= rotateMix;
				var cos:Float = Math.cos(r), sin:Float = Math.sin(r);
				bone._a = cos * a - sin * c;
				bone._b = cos * b - sin * d;
				bone._c = sin * a + cos * c;
				bone._d = sin * b + cos * d;
				modified = true;
			}

			if (translateMix != 0) {
				_temp[0] = data.offsetX;
				_temp[1] = data.offsetY;
				target.localToWorld(_temp);
				bone._worldX += (_temp[0] - bone.worldX) * translateMix;
				bone._worldY += (_temp[1] - bone.worldY) * translateMix;
				modified = true;
			}

			if (scaleMix > 0) {
				var s:Float = Math.sqrt(bone.a * bone.a + bone.c * bone.c);
				var ts:Float = Math.sqrt(ta * ta + tc * tc);
				if (s > 0.00001) s = (s + (ts - s + data.offsetScaleX) * scaleMix) / s;
				bone._a *= s;
				bone._c *= s;
				s = Math.sqrt(bone.b * bone.b + bone.d * bone.d);
				ts = Math.sqrt(tb * tb + td * td);
				if (s > 0.00001) s = (s + (ts - s + data.offsetScaleY) * scaleMix) / s;
				bone._b *= s;
				bone._d *= s;
				modified = true;
			}

			if (shearMix > 0) {
				var b = bone.b, d = bone.d;
				var by:Float = Math.atan2(d, b);
				var r = Math.atan2(td, tb) - Math.atan2(tc, ta) - (by - Math.atan2(bone.c, bone.a));
				if (r > Math.PI)
					r -= Math.PI * 2;
				else if (r < -Math.PI) r += Math.PI * 2;
				r = by + (r + offsetShearY) * shearMix;
				var s = Math.sqrt(b * b + d * d);
				bone._b = Math.cos(r) * s;
				bone._d = Math.sin(r) * s;
				modified = true;
			}

			if (modified) bone.appliedValid = false;
		}
	}

	public function getOrder():Float {
		return _data.order;
	}

	inline function get_data():TransformConstraintData {
		return _data;
	}

	inline function get_bones():Array<Bone> {
		return _bones;
	}

	public function toString():String {
		return _data.name;
	}
}
