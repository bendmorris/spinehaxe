#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_ArrayUtils
#include <spinehaxe/ArrayUtils.h>
#endif
#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
#ifndef INCLUDED_spinehaxe_Skeleton
#include <spinehaxe/Skeleton.h>
#endif
#ifndef INCLUDED_spinehaxe_Slot
#include <spinehaxe/Slot.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_AtlasRegion
#include <spinehaxe/atlas/AtlasRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_atlas_TextureRegion
#include <spinehaxe/atlas/TextureRegion.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_Attachment
#include <spinehaxe/attachments/Attachment.h>
#endif
#ifndef INCLUDED_spinehaxe_attachments_RegionAttachment
#include <spinehaxe/attachments/RegionAttachment.h>
#endif
namespace spinehaxe{
namespace attachments{

Void RegionAttachment_obj::__construct(::String name)
{
HX_STACK_FRAME("spinehaxe.attachments.RegionAttachment","new",0x2394aa8c,"spinehaxe.attachments.RegionAttachment.new","spinehaxe/attachments/RegionAttachment.hx",34,0xd77a2622)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(67)
	this->a = (int)1;
	HX_STACK_LINE(66)
	this->b = (int)1;
	HX_STACK_LINE(65)
	this->g = (int)1;
	HX_STACK_LINE(64)
	this->r = (int)1;
	HX_STACK_LINE(63)
	this->height = (int)0;
	HX_STACK_LINE(62)
	this->width = (int)0;
	HX_STACK_LINE(61)
	this->rotation = (int)0;
	HX_STACK_LINE(60)
	this->scaleY = (int)1;
	HX_STACK_LINE(59)
	this->scaleX = (int)1;
	HX_STACK_LINE(58)
	this->y = (int)0;
	HX_STACK_LINE(57)
	this->x = (int)0;
	HX_STACK_LINE(73)
	super::__construct(name);
	HX_STACK_LINE(74)
	Array< Float > _g = ::spinehaxe::ArrayUtils_obj::allocFloat((int)20);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	this->vertices = _g;
	HX_STACK_LINE(75)
	Array< Float > _g1 = ::spinehaxe::ArrayUtils_obj::allocFloat((int)8);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(75)
	this->offset = _g1;
}
;
	return null();
}

//RegionAttachment_obj::~RegionAttachment_obj() { }

Dynamic RegionAttachment_obj::__CreateEmpty() { return  new RegionAttachment_obj; }
hx::ObjectPtr< RegionAttachment_obj > RegionAttachment_obj::__new(::String name)
{  hx::ObjectPtr< RegionAttachment_obj > result = new RegionAttachment_obj();
	result->__construct(name);
	return result;}

Dynamic RegionAttachment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RegionAttachment_obj > result = new RegionAttachment_obj();
	result->__construct(inArgs[0]);
	return result;}

