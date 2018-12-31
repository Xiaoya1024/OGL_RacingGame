#include "stdafx.h"
#include "SunLight.h"


SunLight::SunLight(float x,float y,float z){
	amb[0]=0.5;
	amb[1]=0.5;
	amb[2]=0.5;
	amb[3]=0.5;
	dif[0]=0.5;
	dif[1]=0.5;
	dif[2]=0.5;
	dif[3]=1;
	spe[0]=1;
	spe[1]=1;
	spe[2]=1;
	spe[3]=1;
	
	pos[0]=x;
	pos[1]=y;
	pos[2]=z;
	pos[3]=0;//Æ½ÐÐ¹â
}

bool SunLight::SetUp(){
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
	glLightfv(GL_LIGHT0,GL_SPECULAR,spe);
	glEnable( GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glGenTextures(1, &T);	
	AUX_RGBImageRec *TextureImage=0;		
	if ((TextureImage=auxDIBImageLoad("sun.bmp"))!=NULL)
	{
		glBindTexture(GL_TEXTURE_2D, T);
		// Generate The Texture
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
		if (!TextureImage->data)					
			return false;
	}
	return true;
}
void SunLight::Start(float x,float y,float z,float size){
	
	
	glPushMatrix();
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glPopMatrix();

	glPushMatrix();

	glFrontFace(GL_CW);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, T);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTranslatef(x,y,z);
	glutSolidSphere(size,50,50);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glFrontFace(GL_CCW);

	glPopMatrix();
}

void SunLight::Stop(){
	glDisable(GL_LIGHTING);
}
