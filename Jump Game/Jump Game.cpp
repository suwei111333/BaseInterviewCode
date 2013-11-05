#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //vector<bool> lvbFlag(n, 0);
		char* lvbFlag = new char[n];
		memset(lvbFlag, 0, sizeof(char)* n);
		lvbFlag[0] = true;
		for(int i = 0; i < n; i++)
		{
			if(!lvbFlag[i])
				continue;

			memset(lvbFlag + i + 1, 1, sizeof(char)* A[i]);
			//for(int j = 1; j<= A[i]; j++)
			//	lvbFlag[i + j] = true;

			if(lvbFlag[n - 1] != 0)
				return true;
		}

		return lvbFlag[n - 1] != 0;
    }
};

int main()
{
	Solution mS;
	int A[] = {2,1, 0, 0};
	bool lb = mS.canJump(A, sizeof(A)/sizeof(int));
	return 0;
}