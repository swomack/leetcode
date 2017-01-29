#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct sort_interval
{
	bool operator () (const Interval& lhs, const Interval& rhs)
	{
		if (lhs.start < rhs.start)
			return true;

		return false;
	}
};

class Solution 
{
public:
	vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> result;

		if (intervals.size() <= 0)
			return result;

		sort(intervals.begin(), intervals.end(), sort_interval());
		result.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); i++)
		{
			int last = result.size() - 1;
			if (intervals[i].start > result[last].end)
				result.push_back(intervals[i]);
			else
				result[last].end = max(result[last].end, intervals[i].end);
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}