import haxe.unit.TestCase;

import Random;

import spinehaxe.SkeletonData;
import spinehaxe.BoneData;


class SkeletonDataTest extends TestCase {

    var skeletonData:SkeletonData;
    var boneIndex:Int;

    override public function setup() {
		this.skeletonData = new SkeletonData();

        var boneData:BoneData = new BoneData("hello", null);
        boneData.length = 12;
        boneData.x = 12;
        boneData.y = 12;
        boneData.rotation = 23;
        boneData.scaleX = 1.0;
        boneData.scaleY = 1.0;
        boneData.flipX = false;
        boneData.flipY = false;
        boneData.inheritScale = true;
        boneData.inheritRotation = true;
        for (i in 0...10) {
            var newBoneData = generateRandomBoneData();
            this.skeletonData.bones.push(newBoneData);
        }
        boneIndex = Random.int(0, 10);
        this.skeletonData.bones.insert(boneIndex, boneData);
    }

    public function testSkeletonInit() {
        assertEquals(skeletonData.bones.length, 11);
    }

    public function testFindBone() {
        var boneData:BoneData = this.skeletonData.findBone("hello");
        assertEquals(boneData.length, 12);
        assertEquals(boneData.name, "hello");
    }

    public function testFindBoneIndex() {
        var boneDataIndex:Int = this.skeletonData.findBoneIndex("hello");
        assertEquals(boneDataIndex, this.boneIndex);
    }

    private function generateRandomBoneData():BoneData {
        var boneData:BoneData = new BoneData(Random.string(10, "aeiasdfkjhou"), null);
        boneData.length = Random.int(1, 3);
        boneData.x = Random.int(1, 13);
        boneData.y = Random.int(1, 13);
        boneData.rotation = Random.int(0, 90);
        boneData.scaleX = Random.float(0, 1);
        boneData.scaleY = Random.float(0, 1);
        boneData.flipX = Random.bool();
        boneData.flipY = Random.bool();
        boneData.inheritScale = Random.bool();
        boneData.inheritRotation = Random.bool();
        return boneData;
    }
}
