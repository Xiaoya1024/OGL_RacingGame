#include "Euler.h"
#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "MathHelper.h"

Euler::Euler(void)
{
	h=0.0f;
	p=0.0f;
	b=0.0f;
}
Euler::Euler(float h,float p,float b){
	this->h=h;
	this->p=p;
	this->b=b;
}
Euler::Euler(const Euler&n){
	this->h=n.h;
	this->p=n.p;
	this->b=n.b;
}

void Euler::Set(float h,float p,float b){
	this->h=h;
	this->p=p;
	this->b=b;
}
void Euler::Set(const Euler&n){
	this->h=n.h;
	this->p=n.p;
	this->b=n.b;
}
Vector Euler::ToVector3(Vector*updir){
	updir->x=cos(DegreeToRadian((float)(b+90)));
	updir->y=sin(DegreeToRadian((float)(b+90))*sin(DegreeToRadian(90-p)));
	if(fabs(updir->x)<=1e-6)
		updir->x=0;
	if(fabs(updir->y)<=1e-6)
		updir->y=0;
	updir->z=-cos(DegreeToRadian((float)(90-p)));

	Vector res;
	res.x=cos(DegreeToRadian((float)(h+90)));
	res.z=-sin(DegreeToRadian((float)(h+90)));
	if(fabs(p)<=1e-6)
		res.y=0;
	else
		res.y=tan(DegreeToRadian((float)(p+90)))*sqrtf(res.x*res.x+res.z*res.z);      
	return res;
}

Matrix Euler::ToMatrix(){
	Matrix res;
	float _h=DegreeToRadian(h);
	float _p=DegreeToRadian(p);
	float _b=DegreeToRadian(b);
	res.m00=cos(_h)*cos(_b)+sin(_h)*sin(_p)*sin(_b);
	res.m01=-cos(_h)*sin(_b)+sin(_h)*sin(_p)*cos(_b);
	res.m02=sin(_h)*cos(_p);
	res.m03=0;
	res.m10=sin(_b)*cos(_p);
	res.m11=cos(_b)*cos(_p);
	res.m12=-sin(_p);
	res.m13=0;
	res.m20=-sin(_h)*cos(_b)+cos(_h)*sin(_p)*sin(_b);
	res.m21=sin(_b)*sin(_h)+cos(_h)*sin(_p)*cos(_b);
	res.m22=cos(_h)*cos(_p);
	res.m23=0;
	res.m30=0;
	res.m31=0;
	res.m32=0;
	res.m33=1;
	return res;
}
Quaternion Euler::ToQuaternion(){
	Quaternion res;
	float _h=DegreeToRadian(h);
	float _p=DegreeToRadian(p);
	float _b=DegreeToRadian(b);
	res.w=cos(_h/2)*cos(_p/2)*cos(_b/2)+sin(_h/2)*sin(_p/2)*sin(_b/2);
	res.x=cos(_h/2)*sin(_p/2)*cos(_b/2)+sin(_h/2)*cos(_p/2)*sin(_b/2);
	res.y=sin(_h/2)*cos(_p/2)*cos(_b/2)-cos(_h/2)*sin(_p/2)*sin(_b/2);
	res.z=cos(_h/2)*cos(_p/2)*sin(_b/2)-sin(_h/2)*sin(_p/2)*cos(_b/2);
	return res;
}

void Euler::normalize(){
	while (b > 180.0)
		b -= 360;
	while (b < -180.0)
		b += 360;
	while (p > 90.0)
		p -= 180;
	while (p < -90.0)
		p += 180;
	if (p == 90.0 || p == -90.0) {
		h -= b;
		b = 0;
	}
	while (h > 180.0)
		h -= 360;
	while (h < -180.0)
		h += 360;
}
Euler Euler::GetNormalize(){
	Euler euler;
	while (b > 180.0)
		euler.b = b -360;
	while (b < -180.0)
		euler.b = b + 360;
	while (p > 90.0)
		euler.p = p - 180;
	while (p < -90.0)
		euler.p = p + 180;
	if (p == 90.0 || p == -90.0) {
		euler.h = h - b;
		euler.b = 0;
	}
	while (h > 180.0)
		euler.h = h - 360;
	while (h < -180.0)
		euler.h = h + 360;
	return euler;
}
