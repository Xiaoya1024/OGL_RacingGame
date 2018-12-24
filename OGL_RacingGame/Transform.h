#pragma once
#include "Vector.h"
#include "Euler.h"
#include "Matrix.h"
class Transform
{
public:
	Transform(void);
	~Transform(void);
	Vector position;//位置
	Vector scale;//大小
	Euler rotate;//旋转

	//世界坐标系中物体的位置
	void setPosition(float x,float y,float z){position.Set(x,y,z);}
	//世界坐标系中物体的位置
	void setPosition(const Vector vec){position.Set(vec);}
	//物体的大小
	void setScale(float x,float y,float z){scale.Set(x,y,z);}
	//物体的大小
	void setScale(const Vector vec){scale.Set(vec);}
	//物体绕自身坐标系的旋转
	void setRotate(float h,float p,float b){rotate.Set(h,p,b);}
	//物体绕自身坐标系的旋转
	void setRotate(const Euler euler){rotate.Set(euler);}
	//重置物体的transform
	void reset();
	//执行物体的变换
	void push();
	//执行物体的相应的变换
	void push(Matrix&mat);//获取当前矩阵mat
	//取出物体的变换
	void pop();
};

