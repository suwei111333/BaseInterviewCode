#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int SLen = S.size() + 1;
		int TLen = T.size() + 1;
		if(SLen  < TLen)
			return 0;

        vector<vector<int> > dp(TLen);
		for(int i = 0; i< TLen; i++)
			dp[i].resize(SLen, 0);

		for(int i = 0; i< SLen; i++)
			dp[0][i] = 1;

		for(int iT = 1; iT < TLen; iT ++)
		{
			for(int iS = iT; iS < SLen; iS ++)
			{
				dp[iT][iS] = dp[iT][iS -1];
				if(S[iS - 1] == T[iT - 1])
				{
					dp[iT][iS] += dp[iT - 1][iS -1];
				}
			}
		}

		return dp[TLen - 1][SLen - 1];

    }


};

int main()
{
	Solution mSolution;
	
	string S("rabbbit");
	string T("rabbit");

	mSolution.numDistinct(S, T);

	return 0;
}