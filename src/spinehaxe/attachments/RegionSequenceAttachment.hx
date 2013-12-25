/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
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
 ******************************************************************************/

package spinehaxe.attachments;
import spinehaxe.Exception;
import spinehaxe.atlas.TextureRegion;
class RegionSequenceAttachment extends RegionAttachment {
    private var mode:Mode;
    private var frameTime:Float;
    private var regions:Array<TextureRegion>;

    public function new (name:String) {
        super(name);
    }

    public override function updateVertices (slot:Slot):Void {
        if (regions == null) throw new IllegalStateException("Regions have not been set: " + this);

        var frameIndex:Int = Math.floor(slot.attachmentTime / frameTime);
        switch (mode) {
            case forward:
                frameIndex = MathUtils.minInt(regions.length - 1, frameIndex);
            case forwardLoop:
                frameIndex = frameIndex % regions.length;
            case pingPong:
                frameIndex = frameIndex % (regions.length * 2);
            if (frameIndex >= regions.length) frameIndex = regions.length - 1 - (frameIndex - regions.length);
            case random:
                frameIndex = MathUtils.random(regions.length - 1);
            case backward:
                frameIndex = MathUtils.maxInt(regions.length - frameIndex - 1, 0);
            case backwardLoop:
                frameIndex = frameIndex % regions.length;
                frameIndex = regions.length - frameIndex - 1;
        }
        setRegion(regions[frameIndex]);

        super.updateVertices(slot);
    }

    public function getRegions ():Array<TextureRegion> {
        if (regions == null) throw new IllegalStateException("Regions have not been set: " + this);
        return regions;
    }

    public function setRegions (regions:Array<TextureRegion>) {
        this.regions = regions;
    }

    /** Sets the time in seconds each frame is shown. */
    public function setFrameTime (frameTime:Float) {
        this.frameTime = frameTime;
    }

    public function setMode (mode:Mode) {
        this.mode = mode;
    }
}
