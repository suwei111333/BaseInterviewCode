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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		TreeNode *LastNode = NULL;
		if(root == NULL)
			return;
        hFlatten(root, &LastNode);
    }

	void hFlatten(TreeNode* root, TreeNode** LastNode)
	{

		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		
		TreeNode* leftTreeLastNode = root;
		if(leftNode)
		{
			hFlatten(leftNode, &leftTreeLastNode);
			root->right = leftNode;
		}
		root->left = NULL;

		TreeNode* rightTreeLastNode = leftTreeLastNode;
		if(rightNode)
		{
			hFlatten(rightNode, &rightTreeLastNode);

			if(leftTreeLastNode)
			{
				leftTreeLastNode->right = rightNode;
			}
		}
		*LastNode = rightTreeLastNode;
	}
};


int main()
{
	Solution mSolution;

	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(2);
	tree->right = new TreeNode(3);


	mSolution.flatten(tree);

	return 0;
}