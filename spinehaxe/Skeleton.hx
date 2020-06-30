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

import spinehaxe.attachments.PathAttachment;
import spinehaxe.attachments.Attachment;

class Skeleton {
	var _data:SkeletonData;
	public var data(get, never):SkeletonData;
	public var skinName(get, set):String;
	public var skin(get, set):Skin;
	public var getUpdateCache(get, never):Array<Updatable>;
	public var bones:Array<Bone>;
	public var slots:Array<Slot>;
	public var drawOrder:Array<Slot>;
	public var ikConstraints:Array<IkConstraint>;
	public var transformConstraints:Array<TransformConstraint>;
	public var pathConstraints:Array<PathConstraint>;
	var _updateCache:Array<Updatable> = new Array<Updatable>();
	var _updateCacheReset:Array<Bone> = new Array<Bone>();
	var _skin:Skin;
	public var r:Float = 1;
	public var g:Float = 1;
	public var b:Float = 1;
	public var a:Float = 1;
	public var time:Float = 0;
	public var flipX:Bool = false;
	public var flipY:Bool = false;
	public var x:Float = 0;
	public var y:Float = 0;

	public function new(data:SkeletonData) {
		if (data == null)
			throw "data cannot be null.";
		_data = data;

		bones = new Array<Bone>();
		for (boneData in data.bones) {
			var bone:Bone;
			if (boneData.parent == null)
				bone = new Bone(boneData, this, null);
			else {
				var parent:Bone = bones[boneData.parent.index];
				bone = new Bone(boneData, this, parent);
				parent.children.push(bone);
			}
			bones.push(bone);
		}

		slots = new Array<Slot>();
		drawOrder = new Array<Slot>();
		for (slotData in data.slots) {
			var bone = bones[slotData.boneData.index];
			var slot:Slot = new Slot(slotData, bone);
			slots.push(slot);
			drawOrder[drawOrder.length] = slot;
		}

		ikConstraints = new Array<IkConstraint>();
		for (ikConstraintData in data.ikConstraints)
			ikConstraints.push(new IkConstraint(ikConstraintData, this));

		transformConstraints = new Array<TransformConstraint>();
		for (transformConstraintData in data.transformConstraints)
			transformConstraints.push(new TransformConstraint(transformConstraintData, this));

		pathConstraints = new Array<PathConstraint>();
		for (pathConstraintData in data.pathConstraints)
			pathConstraints.push(new PathConstraint(pathConstraintData, this));

		updateCache();
	}

	/** Caches information about bones and constraints. Must be called if bones, constraints, or weighted path attachments are
	 * added or removed. */
	public function updateCache():Void {
		var updateCache:Array<Updatable> = this._updateCache;
		ArrayUtils.clearArray(updateCache);

		var bones:Array<Bone> = this.bones;
		for (bone in bones)
			bone._sorted = false;

		// IK first, lowest hierarchy depth first.
		var ikConstraints:Array<IkConstraint> = this.ikConstraints;
		var transformConstraints:Array<TransformConstraint> = this.transformConstraints;
		var pathConstraints:Array<PathConstraint> = this.pathConstraints;
		var ikCount:Int = ikConstraints.length,
			transformCount:Int = transformConstraints.length,
			pathCount:Int = pathConstraints.length;
		var constraintCount:Int = ikCount + transformCount + pathCount;

		var continueOuter:Bool;
		for (i in 0 ... constraintCount) {
			continueOuter = false;
			var ii:Float = 0;
			if (!continueOuter) for (ii in 0 ... ikCount) {
				var ikConstraint:IkConstraint = ikConstraints[ii];
				if (ikConstraint.data.order == i) {
					sortIkConstraint(ikConstraint);
					continueOuter = true;
					break;
				}
			}
			if (!continueOuter) for (ii in 0 ... transformCount) {
				var transformConstraint:TransformConstraint = transformConstraints[ii];
				if (transformConstraint.data.order == i) {
					sortTransformConstraint(transformConstraint);
					continueOuter = true;
					break;
				}
			}
			if (!continueOuter) for (ii in 0 ... pathCount) {
				var pathConstraint:PathConstraint = pathConstraints[ii];
				if (pathConstraint.data.order == i) {
					sortPathConstraint(pathConstraint);
					continueOuter = true;
					break;
				}
			}
		}

		for (bone in bones)
			sortBone(bone);
	}

	function sortIkConstraint(constraint:IkConstraint):Void {
		var target:Bone = constraint.target;
		sortBone(target);

		var constrained:Array<Bone> = constraint.bones;
		var parent:Bone = constrained[0];
		sortBone(parent);

		if (constrained.length > 1) {
			var child:Bone = constrained[constrained.length - 1];
			if (!(_updateCache.indexOf(child) > -1)) _updateCacheReset.push(child);
		}

		_updateCache.push(constraint);

		sortReset(parent.children);
		constrained[constrained.length - 1]._sorted = true;
	}

