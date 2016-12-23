#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct comp
{
	bool operator () (pair<int, int> lhs, pair<int, int> rhs)
	{
		return lhs.first < rhs.first;
	}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals)
	{
		vector<int> result;

		if (intervals.size() <= 0)
			return result;

		
		
		vector<pair<int, int>> sorted_start(intervals.size());

		for (int i = 0; i < intervals.size(); i++)
		{
			sorted_start[i] = make_pair(intervals[i].start, i);
		}

		sort(sorted_start.begin(), sorted_start.end(), comp());


		for (int i = 0; i < intervals.size(); i++)
		{
			int find = intervals[i].end;

			int index = -1;

			int start = 0;
			int end = intervals.size() - 1;

			while (start <= end)
			{
				int middle = (start + end) / 2;

				int value = sorted_start[middle].first;

				if (value == find)
				{
					index = sorted_start[middle].second;
					break;
				}

				if (value > find)
				{
					index = sorted_start[middle].second;
					end = middle - 1;
				}
				else
				{
					start = middle + 1;
				}
			}

			result.push_back(index);
			
		}


		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}