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

import openfl.Vector;
import spinehaxe.attachments.Attachment;
import spinehaxe.Exception;
using Lambda;

class Slot {
	public var data:SlotData;
	public var skeleton(get, never):Skeleton;
	public var bone:Bone;
	public var attachment(default, set):Attachment;
	public var attachmentTime(get, set):Float;

	public var r:Float = 0;
	public var g:Float = 0;
	public var b:Float = 0;
	public var a:Float = 0;
	var _attachmentTime:Float = 0;
	public var attachmentVertices:Vector<Float> = new Vector<Float>();

	public function new(data:SlotData, bone:Bone) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (bone == null) throw new IllegalArgumentException("bone cannot be null.");
		this.data = data;
		this.bone = bone;
		setToSetupPose();
	}

	public inline function get_skeleton() {
		return bone.skeleton;
	}

	/** Sets the attachment and resets {@link #getAttachmentTime()}.
	 * @param attachment May be null. */
	public function set_attachment(attachment:Attachment):Attachment {
		this.attachment = attachment;
		_attachmentTime = skeleton.time;
		attachmentVertices.splice(0, attachmentVertices.length);
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
		var slotIndex:Int = skeleton.data.slots.indexOf(data);
		r = data.r;
		g = data.g;
		b = data.b;
		a = data.a;
		attachment = data.attachmentName == (null) ? null : skeleton.getAttachmentForSlotIndex(slotIndex, data.attachmentName);
	}

	public function toString():String {
		return data.name;
	}
}
