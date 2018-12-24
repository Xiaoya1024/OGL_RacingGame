#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include "Vector.h"
#include "Euler.h"
#include "MathHelper.h"
#include "Quaternion.h"

Matrix::Matrix(void)
{
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){//初始化为单位矩阵
		if(i%5==0)
			mat[i]=1;
		else
			mat[i]=0;
	}
}
Matrix::Matrix(float*p){
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]=p[i];
	}
}
Matrix::Matrix(const Matrix&p){
	float *mat = (float*)&m00;
	float *pMat=(float*)&(p.m00);
	for(int i=0;i<16;i++){
		mat[i]=pMat[i];
	}
}

void Matrix::Set(float *p){
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]=p[i];
	}
}
void Matrix::Set(const Matrix&p){
	float *mat = (float*)&m00;
	float *pMat=(float*)&(p.m00);
	for(int i=0;i<16;i++){
		mat[i]=pMat[i];
	}
}
Matrix& Matrix::operator=(const Matrix&p){//矩阵赋值
	this->m00=p.m00;
	this->m01=p.m01;
	this->m02=p.m02;
	this->m03=p.m03;
	this->m10=p.m10;
	this->m11=p.m11;
	this->m12=p.m12;
	this->m13=p.m13;
	this->m20=p.m20;
	this->m21=p.m21;
	this->m22=p.m22;
	this->m23=p.m23;
	this->m30=p.m30;
	this->m31=p.m31;
	this->m32=p.m32;
	this->m33=p.m33;
	return *this;
}
Matrix Matrix::operator*(float d){//矩阵数乘
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]*=d;
	}
	return *this;
}
Matrix Matrix::operator/(float d){//矩阵数除
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]/=d;
	}
	return *this;
}
Matrix Matrix::operator+(Matrix&p){//矩阵相加
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]+=p[i];
	}
	return *this;
}
Matrix Matrix::operator-(Matrix&p){//矩阵相加
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]-=p[i];
	}
	return *this;
}
Matrix Matrix::operator-(){
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		mat[i]=-mat[i];
	}
	return *this;
}
bool Matrix::operator==(Matrix&p){
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		if(mat[i]!=p[i]){
			return false;
		}
	}
	return true;
}
bool Matrix::operator!=(Matrix&p){
	float *mat = (float*)&m00;
	for(int i=0;i<16;i++){
		if(mat[i]!=p[i]){
			return true;
		}
	}
	return false;
}
Matrix Matrix::operator*(Matrix&p){//矩阵相乘
	Matrix vec;
	float *mat = (float*)&m00;
	for(int i=0;i<4;i++){
		vec[i]=mat[i]*p[0]+mat[i+4]*p[1]+mat[i+8]*p[2]+mat[i+12]*p[3];
		vec[i+4]=mat[i]*p[4]+mat[i+4]*p[5]+mat[i+8]*p[6]+mat[i+12]*p[7];
		vec[i+8]=mat[i]*p[8]+mat[i+4]*p[9]+mat[i+8]*p[10]+mat[i+12]*p[11];
		vec[i+12]=mat[i]*p[12]+mat[i+4]*p[13]+mat[i+8]*p[14]+mat[i+12]*p[15];
	}
	return vec;
}

