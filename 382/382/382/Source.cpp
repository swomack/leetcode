#include <iostream>


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:

	ListNode* fixed;
	ListNode* running;

	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) 
	{
		fixed = running = head;
	}

	/** Returns a random node's value. */
	int getRandom() 
	{
		if (running == NULL)
			running = fixed;

		int ret = running->val;
		running = running->next;

		return ret;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

int main()
{
	Solution s(new ListNode(5));
	return 0;
}