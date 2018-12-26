#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"

const int MAX=10000;

class Road_Point
{
public:
	Vector pos;//中点的位置
	float size;//尺寸
	Vector left;//左边障碍
	Vector right;//右边障碍
	void Setobs(float obs_size,Vector dir=Vector(0,0,1));//设置障碍
	void Setboundary(Vector dir);//设置边界
};
class Road
{
public:
	Road_Point point[MAX];
	int point_number;//使用的点的个数
	void Set_all_boundary();//设置所有边界
	void Setpos(float size);//设置点
	void initRoad();//构造路面
};


