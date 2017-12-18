#include<iostream>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
bool isValid(string s);
int removeDuplicates(vector<int>& nums);
int masin(){
	string s;
	cin >> s;
	isValid(s);
	return 0;
}

bool isValid(string s){
	stack<char> st;
	
	s.substr(1, 1);
	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty())
			if (s[i] == ']' || s[i] == '}' || s[i] == ')')
				return false;
			else
				st.push(s[i]);
		else{
			switch (s[i])
			{
			case ']': if (st.top() == '[')
							st.pop();
					  else
						  return false;
				break;
			case '}':if (st.top() == '{')
							st.pop();
					 else
						 return false; 
				break;
			case ')':
				if (st.top() == '(')
					st.pop();
				else
					return false;
				break;
			default:
				st.push(s[i])	;
			}
		}	
	}
	return true;

}
int removeDuplicates(vector<int>& nums){
	if (nums.size() == 0) return 0;
	int i = 0;
	for (int j = 1; j < nums.size(); j++) {
		if (nums[j] != nums[i]) {
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}