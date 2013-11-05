#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 0) return vector<int>(2, -1);

		vector<int> lvRange(2, -1);	

		int L = 0, H = n;
		while(L < H)
		{
			int M = L + (H - L)/2;

			if(A[M] >= target)
			{
				if(A[M] == target)
					lvRange[0] = M;
				H = M;
			}
			else
			{
				L = M + 1;
			}
		}

		if(lvRange[0] == -1)
			return lvRange;

		L = lvRange[0], H = n;
		while(L < H)
		{
			int M = L + (H - L) /2;
			if(A[M] <= target)
			{
				if(A[M] == target)
					lvRange[1] = M;
				L = M + 1;
			}
			else
			{
				H = M;
			}
		}
		return lvRange;
    }	
};

int main()
{
	Solution mS;
	int A[] = {5, 7, 7, 8, 8, 10};
	int target = 4;
	vector<int> lvRange = mS.searchRange(A, sizeof(A)/sizeof(int), target);

	return 0;
}