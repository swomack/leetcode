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

	
		
		int count = 1;
		int min_boundary = points[0].second;

		for (int i = 1; i < points.size(); i++)
		{
			pair<int, int> current = points[i];

			if (current.first > min_boundary)
			{
				count++;
				min_boundary = current.second;
			}
			else
			{
				min_boundary = min(min_boundary, current.second);
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