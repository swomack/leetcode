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
	ListNode* removeElements(ListNode* head, int val) 
	{
		while (head && head->val == val)
			head = head->next;

		ListNode* temp = head;
		ListNode* prev = temp;

		while (temp)
		{
			if (temp->val == val)
			{
				prev->next = temp->next;
				temp = temp->next;
				continue;
			}

			prev = temp;
			temp = temp->next;
		}

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}