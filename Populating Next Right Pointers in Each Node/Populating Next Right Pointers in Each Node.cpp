#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		queue<TreeLinkNode*> lNodeQueue;
		queue<int> lLevelQueue;

		if(root == NULL || (root->left == NULL && root->right == NULL))
			return;

		lNodeQueue.push(root);
		lLevelQueue.push(0);
		TreeLinkNode* lastNode = NULL;
		int LastLevel = 0;
		while(!lNodeQueue.empty())
		{
			TreeLinkNode* lpCurrentNode = lNodeQueue.front();
			int level = lLevelQueue.front();
			lNodeQueue.pop();
			lLevelQueue.pop();
			
			if(lastNode != NULL && LastLevel == level)
			{
					lastNode->next = lpCurrentNode;
			}

			lastNode = lpCurrentNode;
			LastLevel = level;


			if(lpCurrentNode->left)
			{
				lNodeQueue.push(lpCurrentNode->left);
				lLevelQueue.push(level + 1);
			}

			if(lpCurrentNode->right)
			{
				lNodeQueue.push(lpCurrentNode->right);
				lLevelQueue.push(level + 1);
			}
		}
		
        
    }
};

int main()
{
	return 0;
}