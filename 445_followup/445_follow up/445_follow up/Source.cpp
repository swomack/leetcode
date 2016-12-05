#include <iostream>
#include <stack>


using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (l2 == NULL)
			return l1;

		if (l1 == NULL)
			return l2;

		
		stack<int> a;
		stack<int> b;

		while (l1)
		{
			a.push(l1->val);
			l1 = l1->next;
		}

		while (l2)
		{
			b.push(l2->val);
			l2 = l2->next;
		}



		int carry = 0;
		int sum = a.top() + b.top();
		carry = sum / 10;
		sum %= 10;
		ListNode* res = new ListNode(sum);
		
		a.pop();
		b.pop();

		while (!a.empty() && !b.empty())
		{
			int sum = a.top() + b.top() + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;

			a.pop();
			b.pop();
		}

		while (!a.empty())
		{
			int sum = a.top() + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;

			a.pop();
		}

		while (!b.empty())
		{
			int sum = b.top() + carry;
			carry = sum / 10;
			sum %= 10;

			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;

			b.pop();
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