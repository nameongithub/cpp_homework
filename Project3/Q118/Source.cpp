#include<iostream>
#include"soldier.h"
#include"Leader.h"
#include"Magician.h"
#include"Warrior.h"
#include<vector>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	int index = 0;
	vector<soldier*> s1;
	vector<soldier*> s2;

	for (int i = 0; i < n; i++){
		cin >> index;
		switch (index)
		{
		case 1:{
			soldier * s = new Warrior;

			s1.push_back(s);
			break;
		}
		case 2:{
				;//= new Magician;
			s1.push_back (new Magician);
			break;
		}
		case 3:{
		//	Leader  w;//= new Leader;
			s1.push_back(new Leader);
			break;
		}
		default:
			break;
		}
	}
	for (int i = 0; i < n; i++){
		cin >> index;
		switch (index)
		{
		case 1:{
			Warrior w;
			s2.push_back(new Warrior);
			break;
		}
		case 2:{
			Magician m;
			s2.push_back(new Magician);
			break;
		}
		case 3:{
			Leader l;
			s2.push_back(new Leader);
			break;
		}
		default:
			break;
		}
	}
	int p1 = 0, p2 = 0;
	while (p1 < n && p2 < n){
		s1[p1]->beAttacked(s2[p2]->atk);
		s2[p2]->beAttacked(s1[p1]->atk);
		
		if (s1[p1]->isAlive())
			s1[p1]->power();
		else
			p1++;

		if (s2[p2]->isAlive())
			s2[p2]->power();
		else
			p2++;
	}
	if (n == p1&&n == p2)
		cout << "All Dead";
	else if (n > p1){
		for (int i = p1; i < n; i++){
			if (i != n - 1)
				cout << s1[i]->getName() <<" "<<s1[i]->atk<<" "<<s1[i]->hp<<endl;
			else
				cout << s1[i]->getName() << " " << s1[i]->atk << " " << s1[i]->hp;
		}
	}
	else if (s2.size() > p2){
		for (int i = p2; i < s2.size(); i++){
			if (i != s2.size() - 1)
				cout << s2[i]->getName() << " " << s2[i]->atk << " " << s2[i]->hp<<endl;
			else
				cout << s2[i]->getName() << " " << s2[i]->atk << " " << s2[i]->hp;
		}
	}
	
}