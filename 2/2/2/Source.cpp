#include <iostream>


using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* result = new  ListNode(0);
		ListNode* traverse = result;
		ListNode* prev = NULL;
		int in_hand = 0;
		while (l1 || l2)
		{
			int val1 = 0;
			int val2 = 0;

			if (l1)
			{
				val1 = l1->val;
				l1 = l1->next;
			}

			if (l2)
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			
			int value = val1 + val2 + in_hand;
			in_hand = (int)(value / 10);
			value = value % 10;

			prev = traverse;
			traverse->val = value;
			traverse->next = new ListNode(0);
			traverse = traverse->next;
		}

		if (in_hand)
		{
			prev = traverse;
			traverse->val = in_hand;
			traverse->next = new ListNode(0);
			traverse = traverse->next;
		}

		if(prev)
			prev->next = NULL;
		return result;
	}
};

int main()
{
	ListNode* a = new ListNode(5);
	/*a->next = new ListNode(4);
	a->next->next = new ListNode(3);*/

	ListNode* b = new ListNode(5);
	//b->next = new ListNode(6);
	//b->next->next = new ListNode(4);

	Solution s;
	ListNode* pNode = s.addTwoNumbers(a, b);

	while (pNode)
	{
		cout << pNode->val;
		pNode = pNode->next;
	}
	cout << endl;
}