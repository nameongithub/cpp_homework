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
	//ת������ͬ��Сд
	xChar =( x >= 'a' ? (x - 'a' + 'A') : x);
	yChar =( y >= 'a' ? (y - 'a' + 'A') : y);
	//�ȸ���Сд�ж��Ƿ�С��
	if (xChar < yChar)
		return true;
	if (xChar > yChar)
		return false;
	//���Сд��ͬ�ж��ĸ��Ƿ� x��Сд����ǰ
	if (x > y)
	return true;
	else
	return false;
}
// x�Ƿ�С��y x�Ƿ�Ӧ������ǰ��
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
