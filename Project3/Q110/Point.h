#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0, int z = 0) :x(x), y(y), z(z){};
	~Point();
	int x, y, z;
	friend istream & operator >> (istream & i, Point & t){
		return i >> t.x >> t.y >> t.z;
	}
	friend ostream & operator << (ostream & o, Point & p){
		return o << "x:" << p.x << "," << "y:" << p.y << "," << "z:" << p.z ;
	}
	friend 	void operator ++ (Point& p){
		p.x++;
		p.y++;
		p.z++;
	};
	friend Point& operator + (Point&a, Point&b){
		b.x += a.x;
		b.y += a.y;
		b.z += a.z;
		return b;
	}
};

