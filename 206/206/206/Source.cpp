#include <iostream>
#include <stack>

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
	ListNode* reverseList(ListNode* head) 
	{
		stack<int> rev_stack;

		ListNode* temp = head;

		while (head)
		{
			rev_stack.push(head->val);
			head = head->next;
		}


		head = temp;

		while (!rev_stack.empty())
		{
			temp->val = rev_stack.top();
			rev_stack.pop();
			temp = temp->next;
		}

		return head;

	}
};

int main()
{
	Solution s;

	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);

	ListNode* rev = s.reverseList(root);

	return 0;
}