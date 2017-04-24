#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sums;
class Solution 
{
public:
	int findTargetSumWays(vector<int>& nums, int S) 
	{
		sums.clear();
		sums.push_back(nums[0]);
		sums.push_back(-nums[0]);

		return findTargetSumWays(nums, S, 1, sums);
	}

	int findTargetSumWays(vector<int>& nums, int S, int index, vector<int>& sums)
	{
		if (index >= nums.size())
		{
			int count = 0;

			for_each(sums.begin(), sums.end(), [&count, &S](int num) {
				if (num == S)
					count++;
			});

			return count;
		}


		int num = nums[index];
		int size = sums.size();
		for (int i = 0; i < size; i++)
		{
			sums[i] += num;
			sums.push_back(sums[i] - 2 * num);
		}

		return findTargetSumWays(nums, S, index + 1, sums);
	}
};

int main()
{
	Solution s;
	return 0;
}