#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode* reverse(ListNode* rev)
	{
		ListNode* run = rev->next;

		ListNode* parent = rev;

		while (run)
		{
			rev->next = run->next;
			run->next = parent;
			parent = run;
			run = rev->next;
		}

		return parent;
	}

	bool isPalindrome(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return true;

		// calculate length
		int length = 0;
		ListNode* last = head;
		while (last)
		{
			length++;
			last = last->next;
		}

		// reverse after mid
		int midLength = ceil(length / 2.0);
		ListNode* mid = head;

		for (int i = 0; i < midLength - 1; i++)
		{
			mid = mid->next;
		}

		mid->next = reverse(mid->next);
		mid = mid->next;

		// check if palindrome
		int loop = length / 2;
		for (int i = 0; i < loop; i++)
		{
			if (head->val != mid->val)
				return false;

			head = head->next;
			mid = mid->next;
		}

		return true;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	/*head->next->next->next->next->next = new ListNode(6);*/

	bool res = s.isPalindrome(head);

	return 0;
}