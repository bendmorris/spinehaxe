import haxe.unit.TestCase;

import Random;

import spinehaxe.Bone;
import spinehaxe.BoneData;


class BoneTest extends TestCase {

    var bone:Bone;

    override public function setup() {
        bone = generateRandomBone();
    }

    public function testSlotDataInit() {
        assertTrue(Std.is(this.bone, Bone));
    }

    public static function generateRandomBone():Bone {
        var boneData:BoneData = SkeletonDataTest.generateRandomBoneData();
        var bone:Bone = new Bone(boneData, null);
        return bone;
    }
}
