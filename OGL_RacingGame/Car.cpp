#include "Car.h"
#include "Matrix.h"
#include "gl\glut.h"
Car::Car(void)
{
	position.Set(0,0,0);
	scale.Set(1,1,1);
	rotate.Set(0,0,0);
	speed.Set(0,0,0);
	initCar();
}

Car::~Car(void)
{
	
}
void Car::initBody(){

	if(view==GODVIEW)//上帝视角
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//实体视角
	else if(view==DRIVEVIEW)
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//透视视角
	//绘制的小车车头朝向z轴负方向，关于zoy平面对称
	glScalef(0.2,0.2,0.2);
	glColor3f(1,1,1);	
	//车下半部
	glBegin(GL_POLYGON);
	glVertex3f(20,0,-40);//A
	glVertex3f(30,0,40);//B
	glVertex3f(-30,0,40);//C
	glVertex3f(-20,0,-40);//D
	glEnd();

	//车侧面
	glBegin(GL_POLYGON);
	glVertex3f(20,0,-40);//A
	glVertex3f(30,0,40);//B
	glVertex3f(30,25,40);//F
	glVertex3f(20,10,-40);//E
	glEnd();

	//车侧面
	glBegin(GL_POLYGON);
	glVertex3f(-30,0,40);//C
	glVertex3f(-20,0,-40);//D
	glVertex3f(-20,10,-40);//H
	glVertex3f(-30,25,40);//G
	glEnd();

	//车顶
	glBegin(GL_POLYGON);
	glVertex3f(20,10,-40);//E
	glVertex3f(-20,10,-40);//H
	glVertex3f(-30,25,40);//G
	glVertex3f(30,25,40);//F
	glEnd();

	//车后
	glBegin(GL_POLYGON);
	glVertex3f(30,0,40);//B
	glVertex3f(-30,0,40);//C
	glVertex3f(-30,25,40);//G
	glVertex3f(30,25,40);//F
	glEnd();

	//车尾支架
	glBegin(GL_POLYGON);
	glVertex3f(24,25,40);//1
	glVertex3f(18,25,40);//2
	glVertex3f(18,35,50);//4
	glVertex3f(24,35,50);//3
	glEnd();

	//车尾支架
	glBegin(GL_POLYGON);
	glVertex3f(-24,25,40);//6
	glVertex3f(-18,25,40);//5
	glVertex3f(-18,35,50);//7
	glVertex3f(-24,35,50);//8
	glEnd();

	//车尾支架
	glBegin(GL_POLYGON);
	glVertex3f(24,0,40);//10
	glVertex3f(18,0,40);//9
	glVertex3f(18,35,50);//4
	glVertex3f(24,35,50);//3
	glEnd();

	//车尾支架
	glBegin(GL_POLYGON);
	glVertex3f(-24,0,40);//12
	glVertex3f(-18,0,40);//11
	glVertex3f(-18,35,50);//7
	glVertex3f(-24,35,50);//8
	glEnd();

	//车尾
	glBegin(GL_POLYGON);
	glVertex3f(30,35,50);//13
	glVertex3f(-30,35,50);//14
	glVertex3f(-30,35,60);//16
	glVertex3f(30,35,60);//15
	glEnd();

	//车尾
	glBegin(GL_POLYGON);
	glVertex3f(30,35,50);//13
	glVertex3f(-30,35,50);//14
	glVertex3f(-30,45,60);//18
	glVertex3f(30,45,60);//17
	glEnd();

	//车尾
	glBegin(GL_POLYGON);
	glVertex3f(30,35,60);//15
	glVertex3f(-30,35,60);//16
	glVertex3f(-30,45,60);//18
	glVertex3f(30,45,60);//17
	glEnd();

	//车尾
	glBegin(GL_POLYGON);
	glVertex3f(30,35,60);//15
	glVertex3f(30,45,60);//17
	glVertex3f(30,35,50);//13
	glEnd();

	//车尾
	glBegin(GL_POLYGON);
	glVertex3f(-30,35,50);//14
	glVertex3f(-30,35,60);//16
	glVertex3f(-30,45,60);//18
	glEnd();

}
void Car::initWheel(){

	//前右车轮
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(22.5f,0,-20);
	glRotatef(90,0,1,0);
	glutSolidTorus(2,6,5,100);
	glPopMatrix();

	//后右车轮
	glPushMatrix();
	glTranslatef(27.5f,0,20);
	glRotatef(90,0,1,0);
	glColor3f(0,0,0);
	glutSolidTorus(2,6,5,100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-22.5f,0,-20);
	glRotatef(90,0,1,0);
	glColor3f(0,0,0);
	glutSolidTorus(2,6,5,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(-27.5f,0,20);
	glRotatef(90,0,1,0);
	glutSolidTorus(2,6,5,100);
	glPopMatrix();
	
}
void Car::initCar(){
	initBody();
	initWheel();
}
void Car::pushMatrix(){
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glScalef(scale.x,scale.y,scale.z);
	Matrix mat;//旋转矩阵
	mat=rotate.ToMatrix();
	glMultMatrixf(mat);
	initCar();
}
void Car::popMatrix(){
	glPopMatrix();
}