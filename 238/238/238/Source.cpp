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

		vector<int> p1(nums.size());
		vector<int> p2(nums.size());

		p1[0] = nums[0];

		for (int i = 1; i < p1.size(); i++)
			p1[i] = nums[i] * p1[i - 1];

		p2[p2.size() - 1] = nums[p2.size() - 1];
		for (int i = p2.size() - 2; i >= 0; i--)
			p2[i] = nums[i] * p2[i + 1];

		nums[0] = p2[1];
		nums[nums.size() - 1] = p1[nums.size() - 2];
		for (int i = 1; i < nums.size() - 1; i++)
			nums[i] = p1[i - 1] * p2[i + 1];

		return nums;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,2,3,4 };
	vector<int> res = s.productExceptSelf(param);
	return 0;
}