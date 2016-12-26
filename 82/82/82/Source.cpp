#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		
		while (head && head->next && head->val == head->next->val)
		{
			while (head && head->next && head->val == head->next->val)
			{
				head = head->next;
			}

			head = head->next;
		}

		if (head == NULL || head->next == NULL)
			return head;
		

		ListNode* run = head;
		ListNode* prev = NULL;

		while (run && run->next)
		{
			if (run->val != run->next->val)
			{
				prev = run;
				run = run->next;
				continue;
			}

			while (run && run->next && run->val == run->next->val)
			{
				run = run->next;
			}

			run = run->next;
			prev->next = run;
		}

		return head;

	}
};

int main()
{
	return 0;
}