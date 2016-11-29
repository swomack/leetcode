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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL && l2 == NULL)
			return NULL;
		else if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;

		if (l2->val < l1->val)
		{
			ListNode* temp = l1;
			l1 = l2;
			l2 = temp;
		}

		ListNode* result = l1;

		while (l1->next && l2)
		{
			if (l1->next->val > l2->val)
			{
				ListNode* temp = l2->next;
				l2->next = l1->next;
				l1->next = l2;
				l2 = temp;
			}

			l1 = l1->next;
		}

		if (l1->next == NULL)
			l1->next = l2;

		return result;
	}
};

int main()
{
	return 0;
}