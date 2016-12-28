#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		int list_length = 1;
		ListNode* lc = head;

		while (lc->next)
		{
			lc = lc->next;
			list_length++;
		}

		k %= list_length;

		if (k == 0)
			return head;


		int move = list_length - k - 1;
	
		ListNode* new_last = head;
		while (move--)
		{
			new_last = new_last->next;
		}

		lc->next = head;
		head = new_last->next;
		new_last->next = NULL;

		return head;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);

	ListNode* sol = s.rotateRight(head, 2);

	return 0;
}