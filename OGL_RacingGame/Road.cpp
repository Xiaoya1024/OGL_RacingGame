#include <stdio.h>
#include "Road.h"
#include "MathHelper.h"
#include <GL/glut.h>

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
	for(float angle=0;angle<PI/2;angle+=Radian)//90度右转(0,0,100)->(50,0,150)
	{
		x=50-50*cos(angle);
		z=100+50*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	for(float angle=0;angle<PI/2;angle+=Radian)//90度左转(50,0,150)->(80,0,200)
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
	for(float angle=0;angle<PI/4;angle+=Radian)//45度左转(80,0,300)->(50+15*√2,0,300+15*√2)
	{
		x=50+30*cos(angle);
		z=300+30*sin(angle);
		point[i].pos.Set(x*size,y*size,z*size);
		point[i].size=width*size;
		i++;
	}
	/*for(float angle;angle<PI/4;angle+=Radian)//90度右转(50+15*√2,0,300+15*√2)->()
	{
		x=
	}*/
	this->point_number=i;
	printf("%d\n",point_number);
}
void Road::Set_all_boundary()
{
	for(int i=0;i<point_number-1;i++)
	{
		Vector road_dir(point[i+1].pos-point[i].pos);
		point[i].Setboundary(road_dir);
	}
	printf("%d\n",point_number);
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
	this->left=temp * -size + pos;
	this->right=temp * size + pos;
}
void Road::initRoad()//设置路面
{
	for(int i=0;i<point_number-1;i++)
	{
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
		glVertex3f(point[i].left.x,point[i].left.y,point[i].left.z);
		glVertex3f(point[i+1].left.x,point[i+1].left.y,point[i+1].left.z);
		glVertex3f(point[i+1].right.x,point[i+1].right.y,point[i+1].right.z);
		glVertex3f(point[i].right.x,point[i].right.y,point[i].right.z);
		glEnd();
	}
}
void Obs::Setobs(float obs_size,float angle,Vector pos)//设置障碍,angle是角度
{
	Vector temp(0,0,1);
	Matrix Rotate; 
	Rotate.SetRotate(angle,Vector (0,1,0));
	temp=Rotate.MulVector(temp);
	Rotate.SetRotate(90,Vector (0,1,0));
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			Vector high(0,10,0);
			point[4*i+j]=pos + temp*obs_size + high*(float)i;
			temp=Rotate.MulVector(temp);
		}
	}
}
void All_obs::Set_all_obs()

{
	int i=0;
	float x=0,y=0,z=0;
	float angle=(float)(rand()%90);
	obs_point[i].Setobs(4,angle,Vector(0,0,50));
	i++;
	this->obs_number=i;
}
void Obs::initObs()//构造障碍物的面
{
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	for(int i=0;i<4;i++)//底面
		glVertex3f(point[i].x,point[i].y,point[i].z);
	glEnd();
	glBegin(GL_QUADS);
	for(int i=4;i<8;i++)//顶面
		glVertex3f(point[i].x,point[i].y,point[i].z);
	glEnd();
	for(int i=0;i<4;i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(point[0+i].x,point[0+i].y,point[0+i].z);
		glVertex3f(point[1+i].x,point[1+i].y,point[1+i].z);
		glVertex3f(point[5+i].x,point[5+i].y,point[5+i].z);
		glVertex3f(point[4+i].x,point[4+i].y,point[4+i].z);
		glEnd();
	}
}
void All_obs::All_initObs()
{
	for(int i=0;i<obs_number;i++)
	{
		obs_point[i].initObs();
	}
}