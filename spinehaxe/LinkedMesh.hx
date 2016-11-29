package spinehaxe;

import spinehaxe.attachments.MeshAttachment;

class LinkedMesh {
	public var parent:String;
	public var skin:String;
	public var slotIndex:Int;
	public var mesh:MeshAttachment;

	public function new(mesh:MeshAttachment, skin:String, slotIndex:Int, parent:String) {
		this.mesh = mesh;
		this.skin = skin;
		this.slotIndex = slotIndex;
		this.parent = parent;
	}
}
