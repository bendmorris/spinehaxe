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
import spinehaxe.Exception.IllegalArgumentException;
import spinehaxe.animation.Animation;
import spinehaxe.animation.AttachmentTimeline;
import spinehaxe.animation.ColorTimeline;
import spinehaxe.animation.CurveTimeline;
import spinehaxe.animation.DrawOrderTimeline;
import spinehaxe.animation.EventTimeline;
import spinehaxe.animation.FfdTimeline;
import spinehaxe.animation.FlipXTimeline;
import spinehaxe.animation.FlipYTimeline;
import spinehaxe.animation.IkConstraintTimeline;
import spinehaxe.animation.RotateTimeline;
import spinehaxe.animation.ScaleTimeline;
import spinehaxe.animation.Timeline;
import spinehaxe.animation.TranslateTimeline;
import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.AttachmentLoader;
import spinehaxe.attachments.AttachmentType;
import spinehaxe.attachments.BoundingBoxAttachment;
import spinehaxe.attachments.MeshAttachment;
import spinehaxe.attachments.RegionAttachment;
import spinehaxe.attachments.SkinnedMeshAttachment;
import spinehaxe.JsonUtils;
import haxe.ds.Vector;
using spinehaxe.JsonUtils;

class SkeletonJson {
	public var attachmentLoader:AttachmentLoader;
	public var scale:Float = 1;

	public function new (attachmentLoader:AttachmentLoader = null) {
		this.attachmentLoader = attachmentLoader;
	}

