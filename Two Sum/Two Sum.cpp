#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class compera
{
public:
	vector<int>& mV;
	compera(vector<int>& irV):mV(irV)
	{}
	bool operator()(int a, int b)
	{
		return mV[a] < mV[b];
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if(numbers.empty()) return vector<int>();
		
		vector<int> lvRowMap(numbers.size());
		for(int i = 0; i< numbers.size(); i++)
			lvRowMap[i] = i;

		compera lComp(numbers);
		sort(lvRowMap.begin(), lvRowMap.end(), lComp);

		int numlen = numbers.size();
		int i = 0, j = numlen -1;
		while(i < j)
		{
			int a = numbers[lvRowMap[i]] + numbers[lvRowMap[j]];
			if(a == target)
				break;
			else if(a < target)
				i ++;
			else
				j --;
		}

		vector<int> result;
		if(i < j)
		{
			result.push_back(lvRowMap[i] + 1);
			result.push_back(lvRowMap[j] + 1);
			if(result[0] > result[1]) swap(result[0], result[1]);
			return result;
		}
		else
		{
			return result;
		}
    }
};

int main()
{
	int a[] = {150,24,79,50,88,345,3};
	int target = 200;
	vector<int> numbers(a, a + sizeof(a)/sizeof(int));
	Solution mS;
	vector<int> result = mS.twoSum(numbers, target);
	
	return 0;
}