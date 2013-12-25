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

/** Stores attachments by slot index and attachment name. */
class Skin {
	public var name:String;

	var attachments:Map<String, Attachment>;
	public function new(name:String) {
		attachments = new Map();
		if(name == null) 
			throw new IllegalArgumentException("name cannot be null.");
		this.name = name;
	}

	public function addAttachment(slotIndex:Int, name:String, attachment:Attachment):Void {
		if(attachment == null) 
			throw new IllegalArgumentException("attachment cannot be null.");
		attachments[slotIndex + ":" + name] = attachment;
	}

	/** @return May be null. */	public function getAttachment(slotIndex:Int, name:String):Attachment {
		return attachments[slotIndex + ":" + name];
	}

	public function toString():String {
		return name;
	}

	/** Attach each attachment in this skin if the corresponding attachment in the old skin is currently attached. */	public function attachAll(skeleton:Skeleton, oldSkin:Skin):Void {
		for(key in Reflect.fields(oldSkin.attachments)) {
			var colon:Int = key.indexOf(":");
			var slotIndex:Int = Std.parseInt(key.substring(0, colon));
			var name:String = key.substring(colon + 1);
			var slot:Slot = skeleton.slots[slotIndex];
			if(slot.attachment != null && slot.attachment.name == name)  {
				var attachment:Attachment = getAttachment(slotIndex, name);
				if(attachment != null) 
					slot.attachment = attachment;
			}
		}

	}

}

