#pragma once
#include "stdafx.h"
#include <gl/glaux.h>
#include <GL/glut.h>
#pragma comment(lib,"glaux.lib ")


//�÷�
/*
��ʼ�������� InitSky();
display�� show
*/
class Sky{
public:
	//float seta;//��ת�Ƕ�
	GLuint T[6];
	//��ʼ��
	Sky();
	bool InitSky();
	//����
	void Show(float x,float y,float z);
};