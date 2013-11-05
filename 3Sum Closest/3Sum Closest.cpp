#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int numlen = num.size();
		
		assert(numlen >= 0);
		sort(num.begin(), num.end());

		int result = num[0] + num[1] + num[2];
		for(int k = 0; k< numlen -2; k++)
		{
			int i = k + 1, j = numlen - 1;
			while(i < j)
			{
				int a = num[k] + num[i] + num[j];
				if(a == target)
					return target;
				else if(a < target)
					i ++;
				else 
					j --;
				
				if(abs(result - target) > abs(a - target))
				{
					result = a;
				}

			}
		}
		
		return result;

	}
};

int main()
{
	int S[] = {1,1,1,0};
	int target = -100;
	vector<int> number(S, S + sizeof(S)/sizeof(int));

	Solution mS;
	int result = mS.threeSumClosest(number, target);
	return 0;
}