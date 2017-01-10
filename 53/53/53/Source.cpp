#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxSubArray(vector<int>& nums) 
	{
		int max_val = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			nums[i] = max(nums[i], nums[i] + nums[i - 1]);
			max_val = max(max_val, nums[i]);
		}

		return max_val;
	}
};

int main()
{
	Solution s;
	return 0;
}