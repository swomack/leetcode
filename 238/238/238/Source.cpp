#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		if (nums.size() < 2)
			return nums;

		vector<int> result(nums.size());

		result[0] = nums[0];

		for (int i = 1; i < nums.size(); i++)
			result[i] = result[i - 1] * nums[i];

		result[nums.size() - 1] = result[nums.size() - 2];

		for (int i = nums.size() - 2; i > 0; i--)
		{
			result[i] = result[i - 1] * nums[i + 1];
			nums[i] *= nums[i + 1];
		}

		result[0] = nums[1];

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,2,3,4 };
	vector<int> res = s.productExceptSelf(param);
	return 0;
}