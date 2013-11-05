#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(s.length() <= 1) return false;

		stack<char> S;
		S.push('1');
		for(int i = 0; i< s.length(); i++)
		{
			switch(s[i])
			{
			case '(':
			case '[':
			case '{':
				S.push(s[i]);
				break;
			case ')':
				if(S.top() == '(')
					S.pop();
				else
					S.push(')');
				break;
			case ']':
				if(S.top() == '[')
					S.pop();
				else
					S.push(']');
				break;
			case '}':
				if(S.top() == '{')
					S.pop();
				else
					S.push('}');
				break;
			}
		}

		if(S.size() == 1)
			return true;
		else
			return false;
    }
};

int main()
{
	Solution mS;
	string input("[])");
	bool lb = mS.isValid(input);
	return 0;
}