#pragma once
#include <math.h>
#define FLOAT_EPS 1e-6
#define PI acosf(0.0f)*2
#define Radian acosf(0.0) / 90.f//һ�Ƕȵ���Radian����

static float RadianToDegree(float val){//������ת���ɽǶ�
	float res=(float)(val/Radian);
	return res;
}
static float DegreeToRadian(float degree){//���Ƕ�ת���ɻ���
	float res=(float)(degree*Radian);
	return res;
}