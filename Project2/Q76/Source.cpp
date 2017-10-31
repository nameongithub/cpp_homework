#include<iostream>
#include<string>

using namespace std;
string trim(string s);
string add(string op1, string op2);
void print(string number);
int main(){
	string s1,s2;
	string op1 = "", op2 = "";
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
		if (s1.at(i) <= '9'&&s1.at(i) >= '0')
			op1 += s1[i];
	for (int i = 0; i < s2.length(); i++)
		if (s2.at(i) <= '9'&&s2.at(i) >= '0')
			op2 += s2[i];
	
	string answer = add(op1, op2);
	answer = trim(answer);
	print(answer);
	
	
}
string trim(string s){
	int i = 0;
	while (s[i]=='0')
	{
		i++;
	}
	return s.substr(i);
}
string add(string op1, string op2){
	int carry = 0;
	int minLength = op1.length() > op2.length() ? op2.length() : op1.length();
	string answer = "";
	for (int  i = 0; i < minLength ; i++)
	{
		int a = op1.at(op1.length() - i - 1) - '0';
		int b = op2.at(op2.length() - i - 1) - '0';
		answer = (char)((a + b + carry) % 10 + '0') + answer;
		carry = (a + b + carry) / 10;
	}
	if (op1.length()==op2.length()&&carry>0)
	{
		answer = (char)(carry + '0') + answer;
	}
	if (op1.length()<op2.length())
	{
		for (int i = 0; i < op2.length() - minLength; i++)
		{
			int b = op2.at(op2.length() - minLength - i - 1) - '0';
			answer = (char)((b + carry) % 10 + '0') + answer;
			carry = (b + carry) / 10;
		}
		if (carry>0)
		{
			answer = (char)(carry + '0') + answer;
		}
	}

	if (op1.length() > op2.length()){
		for (int i = 0; i < op1.length() - minLength; i++)
		{
			int b = op1.at(op1.length() - minLength - i - 1) - '0';
			answer = (char)((b + carry) % 10 + '0') + answer;
			carry = (b + carry) / 10;
		}
		if (carry>0)
		{
			answer = (char)(carry + '0') + answer;
		}
	}
	
	return answer;
}
void print(string number){
	for (int i = 0; i < number.length(); i++)
	{
		cout << number[i] << ">";
	}
	cout << "null";
}