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

	TreeNode* sortedListToBASTHelper(ListNode* start, ListNode* end)
	{

	}

	TreeNode* sortedListToBST(ListNode* head) 
	{
		if (head == NULL)
			return NULL;

		return sortedListToBASTHelper(head, NULL);
	}
};


int main()
{
	Solution s;
	return 0;
}