Void RegionAttachment_obj::updateOffset( ){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionAttachment","updateOffset",0x4ba3bed0,"spinehaxe.attachments.RegionAttachment.updateOffset","spinehaxe/attachments/RegionAttachment.hx",78,0xd77a2622)
		HX_STACK_THIS(this)
		HX_STACK_LINE(79)
		Float localX2 = (Float(this->width) / Float((int)2));		HX_STACK_VAR(localX2,"localX2");
		HX_STACK_LINE(80)
		Float localY2 = (Float(this->height) / Float((int)2));		HX_STACK_VAR(localY2,"localY2");
		HX_STACK_LINE(81)
		Float localX = -(localX2);		HX_STACK_VAR(localX,"localX");
		HX_STACK_LINE(82)
		Float localY = -(localY2);		HX_STACK_VAR(localY,"localY");
		HX_STACK_LINE(83)
		if ((::Std_obj::is(this->region,hx::ClassOf< ::spinehaxe::atlas::AtlasRegion >()))){
			HX_STACK_LINE(84)
			::spinehaxe::atlas::AtlasRegion region;		HX_STACK_VAR(region,"region");
			HX_STACK_LINE(84)
			region = hx::TCast< spinehaxe::atlas::AtlasRegion >::cast(this->region);
			HX_STACK_LINE(85)
			if ((region->rotate)){
				HX_STACK_LINE(86)
				hx::AddEq(localX,((Float(region->offsetX) / Float(region->originalWidth)) * this->height));
				HX_STACK_LINE(87)
				hx::AddEq(localY,((Float(region->offsetY) / Float(region->originalHeight)) * this->width));
				HX_STACK_LINE(88)
				hx::SubEq(localX2,((Float((((region->originalWidth - region->offsetX) - region->packedHeight))) / Float(region->originalWidth)) * this->height));
				HX_STACK_LINE(89)
				hx::SubEq(localY2,((Float((((region->originalHeight - region->offsetY) - region->packedWidth))) / Float(region->originalHeight)) * this->width));
			}
			else{
				HX_STACK_LINE(91)
				hx::AddEq(localX,((Float(region->offsetX) / Float(region->originalWidth)) * this->width));
				HX_STACK_LINE(92)
				hx::AddEq(localY,((Float(region->offsetY) / Float(region->originalHeight)) * this->height));
				HX_STACK_LINE(93)
				hx::SubEq(localX2,((Float((((region->originalWidth - region->offsetX) - region->packedWidth))) / Float(region->originalWidth)) * this->width));
				HX_STACK_LINE(94)
				hx::SubEq(localY2,((Float((((region->originalHeight - region->offsetY) - region->packedHeight))) / Float(region->originalHeight)) * this->height));
			}
		}
		HX_STACK_LINE(97)
		hx::MultEq(localX,this->scaleX);
		HX_STACK_LINE(98)
		hx::MultEq(localY,this->scaleY);
		HX_STACK_LINE(99)
		hx::MultEq(localX2,this->scaleX);
		HX_STACK_LINE(100)
		hx::MultEq(localY2,this->scaleY);
		HX_STACK_LINE(101)
		Float rotation = ((Float(::Math_obj::PI) / Float((int)180)) * this->rotation);		HX_STACK_VAR(rotation,"rotation");
		HX_STACK_LINE(102)
		Float cos = ::Math_obj::cos(rotation);		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(103)
		Float sin = ::Math_obj::sin(rotation);		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(104)
		Float localXCos = ((localX * cos) + this->x);		HX_STACK_VAR(localXCos,"localXCos");
		HX_STACK_LINE(105)
		Float localXSin = (localX * sin);		HX_STACK_VAR(localXSin,"localXSin");
		HX_STACK_LINE(106)
		Float localYCos = ((localY * cos) + this->y);		HX_STACK_VAR(localYCos,"localYCos");
		HX_STACK_LINE(107)
		Float localYSin = (localY * sin);		HX_STACK_VAR(localYSin,"localYSin");
		HX_STACK_LINE(108)
		Float localX2Cos = ((localX2 * cos) + this->x);		HX_STACK_VAR(localX2Cos,"localX2Cos");
		HX_STACK_LINE(109)
		Float localX2Sin = (localX2 * sin);		HX_STACK_VAR(localX2Sin,"localX2Sin");
		HX_STACK_LINE(110)
		Float localY2Cos = ((localY2 * cos) + this->y);		HX_STACK_VAR(localY2Cos,"localY2Cos");
		HX_STACK_LINE(111)
		Float localY2Sin = (localY2 * sin);		HX_STACK_VAR(localY2Sin,"localY2Sin");
		HX_STACK_LINE(112)
		this->offset->__unsafe_set((int)0,(localXCos - localYSin));
		HX_STACK_LINE(113)
		this->offset->__unsafe_set((int)1,(localYCos + localXSin));
		HX_STACK_LINE(114)
		this->offset->__unsafe_set((int)2,(localXCos - localY2Sin));
		HX_STACK_LINE(115)
		this->offset->__unsafe_set((int)3,(localY2Cos + localXSin));
		HX_STACK_LINE(116)
		this->offset->__unsafe_set((int)4,(localX2Cos - localY2Sin));
		HX_STACK_LINE(117)
		this->offset->__unsafe_set((int)5,(localY2Cos + localX2Sin));
		HX_STACK_LINE(118)
		this->offset->__unsafe_set((int)6,(localX2Cos - localYSin));
		HX_STACK_LINE(119)
		this->offset->__unsafe_set((int)7,(localYCos + localX2Sin));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RegionAttachment_obj,updateOffset,(void))

