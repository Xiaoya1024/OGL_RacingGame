#include "Transform.h"
#include "gl\glut.h"
Transform::Transform(void)
{
	reset();
}
Transform::~Transform(void)
{
}
void Transform::reset(){
	position.Set(0,0,0);
	scale.Set(1,1,1);
	rotate.Set(0,0,0);
}
void Transform::push(){
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glScalef(scale.x,scale.y,scale.z);
	Matrix mat;//Ðý×ª¾ØÕó
	mat=rotate.ToMatrix();
	glMultMatrixf(mat);
}
void Transform::push(Matrix&mat){
	push();
	glGetFloatv(GL_MODELVIEW_MATRIX, mat);
}
void Transform::pop(){
	glPopMatrix();
}