#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int X = 0;
		int Y = -1000;
		for(int i = 0; i< n; i++)
		{
			X = max(X + A[i], A[i]);
			Y = max(Y, X);
		}
		return Y;
    }
};


int main()
{
	Solution mS;
	
	int A[] = {-2};

	int b = mS.maxSubArray(A, sizeof(A)/sizeof(int));
	return 0;
}