#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s.empty())
			return 0;
		if(s.length() == 1)
			return s[0]> '0'? 1: 0;
		
		vector<int>  dp(s.length() + 1, -1);
		dp[s.length()] = 1;
		dp[s.length() - 1] = 1; 
		for(int i = s.length() - 2; i>= 0; i --)
		{
			dp[i] = dp[i + 1];
			if(dp[i] <= '2' && dp[i + 1] <= '6')
				dp[i] += dp[i+2];
		}
		return dp[0];
    }
};


int main()
{
	Solution mSolution;

	string s("12");
	mSolution.numDecodings(s);
	return 0;

}