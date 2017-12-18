#pragma once
#include "food.h"
class cab :
	public food
{
public:
	cab(){
		carbohyrate = 2.1;
		protein = 0.8;
		DF = 4.3;
		fat = 0;
	};
	~cab();
};

