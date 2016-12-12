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

	ListNode* swapPairsHelper(ListNode* prev)
	{
		if (!prev)
			return prev;

		ListNode* next = prev->next;

		if (!next)
			return prev;

		prev->next = next->next;
		next->next = prev;

		prev->next = swapPairsHelper(prev->next);

		return next;

	}
	
	ListNode* swapPairs(ListNode* head) 
	{
		return swapPairsHelper(head);
	}
};

int main()
{
	Solution s;
	return 0;
}