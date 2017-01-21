#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void permute(vector<int>& nums, vector<int>& permutes, vector<vector<int>>& result, vector<bool>& exists)
	{
		if (nums.size() == permutes.size())
		{
			result.push_back(permutes);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!exists[i])
			{
				exists[i] = true;
				permutes.push_back(nums[i]);
				permute(nums, permutes, result, exists);
				permutes.pop_back();
				exists[i] = false;
			}
		}

	}

	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> result;

		if (nums.size() <= 0)
			return result;

		vector<int> permutes;
		vector<bool> exists(nums.size());

		permute(nums, permutes, result, exists);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}