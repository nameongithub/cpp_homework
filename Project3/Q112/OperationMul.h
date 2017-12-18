#pragma once
#include "Operation.h"
class OperationMul :
	public Operation
{
public:
	OperationMul();
	~OperationMul();
	double	getResult(){
		return NumberA * NumberB;
	}
};

