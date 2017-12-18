#include "OperationFactory.h"
#include"OperationAdd.h"
#include"OperationSub.h"
#include"OperationMul.h"
#include"OperationDiv.h"


OperationFactory::OperationFactory()
{
}


OperationFactory::~OperationFactory()
{
}
Operation * OperationFactory::creatOperation(char c){

	switch (c)
	{	
	case '+' :
		return new OperationAdd;
		break;
	case'-':
		return new OperationSub;
		break;
	case '*':
		return new OperationMul;
		break;
	case '/':
			return new OperationDiv;
			break;
	default:
		return NULL;
		break;
	}
}
