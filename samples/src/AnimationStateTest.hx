import spinehaxe.attachments.AtlasAttachmentLoader;
import spinehaxe.Bone;
import spinehaxe.Skeleton;
import spinehaxe.SkeletonData;
import spinehaxe.SkeletonJson;
import spinehaxe.animation.AnimationState;
import spinehaxe.animation.AnimationStateData;
import spinehaxe.atlas.Atlas;
import spinehaxe.platform.openfl.BitmapDataTextureLoader;
import spinehaxe.platform.openfl.SkeletonAnimation;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;

import flash.Lib;
import openfl.Assets;
import openfl.display.FPS;

class AnimationStateTest extends Sprite {
	var renderer:SkeletonAnimation;

	var atlas:Atlas;
	var skeleton:Skeleton;
	var root_:Bone;
	var state:AnimationState;
	var lastTime:Float = 0.0;

	var mode:Int = 1;

	public function new() {
		super();
		lastTime = haxe.Timer.stamp();

		atlas = new Atlas(Assets.getText("assets/spineboy.atlas"), new BitmapDataTextureLoader("assets/"));
		var json = new SkeletonJson(new AtlasAttachmentLoader(atlas));
		json.scale = 0.6;
		var skeletonData:SkeletonData = json.readSkeletonData(Assets.getText("assets/spineboy.json"), "spineboy");

		// Define mixing between animations.
		var stateData = new AnimationStateData(skeletonData);
		stateData.setMixByName("walk", "jump", 0.2);
		stateData.setMixByName("jump", "run", 0.4);
		stateData.setMixByName("jump", "walk", 0.4);
		stateData.setMixByName("jump", "jump", 0.2);

		renderer = new SkeletonAnimation(skeletonData, stateData);
		skeleton = renderer.skeleton;
		trace(skeleton);
		skeleton.flipX = false;
		#if mesh
		renderer.renderMeshes = true;
		#end
		renderer.x = 150;
		renderer.y = 450;

		state = renderer.state;
		state.onStart.add(function (trackEntry) {
			trace(trackEntry.trackIndex + " fuu start");
		});
		state.onEnd.add(function (trackEntry) {
			trace(trackEntry.trackIndex + " end");
		});
		state.onComplete.add(function (trackEntry) {
			trace(trackEntry.trackIndex + " complete");
		});
		state.onEvent.add(function (trackEntry, event) {
			trace(trackEntry.trackIndex + " event: " + event.data + ": " + event.intValue + ", " + event.floatValue + ", " + event.stringValue);
		});

		state.setAnimationByName(0, "walk", true);
		state.addAnimationByName(0, "jump", false, 3);
		state.addAnimationByName(0, "run", true, 0);

		lastTime = haxe.Timer.stamp();

		addChild(renderer);
		addChild(new FPS());

		Lib.current.addEventListener(Event.ENTER_FRAME, render);
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	public function added(e:Event):Void {
		this.mouseChildren = false;
		stage.addEventListener(MouseEvent.CLICK, onClick);
	}

	public function onClick(e:Event):Void {
		state.setAnimationByName(0, "jump", false);
		state.addAnimationByName(0, "walk", true, 0.5);
	}

	public function render(e:Event):Void {
		var t = haxe.Timer.stamp(),
			delta = (t - lastTime) / 3;
		lastTime = t;
		state.update(delta);
		state.apply(skeleton);
		skeleton.updateWorldTransform();
		renderer.visible = true;
	}

	static function main()
	{
		var main = new AnimationStateTest();

		Lib.current.addChild(main);
	}
}
