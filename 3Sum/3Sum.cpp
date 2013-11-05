#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {

		if(num.empty()) return vector<vector<int> >();
		sort(num.begin(), num.end());

		int target = 0;
		int numLen = num.size();
		vector<vector<int> >  lvvFinalResult;
		vector<int> lvResult(3, num[0] - 10);
		for(int k = 0; k < numLen - 2; k++)
		{
			if(num[k] == lvResult[0]) continue;
			int i = k + 1, j = numLen - 1;
			while(i < j)
			{
				int a = num[i] + num[k] + num[j];
				if(a == target)
				{
					lvResult[0] = num[k];
					lvResult[1] = num[i];
					lvResult[2] = num[j];
					lvvFinalResult.push_back(lvResult);

					//help to avoid duplicate result
					while(num[++i] == num[i - 1] && i < j);
					while(num[--j] == num[j + 1] && i < j);
					//i ++;
					//j --;
				}
				else if(a < target) i ++;
				else j --;
			}
		}
		return lvvFinalResult;

	}
};

int main()
{
	int S[] = {0, 0, 0};
	vector<int> number(S, S + sizeof(S)/sizeof(int));

	Solution mS;
	vector<vector<int> > result = mS.threeSum(number);

	return 0;
}