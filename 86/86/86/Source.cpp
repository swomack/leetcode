#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* walk = head;
		ListNode* lesser = NULL;
		

		if (walk->val < x)
		{
			while (walk->next && walk->next->val < x)
			{
				walk = walk->next;
			}

			if (walk->next == NULL)
				return head;

			lesser = walk;
		}
		else
		{
			while (walk->next && walk->next->val >= x)
			{
				walk = walk->next;
			}

			if (walk->next == NULL)
				return head;

			ListNode* temp = walk->next;
			walk->next = temp->next;
			temp->next = head;
			head = temp;
			lesser = head;
		}
		

		while (walk->next)
		{
			if (walk->next->val < x)
			{
				ListNode* temp = walk->next;
				walk->next = temp->next;
				temp->next = lesser->next;
				lesser->next = temp;
				lesser = lesser->next;
			}
			else
			{
				walk = walk->next;
			}
		}

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}