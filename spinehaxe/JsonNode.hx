package spinehaxe;

import haxe.Json;
import Reflect;
import haxe.ds.Vector;


abstract JsonNode(Dynamic) from Dynamic to Dynamic {
	@:from public static inline function parse(data:String):JsonNode {
		return new JsonNode(Json.parse(data));
	}

	public inline function new(data:Dynamic) {
		this = data;
	}

	public inline function fields():Array<String> {
		return Reflect.fields(this);
	}

	public inline function getDynamic(field:String):Dynamic {
		return Reflect.field(this, field);
	}

	public inline function getNode(field:String):JsonNode {
		return new JsonNode(getDynamic(field));
	}

	public inline function getInt(field:String, defaultValue:Int=0):Int {
		var value:Dynamic = getDynamic(field);
		return (value == null) ? defaultValue : cast(value, Int);
	}

	public inline function getFloat(field:String, defaultValue:Float=0):Float {
		var value:Dynamic = getDynamic(field);
		return (value == null) ? defaultValue : cast(value, Float);
	}

	public inline function getStr(field:String, defaultValue:String=null):String {
		var value:Dynamic = getDynamic(field);
		return (value == null) ? defaultValue : Std.string(value);
	}

	public inline function getBool(field:String, defaultValue:Bool = false):Bool {
		var value = getDynamic(field);
		return (value == null) ? defaultValue : cast(value, Bool);
	}

	public inline function getDynamicArray(field:String):Array<Dynamic> {
		return cast getDynamic(field);
	}

	public inline function getNodesArray(field:String):Array<JsonNode> {
		return cast getDynamic(field);
	}

	public inline function getFloatArray(field:String, scale:Float = 1):Array<Float> {
		var values:Array<Float> = cast getDynamic(field);
		if (scale != 1) {
			for (i in 0 ... values.length)
				values[i] *= scale;
		}
		return values;
	}

	public inline function getIntArray (field:String):Array<Int> {
		return cast getDynamic(field);
	}

	public inline function getUintArray (field:String):Array<UInt> {
		return cast getDynamic(field);
	}

	public inline function getStrArray (field:String):Array<String> {
		return cast getDynamic(field);
	}

	public inline function hasOwnProperty(field:String) {
		return Reflect.hasField(this, field);
	}
}
