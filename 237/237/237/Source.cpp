#include <iostream>
#include <algorithm>

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
	void deleteNode(ListNode* node) 
	{
		if (!node || !node->next)
			return;

		node->val = node->next->val;
		ListNode* temp = node->next->next;
		delete node->next;
		node->next = temp;
	}
};

int main()
{
	Solution s;

	ListNode* root = new ListNode(1);
	root->next = new ListNode(3);
	root->next->next = new ListNode(5);

	s.deleteNode(root);

	getchar();
}