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
import spinehaxe.animation.DeformTimeline;
import spinehaxe.animation.DrawOrderTimeline;
import spinehaxe.animation.EventTimeline;
import spinehaxe.animation.IkConstraintTimeline;
import spinehaxe.animation.PathConstraintMixTimeline;
import spinehaxe.animation.PathConstraintPositionTimeline;
import spinehaxe.animation.PathConstraintSpacingTimeline;
import spinehaxe.animation.RotateTimeline;
import spinehaxe.animation.ScaleTimeline;
import spinehaxe.animation.ShearTimeline;
import spinehaxe.animation.Timeline;
import spinehaxe.animation.TranslateTimeline;
import spinehaxe.animation.TransformConstraintTimeline;
import spinehaxe.attachments.Attachment;
import spinehaxe.attachments.AttachmentLoader;
import spinehaxe.attachments.AttachmentType;
import spinehaxe.attachments.BoundingBoxAttachment;
import spinehaxe.attachments.MeshAttachment;
import spinehaxe.attachments.PathAttachment;
import spinehaxe.attachments.RegionAttachment;
import spinehaxe.attachments.VertexAttachment;
import haxe.ds.Vector;

class SkeletonJson {
	public var attachmentLoader:AttachmentLoader;
	public var scale:Float = 1;
	var linkedMeshes:Array<LinkedMesh> = new Array<LinkedMesh>();

	public function new(?attachmentLoader:AttachmentLoader) {
		this.attachmentLoader = attachmentLoader;
	}

