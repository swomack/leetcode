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
			lesser = walk;

		while (walk->next)
		{
			if (walk->next->val < x)
			{
				if (lesser == walk)
				{
					walk = walk->next;
					lesser = lesser->next;
				}
				else if (lesser == NULL)
				{
					ListNode* temp = walk->next;
					walk->next = temp->next;
					temp->next = head;
					head = temp;
					lesser = head;
				}
				else
				{
					ListNode* temp = walk->next;
					walk->next = temp->next;
					temp->next = lesser->next;
					lesser->next = temp;
					lesser = lesser->next;
				}
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