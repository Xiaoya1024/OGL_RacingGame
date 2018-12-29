#pragma once
#include <gl/glut.h>
#include "Car.h"
#include "Matrix.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);
	float distance;
	int mode;	//0����С����һ�ӽǣ�1�����ϵ��ӽ�
	void update(Car);
	void turnGodView(void);
	void turnCarView(void);
};

