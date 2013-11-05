#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	 ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!head) return NULL;

		ListNode* dummyNode = new ListNode(head->val - 1);
		dummyNode->next = head;

		ListNode* lastSegmentNode = dummyNode;
		ListNode* lastNode = lastSegmentNode->next;
		ListNode* CurNode = lastSegmentNode->next;
		while(CurNode)
		{
			CurNode = CurNode->next;
			bool lbDuplicate = false;
			while(CurNode && CurNode->val == lastNode->val)
			{
				lbDuplicate = true;
				CurNode = CurNode->next;
			}
			if(lbDuplicate)
			{
				lastSegmentNode->next = CurNode;
				lastNode = CurNode;
			}
			else
			{
				lastSegmentNode = lastNode;
				lastNode = CurNode;
			}
		}

		return dummyNode->next;
        
    }

    ListNode *deleteDuplicates1(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!head) return NULL;

		ListNode* lastNode = head;
		ListNode* tmpNode = head;
		tmpNode= tmpNode->next;
		while(tmpNode)
		{
			if(tmpNode->val == lastNode->val)
			{
				lastNode->next = tmpNode->next;
				tmpNode = tmpNode->next;
			}
			else
			{
				lastNode = tmpNode;
				tmpNode = tmpNode->next;
			}
		}
        return head;
    }
};

int main()
{
	int a[] = {0,1,1};
	ListNode* input = new ListNode(a[0]);
	ListNode* tmp = input;
	for(int i = 1; i< sizeof(a)/sizeof(int); i++)
	{
		tmp->next = new ListNode(a[i]);
		tmp = tmp->next;
	}

	Solution mSolution;
	input = mSolution.deleteDuplicates(input);

	return 0;
}