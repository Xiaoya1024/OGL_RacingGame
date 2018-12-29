#include "Car.h"
#include "Curve.h"
#include "Matrix.h"
#include "gl\glut.h"
Car::Car(void){
	position.Set(0,0,0);
	scale.Set(1,1,1);
	rotate=0;
	speed=0;
	initCar();
	carDir.Set(0,0,1);
	fragment=40;
	isSlerp=false;
	autoCompute();
	carPosNum=0;
	fragmentLen=road.point_number/fragment;//片段长度
	roadLine.pointList.clear();
	roadSize=road.point[0].size;
	for(int i=0;i<=road.point_number;i++){//??????
		roadLine.pointList.push_back(road.point[i].pos);
		roadRight.pointList.push_back(road.point[i].right);
		roadLeft.pointList.push_back(road.point[i].left);
	}
}
Car::Car(int carID)
{
	this->carID=carID;
	position.Set(0,0,0);
	scale.Set(1,1,1);
	rotate=0;
	speed=0;
	initCar();
	carDir.Set(0,0,1);
	fragment=40;
	isSlerp=false;
	autoCompute();
	carPosNum=0;
	fragmentLen=road.point_number/fragment;//片段长度
	roadLine.pointList.clear();
	roadSize=road.point[0].size;
	for(int i=0;i<=road.point_number;i++)//??????
		roadLine.pointList.push_back(road.point[i].pos);
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
	glColor3f(0.90,0.81,0.64);	
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
	//	glColor3f(0,0,1);
	glVertex3f(20,10,-40);//E
	glVertex3f(-20,10,-40);//H
	glVertex3f(-30,25,40);//G
	glVertex3f(30,25,40);//F
	glEnd();

	//车后
	glBegin(GL_POLYGON);
	//	glColor3f(1,0,0);
	glVertex3f(30,0,40);//B
	glVertex3f(-30,0,40);//C
	glVertex3f(-30,25,40);//G
	glVertex3f(30,25,40);//F
	glEnd();

	//车尾支架
	//	glColor3f(1,1,1);
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
	if(view==GODVIEW)//上帝视角
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//实体视角
	else if(view==DRIVEVIEW)
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//透视视角
	//前右车轮
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(22.5f,0,-20);
	glRotatef(90,0,1,0);
	glutSolidTorus(4,8,3,50);
	glPopMatrix();

	//后右车轮
	glPushMatrix();
	glTranslatef(27.5f,0,20);
	glRotatef(90,0,1,0);
	glColor3f(0,0,0);
	glutSolidTorus(4,8,3,50);

	glPopMatrix();
	//后右
	glPushMatrix();
	glTranslatef(-22.5f,0,-20);
	glRotatef(90,0,1,0);
	glColor3f(0,0,1);
	glutSolidTorus(4,8,3,50);

	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(-27.5f,0,20);
	glRotatef(90,0,1,0);
	glutSolidTorus(4,8,3,50);

	glPopMatrix();

}
void Car::initCar(){
	glPushMatrix();
	glScalef(0.05,0.05,0.05);
	glRotatef(180,0,1,0);

	initWheel();
	initBody();

	glPopMatrix();
}
void Car::carTransform(){
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glRotatef(rotate,0,1,0);
	initCar();
	glPopMatrix();
	autoCompute();
}
Vector Car::isIntersectToCar(Car car,bool&isCollision){
	Curve carLine;
	Vector vec;
	for(int i=0;i<4;i++){
		carLine.pointList.push_back(car.carPoint[i]);
	}
	carLine.pointList.push_back(car.carPoint[0]);
	for(int i=0;i<4;i++){
		if(carLine.isInsideLine(carPoint[i],1)){//判断当前小车的点是不是在另一个小车内部
			vec.Set(position-car.position);
			vec.y=0;
			vec.normalize();
			//std::cout<<"撞车了"<<std::endl;
			return vec;
		}
	}
	vec.Set(0,0,0);
	return vec;
}
Vector Car::isIntersectToBlock(bool&isCollision){
	Curve blockLine;
	Vector vec;
	for(int i=0;i<block.obs_number;i++){
		for(int j=0;j<4;j++){
			blockLine.pointList.push_back(block.obs_point[i].point[j]);
		}
		blockLine.pointList.push_back(block.obs_point[i].point[0]);
		for(int j=0;j<4;j++){
			if(blockLine.isInsideLine(carPoint[j],1)){
				//	std::cout<<"撞石头了"<<std::endl;
				vec.Set(position-block.obs_point[i].center);
				vec.y=0;
				vec.normalize();
				return vec;
			}
		}
	}
	vec.Set(0,0,0);
	return vec;
}
Vector Car::isIntersectToRoad(bool&isCollision){
	//Curve roadLeft,roadRight;
	Vector vec;
	bool flag=false;
	
	int begin;//=num*fragmentLen;//开始
	int end;//=(num+1)*fragmentLen;//结束
	cout<<"num:"<<carPosNum<<endl;
	//cout<<"begin:"<<begin<<" "<<"end:"<<end<<endl;
	if(carPosNum==0)
		begin=0;
	else
		begin=(carPosNum-1)*fragmentLen;
	end=(carPosNum+2)*fragmentLen;

	
	for(int i=0;i<4;i++){
		if(roadLine.pointToLineDistance(carPoint[i],1)>=roadSize){//说明撞到路了
			cout<<"撞路上了"<<endl;
		//	Vector point1,point2;
		//	float left=roadLeft.pointToLineDistance(carPoint[i],1,point1);
			//float right=roadRight.pointToLineDistance(carPoint[i],1,point2);
			//vec=left<right?point1:point2;
			//if(i==0){
				vec=position-carPoint[i];
		//	}
			//else if(i==1){
				
			//}
			isCollision=true;
			return vec;
		}
	}

	vec.Set(0,0,0);
	isCollision=false;
	return vec;
}
void Car::AIControl(Car opeCar,Car *npcCar){
//	if(!isSlerp){
//		carDir.normalize();
////		Vector vecRoad=isIntersectToRoad();
//	//	Vector vecBlock=isIntersectToBlock();
//		Vector vecCar(0,0,0);
//		for(int i=0;i<carNum;i++){
//			if(npcCar[i].carID==this->carID)continue;
//			//vecCar=vecCar+isIntersectToCar(npcCar[i]);
//		}
//		Vector vec=vecBlock+vecRoad+vecCar+carDir;
//		if(!vec.canNormalize())//向量合成为0
//			vec.Set(0,0,1);
//		else{
//			vec.y=0;
//			vec.normalize();//这是小车最终方向
//		}
//		//if(angle>10){//插值操作
//		//	
//		//}
//		//position+=speed*carDir;
//	}
//	else{
//
//	}
}
void Car::carPrint(){
	//std::cout<<"0："<<carPoint[0].x<<" "<<carPoint[0].z<<std::endl;
	//std::cout<<"1："<<carPoint[1].x<<" "<<carPoint[1].z<<std::endl;
	//std::cout<<"2："<<carPoint[2].x<<" "<<carPoint[2].z<<std::endl;
	//std::cout<<"3："<<carPoint[3].x<<" "<<carPoint[3].z<<std::endl;
	//cout<<"车的位置："<<position.x<<" "<<position.z<<endl;

	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex3f(carPoint[0].x,carPoint[0].y,carPoint[0].z);
	glVertex3f(carPoint[1].x,carPoint[1].y,carPoint[1].z);
	glVertex3f(carPoint[2].x,carPoint[2].y,carPoint[2].z);
	glVertex3f(carPoint[3].x,carPoint[3].y,carPoint[3].z);
	glEnd();
}

void Car::opCar(int type,Vector vec){
	if(type==0){//说明撞在了路上
		cout<<"撞路上了"<<endl;
		cout<<vec.x<<" "<<vec.z<<endl;
		vec.normalize();
		//carDir.normalize();
		Vector dir=vec;
		position.Set(position+dir*speed);
	}
	else if(type==1){//说明撞在了车上
		cout<<"撞车了"<<endl;
	}
	else if(type==2){//说明撞在了障碍物上
		cout<<"撞石头了"<<endl;
	}
}