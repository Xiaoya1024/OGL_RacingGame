#pragma once
#include <gl/glut.h>
#include "Car.h"
#include "Matrix.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);
	int angleX;
	int angleY;
	int sensitivity;
	void update(Car);
private:
	float distance;
};

