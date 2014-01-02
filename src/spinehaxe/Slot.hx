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

class Slot {
	public var data:SlotData;
	public var skeleton:Skeleton;
	public var bone:Bone;
	public var attachment(default, set):Attachment;
	public var attachmentTime(get, set):Float;

	public var r:Float;
	public var g:Float;
	public var b:Float;
	public var a:Float;
	var _attachmentTime:Float;
	public function new(data:SlotData, skeleton:Skeleton, bone:Bone) {
		if(data == null) 
			throw new IllegalArgumentException("data cannot be null.");
		if(skeleton == null) 
			throw new IllegalArgumentException("skeleton cannot be null.");
		if(bone == null) 
			throw new IllegalArgumentException("bone cannot be null.");
		this.data = data;
		this.skeleton = skeleton;
		this.bone = bone;
		setToSetupPose();
	}

	/** Sets the attachment and resets {@link #getAttachmentTime()}.
	 * @param attachment May be null. */
	public function set_attachment(attachment:Attachment):Attachment {
		this.attachment = attachment;
		_attachmentTime = skeleton.time;
		return attachment;
	}

	public function set_attachmentTime(time:Float):Float {
		_attachmentTime = skeleton.time - time;
		return time;
	}

	/** Returns the time since the attachment was set. */
	public function get_attachmentTime():Float {
		return skeleton.time - _attachmentTime;
	}

	public function setToSetupPose():Void {
		var slotIndex:Int = ArrayUtils.indexOf(skeleton.data.slots, data);
		r = data.r;
		g = data.g;
		b = data.b;
		a = data.a;
		attachment = data.attachmentName == (null) ? null:skeleton.getAttachmentForSlotIndex(slotIndex, data.attachmentName);
	}

	public function toString():String {
		return data.name;
	}

}

