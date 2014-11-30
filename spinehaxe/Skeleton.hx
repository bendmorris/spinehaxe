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
import spinehaxe.Exception;
using Lambda;

class Skeleton {
	public var data:SkeletonData;
	public var bones:Array<Bone>;
	public var slots:Array<Slot>;
	public var drawOrder:Array<Slot>;
	public var ikConstraints:Array<IkConstraint>;
	var _boneCache:Array<Array<Bone>> = new Array();
	public var rootBone(get, never):Bone;
	public var skin(default, set):Skin;
	public var skinName(get, set):String;

	public var r:Float = 1;
	public var g:Float = 1;
	public var b:Float = 1;
	public var a:Float = 1;
	public var time:Float = 0;
	public var flipX:Bool = false;
	public var flipY:Bool = false;
	public var x(default, set):Float = 0;
	public var y(default, set):Float = 0;

	public function new(data:SkeletonData) {
		if (data == null)
			throw new IllegalArgumentException("data cannot be null.");
		this.data = data;

		bones = new Array<Bone>();
		for (boneData in data.bones) {
			var parent:Bone = boneData.parent == (null) ? null : bones[data.bones.indexOf(boneData.parent)];
			bones[bones.length] = new Bone(boneData, this, parent);
		}

		slots = new Array<Slot>();
		drawOrder = new Array<Slot>();
		for (slotData in data.slots) {
			var bone:Bone = bones[data.bones.indexOf(slotData.boneData)];
			var slot:Slot = new Slot(slotData, bone);
			slots[slots.length] = slot;
			drawOrder[drawOrder.length] = slot;
		}

		ikConstraints = new Array<IkConstraint>();
		for (ikConstraintData in data.ikConstraints)
		{
			ikConstraints[ikConstraints.length] = new IkConstraint(ikConstraintData, this);
		}

		updateCache();
	}

	/** Caches information about bones and IK constraints. Must be called if bones or IK constraints are added or removed. */
	public function updateCache() : Void {
		var ikConstraintsCount:Int = ikConstraints.length;

		var arrayCount:Int = ikConstraintsCount + 1;
		if (_boneCache.length > arrayCount) _boneCache.splice(arrayCount, _boneCache.length - arrayCount);
		for (cachedBones in _boneCache)
			cachedBones.splice(0, cachedBones.length);
		while (_boneCache.length < arrayCount)
			_boneCache[_boneCache.length] = new Array<Bone>();

		var nonIkBones:Array<Bone> = _boneCache[0];

		var continueOuter:Bool = false;
		for (bone in bones) {
			var current:Bone = bone;
			do {
				var ii:Int = 0;
				for (ikConstraint in ikConstraints) {
					var parent:Bone = ikConstraint.bones[0];
					var child:Bone = ikConstraint.bones[ikConstraint.bones.length - 1];
					while (true) {
						if (continueOuter) break;
						if (current == child) {
							_boneCache[ii].push(bone);
							_boneCache[ii + 1].push(bone);
							continueOuter = true;
							continue;
						}
						if (child == parent) break;
						child = child.parent;
					}
					if (continueOuter) break;
					ii++;
				}
				if (continueOuter) break;
				current = current.parent;
			} while (current != null);
			if (continueOuter) {
				continueOuter = false;
				continue;
			}
			nonIkBones[nonIkBones.length] = bone;
		}
	}

	/** Updates the world transform for each bone and applies IK constraints. */
	public function updateWorldTransform():Void {
		for (bone in bones)
			bone.rotationIK = bone.rotation;
		var i:Int = 0, last:Int = _boneCache.length - 1;
		while (true) {
			for (bone in _boneCache[i])
				bone.updateWorldTransform();
			if (i == last) break;
			ikConstraints[i].apply();
			i++;
		}
	}

	/** Sets the bones and slots to their setup pose values. */
	public function setToSetupPose():Void {
		setBonesToSetupPose();
		setSlotsToSetupPose();
	}

	public function setBonesToSetupPose():Void {
		for (bone in bones)
			bone.setToSetupPose();

		for (ikConstraint in ikConstraints) {
			ikConstraint.bendDirection = ikConstraint.data.bendDirection;
			ikConstraint.mix = ikConstraint.data.mix;
		}
	}

