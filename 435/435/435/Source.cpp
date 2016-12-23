#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct comp
{
	bool operator() (const Interval& lhs, const Interval& rhs)
	{
		return lhs.start < rhs.start;
	}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {

		if (intervals.size() <= 0)
			return 0;

		sort(intervals.begin(), intervals.end(), comp());

		Interval min_boundary = intervals[0];
		int count = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			Interval int_val = intervals[i];

			if (int_val.end <= min_boundary.end)
			{
				count++;
				min_boundary = int_val;
				continue;
			}
			else if (int_val.start < min_boundary.end)
			{
				count++;
				continue;
			}

			min_boundary = int_val;
		}

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}