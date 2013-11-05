#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	void putResult(vector<vector<int> >& lvvResult, vector<int>& lvTmp)
	{
		int lnResult = lvvResult.size();
		for(int i = 0; i< lnResult; i++)
		{
			vector<int>& lRResult = lvvResult[i];
			if(lRResult[0] == lvTmp[0] &&
				lRResult[1] == lvTmp[1] &&
				lRResult[2] == lvTmp[2] &&
				lRResult[3] == lvTmp[3])
				return;
		}
		lvvResult.push_back(lvTmp);
	}
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(num.size() < 4) return vector<vector<int> >();
		
		sort(num.begin(), num.end());

		int numlen = num.size();
		vector<vector<int> > lvvResult;
		vector<int> ltmpResult(4);
		for(int x = 0; x< numlen - 3; x++)
		{
			for(int y = x + 1; y < numlen - 2; y ++)
			{
				int i = y + 1, j = numlen -1;
				while(i < j)
				{
					int a = num[x] + num[y] + num[i] + num[j];
					if(a == target)
					{
						ltmpResult[0] = num[x];
						ltmpResult[1] = num[y];
						ltmpResult[2] = num[i];
						ltmpResult[3] = num[j];
						//lvvResult.push_back(ltmpResult);
						putResult(lvvResult, ltmpResult);
						i ++;
						j --;
					}
					else if(a < target) i ++;
					else j --;
				}
			}
		}

		return lvvResult;
    }
};

int main()
{
	int A[] = {-3,-2,-1,0,0,1,2,3};
	vector<int> num(A, A + sizeof(A)/sizeof(int));
	int target = 0;
	Solution mS;
	mS.fourSum(num, target);

	return 0;
}