#pragma once
#include "GPU.h"
class GPU3 :
	public GPU
{
public:
	GPU3();
	~GPU3();
	double calculate(){
		return hashRate*0.02 - 19.44;
	}
};

