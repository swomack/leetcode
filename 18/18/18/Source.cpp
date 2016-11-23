#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> results;

		if (nums.size() < 4)
			return results;

		sort(nums.begin(), nums.end());

		// this is like 3 sum, except that the 3 sum loop will be runned for 4 sum

		// using four pointer O(n^3)
		for (int i = 0; i < nums.size() - 3;)
		{
			// just like 3sum
			for (int j = i + 1; j < nums.size() - 2;)
			{
				int start = j + 1;
				int end = nums.size() - 1;

				int rest_sum = target - nums[i] - nums[j];

				// sliding window - two sum (since sorted)
				while (start < end)
				{
					int this_sum = nums[start] + nums[end];
					if (this_sum == rest_sum)
					{
						vector<int> result;
						result.push_back(nums[i]);
						result.push_back(nums[j]);
						result.push_back(nums[start]);
						result.push_back(nums[end]);

						results.push_back(result);

						while (++start && start < end && nums[start] == nums[start - 1]);
						while (--end && start < end && nums[end] == nums[end + 1]);
					}
					else if (this_sum < rest_sum) // need to increase the left pointer
					{
						start++;
					}
					else
					{
						end--;
					}
				}

				while (++j && j < nums.size() - 2 && nums[j] == nums[j - 1]);
					
			}

			while (++i && i < nums.size() - 3 && nums[i] == nums[i - 1]);
		}
	
		
		return results;
	}
};

int main()
{
	Solution s;
	vector<int> param{1, 0, -1, 0, -2, 2};

	vector<vector<int>> res = s.fourSum(param, 0);

	getchar();
	return 0;
}