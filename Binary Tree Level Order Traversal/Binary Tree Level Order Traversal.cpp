#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
		vector<vector<int> > lvvLevelOrder;
		if(!root)
			return lvvLevelOrder;

		queue<TreeNode*> lNodeQueue;
		queue<int> lLevelQueue;
		lNodeQueue.push(root);
		lLevelQueue.push(0);
		while(!lLevelQueue.empty())
		{
			TreeNode* lNode = lNodeQueue.front();   lNodeQueue.pop();
			int level = lLevelQueue.front(); lLevelQueue.pop();

			if(level >= lvvLevelOrder.size())
			{
				lvvLevelOrder.resize(level + 1);
			}

			lvvLevelOrder[level].push_back(lNode->val);

			if(lNode->left)
			{
				lNodeQueue.push(lNode->left);
				lLevelQueue.push(level + 1);
			}
			if(lNode->right)
			{
				lNodeQueue.push(lNode->right);
				lLevelQueue.push(level + 1);
			}
		}
		
		return lvvLevelOrder;
        
    }

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > lvvLevelOrder = levelOrder(root);
		for(int i = 1; i < lvvLevelOrder.size(); i+=2)
			reverse(lvvLevelOrder[i].begin(), lvvLevelOrder[i].end());

		return lvvLevelOrder;
    }
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > lvvLevelOrder = levelOrder(root);
		reverse(lvvLevelOrder.begin(), lvvLevelOrder.end());

		return lvvLevelOrder;	    
    }
};

int main()
{
	return 0;
}