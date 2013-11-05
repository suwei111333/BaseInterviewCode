#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	vector<bool* > dp;
	vector<bool* > flag;
	bool isMatch(const char *s, const char *p) {
	
		int slen = strlen(s);
		int plen = strlen(p);

		if(slen > 0 && plen > 0)
		{
			char sEnd =s[slen - 1];
			char pEnd = p[plen - 1];
			if(sEnd != '?' && sEnd != '*' && pEnd != '?' && pEnd != '*' && sEnd != pEnd)
				return false;
		}

		dp.clear();
		flag.clear();
		dp.resize(slen + 1, NULL);
		flag.resize(slen + 1, NULL);
		for(int i = 0; i< slen + 1; i++)
		{
			dp[i] = new bool[plen + 1];
			memset(dp[i], false, sizeof(bool)* (plen + 1));
			flag[i] = new bool[plen + 1];
			memset(flag[i], false, sizeof(bool)* (plen + 1));
		}

		return hisMatch(s, p, 0, 0);
	}
    bool hisMatch(const char *s, const char *p, int Si, int Pi) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(flag[Si][Pi])
			return dp[Si][Pi];
		if(s[Si] == '\0' && p[Pi] == '\0')
		{	
			flag[Si][Pi] = true;
			dp[Si][Pi] = true;
			return true;
		}
		if(s[Si] == '\0' || p[Pi] == '\0')
		{
			flag[Si][Pi] = true;
			dp[Si][Pi] = false;
			return false;
		}

		if(p[Pi] == '*')
		{
			if(p[Pi + 1] == '*')
			{	
				flag[Si][Pi] = true;
				dp[Si][Pi] = hisMatch(s, p, Si, Pi + 1);
				return dp[Si][Pi];
			}
			if(hisMatch(s, p, Si + 1, Pi + 1))
			{	
				flag[Si][Pi] = true;
				dp[Si][Pi] = true;
				return true;
			}
			if(hisMatch(s, p, Si + 1, Pi))
			{	
				flag[Si][Pi] = true;
				dp[Si][Pi] = true;
				return true;
			}
			if(hisMatch(s, p, Si, Pi+ 1))
			{	
				flag[Si][Pi] = true;
				dp[Si][Pi] = true;
				return true;
			}

			flag[Si][Pi] = true;
			return dp[Si][Pi] = false;
		}
		else if(p[Pi] == '?')
		{
			flag[Si][Pi] = true;
			dp[Si][Pi] = hisMatch(s, p, Si + 1, Pi + 1);
			return dp[Si][Pi];
		}
		else
		{
			flag[Si][Pi] = true;
			if(s[Si] != p[Pi])			
				return dp[Si][Pi] = false;

			return dp[Si][Pi] = hisMatch(s, p, Si + 1, Pi + 1 );
		}
    }
};

int main()
{
	string s = "bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa";
	string p = "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****";
	//while(cin >> s >> p)
	{
		Solution mS;
		cout << mS.isMatch(s.c_str(), p.c_str()) << endl;
	}
	return 0;
}