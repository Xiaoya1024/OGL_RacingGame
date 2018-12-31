#include "stdafx.h"
#include "Sky.h"

Sky::Sky(){
	
}
bool Sky::InitSky(){
	char *pic[6]={"./skybox/front.bmp","./skybox/back.bmp","./skybox/top.bmp","./skybox/bottom.bmp","./skybox/right.bmp","./skybox/left.bmp"};
	glGenTextures(6, T);	
	AUX_RGBImageRec *TextureImage=0;		
	int i=0;
	while(i<6){
		if ((TextureImage=auxDIBImageLoad(pic[i]))!=NULL)
		{
			glBindTexture(GL_TEXTURE_2D, T[i]);
			// Generate The Texture
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
			if (!TextureImage->data)					
				return false;
		}
		i++;
	}
	return true;
}
void Sky::Show(float x,float y,float z){
	//seta+=0.1;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//glScalef(500,500,500);
	//glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	
	glTranslatef(x,y,z); 
	//glRotatef(seta,0.0f,1.0f,0.0f); //天空慢慢旋转,模拟云流动
	//glRotatef(90,1,0,0);
	glColor4f(1,1,1,1);

	glBindTexture(GL_TEXTURE_2D, T[1]);
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
	glEnd();

	glBindTexture(GL_TEXTURE_2D, T[0]);
	glBegin(GL_QUADS);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glEnd();

	glBindTexture(GL_TEXTURE_2D, T[2]);
	glBegin(GL_QUADS);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glEnd();

	glBindTexture(GL_TEXTURE_2D, T[3]);
	glPushMatrix();
	glRotatef(180,0,1,0);
	glBegin(GL_QUADS);
	
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, T[4]);
	glBegin(GL_QUADS);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glEnd();

	glBindTexture(GL_TEXTURE_2D, T[5]);
	glBegin(GL_QUADS);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}