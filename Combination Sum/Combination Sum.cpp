#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(target <= 0) return vector<vector<int> >();


		lvvResult.clear();

		map<int, int> lvMap;
		for(int i = 0; i< num.size(); i++)
		{
			if(lvMap.find(num[i]) == lvMap.end())
				lvMap[num[i]] = 1;
			else
				lvMap[num[i]] ++;
		}

		vector<int> lvCount(lvMap.size());
		vector<int> lvNumber(lvMap.size());
		int i = 0;
		for(map<int, int>::iterator iter = lvMap.begin(); iter != lvMap.end();i ++, iter ++)
		{
			lvCount[i] = iter->second;
			lvNumber[i] = iter->first;
		}

		vector<int> lvTmpResult;
		hCombinationSum2(lvCount, lvNumber, 0, lvTmpResult, target);

		return lvvResult;   
    }

	void hCombinationSum2(vector<int>& lvCount, vector<int>& lvNumber, int index, 
		vector<int> lvTmpeResult, int target)
	{
		if(target == 0)
		{
			lvvResult.push_back(lvTmpeResult);
			return ;
		}

		if(target < 0) return;

		if(index >= lvCount.size()) return;

		int count = lvCount[index];
		int num = lvNumber[index];
		hCombinationSum2(lvCount, lvNumber, index + 1,  lvTmpeResult, target);
		
		for(int i = 1; i * num <= target && i <= count; i++ )
		{
			lvTmpeResult.push_back(num);
			hCombinationSum2(lvCount, lvNumber, index + 1,  lvTmpeResult, target - i * num);
		}
	}


    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(target <= 0 ) return vector<vector<int> >();

		lvvResult.clear();;
		
		sort(candidates.begin(), candidates.end());
		vector<int> tmpResult;

		hCombinationSum(candidates, 0, tmpResult, target);

		return lvvResult;
    }

	void hCombinationSum(vector<int>& candidates, int index, vector<int> ivTmpResult, int target)
	{
		if(target == 0)
		{
			lvvResult.push_back(ivTmpResult);
			return;
		}
		
		if(target < 0) return;
		if(index >= candidates.size()) return;

		hCombinationSum(candidates, index + 1, ivTmpResult, target);

		for(int i = 1; i * candidates[index] <= target; i++)
		{
			ivTmpResult.push_back(candidates[index]);
			hCombinationSum(candidates, index + 1, ivTmpResult, target - i* candidates[index]);
		}
	}

	vector<vector<int> > lvvResult;
};

int main()
{
	int A[] = {10,1,2,7,6,1,5};
	vector<int> B(A, A + sizeof(A)/sizeof(int));

	Solution mS;
	vector<vector<int> > C = mS.combinationSum2(B, 8);
	
	return 0;
}