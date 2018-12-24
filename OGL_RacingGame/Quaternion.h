#pragma once
class Euler;
class Matrix;
class Vector;
class Quaternion
{
public:
	Quaternion(void);
	Quaternion(float x,float y,float z,float w);
	Quaternion(const Quaternion&p);

	float x,y,z,w;
	void Set(float x,float y,float z,float w);
	void Set(const Quaternion&p);
	operator float*(){return &x;}

	void SetAngle(float angle,Vector axis);//四元数设置
	void GetAngle(float&angle,Vector&axis);//求旋转轴和角度
	Quaternion& operator=(const Quaternion&p);//重载赋值
	Quaternion operator+(const Quaternion&p);//重载‘+’
	Quaternion operator*(float data);//重载数乘
	Quaternion operator*(const Quaternion&p);//四元数乘法
	Quaternion operator-(const Quaternion&p);//四元数求差
	Quaternion operator-();//求相反数

	float dotMul(const Quaternion&p);//点乘
	float len();//求模

	bool canNormalize();//是否可以标准化
	void normalize();//求标准化，改变自身
	Quaternion getNormalize();//求标准化结果，不改变自身，生成新的四元数

	Quaternion& Inverse();//求逆四元数，会改变自身
	Quaternion GetInverse();//求逆四元数，不改变自身，生成新的四元数
	Quaternion Div(const Quaternion&b);//求差，当前为a，求c=a-b
	Quaternion Slerp(Quaternion&Vend,float t);//插值。从当前四元数插值到Vend四元数，t是参数[0,1]
	void Slerp(Quaternion&Vend,int n,float*t,Quaternion *Result);//插值，一次插值出n个数据，插值参数保存在数组t中，结果返回到数组Result中。
	
	Euler ToEuler();
	Matrix ToMatrix();
};

