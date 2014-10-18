#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_text_AntiAliasType
#include <openfl/text/AntiAliasType.h>
#endif
#ifndef INCLUDED_openfl_text_GridFitType
#include <openfl/text/GridFitType.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_text_TextFieldAutoSize
#include <openfl/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_openfl_text_TextFieldType
#include <openfl/text/TextFieldType.h>
#endif
#ifndef INCLUDED_openfl_text_TextFormat
#include <openfl/text/TextFormat.h>
#endif
#ifndef INCLUDED_openfl_text_TextLineMetrics
#include <openfl/text/TextLineMetrics.h>
#endif
namespace openfl{
namespace text{

Void TextField_obj::__construct()
{
HX_STACK_FRAME("openfl.text.TextField","new",0xbd7676bc,"openfl.text.TextField.new","openfl/text/TextField.hx",42,0xccf02094)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(44)
	Dynamic _g = ::openfl::text::TextField_obj::lime_text_field_create();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	super::__construct(_g,HX_CSTRING("TextField"));
	HX_STACK_LINE(46)
	this->gridFitType = ::openfl::text::GridFitType_obj::PIXEL;
	HX_STACK_LINE(47)
	this->sharpness = (int)0;
}
;
	return null();
}

//TextField_obj::~TextField_obj() { }

Dynamic TextField_obj::__CreateEmpty() { return  new TextField_obj; }
hx::ObjectPtr< TextField_obj > TextField_obj::__new()
{  hx::ObjectPtr< TextField_obj > result = new TextField_obj();
	result->__construct();
	return result;}

Dynamic TextField_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextField_obj > result = new TextField_obj();
	result->__construct();
	return result;}

