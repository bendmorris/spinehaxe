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

/** Stores attachments by slot index and attachment name. */
class Skin {
	public var name:String;
	public var attachments:Array<Map<String, Attachment>> = new Array();

	public function new(name:String) {
		if (name == null) throw new IllegalArgumentException("name cannot be null.");
		this.name = name;
	}

	public function addAttachment(slotIndex:Int, name:String, attachment:Attachment):Void {
		if (attachment == null) throw new IllegalArgumentException("attachment cannot be null.");
		if (attachments[slotIndex] == null) attachments[slotIndex] = new Map();
		attachments[slotIndex][name] = attachment;
	}

	/** @return May be null. */
	public function getAttachment(slotIndex:Int, name:String):Attachment {
		if (slotIndex > attachments.length) return null;
		return (attachments[slotIndex] != null) ? attachments[slotIndex][name] : null;
	}

	public function toString():String {
		return name;
	}

	/** Attach each attachment in this skin if the corresponding attachment in the old skin is currently attached. */
	public function attachAll (skeleton:Skeleton, oldSkin:Skin) : Void {
		var slotIndex:Int = 0;
		for (slot in skeleton.slots) {
			var slotAttachment:Attachment = slot.attachment;
			if (slotAttachment != null && slotIndex < oldSkin.attachments.length) {
				var dictionary:Map<String, Attachment> = oldSkin.attachments[slotIndex];
				for (name in dictionary.keys()) {
					var skinAttachment:Attachment = dictionary[name];
					if (slotAttachment == skinAttachment) {
						var attachment:Attachment = getAttachment(slotIndex, name);
						if (attachment != null) slot.attachment = attachment;
						break;
					}
				}
			}
			slotIndex++;
		}
	}
}
