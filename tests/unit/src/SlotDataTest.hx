import haxe.unit.TestCase;

import Random;

import spinehaxe.SlotData;
import spinehaxe.BoneData;


class SlotDataTest extends TestCase {

    var slotData:SlotData;

    override public function setup() {
        slotData = generateRandomSlotData();
    }

    public function testSlotDataInit() {
        assertTrue(Std.is(this.slotData, SlotData));
    }

    public static function generateRandomSlotData():SlotData {
        var boneData:BoneData = SkeletonDataTest.generateRandomBoneData();
        var slotData:SlotData = new SlotData(Random.string(10, "aeiasdfkjhou"), boneData);
        return slotData;
    }
}
