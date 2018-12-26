#include <stdio.h>
#include "Road.h"

const float Pi = 3.14159265358979323846;
float linewidth = 1;

const int POINTNUM=425;
Road point[POINTNUM];

///////////////////////////rrr
void Setpos(float size)//设置路线
{
	int i=0;
	float x=0,y=0,z=0;
	float width=20;
	for(i=0;z<100;z++)//直道(0,0,0)->(0,0,100) 
	{
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	printf("%d\n",i);
	for(float angle=0;angle<Pi/2;angle+=Pi/180)//90度右转(0,0,100)->(50,0,150)
	{
		x=50-50*cos(angle);
		z=100+50*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	printf("%d\n",i);
	for(float angle=0;angle<Pi/2;angle+=Pi/180)//90度左转(50,0,150)->(80,0,200)
	{
		x=50+30*sin(angle);
		z=200-50*cos(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	printf("%d\n",i);
	for(x=80,z=200;z<300;z++)//菱形车道(80,0,200)->(80,0,300)
	{
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	printf("%d\n",i);
	for(float angle=0;angle<Pi/4;angle+=Pi/180)//45度左转(80,0,300)->(50+15*√2,0,300+15*√2)
	{
		x=50+30*cos(angle);
		z=300+30*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	printf("%d\n",i);
	/*for(float angle;angle<Pi/4;angle+=Pi/180)//90度右转(50+15*√2,0,300+15*√2)->()
	{
		x=
	}*/
}
void Set_all_boundary(int begin,int end)//传入起点和终点的点序号
{
	for(int i=begin;i<end-1;i++)
	{
		Vector road_dir(point[i+1].pos-point[i].pos);
		point[i].Setboundary(road_dir);
	}
	Vector road_dir(point[end-1].pos-point[end-2].pos);
	point[end-1].Setboundary(road_dir);
}
void Road::Setboundary(Vector dir)//设置边界
{
	Vector temp;
	dir.normalize();
	Matrix Rotate;
	Rotate.SetRotate(90,Vector (0,1,0));
	temp=Rotate.MulVector(dir);
	temp.normalize();
	this->left=temp * size + pos;
	this->right=temp * -size + pos;
}
void Set_Road()
{
	Setpos(1.0f);
	Set_all_boundary(0,POINTNUM);
}