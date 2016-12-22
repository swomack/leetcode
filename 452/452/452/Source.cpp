#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findMinArrowShots(vector<pair<int, int>>& points) 
	{
		if (points.empty())
			return 0;
		sort(points.begin(), points.end());

		vector<pair<int, int>> in_queue;
		in_queue.push_back(points[0]);
		int count = 1;

		for (int i = 1; i < points.size(); i++)
		{
			pair<int, int> current = points[i];

			bool insert = true;

			for (int j = 0; j < in_queue.size(); j++)
			{
				if (in_queue[j].second >= current.first)
					continue;

				insert = false;
				break;
			}

			if (insert)
				in_queue.push_back(current);
			else
			{
				count++;
				in_queue.clear();
				in_queue.push_back(current);
			}
		}

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}