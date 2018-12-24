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

	void SetAngle(float angle,Vector axis);//��Ԫ������
	void GetAngle(float&angle,Vector&axis);//����ת��ͽǶ�
	Quaternion& operator=(const Quaternion&p);//���ظ�ֵ
	Quaternion operator+(const Quaternion&p);//���ء�+��
	Quaternion operator*(float data);//��������
	Quaternion operator*(const Quaternion&p);//��Ԫ���˷�
	Quaternion operator-(const Quaternion&p);//��Ԫ�����
	Quaternion operator-();//���෴��

	float dotMul(const Quaternion&p);//���
	float len();//��ģ

	bool canNormalize();//�Ƿ���Ա�׼��
	void normalize();//���׼�����ı�����
	Quaternion getNormalize();//���׼����������ı����������µ���Ԫ��

	Quaternion& Inverse();//������Ԫ������ı�����
	Quaternion GetInverse();//������Ԫ�������ı����������µ���Ԫ��
	Quaternion Div(const Quaternion&b);//����ǰΪa����c=a-b
	Quaternion Slerp(Quaternion&Vend,float t);//��ֵ���ӵ�ǰ��Ԫ����ֵ��Vend��Ԫ����t�ǲ���[0,1]
	void Slerp(Quaternion&Vend,int n,float*t,Quaternion *Result);//��ֵ��һ�β�ֵ��n�����ݣ���ֵ��������������t�У�������ص�����Result�С�
	
	Euler ToEuler();
	Matrix ToMatrix();
};

