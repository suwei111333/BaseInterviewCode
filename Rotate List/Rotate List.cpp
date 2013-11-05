#include <iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k == 0) return head;

		int Listlen = 1;
		ListNode* LastNode = head;
		while(LastNode->next)
		{
			Listlen ++;
			LastNode = LastNode->next;
		}

		if(Listlen == 1 || k % Listlen == 0) return head;

		k = k% Listlen;
		k = Listlen - k;
		while(k --)
		{
			ListNode* CurNode = head;
			head = head->next;
			LastNode->next = CurNode;
			LastNode = CurNode;
			CurNode->next = NULL;
		}
		return head;
    }
};

int main()
{
	return 0;
}

