#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:

	double distance(pair<int, int> &a, pair<int, int> &b)
	{
		return sqrtf((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	}

	int numberOfBoomerangs(vector<pair<int, int>>& points) 
	{
		unordered_map<double, int> count;

		for (int i = 0; i < points.size() - 1; i++)
		{
			for (int j = i + 1; j < points.size(); j++)
			{
				count[distance(points[i], points[j])]++;
			}
		}
	}
};


int main()
{
	Solution s;
	return 0;
}