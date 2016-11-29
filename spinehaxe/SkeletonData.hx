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

import spinehaxe.animation.Animation;

class SkeletonData {
	/** May be null. */
	public var name:String;
	public var bones:Array<BoneData> = new Array<BoneData>(); // Ordered parents first.
	public var slots:Array<SlotData> = new Array<SlotData>(); // Setup pose draw order.
	public var skins:Array<Skin> = new Array<Skin>();
	public var defaultSkin:Skin;
	public var events:Array<EventData> = new Array<EventData>();
	public var animations:Array<Animation> = new Array<Animation>();
	public var ikConstraints:Array<IkConstraintData> = new Array<IkConstraintData>();
	public var transformConstraints:Array<TransformConstraintData> = new Array<TransformConstraintData>();
	public var pathConstraints:Array<PathConstraintData> = new Array<PathConstraintData>();
	public var width:Float;
	public var height:Float;
	public var version:String;
	public var hash:String;

	public var fps:Float;
	public var imagesPath:String;

	public function new () {}

	// --- Bones.

	/** @return May be null. */
	public function findBone(boneName:String):BoneData {
		if (boneName == null) throw "boneName cannot be null.";
		for (bone in bones) {
			if (bone.name == boneName) return bone;
		}
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findBoneIndex (boneName:String):Int {
		if (boneName == null) throw "boneName cannot be null.";
		for (i in 0 ... bones.length)
			if (bones[i].name == boneName) return i;
		return -1;
	}

	// --- Slots.

	/** @return May be null. */
	public function findSlot (slotName:String):SlotData {
		if (slotName == null) throw "slotName cannot be null.";
		for (slot in slots) {
			if (slot.name == slotName) return slot;
		}
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findSlotIndex(slotName:String):Int {
		if (slotName == null) throw "slotName cannot be null.";
		for (i in 0 ... slots.length)
			if (slots[i].name == slotName) return i;
		return -1;
	}

	// --- Skins.

	/** @return May be null. */
	public function findSkin(skinName:String):Skin {
		if (skinName == null) throw "skinName cannot be null.";
		for (skin in skins)
			if (skin.name == skinName) return skin;
		return null;
	}

	// --- Events.

	/** @return May be null. */
	public function findEvent(eventName:String):EventData {
		if (eventName == null) throw "eventName cannot be null.";
		for (eventData in events)
			if (eventData.name == eventName) return eventData;
		return null;
	}

	// --- Animations.

	/** @return May be null. */
	public function findAnimation(animationName:String):Animation {
		if (animationName == null) throw "animationName cannot be null.";
		for (animation in animations)
			if (animation.name == animationName) return animation;
		return null;
	}

	// --- IK constraints.

	/** @return May be null. */
	public function findIkConstraint(constraintName:String):IkConstraintData {
		if (constraintName == null) throw "constraintName cannot be null.";
		for (ikConstraintData in ikConstraints)
			if (ikConstraintData.name == constraintName) return ikConstraintData;
		return null;
	}

	// --- Transform constraints.

	/** @return May be null. */
	public function findTransformConstraint(constraintName:String):TransformConstraintData {
		if (constraintName == null) throw "constraintName cannot be null.";
		for (transformConstraintData in transformConstraints)
			if (transformConstraintData.name == constraintName) return transformConstraintData;
		return null;
	}

	/** @return -1 if the transform constraint was not found. */
	public function findTransformConstraintIndex(transformConstraintName:String):Int {
		if (transformConstraintName == null) throw "transformConstraintName cannot be null.";
		var transformConstraints:Array<TransformConstraintData> = this.transformConstraints;
		for (i in 0 ... transformConstraints.length)
			if (transformConstraints[i].name == transformConstraintName) return i;
		return -1;
	}

	// --- Path constraints.

		/** @return May be null. */
	public function findPathConstraint(constraintName:String):PathConstraintData {
		if (constraintName == null) throw "constraintName cannot be null.";
		var pathConstraints:Array<PathConstraintData> = this.pathConstraints;
		for (constraint in pathConstraints) {
			if (constraint.name == constraintName) return constraint;
		}
		return null;
	}

	/** @return -1 if the path constraint was not found. */
	public function findPathConstraintIndex(pathConstraintName:String):Int {
		if (pathConstraintName == null) throw "pathConstraintName cannot be null.";
		var pathConstraints:Array<PathConstraintData> = this.pathConstraints;
		for (i in 0 ... pathConstraints.length)
			if (pathConstraints[i].name == pathConstraintName) return i;
		return -1;
	}

	// ---

	public function toString():String {
		return name != null ? name : Std.string(this);
	}
}
