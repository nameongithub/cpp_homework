#include<iostream>
#include<string>
using namespace std;
long long array[100];
long long temple[100];
int length;
void print(){
	for (int i = 0; i < length; i++)
	{
		if (i != length - 1)
			cout << array[i] << " ";
		else
			cout << array[i] << endl;

	}
}

void replace(long long a,long long b){
	for (int i = 0; i < length; i++)
	{
		if (array[i] == a)
			array[i] = b;
	}
}




void movetail(long long a){
	int count = 0;
	for (int i = 0; i < length; i++)
		if (array[i] == a){
			temple[length-1- count] = a;
			count++;
		}
	int size = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] != a){
			temple[size++] = array[i];
		}
	}
	for (int i = 0; i < length; i++)
	{
			array[i] = temple[i];
			temple[i] = 0;
	}
}

void movehead(long long a){
	int count = 0;
	for (int i = 0; i < length; i++)
		if (array[i] == a){
			temple[count++] = a;
		}
	for (int i = 0; i < length; i++)
	{
		if (array[i] != a){
			temple[count++] = array[i];
		}
	}
	for (int i = 0; i < length; i++)
	{
		array[i] = temple[i];
		temple[i] = 0;
	}
}
void transplateHead(int n){
	n = n % length;

	for (int i = 0; i < length -  n ; i++)
	{
		temple[i] = array[n + i];
	}
	
	for (int i = 0 ; i < n; i++)
	{
		temple[length - n + i] = array[i];
	}
	for (int i = 0; i < length; i++)
	{
		array[i] = temple[i];
		temple[i] = 0;
	}
}
void transplateTail(int n){
	n = n % length;
	for (int i = 0; i < n ; i++)
	{
		temple[i] = array[length - n + i];
	}
	for (int i = 0; i < length - n; i++)
	{
		temple[n + i] = array[i];
	}

	for (int i = 0; i < length; i++)
	{
		array[i] = temple[i];
		temple[i] = 0;
	}
}

int main(){
	
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	long long m;
	cin >> m;
	string instruction;
	string destination;
	long long a, b;
	int des;
	for (long long i = 0; i < m ; i++)
	{
		cin >> instruction;
		if (instruction == "print") print();
		else  if (instruction == "replace")
		{
			cin >> a >> b;
			replace(a, b);
		}
		else	if (instruction == "move")
		{ 
			cin >> destination>>des;
			if (destination == "head")
				movehead(des);
			else
				movetail(des);
		}
		else if (instruction == "translate")
		{
			cin >> destination >> des;
			if (destination == "head")
				transplateHead(des);
			else
				transplateTail(des);
			
		}
	}
	

}