	public function readSkeletonData (object:String, name:String = null) : SkeletonData {
		if (object == null) throw new IllegalArgumentException("object cannot be null.");

		var root:Dynamic = JsonUtils.parse(object);

		var skeletonData:SkeletonData = new SkeletonData();
		skeletonData.name = name;

		// Skeleton.
		if (root.hasOwnProperty("skeleton")) {
			var skeletonMap:Dynamic = root.skeleton;
			skeletonData.hash = skeletonMap.getStr("hash");
			skeletonData.version = skeletonMap.getStr("spine");
			skeletonData.width = skeletonMap.getFloat('width');
			skeletonData.height = skeletonMap.getFloat('height');
		}

		// Bones.
		var boneData:BoneData;
		for (boneMap in root.getNodesArray("bones")) {
			var parent:BoneData = null;
			var parentName:String = boneMap.getStr("parent");
			if (parentName != null) {
				parent = skeletonData.findBone(parentName);
				if (parent == null) throw "Parent bone not found: " + parentName;
			}
			boneData = new BoneData(boneMap.name, parent);
			boneData.length = boneMap.getFloat("length", 0) * scale;
			boneData.x = boneMap.getFloat("x") * scale;
			boneData.y = boneMap.getFloat("y") * scale;
			boneData.rotation = boneMap.getFloat("rotation");
			boneData.scaleX = boneMap.getFloat("scaleX", 1);
			boneData.scaleY = boneMap.getFloat("scaleY", 1);
			boneData.flipX = boneMap.getBool("flipX", false);
			boneData.flipY = boneMap.getBool("flipY", false);
			boneData.inheritScale = boneMap.getBool("inheritScale", true);
			boneData.inheritRotation = boneMap.getBool("inheritRotation", true);
			skeletonData.bones[skeletonData.bones.length] = boneData;
		}

		// IK constraints.
		if (root.hasOwnProperty("ik")) {
			for (ikMap in root.getNodesArray("ik")) {
				var ikConstraintData:IkConstraintData = new IkConstraintData(ikMap.getStr("name"));

				for (boneName in ikMap.getNodesArray("bones")) {
					var bone:BoneData = skeletonData.findBone(boneName);
					if (bone == null) throw "IK bone not found: " + boneName;
					ikConstraintData.bones[ikConstraintData.bones.length] = bone;
				}

				ikConstraintData.target = skeletonData.findBone(ikMap.getStr("target"));
				if (ikConstraintData.target == null) throw "Target bone not found: " + ikMap.getStr("target");

				ikConstraintData.bendDirection = ikMap.getBool("bendPositive", true) ? 1 : -1;
				ikConstraintData.mix = ikMap.getFloat("mix", 1);

				skeletonData.ikConstraints[skeletonData.ikConstraints.length] = ikConstraintData;
			}
		}

		// Slots.
		for (slotMap in root.getNodesArray("slots")) {
			var boneName = slotMap.getStr("bone");
			boneData = skeletonData.findBone(boneName);
			if (boneData == null) throw "Slot bone not found: " + boneName;
			var slotData:SlotData = new SlotData(slotMap.getStr("name"), boneData);

			var color:String = slotMap.getStr("color");
			if (color != null) {
				slotData.r = toColor(color, 0);
				slotData.g = toColor(color, 1);
				slotData.b = toColor(color, 2);
				slotData.a = toColor(color, 3);
			}

			slotData.attachmentName = slotMap.getStr("attachment");
			slotData.additiveBlending = slotMap.getBool("additive");

			skeletonData.slots[skeletonData.slots.length] = slotData;
		}

		// Skins.
		var skins:JsonNode = root.getNode("skins");
		for (skinName in skins.fields()) {
			var skinMap:JsonNode = skins.getNode(skinName);
			var skin:Skin = new Skin(skinName);
			for (slotName in skinMap.fields()) {
				var slotIndex:Int = skeletonData.findSlotIndex(slotName);
				var slotEntry:Dynamic = skinMap.getNode(slotName);
				for (attachmentName in slotEntry.fields()) {
					var attachment:Attachment = readAttachment(skin, attachmentName, slotEntry.getNode(attachmentName));
					if (attachment != null)
						skin.addAttachment(slotIndex, attachmentName, attachment);
				}
			}
			skeletonData.skins[skeletonData.skins.length] = skin;
			if (skin.name == "default")
				skeletonData.defaultSkin = skin;
		}

		// Events.
		var events:JsonNode = root.getNode("events");
		if (events != null) {
			for (eventName in events.fields()) {
				var eventMap:JsonNode = events.getNode(eventName);
				var eventData:EventData = new EventData(eventName);
				eventData.intValue = eventMap.getInt("int");
				eventData.floatValue = eventMap.getFloat("float");
				eventData.stringValue = eventMap.getStr("string");
				skeletonData.events[skeletonData.events.length] = eventData;
			}
		}

		// Animations.
		var animations:JsonNode = root.getNode("animations");
		for (animationName in animations.fields())
			readAnimation(animationName, animations.getNode(animationName), skeletonData);

		return skeletonData;
	}

