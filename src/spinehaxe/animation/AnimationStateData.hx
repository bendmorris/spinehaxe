/******************************************************************************
 * Spine Runtime Software License - Version 1.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Essential, Professional, Enterprise, or Education License must
 *    be purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
package spinehaxe.animation;

import spinehaxe.SkeletonData;
import spinehaxe.Exception;

class AnimationStateData {
	public var skeletonData:SkeletonData;

	var animationToMixTime:Map<String, Float>;
	public var defaultMix:Float;
	public function new(skeletonData:SkeletonData) {
		animationToMixTime = new Map();
		defaultMix = 0;
		this.skeletonData = skeletonData;
	}

	public function setMixByName(fromName:String, toName:String, duration:Float):Void {
		var from:Animation = skeletonData.findAnimation(fromName);
		if(from == null) 
			throw new IllegalArgumentException("Animation not found: " + fromName);
		var to:Animation = skeletonData.findAnimation(toName);
		if(to == null) 
			throw new IllegalArgumentException("Animation not found: " + toName);
		setMix(from, to, duration);
	}

	public function setMix(from:Animation, to:Animation, duration:Float):Void {
		if(from == null) 
			throw new IllegalArgumentException("from cannot be null.");
		if(to == null) 
			throw new IllegalArgumentException("to cannot be null.");
		animationToMixTime[from.name + ":" + to.name] = duration;
	}

	public function getMix(from:Animation, to:Animation):Float {
		var key = from.name + ":" + to.name;
		if(!animationToMixTime.exists(key)) 
			return defaultMix;
		var time:Dynamic = animationToMixTime[key];
		return time;
	}

}

