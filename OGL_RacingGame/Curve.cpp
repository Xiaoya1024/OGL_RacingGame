#define _CRT_SECURE_NO_WARNINGS
#include "Curve.h"
#include "MathHelper.h"
Curve::Curve(void)
{
}
Curve::~Curve(void)
{
}
bool Curve::isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,Vector&out,int type){
	Vector d1(t.x-a.x,t.y-a.y,t.z-a.z);
	Vector d2(t2.x-b.x,t2.y-b.y,t2.z-b.z);
	if(type!=-1){
		Vector a2=a;
		Vector b2=b;
		Vector d12=d1;
		Vector d22=d2;
		if(type==0)a2.x=b2.x=d12.x=d22.x=0;
		else if(type==1)a2.y=b2.y=d12.y=d22.y=0;
		else if(type==2)a2.z=b2.z=d12.z=d22.z=0;
		Vector cross=d12.crossMul(d22);
		float xx=cross.len();
		xx*=xx;
		Vector bma(b2.x-a2.x,b2.y-a2.y,b2.z-a2.z);
		float t1=(bma.crossMul(d22).dotMul(cross))/xx;
		if(t1>1.0f||t1<0.0f)
			return false;
		if((bma.crossMul(d1).dotMul(cross)/xx>1.0f))
			return false;
		out=a+d1*t1;
		return true;
	}else{
		Vector cross=d1.crossMul(d2);
		float xx=cross.len();
		xx*=xx;
		Vector bma(b.x-a.x,b.y-a.y,b.z-a.z);
		float t1=(bma.crossMul(d2)).dotMul(cross)/xx;
		if(t1>1.0f||t1<0.0f)
			return false;
		if((bma.crossMul(d1)).dotMul(cross)/xx>1.0f)
			return false;
		out=a+d1*t1;
		return true;
	}
}
bool Curve::isSegmentIntersect(Vector&a, Vector&t, Vector&b, Vector&t2,int type){
	Vector d1(t.x-a.x,t.y-a.y,t.z-a.z);
	Vector d2(t2.x-b.x,t2.y-b.y,t2.z-b.z);
	if(type!=-1){
		Vector a2=a;
		Vector b2=b;
		Vector d12=d1;
		Vector d22=d2;
		if(type==0)a2.x=b2.x=d12.x=d22.x=0;
		else if(type==1)a2.y=b2.y=d12.y=d22.y=0;
		else if(type==2)a2.z=b2.z=d12.z=d22.z=0;
		Vector cross=d12.crossMul(d22);
		float xx=cross.len();
		xx*=xx;
		Vector bma(b2.x-a2.x,b2.y-a2.y,b2.z-a2.z);
		float t1=(bma.crossMul(d22).dotMul(cross))/xx;
		if(t1>1.0f||t1<0.0f)
			return false;
		if((bma.crossMul(d1).dotMul(cross)/xx>1.0f))
			return false;
		return true;
	}else{
		Vector cross=d1.crossMul(d2);
		float xx=cross.len();
		xx*=xx;
		Vector bma(b.x-a.x,b.y-a.y,b.z-a.z);
		float t1=(bma.crossMul(d2)).dotMul(cross)/xx;
		if(t1>1.0f||t1<0.0f)
			return false;
		if((bma.crossMul(d1)).dotMul(cross)/xx>1.0f)
			return false;
		return true;
	}
}
bool Curve::isLineIntersect(Curve&other,std::vector<Vector>&p,int type){
	Vector temp;
	for(unsigned int i=1;i<pointList.size();i++)
		for(unsigned int j=1;j<other.pointList.size();j++)
			if(isSegmentIntersect(pointList[i-1],pointList[i],other.pointList[j-1],other.pointList[j],temp,type))
				p.push_back(temp);
	unsigned int k=0;
	return p.size()>k;
}
bool Curve::isLineIntersect(Curve&other,int type){
	Vector temp;
	for(unsigned int i=1;i<pointList.size();i++)
		for(unsigned int j=1;j<other.pointList.size();j++)
			if(isSegmentIntersect(pointList[i-1],pointList[i],other.pointList[j-1],other.pointList[j],temp,type))
				return true;
	return false;
}
float Curve::pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type,Vector&out){
	Vector d(b.x-a.x,b.y-a.y,b.z-a.z);
	Vector d2(p.x-a.x,p.y-a.y,p.z-a.z);
	if(type==0)d.x=d2.x=0;
	else if(type==1)d.y=d2.y=0;
	else if(type==2)d.z=d2.z=0;
	float len1=d.len();
	float len2=d2.len();
	if(len1==0.0f||len2==0.0f){
		out=a;
		return len2;
	}
	if(d.dotMul(d2)>0){
		Vector t2=d2.project(d);
		if(type==0)t2.x=0;
		else if(type==1)t2.y=0;
		else if(type==2)t2.z=0;
		if(t2.len()>len1){
			Vector temp(p.x-b.x,p.y-b.y,p.z-b.z);
			if(type==0)temp.x=0;
			else if(type==1)temp.y=0;
			else if(type==2)temp.z=0;
			out=b;
			return temp.len();
		}else{
			Vector temp(d2.x-t2.x,d2.y-t2.y,d2.z-t2.z);
			if(type==0)temp.x=0;
			else if(type==1)temp.y=0;
			else if(type==2)temp.z=0;
			out=p-temp;
			return temp.len();
		}
	}else{
		out=a;
		return len2;
	}
}
float Curve::pointToLineDistance(Vector&p,int type,Vector&out){
	float dis2=FLT_MAX;
	Vector temp;
	for (unsigned int i=1;i<pointList.size();i++)
	{
		float m=pointToSegmentDistance(pointList[i-1],pointList[i],p,type,temp);
		if(m<dis2){
			out=temp;
			dis2=m;
		}
	}
	return dis2;
}
float Curve::pointToLineDistance(Vector&p,int type){
	float dis2=FLT_MAX;
	Vector temp;
	for (unsigned int i=1;i<pointList.size();i++)
	{
		float m=pointToSegmentDistance(pointList[i-1],pointList[i],p,type,temp);
		if(m<dis2){
			dis2=m;
		}
	}
	return dis2;
}
float Curve::pointToSegmentDistance(Vector &a,Vector&b,Vector&p,int type){
	Vector d(b.x-a.x,b.y-a.y,b.z-a.z);
	Vector d2(p.x-a.x,p.y-a.y,p.z-a.z);
	if(type==0)d.x=d2.x=0;
	else if(type==1)d.y=d2.y=0;
	else if(type==2)d.z=d2.z=0;
	float len1=d.len();
	float len2=d2.len();
	if(len1==0.0f||len2==0.0f){
		return len2;
	}
	if(d.dotMul(d2)>0){
		Vector t2=d2.project(d);
		if(type==0)t2.x=0;
		else if(type==1)t2.y=0;
		else if(type==2)t2.z=0;
		if(t2.len()>len1){
			Vector temp(p.x-b.x,p.y-b.y,p.z-b.z);
			if(type==0)temp.x=0;
			else if(type==1)temp.y=0;
			else if(type==2)temp.z=0;
			return temp.len();
		}else{
			Vector temp(d2.x-t2.x,d2.y-t2.y,d2.z-t2.z);
			if(type==0)temp.x=0;
			else if(type==1)temp.y=0;
			else if(type==2)temp.z=0;
			return temp.len();
		}
	}else{
		return len2;
	}
}
void Curve::runByLine(int begind,float begins,float movedis,Vector&pos,int&curin,float&curdis){
	float ds2=movedis+begins;
	if(ds2>0){
		for(curin=begind;curin<int(pointList.size())-1;curin++){
			float dd=(pointList[curin+1]-pointList[curin]).len();
			if(ds2>=dd){
				ds2-=dd;
			}else{
				curdis=ds2;
				pos=(pointList[curin+1]-pointList[curin])*(ds2/dd)+pointList[curin];
				break;
			}
		}
	}
	else{
		for(curin=begind;curin>0;curin--){
			float dd=(pointList[curin]-pointList[curin-1]).len();
			if(ds2>=dd)
				ds2-=dd;
			else{
				curin=int(ds2);
				pos=(pointList[curin]-pointList[curin-1])*(ds2/dd)+pointList[curin];
				break;
			}
		}
	}
}

