
//空间换时间 素数个数筛选法
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<1000000000> *p = new bitset<1000000000>;
	p->set();
	for (int i = 2; i <= 100000; i++)
	{
		if (p->test(i))
		{
			for (int j = i*i; j < p->size(); j+=i)
			{
				p->reset(j);
			}
		}
	}
	int number = 0;
	for (int i = 2; i < 1000000000; i++)
	{
		if (p->test(i))
		{
			number++;
		}
	}
	cout << number << endl;
	delete[] p;
}