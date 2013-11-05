/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        msum = 0;
		if(root)
			hsumNumbers(root, 0);
		
		return msum;
    }

	void hsumNumbers(TreeNode* lroot, int lsum)
	{
		if(lroot && lroot->left == NULL && lroot->right == NULL)
		{
			msum += (lsum* 10 + lroot->val);
			return;
		}

		if(lroot->left)
			hsumNumbers(lroot->left, lsum* 10 + lroot->val);
		if(lroot->right)
			hsumNumbers(lroot->right, lsum* 10 + lroot->val);
	}

	

	int msum;
};

int main()
{
	Solution lSolution;

	TreeNode* lroot = new TreeNode(1);

	lroot->left = new TreeNode(2);
	lroot->right = new TreeNode(3);
	cout << lSolution.sumNumbers(lroot);


	return 0;
}