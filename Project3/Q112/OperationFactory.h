#pragma once
#include"Operation.h"
class OperationFactory
{
public:
	OperationFactory();
	~OperationFactory();
	Operation * creatOperation(char c);
};

