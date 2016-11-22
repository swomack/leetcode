#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* detectCycle(ListNode *head)
	{
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && slow)
		{
			slow = slow->next;
			fast = fast->next ? (fast->next->next ? fast->next->next : NULL) : NULL;

			if (fast == slow)
				break;
		}

		if (!fast || !slow)
			return NULL;

		while (head != slow)
		{
			head = head->next;
			slow = slow->next;
		}

		return head;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(2);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = head;

	ListNode* res = s.detectCycle(head);

	getchar();
	return 0;
}