	public function readSkeletonData(object:String, ?name:String):SkeletonData {
		if (object == null) throw "object cannot be null.";

		var root:JsonNode = JsonNode.parse(object);

		var skeletonData:SkeletonData = new SkeletonData();
		skeletonData.name = name;

		// Skeleton.
		if (root.hasOwnProperty("skeleton")) {
			var skeletonMap:JsonNode = root.getNode("skeleton");
			skeletonData.hash = skeletonMap.getStr("hash");
			skeletonData.version = skeletonMap.getStr("spine");
			skeletonData.width = skeletonMap.getFloat("width");
			skeletonData.height = skeletonMap.getFloat("height");
			skeletonData.fps = skeletonMap.getFloat("fps");
			skeletonData.imagesPath = skeletonMap.getStr("images");
		}

		// Bones.
		for (boneMap in root.getNodesArray("bones")) {
			var parent:BoneData = null;
			var parentName:String = boneMap.getStr("parent");
			if (parentName != null) {
				parent = skeletonData.findBone(parentName);
				if (parent == null) throw "Parent bone not found: " + parentName;
			}
			var boneData = new BoneData(skeletonData.bones.length, boneMap.getStr("name"), parent);
			boneData.length = boneMap.getFloat("length", 0) * scale;
			boneData.x = boneMap.getFloat("x", 0) * scale;
			boneData.y = boneMap.getFloat("y", 0) * scale;
			boneData.rotation = boneMap.getFloat("rotation");
			boneData.scaleX = boneMap.getFloat("scaleX", 1);
			boneData.scaleY = boneMap.getFloat("scaleY", 1);
			boneData.shearX = boneMap.getFloat("shearX", 0);
			boneData.shearY = boneMap.getFloat("shearY", 0);
			boneData.transformMode = boneMap.getStr("transform", TransformMode.normal);
			skeletonData.bones.push(boneData);
		}

		// Slots.
		for (slotMap in root.getNodesArray("slots")) {
			var slotName = slotMap.getStr("name");
			var boneName = slotMap.getStr("bone");
			var boneData = skeletonData.findBone(boneName);
			if (boneData == null) throw "Slot bone not found: " + boneName;
			var slotData:SlotData = new SlotData(skeletonData.slots.length, slotName, boneData);

			var color:String = slotMap.getStr("color");
			if (color != null) {
				slotData.r = toColor(color, 0);
				slotData.g = toColor(color, 1);
				slotData.b = toColor(color, 2);
				slotData.a = toColor(color, 3);
			}

			slotData.attachmentName = slotMap.getStr("attachment");
			slotData.blendMode = slotMap.getStr("blend", BlendMode.normal);
			skeletonData.slots.push(slotData);
		}

		// IK constraints.
		var constraints:JsonNode = root.getNode("ik");
		for (constraintName in constraints.fields()) {
			var constraintMap:JsonNode = constraints.getNode(constraintName);
			var ikConstraintData:IkConstraintData = new IkConstraintData(constraintMap.getStr("name"));
			ikConstraintData.order = constraintMap.getFloat("order", 0);

			for (boneName in constraintMap.getStrArray("bones")) {
				var bone:BoneData = skeletonData.findBone(boneName);
				if (bone == null) throw "IK constraint bone not found: " + boneName;
				ikConstraintData.bones.push(bone);
			}

			ikConstraintData.target = skeletonData.findBone(constraintMap.getStr("target"));
			if (ikConstraintData.target == null) throw "Target bone not found: " + constraintMap.getStr("target");

			ikConstraintData.bendDirection = (!constraintMap.hasOwnProperty("bendPositive") || constraintMap.getBool("bendPositive")) ? 1 : -1;
			ikConstraintData.mix = constraintMap.hasOwnProperty("mix") ? constraintMap.getFloat("mix") : 1;

			skeletonData.ikConstraints.push(ikConstraintData);
		}

		// Transform constraints.
		var constraints:JsonNode = root.getNode("transform");
		for (constraintName in constraints.fields()) {
			var constraintMap:JsonNode = constraints.getNode(constraintName);
			var transformConstraintData:TransformConstraintData = new TransformConstraintData(constraintMap.getStr("name"));
			transformConstraintData.order = constraintMap.getFloat("order", 0);

			for (boneName in constraintMap.getStrArray("bones")) {
				var bone = skeletonData.findBone(boneName);
				if (bone == null) throw "Transform constraint bone not found: " + boneName;
				transformConstraintData.bones.push(bone);
			}

			transformConstraintData.target = skeletonData.findBone(constraintMap.getStr("target"));
			if (transformConstraintData.target == null) throw "Target bone not found: " + constraintMap.getStr("target");

			transformConstraintData.offsetRotation = constraintMap.getFloat("rotation", 0);
			transformConstraintData.offsetX = constraintMap.getFloat("x", 0) * scale;
			transformConstraintData.offsetY = constraintMap.getFloat("y", 0) * scale;
			transformConstraintData.offsetScaleX = constraintMap.getFloat("scaleX", 0);
			transformConstraintData.offsetScaleY = constraintMap.getFloat("scaleY", 0);
			transformConstraintData.offsetShearY = constraintMap.getFloat("shearY", 0);

			transformConstraintData.rotateMix = constraintMap.hasOwnProperty("rotateMix") ? constraintMap.getFloat("rotateMix") : 1;
			transformConstraintData.translateMix = constraintMap.hasOwnProperty("translateMix") ? constraintMap.getFloat("translateMix") : 1;
			transformConstraintData.scaleMix = constraintMap.hasOwnProperty("scaleMix") ? constraintMap.getFloat("scaleMix") : 1;
			transformConstraintData.shearMix = constraintMap.hasOwnProperty("shearMix") ? constraintMap.getFloat("shearMix") : 1;

			skeletonData.transformConstraints.push(transformConstraintData);
		}

		// Path constraints.
		var constraints:JsonNode = root.getNode("path");
		for (constraintName in constraints.fields()) {
			var constraintMap:JsonNode = constraints.getNode(constraintName);
			var pathConstraintData:PathConstraintData = new PathConstraintData(constraintMap.getStr("name"));
			pathConstraintData.order = constraintMap.getFloat("order", 0);

			for (boneName in constraintMap.getStrArray("bones")) {
				var bone = skeletonData.findBone(boneName);
				if (bone == null) throw "Path constraint bone not found: " + boneName;
				pathConstraintData.bones.push(bone);
			}

			pathConstraintData.target = skeletonData.findSlot(constraintMap.getStr("target"));
			if (pathConstraintData.target == null) throw "Path target slot not found: " + constraintMap.getStr("target");

			pathConstraintData.positionMode = constraintMap.getStr("positionMode", PositionMode.percent);
			pathConstraintData.spacingMode = constraintMap.getStr("spacingMode", SpacingMode.length);
			pathConstraintData.rotateMode = constraintMap.getStr("rotateMode", RotateMode.tangent);
			pathConstraintData.offsetRotation = constraintMap.getFloat("rotation", 0);
			pathConstraintData.position = constraintMap.getFloat("position", 0);
			if (pathConstraintData.positionMode == PositionMode.fixed) pathConstraintData.position *= scale;
			pathConstraintData.spacing = constraintMap.getFloat("spacing", 0);
			if (pathConstraintData.spacingMode == SpacingMode.length || pathConstraintData.spacingMode == SpacingMode.fixed) pathConstraintData.spacing *= scale;
			pathConstraintData.rotateMix = constraintMap.hasOwnProperty("rotateMix") ? constraintMap.getFloat("rotateMix") : 1;
			pathConstraintData.translateMix = constraintMap.hasOwnProperty("translateMix") ? constraintMap.getFloat("translateMix") : 1;

			skeletonData.pathConstraints.push(pathConstraintData);
		}

		// Skins.
		var skins:JsonNode = root.getNode("skins");
		for (skinName in skins.fields()) {
			var skinMap:JsonNode = skins.getNode(skinName);
			var skin:Skin = new Skin(skinName);
			for (slotName in skinMap.fields()) {
				var slotIndex:Int = skeletonData.findSlotIndex(slotName);
				var slotEntry:JsonNode = skinMap.getNode(slotName);
				for (attachmentName in slotEntry.fields()) {
					var attachment:Attachment = readAttachment(slotEntry.getNode(attachmentName), skin, slotIndex, attachmentName);
					if (attachment != null)
						skin.addAttachment(slotIndex, attachmentName, attachment);
				}
			}
			skeletonData.skins.push(skin);
			if (skin.name == "default")
				skeletonData.defaultSkin = skin;
		}

		// Linked meshes.
		var linkedMeshes:Array<LinkedMesh> = this.linkedMeshes;
		for (linkedMesh in linkedMeshes) {
			var parentSkin:Skin = (linkedMesh.skin == null) ? skeletonData.defaultSkin : skeletonData.findSkin(linkedMesh.skin);
			if (parentSkin == null) throw "Skin not found: " + linkedMesh.skin;
			var parentMesh:MeshAttachment = cast parentSkin.getAttachment(linkedMesh.slotIndex, linkedMesh.parent);
			if (parentMesh == null) throw "Parent mesh not found: " + linkedMesh.parent;
			linkedMesh.mesh.parentMesh = parentMesh;
			linkedMesh.mesh.updateUVs();
		}
		ArrayUtils.clearArray(linkedMeshes);

		// Events.
		var events:JsonNode = root.getNode("events");
		if (events != null) {
			for (eventName in events.fields()) {
				var eventMap:JsonNode = events.getNode(eventName);
				var eventData:EventData = new EventData(eventName);
				eventData.intValue = eventMap.getInt("int");
				eventData.floatValue = eventMap.getFloat("float");
				eventData.stringValue = eventMap.getStr("string", "");
				skeletonData.events.push(eventData);
			}
		}

		// Animations.
		var animations:JsonNode = root.getNode("animations");
		for (animationName in animations.fields())
			readAnimation(animations.getNode(animationName), animationName, skeletonData);

		return skeletonData;
	}

