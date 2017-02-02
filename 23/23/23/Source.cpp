#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		ListNode* head = new ListNode(0);

		priority_queue<int> q;

		for (int i = 0; i < lists.size(); i++)
		{
			while (lists[i])
			{
				q.push(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}


		while (!q.empty())
		{
			ListNode* k = new ListNode(q.top());
			q.pop();

			k->next = head->next;
			head->next = k;
		}

		return head->next;
	}
};

int main()
{
	Solution s;
	return 0;
}