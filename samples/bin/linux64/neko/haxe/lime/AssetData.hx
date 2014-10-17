package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/spineboy.atlas", "assets/spineboy.atlas");
			type.set ("assets/spineboy.atlas", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/spineboy.json", "assets/spineboy.json");
			type.set ("assets/spineboy.json", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/spineboy.png", "assets/spineboy.png");
			type.set ("assets/spineboy.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/spineboy.skel", "assets/spineboy.skel");
			type.set ("assets/spineboy.skel", Reflect.field (AssetType, "binary".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
