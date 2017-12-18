#include<iostream>

using namespace std;
typedef long long ll;
long long length;
// 要读懂题意。。心情简单
//用于保存各个节点的权值
ll * p;
//用于保存当前节点以下到当前节点权值和的最小值
ll * min;
//递归函数 取得最小值
ll getMin(long long i, long long j);
int main(){
	cin >> length;
	p = new ll[length*(length + 1) / 2];
	min = new ll[length*(length + 1) / 2];
	ll temple;
	int count = 0;
	for (long long i = 0; i < length; i++)
		for (long long j = 0; j < i + 1; j++){
			cin >> temple;
			*(p + count++) = temple ;
			*(min + count - 1) = 0;
	}
	if (length>1)
		for (long long i = length - 1; i > 0; i--){
			for (ll j = i; j >= 0; j--){
				*(p + (i + 1)*i / 2 + j) = *(p + (i + 1)*i / 2 + j) + ;
		}
	}
	cout << *p << endl;
	ll sum = getMin(0,0);
	cout << sum;
}
ll getMin(long long i, long long j){
	if (i == length - 1)
		return *(p + (i + 1)*i / 2 + j);
	ll x, y;
	if (*(min + (i + 1)*(i + 2) / 2 + j) == 0){
		*(min + (i + 1)*(i + 2) / 2 + j) = getMin(i + 1, j);
	}
	x = *(min + (i + 1)*(i + 2) / 2 + j );
	if (*(min + (i + 1)*(i + 2) / 2 + j + 1) == 0){
		*(min + (i + 1)*(i + 2) / 2 + j + 1) = getMin(i + 1, j + 1);
	}
	y = *(min + (i + 1)*(i + 2) / 2 + j + 1);
	ll min_number;
	if (x < y)
		min_number = x;
	else
		min_number = y;
	return *(p + (i + 1) * i / 2 + j) + min_number;
}
