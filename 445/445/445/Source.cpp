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

	ListNode* reverse(ListNode* prev, ListNode* next)
	{
		if (next == NULL)
			return prev;

		ListNode* temp = reverse(next, next->next);

		next->next = prev;
		prev->next = NULL;

		return temp;

	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		if (l2 == NULL)
			return l1;

		if (l1 == NULL)
			return l2;

		l1 = reverse(l1, l1->next);
		l2 = reverse(l2, l2->next);

		int carry = 0;
		int sum = l1->val + l2->val;
		carry = sum / 10;
		sum %= 10;
		ListNode* res = new ListNode(sum);
		l1 = l1->next;
		l2 = l2->next;

		while (l1 && l2)
		{
			int sum = l1->val + l2->val + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1)
		{
			int sum = l1->val + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
			l1 = l1->next;
		}

		while (l2)
		{
			int sum = l2->val + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
			l2 = l2->next;
		}

		if (carry)
		{
			ListNode* node = new ListNode(carry);
			node->next = res;
			res = node;
		}
	
		return res;
	
	}
};

int main()
{
	Solution s;

	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(7);
	l2->next->next->next = new ListNode(8);

	ListNode* result = s.addTwoNumbers(l1, l2);

	return 0;
}