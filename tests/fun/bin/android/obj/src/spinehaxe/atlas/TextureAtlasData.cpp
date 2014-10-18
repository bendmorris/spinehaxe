#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_StringInput
#include <haxe/io/StringInput.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Page
#include <spinehaxe/atlas/Page.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_Region
#include <spinehaxe/atlas/Region.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureAtlasData
#include <spinehaxe/atlas/TextureAtlasData.h>
#endif
namespace spinehaxe{
namespace atlas{

Void TextureAtlasData_obj::__construct(::String packFileData,::String imagesDir,bool flip)
{
HX_STACK_FRAME("spinehaxe.atlas.TextureAtlasData","new",0x3b47df14,"spinehaxe.atlas.TextureAtlasData.new","spinehaxe/atlas/TextureAtlas.hx",82,0xde245664)
HX_STACK_THIS(this)
HX_STACK_ARG(packFileData,"packFileData")
HX_STACK_ARG(imagesDir,"imagesDir")
HX_STACK_ARG(flip,"flip")
{
	HX_STACK_LINE(83)
	this->tuple = Array_obj< ::String >::__new().Add(null()).Add(null()).Add(null()).Add(null());
	HX_STACK_LINE(84)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(84)
	this->pages = _g;
	HX_STACK_LINE(85)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(85)
	this->regions = _g1;
	HX_STACK_LINE(87)
	::haxe::io::StringInput reader = ::haxe::io::StringInput_obj::__new(packFileData);		HX_STACK_VAR(reader,"reader");
	HX_STACK_LINE(88)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(89)
		::spinehaxe::atlas::Page pageImage = null();		HX_STACK_VAR(pageImage,"pageImage");
		HX_STACK_LINE(90)
		while((true)){
			HX_STACK_LINE(91)
			::String line = null();		HX_STACK_VAR(line,"line");
			HX_STACK_LINE(92)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
			{
				HX_STACK_LINE(92)
				::String _g2 = reader->readLine();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(92)
				line = _g2;
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					HX_STACK_BEGIN_CATCH
					::haxe::io::Eof e = __e;{
						HX_STACK_LINE(92)
						break;
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
			HX_STACK_LINE(93)
			if (((line == null()))){
				HX_STACK_LINE(93)
				break;
			}
			HX_STACK_LINE(94)
			if (((::StringTools_obj::trim(line).length == (int)0))){
				HX_STACK_LINE(95)
				pageImage = null();
			}
			else{
				HX_STACK_LINE(96)
				if (((pageImage == null()))){
					HX_STACK_LINE(97)
					::String file = (imagesDir + line);		HX_STACK_VAR(file,"file");
					HX_STACK_LINE(99)
					::String format = this->readValue(reader);		HX_STACK_VAR(format,"format");
					HX_STACK_LINE(101)
					this->readTuple(reader);
					HX_STACK_LINE(102)
					::String min = this->tuple->__get((int)0);		HX_STACK_VAR(min,"min");
					HX_STACK_LINE(103)
					::String mag = this->tuple->__get((int)1);		HX_STACK_VAR(mag,"mag");
					HX_STACK_LINE(105)
					::String direction = this->readValue(reader);		HX_STACK_VAR(direction,"direction");
					HX_STACK_LINE(106)
					::String repeatX = HX_CSTRING("ClampToEdge");		HX_STACK_VAR(repeatX,"repeatX");
					HX_STACK_LINE(107)
					::String repeatY = HX_CSTRING("ClampToEdge");		HX_STACK_VAR(repeatY,"repeatY");
					HX_STACK_LINE(108)
					if (((direction == HX_CSTRING("x")))){
						HX_STACK_LINE(109)
						repeatX = HX_CSTRING("Repeat");
					}
					else{
						HX_STACK_LINE(110)
						if (((direction == HX_CSTRING("y")))){
							HX_STACK_LINE(111)
							repeatY = HX_CSTRING("Repeat");
						}
						else{
							HX_STACK_LINE(112)
							if (((direction == HX_CSTRING("xy")))){
								HX_STACK_LINE(113)
								repeatX = HX_CSTRING("Repeat");
								HX_STACK_LINE(114)
								repeatY = HX_CSTRING("Repeat");
							}
						}
					}
					HX_STACK_LINE(117)
					::spinehaxe::atlas::Page _g3 = ::spinehaxe::atlas::Page_obj::__new(file,(min == HX_CSTRING("MipMap")),format,min,mag,repeatX,repeatY);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(117)
					pageImage = _g3;
					HX_STACK_LINE(118)
					this->pages->push(pageImage);
				}
				else{
					HX_STACK_LINE(120)
					::String _g4 = this->readValue(reader);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(120)
					bool rotate = (_g4 == HX_CSTRING("true"));		HX_STACK_VAR(rotate,"rotate");
					HX_STACK_LINE(122)
					this->readTuple(reader);
					HX_STACK_LINE(123)
					int left = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(left,"left");
					HX_STACK_LINE(124)
					int top = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(top,"top");
					HX_STACK_LINE(126)
					this->readTuple(reader);
					HX_STACK_LINE(127)
					int width = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(width,"width");
					HX_STACK_LINE(128)
					int height = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(height,"height");
					HX_STACK_LINE(130)
					::spinehaxe::atlas::Region region = ::spinehaxe::atlas::Region_obj::__new();		HX_STACK_VAR(region,"region");
					HX_STACK_LINE(131)
					region->page = pageImage;
					HX_STACK_LINE(132)
					region->left = left;
					HX_STACK_LINE(133)
					region->top = top;
					HX_STACK_LINE(134)
					region->width = width;
					HX_STACK_LINE(135)
					region->height = height;
					HX_STACK_LINE(136)
					region->name = line;
					HX_STACK_LINE(137)
					region->rotate = rotate;
					HX_STACK_LINE(139)
					int _g5 = this->readTuple(reader);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(139)
					if (((_g5 == (int)4))){
						HX_STACK_LINE(140)
						Dynamic _g6 = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(140)
						Dynamic _g7 = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(141)
						Dynamic _g8 = ::Std_obj::parseInt(this->tuple->__get((int)2));		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(141)
						Dynamic _g9 = ::Std_obj::parseInt(this->tuple->__get((int)3));		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(140)
						Array< int > _g10 = Array_obj< int >::__new().Add(_g6).Add(_g7).Add(_g8).Add(_g9);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(140)
						region->splits = _g10;
						HX_STACK_LINE(143)
						int _g11 = this->readTuple(reader);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(143)
						if (((_g11 == (int)4))){
							HX_STACK_LINE(144)
							Dynamic _g12 = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(144)
							Dynamic _g13 = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(145)
							Dynamic _g14 = ::Std_obj::parseInt(this->tuple->__get((int)2));		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(145)
							Dynamic _g15 = ::Std_obj::parseInt(this->tuple->__get((int)3));		HX_STACK_VAR(_g15,"_g15");
							HX_STACK_LINE(144)
							Array< int > _g16 = Array_obj< int >::__new().Add(_g12).Add(_g13).Add(_g14).Add(_g15);		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(144)
							region->pads = _g16;
							HX_STACK_LINE(147)
							this->readTuple(reader);
						}
					}
					HX_STACK_LINE(151)
					Dynamic _g17 = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(151)
					region->originalWidth = _g17;
					HX_STACK_LINE(152)
					Dynamic _g18 = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(152)
					region->originalHeight = _g18;
					HX_STACK_LINE(154)
					this->readTuple(reader);
					HX_STACK_LINE(155)
					Dynamic _g19 = ::Std_obj::parseInt(this->tuple->__get((int)0));		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(155)
					region->offsetX = _g19;
					HX_STACK_LINE(156)
					Dynamic _g20 = ::Std_obj::parseInt(this->tuple->__get((int)1));		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(156)
					region->offsetY = _g20;
					HX_STACK_LINE(158)
					::String _g21 = this->readValue(reader);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(158)
					Dynamic _g22 = ::Std_obj::parseInt(_g21);		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(158)
					region->index = _g22;
					HX_STACK_LINE(160)
					if ((flip)){
						HX_STACK_LINE(160)
						region->flip = true;
					}
					HX_STACK_LINE(162)
					this->regions->push(region);
				}
			}
		}
		HX_STACK_LINE(165)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(165)
			reader->close();
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic ignored = __e;{
				}
			}
		}
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic ex = __e;{
				HX_STACK_LINE(167)
				try
				{
				HX_STACK_CATCHABLE(Dynamic, 0);
				{
					HX_STACK_LINE(167)
					reader->close();
				}
				}
				catch(Dynamic __e){
					{
						HX_STACK_BEGIN_CATCH
						Dynamic ignored = __e;{
						}
					}
				}
				HX_STACK_LINE(168)
				::String _g23 = ::Std_obj::string(ex);		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(168)
				::String _g24 = (HX_CSTRING("Error reading pack file: ") + _g23);		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(168)
				HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(_g24));
			}
		}
	}

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	int run(::spinehaxe::atlas::Region region1,::spinehaxe::atlas::Region region2){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","spinehaxe/atlas/TextureAtlas.hx",171,0xde245664)
		HX_STACK_ARG(region1,"region1")
		HX_STACK_ARG(region2,"region2")
		{
			HX_STACK_LINE(172)
			int MAX_VALUE = (int)16777215;		HX_STACK_VAR(MAX_VALUE,"MAX_VALUE");
			HX_STACK_LINE(173)
			int i1 = region1->index;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(174)
			if (((i1 == (int)-1))){
				HX_STACK_LINE(174)
				i1 = MAX_VALUE;
			}
			HX_STACK_LINE(175)
			int i2 = region2->index;		HX_STACK_VAR(i2,"i2");
			HX_STACK_LINE(176)
			if (((i2 == (int)-1))){
				HX_STACK_LINE(176)
				i2 = MAX_VALUE;
			}
			HX_STACK_LINE(177)
			return (i1 - i2);
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(171)
	this->regions->sort( Dynamic(new _Function_1_1()));
}
;
	return null();
}

//TextureAtlasData_obj::~TextureAtlasData_obj() { }

Dynamic TextureAtlasData_obj::__CreateEmpty() { return  new TextureAtlasData_obj; }
hx::ObjectPtr< TextureAtlasData_obj > TextureAtlasData_obj::__new(::String packFileData,::String imagesDir,bool flip)
{  hx::ObjectPtr< TextureAtlasData_obj > result = new TextureAtlasData_obj();
	result->__construct(packFileData,imagesDir,flip);
	return result;}

Dynamic TextureAtlasData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureAtlasData_obj > result = new TextureAtlasData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String TextureAtlasData_obj::readValue( ::haxe::io::Input reader){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlasData","readValue",0x5629d9ef,"spinehaxe.atlas.TextureAtlasData.readValue","spinehaxe/atlas/TextureAtlas.hx",181,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(reader,"reader")
	HX_STACK_LINE(182)
	::String line = reader->readLine();		HX_STACK_VAR(line,"line");
	HX_STACK_LINE(183)
	int colon = line.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(colon,"colon");
	HX_STACK_LINE(184)
	if (((colon == (int)-1))){
		HX_STACK_LINE(184)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Invalid line: ") + line)));
	}
	HX_STACK_LINE(185)
	::String _g = line.substring((colon + (int)1),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(185)
	return ::StringTools_obj::trim(_g);
}


HX_DEFINE_DYNAMIC_FUNC1(TextureAtlasData_obj,readValue,return )

int TextureAtlasData_obj::readTuple( ::haxe::io::Input reader){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlasData","readTuple",0x3c97f686,"spinehaxe.atlas.TextureAtlasData.readTuple","spinehaxe/atlas/TextureAtlas.hx",189,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_ARG(reader,"reader")
	HX_STACK_LINE(190)
	::String line = reader->readLine();		HX_STACK_VAR(line,"line");
	HX_STACK_LINE(191)
	int colon = line.indexOf(HX_CSTRING(":"),null());		HX_STACK_VAR(colon,"colon");
	HX_STACK_LINE(192)
	if (((colon == (int)-1))){
		HX_STACK_LINE(192)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Invalid line: ") + line)));
	}
	HX_STACK_LINE(193)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(194)
	int lastMatch = (colon + (int)1);		HX_STACK_VAR(lastMatch,"lastMatch");
	HX_STACK_LINE(195)
	while((true)){
		HX_STACK_LINE(195)
		if ((!(((i < (int)3))))){
			HX_STACK_LINE(195)
			break;
		}
		HX_STACK_LINE(196)
		int comma = line.indexOf(HX_CSTRING(","),lastMatch);		HX_STACK_VAR(comma,"comma");
		HX_STACK_LINE(197)
		if (((comma == (int)-1))){
			HX_STACK_LINE(198)
			if (((i == (int)0))){
				HX_STACK_LINE(198)
				HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new((HX_CSTRING("Invalid line: ") + line)));
			}
			HX_STACK_LINE(199)
			break;
		}
		HX_STACK_LINE(201)
		::String _g = line.substring(lastMatch,comma);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(201)
		this->tuple[i] = ::StringTools_obj::trim(_g);
		HX_STACK_LINE(202)
		lastMatch = (comma + (int)1);
		HX_STACK_LINE(203)
		(i)++;
	}
	HX_STACK_LINE(205)
	::String _g1 = line.substring(lastMatch,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(205)
	this->tuple[i] = ::StringTools_obj::trim(_g1);
	HX_STACK_LINE(206)
	return (i + (int)1);
}


HX_DEFINE_DYNAMIC_FUNC1(TextureAtlasData_obj,readTuple,return )

Array< ::Dynamic > TextureAtlasData_obj::getPages( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlasData","getPages",0xa4fa5f9a,"spinehaxe.atlas.TextureAtlasData.getPages","spinehaxe/atlas/TextureAtlas.hx",211,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(211)
	return this->pages;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureAtlasData_obj,getPages,return )

Array< ::Dynamic > TextureAtlasData_obj::getRegions( ){
	HX_STACK_FRAME("spinehaxe.atlas.TextureAtlasData","getRegions",0x8f3f8ad5,"spinehaxe.atlas.TextureAtlasData.getRegions","spinehaxe/atlas/TextureAtlas.hx",215,0xde245664)
	HX_STACK_THIS(this)
	HX_STACK_LINE(215)
	return this->regions;
}


HX_DEFINE_DYNAMIC_FUNC0(TextureAtlasData_obj,getRegions,return )


TextureAtlasData_obj::TextureAtlasData_obj()
{
}

void TextureAtlasData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextureAtlasData);
	HX_MARK_MEMBER_NAME(pages,"pages");
	HX_MARK_MEMBER_NAME(regions,"regions");
	HX_MARK_MEMBER_NAME(tuple,"tuple");
	HX_MARK_END_CLASS();
}

