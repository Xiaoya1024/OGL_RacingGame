#define _CRT_SECURE_NO_WARNINGS
#include "Quaternion.h"
#include "Euler.h"
#include "Vector.h"
#include "Matrix.h"
#include "MathHelper.h"
Quaternion::Quaternion(void)
{
	this->x=0;
	this->y=0;
	this->z=0;
	this->w=1;
}
Quaternion::Quaternion(float x,float y,float z,float w){
	this->x=x;
	this->y=y;
	this->z=z;
	this->w=w;
}
Quaternion::Quaternion(const Quaternion&p){
	this->x=p.x;
	this->y=p.y;
	this->z=p.z;
	this->w=p.w;
}
void Quaternion::Set(float x,float y,float z,float w){
	this->x=x;
	this->y=y;
	this->z=z;
	this->w=w;
}
void Quaternion::Set(const Quaternion&p){
	this->x=p.x;
	this->y=p.y;
	this->z=p.z;
	this->w=p.w;
}
Euler Quaternion::ToEuler(){
	Euler res;
	res.p=RadianToDegree(asin(2*w*x-2*y*z));
	if(fabs(cos(DegreeToRadian(res.p)))<=1e-6)
		res.h=RadianToDegree(atan((2*w*y-2*z*x)/(1-2*y*y-2*z*z)));
	else
		res.h=RadianToDegree(atan((2*z*x+2*w*y)/(1-2*x*x-2*y*y)));
	if(fabs(cos(DegreeToRadian(res.p)))<=1e-6)
		res.b=0;
	else
		res.b=RadianToDegree(atan((2*x*y+2*w*z)/(1-2*z*z-2*x*x)));
	return res;
}
Matrix Quaternion::ToMatrix(){
	Matrix mat;
	mat.m00=1-2*y*y-2*z*z;
	mat.m01=2*x*y-2*w*z;
	mat.m02=2*x*z+2*w*y;
	mat.m03=0;
	mat.m10=2*x*y+2*w*z;
	mat.m11=1-2*x*x-2*z*z;
	mat.m12=2*y*z-2*w*x;
	mat.m13=0;
	mat.m20=2*x*z-2*w*y;
	mat.m21=2*y*z+2*w*x;
	mat.m22=1-2*x*x-2*y*y;
	mat.m23=0;
	mat.m30=0;
	mat.m31=0;
	mat.m32=0;
	mat.m33=1;
	return mat;
}

void Quaternion::SetAngle(float angle,Vector axis){
	w = (float)(cos((angle / 2)*PI / 180));
	x = (float)(axis.x*sin((angle / 2)*PI / 180));
	y = (float)(axis.y*sin((angle / 2)*PI / 180));
	z = (float)(axis.z*sin((angle / 2)*PI / 180));
}
void Quaternion::GetAngle(float&angle,Vector&axis){
	Quaternion res;
	res=*this;
	res=res.getNormalize();
	angle=(float)(2*RadianToDegree(acos(res.w)));
	axis.x=(float)(res.x/sin((angle/2)*PI/180));
	axis.y=(float)(res.y/sin((angle/2)*PI/180));
	axis.z=(float)(res.z/sin((angle/2)*PI/180));
}
Quaternion& Quaternion::operator=(const Quaternion&p){
	x=p.x;
	y=p.y;
	z=p.z;
	w=p.w;
	return *this;
}
Quaternion Quaternion::operator+(const Quaternion&p){
	Quaternion res;
	res.x=x+p.x;
	res.y=y+p.y;
	res.z=z+p.z;
	res.w=w+p.w;
	return res;
}
Quaternion Quaternion::operator*(float data){
	Quaternion res;
	res.x=x*data;
	res.y=y*data;
	res.z=z*data;
	res.w=w*data;
	return res;
}
Quaternion Quaternion::operator*(const Quaternion&p){
	Quaternion res;
	res.w = w * p.w - x * p.x - y * p.y - z * p.z;
	res.x = w * p.x + x * p.w - y * p.z + z * p.y;
	res.y = w * p.y + y * p.w - z * p.x + x * p.z;
	res.z = w * p.z + z * p.w - x * p.y + y * p.x;
	return res;
}
Quaternion Quaternion::operator-(const Quaternion&p){
	Quaternion res;
	res.x=x-p.x;
	res.y=y-p.y;
	res.z=z-p.z;
	res.w=w-p.w;
	return res;
}
Quaternion Quaternion::operator-(){
	Quaternion res;
	res.x=-x;
	res.y=-y;
	res.z=-z;
	res.w=-w;
	return res;
}
float Quaternion::dotMul(const Quaternion&p){
	float res;
	res=x*p.x+y*p.y+z*p.z+w*p.w;
	return res;
}
float Quaternion::len(){
	return sqrtf(x*x+y*y+z*z+w*w);
}
bool Quaternion::canNormalize(){
	if(len()<=FLOAT_EPS)return false;
	else return true;
}
void Quaternion::normalize(){
	float length=this->len();
	x=x/length;
	y=y/length;
	z=z/length;
	w=w/length;
}
Quaternion Quaternion::getNormalize(){
	Quaternion qua;
	float length=this->len();
	qua.x=x/length;
	qua.y=y/length;
	qua.z=z/length;
	qua.w=w/length;
	return qua;
}
Quaternion& Quaternion::Inverse(){
	float length=len();
	if(fabs(length)<=1e-6)
		length=1;
	w=w/length/length;
	x=-x/length/length;
	y=-y/length/length;
	z=-z/length/length;
	return *this;
}
Quaternion Quaternion::GetInverse(){
	Quaternion res;
	float length=len();
	if(fabs(length)<=1e-6)
		length=1;
	res.w=w/length/length;
	res.x=-x/length/length;
	res.y=-y/length/length;
	res.z=-z/length/length;
	return res;
}
Quaternion Quaternion::Div(const Quaternion&b){
	Quaternion inv,res;
	inv=this->GetInverse();
	res=inv*b;
	return res;
}
Quaternion Quaternion::Slerp(Quaternion&Vend,float t){
	Quaternion a,b;

	a=this->getNormalize();
	b=Vend.getNormalize();

	float v=this->dotMul(b);
	if(v<0){
		b=-b;
		v=-v;
	}
	float k0,k1;
	if(v>0.9995f){
		k0=1-t;
		k1=t;
	}
	else{
		float v1=sqrtf(1.0f-v*v);
		float v2=atan2(v1,v);
		k0=sin((1.0f-t)*v2)/v1;
		k1=sin(t*v2)/v1;
	}
	return a*k0+b*k1;
}
void Quaternion::Slerp(Quaternion&Vend,int n,float*t,Quaternion *Result){
	for(int i=0;i<n;i++){
		Result[i]=Slerp(Vend,t[i]);
	}
}