bool Curve::isInsideLine(Vector&p,int type){
	int len = this->pointList.size();
	float totalAngle = 0.0f;
	Vector a;
	Vector b;
	for(int i = 0; i < len; i++) {
		if(i == len - 1) {
			a = this->pointList[i] - p;
			b = this->pointList[0] - p;
		}
		else {
			a = this->pointList[i] - p;
			b = this->pointList[i + 1] - p;
		}
		if(type == 0) {
			a.x = b.x = 0;
			if((a.crossMul(b)).x < 0) {
				totalAngle -= acos(a.dotMul(b) / (a.len() * b.len()));
			}
			else {
				totalAngle += acos(a.dotMul(b) / (a.len() * b.len()));
			}
		}
		else if(type == 1) {
			a.y = b.y = 0;
			if((a.crossMul(b)).y > 0) {
				totalAngle -= acos(a.dotMul(b) / (a.len() * b.len()));
			}
			else {
				totalAngle += acos(a.dotMul(b) / (a.len() * b.len()));
			}
		}
		else if(type == 2) {
			a.z = b.z = 0;
			if((a.crossMul(b)).z < 0) {
				totalAngle -= acos(a.dotMul(b) / (a.len() * b.len()));
			}
			else {
				totalAngle += acos(a.dotMul(b) / (a.len() * b.len()));
			}
		}
	}
	if(abs(totalAngle - 2 * PI) < 0.001) {
		return true;
	}
	return false;
}