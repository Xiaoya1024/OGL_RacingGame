#pragma once
#include <math.h>
#include <iostream>
using namespace std;
#define FLOAT_EPS 1e-6
#define PI 3.141592653
#define Radian 0.0174532925//һ�Ƕȵ���Radian����

static float RadianToDegree(float val){//������ת���ɽǶ�
	float res=float(val/Radian);
	return res;
}
static float DegreeToRadian(float degree){//���Ƕ�ת���ɻ���
	float res=float(degree*Radian);
	return res;
}