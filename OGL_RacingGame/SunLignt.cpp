#include "stdafx.h"
#include "SunLight.h"


SunLight::SunLight(){
	amb[0]=0.2;
	amb[1]=0.2;
	amb[2]=0.2;
	amb[3]=1;
	dif[0]=0.5;
	dif[1]=0.5;
	dif[2]=0.5;
	dif[3]=1;
	spe[0]=1;
	spe[1]=1;
	spe[2]=1;
	spe[3]=1;
	
	pos[0]=0;
	pos[1]=0;
	pos[2]=10;
	pos[3]=0;//Æ½ÐÐ¹â

	size=2;
	r=1;
	g=1;
	b=0;
}

void SunLight::SetUp(){
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
	glLightfv(GL_LIGHT0,GL_SPECULAR,spe);
	glEnable( GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void SunLight::Start(){
	glPushMatrix();
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glTranslatef(pos[0],pos[1],pos[2]);
	glColor3f(r,g,b);	
	glutSolidSphere(size,100,100);
	glPopMatrix();
	
	
}
void SunLight::Stop(){
	glDisable(GL_LIGHTING);
}
