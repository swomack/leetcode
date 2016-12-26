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
		
		stack<ListNode*> nodes;

		while (temp)
		{
			nodes.push(temp);
			temp = temp->next;
		}


		while (n--)
		{
			nodes.pop();
		}

		ListNode* prev = NULL;
		
		if(!nodes.empty())
			prev = nodes.top();

		if (prev == NULL)
			head = head->next;
		else if (prev != NULL)
			prev->next = prev->next->next;

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}