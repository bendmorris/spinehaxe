import openfl.Assets;


#if (!macro && !display && !waxe)


class ApplicationMain {
	
	
	private static var barA:flash.display.Sprite;
	private static var barB:flash.display.Sprite;
	private static var container:flash.display.Sprite;
	private static var forceHeight:Int;
	private static var forceWidth:Int;
	
	
	public static function main () {
		
		flash.Lib.setPackage ("spinehx", "spinehx-AnimationStateTest", "org.bitbucket.nitrobin.spinehx.AnimationStateTest", "1.0.0");
		
		
		#if ios
		flash.display.Stage.shouldRotateInterface = function (orientation:Int):Bool {
			return true;
		}
		#end
		
		
		
		
		
		flash.Lib.create (function () {
				
				flash.Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
				flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
				flash.Lib.current.loaderInfo = flash.display.LoaderInfo.create (null);
				
				
				
				#if windows
				try {
					
					var currentPath = haxe.io.Path.directory (Sys.executablePath ());
					Sys.setCwd (currentPath);
					
				} catch (e:Dynamic) {}
				#elseif linux
				try {
					
					if (!sys.FileSystem.exists (Sys.getCwd () + "/lime.ndll")) {
						
						Sys.setCwd (haxe.io.Path.directory (Sys.executablePath ()));
						
					}
					
				} catch (e:Dynamic) {}
				#end
				
				var hasMain = false;
				
				for (methodName in Type.getClassFields (AnimationStateTest)) {
					
					if (methodName == "main") {
						
						hasMain = true;
						break;
						
					}
					
				}
					
				if (hasMain) {
					
					Reflect.callMethod (AnimationStateTest, Reflect.field (AnimationStateTest, "main"), []);
					
				} else {
					
					var instance:DocumentClass = Type.createInstance(DocumentClass, []);
					
					if (Std.is (instance, flash.display.DisplayObject)) {
						
						flash.Lib.current.addChild (cast instance);
						
					}
					
				}
				
			},
			0, 0, 
			60, 
			16777215,
			(true ? flash.Lib.HARDWARE : 0) |
			(true ? flash.Lib.ALLOW_SHADERS : 0) |
			(true ? flash.Lib.REQUIRE_SHADERS : 0) |
			(false ? flash.Lib.DEPTH_BUFFER : 0) |
			(false ? flash.Lib.STENCIL_BUFFER : 0) |
			(true ? flash.Lib.RESIZABLE : 0) |
			(false ? flash.Lib.BORDERLESS : 0) |
			(false ? flash.Lib.VSYNC : 0) |
			(true ? flash.Lib.FULLSCREEN : 0) |
			(0 == 4 ? flash.Lib.HW_AA_HIRES : 0) |
			(0 == 2 ? flash.Lib.HW_AA : 0),
			"spinehx - AnimationStateTest",
			null
			
		);
		
	}
	
	
	
	
	#if neko
	@:noCompletion public static function __init__ () {
		
		untyped $loader.path = $array (haxe.io.Path.directory (Sys.executablePath ()), $loader.path);
		untyped $loader.path = $array ("./", $loader.path);
		untyped $loader.path = $array ("@executable_path/", $loader.path);
		
	}
	#end
	
	
}


@:build(DocumentClass.build())
@:keep class DocumentClass extends AnimationStateTest {}





#elseif macro


import haxe.macro.Context;
import haxe.macro.Expr;


class DocumentClass {
	
	
	macro public static function build ():Array<Field> {
		
		var classType = Context.getLocalClass ().get ();
		var searchTypes = classType;
		
		while (searchTypes.superClass != null) {
			
			if (searchTypes.pack.length == 2 && searchTypes.pack[1] == "display" && searchTypes.name == "DisplayObject") {
				
				var fields = Context.getBuildFields ();
				var method = macro { return flash.Lib.current.stage; }
				
				fields.push ({ name: "get_stage", access: [ APrivate, AOverride ], kind: FFun({ args: [], expr: method, params: [], ret: macro :flash.display.Stage }), pos: Context.currentPos () });
				return fields;
				
			}
			
			searchTypes = searchTypes.superClass.t.get ();
			
		}
		
		return null;
		
	}
	
	
}


#elseif waxe


class ApplicationMain {
	
	
	public static var autoShowFrame:Bool = true;
	public static var frame:wx.Frame;
	#if openfl
	static public var nmeStage:wx.NMEStage;
	#end
	
	
	public static function main () {
		
		#if openfl
		flash.Lib.setPackage ("spinehx", "spinehx-AnimationStateTest", "org.bitbucket.nitrobin.spinehx.AnimationStateTest", "1.0.0");
		
		#end
		
		wx.App.boot (function () {
			
			
			frame = wx.Frame.create (null, null, "spinehx - AnimationStateTest", null, { width: 0, height: 0 });
			
			
			#if openfl
			var stage = wx.NMEStage.create (frame, null, null, { width: 0, height: 0 });
			#end
			
			var hasMain = false;
			for (methodName in Type.getClassFields (AnimationStateTest)) {
				if (methodName == "main") {
					hasMain = true;
					break;
				}
			}
			
			if (hasMain) {
				Reflect.callMethod (AnimationStateTest, Reflect.field (AnimationStateTest, "main"), []);
			}else {
				var instance = Type.createInstance (AnimationStateTest, []);
			}
			
			if (autoShowFrame) {
				wx.App.setTopWindow (frame);
				frame.shown = true;
			}
			
		});
		
	}
	
	#if neko
	@:noCompletion public static function __init__ () {
		
		untyped $loader.path = $array (haxe.io.Path.directory (Sys.executablePath ()), $loader.path);
		untyped $loader.path = $array ("./", $loader.path);
		untyped $loader.path = $array ("@executable_path/", $loader.path);
		
	}
	#end
	
	
}


#else


import AnimationStateTest;

class ApplicationMain {
	
	
	public static function main () {
		
		
		
	}
	
	
}


#end
