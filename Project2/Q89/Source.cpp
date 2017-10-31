#include<iostream>
#include<string>
typedef long long int;
using namespace std;
string *p;
int length;
int findIndex(string s){
	for (int i = 0; i < length; i++)
	{
		if (*(p + i) == s)
			return i;
	}
	return -1;
}
int findLength(string x, string y){
	if (x == y)
		return 0;
	int xIndex = findIndex(x) + 1;
	int yIndex = findIndex(y) + 1;
	//假设x是y 的父类
	bool xIsparent = false;
	int count = 0;//用于计数
	int index = yIndex / 2;
	while (index > 0){
		count++;
		if (*(p + index - 1) == x){
			xIsparent = true;
			break;
		}
		index /= 2;
	}
	if (xIsparent)
		return count;
	//假设y是x的父类
	bool yIsparent = false;
	count = 0;
	index = xIndex / 2;
	while (index > 0){
		count++;
		if (*(p + index - 1) == y){
			yIsparent = true;
			break;
		}
		index /= 2;
	}
	if (yIsparent)
		return count;

	return -1;
	
}

int main(){
	
	cin >> length;
	p = new string[length];
	for (int i = 0; i < length; i++)
	{
		cin >> *(p + i);
	}
	string x;
	string y;
	cin >> x >> y;
	cout << findLength(x, y);
	
}