	function sortPathConstraint(constraint:PathConstraint):Void {
		var slot:Slot = constraint.target;
		var slotIndex:Int = slot.data.index;
		var slotBone:Bone = slot.bone;
		if (skin != null) sortPathConstraintAttachment(skin, slotIndex, slotBone);
		if (data.defaultSkin != null && data.defaultSkin != skin)
			sortPathConstraintAttachment(data.defaultSkin, slotIndex, slotBone);
		for (ii in 0 ... data.skins.length)
			sortPathConstraintAttachment(data.skins[ii], slotIndex, slotBone);

		var attachment:Attachment = slot.attachment;
		if ((attachment is PathAttachment)) sortPathConstraintAttachment2(attachment, slotBone);

		var constrained:Array<Bone> = constraint.bones;
		var boneCount:Int = constrained.length;
		for (ii in 0 ... boneCount)
			sortBone(constrained[ii]);

		_updateCache.push(constraint);

		for (ii in 0 ... boneCount)
			sortReset(constrained[ii].children);
		for (ii in 0 ... boneCount)
			constrained[ii]._sorted = true;
	}

	function sortTransformConstraint (constraint:TransformConstraint): Void {
		sortBone(constraint.target);

		var constrained:Array<Bone> = constraint.bones;
		var boneCount:Int = constrained.length;
		var ii:Float = 0;
		for (ii in 0 ... boneCount)
			sortBone(constrained[ii]);

		_updateCache.push(constraint);

		for (ii in 0 ... boneCount)
			sortReset(constrained[ii].children);
		for (ii in 0 ... boneCount)
			constrained[ii]._sorted = true;
	}

	function sortPathConstraintAttachment(skin:Skin, slotIndex:Int, slotBone:Bone):Void {
		var dict:Map<String, Attachment> = skin.attachments[slotIndex];
		if (dict == null) return;

		for (value in dict) {
			sortPathConstraintAttachment2(value, slotBone);
		}
	}

	function sortPathConstraintAttachment2(attachment:Attachment, slotBone:Bone):Void {
		var pathAttachment:PathAttachment = cast attachment;
		if (pathAttachment == null) return;
		var pathBones:Array<Int> = pathAttachment.bones;
		if (pathBones == null)
			sortBone(slotBone);
		else {
			var bones:Array<Bone> = this.bones;
			var i:Int = 0;
			while (i < pathBones.length) {
				var boneCount:Int = pathBones[i++];
				var n:Int = i + boneCount;
				while (i < n) {
					sortBone(bones[pathBones[i]]);
					i++;
				}
			}
		}
	}

	function sortBone (bone:Bone):Void {
		if (bone._sorted) return;
		var parent:Bone = bone.parent;
		if (parent != null) sortBone(parent);
		bone._sorted = true;
		_updateCache.push(bone);
	}

	function sortReset (bones:Array<Bone>):Void {
		for (bone in bones) {
			if (bone._sorted) sortReset(bone.children);
			bone._sorted = false;
		}
	}

	/** Updates the world transform for each bone and applies constraints. */
	public function updateWorldTransform ():Void {
		var updateCacheReset:Array<Bone> = this._updateCacheReset;
		for (bone in updateCacheReset) {
			bone.ax = bone.x;
			bone.ay = bone.y;
			bone.arotation = bone.rotation;
			bone.ascaleX = bone.scaleX;
			bone.ascaleY = bone.scaleY;
			bone.ashearX = bone.shearX;
			bone.ashearY = bone.shearY;
			bone.appliedValid = true;
		}
		for (updatable in _updateCache)
			updatable.update();
	}

	/** Sets the bones, constraints, and slots to their setup pose values. */
	public function setToSetupPose ():Void {
		setBonesToSetupPose();
		setSlotsToSetupPose();
	}

	/** Sets the bones and constraints to their setup pose values. */
	public function setBonesToSetupPose ():Void {
		for (bone in bones)
			bone.setToSetupPose();

		for (ikConstraint in ikConstraints) {
			ikConstraint.bendDirection = ikConstraint._data.bendDirection;
			ikConstraint.mix = ikConstraint._data.mix;
		}

		for (transformConstraint in transformConstraints) {
			transformConstraint.rotateMix = transformConstraint._data.rotateMix;
			transformConstraint.translateMix = transformConstraint._data.translateMix;
			transformConstraint.scaleMix = transformConstraint._data.scaleMix;
			transformConstraint.shearMix = transformConstraint._data.shearMix;
		}

		for (pathConstraint in pathConstraints) {
			pathConstraint.position = pathConstraint._data.position;
			pathConstraint.spacing = pathConstraint._data.spacing;
			pathConstraint.rotateMix = pathConstraint._data.rotateMix;
			pathConstraint.translateMix = pathConstraint._data.translateMix;
		}
	}

