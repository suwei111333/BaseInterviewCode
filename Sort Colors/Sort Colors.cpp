#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int r = 0, w = 0, b = n -1;
		for(w = 0; w <= b;)
		{
			if(A[w] == 0)
			{
				swap(A[r++], A[w++]);
			}
			else if(A[w] == 2)
			{
				swap(A[b--], A[w]);
			}
			else
				w ++;
		}
	
		
    }
};

int main()
{
	Solution mS;

	int A[] = {2,2,2,1,2,1,0,0,1,2};
	mS.sortColors(A, sizeof(A)/sizeof(int));
	return 0;
}