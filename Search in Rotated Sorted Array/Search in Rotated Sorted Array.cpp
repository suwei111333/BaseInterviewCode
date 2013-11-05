#include <iostream>
using namespace std;


class Solution {
public:

	bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0)
			return false;

		int L = 0;
		int H = n - 1;
		int M = 0;
		while(L <= H)
		{
			M = L + (H - L)/2;
			if(target == A[M])
				return true;

			if(A[L] < A[M])
			{
				if(target >= A[L] && target < A[M])
				{
					H = M -1;
				}
				else
					L = M + 1;
			}
			else if(A[M] < A[L])
			{	
				if(target > A[M] && target <= A[H])
					L = M + 1;
				else
					H = M - 1;

			}
			else L ++;
		}
		return false;
        
    }
    int search1(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0)
			return -1;

		int L = 0;
		int H = n - 1;
		int M = 0;
		while(L <= H)
		{
			M = L + (H - L)/2;
			if(target == A[M])
				return M;

			if(A[L] <= A[M])
			{
				if(target >= A[L] && target < A[M])
				{
					H = M -1;
				}
				else
					L = M + 1;
			}
			else
			{	
				if(target > A[M] && target <= A[H])
					L = M + 1;
				else
					H = M - 1;

			}
		}
		return -1;
        
    }

};

int main()
{
	int a[] = {3,1};
	Solution mSolution;

	bool pos = mSolution.search(a, sizeof(a)/sizeof(int), 1);

	return 0;
}