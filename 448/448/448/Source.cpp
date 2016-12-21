#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1; 
			nums[index] = nums[index] > 0 ? -nums[index] : nums[index]; // negate to indicate that this position has appropriate item
		}

		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0) 
				res.push_back(i + 1);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 4,3,2,7,8,2,3,1 };
	vector<int> res = s.findDisappearedNumbers(param);
	return 0;
}