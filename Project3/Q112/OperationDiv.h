#pragma once
#include "Operation.h"
class OperationDiv :
	public Operation
{
public:
	OperationDiv();
	~OperationDiv();
	double getResult(){
		if (NumberB == 0)
			return -1;
		return NumberA / NumberB;
	}
};

