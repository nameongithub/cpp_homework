#pragma once
#include<iostream>
using namespace std;
class Operation
{
public:
	Operation();
	~Operation();
	double NumberA;
	double NumberB;
	virtual double	getResult() = 0;
	friend istream & operator >> (istream & i, Operation & o){
		return i >> o.NumberA >> o.NumberB;
	}

};