Vector Matrix::MulPosition(Vector& p){//矩阵乘以位置
	int i;
	Vector vec;
	float *mat = (float*)&m00;
	for( i=0;i<3;i++)
	{
		vec[i] = mat[i]*p.x +mat[4+i]*p.y +mat[8+i]*p.z+mat[12+i];
	}
	return vec;
}
Vector Matrix::MulVector(Vector& p){//矩阵乘以空间向量
	int i;
	Vector vec;
	float *mat = (float*)&m00;
	for( i=0;i<3;i++)
	{
		vec[i] = float(mat[i]*p.x +mat[4+i]*p.y +mat[8+i]*p.z);
	}
	return vec;
}
Matrix& Matrix::SetRotate(float seta,Vector&axis){
	axis.getNormalize();
	seta=DegreeToRadian(seta);
	m03=m13=m23=m30=m31=m32=0;
	m33=1;
	m00=axis.x*axis.x*(1-cos(seta))+cos(seta);
	m01=axis.x*axis.y*(1-cos(seta))-axis.z*sin(seta);
	m02=axis.x*axis.z*(1-cos(seta))+axis.y*sin(seta);
	m10=axis.x*axis.y*(1-cos(seta))+axis.z*sin(seta);
	m11=axis.y*axis.y*(1-cos(seta))+cos(seta);
	m12=axis.y*axis.z*(1-cos(seta))-axis.x*sin(seta);
	m20=axis.x*axis.z*(1-cos(seta))-axis.y*sin(seta);
	m21=axis.y*axis.z*(1-cos(seta))+axis.x*sin(seta);
	m22=axis.z*axis.z*(1-cos(seta))+cos(seta);
	return *this;
}
Matrix& Matrix::SetRotateByAxis(float seta,int axis){
	float c = cos(seta);
	float s = sin(seta);
	if(axis==0)
	{
		m00=1;m01=0;m02=0;m03=0;
		m10=0;m11=c;m12=-s;m13=0;
		m20=0;m21=s;m22=c;m23=0;
		m30=0;m31=0;m32=0;m33=1;
	}
	else if(axis==1)
	{
		m00=c;m01=0;m02=s;m03=0;
		m10=0;m11=1;m12=0;m13=0;
		m20=-s;m21=0;m22=c;m23=0;
		m30=0;m31=0;m32=0;m33=1;
	}
	else
	{
		m00=c;m01=-s;m02=0;m03=0;
		m10=s;m11=c;m12=0;m13=0;
		m20=0;m21=0;m22=1;m23=0;
		m30=0;m31=0;m32=0;m33=1;
	}
	return *this;
}
Matrix& Matrix::SetTrans(Vector&trans){
	m00=m11=m22=m33=1;
	m03=trans.x;
	m13=trans.y;
	m23=trans.z;
	return *this;
}
Matrix& Matrix::SetScale(Vector&p){
	m00=p.x;
	m11=p.y;
	m22=p.z;
	m33=1;
	return *this;
}
float Matrix::Determinant(){//求行列式
	float result=0;
	Vector a=Vector(m10,m20,m30);
	Vector b=Vector(m11,m21,m31);
	Vector c=Vector(m12,m22,m32);
	Vector d=Vector(m13,m23,m33);
	float p1=(b.crossMul(c)).dotMul(d);
	float p2=(a.crossMul(c)).dotMul(d);
	float p3=(a.crossMul(b)).dotMul(d);
	float p4=(a.crossMul(b)).dotMul(c);
	return result=m00*p1-m01*p2+m02*p3-m03*p4;
}
Matrix Matrix::Adjoint(){//求伴随矩阵
	Vector v[16];
	float *mat = (float*)&m00;
	for(int i=0;i<16;i+=4){
		v[i].Set(mat[i],mat[i+1],mat[i+2]);
		v[i+1].Set(mat[i],mat[i+1],mat[i+3]);
		v[i+2].Set(mat[i],mat[i+2],mat[i+3]);
		v[i+3].Set(mat[i+1],mat[i+2],mat[i+3]);
	}
	Matrix vec;
	vec[0]=(v[7].crossMul(v[11])).dotMul(v[15]);
	vec[4]=-(v[6].crossMul(v[10])).dotMul(v[14]);
	vec[8]=(v[5].crossMul(v[9])).dotMul(v[13]);
	vec[12]=-(v[4].crossMul(v[8])).dotMul(v[12]);

	vec[1]=-(v[3].crossMul(v[11])).dotMul(v[15]);
	vec[5]=(v[2].crossMul(v[10])).dotMul(v[14]);
	vec[9]=-(v[1].crossMul(v[9])).dotMul(v[13]);
	vec[13]=(v[0].crossMul(v[8])).dotMul(v[12]);

	vec[2]=(v[3].crossMul(v[7])).dotMul(v[15]);
	vec[6]=-(v[2].crossMul(v[6])).dotMul(v[14]);
	vec[10]=(v[1].crossMul(v[5])).dotMul(v[13]);
	vec[14]=-(v[0].crossMul(v[4])).dotMul(v[12]);

	vec[3]=-(v[3].crossMul(v[7])).dotMul(v[11]);
	vec[7]=(v[2].crossMul(v[6])).dotMul(v[10]);
	vec[11]=-(v[1].crossMul(v[5])).dotMul(v[9]);
	vec[15]=(v[0].crossMul(v[4])).dotMul(v[8]);

	return vec;
}
float Matrix::Inverse(){
	float res=Determinant();
	if(res!=0)
		return res;
	else 
		return 0;
}
Matrix Matrix::GetInverse(){
	return Adjoint()/Determinant();
}
Euler Matrix::ToEuler(){
	Euler eul;
	eul.h=RadianToDegree(atan(m02/m22));
	eul.p=RadianToDegree(asin(-m12));
	eul.b=RadianToDegree(atan(m10/m11));
	return eul;
}
Quaternion Matrix::ToQuaternion(){
	Quaternion res;
	res.w=sqrt(m00+m11+m22+1)/2;
	res.x=-(m12-m21)/(4*res.w);
	res.y=-(m20-m02)/(4*res.w);
	res.z=-(m01-m10)/(4*res.w);
	return res;
}
