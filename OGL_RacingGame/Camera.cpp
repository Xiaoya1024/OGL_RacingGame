#include "Camera.h"


Camera::Camera(void)
{
	distance = 10;
	mode = 0;
}


Camera::~Camera(void)
{
}

void Camera::turnGodView(void) {
	mode = 1;
}

void Camera::turnCarView(void) {
	mode = 0;
}

void Camera::update(Car car) {
	if(mode == 0) {
		Matrix model_view;
		float angle;		//摄像机要旋转的角度
		glPushMatrix();
		glLoadIdentity();
		glRotatef(180.0f, 0, 1, 0);
		glTranslatef(car.position.x, car.position.y + 20, car.position.z - car.speed.z * distance);
		glGetFloatv(GL_MODELVIEW_MATRIX, model_view);
		glPopMatrix();
		glLoadMatrixf(model_view);
	}
	else if(mode == 1) {
		gluLookAt(0, 100, 0, 0, 100, 100, 0, 1, 0);
	}
}