#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	int length;
	ListNode* list_head;
	ListNode* sortList(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		list_head = head;
		ListNode* temp = head;
		length = 0;
		while (temp->next)
		{
			length++;
			temp = temp->next;
		}

		quickSort(head, temp, 0, length);

		return list_head;
	}

	void quickSort(ListNode* start, ListNode* end, int start_index, int end_index)
	{
		if (start_index >= end_index)
			return;

		int pivot_offset = floor(rand() % (end_index - start_index + 1));
		pivot_offset = partition(start, end, pivot_offset);

		if (pivot_offset == 0)
		{
			quickSort(start->next, end, start_index + 1, end_index);
		}
		else
		{
			ListNode* pivot = start;
			int midpoint = pivot_offset;
			while (pivot_offset - 1)
			{
				pivot_offset--;
				pivot = pivot->next;
			}

			quickSort(start, pivot, start_index, start_index + midpoint - 1);

			if(start_index + midpoint + 1 <= end_index)
				quickSort(pivot->next->next, end, start_index + midpoint + 1, end_index);
		}
	}

	int partition(ListNode* start, ListNode* end, int pivot_index)
	{
		ListNode* pivot_node = start;
		while (pivot_index--)
		{
			pivot_node = pivot_node->next;
		}

		swap(end, pivot_node);

		ListNode* temp = start;

		int less_equal = 0;
		while(temp != end)
		{
			if (temp->val <= end->val)
			{
				swap(start, temp);
				start = start->next;
				less_equal++;
			}

			temp = temp->next;
		}

		swap(start, end);

		return less_equal;
	}

	void swap(ListNode* a, ListNode* b)
	{
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);

	ListNode* res = s.sortList(head);

	return 0;
}