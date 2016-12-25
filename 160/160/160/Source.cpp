#include <iostream>
#include <cmath>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		int lengthA = 0;
		int lengthB = 0;

		ListNode* tempA = headA;

		while (tempA)
		{
			lengthA++;
			tempA = tempA->next;
		}

		ListNode* tempB = headB;
		while (tempB)
		{
			lengthB++;
			tempB = tempB->next;
		}

		int dist = abs(lengthA - lengthB);

		if (lengthB > lengthA)
		{
			ListNode* temp = headA;
			headA = headB;
			headB = temp;
		}

		while (dist)
		{
			headA = headA->next;
			dist--;
		}

		while (headA && headB && headA != headB)
		{
			headA = headA->next;
			headB = headB->next;
		}

		return headA;
	}
};

int main()
{
	Solution s;
	return 0;
}