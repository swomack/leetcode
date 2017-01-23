#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



class Solution 
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
	{
		if (nums.size() <= 0)
			return false;
		set<long long> s;

		s.insert((long long)nums[0]);

		for (int i = 0, j = 1; j < nums.size(); j++)
		{
			if (j - i > k)
			{
				s.erase((long long)nums[i]);
				i++;
			}

			set<long long>::iterator itlow1 = s.lower_bound((long long)t - (long long)nums[j]);
			set<long long>::iterator itlow2 = s.lower_bound((long long)nums[j] - (long long)t);

			if ((itlow1 != s.end() && abs(*(itlow1)-nums[j]) <= t) || (itlow2 != s.end() && abs(*(itlow2)-nums[j]) <= t))
				return true;

			s.insert((long long)nums[j]);
		}

		return false;
	}
};

int main()
{
	Solution s;
	return 0;
}