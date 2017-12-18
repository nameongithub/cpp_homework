#pragma once
class QiPan
{
public:
	QiPan(int n,int m);
	int m;
	int n;
	~QiPan();
	void add(int i, int j, int u){
		p[i][j] = u;
	}
	bool isWinner(int user);
private:
	int** p;
	bool isWinner(int i, int j, int user);
};

