#include <iostream>
#include <vector>

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

	vector<int> data;
	vector<int> back_up;

	int i;

	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) 
	{
		while (head)
		{
			data.push_back(head->val);
			back_up.push_back(head->val);
			head = head->next;
		}

		i = data.size() - 1;
	}

	/** Returns a random node's value. */
	int getRandom() 
	{
		if (i < 0)
		{
			i = data.size() - 1;

			for (int j = 0; j < data.size(); j++)
				data[j] = back_up[j];
		}
			

		int index = rand() % (i + 1);

		int ret = data[index];
		swap(&data[i], &data[index]);

		i--;

		return ret;
		
	}

	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
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