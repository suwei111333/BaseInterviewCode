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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = -100000;
		int lCurrentSum = 0;
		hMaxPathSum(root, lCurrentSum, maxSum);

		return maxSum;
    }

	void hMaxPathSum(TreeNode *root, int& oCurrentSum, int& oMaxSum)
	{
		if(root == NULL)
		{
			oCurrentSum = 0;
			return;
		}

		int leftCurrentSum = 0;
		int rightCurrentSum = 0;
		hMaxPathSum(root->left, leftCurrentSum, oMaxSum);
		hMaxPathSum(root->right, rightCurrentSum, oMaxSum);

		oCurrentSum = max(root->val, max(root->val + leftCurrentSum, root->val + rightCurrentSum));
		oMaxSum = max(oMaxSum, max(oCurrentSum, root->val + leftCurrentSum + rightCurrentSum));
	}
};

int main()
{
	Solution mSolution;
	TreeNode *root = NULL;
	mSolution.maxPathSum(root);

	return 0;
}