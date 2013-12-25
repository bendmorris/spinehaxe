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

package spinehaxe.platform.nme.renderers;

import spinehaxe.attachments.RegionAttachment;
import spinehaxe.attachments.Attachment;
import flash.display.Sprite;

class SkeletonRendererDebug extends Sprite {
    var skeleton:Skeleton;

    public function new(skeleton:Skeleton) {
        super();
        this.skeleton = skeleton;
    }

    public function draw() {
        graphics.clear();
        graphics.lineStyle(1, 0xff0000);
        inline function line(x1, y1, x2, y2) {
            graphics.moveTo(x1, y1);
            graphics.lineTo(x2, y2);
        }
        var skeletonX:Float = skeleton.getX();
        var skeletonY:Float = skeleton.getY();

        for (bone in skeleton.getBones()) {
            if (bone.parent == null) continue;
            var x:Float = skeletonX + bone.data.length * bone.m00 + bone.worldX;
            var y:Float = skeletonY + bone.data.length * bone.m10 + bone.worldY;
            line(skeletonX + bone.worldX, skeletonY + bone.worldY, x, y);
        }

        graphics.lineStyle(1, 0x0000ff);
        for (slot in skeleton.getSlots()) {
            var attachment:Attachment = slot.attachment;
            if (Std.is(attachment, RegionAttachment)) {
                var regionAttachment:RegionAttachment = cast(attachment, RegionAttachment);
                regionAttachment.updateVertices(slot);
                var vertices = regionAttachment.getVertices();
                graphics.moveTo(vertices[RegionAttachment.X1], vertices[RegionAttachment.Y1]);
                graphics.lineTo(vertices[RegionAttachment.X2], vertices[RegionAttachment.Y2]);
                graphics.lineTo(vertices[RegionAttachment.X3], vertices[RegionAttachment.Y3]);
                graphics.lineTo(vertices[RegionAttachment.X4], vertices[RegionAttachment.Y4]);
                graphics.lineTo(vertices[RegionAttachment.X1], vertices[RegionAttachment.Y1]);
            }
        }

        graphics.lineStyle(1, 0x00ff00);
//        graphics.beginFill(0x00ff00);
        for (bone in skeleton.getBones()) {
            graphics.drawCircle(skeletonX + bone.worldX, skeletonY + bone.worldY, 3);
        }
        graphics.endFill();
    }
}
