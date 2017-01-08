#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution 
{
public:

	int getClosest(int house_pos, vector<int>& heaters)
	{
		int start = 0;
		int end = heaters.size() - 1;

		int closest = INT_MAX;

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (heaters[middle] == house_pos)
			{
				closest = 0;
				break;
			}

			closest = min(closest, abs(heaters[middle] - house_pos));

			if (heaters[middle] > house_pos)
				end = middle - 1;
			else
				start = middle + 1;

		}

		return closest;
	}

	int findRadius(vector<int>& houses, vector<int>& heaters) 
	{
		sort(heaters.begin(), heaters.end());

		int radius = 0;

		for (int i = 0; i < houses.size(); i++)
		{
			radius = max(radius, getClosest(houses[i], heaters));
		}

		return radius;
	}
};

int main()
{
	Solution s;
	return 0;
}