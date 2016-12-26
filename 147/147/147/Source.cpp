#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {

		ListNode* run = head;

		while (run && run->next)
		{
			if (run->next->val >= run->val)
			{
				run = run->next;
				continue;
			}

			
			ListNode* candidate = run->next;
			run->next = run->next->next;

			if (candidate->val < head->val)
			{
				candidate->next = head;
				head = candidate;
				continue;
			}

			ListNode* check = head;

			while (check->next)
			{
				if (check->next->val <= candidate->val)
				{
					check = check->next;
					continue;
				}
					

				candidate->next = check->next;
				check->next = candidate;
				break;
			}
		}

		return head;
	}
};

int main()
{
	Solution s;

	ListNode* head = new ListNode(4);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);

	head = s.insertionSortList(head);

	return 0;
}