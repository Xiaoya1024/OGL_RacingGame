#pragma once
class Vector;
class Euler;
class Quaternion;
class Matrix
{
public:
	Matrix(void);
	Matrix(float*p);
	Matrix(const Matrix&p);

	float m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33;
	operator float*(){return &m00;}//״̬ת��
	void Set(float *p);
	void Set(const Matrix&p);

	Matrix& operator=(const Matrix&p);//����ֵ
	Matrix operator*(float d);//��������
	Matrix operator*(Matrix&p);//�������
	Matrix operator/(float p);//��������
	Matrix operator+(Matrix&p);//�������
	Matrix operator-(Matrix&p);//�������
	Matrix operator-();//���෴��
	bool operator==(Matrix&p);//�ж��������Ƿ����
	bool operator!=(Matrix&p);

	Vector MulPosition(Vector& p);//������Կռ�λ�õõ�һ��λ�ã�wĬ��Ϊ1���������w����*��ͬ��
	Vector MulVector(Vector& p);//������Կռ�һ��������wΪ0
	Matrix& SetRotate(float seta,Vector&axis);//��������������ת
	Matrix& SetRotateByAxis(float seta,int axis);//��x��y��z����ת��0��ʾx����ת��1��ʾy�ᣬ2��ʾz��
	Matrix& SetTrans(Vector&trans);//��������λ��
	Matrix& SetScale(Vector&p);//������������
	float Determinant();//����������ʽ
	Matrix Adjoint();//���Ľ׾���İ������
	float Inverse();//�������棬�ɹ���������ʽ��ֵ�����򷵻�0
	Matrix GetInverse();//���������

	Euler ToEuler();//����ת��Ϊŷ����
	Quaternion ToQuaternion();//����ת��Ϊ��Ԫ��
};

