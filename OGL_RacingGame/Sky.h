#pragma once
#include "stdafx.h"
#include <gl/glaux.h>
#include <GL/glut.h>

class Sky{
public:
	float x,y,z;//球心 默认0
	float r;//半径
	float seta;//旋转角度

	GLUquadricObj *qobj;
	GLuint T;
	//初始化
	Sky();
	bool InitSky(float skyX,float skyY,float skyZ,float skyR, char *path);
	void Show();
};