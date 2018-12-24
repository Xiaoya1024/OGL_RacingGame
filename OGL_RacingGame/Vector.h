#pragma once
class Euler;
class Vector
{
public:
	Vector();
	Vector(float x,float y,float z);
	Vector(const Vector &p);

	float x;//���Ա
	float y;
	float z;
	void Set(float x,float y,float z);
	void Set(const Vector&p);
	operator float*(){return &x;}

	Vector operator+(Vector &p);//���ء�+������
	Vector operator-(Vector &p);//���ء�-������
	Vector operator*(float p);//���ء�*������
	Vector& operator=(Vector &p);//���ء�=������
	Vector operator-();//���෴��
	bool operator==(Vector &p);//���ء�==������
	bool operator!=(Vector &p);//���ء�!=������

	float dotMul(Vector &n);//������˲���
	Vector crossMul(Vector &n);//������˲���
	float len();//������ģ����
	bool canNormalize();//�Ƿ���Ա�׼��
	void normalize();//������׼������
	Vector getNormalize();//��ȡ������׼�����
	Vector project(Vector &n);//����ͶӰ����
	
	float findSeta(Vector&p);//�����������֮��ļн�
	Vector rotateByAxis(float angle,int type);//type=0-��x�ᣬtype=1-��y�ᣬtype=2-z�ᣬ������z����ת(��)angle=10��
	Vector lerp(Vector&Vend,float t);//���Բ�ֵ
	void lerp(Vector&Vend,int n,float*t,Vector*Result);//���Բ�ֵ
	Euler ToEuler();//����תŷ����
};

