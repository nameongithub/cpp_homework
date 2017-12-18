#pragma once
#include"soldier.h"
class Warrior : public soldier
{
public:
	Warrior(){
		hp = 12;
		atk = 2;
		name = "Warrior";
	};
	~Warrior();
	virtual	void power(){
		hp++;
	}
};

