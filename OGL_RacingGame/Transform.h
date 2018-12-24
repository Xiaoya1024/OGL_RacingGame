#pragma once
#include "Vector.h"
#include "Euler.h"
#include "Matrix.h"
class Transform
{
public:
	Transform(void);
	~Transform(void);
	Vector position;//λ��
	Vector scale;//��С
	Euler rotate;//��ת

	//��������ϵ�������λ��
	void setPosition(float x,float y,float z){position.Set(x,y,z);}
	//��������ϵ�������λ��
	void setPosition(const Vector vec){position.Set(vec);}
	//����Ĵ�С
	void setScale(float x,float y,float z){scale.Set(x,y,z);}
	//����Ĵ�С
	void setScale(const Vector vec){scale.Set(vec);}
	//��������������ϵ����ת
	void setRotate(float h,float p,float b){rotate.Set(h,p,b);}
	//��������������ϵ����ת
	void setRotate(const Euler euler){rotate.Set(euler);}
	//���������transform
	void reset();
	//ִ������ı任
	void push();
	//ִ���������Ӧ�ı任
	void push(Matrix&mat);//��ȡ��ǰ����mat
	//ȡ������ı任
	void pop();
};

