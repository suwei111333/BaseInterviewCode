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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!root)
			return true;
		
		mbBalanced = true;
		int leftH = hHeight(root->left);
		int rightH = hHeight(root->right);

		if(mbBalanced && abs(leftH - rightH) > 1)
			mbBalanced = false;

		return mbBalanced;
    }

	int hHeight(TreeNode* root)
	{
		if(!root)
			return 0;
		
		int leftH = hHeight(root->left);
		int rightH = hHeight(root->right);

		if(abs(leftH - rightH) > 1)
			mbBalanced = false;

		return max(leftH, rightH) + 1;
	}

	bool mbBalanced;
};

int main()
{
	Solution mSolution;
	TreeNode* tree = new TreeNode(1);
	tree->right = new TreeNode(2);
	tree->right->right = new TreeNode(3);

	mSolution.isBalanced(tree);

	return 0;
}