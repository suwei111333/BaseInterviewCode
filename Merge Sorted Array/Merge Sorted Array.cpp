#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int targetIndex = n + m -1;
		int AIndex = m -1;
		int BIndex = n -1;
		while(AIndex>= 0 && BIndex >=0)
		{
			if(A[AIndex] >= B[BIndex])
			{
				A[targetIndex] = A[AIndex];
				AIndex --;
			}
			else
			{
				A[targetIndex] = B[BIndex];
				BIndex --;
			}

			targetIndex --;
		}

		if(AIndex >= 0)
			return;

		while(BIndex >= 0)
		{
			A[targetIndex] = B[BIndex];
			targetIndex --;
			BIndex --;
		}
    }
};

int main()
{
	return 0;
}