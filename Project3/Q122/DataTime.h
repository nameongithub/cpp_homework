#pragma once
#include<iostream>
using namespace std;
class DataTime
{
public:
	DataTime(int year, int month, int day, int hour, int minute, int second) :year(year), month(month), day(day), hour(hour), minute(minute), second(second){};
	~DataTime();
	 void operator ++();
	 int year;
	 int month;
	 int day;
	 int hour;
	 int minute;
	 int second;
	bool isLeapYear(){
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	 }
	friend ostream & operator <<(ostream& o, const DataTime& t){
		return o << t.year << " " << t.month << " " << t.day << " "
			<< t.hour << " " << t.minute << " " << t.second;
	};
private:

	void secondAdd();
	void minuteAdd();
	void hourAdd();
	void dayAdd();
	void monthAdd();
	void yearAdd();
};

