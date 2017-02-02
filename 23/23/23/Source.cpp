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

	ListNode* mergeTwo(ListNode* head1, ListNode* head2)
	{
		ListNode* head = new ListNode(0);
		ListNode* tail = head;

		while (head1 && head2)
		{
			if (head1->val < head2->val)
			{
				tail->next = head1;
				head1 = head1->next;
			}
			else
			{
				tail->next = head2;
				head2 = head2->next;
			}

			tail = tail->next;
		}


		while (head1)
		{
			tail->next = head1;
			head1 = head1->next;
			tail = tail->next;
		}

		while (head2)
		{
			tail->next = head2;
			head2 = head2->next;
			tail = tail->next;
		}

		return head->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.size() == 0)
			return NULL;
		while (lists.size() > 1)
		{
			lists[lists.size() - 2] = mergeTwo(lists[lists.size() - 2], lists[lists.size() - 1]);
			lists.pop_back();
		}

		return lists[0];
	}
};

int main()
{
	Solution s;
	return 0;
}