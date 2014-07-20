import spinehaxe.Bone;
import spinehaxe.Skeleton;
import spinehaxe.SkeletonData;
import spinehaxe.SkeletonJson;
import spinehaxe.animation.AnimationState;
import spinehaxe.animation.AnimationStateData;
import spinehaxe.atlas.TextureAtlas;
import spinehaxe.platform.nme.BitmapDataTextureLoader;
import spinehaxe.platform.nme.renderers.SkeletonRenderer;
import spinehaxe.atlas.TextureAtlas;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;

import flash.Lib;
import openfl.Assets;
import openfl.display.FPS;

class AnimationStateTest extends Sprite {

    var renderer:SkeletonRenderer;

    var atlas:TextureAtlas;
    var skeleton:Skeleton;
    var root_:Bone;
    var state:AnimationState;
    var lastTime:Float = 0.0;

    var mode:Int = 1;

    public function new() {
        super();
        lastTime = haxe.Timer.stamp();

        atlas = TextureAtlas.create(Assets.getText("assets/spineboy.atlas"), "assets/", new BitmapDataTextureLoader());
        var json = SkeletonJson.create(atlas);
		json.scale = 0.6;
        var skeletonData:SkeletonData = json.readSkeletonData(Assets.getText("assets/spineboy.json"), "spineboy");

        // Define mixing between animations.
        var stateData = new AnimationStateData(skeletonData);
        stateData.setMixByName("walk", "jump", 0.2);
        stateData.setMixByName("jump", "walk", 0.4);
        stateData.setMixByName("jump", "jump", 0.2);

        state = new AnimationState(stateData);
        state.setAnimationByName(0, "walk", true);

        skeleton = new Skeleton(skeletonData);

        skeleton.x = 150;
        skeleton.y = 450;
        skeleton.flipY = true;

        skeleton.updateWorldTransform();

        lastTime = haxe.Timer.stamp();

        renderer = new SkeletonRenderer(skeleton);
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
//        mode++;
//        mode%=3;
        state.setAnimationByName(0, "jump", false);
        state.addAnimationByName(0, "walk", true, 0.5);
    }

    public function render(e:Event):Void {
        var delta = (haxe.Timer.stamp() - lastTime) / 3;
        lastTime = haxe.Timer.stamp();
        state.update(delta);
        state.apply(skeleton);
		var anim = state.getCurrent(0);
        if (anim.toString() == "walk") {
            // After one second, change the current animation. Mixing is done by AnimationState for you.
            if (anim.time > 2) state.setAnimationByName(0, "jump", false);
        } else {
            if (anim.time > 1) state.setAnimationByName(0, "walk", true);
        }

        skeleton.updateWorldTransform();

        renderer.visible = true;
        renderer.draw();

    }

	static function main()
	{
		var main = new AnimationStateTest();

		Lib.current.addChild(main);
	}

}