	public function setSlotsToSetupPose():Void {
		var i:Int = 0;
		drawOrder.splice(0, drawOrder.length);
		for (slot in slots) {
			drawOrder[i++] = slot;
			slot.setToSetupPose();
		}
	}

	public function get_rootBone():Bone {
		if (bones.length == 0) return null;
		return bones[0];
	}

	/** @return May be null. */
	public function findBone(boneName:String):Bone {
		if (boneName == null)
			throw new IllegalArgumentException("boneName cannot be null.");
		for (bone in bones)
			if (bone.data.name == boneName) return bone;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findBoneIndex(boneName:String):Int {
		if (boneName == null)
			throw new IllegalArgumentException("boneName cannot be null.");
		var i:Int = 0;
		for (bone in bones) {
			if (bone.data.name == boneName) return i;
			i++;
		}

		return -1;
	}

	/** @return May be null. */
	public function findSlot(slotName:String):Slot {
		if (slotName == null)
			throw new IllegalArgumentException("slotName cannot be null.");
		for (slot in slots)
			if (slot.data.name == slotName) return slot;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findSlotIndex(slotName:String):Int {
		if (slotName == null)
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		for (slot in slots) {
			if (slot.data.name == slotName) return i;
			i++;
		}

		return -1;
	}

	public function get_skinName():String {
		return skin.name;
	}

	public function set_skinName(skinName:String):String {
		var skin:Skin = data.findSkin(skinName);
		if (skin == null)
			throw new IllegalArgumentException("Skin not found: " + skinName);
		this.skin = skin;
		return skinName;
	}

	/** Sets the skin used to look up attachments not found in the {@link SkeletonData#getDefaultSkin() default skin}. Attachments
	 * from the new skin are attached if the corresponding attachment from the old skin was attached.
	 * @param newSkin May be null. */
	private function set_skin(newSkin:Skin):Skin {
		if (newSkin != null) {
			if (skin != null)
				newSkin.attachAll(this, skin);
			else {
				var i:Int = 0;
				for (slot in slots) {
					var name:String = slot.data.attachmentName;
					if (name != null && name != "") {
						var attachment:Attachment = newSkin.getAttachment(i, name);
						if (attachment != null) slot.attachment = attachment;
					}
				}
			}
		}
		return skin = newSkin;
	}
	
	private function set_x(value:Float):Float
	{
		return x = value;
	}
	
	private function set_y(value:Float):Float
	{
		return y = value;
	}

	/** @return May be null. */
	public function getAttachmentForSlotName(slotName:String, attachmentName:String):Attachment {
		return getAttachmentForSlotIndex(data.findSlotIndex(slotName), attachmentName);
	}

	/** @return May be null. */
	public function getAttachmentForSlotIndex(slotIndex:Int, attachmentName:String):Attachment {
		if (attachmentName == null)
			throw new IllegalArgumentException("attachmentName cannot be null.");
		if (skin != null) {
			var attachment:Attachment = skin.getAttachment(slotIndex, attachmentName);
			if (attachment != null)
				return attachment;
		}
		if (data.defaultSkin != null)
			return data.defaultSkin.getAttachment(slotIndex, attachmentName);
		return null;
	}

	/** @param attachmentName May be null. */
	public function setAttachment(slotName:String, attachmentName:String):Void {
		if (slotName == null)
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		for (slot in slots) {
			if (slot.data.name == slotName) {
				var attachment:Attachment = null;
				if (attachmentName != null) {
					attachment = getAttachmentForSlotIndex(i, attachmentName);
					if (attachment == null)
						throw new IllegalArgumentException("Attachment not found: " + attachmentName + ", for slot: " + slotName);
				}
				slot.attachment = attachment;
				return;
			}
			i++;
		}

		throw new IllegalArgumentException("Slot not found: " + slotName);
	}

	/** @return May be null. */
	public function findIkConstraint (ikConstraintName:String) : IkConstraint {
		if (ikConstraintName == null) throw new IllegalArgumentException("ikConstraintName cannot be null.");
		for (ikConstraint in ikConstraints)
		if (ikConstraint.data.name == ikConstraintName) return ikConstraint;
		return null;
	}

	public function update(delta:Float):Void {
		time += delta;
	}

	public function toString():String {
		return (data.name != null) ? data.name : ("" + this);
	}

}

