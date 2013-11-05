#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(num.size() <= 1) return;
		
		int numLen = num.size();
		int i = 0;
		for(i = numLen - 1; i > 0; i--)
		{
			if(num[i - 1] < num[i])
			{
				for(int j = numLen -1; j >= 0; j--)
				{
					if(num[j] > num[i - 1])
					{
						swap(num[j], num[i - 1]);
						reverse(num.begin() + i, num.end());
						return;
					}
				}
			}
		}
		if(i == 0)
		{
			reverse(num.begin(), num.end());
		}
    }
};

int main()
{
	vector<int> input;
	for(int i = 0; i< 4; i++)
		input.push_back(i + 1);

	Solution mS;
	for(int j = 0; j< 26; j++)
	{
		for(int i =0; i< 4; i++)
			cout << input[i] << ' ';
		cout << endl;
		mS.nextPermutation(input);
	}
	/*
	do
	{
		for(int i =0; i< 4; i++)
			cout << input[i] << ' ';
		cout << endl;
	}while(std::next_permutation(input.begin(), input.end()));
	*/

	return 0;
}