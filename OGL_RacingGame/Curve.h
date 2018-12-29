#pragma once
#include"Vector.h"
#include <vector>
class Curve
{
public:
	Curve(void);
	~Curve(void);
	std::vector<Vector>pointList;
	//type是-1表示计算3维相交，0表示忽略x值,1表示忽略y值,2表示忽略z值
	
	bool isLineIntersect(Curve&other,std::vector<Vector>&p,int type);//判断折线相交，p是相交的点
	bool isLineIntersect(Curve&other,int type);

	float pointToLineDistance(Vector&p,int type);
	float pointToLineDistance(Vector&p,int type,Vector&out);//点到折线的距离，out是最近距离的点
	//沿折线运动，begind是运动前的索引位置,begdis是到运动前索引位置的距离float，movedis是要沿折线运动的距离，输出 pos( 当前位置) curind(当前索引) curdis(到当前索引的距离)
	void runByLine(int begind,float begins,float movedis,Vector&pos,int&curin,float&curdis);
	bool isInsideLine(Vector&p,int type);

	float pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type);

	bool isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,Vector&out,int type);//判断线段是否相交,out为相交的点
	bool isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,int type);
	float pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type,Vector&out);//点到线段的距离，a,b是线段的两点，p是点，out是最近距离的点
};

