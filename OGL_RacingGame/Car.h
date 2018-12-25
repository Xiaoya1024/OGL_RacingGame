#pragma once
#include "Vector.h"
#include "Euler.h"
enum carType{//����Ӧ��������ͬ��ͼƬ
	npcCar=0,
	blueCar=1,
	greenCar=2,
	redCar=3,
};
enum carView{
	DRIVEVIEW=0,//˾���ӽ�
	GODVIEW=1//�ϵ��ӽ�
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
	void initBody();//viewΪ0��ʾ�ϵ��ӽǣ�Ϊ1��ʾ˾���ӽǣ�͸�ӣ�
	void initWheel();
	void initCar();
	void pushMatrix();//ִ��С���ı任
	void popMatrix();//��С���ı任����ȡ��
};

