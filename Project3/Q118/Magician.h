#pragma once
#include "soldier.h"
class Magician :
	public soldier
{
public:
	Magician(){
		hp = 2;
		atk = 6;
		name = "Magician";
	};
	int pow = 1;
	virtual	bool beAttacked(int defeat){
		if (pow == 1)
		{
			pow = 0;
			return false;
		}
		hp -= defeat;
		return true;
	}
	~Magician();
	virtual	void power(){
		
	}
};

