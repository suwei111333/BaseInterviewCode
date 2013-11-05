#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

	
	void hSubsets(vector<int>& S, int Index, vector<int> iResult)
	{
		if(Index >= S.size())
		{
			lvvFinalResult.push_back(iResult);
			return;
		}

		hSubsets(S, Index + 1, iResult);

		iResult.push_back(S[Index]);
		hSubsets(S, Index + 1, iResult);
	}

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		sort(S.begin(), S.end());
		lvvFinalResult.clear();
		if(S.empty()) return lvvFinalResult;
		
		vector<int> lvResult;
		hSubsets(S, 1, lvResult);

		lvResult.push_back(S[0]);
		hSubsets(S, 1, lvResult);
        
		return lvvFinalResult;
    }

	vector<vector<int> > lvvFinalResult;
};

int main()
{
	Solution mS;

	int a[] = {4, 1, 0};
	vector<int> S(a, a + sizeof(a)/sizeof(int));
	mS.subsets(S);
	return 0;
}