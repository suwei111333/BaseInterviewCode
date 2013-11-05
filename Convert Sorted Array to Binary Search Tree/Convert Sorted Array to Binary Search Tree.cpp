#include <iostream>
#include <vector>
using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
		{
			return NULL;
		}
		
		TreeNode* root = hCreateBST(num, 0, num.size());
		return root;
    }

	TreeNode* hCreateBST(vector<int> &num, int start, int end)
	{
		if(start >= end)
			return NULL;

		int mid = start + (end - start)/2;
		TreeNode* parent = new TreeNode(num[mid]);
		parent->left = hCreateBST(num, start, mid);
		parent->right = hCreateBST(num, mid + 1, end);
		return parent;
	}
};

int main()
{
	Solution mSolution;

	int a[] = {1,2,3,4,5,6};
	vector<int> input(a, a + sizeof(a)/sizeof(int)); 

	mSolution.sortedArrayToBST(input);
	return 0;
}