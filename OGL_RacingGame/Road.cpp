#include <stdio.h>
#include "Road.h"
#include <GL/glut.h>

const float Pi = 3.14159265358979323846;
float linewidth = 1;

///////////////////////////
void Road::Setpos(float size)//设置路线
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
	for(float angle=0;angle<Pi/2;angle+=Pi/180)//90度右转(0,0,100)->(50,0,150)
	{
		x=50-50*cos(angle);
		z=100+50*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	for(float angle=0;angle<Pi/2;angle+=Pi/180)//90度左转(50,0,150)->(80,0,200)
	{
		x=50+30*sin(angle);
		z=200-50*cos(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	for(x=80,z=200;z<300;z++)//菱形车道(80,0,200)->(80,0,300)
	{
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	for(float angle=0;angle<Pi/4;angle+=Pi/180)//45度左转(80,0,300)->(50+15*√2,0,300+15*√2)
	{
		x=50+30*cos(angle);
		z=300+30*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	/*for(float angle;angle<Pi/4;angle+=Pi/180)//90度右转(50+15*√2,0,300+15*√2)->()
	{
		x=
	}*/
	point_number=i;
}
void Road::Set_all_boundary()
{
	for(int i=0;i<point_number-1;i++)
	{
		Vector road_dir(point[i+1].pos-point[i].pos);
		point[i].Setboundary(road_dir);
	}
	Vector road_dir(point[point_number-1].pos-point[point_number-2].pos);
	point[point_number-1].Setboundary(road_dir);
}
void Road_Point::Setboundary(Vector dir)//设置边界
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
void Road::initRoad()//设置路面
{
	for(int i=0;i<point_number;i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(point[i].left.x,point[i].left.y,point[i].left.z);
		glVertex3f(point[i+1].left.x,point[i+1].left.y,point[i+1].left.z);
		glVertex3f(point[i+1].right.x,point[i+1].right.y,point[i+1].right.z);
		glVertex3f(point[i].right.x,point[i].right.y,point[i].right.z);
		glEnd();
	}
}