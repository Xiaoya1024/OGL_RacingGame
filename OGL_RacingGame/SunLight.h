
#pragma once
#include "stdafx.h"
#include <GL/glut.h>
#include <gl/glaux.h>
#pragma comment(lib,"glaux.lib ")

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
	
	//̫������
	GLuint T;

	SunLight(float x,float y,float z);//��ķ���

	bool SetUp();
	void Start(float x,float y,float z,float size);//̫��λ��
	void Stop();
};
