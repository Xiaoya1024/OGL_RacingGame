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
	operator float*(){return &m00;}//状态转换
	void Set(float *p);
	void Set(const Matrix&p);

	Matrix& operator=(const Matrix&p);//矩阵赋值
	Matrix operator*(float d);//矩阵数乘
	Matrix operator*(Matrix&p);//矩阵相乘
	Matrix operator/(float p);//矩阵数除
	Matrix operator+(Matrix&p);//矩阵相加
	Matrix operator-(Matrix&p);//矩阵相减
	Matrix operator-();//求相反数
	bool operator==(Matrix&p);//判断两矩阵是否相等
	bool operator!=(Matrix&p);

	Vector MulPosition(Vector& p);//矩阵乘以空间位置得到一个位置，w默认为1，结果不除w，与*不同。
	Vector MulVector(Vector& p);//矩阵乘以空间一个向量，w为0
	Matrix& SetRotate(float seta,Vector&axis);//矩阵绕任意轴旋转
	Matrix& SetRotateByAxis(float seta,int axis);//按x，y，z轴旋转，0表示x轴旋转，1表示y轴，2表示z轴
	Matrix& SetTrans(Vector&trans);//矩阵设置位移
	Matrix& SetScale(Vector&p);//矩阵设置缩放
	float Determinant();//求矩阵的行列式
	Matrix Adjoint();//求四阶矩阵的伴随矩阵
	float Inverse();//矩阵求逆，成功返回行列式的值，否则返回0
	Matrix GetInverse();//返回逆矩阵

	Euler ToEuler();//矩阵转化为欧拉角
	Quaternion ToQuaternion();//矩阵转化为四元数
};

