#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"

const int MAX=10000;
const int OBSNUM=100;

class Road_Point
{
public:
	Vector pos;//中点的位置
	float size;//尺寸
	Vector left;//左边边界点
	Vector right;//右边边界点

	
	void Setboundary(Vector dir);//设置边界
};
class Road
{
public:
	Road_Point point[MAX];
	int point_number;//使用的点的个数
	Road ()
	{
		Setpos(1.0f);
		Set_all_boundary();
	}
	void initRoad();//构造路面
private:
	void Set_all_boundary();//设置所有边界
	void Setpos(float size=1.0f);//设置点

};
class Obs//障碍物
{
public:
	Vector point[8];
	void Setobs(float obs_size,float angle=0.0f,Vector pos=Vector(0,0,1));//设置障碍
	void initObs();//构造障碍物的面
};
class All_obs//所有障碍物
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
