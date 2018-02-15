#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// traverse the same way, if overlap, check the overlap count of the existing node
// if count is zero then take the intersection part and create a new node with it & insert and child of the existing node. Remove the intersected part from the exsiting node and the new range. Then add the new range as new node.
// if count is one then return false and dont insert
class MyCalendarTwo {
	struct booking {
		int start, end;
		int overlap;
		booking* left;
		booking* right;
	};

	booking* root;

public:
	MyCalendarTwo() {
		root = nullptr;
	}

	bool book(int start, int end) {
		return bookingTraverse(&root, start, --end);
	}

	bool bookingTraverse(booking** nodeRef, int start, int end)
	{
		if (*nodeRef == nullptr)
		{
			*nodeRef = new booking{ start, end, 0, nullptr, nullptr };
			return true;
		}

		if (doesOverlap(*nodeRef, start, end))
			return false;

		if ((*nodeRef)->start > end)
			return bookingTraverse(&((*nodeRef)->left), start, end);
		else
			return bookingTraverse(&((*nodeRef)->right), start, end);
	}

	bool doesOverlap(booking* book1, int start, int end)
	{
		if (book1->end >= start && book1->start <= end)
			return true;
		else if (book1->start <= end && book1->end >= start)
			return true;

		return false;

	}
};

/**
* Your MyCalendar object will be instantiated and called as such:
* MyCalendar obj = new MyCalendar();
* bool param_1 = obj.book(start,end);
*/

int main()
{
	MyCalendar calendar;
	return 0;
}