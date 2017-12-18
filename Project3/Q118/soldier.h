#pragma once
#include<string>
using namespace std;
class soldier
{
public:
	soldier();
	~soldier();
	int hp;
	int atk;
string name;
	virtual	void power();
	bool isAlive(){
		return hp > 0;
	};
	virtual bool beAttacked(int defeat){
		hp -= defeat;
		return true;
	}
	virtual string getName(){
		return name;
	}
};