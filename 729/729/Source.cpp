#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCalendar {
	struct booking {
		int start, end;
		booking* left;
		booking* right;
	} ;

	booking* root;

public:
	MyCalendar() {
		root = nullptr;
	}

	bool book(int start, int end) {
		return bookingTraverse(&root, start, --end);
	}

	bool bookingTraverse(booking** nodeRef, int start, int end)
	{
		if (*nodeRef == nullptr)
		{
			*nodeRef = new booking {start, end, nullptr, nullptr};
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