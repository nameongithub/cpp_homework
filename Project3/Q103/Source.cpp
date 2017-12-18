#include<string>
#include<iostream>
using namespace std;
void normal(string s);
void sort(string s);
int length;
long long zhuzi[2000];
int main(){
	string operat;
	cin >> operat>>length;
	if (operat == "NORMAL")
		normal(operat);
	else
		sort(operat);
}
void normal(string s){
	
	
	for (int i = 0; i < length; i++)
		cin >> zhuzi[i];
	int * used = new int[length];
	for (int  i = 0; i < length; i++)
	{
		used[i] = 0;
	}
	long long max = 0;
	int count = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (used[i])
		{
			continue;
		}
		int templeLength = 1;
		for (int j = 0; j < i; j++){
			if (zhuzi[i - j - 1] >= zhuzi[i])
			{
				templeLength++;
				if (zhuzi[i-j-1]==zhuzi[i])
				{
					used[i - j - 1] = 1;
				}
			}
			else
				break;
		}
		for (int j = i + 1; j < length; j++){
			if (zhuzi[j] >= zhuzi[i])
			{
				templeLength++;
				if (zhuzi[j] == zhuzi[i]){
					used[j] = 1;
				}
			}

			else
				break;
		}
		long long templeMax = zhuzi[i] * templeLength;

		if (templeMax == max )
		{
			count++;
			
		}
		if (templeMax > max)
		{
			max = templeMax;
			count = 1;
		}
		
	}

	cout << max << " "<<count;


}
void sort(string s){
	for (int i = 0; i < length; i++)
		cin >> zhuzi[i];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (zhuzi[j] > zhuzi[j + 1]){
				long long temple = zhuzi[j];
				zhuzi[j] = zhuzi[j + 1];
				zhuzi[j + 1] = temple;
			}
		}
	}
	long long max = 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		long long templeMax = zhuzi[i] * (length - i);
		if (templeMax == max)
		{
			count++;
		}
		if (templeMax > max)
		{
			max = templeMax;
			count = 1;
		}

	}
	cout << max;
}