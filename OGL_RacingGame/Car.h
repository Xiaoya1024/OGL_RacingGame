#pragma once
#include "Vector.h"
#include "Euler.h"
enum carType{//这里应该是贴不同的图片
	npcCar=0,
	blueCar=1,
	greenCar=2,
	redCar=3,
};
enum carView{
	DRIVEVIEW=0,//司机视角
	GODVIEW=1//上帝视角
};
class Car
{
public:
	Car(void);
	~Car(void);
	Vector position;
	Vector scale;
	Euler rotate;
	Vector speed;
	carView view;
	void initBody();//view为0表示上帝视角，为1表示司机视角（透视）
	void initWheel();
	void initCar();
	void pushMatrix();//执行小车的变换
	void popMatrix();//将小车的变换矩阵取出
};

