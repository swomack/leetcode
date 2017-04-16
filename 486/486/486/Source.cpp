#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool PredictTheWinner(vector<int>& nums) 
	{
		int size = nums.size();

		int total_val = 0;

		for_each(nums.begin(), nums.end(), [&total_val](int val) {
			total_val += val;
		});

		vector<vector<int>> dp(size, vector<int>(size, -1));

		dp[0][size - 1] = calculateOnesSum(nums, 0, size - 1, dp, 1);




		return dp[0][size - 1] * 2 >= total_val;
	}

	int calculateOnesSum(vector<int>& nums, int begin, int end, vector<vector<int>>& dp, int turn)
	{
		if (begin > end)
			return 0;

		if (begin == end && turn == 1)
			return nums[begin];
		else if (begin == end && turn == 2)
			return 0;


		if (dp[begin][end] != -1)
			return dp[begin][end];

		if (turn == 1)
		{
			dp[begin + 1][end] = calculateOnesSum(nums, begin + 1, end, dp, 2);
			dp[begin][end - 1] = calculateOnesSum(nums, begin, end - 1, dp, 2);

			return max(dp[begin + 1][end] + nums[begin], dp[begin][end - 1] + nums[end]);
		}

		dp[begin + 1][end] = calculateOnesSum(nums, begin + 1, end, dp, 1);
		dp[begin][end - 1] = calculateOnesSum(nums, begin, end - 1, dp, 1);

		return min(dp[begin + 1][end], dp[begin][end - 1]);
	}
};

int main()
{
	vector<int> a{1, 5, 2};
	Solution s;

	bool res = s.PredictTheWinner(a);

	return 0;
}