#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) 
	{
		int res = 0;

		if (timeSeries.size() <= 0)
			return res;
		
		for (int i = 0; i < timeSeries.size() - 1; i++)
		{
			res += min(duration, timeSeries[i + 1] - timeSeries[i]);
		}

		return res + duration;
	}
};


int main()
{
	Solution s;
	return 0;
}