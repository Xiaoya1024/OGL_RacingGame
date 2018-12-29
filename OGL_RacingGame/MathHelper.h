#pragma once
#include <math.h>
#include <iostream>
using namespace std;
#define FLOAT_EPS 1e-6
#define PI 3.141592653
#define Radian 0.0174532925//一角度等于Radian弧度

static float RadianToDegree(float val){//将弧度转换成角度
	float res=float(val/Radian);
	return res;
}
static float DegreeToRadian(float degree){//将角度转换成弧度
	float res=float(degree*Radian);
	return res;
}