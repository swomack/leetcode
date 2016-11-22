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
	bool hasCycle(ListNode *head)
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

		return fast && slow && fast == slow;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(2);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = head;

	bool res = s.hasCycle(head);

	getchar();
	return 0;
}