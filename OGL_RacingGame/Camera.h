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
	int mode;	//0代表小车第一视角，1代表上帝视角
	void update(Car);
	void turnGodView(void);
	void turnCarView(void);
};

