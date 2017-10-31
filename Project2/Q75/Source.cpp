#include<iostream>
using namespace std;
#include<vector>
#include<string>
vector<string> tree;
void inOrder(int i);
int main(){
	string s;
	while (cin>>s)
	{
		tree.push_back(s);
	}
	inOrder(1);
	
}
void inOrder(int n){
	if (n > tree.size())
		return;
	if (tree.at(n - 1) == "null")
		return;
	inOrder(2 * n);
	cout << tree.at(n-1)<<" ";
	inOrder(2 * n + 1);
}
