#include "DataTime.h"




DataTime::~DataTime()
{
}
void DataTime::operator++(){
	secondAdd();
}
void DataTime::secondAdd(){
	if (second < 59)
		second++;
	else
	{
		second = 0;
		minuteAdd();
	}
}
void DataTime::minuteAdd(){
	if (minute < 59)
		minute++;
	else
	{
		minute = 0;
		hourAdd();
	}
}
void DataTime::hourAdd(){
	if (hour < 23)
		hour++;
	else
	{
		hour = 0;
		dayAdd();
	}
}
void DataTime::dayAdd(){
	if (isLeapYear() && month == 2)
	{
		if (day <= 28)
			day++;
		else{
			day = 1;
			month++;
		}
	}
	else if (!isLeapYear()&&month == 2 && day == 28){
		day = 1;
		month++;
	} 
	else if ((day == 31) && (month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10 || month == 12)){
		day = 1;
		monthAdd();
	}
	else if ((day == 30) && (month==4||month==6||month==9
	||month==11))
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
	
}
void DataTime::monthAdd(){
	if (month == 12){
		month = 1;
		yearAdd();
	}
	else{
		month++;
	}
}
void DataTime::yearAdd(){
	year++;
}