	private function readAttachment (skin:Skin, name:String, map:Dynamic) : Attachment {
		name = map.getStr("name", name);

		var type:AttachmentType = map.getStr("type",  "region");
		var path:String = map.getStr("path", name);

		var scale:Float = this.scale;
		var color:String, vertices:Array<Float>;
		switch (type) {
		case AttachmentType.Region:
			var region:RegionAttachment = attachmentLoader.newRegionAttachment(skin, name, path);
			if (region == null) return null;
			region.path = path;
			region.x = map.getFloat("x") * scale;
			region.y = map.getFloat("y") * scale;
			region.scaleX = map.getFloat("scaleX", 1);
			region.scaleY = map.getFloat("scaleY", 1);
			region.rotation = map.getFloat("rotation");
			region.width = map.getFloat("width") * scale;
			region.height = map.getFloat("height") * scale;
			
			color = map.getStr("color");
			if (color != null) {
				region.r = toColor(color, 0);
				region.g = toColor(color, 1);
				region.b = toColor(color, 2);
				region.a = toColor(color, 3);
			}
			
			region.updateOffset();
			return region;

		case AttachmentType.Mesh:
			var mesh:MeshAttachment = attachmentLoader.newMeshAttachment(skin, name, path);
			if (mesh == null) return null;
			mesh.path = path; 
			mesh.vertices = map.getFloatArray("vertices", scale);
			mesh.triangles = map.getIntArray("triangles");
			mesh.regionUVs = map.getFloatArray("uvs", 1);
			mesh.updateUVs();

			color = map.getStr("color");
			if (color != null) {
				mesh.r = toColor(color, 0);
				mesh.g = toColor(color, 1);
				mesh.b = toColor(color, 2);
				mesh.a = toColor(color, 3);
			}

			mesh.hullLength = map.getInt("hull") * 2;
			if (map.hasOwnProperty("edges")) mesh.edges = map.getIntArray("edges");
			mesh.width = map.getFloat("width") * scale;
			mesh.height = map.getFloat("height") * scale;
			return mesh;
		case AttachmentType.SkinnedMesh:
			var skinnedMesh:SkinnedMeshAttachment = attachmentLoader.newSkinnedMeshAttachment(skin, name, path);
			if (skinnedMesh == null) return null;
			skinnedMesh.path = path;

			var uvs:Array<Float> = map.getFloatArray("uvs", 1);
			vertices = map.getFloatArray("vertices", 1);
			var weights:Array<Float> = new Array<Float>();
			var bones:Array<Int> = new Array<Int>();
			var i:Int = 0, n:Int = vertices.length;
			while (i < n) {
				var boneCount:Int = Std.int(vertices[i++]);
				bones[bones.length] = boneCount;
				var nn:Int = i + boneCount * 4;
				while (i < nn) {
					bones[bones.length] = Std.int(vertices[i]);
					weights[weights.length] = vertices[i + 1] * scale;
					weights[weights.length] = vertices[i + 2] * scale;
					weights[weights.length] = vertices[i + 3];
					i += 4;
				}
			}
			skinnedMesh.bones = bones;
			skinnedMesh.weights = weights;
			skinnedMesh.triangles = map.getIntArray("triangles");
			skinnedMesh.regionUVs = uvs;
			skinnedMesh.updateUVs();
			
			color = map.getStr("color");
			if (color != null) {
				skinnedMesh.r = toColor(color, 0);
				skinnedMesh.g = toColor(color, 1);
				skinnedMesh.b = toColor(color, 2);
				skinnedMesh.a = toColor(color, 3);
			}
			
			skinnedMesh.hullLength = map.getInt("hull") * 2;
			if (map.hasOwnProperty("edges")) skinnedMesh.edges = map.getIntArray("edges");
			skinnedMesh.width = map.getFloat("width") * scale;
			skinnedMesh.height = map.getFloat("height") * scale;
			return skinnedMesh;
		case AttachmentType.BoundingBox:
			var box:BoundingBoxAttachment = attachmentLoader.newBoundingBoxAttachment(skin, name);
			for (point in map.getFloatArray("vertices", 1)) {
				box.vertices.push(point * scale);
      }
			return box;
		default:
			throw "Attachment type not implemented: " + type;
		}

		return null;
	}

