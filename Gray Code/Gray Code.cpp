#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		bool* lpbFlat = new bool[1<< n];
		memset(lpbFlat, 0, sizeof(bool)* (1<< n));

		vector<int> lvGrayCode;
		int lcurrentWord = 0;
		int lnNumGrayCode = 1 << n;
		while(lnNumGrayCode >0)
		{
			lnNumGrayCode--;
			lpbFlat[lcurrentWord] = true;
			lvGrayCode.push_back(lcurrentWord);
			for(int i = 0; i< n; i++)
			{
				int ltmpWord = lcurrentWord & (1 << i) ? lcurrentWord & (~(1<<i)): lcurrentWord | (1 << i);

				if(lpbFlat[ltmpWord] == false)
				{
					lcurrentWord = ltmpWord;
					break;
				}
			}
		}

		return lvGrayCode;
    }
};

int main()
{
	Solution mSolution;

	int n;
	while(cin >> n)
	{
		mSolution.grayCode(n);
	}
	return 0;
}