Void TextField_obj::appendText( ::String text){
{
		HX_STACK_FRAME("openfl.text.TextField","appendText",0xaa44eccb,"openfl.text.TextField.appendText","openfl/text/TextField.hx",52,0xccf02094)
		HX_STACK_THIS(this)
		HX_STACK_ARG(text,"text")
		HX_STACK_LINE(54)
		::String _g = ::openfl::text::TextField_obj::lime_text_field_get_text(this->__handle);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		::String _g1 = (_g + text);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		::openfl::text::TextField_obj::lime_text_field_set_text(this->__handle,_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,appendText,(void))

int TextField_obj::getLineOffset( int lineIndex){
	HX_STACK_FRAME("openfl.text.TextField","getLineOffset",0x5676a039,"openfl.text.TextField.getLineOffset","openfl/text/TextField.hx",61,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(lineIndex,"lineIndex")
	HX_STACK_LINE(61)
	return ::openfl::text::TextField_obj::lime_text_field_get_line_offset(this->__handle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineOffset,return )

::String TextField_obj::getLineText( int lineIndex){
	HX_STACK_FRAME("openfl.text.TextField","getLineText",0xb8113fd3,"openfl.text.TextField.getLineText","openfl/text/TextField.hx",68,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(lineIndex,"lineIndex")
	HX_STACK_LINE(68)
	return ::openfl::text::TextField_obj::lime_text_field_get_line_text(this->__handle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineText,return )

::openfl::text::TextLineMetrics TextField_obj::getLineMetrics( int lineIndex){
	HX_STACK_FRAME("openfl.text.TextField","getLineMetrics",0xa6c52add,"openfl.text.TextField.getLineMetrics","openfl/text/TextField.hx",73,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(lineIndex,"lineIndex")
	HX_STACK_LINE(75)
	::openfl::text::TextLineMetrics result = ::openfl::text::TextLineMetrics_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(76)
	::openfl::text::TextField_obj::lime_text_field_get_line_metrics(this->__handle,lineIndex,result);
	HX_STACK_LINE(77)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineMetrics,return )

::openfl::text::TextFormat TextField_obj::getTextFormat( hx::Null< int >  __o_beginIndex,hx::Null< int >  __o_endIndex){
int beginIndex = __o_beginIndex.Default(-1);
int endIndex = __o_endIndex.Default(-1);
	HX_STACK_FRAME("openfl.text.TextField","getTextFormat",0x560e1d56,"openfl.text.TextField.getTextFormat","openfl/text/TextField.hx",82,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(beginIndex,"beginIndex")
	HX_STACK_ARG(endIndex,"endIndex")
{
		HX_STACK_LINE(84)
		::openfl::text::TextFormat result = ::openfl::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(85)
		::openfl::text::TextField_obj::lime_text_field_get_text_format(this->__handle,result,beginIndex,endIndex);
		HX_STACK_LINE(86)
		return result;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(TextField_obj,getTextFormat,return )

Void TextField_obj::replaceText( int beginIndex,int endIndex,::String newText){
{
		HX_STACK_FRAME("openfl.text.TextField","replaceText",0x698fcd5d,"openfl.text.TextField.replaceText","openfl/text/TextField.hx",93,0xccf02094)
		HX_STACK_THIS(this)
		HX_STACK_ARG(beginIndex,"beginIndex")
		HX_STACK_ARG(endIndex,"endIndex")
		HX_STACK_ARG(newText,"newText")
		HX_STACK_LINE(93)
		::openfl::Lib_obj::notImplemented(HX_CSTRING("TextField.replaceText"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TextField_obj,replaceText,(void))

Void TextField_obj::setSelection( int beginIndex,int endIndex){
{
		HX_STACK_FRAME("openfl.text.TextField","setSelection",0xa586666e,"openfl.text.TextField.setSelection","openfl/text/TextField.hx",100,0xccf02094)
		HX_STACK_THIS(this)
		HX_STACK_ARG(beginIndex,"beginIndex")
		HX_STACK_ARG(endIndex,"endIndex")
		HX_STACK_LINE(100)
		::openfl::Lib_obj::notImplemented(HX_CSTRING("TextField.setSelection"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextField_obj,setSelection,(void))

Void TextField_obj::setTextFormat( ::openfl::text::TextFormat format,hx::Null< int >  __o_beginIndex,hx::Null< int >  __o_endIndex){
int beginIndex = __o_beginIndex.Default(-1);
int endIndex = __o_endIndex.Default(-1);
	HX_STACK_FRAME("openfl.text.TextField","setTextFormat",0x9b13ff62,"openfl.text.TextField.setTextFormat","openfl/text/TextField.hx",107,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(format,"format")
	HX_STACK_ARG(beginIndex,"beginIndex")
	HX_STACK_ARG(endIndex,"endIndex")
{
		HX_STACK_LINE(107)
		::openfl::text::TextField_obj::lime_text_field_set_text_format(this->__handle,format,beginIndex,endIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TextField_obj,setTextFormat,(void))

::openfl::text::TextFieldAutoSize TextField_obj::get_autoSize( ){
	HX_STACK_FRAME("openfl.text.TextField","get_autoSize",0xd7aef1fd,"openfl.text.TextField.get_autoSize","openfl/text/TextField.hx",119,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(119)
	int _g = ::openfl::text::TextField_obj::lime_text_field_get_auto_size(this->__handle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(119)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::openfl::text::TextFieldAutoSize >(),_g,null());
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_autoSize,return )

::openfl::text::TextFieldAutoSize TextField_obj::set_autoSize( ::openfl::text::TextFieldAutoSize value){
	HX_STACK_FRAME("openfl.text.TextField","set_autoSize",0xeca81571,"openfl.text.TextField.set_autoSize","openfl/text/TextField.hx",120,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(120)
	int _g = value->__Index();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(120)
	::openfl::text::TextField_obj::lime_text_field_set_auto_size(this->__handle,_g);
	HX_STACK_LINE(120)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_autoSize,return )

bool TextField_obj::get_background( ){
	HX_STACK_FRAME("openfl.text.TextField","get_background",0x50119b5b,"openfl.text.TextField.get_background","openfl/text/TextField.hx",121,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(121)
	return ::openfl::text::TextField_obj::lime_text_field_get_background(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_background,return )

bool TextField_obj::set_background( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_background",0x703183cf,"openfl.text.TextField.set_background","openfl/text/TextField.hx",122,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(122)
	::openfl::text::TextField_obj::lime_text_field_set_background(this->__handle,value);
	HX_STACK_LINE(122)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_background,return )

int TextField_obj::get_backgroundColor( ){
	HX_STACK_FRAME("openfl.text.TextField","get_backgroundColor",0x63403c08,"openfl.text.TextField.get_backgroundColor","openfl/text/TextField.hx",123,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	return ::openfl::text::TextField_obj::lime_text_field_get_background_color(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_backgroundColor,return )

int TextField_obj::set_backgroundColor( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_backgroundColor",0x9fdd2f14,"openfl.text.TextField.set_backgroundColor","openfl/text/TextField.hx",124,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(124)
	::openfl::text::TextField_obj::lime_text_field_set_background_color(this->__handle,value);
	HX_STACK_LINE(124)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_backgroundColor,return )

bool TextField_obj::get_border( ){
	HX_STACK_FRAME("openfl.text.TextField","get_border",0xa3e0d9d9,"openfl.text.TextField.get_border","openfl/text/TextField.hx",125,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(125)
	return ::openfl::text::TextField_obj::lime_text_field_get_border(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_border,return )

bool TextField_obj::set_border( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_border",0xa75e784d,"openfl.text.TextField.set_border","openfl/text/TextField.hx",126,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(126)
	::openfl::text::TextField_obj::lime_text_field_set_border(this->__handle,value);
	HX_STACK_LINE(126)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_border,return )

int TextField_obj::get_borderColor( ){
	HX_STACK_FRAME("openfl.text.TextField","get_borderColor",0x6267b4ca,"openfl.text.TextField.get_borderColor","openfl/text/TextField.hx",127,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	return ::openfl::text::TextField_obj::lime_text_field_get_border_color(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_borderColor,return )

int TextField_obj::set_borderColor( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_borderColor",0x5e3331d6,"openfl.text.TextField.set_borderColor","openfl/text/TextField.hx",128,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(128)
	::openfl::text::TextField_obj::lime_text_field_set_border_color(this->__handle,value);
	HX_STACK_LINE(128)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_borderColor,return )

int TextField_obj::get_bottomScrollV( ){
	HX_STACK_FRAME("openfl.text.TextField","get_bottomScrollV",0xfa9e92b1,"openfl.text.TextField.get_bottomScrollV","openfl/text/TextField.hx",129,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(129)
	return ::openfl::text::TextField_obj::lime_text_field_get_bottom_scroll_v(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_bottomScrollV,return )

::openfl::text::TextFormat TextField_obj::get_defaultTextFormat( ){
	HX_STACK_FRAME("openfl.text.TextField","get_defaultTextFormat",0x83063818,"openfl.text.TextField.get_defaultTextFormat","openfl/text/TextField.hx",130,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(130)
	::openfl::text::TextFormat result = ::openfl::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(130)
	::openfl::text::TextField_obj::lime_text_field_get_def_text_format(this->__handle,result);
	HX_STACK_LINE(130)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_defaultTextFormat,return )

::openfl::text::TextFormat TextField_obj::set_defaultTextFormat( ::openfl::text::TextFormat value){
	HX_STACK_FRAME("openfl.text.TextField","set_defaultTextFormat",0xd70f0624,"openfl.text.TextField.set_defaultTextFormat","openfl/text/TextField.hx",131,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(131)
	::openfl::text::TextField_obj::lime_text_field_set_def_text_format(this->__handle,value);
	HX_STACK_LINE(131)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_defaultTextFormat,return )

bool TextField_obj::get_displayAsPassword( ){
	HX_STACK_FRAME("openfl.text.TextField","get_displayAsPassword",0x62bc3b42,"openfl.text.TextField.get_displayAsPassword","openfl/text/TextField.hx",132,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(132)
	return ::openfl::text::TextField_obj::lime_text_field_get_display_as_password(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_displayAsPassword,return )

bool TextField_obj::set_displayAsPassword( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_displayAsPassword",0xb6c5094e,"openfl.text.TextField.set_displayAsPassword","openfl/text/TextField.hx",133,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(133)
	::openfl::text::TextField_obj::lime_text_field_set_display_as_password(this->__handle,value);
	HX_STACK_LINE(133)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_displayAsPassword,return )

bool TextField_obj::get_embedFonts( ){
	HX_STACK_FRAME("openfl.text.TextField","get_embedFonts",0xb8d5ce98,"openfl.text.TextField.get_embedFonts","openfl/text/TextField.hx",134,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(134)
	return this->__embedFonts;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_embedFonts,return )

bool TextField_obj::set_embedFonts( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_embedFonts",0xd8f5b70c,"openfl.text.TextField.set_embedFonts","openfl/text/TextField.hx",135,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(135)
	return this->__embedFonts = value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_embedFonts,return )

::String TextField_obj::get_htmlText( ){
	HX_STACK_FRAME("openfl.text.TextField","get_htmlText",0xb86d81e5,"openfl.text.TextField.get_htmlText","openfl/text/TextField.hx",136,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(136)
	::String _g = ::openfl::text::TextField_obj::lime_text_field_get_html_text(this->__handle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(136)
	return ::StringTools_obj::replace(_g,HX_CSTRING("\n"),HX_CSTRING("<br/>"));
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_htmlText,return )

::String TextField_obj::set_htmlText( ::String value){
	HX_STACK_FRAME("openfl.text.TextField","set_htmlText",0xcd66a559,"openfl.text.TextField.set_htmlText","openfl/text/TextField.hx",137,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(137)
	::openfl::text::TextField_obj::lime_text_field_set_html_text(this->__handle,value);
	HX_STACK_LINE(137)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_htmlText,return )

int TextField_obj::get_maxChars( ){
	HX_STACK_FRAME("openfl.text.TextField","get_maxChars",0x980651c6,"openfl.text.TextField.get_maxChars","openfl/text/TextField.hx",138,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	return ::openfl::text::TextField_obj::lime_text_field_get_max_chars(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxChars,return )

int TextField_obj::set_maxChars( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_maxChars",0xacff753a,"openfl.text.TextField.set_maxChars","openfl/text/TextField.hx",139,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(139)
	::openfl::text::TextField_obj::lime_text_field_set_max_chars(this->__handle,value);
	HX_STACK_LINE(139)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_maxChars,return )

int TextField_obj::get_maxScrollH( ){
	HX_STACK_FRAME("openfl.text.TextField","get_maxScrollH",0xc4f0b4c4,"openfl.text.TextField.get_maxScrollH","openfl/text/TextField.hx",140,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(140)
	return ::openfl::text::TextField_obj::lime_text_field_get_max_scroll_h(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxScrollH,return )

int TextField_obj::get_maxScrollV( ){
	HX_STACK_FRAME("openfl.text.TextField","get_maxScrollV",0xc4f0b4d2,"openfl.text.TextField.get_maxScrollV","openfl/text/TextField.hx",141,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(141)
	return ::openfl::text::TextField_obj::lime_text_field_get_max_scroll_v(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxScrollV,return )

bool TextField_obj::get_multiline( ){
	HX_STACK_FRAME("openfl.text.TextField","get_multiline",0x24925820,"openfl.text.TextField.get_multiline","openfl/text/TextField.hx",142,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(142)
	return ::openfl::text::TextField_obj::lime_text_field_get_multiline(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_multiline,return )

bool TextField_obj::set_multiline( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_multiline",0x69983a2c,"openfl.text.TextField.set_multiline","openfl/text/TextField.hx",143,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(143)
	::openfl::text::TextField_obj::lime_text_field_set_multiline(this->__handle,value);
	HX_STACK_LINE(143)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_multiline,return )

int TextField_obj::get_numLines( ){
	HX_STACK_FRAME("openfl.text.TextField","get_numLines",0xda475406,"openfl.text.TextField.get_numLines","openfl/text/TextField.hx",144,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return ::openfl::text::TextField_obj::lime_text_field_get_num_lines(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_numLines,return )

int TextField_obj::get_scrollH( ){
	HX_STACK_FRAME("openfl.text.TextField","get_scrollH",0xbeccf60e,"openfl.text.TextField.get_scrollH","openfl/text/TextField.hx",145,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(145)
	return ::openfl::text::TextField_obj::lime_text_field_get_scroll_h(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_scrollH,return )

int TextField_obj::set_scrollH( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_scrollH",0xc939fd1a,"openfl.text.TextField.set_scrollH","openfl/text/TextField.hx",146,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(146)
	::openfl::text::TextField_obj::lime_text_field_set_scroll_h(this->__handle,value);
	HX_STACK_LINE(146)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_scrollH,return )

int TextField_obj::get_scrollV( ){
	HX_STACK_FRAME("openfl.text.TextField","get_scrollV",0xbeccf61c,"openfl.text.TextField.get_scrollV","openfl/text/TextField.hx",147,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(147)
	return ::openfl::text::TextField_obj::lime_text_field_get_scroll_v(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_scrollV,return )

int TextField_obj::set_scrollV( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_scrollV",0xc939fd28,"openfl.text.TextField.set_scrollV","openfl/text/TextField.hx",148,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(148)
	::openfl::text::TextField_obj::lime_text_field_set_scroll_v(this->__handle,value);
	HX_STACK_LINE(148)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_scrollV,return )

bool TextField_obj::get_selectable( ){
	HX_STACK_FRAME("openfl.text.TextField","get_selectable",0xee1ebe03,"openfl.text.TextField.get_selectable","openfl/text/TextField.hx",149,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(149)
	return ::openfl::text::TextField_obj::lime_text_field_get_selectable(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_selectable,return )

bool TextField_obj::set_selectable( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_selectable",0x0e3ea677,"openfl.text.TextField.set_selectable","openfl/text/TextField.hx",150,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(150)
	::openfl::text::TextField_obj::lime_text_field_set_selectable(this->__handle,value);
	HX_STACK_LINE(150)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_selectable,return )

::String TextField_obj::get_text( ){
	HX_STACK_FRAME("openfl.text.TextField","get_text",0x3b0d545a,"openfl.text.TextField.get_text","openfl/text/TextField.hx",151,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(151)
	return ::openfl::text::TextField_obj::lime_text_field_get_text(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_text,return )

::String TextField_obj::set_text( ::String value){
	HX_STACK_FRAME("openfl.text.TextField","set_text",0xe96aadce,"openfl.text.TextField.set_text","openfl/text/TextField.hx",152,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(152)
	::openfl::text::TextField_obj::lime_text_field_set_text(this->__handle,value);
	HX_STACK_LINE(152)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_text,return )

int TextField_obj::get_textColor( ){
	HX_STACK_FRAME("openfl.text.TextField","get_textColor",0x69ca86a9,"openfl.text.TextField.get_textColor","openfl/text/TextField.hx",153,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(153)
	return ::openfl::text::TextField_obj::lime_text_field_get_text_color(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textColor,return )

int TextField_obj::set_textColor( int value){
	HX_STACK_FRAME("openfl.text.TextField","set_textColor",0xaed068b5,"openfl.text.TextField.set_textColor","openfl/text/TextField.hx",154,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(154)
	::openfl::text::TextField_obj::lime_text_field_set_text_color(this->__handle,value);
	HX_STACK_LINE(154)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_textColor,return )

Float TextField_obj::get_textWidth( ){
	HX_STACK_FRAME("openfl.text.TextField","get_textWidth",0xe9d0cb4c,"openfl.text.TextField.get_textWidth","openfl/text/TextField.hx",155,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(155)
	return ::openfl::text::TextField_obj::lime_text_field_get_text_width(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textWidth,return )

Float TextField_obj::get_textHeight( ){
	HX_STACK_FRAME("openfl.text.TextField","get_textHeight",0x63308fe1,"openfl.text.TextField.get_textHeight","openfl/text/TextField.hx",156,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(156)
	return ::openfl::text::TextField_obj::lime_text_field_get_text_height(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textHeight,return )

::openfl::text::TextFieldType TextField_obj::get_type( ){
	HX_STACK_FRAME("openfl.text.TextField","get_type",0x3b1c7a67,"openfl.text.TextField.get_type","openfl/text/TextField.hx",157,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(157)
	if ((::openfl::text::TextField_obj::lime_text_field_get_type(this->__handle))){
		HX_STACK_LINE(157)
		return ::openfl::text::TextFieldType_obj::INPUT;
	}
	else{
		HX_STACK_LINE(157)
		return ::openfl::text::TextFieldType_obj::DYNAMIC;
	}
	HX_STACK_LINE(157)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_type,return )

::openfl::text::TextFieldType TextField_obj::set_type( ::openfl::text::TextFieldType value){
	HX_STACK_FRAME("openfl.text.TextField","set_type",0xe979d3db,"openfl.text.TextField.set_type","openfl/text/TextField.hx",158,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(158)
	::openfl::text::TextField_obj::lime_text_field_set_type(this->__handle,(value == ::openfl::text::TextFieldType_obj::INPUT));
	HX_STACK_LINE(158)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_type,return )

bool TextField_obj::get_wordWrap( ){
	HX_STACK_FRAME("openfl.text.TextField","get_wordWrap",0xa91076e1,"openfl.text.TextField.get_wordWrap","openfl/text/TextField.hx",159,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_LINE(159)
	return ::openfl::text::TextField_obj::lime_text_field_get_word_wrap(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_wordWrap,return )

bool TextField_obj::set_wordWrap( bool value){
	HX_STACK_FRAME("openfl.text.TextField","set_wordWrap",0xbe099a55,"openfl.text.TextField.set_wordWrap","openfl/text/TextField.hx",160,0xccf02094)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(160)
	::openfl::text::TextField_obj::lime_text_field_set_word_wrap(this->__handle,value);
	HX_STACK_LINE(160)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_wordWrap,return )

Dynamic TextField_obj::lime_text_field_create;

Dynamic TextField_obj::lime_text_field_get_text;

Dynamic TextField_obj::lime_text_field_set_text;

Dynamic TextField_obj::lime_text_field_get_html_text;

Dynamic TextField_obj::lime_text_field_set_html_text;

Dynamic TextField_obj::lime_text_field_get_text_color;

Dynamic TextField_obj::lime_text_field_set_text_color;

Dynamic TextField_obj::lime_text_field_get_selectable;

Dynamic TextField_obj::lime_text_field_set_selectable;

Dynamic TextField_obj::lime_text_field_get_display_as_password;

Dynamic TextField_obj::lime_text_field_set_display_as_password;

Dynamic TextField_obj::lime_text_field_get_def_text_format;

Dynamic TextField_obj::lime_text_field_set_def_text_format;

Dynamic TextField_obj::lime_text_field_get_auto_size;

Dynamic TextField_obj::lime_text_field_set_auto_size;

Dynamic TextField_obj::lime_text_field_get_type;

Dynamic TextField_obj::lime_text_field_set_type;

Dynamic TextField_obj::lime_text_field_get_multiline;

Dynamic TextField_obj::lime_text_field_set_multiline;

Dynamic TextField_obj::lime_text_field_get_word_wrap;

Dynamic TextField_obj::lime_text_field_set_word_wrap;

Dynamic TextField_obj::lime_text_field_get_border;

Dynamic TextField_obj::lime_text_field_set_border;

Dynamic TextField_obj::lime_text_field_get_border_color;

Dynamic TextField_obj::lime_text_field_set_border_color;

Dynamic TextField_obj::lime_text_field_get_background;

Dynamic TextField_obj::lime_text_field_set_background;

Dynamic TextField_obj::lime_text_field_get_background_color;

Dynamic TextField_obj::lime_text_field_set_background_color;

Dynamic TextField_obj::lime_text_field_get_text_width;

Dynamic TextField_obj::lime_text_field_get_text_height;

Dynamic TextField_obj::lime_text_field_get_text_format;

Dynamic TextField_obj::lime_text_field_set_text_format;

Dynamic TextField_obj::lime_text_field_get_max_scroll_v;

Dynamic TextField_obj::lime_text_field_get_max_scroll_h;

Dynamic TextField_obj::lime_text_field_get_bottom_scroll_v;

Dynamic TextField_obj::lime_text_field_get_scroll_h;

Dynamic TextField_obj::lime_text_field_set_scroll_h;

Dynamic TextField_obj::lime_text_field_get_scroll_v;

Dynamic TextField_obj::lime_text_field_set_scroll_v;

Dynamic TextField_obj::lime_text_field_get_num_lines;

Dynamic TextField_obj::lime_text_field_get_max_chars;

Dynamic TextField_obj::lime_text_field_set_max_chars;

Dynamic TextField_obj::lime_text_field_get_line_text;

Dynamic TextField_obj::lime_text_field_get_line_metrics;

Dynamic TextField_obj::lime_text_field_get_line_offset;


TextField_obj::TextField_obj()
{
}

void TextField_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextField);
	HX_MARK_MEMBER_NAME(antiAliasType,"antiAliasType");
	HX_MARK_MEMBER_NAME(bottomScrollV,"bottomScrollV");
	HX_MARK_MEMBER_NAME(gridFitType,"gridFitType");
	HX_MARK_MEMBER_NAME(maxScrollH,"maxScrollH");
	HX_MARK_MEMBER_NAME(maxScrollV,"maxScrollV");
	HX_MARK_MEMBER_NAME(numLines,"numLines");
	HX_MARK_MEMBER_NAME(sharpness,"sharpness");
	HX_MARK_MEMBER_NAME(textHeight,"textHeight");
	HX_MARK_MEMBER_NAME(textWidth,"textWidth");
	HX_MARK_MEMBER_NAME(__embedFonts,"__embedFonts");
	::openfl::display::DisplayObject_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextField_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(antiAliasType,"antiAliasType");
	HX_VISIT_MEMBER_NAME(bottomScrollV,"bottomScrollV");
	HX_VISIT_MEMBER_NAME(gridFitType,"gridFitType");
	HX_VISIT_MEMBER_NAME(maxScrollH,"maxScrollH");
	HX_VISIT_MEMBER_NAME(maxScrollV,"maxScrollV");
	HX_VISIT_MEMBER_NAME(numLines,"numLines");
	HX_VISIT_MEMBER_NAME(sharpness,"sharpness");
	HX_VISIT_MEMBER_NAME(textHeight,"textHeight");
	HX_VISIT_MEMBER_NAME(textWidth,"textWidth");
	HX_VISIT_MEMBER_NAME(__embedFonts,"__embedFonts");
	::openfl::display::DisplayObject_obj::__Visit(HX_VISIT_ARG);
}

Dynamic TextField_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return get_text(); }
		if (HX_FIELD_EQ(inName,"type") ) { return get_type(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return get_border(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollH") ) { return get_scrollH(); }
		if (HX_FIELD_EQ(inName,"scrollV") ) { return get_scrollV(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"autoSize") ) { return get_autoSize(); }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return get_htmlText(); }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return get_maxChars(); }
		if (HX_FIELD_EQ(inName,"numLines") ) { return inCallProp ? get_numLines() : numLines; }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return get_wordWrap(); }
		if (HX_FIELD_EQ(inName,"get_text") ) { return get_text_dyn(); }
		if (HX_FIELD_EQ(inName,"set_text") ) { return set_text_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"multiline") ) { return get_multiline(); }
		if (HX_FIELD_EQ(inName,"sharpness") ) { return sharpness; }
		if (HX_FIELD_EQ(inName,"textColor") ) { return get_textColor(); }
		if (HX_FIELD_EQ(inName,"textWidth") ) { return inCallProp ? get_textWidth() : textWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return get_background(); }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return get_embedFonts(); }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { return inCallProp ? get_maxScrollH() : maxScrollH; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { return inCallProp ? get_maxScrollV() : maxScrollV; }
		if (HX_FIELD_EQ(inName,"selectable") ) { return get_selectable(); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { return inCallProp ? get_textHeight() : textHeight; }
		if (HX_FIELD_EQ(inName,"appendText") ) { return appendText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_border") ) { return get_border_dyn(); }
		if (HX_FIELD_EQ(inName,"set_border") ) { return set_border_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { return get_borderColor(); }
		if (HX_FIELD_EQ(inName,"gridFitType") ) { return gridFitType; }
		if (HX_FIELD_EQ(inName,"getLineText") ) { return getLineText_dyn(); }
		if (HX_FIELD_EQ(inName,"replaceText") ) { return replaceText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollH") ) { return get_scrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollH") ) { return set_scrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollV") ) { return get_scrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollV") ) { return set_scrollV_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__embedFonts") ) { return __embedFonts; }
		if (HX_FIELD_EQ(inName,"setSelection") ) { return setSelection_dyn(); }
		if (HX_FIELD_EQ(inName,"get_autoSize") ) { return get_autoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_autoSize") ) { return set_autoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_htmlText") ) { return get_htmlText_dyn(); }
		if (HX_FIELD_EQ(inName,"set_htmlText") ) { return set_htmlText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxChars") ) { return get_maxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxChars") ) { return set_maxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"get_numLines") ) { return get_numLines_dyn(); }
		if (HX_FIELD_EQ(inName,"get_wordWrap") ) { return get_wordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"set_wordWrap") ) { return set_wordWrap_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { return antiAliasType; }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { return inCallProp ? get_bottomScrollV() : bottomScrollV; }
		if (HX_FIELD_EQ(inName,"getLineOffset") ) { return getLineOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextFormat") ) { return getTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextFormat") ) { return setTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_multiline") ) { return get_multiline_dyn(); }
		if (HX_FIELD_EQ(inName,"set_multiline") ) { return set_multiline_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textColor") ) { return get_textColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textColor") ) { return set_textColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textWidth") ) { return get_textWidth_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getLineMetrics") ) { return getLineMetrics_dyn(); }
		if (HX_FIELD_EQ(inName,"get_background") ) { return get_background_dyn(); }
		if (HX_FIELD_EQ(inName,"set_background") ) { return set_background_dyn(); }
		if (HX_FIELD_EQ(inName,"get_embedFonts") ) { return get_embedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"set_embedFonts") ) { return set_embedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxScrollH") ) { return get_maxScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxScrollV") ) { return get_maxScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"get_selectable") ) { return get_selectable_dyn(); }
		if (HX_FIELD_EQ(inName,"set_selectable") ) { return set_selectable_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textHeight") ) { return get_textHeight_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return get_backgroundColor(); }
		if (HX_FIELD_EQ(inName,"get_borderColor") ) { return get_borderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderColor") ) { return set_borderColor_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return get_defaultTextFormat(); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return get_displayAsPassword(); }
		if (HX_FIELD_EQ(inName,"get_bottomScrollV") ) { return get_bottomScrollV_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_backgroundColor") ) { return get_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundColor") ) { return set_backgroundColor_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_defaultTextFormat") ) { return get_defaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"set_defaultTextFormat") ) { return set_defaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_displayAsPassword") ) { return get_displayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"set_displayAsPassword") ) { return set_displayAsPassword_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"lime_text_field_create") ) { return lime_text_field_create; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text") ) { return lime_text_field_get_text; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text") ) { return lime_text_field_set_text; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_type") ) { return lime_text_field_get_type; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_type") ) { return lime_text_field_set_type; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_border") ) { return lime_text_field_get_border; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_border") ) { return lime_text_field_set_border; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_scroll_h") ) { return lime_text_field_get_scroll_h; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_scroll_h") ) { return lime_text_field_set_scroll_h; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_scroll_v") ) { return lime_text_field_get_scroll_v; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_scroll_v") ) { return lime_text_field_set_scroll_v; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_html_text") ) { return lime_text_field_get_html_text; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_html_text") ) { return lime_text_field_set_html_text; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_auto_size") ) { return lime_text_field_get_auto_size; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_auto_size") ) { return lime_text_field_set_auto_size; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_multiline") ) { return lime_text_field_get_multiline; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_multiline") ) { return lime_text_field_set_multiline; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_word_wrap") ) { return lime_text_field_get_word_wrap; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_word_wrap") ) { return lime_text_field_set_word_wrap; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_num_lines") ) { return lime_text_field_get_num_lines; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_chars") ) { return lime_text_field_get_max_chars; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_max_chars") ) { return lime_text_field_set_max_chars; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_text") ) { return lime_text_field_get_line_text; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_color") ) { return lime_text_field_get_text_color; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text_color") ) { return lime_text_field_set_text_color; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_selectable") ) { return lime_text_field_get_selectable; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_selectable") ) { return lime_text_field_set_selectable; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_background") ) { return lime_text_field_get_background; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_background") ) { return lime_text_field_set_background; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_width") ) { return lime_text_field_get_text_width; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_height") ) { return lime_text_field_get_text_height; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_format") ) { return lime_text_field_get_text_format; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text_format") ) { return lime_text_field_set_text_format; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_offset") ) { return lime_text_field_get_line_offset; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_border_color") ) { return lime_text_field_get_border_color; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_border_color") ) { return lime_text_field_set_border_color; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_scroll_v") ) { return lime_text_field_get_max_scroll_v; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_scroll_h") ) { return lime_text_field_get_max_scroll_h; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_metrics") ) { return lime_text_field_get_line_metrics; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_def_text_format") ) { return lime_text_field_get_def_text_format; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_def_text_format") ) { return lime_text_field_set_def_text_format; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_bottom_scroll_v") ) { return lime_text_field_get_bottom_scroll_v; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_background_color") ) { return lime_text_field_get_background_color; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_background_color") ) { return lime_text_field_set_background_color; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_display_as_password") ) { return lime_text_field_get_display_as_password; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_display_as_password") ) { return lime_text_field_set_display_as_password; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextField_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return set_text(inValue); }
		if (HX_FIELD_EQ(inName,"type") ) { return set_type(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return set_border(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollH") ) { return set_scrollH(inValue); }
		if (HX_FIELD_EQ(inName,"scrollV") ) { return set_scrollV(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"autoSize") ) { return set_autoSize(inValue); }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return set_htmlText(inValue); }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return set_maxChars(inValue); }
		if (HX_FIELD_EQ(inName,"numLines") ) { numLines=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return set_wordWrap(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"multiline") ) { return set_multiline(inValue); }
		if (HX_FIELD_EQ(inName,"sharpness") ) { sharpness=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textColor") ) { return set_textColor(inValue); }
		if (HX_FIELD_EQ(inName,"textWidth") ) { textWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return set_background(inValue); }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return set_embedFonts(inValue); }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { maxScrollH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { maxScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selectable") ) { return set_selectable(inValue); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { textHeight=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { return set_borderColor(inValue); }
		if (HX_FIELD_EQ(inName,"gridFitType") ) { gridFitType=inValue.Cast< ::openfl::text::GridFitType >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__embedFonts") ) { __embedFonts=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { antiAliasType=inValue.Cast< ::openfl::text::AntiAliasType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { bottomScrollV=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return set_backgroundColor(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return set_defaultTextFormat(inValue); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return set_displayAsPassword(inValue); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"lime_text_field_create") ) { lime_text_field_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text") ) { lime_text_field_get_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text") ) { lime_text_field_set_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_type") ) { lime_text_field_get_type=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_type") ) { lime_text_field_set_type=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_border") ) { lime_text_field_get_border=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_border") ) { lime_text_field_set_border=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_scroll_h") ) { lime_text_field_get_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_scroll_h") ) { lime_text_field_set_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_scroll_v") ) { lime_text_field_get_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_scroll_v") ) { lime_text_field_set_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_html_text") ) { lime_text_field_get_html_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_html_text") ) { lime_text_field_set_html_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_auto_size") ) { lime_text_field_get_auto_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_auto_size") ) { lime_text_field_set_auto_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_multiline") ) { lime_text_field_get_multiline=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_multiline") ) { lime_text_field_set_multiline=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_word_wrap") ) { lime_text_field_get_word_wrap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_word_wrap") ) { lime_text_field_set_word_wrap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_num_lines") ) { lime_text_field_get_num_lines=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_chars") ) { lime_text_field_get_max_chars=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_max_chars") ) { lime_text_field_set_max_chars=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_text") ) { lime_text_field_get_line_text=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_color") ) { lime_text_field_get_text_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text_color") ) { lime_text_field_set_text_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_selectable") ) { lime_text_field_get_selectable=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_selectable") ) { lime_text_field_set_selectable=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_background") ) { lime_text_field_get_background=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_background") ) { lime_text_field_set_background=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_width") ) { lime_text_field_get_text_width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_height") ) { lime_text_field_get_text_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_text_format") ) { lime_text_field_get_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_text_format") ) { lime_text_field_set_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_offset") ) { lime_text_field_get_line_offset=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_border_color") ) { lime_text_field_get_border_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_border_color") ) { lime_text_field_set_border_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_scroll_v") ) { lime_text_field_get_max_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_max_scroll_h") ) { lime_text_field_get_max_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_line_metrics") ) { lime_text_field_get_line_metrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_def_text_format") ) { lime_text_field_get_def_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_def_text_format") ) { lime_text_field_set_def_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_get_bottom_scroll_v") ) { lime_text_field_get_bottom_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_background_color") ) { lime_text_field_get_background_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_background_color") ) { lime_text_field_set_background_color=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_text_field_get_display_as_password") ) { lime_text_field_get_display_as_password=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_text_field_set_display_as_password") ) { lime_text_field_set_display_as_password=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextField_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("antiAliasType"));
	outFields->push(HX_CSTRING("autoSize"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("borderColor"));
	outFields->push(HX_CSTRING("bottomScrollV"));
	outFields->push(HX_CSTRING("defaultTextFormat"));
	outFields->push(HX_CSTRING("displayAsPassword"));
	outFields->push(HX_CSTRING("embedFonts"));
	outFields->push(HX_CSTRING("gridFitType"));
	outFields->push(HX_CSTRING("htmlText"));
	outFields->push(HX_CSTRING("maxChars"));
	outFields->push(HX_CSTRING("maxScrollH"));
	outFields->push(HX_CSTRING("maxScrollV"));
	outFields->push(HX_CSTRING("multiline"));
	outFields->push(HX_CSTRING("numLines"));
	outFields->push(HX_CSTRING("scrollH"));
	outFields->push(HX_CSTRING("scrollV"));
	outFields->push(HX_CSTRING("selectable"));
	outFields->push(HX_CSTRING("sharpness"));
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("textColor"));
	outFields->push(HX_CSTRING("textHeight"));
	outFields->push(HX_CSTRING("textWidth"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("wordWrap"));
	outFields->push(HX_CSTRING("__embedFonts"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lime_text_field_create"),
	HX_CSTRING("lime_text_field_get_text"),
	HX_CSTRING("lime_text_field_set_text"),
	HX_CSTRING("lime_text_field_get_html_text"),
	HX_CSTRING("lime_text_field_set_html_text"),
	HX_CSTRING("lime_text_field_get_text_color"),
	HX_CSTRING("lime_text_field_set_text_color"),
	HX_CSTRING("lime_text_field_get_selectable"),
	HX_CSTRING("lime_text_field_set_selectable"),
	HX_CSTRING("lime_text_field_get_display_as_password"),
	HX_CSTRING("lime_text_field_set_display_as_password"),
	HX_CSTRING("lime_text_field_get_def_text_format"),
	HX_CSTRING("lime_text_field_set_def_text_format"),
	HX_CSTRING("lime_text_field_get_auto_size"),
	HX_CSTRING("lime_text_field_set_auto_size"),
	HX_CSTRING("lime_text_field_get_type"),
	HX_CSTRING("lime_text_field_set_type"),
	HX_CSTRING("lime_text_field_get_multiline"),
	HX_CSTRING("lime_text_field_set_multiline"),
	HX_CSTRING("lime_text_field_get_word_wrap"),
	HX_CSTRING("lime_text_field_set_word_wrap"),
	HX_CSTRING("lime_text_field_get_border"),
	HX_CSTRING("lime_text_field_set_border"),
	HX_CSTRING("lime_text_field_get_border_color"),
	HX_CSTRING("lime_text_field_set_border_color"),
	HX_CSTRING("lime_text_field_get_background"),
	HX_CSTRING("lime_text_field_set_background"),
	HX_CSTRING("lime_text_field_get_background_color"),
	HX_CSTRING("lime_text_field_set_background_color"),
	HX_CSTRING("lime_text_field_get_text_width"),
	HX_CSTRING("lime_text_field_get_text_height"),
	HX_CSTRING("lime_text_field_get_text_format"),
	HX_CSTRING("lime_text_field_set_text_format"),
	HX_CSTRING("lime_text_field_get_max_scroll_v"),
	HX_CSTRING("lime_text_field_get_max_scroll_h"),
	HX_CSTRING("lime_text_field_get_bottom_scroll_v"),
	HX_CSTRING("lime_text_field_get_scroll_h"),
	HX_CSTRING("lime_text_field_set_scroll_h"),
	HX_CSTRING("lime_text_field_get_scroll_v"),
	HX_CSTRING("lime_text_field_set_scroll_v"),
	HX_CSTRING("lime_text_field_get_num_lines"),
	HX_CSTRING("lime_text_field_get_max_chars"),
	HX_CSTRING("lime_text_field_set_max_chars"),
	HX_CSTRING("lime_text_field_get_line_text"),
	HX_CSTRING("lime_text_field_get_line_metrics"),
	HX_CSTRING("lime_text_field_get_line_offset"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::text::AntiAliasType*/ ,(int)offsetof(TextField_obj,antiAliasType),HX_CSTRING("antiAliasType")},
	{hx::fsInt,(int)offsetof(TextField_obj,bottomScrollV),HX_CSTRING("bottomScrollV")},
	{hx::fsObject /*::openfl::text::GridFitType*/ ,(int)offsetof(TextField_obj,gridFitType),HX_CSTRING("gridFitType")},
	{hx::fsInt,(int)offsetof(TextField_obj,maxScrollH),HX_CSTRING("maxScrollH")},
	{hx::fsInt,(int)offsetof(TextField_obj,maxScrollV),HX_CSTRING("maxScrollV")},
	{hx::fsInt,(int)offsetof(TextField_obj,numLines),HX_CSTRING("numLines")},
	{hx::fsFloat,(int)offsetof(TextField_obj,sharpness),HX_CSTRING("sharpness")},
	{hx::fsFloat,(int)offsetof(TextField_obj,textHeight),HX_CSTRING("textHeight")},
	{hx::fsFloat,(int)offsetof(TextField_obj,textWidth),HX_CSTRING("textWidth")},
	{hx::fsBool,(int)offsetof(TextField_obj,__embedFonts),HX_CSTRING("__embedFonts")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("antiAliasType"),
	HX_CSTRING("bottomScrollV"),
	HX_CSTRING("gridFitType"),
	HX_CSTRING("maxScrollH"),
	HX_CSTRING("maxScrollV"),
	HX_CSTRING("numLines"),
	HX_CSTRING("sharpness"),
	HX_CSTRING("textHeight"),
	HX_CSTRING("textWidth"),
	HX_CSTRING("__embedFonts"),
	HX_CSTRING("appendText"),
	HX_CSTRING("getLineOffset"),
	HX_CSTRING("getLineText"),
	HX_CSTRING("getLineMetrics"),
	HX_CSTRING("getTextFormat"),
	HX_CSTRING("replaceText"),
	HX_CSTRING("setSelection"),
	HX_CSTRING("setTextFormat"),
	HX_CSTRING("get_autoSize"),
	HX_CSTRING("set_autoSize"),
	HX_CSTRING("get_background"),
	HX_CSTRING("set_background"),
	HX_CSTRING("get_backgroundColor"),
	HX_CSTRING("set_backgroundColor"),
	HX_CSTRING("get_border"),
	HX_CSTRING("set_border"),
	HX_CSTRING("get_borderColor"),
	HX_CSTRING("set_borderColor"),
	HX_CSTRING("get_bottomScrollV"),
	HX_CSTRING("get_defaultTextFormat"),
	HX_CSTRING("set_defaultTextFormat"),
	HX_CSTRING("get_displayAsPassword"),
	HX_CSTRING("set_displayAsPassword"),
	HX_CSTRING("get_embedFonts"),
	HX_CSTRING("set_embedFonts"),
	HX_CSTRING("get_htmlText"),
	HX_CSTRING("set_htmlText"),
	HX_CSTRING("get_maxChars"),
	HX_CSTRING("set_maxChars"),
	HX_CSTRING("get_maxScrollH"),
	HX_CSTRING("get_maxScrollV"),
	HX_CSTRING("get_multiline"),
	HX_CSTRING("set_multiline"),
	HX_CSTRING("get_numLines"),
	HX_CSTRING("get_scrollH"),
	HX_CSTRING("set_scrollH"),
	HX_CSTRING("get_scrollV"),
	HX_CSTRING("set_scrollV"),
	HX_CSTRING("get_selectable"),
	HX_CSTRING("set_selectable"),
	HX_CSTRING("get_text"),
	HX_CSTRING("set_text"),
	HX_CSTRING("get_textColor"),
	HX_CSTRING("set_textColor"),
	HX_CSTRING("get_textWidth"),
	HX_CSTRING("get_textHeight"),
	HX_CSTRING("get_type"),
	HX_CSTRING("set_type"),
	HX_CSTRING("get_wordWrap"),
	HX_CSTRING("set_wordWrap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextField_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_create,"lime_text_field_create");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_text,"lime_text_field_get_text");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_text,"lime_text_field_set_text");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_html_text,"lime_text_field_get_html_text");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_html_text,"lime_text_field_set_html_text");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_text_color,"lime_text_field_get_text_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_text_color,"lime_text_field_set_text_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_selectable,"lime_text_field_get_selectable");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_selectable,"lime_text_field_set_selectable");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_display_as_password,"lime_text_field_get_display_as_password");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_display_as_password,"lime_text_field_set_display_as_password");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_def_text_format,"lime_text_field_get_def_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_def_text_format,"lime_text_field_set_def_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_auto_size,"lime_text_field_get_auto_size");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_auto_size,"lime_text_field_set_auto_size");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_type,"lime_text_field_get_type");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_type,"lime_text_field_set_type");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_multiline,"lime_text_field_get_multiline");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_multiline,"lime_text_field_set_multiline");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_word_wrap,"lime_text_field_get_word_wrap");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_word_wrap,"lime_text_field_set_word_wrap");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_border,"lime_text_field_get_border");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_border,"lime_text_field_set_border");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_border_color,"lime_text_field_get_border_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_border_color,"lime_text_field_set_border_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_background,"lime_text_field_get_background");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_background,"lime_text_field_set_background");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_background_color,"lime_text_field_get_background_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_background_color,"lime_text_field_set_background_color");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_text_width,"lime_text_field_get_text_width");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_text_height,"lime_text_field_get_text_height");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_text_format,"lime_text_field_get_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_text_format,"lime_text_field_set_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_max_scroll_v,"lime_text_field_get_max_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_max_scroll_h,"lime_text_field_get_max_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_bottom_scroll_v,"lime_text_field_get_bottom_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_scroll_h,"lime_text_field_get_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_scroll_h,"lime_text_field_set_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_scroll_v,"lime_text_field_get_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_scroll_v,"lime_text_field_set_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_num_lines,"lime_text_field_get_num_lines");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_max_chars,"lime_text_field_get_max_chars");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_set_max_chars,"lime_text_field_set_max_chars");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_line_text,"lime_text_field_get_line_text");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_line_metrics,"lime_text_field_get_line_metrics");
	HX_MARK_MEMBER_NAME(TextField_obj::lime_text_field_get_line_offset,"lime_text_field_get_line_offset");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextField_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_create,"lime_text_field_create");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_text,"lime_text_field_get_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_text,"lime_text_field_set_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_html_text,"lime_text_field_get_html_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_html_text,"lime_text_field_set_html_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_text_color,"lime_text_field_get_text_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_text_color,"lime_text_field_set_text_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_selectable,"lime_text_field_get_selectable");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_selectable,"lime_text_field_set_selectable");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_display_as_password,"lime_text_field_get_display_as_password");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_display_as_password,"lime_text_field_set_display_as_password");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_def_text_format,"lime_text_field_get_def_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_def_text_format,"lime_text_field_set_def_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_auto_size,"lime_text_field_get_auto_size");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_auto_size,"lime_text_field_set_auto_size");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_type,"lime_text_field_get_type");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_type,"lime_text_field_set_type");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_multiline,"lime_text_field_get_multiline");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_multiline,"lime_text_field_set_multiline");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_word_wrap,"lime_text_field_get_word_wrap");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_word_wrap,"lime_text_field_set_word_wrap");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_border,"lime_text_field_get_border");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_border,"lime_text_field_set_border");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_border_color,"lime_text_field_get_border_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_border_color,"lime_text_field_set_border_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_background,"lime_text_field_get_background");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_background,"lime_text_field_set_background");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_background_color,"lime_text_field_get_background_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_background_color,"lime_text_field_set_background_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_text_width,"lime_text_field_get_text_width");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_text_height,"lime_text_field_get_text_height");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_text_format,"lime_text_field_get_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_text_format,"lime_text_field_set_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_max_scroll_v,"lime_text_field_get_max_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_max_scroll_h,"lime_text_field_get_max_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_bottom_scroll_v,"lime_text_field_get_bottom_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_scroll_h,"lime_text_field_get_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_scroll_h,"lime_text_field_set_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_scroll_v,"lime_text_field_get_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_scroll_v,"lime_text_field_set_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_num_lines,"lime_text_field_get_num_lines");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_max_chars,"lime_text_field_get_max_chars");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_set_max_chars,"lime_text_field_set_max_chars");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_line_text,"lime_text_field_get_line_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_line_metrics,"lime_text_field_get_line_metrics");
	HX_VISIT_MEMBER_NAME(TextField_obj::lime_text_field_get_line_offset,"lime_text_field_get_line_offset");
};

