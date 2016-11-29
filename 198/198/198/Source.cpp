#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int rob(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;

		if (nums.size() == 1)
			return nums[0];

		nums[1] = nums[0] > nums[1] ? nums[0] : nums[1];

		for (int i = 2; i < nums.size(); i++)
			nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);

		return nums[nums.size() - 1];
	}
};

int main()
{
	Solution s;

	vector<int> param{};

	int res = s.rob(param);

	return 0;
}