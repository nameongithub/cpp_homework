#pragma once
#include "food.h"
class beef :
	public food
{
public:
	beef(){
		carbohyrate = 1.8;
		protein = 17.5;
		DF = 0;
		fat = 7.2;
	};
	~beef();
};

