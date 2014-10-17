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

import flash.display.Sprite;

import spinehaxe.Event;
import spinehaxe.SkeletonData;
import spinehaxe.SkeletonJson;
import spinehaxe.animation.AnimationStateData;
import spinehaxe.atlas.TextureAtlas;
import spinehaxe.attachments.AtlasAttachmentLoader;
import spinehaxe.platform.openfl.BitmapDataTextureLoader;
import spinehaxe.platform.openfl.SkeletonAnimation;

import openfl.Assets;


class Main extends Sprite {
	private var skeleton:SkeletonAnimation;

	var time:Float = 0;
	var lastTime:Float = 0;

	public function new () {
		super();

		lastTime = haxe.Timer.stamp();

		var atlas = TextureAtlas.create(Assets.getText("assets/spineboy.atlas"), "assets/", new BitmapDataTextureLoader());
		var json = SkeletonJson.create(atlas);
		json.scale = 0.6;
		var skeletonData:SkeletonData = json.readSkeletonData(Assets.getText("assets/spineboy.json"), "spineboy");

		var stateData:AnimationStateData = new AnimationStateData(skeletonData);
		stateData.setMixByName("walk", "jump", 0.2);
		stateData.setMixByName("jump", "run", 0.4);
		stateData.setMixByName("jump", "jump", 0.2);

		skeleton = new SkeletonAnimation(skeletonData, stateData);
		skeleton.x = 320;
		skeleton.y = 420;
		
		skeleton.state.onStart.add(function (trackIndex:Int, e:Dynamic) : Void {
			trace(trackIndex + " start: " + skeleton.state.getCurrent(trackIndex));
		});
		skeleton.state.onEnd.add(function (trackIndex:Int, e:Dynamic) : Void {
			trace(trackIndex + " end: " + skeleton.state.getCurrent(trackIndex));
		});
		skeleton.state.onComplete.add(function (trackIndex:Int, count:Int) : Void {
			trace(trackIndex + " complete: " + skeleton.state.getCurrent(trackIndex) + ", " + count);
		});
		skeleton.state.onEvent.add(function (trackIndex:Int, event:Event) : Void {
			trace(trackIndex + " event: " + skeleton.state.getCurrent(trackIndex) + ", "
				+ event.data.name + ": " + event.intValue + ", " + event.floatValue + ", " + event.stringValue);
		});
		
		skeleton.state.setAnimationByName(0, "walk", true);
		//skeleton.state.addAnimationByName(0, "jump", false, 3);
		//skeleton.state.addAnimationByName(0, "run", true, 0);

		addChild(skeleton);
		flash.Lib.current.addEventListener(flash.events.Event.ENTER_FRAME, enterFrame);
	}

	public function enterFrame(e:flash.events.Event):Void {
		var delta = (haxe.Timer.stamp() - lastTime);
		lastTime = haxe.Timer.stamp();
		skeleton.advanceTime(delta);
	}

	static function main()
	{
		var main = new Main();
		
		flash.Lib.current.stage.addChild(main);
	}
}