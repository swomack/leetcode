#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	TreeNode* sortedListToBSTHelper(ListNode* start, ListNode* end, int size)
	{
		if (size <= 0)
			return NULL;

		if (start == end)
			return new TreeNode(start->val);

		int middle = size / 2;
		int loop = middle;

		ListNode* temp = start;
		ListNode* prev = NULL;
		while (loop--)
		{
			prev = temp;
			temp = temp->next;
		}
			

		TreeNode* local_root = new TreeNode(temp->val);
		local_root->left = sortedListToBSTHelper(start, prev, middle);
		local_root->right = sortedListToBSTHelper(temp->next, end, size - middle - 1);

		return local_root;
	}

	TreeNode* sortedListToBST(ListNode* head) 
	{
		if (head == NULL)
			return NULL;

		ListNode* tail = head;
		int size = 1;
		while (tail->next != NULL)
		{
			tail = tail->next;
			size++;
		}
			

		return sortedListToBSTHelper(head, tail, size);
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

	TreeNode* t = s.sortedListToBST(head);

	return 0;
}