	public function setSlotsToSetupPose ():Void {
		var i:Int = 0;
		for (slot in slots) {
			drawOrder[i++] = slot;
			slot.setToSetupPose();
		}
	}

	inline function get_data():SkeletonData {
		return _data;
	}

	inline function get_getUpdateCache():Array<Updatable> {
		return _updateCache;
	}

	inline function get_rootBon():Bone {
		if (bones.length == 0) return null;
		return bones[0];
	}

	/** @return May be null. */
	public function findBone(boneName:String):Bone {
		if (boneName == null)
			throw "boneName cannot be null.";
		for (bone in bones)
			if (bone._data.name == boneName) return bone;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findBoneIndex(boneName:String):Int {
		if (boneName == null)
			throw "boneName cannot be null.";
		var i:Int = 0;
		for (bone in bones) {
			if (bone._data.name == boneName) return i;
			i++;
		}
		return -1;
	}

	/** @return May be null. */
	public function findSlot(slotName:String):Slot {
		if (slotName == null)
			throw "slotName cannot be null.";
		for (slot in slots)
			if (slot.data.name == slotName) return slot;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findSlotIndex(slotName:String):Int {
		if (slotName == null)
			throw "slotName cannot be null.";
		var i:Int = 0;
		for (slot in slots) {
			if (slot.data.name == slotName) return i;
			i++;
		}
		return -1;
	}

	inline function get_skin():Skin {
		return _skin;
	}

	inline function set_skinName(skinName:String):String {
		var skin:Skin = data.findSkin(skinName);
		if (skin == null) throw "Skin not found: " + skinName;
		return (this.skin = skin).name;
	}

	/** @return May be null. */
	inline function get_skinName():String {
		return _skin == null ? null : _skin.name;
	}

	/** Sets the skin used to look up attachments before looking in the {@link SkeletonData#getDefaultSkin() default skin}.
	 * Attachments from the new skin are attached if the corresponding attachment from the old skin was attached. If there was
	 * no old skin, each slot's setup mode attachment is attached from the new skin.
	 * @param newSkin May be null. */
	inline function set_skin(newSkin:Skin):Skin {
		if (newSkin != null) {
			if (skin != null)
				newSkin.attachAll(this, skin);
			else {
				var i:Int = 0;
				for (slot in slots) {
					var name:String = slot.data.attachmentName;
					if (name != null) {
						var attachment:Attachment = newSkin.getAttachment(i, name);
						if (attachment != null) slot.attachment = attachment;
					}
					i++;
				}
			}
		}
		return _skin = newSkin;
	}

	/** @return May be null. */
	public function getAttachmentForSlotName(slotName:String, attachmentName:String):Attachment {
		return getAttachmentForSlotIndex(data.findSlotIndex(slotName), attachmentName);
	}

	/** @return May be null. */
	public function getAttachmentForSlotIndex(slotIndex:Int, attachmentName:String):Attachment {
		if (attachmentName == null) throw "attachmentName cannot be null.";
		if (skin != null) {
			var attachment:Attachment = skin.getAttachment(slotIndex, attachmentName);
			if (attachment != null) return attachment;
		}
		if (data.defaultSkin != null) return data.defaultSkin.getAttachment(slotIndex, attachmentName);
		return null;
	}

	/** @param attachmentName May be null. */
	public function setAttachment(slotName:String, attachmentName:String):Void {
		if (slotName == null) throw "slotName cannot be null.";
		var i:Int = 0;
		for (slot in slots) {
			if (slot.data.name == slotName) {
				var attachment:Attachment = null;
				if (attachmentName != null) {
					attachment = getAttachmentForSlotIndex(i, attachmentName);
					if (attachment == null)
						throw "Attachment not found: " + attachmentName + ", for slot: " + slotName;
				}
				slot.attachment = attachment;
				return;
			}
			i++;
		}
		throw "Slot not found: " + slotName;
	}

	/** @return May be null. */
	public function findIkConstraint (constraintName:String):IkConstraint {
		if (constraintName == null) throw "constraintName cannot be null.";
		for (ikConstraint in ikConstraints)
			if (ikConstraint._data.name == constraintName) return ikConstraint;
		return null;
	}

	/** @return May be null. */
	public function findTransformConstraint (constraintName:String):TransformConstraint {
		if (constraintName == null) throw "constraintName cannot be null.";
		for (transformConstraint in transformConstraints)
			if (transformConstraint._data.name == constraintName) return transformConstraint;
		return null;
	}

	/** @return May be null. */
	public function findPathConstraint(constraintName:String):PathConstraint {
		if (constraintName == null) throw "constraintName cannot be null.";
		for (pathConstraint in pathConstraints)
			if (pathConstraint._data.name == constraintName) return pathConstraint;
		return null;
	}

	public function update(delta:Float):Void {
		time += delta;
	}

	public function toString():String {
		return _data.name != null ? _data.name : Std.string(this);
	}
}
