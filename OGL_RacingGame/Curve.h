#pragma once
#include"Vector.h"
#include <vector>
class Curve
{
public:
	Curve(void);
	~Curve(void);
	std::vector<Vector>pointList;
	//type��-1��ʾ����3ά�ཻ��0��ʾ����xֵ,1��ʾ����yֵ,2��ʾ����zֵ
	
	bool isLineIntersect(Curve&other,std::vector<Vector>&p,int type);//�ж������ཻ��p���ཻ�ĵ�
	bool isLineIntersect(Curve&other,int type);

	float pointToLineDistance(Vector&p,int type);
	float pointToLineDistance(Vector&p,int type,Vector&out);//�㵽���ߵľ��룬out���������ĵ�
	//�������˶���begind���˶�ǰ������λ��,begdis�ǵ��˶�ǰ����λ�õľ���float��movedis��Ҫ�������˶��ľ��룬��� pos( ��ǰλ��) curind(��ǰ����) curdis(����ǰ�����ľ���)
	void runByLine(int begind,float begins,float movedis,Vector&pos,int&curin,float&curdis);
	bool isInsideLine(Vector&p,int type);

	float pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type);

	bool isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,Vector&out,int type);//�ж��߶��Ƿ��ཻ,outΪ�ཻ�ĵ�
	bool isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,int type);
	float pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type,Vector&out);//�㵽�߶εľ��룬a,b���߶ε����㣬p�ǵ㣬out���������ĵ�
};

