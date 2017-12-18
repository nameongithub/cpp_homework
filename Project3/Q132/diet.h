#pragma once
#include"food.h"
#include<vector>

class diet
{
public:
	diet();
	~diet();
	std::vector<food> list;
	friend void  operator += (diet& d, food & f){
		d.list.push_back(f);
	}
	const double MIN_CAR = 13.3;
	const double MIN_PRO = 13.5;
	const double MIN_DF = 3.3;
	const double MAX_FAT = 10.3;
	bool ishealthy(){
		double car = 0;
		for (food f : list)
			car += f.carbohyrate;
		
		double pro = 0;
		for (food f : list)
			pro += f.protein;

		double df = 0;
		for (food f : list)
			df += f.DF;
		
		double fat = 0;
		for (food f : list){
			fat += f.fat;
		}
		return (car >= MIN_CAR&&pro >= MIN_PRO&&
			df >= MIN_DF&&fat <= MAX_FAT);
	}
};

