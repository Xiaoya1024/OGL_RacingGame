
#pragma once
#include "stdafx.h"
#include <time.h>

class Timer{
public:	
	clock_t clockBegin, clockEnd;
	
	void Start();
	void Stop();
	//∫¡√Î
	int Get();
};