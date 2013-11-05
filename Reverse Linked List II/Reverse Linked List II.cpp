#include <iostream>
#include <vector>
#include <string>
using namespace std;


 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummy(0);

		dummy.next = head;
		ListNode* PreM, *Pre = &dummy;
		for(int i = 1; i<= n; i++)
		{
			if(i == m) PreM = Pre;

			if(i > m && i <= n)
			{
				Pre->next = head->next;
				head->next = PreM->next;
				PreM->next = head;
				head = Pre;
			}
			Pre = head;
			head = head->next;
		}

		return dummy.next;
    }
};

int main()
{
	return 0;
}