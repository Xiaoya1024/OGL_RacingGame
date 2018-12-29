#include "stdafx.h"
#include "Timer.h"

void Timer::Start(){
	clockBegin=clock();
}

void Timer::Stop(){
	clockEnd=clock();
}

int Timer::Get(){
	return clockEnd-clockBegin;
}