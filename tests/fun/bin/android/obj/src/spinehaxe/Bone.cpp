#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_spinehaxe_Bone
#include <spinehaxe/Bone.h>
#endif
#ifndef INCLUDED_spinehaxe_BoneData
#include <spinehaxe/BoneData.h>
#endif
#ifndef INCLUDED_spinehaxe_Exception
#include <spinehaxe/Exception.h>
#endif
namespace spinehaxe{

Void Bone_obj::__construct(::spinehaxe::BoneData data,::spinehaxe::Bone parent)
{
HX_STACK_FRAME("spinehaxe.Bone","new",0x87d75d5b,"spinehaxe.Bone.new","spinehaxe/Bone.hx",34,0x58cd3894)
HX_STACK_THIS(this)
HX_STACK_ARG(data,"data")
HX_STACK_ARG(parent,"parent")
{
	HX_STACK_LINE(52)
	this->scaleY = (int)0;
	HX_STACK_LINE(51)
	this->scaleX = (int)0;
	HX_STACK_LINE(50)
	this->rotation = (int)0;
	HX_STACK_LINE(49)
	this->y = (int)0;
	HX_STACK_LINE(48)
	this->x = (int)0;
	HX_STACK_LINE(45)
	this->worldScaleY = (int)0;
	HX_STACK_LINE(44)
	this->worldScaleX = (int)0;
	HX_STACK_LINE(43)
	this->worldRotation = (int)0;
	HX_STACK_LINE(42)
	this->worldY = (int)0;
	HX_STACK_LINE(41)
	this->worldX = (int)0;
	HX_STACK_LINE(40)
	this->m11 = (int)0;
	HX_STACK_LINE(39)
	this->m10 = (int)0;
	HX_STACK_LINE(38)
	this->m01 = (int)0;
	HX_STACK_LINE(37)
	this->m00 = (int)0;
	HX_STACK_LINE(55)
	if (((data == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(::spinehaxe::Exception_obj::__new(HX_CSTRING("data cannot be null.")));
	}
	HX_STACK_LINE(57)
	this->data = data;
	HX_STACK_LINE(58)
	this->parent = parent;
	HX_STACK_LINE(59)
	this->setToSetupPose();
}
;
	return null();
}

//Bone_obj::~Bone_obj() { }

Dynamic Bone_obj::__CreateEmpty() { return  new Bone_obj; }
hx::ObjectPtr< Bone_obj > Bone_obj::__new(::spinehaxe::BoneData data,::spinehaxe::Bone parent)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(data,parent);
	return result;}

Dynamic Bone_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Bone_obj::updateWorldTransform( bool flipX,bool flipY){
{
		HX_STACK_FRAME("spinehaxe.Bone","updateWorldTransform",0x6ce57d48,"spinehaxe.Bone.updateWorldTransform","spinehaxe/Bone.hx",63,0x58cd3894)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flipX,"flipX")
		HX_STACK_ARG(flipY,"flipY")
		HX_STACK_LINE(64)
		if (((this->parent != null()))){
			HX_STACK_LINE(65)
			this->worldX = (((this->x * this->parent->m00) + (this->y * this->parent->m01)) + this->parent->worldX);
			HX_STACK_LINE(66)
			this->worldY = (((this->x * this->parent->m10) + (this->y * this->parent->m11)) + this->parent->worldY);
			HX_STACK_LINE(67)
			if ((this->data->inheritScale)){
				HX_STACK_LINE(68)
				this->worldScaleX = (this->parent->worldScaleX * this->scaleX);
				HX_STACK_LINE(69)
				this->worldScaleY = (this->parent->worldScaleY * this->scaleY);
			}
			else{
				HX_STACK_LINE(73)
				this->worldScaleX = this->scaleX;
				HX_STACK_LINE(74)
				this->worldScaleY = this->scaleY;
			}
			HX_STACK_LINE(77)
			if ((this->data->inheritRotation)){
				HX_STACK_LINE(77)
				this->worldRotation = (this->parent->worldRotation + this->rotation);
			}
			else{
				HX_STACK_LINE(77)
				this->worldRotation = this->rotation;
			}
		}
		else{
			HX_STACK_LINE(81)
			if ((flipX)){
				HX_STACK_LINE(81)
				this->worldX = -(this->x);
			}
			else{
				HX_STACK_LINE(81)
				this->worldX = this->x;
			}
			HX_STACK_LINE(82)
			if (((flipY != ::spinehaxe::Bone_obj::yDown))){
				HX_STACK_LINE(82)
				this->worldY = -(this->y);
			}
			else{
				HX_STACK_LINE(82)
				this->worldY = this->y;
			}
			HX_STACK_LINE(83)
			this->worldScaleX = this->scaleX;
			HX_STACK_LINE(84)
			this->worldScaleY = this->scaleY;
			HX_STACK_LINE(85)
			this->worldRotation = this->rotation;
		}
		HX_STACK_LINE(88)
		Float radians = (this->worldRotation * ((Float(::Math_obj::PI) / Float((int)180))));		HX_STACK_VAR(radians,"radians");
		HX_STACK_LINE(89)
		Float cos = ::Math_obj::cos(radians);		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(90)
		Float sin = ::Math_obj::sin(radians);		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(91)
		this->m00 = (cos * this->worldScaleX);
		HX_STACK_LINE(92)
		this->m10 = (sin * this->worldScaleX);
		HX_STACK_LINE(93)
		this->m01 = (-(sin) * this->worldScaleY);
		HX_STACK_LINE(94)
		this->m11 = (cos * this->worldScaleY);
		HX_STACK_LINE(95)
		if ((flipX)){
			HX_STACK_LINE(96)
			this->m00 = -(this->m00);
			HX_STACK_LINE(97)
			this->m01 = -(this->m01);
		}
		HX_STACK_LINE(99)
		if (((flipY != ::spinehaxe::Bone_obj::yDown))){
			HX_STACK_LINE(100)
			this->m10 = -(this->m10);
			HX_STACK_LINE(101)
			this->m11 = -(this->m11);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Bone_obj,updateWorldTransform,(void))

Void Bone_obj::setToSetupPose( ){
{
		HX_STACK_FRAME("spinehaxe.Bone","setToSetupPose",0xcb8efed6,"spinehaxe.Bone.setToSetupPose","spinehaxe/Bone.hx",105,0x58cd3894)
		HX_STACK_THIS(this)
		HX_STACK_LINE(106)
		this->x = this->data->x;
		HX_STACK_LINE(107)
		this->y = this->data->y;
		HX_STACK_LINE(108)
		this->rotation = this->data->rotation;
		HX_STACK_LINE(109)
		this->scaleX = this->data->scaleX;
		HX_STACK_LINE(110)
		this->scaleY = this->data->scaleY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,setToSetupPose,(void))

::String Bone_obj::toString( ){
	HX_STACK_FRAME("spinehaxe.Bone","toString",0xe82355d1,"spinehaxe.Bone.toString","spinehaxe/Bone.hx",114,0x58cd3894)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->data->name;
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,toString,return )

bool Bone_obj::yDown;


Bone_obj::Bone_obj()
{
}

void Bone_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bone);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(m00,"m00");
	HX_MARK_MEMBER_NAME(m01,"m01");
	HX_MARK_MEMBER_NAME(m10,"m10");
	HX_MARK_MEMBER_NAME(m11,"m11");
	HX_MARK_MEMBER_NAME(worldX,"worldX");
	HX_MARK_MEMBER_NAME(worldY,"worldY");
	HX_MARK_MEMBER_NAME(worldRotation,"worldRotation");
	HX_MARK_MEMBER_NAME(worldScaleX,"worldScaleX");
	HX_MARK_MEMBER_NAME(worldScaleY,"worldScaleY");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_END_CLASS();
}

void Bone_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(m00,"m00");
	HX_VISIT_MEMBER_NAME(m01,"m01");
	HX_VISIT_MEMBER_NAME(m10,"m10");
	HX_VISIT_MEMBER_NAME(m11,"m11");
	HX_VISIT_MEMBER_NAME(worldX,"worldX");
	HX_VISIT_MEMBER_NAME(worldY,"worldY");
	HX_VISIT_MEMBER_NAME(worldRotation,"worldRotation");
	HX_VISIT_MEMBER_NAME(worldScaleX,"worldScaleX");
	HX_VISIT_MEMBER_NAME(worldScaleY,"worldScaleY");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
}

Dynamic Bone_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m00") ) { return m00; }
		if (HX_FIELD_EQ(inName,"m01") ) { return m01; }
		if (HX_FIELD_EQ(inName,"m10") ) { return m10; }
		if (HX_FIELD_EQ(inName,"m11") ) { return m11; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"yDown") ) { return yDown; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"worldX") ) { return worldX; }
		if (HX_FIELD_EQ(inName,"worldY") ) { return worldY; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"worldScaleX") ) { return worldScaleX; }
		if (HX_FIELD_EQ(inName,"worldScaleY") ) { return worldScaleY; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"worldRotation") ) { return worldRotation; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setToSetupPose") ) { return setToSetupPose_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"updateWorldTransform") ) { return updateWorldTransform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bone_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m00") ) { m00=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m01") ) { m01=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m10") ) { m10=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m11") ) { m11=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::spinehaxe::BoneData >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"yDown") ) { yDown=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::spinehaxe::Bone >(); return inValue; }
		if (HX_FIELD_EQ(inName,"worldX") ) { worldX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"worldY") ) { worldY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"worldScaleX") ) { worldScaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"worldScaleY") ) { worldScaleY=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"worldRotation") ) { worldRotation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bone_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("m00"));
	outFields->push(HX_CSTRING("m01"));
	outFields->push(HX_CSTRING("m10"));
	outFields->push(HX_CSTRING("m11"));
	outFields->push(HX_CSTRING("worldX"));
	outFields->push(HX_CSTRING("worldY"));
	outFields->push(HX_CSTRING("worldRotation"));
	outFields->push(HX_CSTRING("worldScaleX"));
	outFields->push(HX_CSTRING("worldScaleY"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("yDown"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::spinehaxe::BoneData*/ ,(int)offsetof(Bone_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*::spinehaxe::Bone*/ ,(int)offsetof(Bone_obj,parent),HX_CSTRING("parent")},
	{hx::fsFloat,(int)offsetof(Bone_obj,m00),HX_CSTRING("m00")},
	{hx::fsFloat,(int)offsetof(Bone_obj,m01),HX_CSTRING("m01")},
	{hx::fsFloat,(int)offsetof(Bone_obj,m10),HX_CSTRING("m10")},
	{hx::fsFloat,(int)offsetof(Bone_obj,m11),HX_CSTRING("m11")},
	{hx::fsFloat,(int)offsetof(Bone_obj,worldX),HX_CSTRING("worldX")},
	{hx::fsFloat,(int)offsetof(Bone_obj,worldY),HX_CSTRING("worldY")},
	{hx::fsFloat,(int)offsetof(Bone_obj,worldRotation),HX_CSTRING("worldRotation")},
	{hx::fsFloat,(int)offsetof(Bone_obj,worldScaleX),HX_CSTRING("worldScaleX")},
	{hx::fsFloat,(int)offsetof(Bone_obj,worldScaleY),HX_CSTRING("worldScaleY")},
	{hx::fsFloat,(int)offsetof(Bone_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Bone_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(Bone_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsFloat,(int)offsetof(Bone_obj,scaleX),HX_CSTRING("scaleX")},
	{hx::fsFloat,(int)offsetof(Bone_obj,scaleY),HX_CSTRING("scaleY")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("parent"),
	HX_CSTRING("m00"),
	HX_CSTRING("m01"),
	HX_CSTRING("m10"),
	HX_CSTRING("m11"),
	HX_CSTRING("worldX"),
	HX_CSTRING("worldY"),
	HX_CSTRING("worldRotation"),
	HX_CSTRING("worldScaleX"),
	HX_CSTRING("worldScaleY"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("rotation"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("updateWorldTransform"),
	HX_CSTRING("setToSetupPose"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Bone_obj::yDown,"yDown");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Bone_obj::yDown,"yDown");
};

#endif

Class Bone_obj::__mClass;

void Bone_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("spinehaxe.Bone"), hx::TCanCast< Bone_obj> ,sStaticFields,sMemberFields,
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

void Bone_obj::__boot()
{
	yDown= false;
}

} // end namespace spinehaxe
