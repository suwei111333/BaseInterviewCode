#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(s.empty()) return true;
		
		lowerCase(s);

		int len = s.size();
		int i = 0;
		int j = len -1;
		for(; i < j; i ++, j --)
		{
			while(!isOK(s[i]))
			{
				i ++;
				if(i >= j) break;
			}
			while(!isOK(s[j]))
			{
				j --;
				if(i >= j) break;
			}
			if(s[i] != s[j])
				return false;
		}
		
		return true;
    }

	void lowerCase(string& s)
	{
		for(int i = 0; i< s.size(); i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = 'a' + (s[i] - 'A');
			}
			else if(!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'))
				s[i] = '#';
		}
	}
	bool isOK(char a)
	{
		if(a >= 'a' && a <= 'z' || a >= '0' && a <= '9')
			return true;
		return false;
	}
};

int main()
{
	while(true)
	{
		Solution mSolution;
		string input;
		cin >> input;
		bool lb = mSolution.isPalindrome(input);
	}
	return 0;
}