#include <iostream>
using namespace std;


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 0) return 0;
		
		if(n == 1)
			return target <= A[0]? 0: 1;

		int L = 0, H = n;
		while(L < H)
		{
			int M = L + (H - L)/2;
			if(A[M] == target)
				return M;
			else if(A[M] < target)
				L = M + 1;
			else 
				H = M;
		}

		return H;
    }
};

int main()
{
	Solution mS;
	int A[] = {1};
	int target = 0;
	int a = mS.searchInsert(A, sizeof(A)/sizeof(int), target);

	return 0;
}