package spinehaxe;


class IkConstraint {
	//static private final Vector2 temp = new Vector2();
	public var IkConstraintData data:IkConstraintData;
	public var bones:Array<Bone>;
    public var target:Bone ;
	public var mix:Float = 1;
	public var bendDirection:Int;

	public function new(data:IkConstraintData, skeleton:Skeleton ) {
		this.data = data;
		addthis.mix = data.mix;
		this.bendDirection = data.bendDirection;

		this.bones = new Array(data.bones.size);
		if (skeleton != null) {
			for (boneData:BoneData in data.bones)
				bones.add(skeleton.findBone(boneData.name));
			target = skeleton.findBone(data.target.name);
		}
	}

	//public void apply () {
		//Bone target = this.target;
		//Array<Bone> bones = this.bones;
		//switch (bones.size) {
		//case 1:
			//apply(bones.first(), target.worldX, target.worldY, mix);
			//break;
		//case 2:
			//apply(bones.first(), bones.get(1), target.worldX, target.worldY, bendDirection, mix);
			//break;
		//}
	//}

	//public Array<Bone> getBones () {
		//return bones;
	//}

	//public Bone getTarget () {
		//return target;
	//}

	//public void setTarget (Bone target) {
		//this.target = target;
	//}

	//public float getMix () {
		//return mix;
	//}

	//public void setMix (float mix) {
		//this.mix = mix;
	//}

	//public int getBendDirection () {
		//return bendDirection;
	//}

	//public void setBendDirection (int bendDirection) {
		//this.bendDirection = bendDirection;
	//}

	//public IkConstraintData getData () {
		//return data;
	//}

	//public function toString():String {
		//return data.name;
	//}

	/** Adjusts the bone rotation so the tip is as close to the target position as possible. The target is specified in the world
	 * coordinate system. */
	//static public void apply (Bone bone, float targetX, float targetY, float alpha) {
		//float parentRotation = (!bone.data.inheritRotation || bone.parent == null) ? 0 : bone.parent.worldRotation;
		//float rotation = bone.rotation;
		//float rotationIK = (float)Math.atan2(targetY - bone.worldY, targetX - bone.worldX) * radDeg - parentRotation;
		//bone.rotationIK = rotation + (rotationIK - rotation) * alpha;
	//}

	/** Adjusts the parent and child bone rotations so the tip of the child is as close to the target position as possible. The
	 * target is specified in the world coordinate system.
	 * @param child Any descendant bone of the parent. */
	//static public void apply (Bone parent, Bone child, float targetX, float targetY, int bendDirection, float alpha) {
		//float childRotation = child.rotation, parentRotation = parent.rotation;
		//if (alpha == 0) {
			//child.rotationIK = childRotation;
			//parent.rotationIK = parentRotation;
			//return;
		//}
		//Vector2 position = temp;
		//Bone parentParent = parent.parent;
		//if (parentParent != null) {
			//parentParent.worldToLocal(position.set(targetX, targetY));
			//targetX = (position.x - parent.x) * parentParent.worldScaleX;
			//targetY = (position.y - parent.y) * parentParent.worldScaleY;
		//} else {
			//targetX -= parent.x;
			//targetY -= parent.y;
		//}
		//if (child.parent == parent)
			//position.set(child.x, child.y);
		//else
			//parent.worldToLocal(child.parent.localToWorld(position.set(child.x, child.y)));
		//float childX = position.x * parent.worldScaleX, childY = position.y * parent.worldScaleY;
		//float offset = (float)Math.atan2(childY, childX);
		//float len1 = (float)Math.sqrt(childX * childX + childY * childY), len2 = child.data.length * child.worldScaleX;
		//// Based on code by Ryan Juckett with permission: Copyright (c) 2008-2009 Ryan Juckett, http://www.ryanjuckett.com/
		//float cosDenom = 2 * len1 * len2;
		//if (cosDenom < 0.0001f) {
			//child.rotationIK = childRotation + ((float)Math.atan2(targetY, targetX) * radDeg - parentRotation - childRotation)
				//* alpha;
			//return;
		//}
		//float cos = clamp((targetX * targetX + targetY * targetY - len1 * len1 - len2 * len2) / cosDenom, -1, 1);
		//float childAngle = (float)Math.acos(cos) * bendDirection;
		//float adjacent = len1 + len2 * cos, opposite = len2 * sin(childAngle);
		//float parentAngle = (float)Math.atan2(targetY * adjacent - targetX * opposite, targetX * adjacent + targetY * opposite);
		//float rotation = (parentAngle - offset) * radDeg - parentRotation;
		//if (rotation > 180)
			//rotation -= 360;
		//else if (rotation < -180) //
			//rotation += 360;
		//parent.rotationIK = parentRotation + rotation * alpha;
		//rotation = (childAngle + offset) * radDeg - childRotation;
		//if (rotation > 180)
			//rotation -= 360;
		//else if (rotation < -180) //
			//rotation += 360;
		//child.rotationIK = childRotation + (rotation + parent.worldRotation - child.parent.worldRotation) * alpha;
	//}
//}
