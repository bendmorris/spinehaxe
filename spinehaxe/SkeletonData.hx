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

import spinehaxe.animation.Animation;
import spinehaxe.Exception;
import haxe.ds.Vector;

class SkeletonData {
	public var name:String;
	public var bones:Array<BoneData>;
	// Ordered parents first.
	public var slots:Array<SlotData>;
	// Setup pose draw order.
	public var skins:Array<Skin>;
	public var defaultSkin:Skin;
	public var events:Array<EventData>;
	public var animations:Array<Animation>;
	// --- Bones.
	public function addBone(bone:BoneData):Void {
		if (bone == null)
			throw new IllegalArgumentException("bone cannot be null.");
		bones[bones.length] = bone;
	}

	/** @return May be null. */
	public function findBone(boneName:String):BoneData {
		if (boneName == null)
			throw new IllegalArgumentException("boneName cannot be null.");
		var i:Int = 0;
		var n:Int = bones.length;
		while(i < n) {
			var bone:BoneData = bones[i];
			if (bone.name == boneName)
				return bone;
			i++;
		}
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findBoneIndex(boneName:String):Int {
		if (boneName == null)
			throw new IllegalArgumentException("boneName cannot be null.");
		var i:Int = 0;
		var n:Int = bones.length;
		while(i < n) {
			if (bones[i].name == boneName)
				return i;
			i++;
		}
		return -1;
	}

	// --- Slots.
	public function addSlot(slot:SlotData):Void {
		if (slot == null)
			throw new IllegalArgumentException("slot cannot be null.");
		slots[slots.length] = slot;
	}

	/** @return May be null. */
	public function findSlot(slotName:String):SlotData {
		if (slotName == null)
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		var n:Int = slots.length;
		while(i < n) {
			var slot:SlotData = slots[i];
			if (slot.name == slotName)
				return slot;
			i++;
		}
		return null;
	}

	/** @return -1 if the bone was not found. */
	public function findSlotIndex(slotName:String):Int {
		if (slotName == null)
			throw new IllegalArgumentException("slotName cannot be null.");
		var i:Int = 0;
		var n:Int = slots.length;
		while(i < n) {
			if (slots[i].name == slotName)
				return i;
			i++;
		}
		return -1;
	}

	// --- Skins.
	public function addSkin(skin:Skin):Void {
		if (skin == null)
			throw new IllegalArgumentException("skin cannot be null.");
		skins[skins.length] = skin;
	}

	/** @return May be null. */
	public function findSkin(skinName:String):Skin {
		if (skinName == null)
			throw new IllegalArgumentException("skinName cannot be null.");
		for (skin in skins)
			if (skin.name == skinName)
			return skin;
		return null;
	}

	// --- Events.
	public function addEvent(eventData:EventData):Void {
		if (eventData == null)
			throw new IllegalArgumentException("eventData cannot be null.");
		events[events.length] = eventData;
	}

	/** @return May be null. */
	public function findEvent(eventName:String):EventData {
		if (eventName == null)
			throw new IllegalArgumentException("eventName cannot be null.");
		var i:Int = 0;
		var n:Int = events.length;
		while(i < n) {
			var eventData:EventData = events[i];
			if (eventData.name == eventName)
				return eventData;
			i++;
		}
		return null;
	}

	// --- Animations.
	public function addAnimation(animation:Animation):Void {
		if (animation == null)
			throw new IllegalArgumentException("animation cannot be null.");
		animations[animations.length] = animation;
	}

	/** @return May be null. */
	public function findAnimation(animationName:String):Animation {
		if (animationName == null)
			throw new IllegalArgumentException("animationName cannot be null.");
		var i:Int = 0;
		var n:Int = animations.length;
		while(i < n) {
			var animation:Animation = animations[i];
			if (animation.name == animationName)
				return animation;
			i++;
		}
		return null;
	}

	// ---
	public function toString():String {
		return name != (null) ? name : ("" + this);
	}


	public function new() {
		bones = new Array<BoneData>();
		slots = new Array<SlotData>();
		skins = new Array<Skin>();
		events = new Array<EventData>();
		animations = new Array<Animation>();
	}
}