Void RegionAttachment_obj::setRegion( ::spinehaxe::atlas::TextureRegion region){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionAttachment","setRegion",0xe044f962,"spinehaxe.attachments.RegionAttachment.setRegion","spinehaxe/attachments/RegionAttachment.hx",122,0xd77a2622)
		HX_STACK_THIS(this)
		HX_STACK_ARG(region,"region")
		HX_STACK_LINE(123)
		if (((region == null()))){
			HX_STACK_LINE(123)
			HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("region cannot be null.")));
		}
		HX_STACK_LINE(124)
		this->region = region;
		HX_STACK_LINE(125)
		if (((  ((::Std_obj::is(region,hx::ClassOf< ::spinehaxe::atlas::AtlasRegion >()))) ? bool((hx::TCast< spinehaxe::atlas::AtlasRegion >::cast(region))->rotate) : bool(false) ))){
			HX_STACK_LINE(126)
			this->vertices->__unsafe_set((int)8,region->u);
			HX_STACK_LINE(127)
			this->vertices->__unsafe_set((int)9,region->v2);
			HX_STACK_LINE(128)
			this->vertices->__unsafe_set((int)13,region->u);
			HX_STACK_LINE(129)
			this->vertices->__unsafe_set((int)14,region->v);
			HX_STACK_LINE(130)
			this->vertices->__unsafe_set((int)18,region->u2);
			HX_STACK_LINE(131)
			this->vertices->__unsafe_set((int)19,region->v);
			HX_STACK_LINE(132)
			this->vertices->__unsafe_set((int)3,region->u2);
			HX_STACK_LINE(133)
			this->vertices->__unsafe_set((int)4,region->v2);
		}
		else{
			HX_STACK_LINE(135)
			this->vertices->__unsafe_set((int)3,region->u);
			HX_STACK_LINE(136)
			this->vertices->__unsafe_set((int)4,region->v2);
			HX_STACK_LINE(137)
			this->vertices->__unsafe_set((int)8,region->u);
			HX_STACK_LINE(138)
			this->vertices->__unsafe_set((int)9,region->v);
			HX_STACK_LINE(139)
			this->vertices->__unsafe_set((int)13,region->u2);
			HX_STACK_LINE(140)
			this->vertices->__unsafe_set((int)14,region->v);
			HX_STACK_LINE(141)
			this->vertices->__unsafe_set((int)18,region->u2);
			HX_STACK_LINE(142)
			this->vertices->__unsafe_set((int)19,region->v2);
		}
		HX_STACK_LINE(144)
		this->updateOffset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RegionAttachment_obj,setRegion,(void))

