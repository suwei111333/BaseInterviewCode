#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
		if(!root)
			return result;
		
		TreeNode* lNode = root;
		stack<TreeNode*>  lStack;
		while(lNode || !lStack.empty())
		{
			while(lNode)
			{
				lStack.push(lNode);
				lNode = lNode->left;
			}

			if(!lStack.empty())
			{
				lNode = lStack.top();
				lStack.pop();
				result.push_back(lNode->val);
				lNode = lNode ->right;
			}
		}

		return result;
    }
};

int main()
{
	Solution mSolution;
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	mSolution.inorderTraversal(root);
	return 0;
}