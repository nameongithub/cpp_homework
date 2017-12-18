#pragma once
#include "Operation.h"
class OperationAdd :
	public Operation
{
public:
	OperationAdd();
	~OperationAdd();
	double getResult(){
		return NumberA + NumberB;
	}
};

