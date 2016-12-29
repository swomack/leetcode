#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* sortList(ListNode* head) 
	{
		vector<int> sorted_list;
		ListNode* temp = head;

		while (temp)
		{
			sorted_list.push_back(temp->val);
			temp = temp->next;
		}

		sort(sorted_list.begin(), sorted_list.end());

		temp = head;

		for (int i = 0; i < sorted_list.size(); i++)
		{
			temp->val = sorted_list[i];
			temp = temp->next;
		}

		return head;
	}
};

int main()
{
	Solution s;
	return 0;
}