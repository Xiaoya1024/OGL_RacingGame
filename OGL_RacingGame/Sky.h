#pragma once
#include <gl/glaux.h>
#include <GL/glut.h>
#pragma comment(lib,"glaux.lib ")

class Sky{
public:
	float x,y,z;//球心 默认0
	float r;//半径
	float seta;//旋转角度

	GLUquadricObj *qobj;
	GLuint T;
	//初始化
	Sky();
	bool InitSky(char* path);
	void Show(float skyX,float skyY,float skyZ,float skyR);
};