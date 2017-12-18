#include<iostream>
#include"Point.h"
using namespace std;
int main(){
	Point a, b;
	cin >> a >> b;
	++a;
	cout << a <<endl<<a+b;
	getchar();
}