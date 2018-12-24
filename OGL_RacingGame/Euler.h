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

	float h,p,b;//��ʾ���ǽǶȶ����ǻ���
	operator float*(){return &h;}
	void Set(float h,float p,float b);
	void Set(const Euler&n);
	

	Vector ToVector3(Vector*updir=0);//ת��Ϊ����
	Matrix ToMatrix();//ת��Ϊ����
	Quaternion ToQuaternion();//ת��Ϊ��Ԫ��

	void normalize();
	Euler GetNormalize();
};

