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

	ListNode* reverse(ListNode* prev, ListNode* next, int count, int m, int n)
	{
		if (count < m)
		{
			prev->next = reverse(next, next->next, count + 1, m, n);
			return prev;
		}
		else if (count >= m && count < n)
		{
			ListNode* ret = reverse(next, next->next, count + 1, m, n);

			prev->next = next->next;
			next->next = prev;

			return ret;

		}
		else
		{
			return prev;
		}
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		head = reverse(head, head->next, 1, m, n);

		return head;

	}
};


int main()
{
	Solution s;
	return 0;
}
