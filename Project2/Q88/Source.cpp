#include<iostream>
#include<string>
using namespace std;
int length;
string *p;
bool LessThan(char x, char y){
	if (x == y)
		return false;
	int xChar = x;
	int yChar = y;
	//转换成相同的小写
	xChar =( x >= 'a' ? (x - 'a' + 'A') : x);
	yChar =( y >= 'a' ? (y - 'a' + 'A') : y);
	//先根据小写判断是否小于
	if (xChar < yChar)
		return true;
	if (xChar > yChar)
		return false;
	//如果小写相同判断哪个是否 x是小写排在前
	if (x > y)
	return true;
	else
	return false;
}
// x是否小于y x是否应该排在前面
bool lessThan(string x, string y){
	if (x == y)
		return false;
	if (x.length() > y.length())
		return false;
	if (x.length() < y.length())
		return true;
	for (int i = 0; i < x.length(); i++){
		if (x[i] != y[i])
		if (LessThan(x[i], y[i]))
			return true;
		else
			return false;
	}
	return false;
}

int main(){
	cin >> length;
	p = new string[length];
	for (int i = 0; i < length; i++){
		cin >> *(p+i);
	}
	for (int i = 0; i < length; i++){
		for (int j = 0 ; j < length-1; j++){
			if (!lessThan(p[j], p[j+1])){
				string temple = *(p + j);
				*(p+j) = *(p + j + 1);
				*(p+j+1) = temple;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		if (i != length - 1)
			cout << *(p + i) << endl;
		else
			cout << *(p + i);
	}
}
