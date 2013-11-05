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
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return catalan(n);
    }

	int catalan(int n)
	{	 // = C(n, 2n)/(n + 1)
		long long base = 1;
		for(int i = 1; i<= n; i++)
			base *= i;

		long long child = 1;
		for(int i = n + 1; i<= 2*n; i++)
			child *= i;

		child /= base;
		return child /(n + 1);

	}

	vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        // If the range is invalid, then return an empty tree
        if (start > end)
		{
			vector<TreeNode* > lvEmpty(1);
			lvEmpty[0] = NULL;
			return lvEmpty;
		}
        vector<TreeNode *> result;
        for (int i = start; i <= end; ++i) {
            // Generate all possible left subtrees (including the empty subtree)
            vector<TreeNode *> leftSubtrees = generateTrees(start, i - 1);

            // Generate all possible right subtrees (including the empty subtree)
            vector<TreeNode *> rightSubtrees = generateTrees(i + 1, end);

            // For each left subtree and each right subtree, create a root node
            // with value i and then link the two subtrees to the root
            for (int j = 0; j < leftSubtrees.size(); ++j) {
                for (int k = 0; k < rightSubtrees.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};


int main()
{
	Solution mSolution;
	int n = 0;
	while(cin >> n)
	{	cout << mSolution.numTrees(n) << endl;
		vector<TreeNode *> lvTrees = mSolution.generateTrees(n);
		int j = 10;
	}
	return 0;
}