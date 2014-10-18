package spinehaxe;

//import flash.utils.ByteArray;
import spinehaxe.animation.Animation;
import spinehaxe.animation.AttachmentTimeline;
import spinehaxe.animation.ColorTimeline;
import spinehaxe.animation.CurveTimeline;
import spinehaxe.animation.DrawOrderTimeline;
import spinehaxe.animation.EventTimeline;
//import spinehaxe.animation.FfdTimeline;
import spinehaxe.animation.RotateTimeline;
import spinehaxe.animation.ScaleTimeline;
import spinehaxe.animation.Timeline;
import spinehaxe.animation.TranslateTimeline;
import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.AttachmentLoader;
import spinehaxe.attachments.AttachmentType;
import spinehaxe.attachments.BoundingBoxAttachment;
//import spinehaxe.attachments.MeshAttachment;
import spinehaxe.attachments.RegionAttachment;
//import spinehaxe.attachments.SkinnedMeshAttachment;
import spinehaxe.attachments.AtlasAttachmentLoader;
import spinehaxe.atlas.TextureAtlas;
import spinehaxe.Exception;
import spinehaxe.Color;
import spinehaxe.JsonUtils;
using spinehaxe.JsonUtils;
import haxe.ds.Vector;

class SkeletonJson {
	static public inline var TIMELINE_SCALE:String = "scale";
	static public inline var TIMELINE_ROTATE:String = "rotate";
	static public inline var TIMELINE_TRANSLATE:String = "translate";
	static public inline var TIMELINE_ATTACHMENT:String = "attachment";
	static public inline var TIMELINE_COLOR:String = "color";
	public var attachmentLoader:AttachmentLoader;
	public var scale:Float;
	public static var parsedJson:Map<String, JsonNode> = new Map();
	public function new(attachmentLoader:AttachmentLoader = null) {
		scale = 1;
		this.attachmentLoader = attachmentLoader;
	}
	
	public static function create(atlas:TextureAtlas) {
		return new SkeletonJson(new AtlasAttachmentLoader(atlas));
	}

	public function readSkeletonData(fileData:String, name:String = null):SkeletonData {
		var skeletonData:SkeletonData = new SkeletonData();
		skeletonData.name = name;
		if (!parsedJson.exists(name)) parsedJson[name] = JsonUtils.parse(fileData);
		var root:JsonNode = parsedJson[name];
		
		// Bones.
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
		}

        // IK constraints.
        //for (ikMap in root.getNodesArray("ik")) {
            //var parent:BoneData = null;
            //var ikConstraintData:IkConstraintData = new IkConstraintData(ikMap.getString("name"));

            //for (boneMap in root.getNodesArray("bones")) {
                //var boneName:String = boneMap.asString();
                //trace(boneName);
                //var bone:BoneData  = skeletonData.findBone(boneName);
                //if (bone == null) throw new SerializationException("IK bone not found: " + boneName);
                ////ikConstraintData.bones.push(bone);
            //}

            //var targetName:String = ikMap.getString("target");
            //ikConstraintData.target = skeletonData.findBone(targetName);
            //if (ikConstraintData.target == null) throw new SerializationException("Target bone not found: " + targetName);

            //ikConstraintData.bendDirection = ikMap.getBool("bendPositive", true) ? 1 : -1;
            //ikConstraintData.mix = ikMap.getFloat("mix", 1);

            ////skeletonData.ikConstraints.push(ikConstraintData);
        //}

		// Slots.
		var slots = root.getNodesArray("slots");
		if (slots != null) {
			for (slotMap in slots) {
				var boneName:String = slotMap.getStr("bone");
				boneData = skeletonData.findBone(boneName);
				if (boneData == null)
					throw new Exception("Slot bone not found: " + boneName);
				var slotData:SlotData = new SlotData(slotMap.getStr("name"), boneData);

                var color_str:String = slotMap.getStr("color");
                if (color_str != null) slotData.color = Color.fromString(color_str);
				
				slotData.attachmentName = slotMap.getStr("attachment");
				slotData.additiveBlending = slotMap.getBool("additive", false);
				skeletonData.addSlot(slotData);
			}
		}

        trace("read slots");
		// Skins.
		var skins:JsonNode = root.getNode("skins");
		if (skins != null) {
			for (skinName in skins.fields()) {
				var skinValue:JsonNode = skins.getNode(skinName);
				var skin:Skin = new Skin(skinName);
				for (slotName in skinValue.fields()) {
					var slotValue:JsonNode = skinValue.getNode(slotName);
					var slotIndex:Int = skeletonData.findSlotIndex(slotName);
					for (attachmentName in slotValue.fields()) {
						var attachmentValue:JsonNode = slotValue.getNode(attachmentName);
						var attachment:Attachment = readAttachment(skin, attachmentName, attachmentValue);
						if (attachment != null)
							skin.addAttachment(slotIndex, attachmentName, attachment);
					}

				}

				skeletonData.addSkin(skin);
				if (skin.name == "default")
					skeletonData.defaultSkin = skin;
			}
		}
        trace("read skins");

