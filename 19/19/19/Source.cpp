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
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* temp = head;
		
		while (n--)
		{
			temp = temp->next;
		}

		if (temp == NULL)
			return head->next;

		temp = temp->next;
		ListNode* temp2 = head;

		while (temp)
		{
			temp = temp->next;
			temp2 = temp2->next;
		}

		temp2->next = temp2->next->next;

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}