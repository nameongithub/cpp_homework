#include<iostream>
using namespace std;
#include"Sort.h"

int main(){
	
	
	int x1;
	cin >> x1;
	
	Sort<int> sort1(x1);
	cin >> sort1;
	
	int search1;
	cin >> search1;
	cout << sort1.search(search1)<<endl;
	
	int x2;
	cin >> x2;

	Sort<double> sort2(x2);
	cin >> sort2;

	double search2;
	cin >> search2;
	cout << sort2.search(search2)<<endl;

	
	
	
	int x3;
	cin >> x3;

	Sort<char> sort3(x3);
	cin >> sort3;

	char search3;
	cin >> search3;
	cout << sort3.search(search3);
	
	
	
}