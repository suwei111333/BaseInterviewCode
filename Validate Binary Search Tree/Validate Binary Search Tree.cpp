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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!root) return true;
		int MINValue = -100000;
		int MAXValue = 100000;
		return hIsValidBST(root->left, MINValue, root->val) 
			&& hIsValidBST(root->right, root->val, MAXValue);
        
    }

	bool hIsValidBST(TreeNode *root, int MinValue, int MaxValue)
	{
		if(!root)
			return true;

		if(!(root->val > MinValue && root->val < MaxValue))
			return false;

		if(!hIsValidBST(root->left, MinValue, root->val))
			return false;

		if(!hIsValidBST(root->right, root->val, MaxValue))
			return false;

		return true;
	}
};

int main()
{
	return 0;
}