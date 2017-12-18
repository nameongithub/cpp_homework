#pragma once
#include<iostream>
using namespace std;
class GPU
{
public:
	GPU();
	~GPU();
	virtual double calculate() = 0;
	int price, hashRate;
	friend istream& operator >>(istream& i, GPU & gpu){
		return i >>gpu.price >> gpu.hashRate;
	}

};

