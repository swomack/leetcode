#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	int length;
	
	ListNode* sortList(ListNode* head) 
	{
		return mergeSort(head);
	}


	ListNode* mergeSort(ListNode* a)
	{
		if (a == NULL || a->next == NULL)
			return a;

		
		ListNode* mid_node = getMid(a);

		ListNode* b = mid_node->next;
		mid_node->next = NULL;

		a = mergeSort(a);
		b = mergeSort(b);

		ListNode* head = merge(a, b);
		return head;
	}

	ListNode* getMid(ListNode* a)
	{
		ListNode* slow = a;
		ListNode* fast = a;
		while (fast && fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		
		return slow;
	}

	ListNode* merge(ListNode* a, ListNode* b)
	{
		ListNode *head = new ListNode(-1);

		ListNode* run = head;

		while (a && b)
		{
			if (a->val < b->val)
			{
				run->next = a;
				a = a->next;
			}
			else
			{
				run->next = b;
				b = b->next;
			}

			run = run->next;
		}

		if (a)
		{
			while (a)
			{
				run->next = a;
				run = run->next;
				a = a->next;
			}
		}

		if (b)
		{
			while (b)
			{
				run->next = b;
				run = run->next;
				b = b->next;
			}
		}

		run->next = NULL;
		return head->next;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);

	ListNode* res = s.sortList(head);

	return 0;
}