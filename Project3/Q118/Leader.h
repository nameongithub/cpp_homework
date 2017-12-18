#pragma once
#include "soldier.h"
class Leader :
	public soldier
{
public:
	Leader(){
		hp = 6;
		atk = 6;
		name = "Leader";
	};
	~Leader();
	virtual	void power(){
 		atk++;
	}
	
};

