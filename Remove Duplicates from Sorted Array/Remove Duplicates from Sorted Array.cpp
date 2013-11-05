#include <iostream>
using namespace std;


class Solution {
public:
	int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!n) return n;
		
		int lnTarget = 0;
		int level = 1;
		int lnSource = 1;
		while(lnSource < n)
		{
			if(A[lnSource] != A[lnTarget])
			{
				A[++lnTarget] = A[lnSource];
				level = 1;
			}
			else
			{
				if(level == 1)
				{
					A[++lnTarget] = A[lnSource];
					level ++;
				}
			}
			lnSource ++;
		}
		
		return lnTarget + 1;
        
    }

    int removeDuplicates1(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return n;

		int lnTarget = 0;
		int lnSource = 0;
		while(lnSource < n)
		{
			if(A[lnSource] != A[lnTarget])
			{
				A[++lnTarget] = A[lnSource];
			}

			lnSource ++;
		}

		return lnTarget + 1;

    }
};

int main()
{
	int a[] = {1,1,1, 2,2, 3,3,3,3,4};
	Solution mSolution;

	int len = mSolution.removeDuplicates(a, sizeof(a)/sizeof(int));
	return 0;
}