Void RegionAttachment_obj::updateVertices( ::spinehaxe::Slot slot){
{
		HX_STACK_FRAME("spinehaxe.attachments.RegionAttachment","updateVertices",0x143ff076,"spinehaxe.attachments.RegionAttachment.updateVertices","spinehaxe/attachments/RegionAttachment.hx",147,0xd77a2622)
		HX_STACK_THIS(this)
		HX_STACK_ARG(slot,"slot")
		HX_STACK_LINE(148)
		::spinehaxe::Skeleton skeleton = slot->skeleton;		HX_STACK_VAR(skeleton,"skeleton");
		HX_STACK_LINE(156)
		Float color = (int)1;		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(157)
		this->vertices->__unsafe_set((int)2,color);
		HX_STACK_LINE(158)
		this->vertices->__unsafe_set((int)7,color);
		HX_STACK_LINE(159)
		this->vertices->__unsafe_set((int)12,color);
		HX_STACK_LINE(160)
		this->vertices->__unsafe_set((int)17,color);
		HX_STACK_LINE(162)
		::spinehaxe::Bone bone = slot->bone;		HX_STACK_VAR(bone,"bone");
		HX_STACK_LINE(163)
		Float x = (bone->worldX + skeleton->x);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(164)
		Float y = (bone->worldY + skeleton->y);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(165)
		Float m00 = bone->m00;		HX_STACK_VAR(m00,"m00");
		HX_STACK_LINE(166)
		Float m01 = bone->m01;		HX_STACK_VAR(m01,"m01");
		HX_STACK_LINE(167)
		Float m10 = bone->m10;		HX_STACK_VAR(m10,"m10");
		HX_STACK_LINE(168)
		Float m11 = bone->m11;		HX_STACK_VAR(m11,"m11");
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(169)
			Float _g = this->offset->__unsafe_get((int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(169)
			Float _g1 = (_g * m00);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(169)
			Float _g2 = this->offset->__unsafe_get((int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(169)
			Float _g3 = (_g2 * m01);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(169)
			Float _g4 = (_g1 + _g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(169)
			Float val = (_g4 + x);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(169)
			this->vertices->__unsafe_set((int)0,val);
		}
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			Float _g5 = this->offset->__unsafe_get((int)0);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(170)
			Float _g6 = (_g5 * m10);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(170)
			Float _g7 = this->offset->__unsafe_get((int)1);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(170)
			Float _g8 = (_g7 * m11);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(170)
			Float _g9 = (_g6 + _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(170)
			Float val = (_g9 + y);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(170)
			this->vertices->__unsafe_set((int)1,val);
		}
		HX_STACK_LINE(171)
		{
			HX_STACK_LINE(171)
			Float _g10 = this->offset->__unsafe_get((int)2);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(171)
			Float _g11 = (_g10 * m00);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(171)
			Float _g12 = this->offset->__unsafe_get((int)3);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(171)
			Float _g13 = (_g12 * m01);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(171)
			Float _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(171)
			Float val = (_g14 + x);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(171)
			this->vertices->__unsafe_set((int)5,val);
		}
		HX_STACK_LINE(172)
		{
			HX_STACK_LINE(172)
			Float _g15 = this->offset->__unsafe_get((int)2);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(172)
			Float _g16 = (_g15 * m10);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(172)
			Float _g17 = this->offset->__unsafe_get((int)3);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(172)
			Float _g18 = (_g17 * m11);		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(172)
			Float _g19 = (_g16 + _g18);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(172)
			Float val = (_g19 + y);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(172)
			this->vertices->__unsafe_set((int)6,val);
		}
		HX_STACK_LINE(173)
		{
			HX_STACK_LINE(173)
			Float _g20 = this->offset->__unsafe_get((int)4);		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(173)
			Float _g21 = (_g20 * m00);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(173)
			Float _g22 = this->offset->__unsafe_get((int)5);		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(173)
			Float _g23 = (_g22 * m01);		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(173)
			Float _g24 = (_g21 + _g23);		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(173)
			Float val = (_g24 + x);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(173)
			this->vertices->__unsafe_set((int)10,val);
		}
		HX_STACK_LINE(174)
		{
			HX_STACK_LINE(174)
			Float _g25 = this->offset->__unsafe_get((int)4);		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(174)
			Float _g26 = (_g25 * m10);		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(174)
			Float _g27 = this->offset->__unsafe_get((int)5);		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(174)
			Float _g28 = (_g27 * m11);		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(174)
			Float _g29 = (_g26 + _g28);		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(174)
			Float val = (_g29 + y);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(174)
			this->vertices->__unsafe_set((int)11,val);
		}
		HX_STACK_LINE(175)
		{
			HX_STACK_LINE(175)
			Float _g30 = this->offset->__unsafe_get((int)6);		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(175)
			Float _g31 = (_g30 * m00);		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(175)
			Float _g32 = this->offset->__unsafe_get((int)7);		HX_STACK_VAR(_g32,"_g32");
			HX_STACK_LINE(175)
			Float _g33 = (_g32 * m01);		HX_STACK_VAR(_g33,"_g33");
			HX_STACK_LINE(175)
			Float _g34 = (_g31 + _g33);		HX_STACK_VAR(_g34,"_g34");
			HX_STACK_LINE(175)
			Float val = (_g34 + x);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(175)
			this->vertices->__unsafe_set((int)15,val);
		}
		HX_STACK_LINE(176)
		{
			HX_STACK_LINE(176)
			Float _g35 = this->offset->__unsafe_get((int)6);		HX_STACK_VAR(_g35,"_g35");
			HX_STACK_LINE(176)
			Float _g36 = (_g35 * m10);		HX_STACK_VAR(_g36,"_g36");
			HX_STACK_LINE(176)
			Float _g37 = this->offset->__unsafe_get((int)7);		HX_STACK_VAR(_g37,"_g37");
			HX_STACK_LINE(176)
			Float _g38 = (_g37 * m11);		HX_STACK_VAR(_g38,"_g38");
			HX_STACK_LINE(176)
			Float _g39 = (_g36 + _g38);		HX_STACK_VAR(_g39,"_g39");
			HX_STACK_LINE(176)
			Float val = (_g39 + y);		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(176)
			this->vertices->__unsafe_set((int)16,val);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RegionAttachment_obj,updateVertices,(void))

int RegionAttachment_obj::X1;

int RegionAttachment_obj::Y1;

int RegionAttachment_obj::C1;

int RegionAttachment_obj::U1;

int RegionAttachment_obj::V1;

int RegionAttachment_obj::X2;

int RegionAttachment_obj::Y2;

int RegionAttachment_obj::C2;

int RegionAttachment_obj::U2;

int RegionAttachment_obj::V2;

int RegionAttachment_obj::X3;

int RegionAttachment_obj::Y3;

int RegionAttachment_obj::C3;

int RegionAttachment_obj::U3;

int RegionAttachment_obj::V3;

int RegionAttachment_obj::X4;

int RegionAttachment_obj::Y4;

int RegionAttachment_obj::C4;

int RegionAttachment_obj::U4;

int RegionAttachment_obj::V4;


RegionAttachment_obj::RegionAttachment_obj()
{
}

void RegionAttachment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RegionAttachment);
	HX_MARK_MEMBER_NAME(region,"region");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	HX_MARK_MEMBER_NAME(offset,"offset");
	::spinehaxe::attachments::Attachment_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RegionAttachment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(region,"region");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(g,"g");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(vertices,"vertices");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	::spinehaxe::attachments::Attachment_obj::__Visit(HX_VISIT_ARG);
}

Dynamic RegionAttachment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"region") ) { return region; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setRegion") ) { return setRegion_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateOffset") ) { return updateOffset_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateVertices") ) { return updateVertices_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RegionAttachment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"region") ) { region=inValue.Cast< ::spinehaxe::atlas::TextureRegion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RegionAttachment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("region"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("vertices"));
	outFields->push(HX_CSTRING("offset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("X1"),
	HX_CSTRING("Y1"),
	HX_CSTRING("C1"),
	HX_CSTRING("U1"),
	HX_CSTRING("V1"),
	HX_CSTRING("X2"),
	HX_CSTRING("Y2"),
	HX_CSTRING("C2"),
	HX_CSTRING("U2"),
	HX_CSTRING("V2"),
	HX_CSTRING("X3"),
	HX_CSTRING("Y3"),
	HX_CSTRING("C3"),
	HX_CSTRING("U3"),
	HX_CSTRING("V3"),
	HX_CSTRING("X4"),
	HX_CSTRING("Y4"),
	HX_CSTRING("C4"),
	HX_CSTRING("U4"),
	HX_CSTRING("V4"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::atlas::TextureRegion*/ ,(int)offsetof(RegionAttachment_obj,region),HX_CSTRING("region")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,scaleX),HX_CSTRING("scaleX")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,scaleY),HX_CSTRING("scaleY")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,height),HX_CSTRING("height")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(RegionAttachment_obj,a),HX_CSTRING("a")},
	{hx::fsString,(int)offsetof(RegionAttachment_obj,path),HX_CSTRING("path")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(RegionAttachment_obj,vertices),HX_CSTRING("vertices")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(RegionAttachment_obj,offset),HX_CSTRING("offset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("region"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("rotation"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("path"),
	HX_CSTRING("vertices"),
	HX_CSTRING("offset"),
	HX_CSTRING("updateOffset"),
	HX_CSTRING("setRegion"),
	HX_CSTRING("updateVertices"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::X1,"X1");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::Y1,"Y1");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::C1,"C1");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::U1,"U1");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::V1,"V1");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::X2,"X2");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::Y2,"Y2");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::C2,"C2");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::U2,"U2");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::V2,"V2");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::X3,"X3");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::Y3,"Y3");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::C3,"C3");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::U3,"U3");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::V3,"V3");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::X4,"X4");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::Y4,"Y4");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::C4,"C4");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::U4,"U4");
	HX_MARK_MEMBER_NAME(RegionAttachment_obj::V4,"V4");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::X1,"X1");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::Y1,"Y1");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::C1,"C1");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::U1,"U1");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::V1,"V1");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::X2,"X2");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::Y2,"Y2");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::C2,"C2");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::U2,"U2");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::V2,"V2");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::X3,"X3");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::Y3,"Y3");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::C3,"C3");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::U3,"U3");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::V3,"V3");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::X4,"X4");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::Y4,"Y4");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::C4,"C4");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::U4,"U4");
	HX_VISIT_MEMBER_NAME(RegionAttachment_obj::V4,"V4");
};

#endif

Class RegionAttachment_obj::__mClass;

void RegionAttachment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.attachments.RegionAttachment"), hx::TCanCast< RegionAttachment_obj> ,sStaticFields,sMemberFields,
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

void RegionAttachment_obj::__boot()
{
	X1= (int)0;
	Y1= (int)1;
	C1= (int)2;
	U1= (int)3;
	V1= (int)4;
	X2= (int)5;
	Y2= (int)6;
	C2= (int)7;
	U2= (int)8;
	V2= (int)9;
	X3= (int)10;
	Y3= (int)11;
	C3= (int)12;
	U3= (int)13;
	V3= (int)14;
	X4= (int)15;
	Y4= (int)16;
	C4= (int)17;
	U4= (int)18;
	V4= (int)19;
}

} // end namespace spinehaxe
} // end namespace attachments
