#include <iostream>
#include <vector>
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
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		ListNode* head = new ListNode(0);
		ListNode* run = head;

		while (true)
		{
			int smallest = INT_MAX;
			int smallest_index = -1;


			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i] && lists[i]->val <= smallest)
				{
					smallest = lists[i]->val;
					smallest_index = i;
				}
			}


			if (smallest_index == -1)
				break;

			run->next = lists[smallest_index];
			lists[smallest_index] = lists[smallest_index]->next;
			run = run->next;
		}


		return head->next;
	}
};

int main()
{
	Solution s;
	return 0;
}