#include "Camera.h"
Camera::Camera(void)
{
	distance = 10;
	sensitivity=2;
}

Camera::~Camera(void)
{
}

void Camera::update(Car car) {
	if(car.view == DRIVEVIEW) {
		Matrix model_view;
		float angle;		//摄像机要旋转的角度
		angle = acos(car.getCarDir().dotMul(Vector(0, 0, 1)) / (car.getCarDir().len() * 1));
		angle = RadianToDegree(angle);
		if(car.getCarDir().crossMul(Vector(0, 0, 1)).y <= 0) {
			angle *= -1;
		}
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, -3, -5);
		glRotatef(180.0f + angle, 0, 1, 0);

		glTranslatef(-car.getPosition().x, -car.getPosition().y, -car.getPosition().z);
		glGetFloatv(GL_MODELVIEW_MATRIX, model_view);
		glPopMatrix();
		glLoadMatrixf(model_view);
	}
	else if(car.view==GODVIEW) {
		Matrix model_view;

		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, -10, -20);
		angleY = angleY % 360;
		if(angleX > 90) {
			angleX = 90;
		}
		if(angleX < 0) {
			angleX = 0;
		}
		glRotatef(angleX, 1, 0, 0);
		glRotatef(180.0f + angleY, 0, 1, 0);
		glTranslatef(-car.getPosition().x, -car.getPosition().y, -car.getPosition().z);
		glGetFloatv(GL_MODELVIEW_MATRIX, model_view);
		glPopMatrix();
		glLoadMatrixf(model_view);
	}

}
