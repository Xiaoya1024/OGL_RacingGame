#pragma once
#include <gl/glaux.h>
#include <GL/glut.h>
#pragma comment(lib,"glaux.lib ")

class Sky{
public:
	float x,y,z;//���� Ĭ��0
	float r;//�뾶
	float seta;//��ת�Ƕ�

	GLUquadricObj *qobj;
	GLuint T;
	//��ʼ��
	Sky();
	bool InitSky(char* path);
	void Show(float skyX,float skyY,float skyZ,float skyR);
};