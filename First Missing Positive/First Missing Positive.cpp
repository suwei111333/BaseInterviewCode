#include <iostream>
using namespace std;

class Solution  {
public:
    int firstMissingPositive(int A[], int n) {

		//move all the A[i] to the right place
		//for example A[] = {3, 2, 5};
		//after this A[] = {5, 2, 3}
		//move 3 to A[2]
		//move 2 to A[1]
		//5 is not in the range, so need to move.
        for (int i=0; i<n; ++i)
        {
            if (A[i] > 0 && A[i] < n)
            {
                if (A[i]-1 != i && A[A[i]-1] != A[i])
                {
                    int temp = A[A[i]-1];
                    A[A[i]-1] = A[i];
                    A[i] = temp;
                    --i;
                }
            }
        }

		//after move all the A[i] to the right place
		//check each A[i] - 1 == i
        for (int j=0; j<n; ++j)
            if (A[j]-1 != j)
               return j+1;

        return n+1; 
   }
};

int main()
{

	Solution mS;
	int A[] = {0,11,15,3,4,5,6,7};
	int b = mS.firstMissingPositive(A, sizeof(A)/sizeof(int));

	return 0;
}