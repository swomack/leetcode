#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;

		ListNode* temp = head;
		reorder(temp, temp->next);
	}

	ListNode* reorder(ListNode* head, ListNode* tail)
	{
		if (tail->next == NULL)
		{
			if (head->next == tail)
			{
				tail->next = NULL;
				return head;
			}
			else
			{
				tail->next = head->next;
				head->next = tail;
				return tail->next;
			}
		}

		head = reorder(head, tail->next);

		if (head == NULL)
			return head;

		if (head == tail || head->next == tail)
			tail->next = NULL;
		else
		{
			tail->next = head->next;
			head->next = tail;
		}

		return tail->next;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	
	Solution s;

	s.reorderList(head);

	return 0;
}