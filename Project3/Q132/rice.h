#pragma once
#include "food.h"
class rice :
	public food
{
public:
	rice(){
		carbohyrate = 16.2;
		protein = 3.7;
		DF = 0;
		fat = 0;
	};
	~rice();
	
};

