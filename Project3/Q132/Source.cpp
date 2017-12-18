#include<iostream>
#include"diet.h"
#include"food.h"
#include"beef.h"
#include"bro.h"
#include"cab.h"
#include"duck.h"
#include"food.h"
#include"oat.h"
#include"rice.h"
using namespace std;
int main(){
	int index;
	diet diet;
	while (cin >> index){
		switch (index)
		{
		case 1:
		{	rice r;
			diet += r;
			break;
		}
		case 2:{
			beef b;
			diet += b;
			break;
		}
		case 3:{
			bro b;
			diet += b;
			break;
		}	
		case 4:{
			oat b;
			diet += b;
			break;
		}	case 5:{
			duck b;
			diet += b;
			break;
		}	case 6:{
			cab b;
			diet += b;
			break;
		}
		default:{
			cout << "-1";
			return 0;
				break;
		}
		}
	}
	if (diet.ishealthy())
		cout << "healthy";
	else
		cout << "unhealthy";

}