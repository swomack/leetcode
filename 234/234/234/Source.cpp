#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<ListNode*> nodes;

		ListNode* temp = head;
		while (temp)
		{
			nodes.push(temp);
			temp = temp->next;
		}

		int halfLength = nodes.size() / 2;
	
		while (halfLength--)
		{
			ListNode* rear = nodes.top();
			nodes.pop();

			if (rear->val != head->val)
				return false;

			head = head->next;
		}

		return true;
	}
};

int main()
{
	Solution s;
	return 0;
}