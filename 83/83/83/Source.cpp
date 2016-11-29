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
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if (head == NULL)
			return head;

		ListNode* result = head;
		ListNode* next_unique = head;

		while (head)
		{
			while (next_unique && head->val == next_unique->val)
			{
				next_unique = next_unique->next;
			}

			head->next = next_unique;
			head = next_unique;
		}

		return result;
		
	}
};

int main()
{
	return 0;
}