	private function readVertices(map:JsonNode, attachment:VertexAttachment, verticesLength:Int):Void {
		attachment.worldVerticesLength = verticesLength;
		var vertices:Array<Float> = map.getFloatArray("vertices", 1);
		if (verticesLength == vertices.length) {
			if (scale != 1) {
				for (i in 0 ... vertices.length) {
					vertices[i] *= scale;
				}
			}
			attachment.vertices = vertices;
			return;
		}

		var weights:Array<Float> = new Array<Float>();
		var bones:Array<Int> = new Array<Int>();
		var i = 0, n = vertices.length;
		/*while (i < n) {
			var boneCount:Int = Std.int(vertices[i++]);
			bones.push(boneCount);
			var nn:Int = i + boneCount * 4;
			while (i < nn) {
				bones.push(Std.int(vertices[i]));
				weights.push(vertices[i + 1] * scale);
				weights.push(vertices[i + 2] * scale);
				weights.push(vertices[i + 3]);
				i += 4;
			}
		}*/
		attachment.bones = bones;
		attachment.vertices = weights;
	}

	private function readAttachment(map:JsonNode, skin:Skin, slotIndex:Int, name:String):Attachment {
		name = map.getStr("name", name);

		var type:AttachmentType = map.getStr("type", "region");
		var path:String = map.getStr("path", name);

		var scale:Float = this.scale;
		var color:String;
		switch (type) {
			case AttachmentType.Region:
				var region:RegionAttachment = attachmentLoader.newRegionAttachment(skin, name, path);
				if (region == null) return null;
				region.path = path;
				region.x = map.getFloat("x", 0) * scale;
				region.y = map.getFloat("y", 0) * scale;
				region.scaleX = map.getFloat("scaleX", 1);
				region.scaleY = map.getFloat("scaleY", 1);
				region.rotation = map.getFloat("rotation");
				region.width = map.getFloat("width", 0) * scale;
				region.height = map.getFloat("height", 0) * scale;

				color = map.getStr("color");
				if (color != null) {
					region.r = toColor(color, 0);
					region.g = toColor(color, 1);
					region.b = toColor(color, 2);
					region.a = toColor(color, 3);
				}

				region.updateOffset();
				return region;

			case AttachmentType.Mesh, AttachmentType.LinkedMesh:
				var mesh:MeshAttachment = attachmentLoader.newMeshAttachment(skin, name, path);
				if (mesh == null) return null;
				mesh.path = path;

				color = map.getStr("color");
				if (color != null) {
					mesh.r = toColor(color, 0);
					mesh.g = toColor(color, 1);
					mesh.b = toColor(color, 2);
					mesh.a = toColor(color, 3);
				}

				mesh.width = map.getFloat("width", 0) * scale;
				mesh.height = map.getFloat("height", 0) * scale;

				if (map.getStr("parent") != null) {
					mesh.inheritDeform = map.getBool("deform", true);
					linkedMeshes.push(new LinkedMesh(mesh, map.getStr("skin"), slotIndex, map.getStr("parent")));
					return mesh;
				}

				var uvs:Array<Float> = map.getFloatArray("uvs", 1);
				readVertices(map, mesh, uvs.length);
				mesh.triangles = cast map.getUintArray("triangles");
				mesh.regionUVs = uvs;
				mesh.updateUVs();

				mesh.hullLength = map.getInt("hull", 0) * 2;
				if (map.hasOwnProperty("edges")) mesh.edges = map.getIntArray("edges");
				return mesh;

			case AttachmentType.BoundingBox:
				var box:BoundingBoxAttachment = attachmentLoader.newBoundingBoxAttachment(skin, name);
				if (box == null) return null;
				readVertices(map, box, map.getInt("vertexCount") << 1);
				return box;

			case AttachmentType.Path:
				var path:PathAttachment = attachmentLoader.newPathAttachment(skin, name);
				if (path == null) return null;
				path.closed = map.getBool("closed", false);
				path.constantSpeed = map.getBool("constantSpeed", true);

				var vertexCount:Int = map.getInt("vertexCount");
				readVertices(map, path, vertexCount << 1);

				var lengths:Array<Float> = new Array();
				for (curve in map.getFloatArray("lengths")) {
					lengths.push(curve * scale);
				}
				path.lengths = lengths;
				return path;

			default:
				throw "Attachment type not implemented: " + type;
		}

		return null;
	}

