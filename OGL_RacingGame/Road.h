#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"
class Road
{
public:
	Vector pos;//�е��λ��
	float size;//�ߴ�
	Vector left;//����ϰ�
	Vector right;//�ұ��ϰ�
	void Setobs(float obs_size,Vector dir=Vector(0,0,1));//�����ϰ�
	void Setboundary(Vector dir);//���ñ߽�
};
void Setpos(float size);
void Set_all_boundary(int begin,int end);
void Set_Road();