		// Events.
		var events:Dynamic = root.getNode("events");
		if (events != null) {
			for (eventName in events.fields()) {
				var eventMap:JsonNode = events.getNode(eventName);
				var eventData:EventData = new EventData(eventName);
				eventData.intValue = eventMap.getInt("int", 0);
				eventData.floatValue = eventMap.getFloat("float", 0);
				eventData.stringValue = eventMap.getStr("string", null);
				skeletonData.addEvent(eventData);
			}

		}

		// Animations.
		var animations:Dynamic = root.getNode("animations");
		for (animationName in animations.fields())
			readAnimation(animationName, animations.getNode(animationName), skeletonData);
		
		return skeletonData;
	}

	function readAttachment(skin:Skin, name:String, map:Dynamic):Attachment {
		var name2 = map.getStr("name");
		name = name2 != null ? name2 : name;
		
		var type:AttachmentType = AttachmentTypes.valueOf(map.getStr("type", "region"));
		var attachment:Attachment = attachmentLoader.newAttachment(skin, type, name);
		if (Std.is(attachment, RegionAttachment)) {
			var regionAttachment:RegionAttachment = try cast(attachment, RegionAttachment) catch(e:Dynamic) null;
			regionAttachment.x = map.getFloat("x", 0) * scale;
			regionAttachment.y = map.getFloat("y", 0) * scale;
			regionAttachment.scaleX = map.getFloat("scaleX", 1);
			regionAttachment.scaleY = map.getFloat("scaleY", 1);
			regionAttachment.rotation = map.getFloat("rotation", 0);
			regionAttachment.width = map.getFloat("width", 32) * scale;
			regionAttachment.height = map.getFloat("height", 32) * scale;
			regionAttachment.updateOffset();
		}

		/*else if (Std.is(attachment, BoundingBoxAttachment)) {
			var box:BoundingBoxAttachment = try cast(attachment, BoundingBoxAttachment) catch(e:Dynamic) null;
			var vertices:Vector<Float> = box.vertices;
			for (point in map.getDynamic("vertices"))
				vertices[vertices.length] = point * scale;
		}*/
		return attachment;
	}

	function readAnimation(name:String, map:Dynamic, skeletonData:SkeletonData):Void {
		var timelines:Array<Timeline> = new Array();
		var duration:Float = 0;
		var bones:JsonNode = map.getNode("bones");
		if (bones != null) {
			for (boneName in bones.fields()) {
				var boneIndex:Int = skeletonData.findBoneIndex(boneName);
				if (boneIndex == -1)
					throw new SerializationException("Bone not found: " + boneName);
				var boneMap:JsonNode = bones.getNode(boneName);
				for (timelineName in boneMap.fields()) {
					var values = boneMap.getNodesArray(timelineName);
					
					if (timelineName == TIMELINE_ROTATE) {
						var timeline:RotateTimeline = new RotateTimeline(values.length);
						timeline.boneIndex = boneIndex;
						
						var frameIndex:Int = 0;
						for (valueMap in values) {
							var time = valueMap.getFloat("time");
							timeline.setFrame(frameIndex, time, valueMap.getFloat("angle"));
							readCurve(timeline, frameIndex, valueMap);
							frameIndex++;
						}

						timelines.push(timeline);
						duration = Math.max(duration, timeline.frames.get(Std.int(timeline.frameCount * 2 - 2)));
					}

					else if (timelineName == TIMELINE_TRANSLATE || timelineName == TIMELINE_SCALE) {
						var timeline1:TranslateTimeline;
						var timelineScale:Float = 1;
						if (timelineName == TIMELINE_SCALE)
							timeline1 = new ScaleTimeline(values.length)
						else  {
							timeline1 = new TranslateTimeline(values.length);
							timelineScale = scale;
						}

						timeline1.boneIndex = boneIndex;
						var frameIndex1:Int = 0;
						for (valueMap1 in values) {
							var time = valueMap1.getFloat("time");
							var x:Float = valueMap1.getFloat("x", 0) * timelineScale;
							var y:Float = valueMap1.getFloat("y", 0) * timelineScale;
							timeline1.setFrame(frameIndex1, time, x, y);
							readCurve(timeline1, frameIndex1, valueMap1);
							frameIndex1++;
						}

						timelines.push(timeline1);
						duration = Math.max(duration, timeline1.frames.get(Std.int(timeline1.frameCount * 3 - 3)));
					}

					else throw new RuntimeException("Invalid timeline type for a bone: " + timelineName + " (" + boneName + ")");
				}

			}
		}

		var slots:JsonNode = map.getNode("slots");
		if (slots != null) {
			for (slotName in slots.fields()) {
				var slotMap:JsonNode = slots.getNode(slotName);
				var slotIndex:Int = skeletonData.findSlotIndex(slotName);
				for (timelineName2 in slotMap.fields()) {
					var values2 = slotMap.getNodesArray(timelineName2);
					if (timelineName2 == TIMELINE_COLOR) {
						var timeline2:ColorTimeline = new ColorTimeline(values2.length);
						timeline2.slotIndex = slotIndex;
						var frameIndex2:Int = 0;
						for (valueMap2 in values2) {
							var time = valueMap2.getFloat("time");
							var color:String = valueMap2.getStr("color");
							var r:Float = toColor(color, 0);
							var g:Float = toColor(color, 1);
							var b:Float = toColor(color, 2);
							var a:Float = toColor(color, 3);
							timeline2.setFrame(frameIndex2, time, r, g, b, a);
							readCurve(timeline2, frameIndex2, valueMap2);
							frameIndex2++;
						}

						timelines.push(timeline2);
						duration = Math.max(duration, timeline2.frames[Std.int(timeline2.frameCount * 5 - 5)]);
					}

					else if (timelineName2 == TIMELINE_ATTACHMENT) {
						var timeline3:AttachmentTimeline = new AttachmentTimeline(values2.length);
						timeline3.slotIndex = slotIndex;
						var frameIndex3:Int = 0;
						for (valueMap3 in values2) {
							var time = valueMap3.getFloat("time");
							var name = valueMap3.getStr("name");
							timeline3.setFrame(frameIndex3++, time, name);
						}

						timelines.push(timeline3);
						duration = Math.max(duration, timeline3.frames[timeline3.frameCount - 1]);
					}

					else throw new Exception("Invalid timeline type for a slot: " + timelineName2 + " (" + slotName + ")");
				}

			}
		}

		var eventsMap:JsonNode = map.getNode("events");
		if (eventsMap != null) {
			var timeline4:EventTimeline = new EventTimeline(eventsMap.length);
			var frameIndex4:Int = 0;
			for (eventMap in cast(eventsMap, Array<JsonNode>)) {
				var eventMapName = eventMap.getStr("name");
				var eventData:EventData = skeletonData.findEvent(eventMapName);
				if (eventData == null)
					throw new Exception("Event not found: " + eventMapName);
				var event:Event = new Event(eventData);
				event.intValue = eventMap.getInt("int", eventData.intValue);
				event.floatValue = eventMap.getFloat("float", eventData.floatValue);
				event.stringValue = eventMap.getStr("string", eventData.stringValue);
				var time = eventMap.getFloat("time");
				timeline4.setFrame(frameIndex4++, time, event);
			}

			timelines.push(timeline4);
			duration = Math.max(duration, timeline4.frames[timeline4.frameCount - 1]);
		}
		
		var drawOrderValues:Dynamic = map.getNode("draworder");
		if (drawOrderValues != null) {
			var timeline5:DrawOrderTimeline = new DrawOrderTimeline(drawOrderValues.length);
			var slotCount:Int = skeletonData.slots.length;
			var frameIndex5:Int = 0;
			for (drawOrderMap in cast(drawOrderValues, Array<JsonNode>)) {
				var drawOrder:Vector<Int> = null;
				var offsets = drawOrderMap.getNode("offsets");
				if (offsets != null) {
					drawOrder = new Vector<Int>(slotCount);
					var i:Int = slotCount - 1;
					while(i >= 0) {
						drawOrder[i] = -1;
						i--;
					}
					var unchanged:Vector<Int> = new Vector<Int>(Math.floor(slotCount - offsets.length));
					var originalIndex:Int = 0;
					var unchangedIndex:Int = 0;
					for (offsetMap in cast(offsets, Array<JsonNode>)) {
						var slotName:String = offsetMap.getStr("slot");
						var slotIndex2:Int = skeletonData.findSlotIndex(slotName);
						if (slotIndex2 == -1)
							throw new Exception("Slot not found: " + slotName);
						// Collect unchanged items.
						while(originalIndex != slotIndex2)unchanged[unchangedIndex++] = originalIndex++;
						// Set changed items.
						var offset = offsetMap.getInt("offset");
						drawOrder[originalIndex + offset] = originalIndex++;
					}

					// Collect remaining unchanged items.
					while(originalIndex < slotCount)unchanged[unchangedIndex++] = originalIndex++;
					// Fill in unchanged items.
					i = slotCount - 1;
					while(i >= 0) {
						if (drawOrder[i] == -1)
							drawOrder[i] = unchanged[--unchangedIndex];
						i--;
					}

				}
				var time = drawOrderMap.getFloat("time");
				timeline5.setFrame(frameIndex5++, time, drawOrder);
			}

			timelines.push(timeline5);
			duration = Math.max(duration, timeline5.frames[timeline5.frameCount - 1]);
		}
		skeletonData.addAnimation(new Animation(name, timelines, duration));
	}

	function readCurve(timeline:CurveTimeline, frameIndex:Int, valueMap:Dynamic):Void {
		var curve:Dynamic = Reflect.field(valueMap, "curve");
		if (curve == null)
			return;
		if (curve == "stepped")
			timeline.setStepped(frameIndex)
		else if (Std.is(curve, Array)) {
			timeline.setCurve(frameIndex, curve[0], curve[1], curve[2], curve[3]);
		}
	}

	static function toColor(hexString:String, colorIndex:Int):Float {
		if (hexString.length != 8)
			throw new IllegalArgumentException("Color hexidecimal length must be 8, recieved: " + hexString);
		return Std.parseInt("0x" + hexString.substring(colorIndex * 2, colorIndex * 2 + 2)) / 255;
	}

}

