package spinehaxe;


class IkConstraintData {
	public var name:String;
	public var bones:Array<Bone> = new Array<Bone>();
	public var target:BoneData;
	public var bendDirection:Int = 1;
	public var mix:Float = 1;

	public function new(name:String) {
		this.name = name;
	}

	public function toString():String {
		return name;
	}
}
