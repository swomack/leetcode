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

		stack<Interval> s_ins;
		s_ins.push(intervals[0]);

		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start > s_ins.top().end)
				s_ins.push(intervals[i]);
			else
				s_ins.top().end = max(s_ins.top().end, intervals[i].end);
		}

		result.resize(s_ins.size());

		while (!s_ins.empty())
		{
			result[s_ins.size() - 1] = s_ins.top();
			s_ins.pop();
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}