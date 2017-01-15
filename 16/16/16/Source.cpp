#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(), nums.end());
		int shortest = nums[0] + nums[1] + nums[2];

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;

			int start = i + 1;
			int end = nums.size() - 1;

			while (start < end)
			{
				int sum = nums[i] + nums[start] + nums[end];

				if (abs(target - sum) < abs(target - shortest))
					shortest = sum;

				if (sum > target)
					end--;
				else
					start++;
			}
		}

		return shortest;
	}
};

int main()
{
	Solution s;
	vector<int> p{ 1,1,1,1 };

	return 0;
}