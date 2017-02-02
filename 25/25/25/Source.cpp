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
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (k == 1)
			return head;

		int length = 0;
		ListNode* head_copy = head;

		while (head_copy != NULL && ++length)
			head_copy = head_copy->next;

		if (length == 0)
			return head;


		int round = length / k;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;
		while (round--)
		{
			ListNode* prev = head->next;
			ListNode* next = prev->next;

			for (int i = 1; i < k; i++)
			{
				ListNode* t = head->next;
				head->next = next;
				prev->next = next->next;
				next->next = t;
				next = prev->next;
			}

			head = prev;
		}

		return dummy->next;
	}
};

int main()
{
	Solution s;
	return 0;
}