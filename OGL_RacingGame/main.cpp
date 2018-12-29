#include <iostream>
#include "Camera.h"
#include "Car.h"
#include "Curve.h"
#include "Road.h"
#include "gl/glut.h"
Road road;
All_obs block;
Car car(0);//玩家操纵的小车
Car*npcCar=new Car[carNum];
Camera camera;
int old_x,old_y;

void myDisplay();
void myTimerFunc(int val);
void myReshape(int w,int h);
void myKeyboardFunc(unsigned char key,int x, int y);
void mySpecialFunc(int key,int x,int y);
void SetRC();
void CarDisplay();
void mouse(int button, int state, int x, int y);
void onMouseMove(int x, int y) ;

int main(int argc,char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OSG_RacingGame");
	glutDisplayFunc(&myDisplay);
	glutTimerFunc(1,myTimerFunc,1);
	glutReshapeFunc(&myReshape);
	glutKeyboardFunc(&myKeyboardFunc);
	glutSpecialFunc(&mySpecialFunc);
	glutMouseFunc(&mouse);
	glutMotionFunc(&onMouseMove);
	SetRC();
	glutMainLoop();
	return 0;
}
void myDisplay(){
	glClearColor(0.8,0.8,0.8, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	camera.update(car);
	road.initRoad();
	block.All_initObs();
	CarDisplay();
	glPopMatrix();
	glutSwapBuffers();
}
void CarDisplay(){
	//测试
	glPushMatrix();
	glTranslatef(15,0,20);
	npcCar[0].SetPosition(15,0,20);
	npcCar[0].SetCarDir(0,0,1);
	npcCar[0].initCar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15,0,20);
	npcCar[1].SetPosition(-15,0,20);
	npcCar[1].SetCarDir(0,0,1);
	npcCar[1].initCar();
	glPopMatrix();
	npcCar[0].carPrint();

	Vector vec;
	bool isCollision=false;
	car.carPosNum=int(car.getPosition().z/car.fragmentLen);//在第num个片段
	vec=car.isIntersectToRoad(isCollision);
	if(isCollision)car.opCar(0,vec);
	//for(int i=0;i<carNum;i++){
	//	vec=car.isIntersectToCar(npcCar[i]);
	//	if(vec.canNormalize()){
	//		car.opCar(1,vec);
	//		//isCollision=true;
	//	}
	//}
	//vec=car.isIntersectToBlock();
	//if(vec.canNormalize()){
	//	car.opCar(2,vec);
	//	//isCollision=true;
	//}
	if(!isCollision)
		car.SetPosition(car.getCarDir()*car.speed+car.getPosition());
	car.carTransform();
	car.carPrint();
	//cout<<"************************未发生碰撞***************************"<<endl;
}
void myTimerFunc(int val){

	myDisplay();
	glutTimerFunc(1,myTimerFunc,1);
}
void myReshape(int w,int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,GLfloat(w)/h,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myKeyboardFunc(unsigned char key,int x, int y){
	switch(key){
	case ' ':
		if(car.view==GODVIEW)
			car.view=DRIVEVIEW;
		else
			car.view=GODVIEW;
		break;
	}
}
void mySpecialFunc(int key,int x,int y){
	switch(key){
	case GLUT_KEY_LEFT://左箭头
		car.SetRotate(car.getRotate()+1);
		car.SetCarDir(car.getCarDir().rotateByAxis(-1,1));
		break;
	case GLUT_KEY_RIGHT://右箭头
		car.SetRotate(car.getRotate()-1);
		car.SetCarDir(car.getCarDir().rotateByAxis(1,1));
		break;
	case GLUT_KEY_UP://上箭头
		car.speed=car.speed+0.1f;
		if(car.speed>2.0f)
			car.speed=2.0f;
		break;
	case GLUT_KEY_DOWN://下箭头
		if(fabs(car.speed)>= 0.1f)
			car.speed=car.speed-0.1f;
		if(car.speed<=FLOAT_EPS)
			car.speed=0;
		break;
	}
}
void SetRC(){
	car.view=GODVIEW;
	for(int i=0;i<carNum;i++){
		npcCar[i].view=GODVIEW;
		npcCar[i].SetCarID(i+1);
	}

	

	//Curve curve;
	//Vector vec;
	//vec.Set(18.5,0,24.5);
	//curve.pointList.push_back(vec);
	//vec.Set(11.5,0,24.5);
	//curve.pointList.push_back(vec);
	//vec.Set(11.5,0,15.5);
	//curve.pointList.push_back(vec);
	//vec.Set(18.5,0,15.5);
	//curve.pointList.push_back(vec);
	//Vector point;
	//point.Set(12,0,16);

	//cout<<curve.isInsideLine(point,1)<<endl;
}
void mouse(int button, int state, int x, int y) {	//鼠标点击的瞬间被执行
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		old_x = x;
		old_y = y;
	}
	//else if(button == GLUT_WHEEL_UP)
}

void onMouseMove(int x, int y) {	//处理鼠标拖动
	if(car.view == GODVIEW) {
		camera.angleY += (x - old_x) / camera.sensitivity;
		camera.angleX += (y - old_y) / camera.sensitivity;
		old_x = x;
		old_y = y;
	}
}
