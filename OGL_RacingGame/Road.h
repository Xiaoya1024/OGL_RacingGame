#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"

const int MAX=10000;

class Road_Point
{
public:
	Vector pos;//�е��λ��
	float size;//�ߴ�
	Vector left;//����ϰ�
	Vector right;//�ұ��ϰ�
	void Setobs(float obs_size,Vector dir=Vector(0,0,1));//�����ϰ�
	void Setboundary(Vector dir);//���ñ߽�
};
class Road
{
public:
	Road_Point point[MAX];
	int point_number;//ʹ�õĵ�ĸ���
	void Set_all_boundary();//�������б߽�
	void Setpos(float size);//���õ�
	void initRoad();//����·��
};


