#include<iostream>
using namespace std;
int main(){
	int a, b, c, d;
	int sum = 0;
	cin >> a >> b >> c >> d;
	if (a == 1)
		sum += b * 10;
	if (a == 2)
		sum += b * 8;
	if (a == 3)
		sum += b * 7;
	if (c == 1)
		sum += d * 4;
	if (c == 2)
		sum += d * 3;
	cout << sum;
}