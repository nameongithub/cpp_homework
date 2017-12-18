#include<iostream>
#include"QiPan.h"
using namespace std;
int main(){
	int m, n;
	cin >> n >> m;
	QiPan q(n, m);
	//o
	int user1 = 1;
	//x
	int user2 = 2;
	int count = 0;
	int i, j;
	while (cin >> i >> j){
		
		if (count / 2 * 2 == count)
			q.add(i, j, user1);
		else
			q.add(i, j, user2);
		count++;
	}
	
	bool oWin = q.isWinner(user1);
	bool xWin = q.isWinner(user2);


	
	
	if (oWin&&xWin){
		cout << "Dogfall";
	}else if (oWin)
	{
		cout << "O Success";
	}
	else if (xWin){
		cout << "X Success";
	}
	else{
		cout << "Dogfall";
	}
	
}