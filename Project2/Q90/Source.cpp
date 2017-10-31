#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> stackForElement;
void ADD(int element);
void PRINT();
void REVERSE();
void REMOVEREPEAT(int element);
void DEL(int elemebt);
void SIZE();
struct  node
{
	int element;
	node* next = NULL;
};
node * header;
int main(){
	header = new node[1];
	header->element = 0;
	header->next = NULL;
	int length;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		string instruction;
		cin >> instruction;
		if (instruction == "ADD"){
			int number;
			cin >> number;
			ADD(number);
		}
		if (instruction == "SIZE"){
			SIZE();
		}
		if (instruction == "PRINT"){
			PRINT();
		}
		if (instruction == "REMOVEREPEAT"){
			int number;
			cin >> number;
			REMOVEREPEAT(number);
		}
		if ("DEL" == instruction){
			int number;
			cin >> number;
			DEL(number);
		}
		if ("REVERSE" == instruction){
			REVERSE();
		}
	}
}
void ADD(int element){
	node* newNode = new node[1];
	newNode->element = element;
	node * temple = header;
	while (temple->next != NULL)
		temple = temple->next;
	temple->next = newNode;
	header->element++;
}

void PRINT(){
	if (header->element==0)
	{
		cout << "NULL" << endl;
		return;
	}
	node* temple = header;
	for (int i = 0; i < header->element; i++)
	{
		temple = temple->next;
		if (i != header->element - 1)
			cout << temple->element << " ";
		else
			cout << temple->element << endl;
	}
}
void SIZE(){
	cout << header->element << endl;
}
void DEL(int x){
	node * temple = header;
	while (temple->next != NULL){
		if (temple->next->element==x)
		{
			temple->next = temple->next->next;
			header->element--;
			continue;
		}
		temple = temple->next;
	}
}
void REMOVEREPEAT(int number){
	int count = 0;
	node * temple = header;
	while (temple->next != NULL){
		temple = temple->next;
		if (temple->element == number)
			count++;
	}
	if (count <= 1)
		return;
	temple = header;
	while (temple->next != NULL&&count>1){
		if (temple->next->element == number)
		{
			temple->next = temple->next->next;
			header->element--;
			count--;
			continue;
		}
		temple = temple->next;
	}
}
void REVERSE(){
	if (header->element <= 1)
		return;
	node * itr = header;
	for (int i = 0; i < header->element; i++){
		itr = itr->next;
		stackForElement.push(itr->element);
	}
	header->element = 0;
	header->next = NULL;
	while (!stackForElement.empty()){
		ADD(stackForElement.top());
		stackForElement.pop();
	}
}