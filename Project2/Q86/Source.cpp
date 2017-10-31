#include<iostream>
using namespace std;
int m, n;
int*p;
int length;
int getElement(int x, int y);
int getSpecialNumber(int x);
int main(){
	cin >> m >> n;
	p = new int[m*n];
	length = m * n;
	int count = 0;
	for (int i = 0; i < length; i++)
		cin >> *(p + count++);
	int x;
	cin >> x;
	cout << getSpecialNumber(x);
	
}
int getElement(int x, int y){
	return *(p + n * x + y);
}

int getSpecialNumber(int special){
	int xCount = 0, yCount = 0,i = 1;
	while (special >= (m+n-i)){
		special -= (m + n - i);
		i += 2;
		xCount++;
		yCount++;
	}
	if (special >= n - yCount){		
		special -= (n - yCount);
		yCount++;
	}
	int x, y;
	if (xCount == yCount){
		if (xCount / 2 * 2 == xCount){
			x = xCount / 2;
			y = yCount / 2 + special;
		}
		else{
			
				x = m - 1 - xCount/2;
				y = n - 2 - special - yCount/2 ;//很迷 我也不知道为啥 就这样对了
				
		}
	}
	else{
		if (yCount/2*2!=yCount){
			x = (xCount / 2) + special + 1;
			y = n - (yCount / 2) - 1;
		}
		else{
			
			x = (m - 1) - (xCount/2) - special - 1;	
			y = (yCount / 2) - 1;
		}
	}
	
	return getElement(x, y);


}