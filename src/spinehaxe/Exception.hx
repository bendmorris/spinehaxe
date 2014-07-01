package spinehaxe;
class Exception {
	public var msg:String;
	public function new(msg:String) {
		this.msg = msg;
	}
}

typedef RuntimeException = Exception;
typedef IllegalArgumentException = Exception;
typedef IllegalStateException = Exception;
typedef SerializationException = Exception;
