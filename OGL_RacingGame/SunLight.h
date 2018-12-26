
#pragma once
#include "stdafx.h"
#include <GL/glut.h>

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
	
	//太阳大小
	GLfloat size;
	//太阳颜色
	GLfloat r,g,b;

	SunLight();

	void SetUp();
	void Start();
	void Stop();
};
