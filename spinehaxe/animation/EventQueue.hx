/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

package spinehaxe.animation;

import spinehaxe.Event;

class EventQueue {
	var entries:Array<TrackEntry> = new Array();
	var eventTypes:Array<EventType> = new Array();
	var events:Array<Event> = new Array();
	var animationState:AnimationState;
	public var drainDisabled:Bool;

	public function new(animationState:AnimationState) {
		this.animationState = animationState;
	}

	public function start(entry:TrackEntry):Void {
		eventTypes.push(EventType.start);
		entries.push(entry);
		animationState.animationsChanged = true;
	}

	public function interrupt(entry:TrackEntry):Void {
		eventTypes.push(EventType.interrupt);
		entries.push(entry);
	}

	public function end(entry:TrackEntry):Void {
		eventTypes.push(EventType.end);
		entries.push(entry);
		animationState.animationsChanged = true;
	}

	public function dispose(entry:TrackEntry):Void {
		eventTypes.push(EventType.dispose);
		entries.push(entry);
	}

	public function complete(entry:TrackEntry):Void {
		eventTypes.push(EventType.complete);
		entries.push(entry);
	}

	public function event(entry:TrackEntry, event:Event):Void {
		eventTypes.push(EventType.event);
		entries.push(entry);
		events.push(event);
	}

	public function drain ():Void {
		if (drainDisabled) return; // Not reentrant.
		drainDisabled = true;

		var i:Int = 0, eventIndex:Int = 0;
		for (i in 0 ... entries.length) {
			var type:EventType = eventTypes[i];
			var entry:TrackEntry = entries[i];
			switch (type) {
				case EventType.start:
					entry.onStart.invoke1(entry);
					animationState.onStart.invoke1(entry);
				case EventType.interrupt:
					entry.onInterrupt.invoke1(entry);
					animationState.onInterrupt.invoke1(entry);
				case EventType.end:
					entry.onEnd.invoke1(entry);
					animationState.onEnd.invoke1(entry);
					entry.onDispose.invoke1(entry);
					animationState.onDispose.invoke1(entry);
					animationState.trackEntryPool.free(entry);
				case EventType.dispose:
					entry.onDispose.invoke1(entry);
					animationState.onDispose.invoke1(entry);
					animationState.trackEntryPool.free(entry);
				case EventType.complete:
					entry.onComplete.invoke1(entry);
					animationState.onComplete.invoke1(entry);
				case EventType.event:
					var event:Event = events[eventIndex++];
					entry.onEvent.invoke2(entry, event);
					animationState.onEvent.invoke2(entry, event);
			}
		}
		clear();

		drainDisabled = false;
	}

	public function clear():Void {
		ArrayUtils.clearArray(eventTypes);
		ArrayUtils.clearArray(entries);
		ArrayUtils.clearArray(events);
	}
}
