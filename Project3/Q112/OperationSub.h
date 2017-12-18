#pragma once
#include "Operation.h"
class OperationSub :
	public Operation
{
public:
	OperationSub();
	~OperationSub();
	double getResult(){
		return NumberA - NumberB;
	}
};

