#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > lvFinalResult;
		if(!n) return lvFinalResult;

		vector<string> lvStmpResult(n, string(n, '.'));

		hSolveNQueens(n, 0, lvStmpResult, lvFinalResult);

		return lvFinalResult;
    }

	void hSolveNQueens(int n, int level, vector<string>& irvTmpResult, vector<vector<string> >& orvvFinalResult)
	{
		if(level >= n)
		{
			orvvFinalResult.push_back(irvTmpResult);
			return ;
		}

		for(int i = 0; i< n; i++)
		{
			if(isOK(irvTmpResult, level, i))
			{
				irvTmpResult[level][i] = 'Q';
				hSolveNQueens(n, level + 1, irvTmpResult, orvvFinalResult);
				irvTmpResult[level][i] = '.';
			}
		}
	}

	bool isOK(vector<string>& irvTmpResult, int level, int i)
	{
		int n = irvTmpResult.size();
		for(int j = 0; j< level; j++)
		{
			if(irvTmpResult[j][i] == 'Q')
				return false;
			
			int left = i - (level - j);
			if(left >= 0 && irvTmpResult[j][left] == 'Q')
				return false;
			int right = i + (level - j);
			if(right < n && irvTmpResult[j][right] == 'Q')
				return false;
		}
		return true;
	}
};


int main()
{
	Solution mS;
	int n;
	while(cin >> n)
	{
		mS.solveNQueens(n);
	}

	return 0;
}