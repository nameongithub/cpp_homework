#include<iostream>
#include"GPU.h"
#include"GPU1.h"
#include"GPU2.h"
#include"GPU3.h"
using namespace std;
int main(){
	GPU1 g1;
	GPU2 g2;
	GPU3 g3;
	cin >> g1 >> g2 >> g3;
	int sunPrice = g1.price + g2.price + g3.price;
	double profit = g1.calculate() + g2.calculate() + g3.calculate();
	
	if (profit <= 0)
		cout << "-1";
	else
	{
		int day = sunPrice / profit;
		double temple = sunPrice / profit;
		
		if (day < temple)
			day++;
		cout << day;
		//getchar();
	}
}