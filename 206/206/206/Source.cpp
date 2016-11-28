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

	ListNode* recursion(ListNode* prev, ListNode* next)
	{
		if (next->next == NULL)
		{
			ListNode* tail = next;
			next->next = prev;
			return tail;
		}

		ListNode* temp = recursion(next, next->next);

		next->next = prev;

		return temp;
	}

	ListNode* reverseList(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* temp = recursion(head, head->next);
		head->next = NULL;
		return temp;
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