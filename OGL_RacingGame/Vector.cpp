#include "Vector.h"
#include "MathHelper.h"
#include "Euler.h"
Vector::Vector()
{
	x=0.0f;
	y=0.0f;
	z=0.0f;
}
Vector::Vector(float x,float y,float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
Vector::Vector(const Vector &p){
	this->x=p.x;
	this->y=p.y;
	this->z=p.z;
}
void Vector::Set(float x,float y,float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
void Vector::Set(const Vector&p){
	this->x=p.x;
	this->y=p.y;
	this->z=p.z;
}
//���������+
Vector Vector::operator+(Vector &p){
	return Vector(x+p.x,y+p.y,z+p.z);
}

//���������-
Vector Vector::operator-(Vector &p){
	return Vector(x-p.x,y-p.y,z-p.z);
}

//���������*
Vector Vector::operator*(float p){
	return Vector(x*p,y*p,z*p);
}
//���������=
Vector& Vector::operator=(Vector &p){
	x=p.x;y=p.y;z=p.z;
	return *this;
}
Vector Vector::operator-(){
	Vector vec;
	vec.x=-x;
	vec.y=-y;
	vec.z=-z;
	return vec;
}
//���������==
bool Vector::operator==(Vector &p){
	if(x==p.x&&y==p.y&&z==p.z){
		return true;
	}
	return false;
}
bool Vector::operator!=(Vector &p){
	return !((*this)==p);
}

//������˲���
float Vector::dotMul(Vector &n){
	return x*n.x+y*n.y+z*n.z;
}

//������˲���
Vector Vector::crossMul(Vector &n){
	return Vector(y*n.z-z*n.y,z*n.x-x*n.z,x*n.y-y*n.x);
}

bool Vector::canNormalize(){
	float len=this->len();
	if(len<=FLOAT_EPS)return false;
	else return true;
}
//������׼��
void Vector::normalize(){
	float len=this->len();
	x=x/len;
	y=y/len;
	z=z/len;
}

//��ȡ��׼�����
Vector Vector::getNormalize(){
	float len=this->len();
	Vector vec;
	vec.z=x/len;
	vec.y=y/len;
	vec.z=z/len;
	return vec;
}

//����������ģ
float Vector::len(){
	return sqrtf((x*x)+(y*y)+(z*z));
}

Vector Vector::project(Vector &n){//����ͶӰ����
	float uv=(this->dotMul(n))/((n.x*n.x)+(n.y*n.y)+(n.z*n.z));
	return Vector(uv*n.x,uv*n.y,uv*n.z);
}

float Vector::findSeta(Vector&p){//����������֮��ļн�
	float res=this->dotMul(p);
	float a1=this->len();
	float a2=p.len();
	return acosf(res/(a1*a2));//���ص���һ������
}
Vector Vector::rotateByAxis(float angle,int type){
	Vector res;
	float _angle=DegreeToRadian(angle);
	if(type==0){
		res.x=this->x;
		res.y=this->y*cos(_angle)-this->z*sin(_angle);
		res.z=this->y*sin(_angle)+this->z*cos(_angle);
	}else if(type==1){
		res.y=this->y;
		res.x=this->x*cos(_angle)-this->z*sin(_angle);
		res.z=this->x*(sin(_angle))+this->z*cos(_angle);
	}else if(type==2){
		res.z=this->z;
		res.x=this->x*cos(_angle)-this->y*sin(_angle);
		res.y=this->x*sin(_angle)+this->y*cos(_angle);
	}
	return res;
}

Vector Vector::lerp(Vector&Vend,float t){
	Vector a=*this;
	return a*(1-t)+Vend*t;
}
void Vector::lerp(Vector&Vend,int n,float*t,Vector*Result){
	for(int i=0;i<n;i++){
		Result[i]=lerp(Vend,t[i]);
	}
}
Euler Vector::ToEuler(){//ת��Ϊŷ����
	float len=this->len();
	float temp=y/len;
	if(temp>1){
		temp=1;
	}
	else if(temp<-1){
		temp=-1;
	}
	float angle=RadianToDegree(atan2(-x,-z));
	float ph=RadianToDegree(acos(temp));
	Euler ceuler;
	ceuler.Set(angle,90-ph,0);
	return ceuler.GetNormalize();
}
