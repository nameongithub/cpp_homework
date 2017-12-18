#include"Student.h"
#include<iostream>
template<class E,class T>
int compare(E a, T b){
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
};
int main(){
	Student A, B;
	cin >> A >> B;
	cout << compare(A.name, B.name) << " " << compare(A.year, B.year) << " " << compare(A.weight, B.weight) << " "
		<< compare(A, B);
}
