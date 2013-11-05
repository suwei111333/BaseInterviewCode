#include <iostream>
#include <vector>
#include <string>
using namespace std;

string MaxIP("256");
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> lvResult;
		if(s.size() < 4) return lvResult;
		
		string ltempResult;
		hRestoreIpAddresses(s, 0, s.length(), 0, ltempResult, lvResult);
		
		return lvResult;
    }

	void hRestoreIpAddresses(string& s, int start, int end, int level, string iTempResult, vector<string>& orvResult)
	{
		if(start >= end && level >= 4)
		{
			orvResult.push_back(iTempResult);
			return;
		}

		if(start >= end || level >= 4)
			return;

		for(int i = start + 1; i <= end; i++)
		{
			if(isOK(s, start, i))
			{
				hRestoreIpAddresses(s, i, end, level + 1, iTempResult.empty()? string(s.begin() + start, s.begin() + i):iTempResult + "." + string(s.begin() + start, s.begin() + i), orvResult);
			}
		}
	}

	bool isOK(string& s, int start, int end)
	{
		if(start >= end) return false;

		if(end - start == 1)
			return true;

		if(end - start == 2) 
		{	
			if(s[start] == '0')
				return false;
			return true;
		}
		if(end - start > 3) return false;

		string tmp(s.begin() + start, s.begin() + end);
		
		if(tmp[0] == '0')
			return false;

		return tmp.compare(MaxIP) < 0;
	}

	
};

int main()
{
	string ip("010010");
	Solution mSolution;

	mSolution.restoreIpAddresses(ip);
	return 0;
}