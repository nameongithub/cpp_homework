#include<iostream>
#include"OperationFactory.h"
#include"Operation.h"
using namespace std;
int main(){
	char op;
	cin >> op;
	OperationFactory fa;
	Operation *o = fa.creatOperation(op);
	cin >> *o;
	cout << o->getResult();
}