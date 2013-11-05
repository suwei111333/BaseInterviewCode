#include <iostream>
using namespace std;


class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n < 3) return 0;

		int result = 0;
		int lastMax = 0;
		int lastMaxIndex = -1;
		for(int i = 0; i< n; i++)
		{
			while(i + 1 < n && A[i] < A[i + 1])
			{
				i ++;
			}
			
			int high = min(lastMax, A[i]);
			
		}
    }
};


int main()
{
	return 0;
}