#pragma once
#include <math.h>
#define FLOAT_EPS 1e-6
#define PI acosf(0.0f)*2
#define Radian acosf(0.0) / 90.f//一角度等于Radian弧度

static float RadianToDegree(float val){//将弧度转换成角度
	float res=(float)(val/Radian);
	return res;
}
static float DegreeToRadian(float degree){//将角度转换成弧度
	float res=(float)(degree*Radian);
	return res;
}