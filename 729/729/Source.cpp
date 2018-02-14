#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCalendar {
	struct booking {
		int start, end;
	} ;

	vector<booking> bookings;

public:
	MyCalendar() {
		bookings.clear();
	}

	bool book(int start, int end) {

		end--;

		for (auto element : bookings)
		{
			if (doesOverlap(element, { start, end }))
				return false;
		}

		bookings.push_back({ start, end});
		return true;
	}

	bool doesOverlap(const booking& book1, const booking& book2)
	{
		if (book1.end >= book2.start && book1.start <= book2.start)
			return true;
		else if (book1.start <= book2.end && book1.end >= book2.start)
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