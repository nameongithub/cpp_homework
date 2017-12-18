#include<iostream>
#include"DataTime.h"
using namespace std;
int main(){
	int year, month, day, hour, minute, second;
	cin >> year >> month >> day >> hour >> minute >> second;
	DataTime dataTime(year, month, day, hour, minute, second);
	dataTime++;
	cout << dataTime;
}