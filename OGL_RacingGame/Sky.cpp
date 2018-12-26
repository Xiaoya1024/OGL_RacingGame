#include "stdafx.h"
#include "Sky.h"

Sky::Sky(){
	x=0;
	y=0;
	z=0;
	r=200;
	seta=0;
}
bool Sky::InitSky(float skyX,float skyY,float skyZ,float skyR, char *path){
	x=skyX;
	y=skyY;
	z=skyZ;
	r=skyR;
	
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj,GLU_SMOOTH);
	gluQuadricTexture(qobj,GL_TRUE);

	AUX_RGBImageRec *TextureImage=0;					
	if ((TextureImage=auxDIBImageLoad(path))!=NULL)
	{
		glGenTextures(1, &T);					
		glBindTexture(GL_TEXTURE_2D, T);
		// Generate The Texture
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
		
		if (TextureImage->data)					
		return true;
	}
	return false;
}
void Sky::Show(){
	seta+=0.1;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glBindTexture(GL_TEXTURE_2D, T);
	glTranslatef(x,y,z); 
	glRotatef(seta,0.0f,1.0f,0.0f); //天空慢慢旋转,模拟云流动
	glRotatef(90,1,0,0);
	glColor4f(1,1,1,1);
	gluSphere(qobj,r,32,32);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}