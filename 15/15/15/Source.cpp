#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> results;

		if (nums.size() < 3)
			return results;

		sort(nums.begin(), nums.end());

		for (int k = 0; k < nums.size();)
		{
			int target = 0 - nums[k];

			// just like 2 sum now
			for (int i = k + 1, j = nums.size() - 1; i < j;)
			{
				int sum = nums[i] + nums[j];
				if (sum == target)
				{
					vector<int> res;
					res.push_back(nums[k]);
					res.push_back(nums[i]);
					res.push_back(nums[j]);

					results.push_back(res);

					while (++i && i < j && nums[i] == nums[i - 1]);
					while (--j && j > i && nums[j] == nums[j + 1]);
				}
				else if (sum < target)
				{
					i++;
				}
				else
				{
					j--;
				}
			}

			while (++k && k < nums.size() && nums[k] == nums[k - 1]);

		}

		return results;
		
	}
};

int main()
{
	Solution s;

	vector<int> param{ -2,0,1,1,2 };

	vector<vector<int>> result = s.threeSum(param);

	getchar();
	return 0;
}