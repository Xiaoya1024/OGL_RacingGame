#pragma once
#include "stdafx.h"
#include <gl/glaux.h>
#include <GL/glut.h>

class Sky{
public:
	float x,y,z;//���� Ĭ��0
	float r;//�뾶
	float seta;//��ת�Ƕ�

	GLUquadricObj *qobj;
	GLuint T;
	//��ʼ��
	Sky();
	bool InitSky(float skyX,float skyY,float skyZ,float skyR, char *path);
	void Show();
};