#endif

Class TextField_obj::__mClass;

void TextField_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.text.TextField"), hx::TCanCast< TextField_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void TextField_obj::__boot()
{
	lime_text_field_create= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_create"),(int)0);
	lime_text_field_get_text= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_text"),(int)1);
	lime_text_field_set_text= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_text"),(int)2);
	lime_text_field_get_html_text= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_html_text"),(int)1);
	lime_text_field_set_html_text= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_html_text"),(int)2);
	lime_text_field_get_text_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_text_color"),(int)1);
	lime_text_field_set_text_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_text_color"),(int)2);
	lime_text_field_get_selectable= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_selectable"),(int)1);
	lime_text_field_set_selectable= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_selectable"),(int)2);
	lime_text_field_get_display_as_password= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_display_as_password"),(int)1);
	lime_text_field_set_display_as_password= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_display_as_password"),(int)2);
	lime_text_field_get_def_text_format= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_def_text_format"),(int)2);
	lime_text_field_set_def_text_format= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_def_text_format"),(int)2);
	lime_text_field_get_auto_size= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_auto_size"),(int)1);
	lime_text_field_set_auto_size= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_auto_size"),(int)2);
	lime_text_field_get_type= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_type"),(int)1);
	lime_text_field_set_type= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_type"),(int)2);
	lime_text_field_get_multiline= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_multiline"),(int)1);
	lime_text_field_set_multiline= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_multiline"),(int)2);
	lime_text_field_get_word_wrap= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_word_wrap"),(int)1);
	lime_text_field_set_word_wrap= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_word_wrap"),(int)2);
	lime_text_field_get_border= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_border"),(int)1);
	lime_text_field_set_border= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_border"),(int)2);
	lime_text_field_get_border_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_border_color"),(int)1);
	lime_text_field_set_border_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_border_color"),(int)2);
	lime_text_field_get_background= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_background"),(int)1);
	lime_text_field_set_background= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_background"),(int)2);
	lime_text_field_get_background_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_background_color"),(int)1);
	lime_text_field_set_background_color= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_background_color"),(int)2);
	lime_text_field_get_text_width= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_text_width"),(int)1);
	lime_text_field_get_text_height= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_text_height"),(int)1);
	lime_text_field_get_text_format= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_text_format"),(int)4);
	lime_text_field_set_text_format= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_text_format"),(int)4);
	lime_text_field_get_max_scroll_v= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_max_scroll_v"),(int)1);
	lime_text_field_get_max_scroll_h= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_max_scroll_h"),(int)1);
	lime_text_field_get_bottom_scroll_v= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_bottom_scroll_v"),(int)1);
	lime_text_field_get_scroll_h= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_scroll_h"),(int)1);
	lime_text_field_set_scroll_h= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_scroll_h"),(int)2);
	lime_text_field_get_scroll_v= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_scroll_v"),(int)1);
	lime_text_field_set_scroll_v= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_scroll_v"),(int)2);
	lime_text_field_get_num_lines= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_num_lines"),(int)1);
	lime_text_field_get_max_chars= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_max_chars"),(int)1);
	lime_text_field_set_max_chars= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_set_max_chars"),(int)2);
	lime_text_field_get_line_text= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_line_text"),(int)2);
	lime_text_field_get_line_metrics= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_line_metrics"),(int)3);
	lime_text_field_get_line_offset= ::openfl::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_text_field_get_line_offset"),(int)2);
}

} // end namespace openfl
} // end namespace text
