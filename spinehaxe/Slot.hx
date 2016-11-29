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

import haxe.ds.Vector;
import spinehaxe.attachments.Attachment;
import spinehaxe.Exception;
using Lambda;

class Slot {
	var _data:SlotData;
	var _bone:Bone;
	var _attachment:Attachment;
	public var data(get, never):SlotData;
	public var bone(get, never):Bone;
	public var skeleton(get, never):Skeleton;
	public var attachment(get, set):Attachment;
	public var attachmentTime(get, set):Float;

	public var r:Float = 0;
	public var g:Float = 0;
	public var b:Float = 0;
	public var a:Float = 0;
	var _attachmentTime:Float = 0;
	public var attachmentVertices:Array<Float> = new Array();

	public function new(data:SlotData, bone:Bone) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (bone == null) throw new IllegalArgumentException("bone cannot be null.");
		_data = data;
		_bone = bone;
		setToSetupPose();
	}

	inline function get_data():SlotData return _data;

	inline function get_bone():Bone return _bone;

	inline function get_skeleton():Skeleton return _bone.skeleton;

	inline function get_attachment():Attachment return _attachment;

	/** Sets the attachment and resets {@link #getAttachmentTime()}.
	 * @param attachment May be null. */
	inline function set_attachment(attachment:Attachment):Attachment {
		if (_attachment == attachment) return _attachment;
		_attachment = attachment;
		_attachmentTime = skeleton.time;
		ArrayUtils.clearArray(attachmentVertices);
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
		r = data.r;
		g = data.g;
		b = data.b;
		a = data.a;
		if (data.attachmentName == null)
			_attachment = null;
		else {
			_attachment = null;
			attachment = _bone._skeleton.getAttachmentForSlotIndex(data.index, data.attachmentName);
		}
	}

	public function toString():String {
		return data.name;
	}
}
