#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	bool exist(vector<int>& permutes, int n)
	{
		for (int i = 0; i < permutes.size(); i++)
		{
			if (permutes[i] == n)
				return true;
		}

		return false;
	}

	void permute(vector<int>& nums, vector<int>& permutes, vector<vector<int>>& result)
	{
		if (nums.size() == permutes.size())
		{
			result.push_back(permutes);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!exist(permutes, nums[i]))
			{
				permutes.push_back(nums[i]);
				permute(nums, permutes, result);
				permutes.pop_back();
			}
		}

	}

	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> result;

		if (nums.size() <= 0)
			return result;

		vector<int> permutes;

		permute(nums, permutes, result);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}