void TextureAtlasData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pages,"pages");
	HX_VISIT_MEMBER_NAME(regions,"regions");
	HX_VISIT_MEMBER_NAME(tuple,"tuple");
}

Dynamic TextureAtlasData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"pages") ) { return pages; }
		if (HX_FIELD_EQ(inName,"tuple") ) { return tuple; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { return regions; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getPages") ) { return getPages_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readValue") ) { return readValue_dyn(); }
		if (HX_FIELD_EQ(inName,"readTuple") ) { return readTuple_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getRegions") ) { return getRegions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureAtlasData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"pages") ) { pages=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tuple") ) { tuple=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { regions=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureAtlasData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pages"));
	outFields->push(HX_CSTRING("regions"));
	outFields->push(HX_CSTRING("tuple"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TextureAtlasData_obj,pages),HX_CSTRING("pages")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TextureAtlasData_obj,regions),HX_CSTRING("regions")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(TextureAtlasData_obj,tuple),HX_CSTRING("tuple")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("pages"),
	HX_CSTRING("regions"),
	HX_CSTRING("tuple"),
	HX_CSTRING("readValue"),
	HX_CSTRING("readTuple"),
	HX_CSTRING("getPages"),
	HX_CSTRING("getRegions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureAtlasData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureAtlasData_obj::__mClass,"__mClass");
};

#endif

Class TextureAtlasData_obj::__mClass;

void TextureAtlasData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.atlas.TextureAtlasData"), hx::TCanCast< TextureAtlasData_obj> ,sStaticFields,sMemberFields,
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

void TextureAtlasData_obj::__boot()
{
}

} // end namespace spinehaxe
} // end namespace atlas
