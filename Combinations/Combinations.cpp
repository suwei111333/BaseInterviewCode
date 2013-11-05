#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		lvvFinalResult.clear();
		if(n == 0) return lvvFinalResult;

		vector<int> S;
		for(int i = 0; i< n; i++)
			S.push_back(i + 1);

		vector<int> lvResult;
		hSubsets(S, 1, k,  lvResult);

		lvResult.push_back(S[0]);
		hSubsets(S, 1, k - 1, lvResult);
        
		return lvvFinalResult;
    }

	void hSubsets(vector<int>& S, int Index, int Level, vector<int> iResult)
	{
		if(Level <= 0)
		{
			lvvFinalResult.push_back(iResult);
			return;
		}
		if(Index >= S.size())
			return;

		hSubsets(S, Index + 1, Level, iResult);

		iResult.push_back(S[Index]);
		hSubsets(S, Index + 1, Level - 1, iResult);
	}

	vector<vector<int> > lvvFinalResult;
};

int main()
{
	Solution mS;

	mS.combine(4, 2);
	return 0;
}
