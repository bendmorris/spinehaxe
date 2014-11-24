import haxe.unit.TestCase;

//import flash.Lib;
//import openfl.Assets;
import spinehaxe.SkeletonJson;
import spinehaxe.SkeletonData;
import spinehaxe.JsonUtils;
using spinehaxe.JsonUtils;
import spinehaxe.Exception;
import spinehaxe.BoneData;
import spinehaxe.Color;
//import spinehaxe.platform.nme.BitmapDataTextureLoader;
//import spinehaxe.atlas.TextureAtlas;


class LoadJSONTest extends TestCase {

    // basic check ;)
    var str: String;
    var skeletonData:SkeletonData;
    var scale:Float;
	var parsedJson:Map<String, JsonNode> = new Map();
    var root:JsonNode;

    override public function setup() {
        str = "foo";

        scale = 1;
        //var fileData:String = sys.io.File.getContent("assets/spineboy.json");
        var fileData:String = sys.io.File.getContent("../../samples/assets/spineboy.json");
        skeletonData = new SkeletonData();
        var name:String = "spineboy";
		if (!parsedJson.exists(name)) parsedJson[name] = JsonUtils.parse(fileData);
		root = parsedJson[name];
        //trace(JsonUtils.getNodesArray(root, "bones"));
    }

    public function testSetup() {
        assertEquals("foo", str);
    }

    public function testLoadSkeletonCoreData() {
        // Skeleton.
        var skeletonMap = root.getNode("skeleton");
        if (skeletonMap != null) {
            skeletonData.version = skeletonMap.getString("spine", null);
            skeletonData.hash = skeletonMap.getString("hash", null);
            skeletonData.width = skeletonMap.getFloat("width", 0);
            skeletonData.height = skeletonMap.getFloat("height", 0);
            //skeletonData.imagesPath = skeletonMap.getString("images", null);
            assertEquals(skeletonMap.version, "2.1.1");
        }
        else {
            assertTrue(skeletonMap == null);
        }
        skeletonData.height = 120;
        skeletonData.width = 120;
        skeletonData.hash = "asdlkfjhu39333yhgjaskhga";
        skeletonData.name = "spineboy";
        skeletonData.version = "2.1.1";
        assertEquals(skeletonData.version, "2.1.1");
        assertEquals(skeletonData.name, "spineboy");
        assertEquals(skeletonData.hash, "asdlkfjhu39333yhgjaskhga");
        assertEquals(skeletonData.height, 120);
        assertEquals(skeletonData.width, 120);
    }

    public function testLoadBonesData() {
        var boneData:BoneData;
        for (boneMap in root.getNodesArray("bones")) {
			var parent:BoneData = null;
			var parentName:String = boneMap.getStr("parent");
			if (parentName != null) {
				parent = skeletonData.findBone(parentName);
				if (parent == null)
					throw new Exception("Parent bone not found: " + parentName);
			}
			boneData = new BoneData(boneMap.getStr("name"), parent);
			boneData.length = boneMap.getFloat("length", 0) * scale;
			boneData.x = boneMap.getFloat("x", 0) * scale;
			boneData.y = boneMap.getFloat("y", 0) * scale;
			boneData.rotation = boneMap.getFloat("rotation", 0);
			boneData.scaleX = boneMap.getFloat("scaleX", 1);
			boneData.scaleY = boneMap.getFloat("scaleY", 1);
			boneData.flipX = boneMap.getBool("flipX", false);
			boneData.flipY = boneMap.getBool("flipY", false);
			boneData.inheritScale = boneMap.getBool("inheritScale", true);
			boneData.inheritRotation = boneMap.getBool("inheritRotation", true);

            var color_str:String = boneMap.getStr("color");
            if (color_str != null) boneData.color = Color.fromString(color_str);

            skeletonData.bones.push(boneData);
			//skeletonData.addBone(boneData);
		}
        assertTrue(skeletonData.bones.length == 17);
        assertTrue(skeletonData.bones[0].name == "hip");
        assertTrue(skeletonData.bones[0].y == 247.47);
        assertTrue(skeletonData.bones[16].name == "gunTip");
        assertTrue(skeletonData.bones[16].parent == skeletonData.bones[15]);
        assertTrue(skeletonData.bones[15].x == 34.42);
        assertTrue(skeletonData.bones[15].y == -0.45);
        assertTrue(skeletonData.bones[15].rotation == 5.34);
        assertTrue(skeletonData.bones[4].inheritScale == false);
        assertTrue(skeletonData.bones[4].flipX == false);
        assertTrue(skeletonData.bones[0].flipX == false);
        assertTrue(skeletonData.bones[4].flipY == false);
        assertEquals(skeletonData.bones[16].color.toString(), "FF000DFF");
        assertEquals(skeletonData.bones[1].color.toString(), "00FF04FF");
        assertEquals(skeletonData.bones[0].color.toString(), "9C9C9CFF");
    }

    public function testSkeletonDataLoad() {
        //var json = new SkeletonJson();
        //var atlas:TextureAtlas = TextureAtlas.create(sys.io.File.getContent("../../samples/assets/spineboy.atlas"), "assets/", new BitmapDataTextureLoader());
        //var json = SkeletonJson.create(atlas);
		//json.scale = 0.6;
        // open and read file at once
        //var fileContent:String = sys.io.File.getContent("../../samples/assets/spineboy.json");
        //var fileContent:String = sys.io.File.getContent("assets/spineboy.json");
        //var skeletonData:SkeletonData = json.readSkeletonData(fileContent, "spineboy");
        assertEquals("foo", str);
    }
}
