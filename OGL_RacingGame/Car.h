#pragma once
#include "Vector.h"
#include "Road.h"
#include "Curve.h"
#include "MathHelper.h"
#include "Quaternion.h"
#include "gl/glut.h"
const int carNum=2;
enum carType{//����Ӧ��������ͬ��ͼƬ
	npc_car=0,
	blue_car=1,
	green_car=2,
	red_car=3,
};
enum carView{
	DRIVEVIEW=0,//˾���ӽ�
	GODVIEW=1//�ϵ��ӽ�
};
class Car
{
public:
	Car(void);
	Car(int carID);
	~Car(void);
	
	float speed;
	carView view;
	void initBody();//viewΪ0��ʾ�ϵ��ӽǣ�Ϊ1��ʾ˾���ӽǣ�͸�ӣ�
	void initWheel();
	void initCar();

	Vector getPosition(){return position;}
	Vector getCarDir(){return carDir;}
	float getRotate(){return rotate;}
	int getCarID(){return carID;}

	void SetCarID(int id){
		carID=id;
	}
	void SetPosition(float x,float y,float z){
		position.Set(x,y,z);
		autoCompute();
	}
	void SetPosition(const Vector vec){
		position.Set(vec);
		autoCompute();
	}
	void SetRotate(float angle){
		rotate=angle;
		autoCompute();
	}
	void SetCarDir(float x,float y,float z){
		carDir.Set(x,y,z);
		carDir.normalize();
		autoCompute();
	}
	void SetCarDir(const Vector vec){
		carDir.Set(vec);
		carDir.normalize();
		autoCompute();
	}
	void carTransform(); 
	void carPrint();
	Vector isIntersectToCar(Car car,bool&isCollision);
	Vector isIntersectToRoad(bool&isCollision);
	Vector isIntersectToBlock(bool&isCollision);
	void autoCompute(){
		Vector a=carDir.rotateByAxis(RadianToDegree(-atanf((float)7/(float)9)),1)*sqrtf(35*35+45*45)*0.05f;
		Vector b=carDir.rotateByAxis(RadianToDegree(atanf((float)7/(float)9)),1)*sqrtf(35*35+45*45)*0.05f;
		carPoint[0]=position+a;
		carPoint[1]=position+b;
		carPoint[2]=position-a;
		carPoint[3]=position-b;
	}

	void AIControl(Car opeCar,Car *car);
	void opCar(int type,Vector vec);
	int carPosNum;
	int fragmentLen;
private:
	Vector position;
	Vector scale;
	float rotate;
	Vector carDir;
	Vector carPoint[4];
	Road road;
	All_obs block;
	int fragment;
	Curve roadLine,roadLeft,roadRight;
	int carID;
	bool isSlerp;
	float roadSize;
};

