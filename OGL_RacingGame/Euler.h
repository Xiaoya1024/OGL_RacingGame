#pragma once
class Vector;
class Matrix;
class Quaternion;
class Euler
{
public:
	Euler(void);
	Euler(float h,float p,float b);
	Euler(const Euler&n);

	float h,p,b;//表示的是角度而不是弧度
	operator float*(){return &h;}
	void Set(float h,float p,float b);
	void Set(const Euler&n);
	

	Vector ToVector3(Vector*updir=0);//转换为向量
	Matrix ToMatrix();//转换为矩阵
	Quaternion ToQuaternion();//转换为四元数

	void normalize();
	Euler GetNormalize();
};

