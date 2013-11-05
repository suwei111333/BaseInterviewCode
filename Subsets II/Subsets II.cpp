#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> lmMap;
		for(int i = 0; i< S.size(); i++)
		{
			if(lmMap.find(S[i]) == lmMap.end())
			{
				lmMap[S[i]] = 1;
			}
			else
			{
				lmMap[S[i]] ++;
			}
		}
		vector<int> lvKey;
		vector<int> lvTimes;
		for(map<int, int>::iterator iter = lmMap.begin(); iter != lmMap.end(); iter ++)
		{
			lvKey.push_back(iter->first);
			lvTimes.push_back(iter->second);
		}
		
		vector<vector<int> > lvvResult;
		vector<int> lvResult;
		hSubsetsWithDup(lvKey, lvTimes, 0, lvResult, lvvResult);

		return lvvResult;
    }

	void hSubsetsWithDup(vector<int>& irvKey, vector<int>& irvTimes, int level, 
		vector<int> ivResult, vector<vector<int> >& iorvvFinalResult)
	{
		if(level >= irvKey.size())
		{
			iorvvFinalResult.push_back(ivResult);
			return;
		}

		hSubsetsWithDup(irvKey, irvTimes, level + 1, ivResult, iorvvFinalResult);

		for(int i = 0; i< irvTimes[level]; i++)
		{
			ivResult.push_back(irvKey[level]);
			hSubsetsWithDup(irvKey, irvTimes, level + 1, ivResult, iorvvFinalResult);	
		}
	}
};

int main()
{
	Solution mSolution;

	int S[] = {};
	vector<int> input(S, S + sizeof(S)/sizeof(int));
	mSolution.subsetsWithDup(input);

	return 0;
}