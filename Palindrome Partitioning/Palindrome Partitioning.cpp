#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string& s, int startpos, int endpos)
{
	int i = startpos;
	int j = endpos;
	for(; i<= j; i++, j--)
	{
		if(s[i] != s[j]) return false;
	}

	return true;

}
int GetLonggestPalindrome(string& s, int startPos)
{
	int len = s.length();
	int longgestLength = 1;
	for(int i = startPos + 1; i < len; i++)
	{
		if(isPalindrome(s, startPos, i))
		{
			longgestLength = i - startPos + 1;
		}
	}
	return longgestLength;
}

int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int len = s.length();
	if(len <= 1) return 0;
	
	int minCutNum = 0;
	int tmplength = 0;
	int startIndex = 0;
	while(startIndex < len)
	{
		tmplength = GetLonggestPalindrome( s, startIndex);
		startIndex += tmplength;
		minCutNum ++;
	}

	return minCutNum -1;
}

#define MAXLen 100
int minCutDP(string s)
{
    int len = s.size();
	bool lbIsPalindrome[MAXLen][MAXLen];
	int dp[MAXLen];

	for(int i = 0; i<=  len; i++)
		dp[i] = len - i;
	
	memset(lbIsPalindrome, 0, sizeof(bool) * MAXLen * MAXLen);

	for(int i = len - 1; i >= 0; i--)
	{
		for(int j = i; j < len; j ++)
		{
			if(s[i] == s[j] && (j - i < 2 || lbIsPalindrome[i + 1][j - 1]))
			{
				lbIsPalindrome[i][j] = true;
				dp[i] = min(dp[i], dp[j + 1] + 1);
			}
		}
	}

	return dp[0] - 1;

}

vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int len = s.size();
	bool lbIsPalindrome[MAXLen][MAXLen];
	vector<vector<vector<string> >> dp(len + 1);

	vector<string> tmpString;
	vector<string> ltmpString;
	//for(int i = len - 1; i>= 0; i--)
	//{	
	//	tmpString.insert(tmpString.begin(), string(&s[i], 1));
	//	dp[i].push_back(tmpString);
	//}
	memset(lbIsPalindrome, 0, sizeof(bool) * MAXLen * MAXLen);

	for(int i = 0; i< len; i++)
	{
		lbIsPalindrome[i][i] = true;
		if(i + 1 < len && s[i] == s[i + 1])
			lbIsPalindrome[i][i + 1] = true;

	}

	for(int i = len - 1; i >= 0; i--)
	{
		for(int j = i; j < len; j ++)
		{
			if(s[i] == s[j] && ((j - i < 2)||lbIsPalindrome[i + 1][j - 1]))
			{
				lbIsPalindrome[i][j] = true;
				//dp[i] = min(dp[i], dp[j + 1] + 1);
				if(dp[j + 1].empty())
				{
					vector<string> ltmpString;
					ltmpString.push_back(string(&s[i], j -i + 1));
					dp[i].push_back(ltmpString);
				}
				for(int k = 0; k < dp[j + 1].size(); k++)
				{
					vector<string> ltmpString;
					ltmpString.push_back(string(&s[i], j -i + 1));
					ltmpString.insert(ltmpString.end(), dp[j + 1][k].begin(), dp[j + 1][k].end());
					dp[i].push_back(ltmpString);
				}
			}
		}
	}
	return dp[0];
        
}


int main()
{
	while(true)
	{
		string inputstring;
		cin >> inputstring;
		cout << minCut(inputstring) << endl;
		//cout << minCutDP(inputstring) << endl;

		partition(inputstring);
	}
	return 0;
}