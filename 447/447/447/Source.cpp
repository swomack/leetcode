#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int distance(pair<int, int> p1, pair<int, int> p2)
	{
		return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
	}

	int numberOfBoomerangs(vector<pair<int, int>>& points) 
	{
		int count = 0;
		for (int i = 0; i < points.size() - 2; i++)
		{
			for (int j = i + 1; j < points.size() - 1; j++)
			{
				for (int k = j + 1; k < points.size(); k++)
				{
					int distance1 = distance(points[i], points[j]);
					int distance2 = distance(points[i], points[k]);
					int distance3 = distance(points[j], points[k]);

					if (distance1 == distance2 || distance1 == distance3 || distance3 == distance2)
						count += 2;
				}
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