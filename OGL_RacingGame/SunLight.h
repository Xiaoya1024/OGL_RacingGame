
#pragma once
#include "stdafx.h"
#include <GL/glut.h>
#include <gl/glaux.h>
#pragma comment(lib,"glaux.lib ")

class SunLight
{
public:
	//环境光(Ambient Light)
	GLfloat amb[4];
	//漫射光(Diffuse Light)
	GLfloat dif[4];
	//镜面反射
	GLfloat spe[4];
	//位置/方向 
	GLfloat pos[4];
	
	//太阳纹理
	GLuint T;

	SunLight(float x,float y,float z);//光的方向

	bool SetUp();
	void Start(float x,float y,float z,float size);//太阳位置
	void Stop();
};
