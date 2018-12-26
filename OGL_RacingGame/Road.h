#pragma once
#include"Vector.h"
#include <vector>
#include "Matrix.h"
class Road
{
public:
	Vector pos;//÷–µ„µƒŒª÷√
	float size;//≥ﬂ¥Á
	Vector left;//◊Û±ﬂ’œ∞≠
	Vector right;//”“±ﬂ’œ∞≠
	void Setobs(float obs_size,Vector dir=Vector(0,0,1));//…Ë÷√’œ∞≠
	void Setboundary(Vector dir);//…Ë÷√±ﬂΩÁ
};
void Setpos(float size);
void Set_all_boundary(int begin,int end);
void Set_Road();