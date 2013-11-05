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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL)
		{
			return 0;
		}

		
		if(sum == root->val && root->left == NULL && root->right == NULL)
			return true;

		sum -= root->val;

		if(root->left && hasPathSum(root->left, sum))
			return true;
		if(root->right && hasPathSum(root->right, sum))
			return true;
		
		return false;
    }

	vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<vector<int> > lvvFinalResult;
		vector<int>  lvTempResult;
		
		int level = 0;
		hPathSum(root, sum, lvTempResult, level, lvvFinalResult);
        
		return lvvFinalResult;
    }

	void hPathSum(TreeNode* root, int sum, vector<int>& irvTempResult, int level, vector<vector<int>>& orvvFinalResult)
	{
		if(root == NULL) return;

		if(sum == root->val && root->left == NULL && root->right == NULL)
		{
			irvTempResult.resize(level + 1);
			irvTempResult[level] = root->val;
			orvvFinalResult.push_back(vector<int>(irvTempResult.begin(), irvTempResult.end()));
			return;
		}

		sum -= root->val;
		irvTempResult.resize(level + 1);
		irvTempResult[level] = root->val;

		if(root->left)
		{
			 hPathSum(root->left, sum, irvTempResult, level + 1, orvvFinalResult);
		}
		if(root->right)
		{
			hPathSum(root->right, sum, irvTempResult, level + 1, orvvFinalResult);
		}
	}
};



int main()
{
	TreeNode* tree = new TreeNode(-2);
	//tree->left = new TreeNode(4);
	tree->right = new TreeNode(-3);
	//tree->left->left = new TreeNode(11);
	//tree->left->left->left = new TreeNode(7);
	//tree->left->left->right = new TreeNode(2);
	//tree->right->left = new TreeNode(13);
	//tree->right->right = new TreeNode(4);

	Solution mSolution;
	//bool lb = mSolution.hasPathSum(tree, -5);

	vector<vector<int> >  lvvResult = mSolution.pathSum(tree, -5);

	return 0;

}