	private function readAnimation(map:JsonNode, name:String, skeletonData:SkeletonData):Void {
		var scale:Float = this.scale;
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
						readCurve(valueMap, colorTimeline, frameIndex);
						frameIndex++;
					}
					timelines.push(colorTimeline);
					duration = Math.max(duration, colorTimeline.frames[Std.int(colorTimeline.frameCount - 1) * ColorTimeline.ENTRIES]);

				} else if (timelineName == "attachment") {
					var attachmentTimeline:AttachmentTimeline = new AttachmentTimeline(values.length);
					attachmentTimeline.slotIndex = slotIndex;
					
					frameIndex = 0;
					for (valueMap in values)
						attachmentTimeline.setFrame(frameIndex++, valueMap.getFloat("time"), valueMap.getStr("name"));
					timelines.push(attachmentTimeline);
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
						readCurve(valueMap, rotateTimeline, frameIndex);
						frameIndex++;
					}
					timelines.push(rotateTimeline);
					duration = Math.max(duration, rotateTimeline.frames[Std.int(rotateTimeline.frameCount - 1) * RotateTimeline.ENTRIES]);

				} else if (timelineName == "translate" || timelineName == "scale" || timelineName == "shear") {
					var translateTimeline:TranslateTimeline;
					var timelineScale:Float = 1;
					if (timelineName == "scale")
						translateTimeline = new ScaleTimeline(values.length);
					else if (timelineName == "shear")
						translateTimeline = new ShearTimeline(values.length);
					else {
						translateTimeline = new TranslateTimeline(values.length);
						timelineScale = scale;
					}

					translateTimeline.boneIndex = boneIndex;

					frameIndex = 0;
					for (valueMap in values) {
						var x:Float = valueMap.getFloat("x", 0) * timelineScale;
						var y:Float = valueMap.getFloat("y", 0) * timelineScale;
						translateTimeline.setFrame(frameIndex, valueMap.getFloat("time"), x, y);
						readCurve(valueMap, translateTimeline, frameIndex);
						frameIndex++;
					}

					timelines.push(translateTimeline);
					duration = Math.max(duration, translateTimeline.frames[Std.int(translateTimeline.frameCount - 1) * TranslateTimeline.ENTRIES]);

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
				readCurve(valueMap, ikTimeline, frameIndex);
				frameIndex++;
			}
			timelines.push(ikTimeline);
			duration = Math.max(duration, ikTimeline.frames[Std.int(ikTimeline.frameCount - 1) * IkConstraintTimeline.ENTRIES]);
		}

		var transformMap:JsonNode = map.getNode("transform");
		for (transformName in transformMap.fields()) {
			var transformConstraint:TransformConstraintData = skeletonData.findTransformConstraint(transformName);
			values = transformMap.getNodesArray(transformName);
			var transformTimeline:TransformConstraintTimeline = new TransformConstraintTimeline(values.length);
			transformTimeline.transformConstraintIndex = skeletonData.transformConstraints.indexOf(transformConstraint);
			frameIndex = 0;
			for (valueMap in values) {
				var rotateMix:Float = valueMap.getFloat("rotateMix", 1);
				var translateMix:Float = valueMap.getFloat("translateMix", 1);
				var scaleMix:Float = valueMap.getFloat("scaleMix", 1);
				var shearMix:Float = valueMap.getFloat("shearMix", 1);
				transformTimeline.setFrame(frameIndex, valueMap.getFloat("time"), rotateMix, translateMix, scaleMix, shearMix);
				readCurve(valueMap, transformTimeline, frameIndex);
				frameIndex++;
			}
			timelines.push(transformTimeline);
			duration = Math.max(duration, transformTimeline.frames[Std.int(transformTimeline.frameCount - 1) * TransformConstraintTimeline.ENTRIES]);
		}

		// Path constraint timelines.
		var paths:JsonNode = map.getNode("paths");
		for (pathName in paths.fields()) {
			var index:Int = skeletonData.findPathConstraintIndex(pathName);
			if (index == -1) throw "Path constraint not found: " + pathName;
			var data:PathConstraintData = skeletonData.pathConstraints[index];

			var pathMap:JsonNode = paths.getNode(pathName);
			for (timelineName in pathMap.fields()) {
				values = pathMap.getNodesArray(timelineName);

				if (timelineName == "position" || timelineName == "spacing") {
					var pathTimeline:PathConstraintPositionTimeline;
					var timelineScale:Float = 1;
					if (timelineName == "spacing") {
						pathTimeline = new PathConstraintSpacingTimeline(values.length);
						if (data.spacingMode == SpacingMode.length || data.spacingMode == SpacingMode.fixed) timelineScale = scale;
					} else {
						pathTimeline = new PathConstraintPositionTimeline(values.length);
						if (data.positionMode == PositionMode.fixed) timelineScale = scale;
					}
					pathTimeline.pathConstraintIndex = index;
					frameIndex = 0;
					for (valueMap in values) {
						var value:Float = valueMap.getFloat(timelineName, 0);
						pathTimeline.setFrame(frameIndex, valueMap.getFloat("time"), value * timelineScale);
						readCurve(valueMap, pathTimeline, frameIndex);
						frameIndex++;
					}
					timelines.push(pathTimeline);
					duration = Math.max(duration,
						pathTimeline.frames[Std.int(pathTimeline.frameCount - 1) * PathConstraintPositionTimeline.ENTRIES]);
				} else if (timelineName == "mix") {
					var pathMixTimeline:PathConstraintMixTimeline = new PathConstraintMixTimeline(values.length);
					pathMixTimeline.pathConstraintIndex = index;
					frameIndex = 0;
					for (valueMap in values) {
						var rotateMix = valueMap.hasOwnProperty("rotateMix") ? valueMap.getFloat("rotateMix") : 1;
						var translateMix = valueMap.hasOwnProperty("translateMix") ? valueMap.getFloat("translateMix") : 1;
						pathMixTimeline.setFrame(frameIndex, valueMap.getFloat("time"), rotateMix, translateMix);
						readCurve(valueMap, pathMixTimeline, frameIndex);
						frameIndex++;
					}
					timelines.push(pathMixTimeline);
					duration = Math.max(duration,
						pathMixTimeline.frames[Std.int(pathMixTimeline.frameCount - 1) * PathConstraintMixTimeline.ENTRIES]);
				}
			}
		}

		var deformMap:JsonNode = map.getNode("deform");
		for (skinName in deformMap.fields()) {
			var skin:Skin = skeletonData.findSkin(skinName);
			slotMap = deformMap.getNode(skinName);
			for (slotName in slotMap.fields()) {
				slotIndex = skeletonData.findSlotIndex(slotName);
				var timelineMap:JsonNode = slotMap.getNode(slotName);
				for (timelineName in timelineMap.fields()) {
					values = timelineMap.getNodesArray(timelineName);

					var attachment:VertexAttachment = cast skin.getAttachment(slotIndex, timelineName);
					if (attachment == null) throw "Deform attachment not found: " + timelineName;
					var weighted:Bool = attachment.bones != null;
					var vertices:Array<Float> = attachment.vertices;
					var deformLength:Int = weighted ? Std.int(vertices.length / 3 * 2) : vertices.length;

					var deformTimeline:DeformTimeline = new DeformTimeline(values.length);
					deformTimeline.slotIndex = slotIndex;
					deformTimeline.attachment = attachment;

					frameIndex = 0;
					for (valueMap in values) {
						var deform:Array<Float>;
						var verticesValue:JsonNode = valueMap.getNode("vertices");
						if (verticesValue == null)
							deform = weighted ? new Array() : vertices;
						else {
							deform = new Array();
							var start:Int = valueMap.getInt("offset", 0);
							var temp:Array<Float> = valueMap.getFloatArray("vertices", 1);
							for (i in 0 ... start)
								deform[i] = 0;
							for (i in 0 ... temp.length) {
								deform[start + i] = temp[i];
							}
							for (i in deform.length ... deformLength) {
								deform[i] = 0;
							}
							if (scale != 1) {
								var n:Int;
								for (i in start ... start + temp.length)
									deform[i] *= scale;
							}
							if (!weighted) {
								for (i in 0 ... deformLength)
									deform[i] += vertices[i];
							}
						}

						deformTimeline.setFrame(frameIndex, valueMap.getFloat("time"), deform);
						readCurve(valueMap, deformTimeline, frameIndex);
						frameIndex++;
					}
					timelines[timelines.length] = deformTimeline;
					duration = Math.max(duration, deformTimeline.frames[Std.int(deformTimeline.frameCount - 1)]);
				}
			}
		}

		var drawOrderValues:Array<JsonNode> = map.getNodesArray("drawOrder");
		if (drawOrderValues == null) drawOrderValues = map.getNodesArray("draworder");
		if (drawOrderValues != null) {
			var drawOrderTimeline:DrawOrderTimeline = new DrawOrderTimeline(drawOrderValues.length);
			var slotCount:Int = skeletonData.slots.length;
			frameIndex = 0;
			for (drawOrderMap in drawOrderValues) {
				var drawOrder:Array<Int> = null;
				if (drawOrderMap.hasOwnProperty("offsets")) {
					drawOrder = new Array();
					for (i in 0 ... slotCount)
						drawOrder[i] = -1;
					var offsets:Array<JsonNode> = drawOrderMap.getNodesArray("offsets");
					var unchanged:Vector<Int> = new Vector(slotCount - offsets.length);
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
					var i:Int = slotCount - 1;
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

		var eventsMap:Array<JsonNode> = map.getNodesArray("events");
		if (eventsMap != null) {
			var eventTimeline:EventTimeline = new EventTimeline(eventsMap.length);
			frameIndex = 0;
			for (eventMap in eventsMap) {
				var eventData:EventData = skeletonData.findEvent(eventMap.getStr("name"));
				if (eventData == null) throw "Event not found: " + eventMap.getStr("name");
				var event:Event = new Event(eventMap.getFloat("time"), eventData);
				event.intValue = eventMap.hasOwnProperty("int") ? eventMap.getInt("int") : eventData.intValue;
				event.floatValue = eventMap.hasOwnProperty("float") ? eventMap.getFloat("float") : eventData.floatValue;
				event.stringValue = eventMap.hasOwnProperty("string") ? eventMap.getStr("string") : eventData.stringValue;
				eventTimeline.setFrame(frameIndex++, event);
			}
			timelines[timelines.length] = eventTimeline;
			duration = Math.max(duration, eventTimeline.frames[eventTimeline.frameCount - 1]);
		}

		skeletonData.animations[skeletonData.animations.length] = new Animation(name, timelines, duration);
	}

	static private function readCurve(map:JsonNode, timeline:CurveTimeline, frameIndex:Int) : Void {
		var curve:Dynamic = map.getDynamic("curve");
		if (curve == null) return;
		if (Std.is(curve, String) && cast(curve, String) == "stepped")
			timeline.setStepped(frameIndex);
		else if (Std.is(curve, Array)) {
			var curveValues:Array<Float> = cast curve;
			timeline.setCurve(frameIndex, curveValues[0], curveValues[1], curveValues[2], curveValues[3]);
		}
	}

	static private function toColor (hexString:String, colorIndex:Int) : Float {
		if (hexString.length != 8) throw new IllegalArgumentException("Color hexidecimal length must be 8, recieved: " + hexString);
		return Std.parseInt("0x" + hexString.substring(colorIndex * 2, colorIndex * 2 + 2)) / 255;
	}
}
