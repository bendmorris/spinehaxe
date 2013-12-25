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
import spinehaxe.Exception;
using Lambda;

class Skeleton {
	public var data:SkeletonData;
	public var bones:Array<Bone>;
	public var rootBone(get, never):Bone;
	public var slots:Array<Slot>;
	public var drawOrder:Array<Slot>;
	public var skin:Skin;
	public var skinName(never, set):String;

	public var r:Int;
	public var g:Int;
	public var b:Int;
	public var a:Int;
	public var time:Float;
	public var flipX:Bool;
	public var flipY:Bool;
	public var x:Float;
	public var y:Float;
	public function new(data:SkeletonData) {
		r = 1;
		g = 1;
		b = 1;
		a = 1;
		x = 0;
		y = 0;
		if(data == null) 
			throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.bones = new Array<Bone>();
		for(boneData in data.bones) {
			var parent:Bone = boneData.parent == (null) ? null : this.bones[data.bones.indexOf(boneData.parent)];
			this.bones[this.bones.length] = new Bone(boneData, parent);
		}

		slots = new Array<Slot>();
		drawOrder = new Array<Slot>();
		for(slotData in data.slots) {
			var bone:Bone = bones[data.bones.indexOf(slotData.boneData)];
			var slot:Slot = new Slot(slotData, this, bone);
			slots[slots.length] = slot;
			drawOrder[drawOrder.length] = slot;
		}
	}

	/** Updates the world transform for each bone. */
	public function updateWorldTransform():Void {
		for(bone in bones)
			bone.updateWorldTransform(flipX, flipY);
	}

	/** Sets the bones and slots to their setup pose values. */
	public function setToSetupPose():Void {
		setBonesToSetupPose();
		setSlotsToSetupPose();
	}

	public function setBonesToSetupPose():Void {
		for(bone in bones)
			bone.setToSetupPose();
	}

	public function setSlotsToSetupPose():Void {
		for(slot in slots)
			slot.setToSetupPose();
	}

	public function get_rootBone():Bone {
		if(bones.length == 0) 
			return null;
		return bones[0];
	}

	/** @return May be null. */
	public function findBone(boneName:String):Bone {
		if(boneName == null) 
			throw new IllegalArgumentException("boneName cannot be null.");
		for(bone in bones)
			if(bone.data.name == boneName) 
			return bone;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findBoneIndex(boneName:String):Int {
		if(boneName == null) 
			throw new IllegalArgumentException("boneName cannot be null.");
		var i:Int = 0;
		for(bone in bones) {
			if(bone.data.name == boneName) 
				return i;
			i++;
		}

		return -1;
	}

	/** @return May be null. */
	public function findSlot(slotName:String):Slot {
		if(slotName == null) 
			throw new IllegalArgumentException("slotName cannot be null.");
		for(slot in slots)
			if(slot.data.name == slotName) 
			return slot;
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findSlotIndex(slotName:String):Int {
		if(slotName == null) 
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		for(slot in slots) {
			if(slot.data.name == slotName) 
				return i;
			i++;
		}

		return -1;
	}

	public function set_skinName(skinName:String):String {
		var skin:Skin = data.findSkin(skinName);
		if(skin == null) 
			throw new IllegalArgumentException("Skin not found: " + skinName);
		this.skin = skin;
		return skinName;
	}

	/** Sets the skin used to look up attachments not found in the {@link SkeletonData#getDefaultSkin() default skin}. Attachments
	 * from the new skin are attached if the corresponding attachment from the old skin was attached.
	 * @param newSkin May be null. */
	public function setSkin(newSkin:Skin):Skin {
		if(skin != null && newSkin != null) 
			newSkin.attachAll(this, skin);
		skin = newSkin;
		return newSkin;
	}

	/** @return May be null. */
	public function getAttachmentForSlotName(slotName:String, attachmentName:String):Attachment {
		return getAttachmentForSlotIndex(data.findSlotIndex(slotName), attachmentName);
	}

	/** @return May be null. */
	public function getAttachmentForSlotIndex(slotIndex:Int, attachmentName:String):Attachment {
		if(attachmentName == null) 
			throw new IllegalArgumentException("attachmentName cannot be null.");
		if(skin != null)  {
			var attachment:Attachment = skin.getAttachment(slotIndex, attachmentName);
			if(attachment != null) 
				return attachment;
		}
		if(data.defaultSkin != null) 
			return data.defaultSkin.getAttachment(slotIndex, attachmentName);
		return null;
	}

	/** @param attachmentName May be null. */
	public function setAttachment(slotName:String, attachmentName:String):Void {
		if(slotName == null) 
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		for(slot in slots) {
			if(slot.data.name == slotName)  {
				var attachment:Attachment = null;
				if(attachmentName != null)  {
					attachment = getAttachmentForSlotIndex(i, attachmentName);
					if(attachment == null) 
						throw new IllegalArgumentException("Attachment not found: " + attachmentName + ", for slot: " + slotName);
				}
				slot.attachment = attachment;
				return;
			}
			i++;
		}

		throw new IllegalArgumentException("Slot not found: " + slotName);
	}

	public function update(delta:Float):Void {
		time += delta;
	}

	public function toString():String {
		return data.name != (null) ? data.name : ("" + this);
	}

}

