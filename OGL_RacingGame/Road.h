#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"

const int MAX=10000;
const int OBSNUM=100;

class Road_Point
{
public:
	Vector pos;//�е��λ��
	float size;//�ߴ�
	Vector left;//��߽߱��
	Vector right;//�ұ߽߱��

	
	void Setboundary(Vector dir);//���ñ߽�
};
class Road
{
public:
	Road_Point point[MAX];
	int point_number;//ʹ�õĵ�ĸ���
	Road ()
	{
		Setpos(1.0f);
		Set_all_boundary();
	}
	void initRoad();//����·��
private:
	void Set_all_boundary();//�������б߽�
	void Setpos(float size=1.0f);//���õ�

};
class Obs//�ϰ���
{
public:
	Vector point[8];
	void Setobs(float obs_size,float angle=0.0f,Vector pos=Vector(0,0,1));//�����ϰ�
	void initObs();//�����ϰ������
};
class All_obs//�����ϰ���
{
public: 
	Obs obs_point[OBSNUM];
	int obs_number;
	All_obs()
	{
		Set_all_obs();
	}
	void All_initObs();
private:
	void Set_all_obs();
};
