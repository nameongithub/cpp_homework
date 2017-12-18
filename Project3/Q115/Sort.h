#pragma once
#include<iostream>
using namespace std;


template<typename T>
class Sort
{
public:
	T * p;
	int number;
	Sort(int n);
	~Sort();
	

	
	friend istream & operator >> (istream & i, Sort<T>& s){
		for (int j = 0; j < s.number; j++){
			i >> *(s.p + j);
		}
	
		return i;
	};
	friend ostream & operator << (ostream & o, Sort<T>& s){
	
		for (int j = 0; j < s.number; j++){
			o << *(s.p + j)<<" ";
		}
		o << endl;
		return o;
	}
	int search(T t);
private: 
		void sort(){
		for (int i = 0; i < number; i++){
			for (int j = 0; j < number - 1; j++){
				if (*(p + j) > *(p + j + 1)){
					T t = *(p + j);
					*(p + j) = *(p + j + 1);
					*(p + j + 1) = t;
				}
			}
		}
	}
};
template<class T>
Sort<T>::Sort(int n) :number(n), p(new T[n])
{

}
template <typename T>
Sort<T>::~Sort()
{
}
template <typename T>
int Sort<T>::search(T t){
	sort();
	int min = 0;
	int max = number - 1 ;
	//’“÷–µ„
	
	int x = 0;
	//  —≠ª∑
	while (min<=max){
		x++;
		int mid = min + (max - min) / 2;
		if (t < *(p + mid))
			max = mid - 1;
		else if (t>*(p + mid))
			min = mid + 1;
		else
			return x;

	}
	return x;
}