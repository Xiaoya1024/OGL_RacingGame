
#pragma once
#include "stdafx.h"
#include <GL/glut.h>

class SunLight
{
public:
	//������(Ambient Light)
	GLfloat amb[4];
	//�����(Diffuse Light)
	GLfloat dif[4];
	//���淴��
	GLfloat spe[4];
	//λ��/���� 
	GLfloat pos[4];
	
	//̫����С
	GLfloat size;
	//̫����ɫ
	GLfloat r,g,b;

	SunLight();

	void SetUp();
	void Start();
	void Stop();
};
