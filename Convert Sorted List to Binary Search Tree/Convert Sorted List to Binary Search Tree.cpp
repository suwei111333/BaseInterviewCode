#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
	};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
		
		int len = 0;
		ListNode* tmpNode = head;
		while(tmpNode)
		{
			len ++;
			tmpNode = tmpNode->next;
		}
		TreeNode* root = hCreateBST(head, 0, len-1);
		
		return root;
    }

	TreeNode* hCreateBST(ListNode *&head, int start, int end)
	{
		if(start> end)
		{
			return NULL;
		}
		int mid = start + (end - start)/2;
		TreeNode* leftTree = hCreateBST(head, start, mid -1);
		TreeNode* Parent = new TreeNode(head->val);
		Parent->left = leftTree;
		head = head->next;
		Parent->right = hCreateBST(head, mid+ 1, end);

		return Parent;
	}
};

int main()
{
	Solution mSolution;
	
	ListNode* list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	list->next->next->next = new ListNode(4);
	list->next->next->next->next = new ListNode(5);

	mSolution.sortedListToBST(list);

	return 0;
}