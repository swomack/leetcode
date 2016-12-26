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

	ListNode* removingNode(ListNode* node, int& n)
	{
		if (node->next == NULL)
			return NULL;

		ListNode* ret = removingNode(node->next, n);

		n--;

		if (n == 0)
			return node;

		return ret;

	}

	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* temp = head;
		ListNode* rem = removingNode(temp, n);

		if (rem == NULL)
			head = head->next;
		else
			rem->next = rem->next->next;

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}