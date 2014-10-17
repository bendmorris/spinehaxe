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

import spinehaxe.Exception;
import spinehaxe.Color;

class BoneData {
	public var parent:BoneData;
	public var name:String;

	public var length:Float;
	public var x:Float;
	public var y:Float;
	public var rotation:Float;
	public var scaleX:Float;
	public var scaleY:Float;
	public var inheritScale:Bool;
	public var inheritRotation:Bool;
    public var flipX:Bool;
    public var flipY:Bool;

    // Nonessential.
    public var color:Color = new Color(0.61, 0.61, 0.61, 1);

	/** @param parent May be null. */
	public function new(name:String, parent:BoneData) {
		if (name == null)
			throw new IllegalArgumentException("name cannot be null.");
		scaleX = 1;
		scaleY = 1;
		inheritScale = true;
		inheritRotation = true;
		this.name = name;
		this.parent = parent;
	}

    //TODO:[Yura] в haxe нету перегруженных конструкторов, а значит надо сделать иной подход к реализации
    //public function new(bone:BoneData, parent:BoneData) {
		//if (bone == null)
			//throw new IllegalArgumentException("bone cannot be null.");
		//this.parent = parent;
        //name = bone.name;
        //length = bone.length;
        //x = bone.x;
        //y = bone.y;
        //rotation = bone.rotation;
		//scaleX = bone.scaleX;
		//scaleY = bone.scaleY;
        //flipX = bone.flipX;
        //flipY = bone.flipY;
	//}

	public function toString():String {
		return name;
	}

    public function getColor():Color {
        return this.color;
    }

}
