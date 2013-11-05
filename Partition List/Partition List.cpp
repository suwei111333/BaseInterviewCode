#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;

		ListNode* lessListHead = new ListNode(0);
		ListNode* MoreListHead = new ListNode(0);
		ListNode* lessListTail = lessListHead;
		ListNode* MoreListTail = MoreListHead;
		while(head)
		{
			if(head->val < x)
			{
				lessListTail->next = head;
				lessListTail = lessListTail->next;

			}
			else
			{
				MoreListTail->next = head;
				MoreListTail = MoreListTail->next;
			}
			head = head->next;
		}
		lessListTail->next = MoreListHead->next;
		MoreListTail->next = NULL;

		return lessListHead->next;
    }
};