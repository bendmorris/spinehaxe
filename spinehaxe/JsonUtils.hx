package spinehaxe;

import haxe.Json;
import Reflect;
import haxe.ds.Vector;

typedef JsonNode = Dynamic;


class JsonUtils {
	public static function parse(data:String):JsonNode {
		return cast Json.parse(data);
	}

	public static function fields(node:JsonNode):Array<String> {
		return Reflect.fields(node);
	}

	public static function getNode(node:JsonNode, field:String):JsonNode {
		return getDynamic(node, field);
	}

	public static inline function getDynamic(node:JsonNode, field:String):Dynamic {
		return Reflect.getProperty(node, field);
	}

	public static function getNodesArray(node:JsonNode, field:String):Array<JsonNode> {
		return cast(getDynamic(node, field), Array<JsonNode>);
	}

	public static function getInt(node:JsonNode, field:String, defaultValue:Int=0):Int {
		var value:Dynamic = getDynamic(node, field);
		if (value == null) return defaultValue;
		return cast(value, Int);
	}

	public static function getFloat(node:JsonNode, field:String, defaultValue:Float=0):Float {
		var value:Dynamic = getDynamic(node, field);
		if (value == null) return defaultValue;
		if (Std.is(value, Int)) return cast(value, Int);
		return cast(value, Float);
	}

	public static function getStr(node:JsonNode, field:String, defaultValue:String=null):String {
		var value:Dynamic = getDynamic(node, field);
		if (value == null) return defaultValue;
		return cast(value, String);
	}

	public static function getBool(node:JsonNode, field:String, defaultValue:Bool = false):Bool {
		var value = getDynamic(node, field);
		if (value == null) {
		   return defaultValue;
		}
		return cast value;
	}

	static private function getFloatArray (map:JsonNode, name:String, scale:Float) : Array<Float> {
		var values:Array<Float> = getDynamic(map, name);
		if (scale != 1) {
			for (i in 0 ... values.length)
				values[i] *= scale;
		}
		return values;
	}

	static private function getIntArray (map:JsonNode, name:String) : Array<Int> {
		return cast getDynamic(map, name);
	}

	static private function getUintArray (map:JsonNode, name:String) : Array<UInt> {
		return cast getDynamic(map, name);
	}

	public static function hasOwnProperty(node:JsonNode, field:String) {
		return Reflect.hasField(node, field);
	}
}
