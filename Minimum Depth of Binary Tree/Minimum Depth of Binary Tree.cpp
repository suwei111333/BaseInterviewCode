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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
			return 0;
		mFinalmin  = 10000;
		int level = 1;
		hMinDepth(root, level);

		return mFinalmin;
    }

	void hMinDepth(TreeNode* root, int level)
	{
		if(root->left == NULL && root->right == NULL)
		{
			mFinalmin = min(level, mFinalmin);
			return;
		}

		if(level >= mFinalmin)
			return;

		if(root->left)
		{
			hMinDepth(root->left, level + 1);
		}
		if(root->right)
		{
			hMinDepth(root->right, level + 1);
		}
	}

	int mFinalmin;
};

int main()
{

	return 0;
}