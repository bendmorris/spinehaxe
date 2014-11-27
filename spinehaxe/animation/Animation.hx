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
package spinehaxe.animation;

import spinehaxe.Event;
import spinehaxe.Skeleton;
import spinehaxe.Exception;
import haxe.ds.Vector;

class Animation {
	public var timelines:Array<Timeline>;
	public var name:String;

	public var duration:Float = 0;
	public function new(name:String, timelines:Array<Timeline>, duration:Float) {
		if (name == null)
			throw new IllegalArgumentException("name cannot be null.");
		if (timelines == null)
			throw new IllegalArgumentException("timelines cannot be null.");
		this.name = name;
		this.timelines = timelines;
		this.duration = duration;
	}

	/** Poses the skeleton at the specified time for this animation. */
	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, loop:Bool, events:Array<Event>):Void {
		if (skeleton == null)
			throw new IllegalArgumentException("skeleton cannot be null.");
		if (loop && duration != 0) {
			time %= duration;
			lastTime %= duration;
		}
		var n:Int = timelines.length;
		for(i in 0...n) {
			timelines[i].apply(skeleton, lastTime, time, events, 1);
		}
	}

	/** Poses the skeleton at the specified time for this animation mixed with the current pose.
	 * @param alpha The amount of this animation that affects the current pose. */
	public function mix(skeleton:Skeleton, lastTime:Float, time:Float, loop:Bool, events:Array<Event>, alpha:Float):Void {
		if (skeleton == null)
			throw new IllegalArgumentException("skeleton cannot be null.");
		if (loop && duration != 0) {
			time %= duration;
			lastTime %= duration;
		}
		var n:Int = timelines.length;
		for (i in 0...n) {
			timelines[i].apply(skeleton, lastTime, time, events, alpha);
		}
	}

	public function toString():String {
		return name;
	}

	/** @param target After the first and before the last entry. */
	static public function binarySearch(values:Vector<Float>, target:Float, step:Int):Int {
		var low:Int = 0;
		var high:Int = Std.int(values.length / step - 2);
		if (high == 0)
			return step;
		var current:Int = high >>> 1;
		while(true) {
			if (values[(current + 1) * step] <= target)
				low = current + 1;
			else high = current;
			if (low == high)
				return (low + 1) * step;
			current = (low + high) >>> 1;
		}

		return 0;
	}

	/** @param target After the first and before the last entry. */
	static public function binarySearch1 (values:Vector<Float>, target:Float):Int {
		var low:Int = 0;
		var high:Int = values.length - 2;
		if (high == 0)
			return 1;
		var current:Int = high >>> 1;
		while (true) {
			if (values[current + 1] <= target)
				low = current + 1;
			else
				high = current;
			if (low == high)
				return low + 1;
			current = (low + high) >>> 1;
		}
		return 0; // Can't happen.
	}

	static public function linearSearch(values:Array<Float>, target:Float, step:Int):Int {
		var i:Int = 0;
		var last:Int = values.length - step;
		while(i <= last) {
			if (values[i] > target)
				return i;
			i += step;
		}
		return -1;
	}

}

