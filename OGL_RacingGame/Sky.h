#pragma once
#include "stdafx.h"
#include <gl/glaux.h>
#include <GL/glut.h>
#pragma comment(lib,"glaux.lib ")


//用法
/*
初始化函数中 InitSky();
display中 show
*/
class Sky{
public:
	//float seta;//旋转角度
	GLuint T[6];
	//初始化
	Sky();
	bool InitSky();
	//坐标
	void Show(float x,float y,float z);
};