#pragma once
class Euler;
class Vector
{
public:
	Vector();
	Vector(float x,float y,float z);
	Vector(const Vector &p);

	float x;//类成员
	float y;
	float z;
	void Set(float x,float y,float z);
	void Set(const Vector&p);
	operator float*(){return &x;}

	Vector operator+(Vector &p);//重载“+”操作
	Vector operator-(Vector &p);//重载“-”操作
	Vector operator*(float p);//重载“*”操作
	Vector& operator=(Vector &p);//重载“=”操作
	Vector operator-();//求相反数
	bool operator==(Vector &p);//重载“==”操作
	bool operator!=(Vector &p);//重载“!=”操作

	float dotMul(Vector &n);//向量点乘操作
	Vector crossMul(Vector &n);//向量叉乘操作
	float len();//向量求模操作
	bool canNormalize();//是否可以标准化
	void normalize();//向量标准化操作
	Vector getNormalize();//获取向量标准化结果
	Vector project(Vector &n);//向量投影操作
	
	float findSeta(Vector&p);//求出两个向量之间的夹角
	Vector rotateByAxis(float angle,int type);//type=0-绕x轴，type=1-绕y轴，type=2-z轴，比如绕z轴旋转(逆)angle=10°
	Vector lerp(Vector&Vend,float t);//线性插值
	void lerp(Vector&Vend,int n,float*t,Vector*Result);//线性插值
	Euler ToEuler();//向量转欧拉角
};

