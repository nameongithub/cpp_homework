#pragma once
#include "GPU.h"
class GPU1 :
	public GPU
{
public:
	GPU1();
	~GPU1();
	 double calculate(){
		 return GPU::hashRate*0.02-16.2;
	}
};

