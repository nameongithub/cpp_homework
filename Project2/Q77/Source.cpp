#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isCorrect(string s);
bool checkTag(string s);
int main(){
	string s;
	getline(cin,s);
	if (isCorrect(s))
		cout << "True";
	else
		cout << "False";
	getchar();
}
bool isCorrect(string s){




	stack<string> start;
	
	
	int i = 0, length = s.length();
	while (i < length){
		if (s[i] == '<'){
			string tag = "";
			if ('!' == s[i + 1] && '-' == s[i + 2] && '-' == s[i + 3]) {
				i += 4;
				while ('-' != s[i] || '-' != s[i + 1] || '>' != s[i + 2]) i++;
				i += 3;
				continue;
			}
			if (s[i+1] == '/')
			{	i++;
			while (s[i+1] != '>')
				tag += s[++i];
			if (tag == start.top())
				start.pop();
			else
				return false;
			continue;
			}
			while (s[i+1]!= '>')
				tag += s[++i];
			if (!checkTag(tag))
				return false;
			start.push(tag);
		}
		else
			i++;	
	}
	return start.empty();
}
bool checkTag(string s){
	if (s.length()>9)
	{
		return false;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (!(s[i] <= 'Z'&&s[i] >= 'A'))
			return false;
	}
	return true;
}