	private function readAnimation (name:String, map:JsonNode, skeletonData:SkeletonData) : Void {
		var timelines:Array<Timeline> = new Array<Timeline>();
		var duration:Float = 0;

		var slotMap:JsonNode, slotIndex:Int = 0, slotName:String;
		var values:Array<JsonNode>, valueMap:JsonNode, frameIndex:Int = 0;
		var i:Int = 0;
		var timelineName:String;

		var slots:JsonNode = map.getNode("slots");
		for (slotName in slots.fields()) {
			slotMap = Reflect.getProperty(slots, slotName);
			slotIndex = skeletonData.findSlotIndex(slotName);

			for (timelineName in slotMap.fields()) {
				values = slotMap.getNodesArray(timelineName);
				if (timelineName == "color") {
					var colorTimeline:ColorTimeline = new ColorTimeline(values.length);
					colorTimeline.slotIndex = slotIndex;
					
					frameIndex = 0;
					for (valueMap in values) {
						var color:String = valueMap.getStr("color");
						var r:Float = toColor(color, 0);
						var g:Float = toColor(color, 1);
						var b:Float = toColor(color, 2);
						var a:Float = toColor(color, 3);
						colorTimeline.setFrame(frameIndex, valueMap.getFloat("time"), r, g, b, a);
						readCurve(colorTimeline, frameIndex, valueMap);
						frameIndex++;
					}
					timelines[timelines.length] = colorTimeline;
					duration = Math.max(duration, colorTimeline.frames[colorTimeline.frameCount * 5 - 5]);
					
				} else if (timelineName == "attachment") {
					var attachmentTimeline:AttachmentTimeline = new AttachmentTimeline(values.length);
					attachmentTimeline.slotIndex = slotIndex;
					
					frameIndex = 0;
					for (valueMap in values)
						attachmentTimeline.setFrame(frameIndex++, valueMap.getFloat("time"), valueMap.getStr("name"));
					timelines[timelines.length] = attachmentTimeline;
					duration = Math.max(duration, attachmentTimeline.frames[attachmentTimeline.frameCount - 1]);

				} else
					throw "Invalid timeline type for a slot: " + timelineName + " (" + slotName + ")";
			}
		}

		var bones:JsonNode = map.getNode("bones");
		for (boneName in bones.fields()) {
			var boneIndex:Int = skeletonData.findBoneIndex(boneName);
			if (boneIndex == -1) throw "Bone not found: " + boneName;
			var boneMap:JsonNode = bones.getNode(boneName);

			for (timelineName in boneMap.fields()) {
				values = boneMap.getNodesArray(timelineName);
				if (timelineName == "rotate") {
					var rotateTimeline:RotateTimeline = new RotateTimeline(values.length);
					rotateTimeline.boneIndex = boneIndex;

					frameIndex = 0;
					for (valueMap in values) {
						rotateTimeline.setFrame(frameIndex, valueMap.getFloat("time"), valueMap.getFloat("angle"));
						readCurve(rotateTimeline, frameIndex, valueMap);
						frameIndex++;
					}
					timelines[timelines.length] = rotateTimeline;
					duration = Math.max(duration, rotateTimeline.frames[rotateTimeline.frameCount * 2 - 2]);

				} else if (timelineName == "translate" || timelineName == "scale") {
					var timeline:TranslateTimeline;
					var timelineScale:Float = 1;
					if (timelineName == "scale")
						timeline = new ScaleTimeline(values.length);
					else {
						timeline = new TranslateTimeline(values.length);
						timelineScale = scale;
					}
					timeline.boneIndex = boneIndex;

					frameIndex = 0;
					for (valueMap in values) {
						var x:Float = valueMap.getFloat("x") * timelineScale;
						var y:Float = valueMap.getFloat("y") * timelineScale;
						timeline.setFrame(frameIndex, valueMap.getFloat("time"), x, y);
						readCurve(timeline, frameIndex, valueMap);
						frameIndex++;
					}
					timelines[timelines.length] = timeline;
					duration = Math.max(duration, timeline.frames[timeline.frameCount * 3 - 3]);

				} else if (timelineName == "flipX" || timelineName == "flipY") {
					var flipX:Bool = timelineName == "flipX";
					var flipTimeline:FlipXTimeline = flipX ? new FlipXTimeline(values.length) : new FlipYTimeline(values.length);
					flipTimeline.boneIndex = boneIndex;
					
					var field:String = flipX ? "x" : "y";
					frameIndex = 0;
					for (valueMap in values) {
						flipTimeline.setFrame(frameIndex, valueMap.getFloat("time"), valueMap.getBool(field, false));
						frameIndex++;
					}
					timelines[timelines.length] = flipTimeline;
					duration = Math.max(duration, flipTimeline.frames[flipTimeline.frameCount * 3 - 3]);

				} else
					throw "Invalid timeline type for a bone: " + timelineName + " (" + boneName + ")";
			}
		}

		var ikMap:JsonNode = map.getNode("ik");
		for (ikConstraintName in ikMap.fields()) {
			var ikConstraint:IkConstraintData = skeletonData.findIkConstraint(ikConstraintName);
			values = ikMap.getNodesArray(ikConstraintName);
			var ikTimeline:IkConstraintTimeline = new IkConstraintTimeline(values.length);
			ikTimeline.ikConstraintIndex = skeletonData.ikConstraints.indexOf(ikConstraint);
			frameIndex = 0;
			for (valueMap in values) {
				var mix:Float = valueMap.getFloat("mix", 1);
				var bendDirection:Int = valueMap.getBool("bendPositive", true) ? 1 : -1;
				ikTimeline.setFrame(frameIndex, valueMap.getFloat("time"), mix, bendDirection);
				readCurve(ikTimeline, frameIndex, valueMap);
				frameIndex++;
			}
			timelines[timelines.length] = ikTimeline;
			duration = Math.max(duration, ikTimeline.frames[ikTimeline.frameCount * 3 - 3]);
		}

		var ffd:JsonNode = map.getNode("ffd");
		for (skinName in ffd.fields()) {
			var skin:Skin = skeletonData.findSkin(skinName);
			slotMap = ffd.getNode(skinName);
			for (slotName in slotMap.fields()) {
				slotIndex = skeletonData.findSlotIndex(slotName);
				var meshMap:JsonNode = slotMap.getNode(slotName);
				for (meshName in meshMap.fields()) {
					values = meshMap.getNodesArray(meshName);
					var ffdTimeline:FfdTimeline = new FfdTimeline(values.length);
					var attachment:Attachment = skin.getAttachment(slotIndex, meshName);
					if (attachment == null) throw "FFD attachment not found: " + meshName;
					ffdTimeline.slotIndex = slotIndex;
					ffdTimeline.attachment = attachment;

					var vertexCount:Int = 0;
					if (Std.is(attachment, MeshAttachment))
						vertexCount = cast(attachment, MeshAttachment).vertices.length;
					else
						vertexCount = Std.int(cast(attachment, SkinnedMeshAttachment).weights.length / 3 * 2);

					frameIndex = 0;
					for (valueMap in values) {
						var vertices:Array<Float>;
						if (!valueMap.hasOwnProperty("vertices")) {
							if (Std.is(attachment, MeshAttachment))
								vertices = cast(attachment, MeshAttachment).vertices;
							else
								vertices = new Array<Float>();
						} else {
							var verticesValue:Array<Float> = valueMap.getFloatArray("vertices", 1);
							var start:Int = valueMap.getInt("offset");
							var n:Int = verticesValue.length;
							vertices = new Array();
							for (i in 0...vertexCount) { vertices[i] = 0; }
							if (scale == 1) {
								for (i in 0 ... n)
									vertices[i + start] = verticesValue[i];
							} else {
								for (i in 0 ... n)
									vertices[i + start] = verticesValue[i] * scale;
							}
							if (Std.is(attachment, MeshAttachment)) {
								var meshVertices:Array<Float> = cast(attachment, MeshAttachment).vertices;
								for (i in 0 ... vertexCount)
									vertices[i] += meshVertices[i];
							}
						}
						
						ffdTimeline.setFrame(frameIndex, valueMap.getFloat("time"), vertices);
						readCurve(ffdTimeline, frameIndex, valueMap);
						frameIndex++;
					}
					timelines[timelines.length] = ffdTimeline;
					duration = Math.max(duration, ffdTimeline.frames[ffdTimeline.frameCount - 1]);
				}
			}
		}

		var drawOrderValues:Array<{slot:String, offset: Int}> = map.getNode("drawOrder");
		if (drawOrderValues == null) drawOrderValues = map.getNode("draworder");
		if (drawOrderValues != null && drawOrderValues.length > 0) {
			var drawOrderTimeline:DrawOrderTimeline = new DrawOrderTimeline(drawOrderValues.length);
			var slotCount:Int = skeletonData.slots.length;
			frameIndex = 0;
			for (drawOrderMap in drawOrderValues) {
				var drawOrder:Vector<Int> = null;
				if (drawOrderMap.hasOwnProperty("offsets")) {
					drawOrder = new Vector<Int>(slotCount);
					var i = slotCount - 1;
					while (i >= 0)
						drawOrder[i--] = -1;
					var offsets:Array<JsonNode> = drawOrderMap.getNodesArray("offsets");
					var unchanged:Vector<Int> = new Vector<Int>(Std.int(slotCount - offsets.length));
					var originalIndex:Int = 0, unchangedIndex:Int = 0;
					for (offsetMap in offsets) {
						slotIndex = skeletonData.findSlotIndex(offsetMap.getStr("slot"));
						if (slotIndex == -1) throw "Slot not found: " + offsetMap.getStr("slot");
						// Collect unchanged items.
						while (originalIndex != slotIndex)
							unchanged[unchangedIndex++] = originalIndex++;
						// Set changed items.
						drawOrder[originalIndex + offsetMap.getInt("offset")] = originalIndex++;
					}
					// Collect remaining unchanged items.
					while (originalIndex < slotCount)
						unchanged[unchangedIndex++] = originalIndex++;
					// Fill in unchanged items.
					var i = slotCount - 1;
					while (i >= 0) {
						if (drawOrder[i] == -1) drawOrder[i] = unchanged[--unchangedIndex];
						i--;
					}
				}
				drawOrderTimeline.setFrame(frameIndex++, drawOrderMap.getFloat("time"), drawOrder);
			}
			timelines[timelines.length] = drawOrderTimeline;
			duration = Math.max(duration, drawOrderTimeline.frames[drawOrderTimeline.frameCount - 1]);
		}

		var eventsMap:JsonNode = map.getNode("events");
		if (eventsMap != null && eventsMap.length > 0) {
			var eventTimeline:EventTimeline = new EventTimeline(eventsMap.length);
			frameIndex = 0;
			for (eventMap in cast(eventsMap, Array<JsonNode>)) {
				var eventData:EventData = skeletonData.findEvent(eventMap.getStr("name"));
				if (eventData == null) throw "Event not found: " + eventMap.getStr("name");
				var event:Event = new Event(eventData);
				event.intValue = eventMap.getInt("int", eventData.intValue);
				event.floatValue = eventMap.getFloat("float", event.floatValue);
				event.stringValue = eventMap.getStr("string", eventData.stringValue);
				eventTimeline.setFrame(frameIndex++, eventMap.getFloat("time"), event);
			}
			timelines[timelines.length] = eventTimeline;
			duration = Math.max(duration, eventTimeline.frames[eventTimeline.frameCount - 1]);
		}

		skeletonData.animations[skeletonData.animations.length] = new Animation(name, timelines, duration);
	}

	static private function readCurve (timeline:CurveTimeline, frameIndex:Int, valueMap:JsonNode) : Void {
		var curve:JsonNode = valueMap.getNode("curve");
		if (curve == null) return;
		if (Std.is(curve, String) && cast(curve, String) == "stepped")
			timeline.setStepped(frameIndex);
		else if (Std.is(curve, Array))
			timeline.setCurve(frameIndex, curve[0], curve[1], curve[2], curve[3]);
	}

	static private function toColor (hexString:String, colorIndex:Int) : Float {
		if (hexString.length != 8) throw new IllegalArgumentException("Color hexidecimal length must be 8, recieved: " + hexString);
		return Std.parseInt("0x" + hexString.substring(colorIndex * 2, colorIndex * 2 + 2)) / 255;
	}
}
