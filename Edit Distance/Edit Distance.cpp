#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int word1len = word1.length();
		int word2len = word2.length();
		if(word1len == 0)
			return word2len;
		if(word2len == 0)
			return word1len;

		vector<vector<int> > dp(word1len + 1, vector<int>(word2len + 1, 0));
		for(int i = 0; i<= word2len; i++)
			dp[0][i] = i;
		for(int j = 0; j <= word1len; j ++)
			dp[j][0] = j;

		for(int i = 1; i<= word1len; i++)
		{
			for(int j = 1; j <= word2len; j++)
			{
				if(word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				}
			}
		}

		return dp[word1len][word2len];
        
    }
};


class Solution1 {
public:
	int minDistance(string word1, string word2) {
		int word1len = word1.length();
		int word2len = word2.length();
		if(word1len == 0)
			return word2len;
		if(word2len == 0)
			return word1len;
		dp.clear();
		dp.resize(word1len + 1, vector<int>(word2len  + 1, 0));

		return hMinDistance(word1, word1len, word2, word2len);

	}

	int hMinDistance(string& word1, int Index1, string& word2, int Index2)
	{
		if(Index1 == 0 && Index2 == 0)
			return 0;
		if(dp[Index1][Index2])
			return dp[Index1][Index2];

		if(Index1 == 0)
			return dp[Index1][Index2] = Index2;
		if(Index2 == 0)
			return dp[Index1][Index2] = Index1;

		if(word1[Index1 - 1] == word2[Index2 - 1])
			dp[Index1][Index2] = hMinDistance(word1, Index1 - 1, word2, Index2 - 1);
		else
		{
			int insert = hMinDistance(word1, Index1 -1, word2, Index2);
			int delet = hMinDistance(word1, Index1, word2, Index2 - 1);
			int replace = hMinDistance(word1, Index1 -1, word2, Index2 - 1);
			dp[Index1][Index2] = min(insert, min(delet, replace)) + 1;
		}

		return dp[Index1][Index2];
	}

	vector<vector<int> > dp;
};

int main()
{
	Solution1 mS;

	string a = "a";
	string b = "ab";
	int dis = mS.minDistance(a, b);

	return 0;
}