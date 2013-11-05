#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> dp(triangle.size());
		int lnrow = triangle.size();
		dp.assign(triangle[lnrow - 1].begin(), triangle[lnrow - 1].end());

		for(int irow = lnrow-2; irow >= 0; irow--)
		{	
			vector<int>& lrvRow = triangle[irow];
			for(int j = 0; j< lrvRow.size(); j ++)
			{
				dp[j] = lrvRow[j] + min(dp[j], dp[j + 1]);
			}
		}
		return dp[0];
    }
};


int main()
{
	return 0;
}