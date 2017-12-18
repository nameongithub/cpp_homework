#pragma once
#include<string>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	friend istream & operator >> (istream &i, Student &s){
		return i >> s.id >> s.name >> s.year >> s.weight >> s.mathScore >> s.EnglishScore >> s.cppScore;
	}
	friend	int operator >(Student & s, Student & t){
		if (s.sum() > t.sum())
			return 1;
		return 0;
	}
	friend int operator < (Student & s, Student & t){
		if (s.sum() < t.sum())
			return 1;
		return 0;
	}
	friend int operator == (Student & s, Student & t){
		if (s.sum() == t.sum())
			return 1;
		return 0;
	}
	int sum(){
		return mathScore * 4 + EnglishScore * 4 + cppScore * 3;
	}
	string id;
	string name;
	int year;
	double weight;
	double mathScore;
	double EnglishScore;
	double cppScore;
private:
	
};

