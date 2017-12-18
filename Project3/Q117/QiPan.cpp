#include "QiPan.h"

QiPan::QiPan(int n, int m){
	p = new int*[n];
	for (int i = 0; i < n; i++){
		p[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			p[i][j] = 0;
		}
	}
	QiPan::n = n;
	QiPan::m = m;
}
bool QiPan::isWinner(int user){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (isWinner(i, j, user))
				return true;
		}
	}
	return false;
}
bool QiPan::isWinner(int i, int j, int user){
	if (p[i][j] != user)
		return false;

	int count = 1;
	int x = i, y = j;
	while (++x < n&&p[x][y] == user)
		count++;
	x = i;
	y = j;
	while (--x >= 0&&p[x][y] == user)
		count++;
	if (count >= m)
		return true;
	count = 1;
	x = i;
	y = j;
	while (--y >= 0 && p[x][y] == user)
		count++;
	y = j;
	while (++y <n && p[x][y] == user)
		count++;
	if (count >= m)
		return true;
	count = 1;
	x = i;
	y = j;
	while (++y <n &&++x<n&& p[x][y] == user)
		count++;
	x = i;
	y = j;
	while (--y >=0 &&--x>=0&& p[x][y] == user)
		count++;
	if (count >= m)
		return true;
	count = 1;
	x = i;
	y = j;

	while (++y < n &&--x>=0&& p[x][y] == user)
		count++;
	x = i;
	y = j;
	while (--y >= 0 && ++x < n&& p[x][y] == user)
		count++;
	if (count >= m)
		return true;
	return false;
};
QiPan::~QiPan()
{
}
