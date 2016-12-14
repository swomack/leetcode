#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	unordered_map<int, int> count;
	int combinationSum4(vector<int>& nums, int target)
	{
		count.clear();
		return combinationSumHelper(nums, target);
	}

	int combinationSumHelper(vector<int>& nums, int target)
	{
		int results = 0;

		if (target < 0)
			return results;

		if (count[target])
			return count[target];

		for (int i = 0; i < nums.size(); i++)
		{
			if (target - nums[i] == 0)
			{
				results++;
			}
			else
			{
				results += combinationSum4(nums, target - nums[i]);
			}

		}

		count[target] = results;

		return results;
	}

};

int main()
{
	Solution s;
	vector<int> param{ 4,2,1 };

	int res = s.combinationSum4(param, 7);

	return 0;
}