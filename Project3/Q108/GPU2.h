#pragma once
#include "GPU.h"
class GPU2 :
	public GPU
{
public:
	GPU2();
	~GPU2();
	double calculate(){
		return hashRate*0.02 - 28.8;
	}
};

