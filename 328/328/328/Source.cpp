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
	ListNode* oddEvenList(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* odd_prev = head;
		ListNode* odd_next = head->next->next;
		ListNode* even_first = head->next;
		ListNode* even_last = head->next;

		while (odd_next)
		{
			odd_prev->next = odd_next;
			even_last->next = odd_next->next;
			even_last = even_last->next;
			odd_next->next = even_first;
			odd_prev = odd_next;

			if (even_last == NULL)
				break;

			odd_next = even_last->next;

		}

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}