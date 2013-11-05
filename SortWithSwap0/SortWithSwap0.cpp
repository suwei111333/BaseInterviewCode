#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int loopSize(vector<int>& num)
	{
		int rel = 0;
		int tmp1 = num[0];
		int tmp2;
		num[0] = 0;
		while(tmp1 != 0)
		{
			tmp2 = num[tmp1];
			num[tmp1] = tmp1;
			tmp1 = tmp2;
			rel ++;
		}
		return rel;
	}
	int SortWithSwap0(vector<int>& num)
	{
		int rel = 0;
		int numlen = num.size();
		if(numlen < 2) return rel;
		
		for(int i = 0; i< numlen; i++)
		{
			if(num[i] != i && i != 0)
			{
				swap(num[i], num[0]);
				rel ++;
			}
			rel += loopSize(num);
		}
		
		return rel;
	}
};


int main()
{
	int a[] = {0, 4, 3, 2, 1};

	vector<int> num(a, a + sizeof(a)/sizeof(int));
	Solution mS;
	cout << mS.SortWithSwap0(num) << endl;
	return 0;
}