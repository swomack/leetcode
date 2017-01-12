#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

	int bin_search(vector<int>& a, int val)
	{
		int start = 0;
		int end = a.size() - 1;

		int ret = end;

		while (a[start] <= val && a[end] >= val && start < end - 1)
		{
			int middle = (start + end) / 2;

			if (a[middle] == val)
				return middle;

			if (a[middle] > val)
			{
				end = middle;
				ret = end;
			}
			else
				start = middle;
		}

		return ret;
	}

	int lengthOfLIS(vector<int>& nums)
	{
		if (nums.size() <= 0)
			return 0;

		vector<int> min_val_length_LIS;
		min_val_length_LIS.push_back(nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] <= min_val_length_LIS[0])
			{
				min_val_length_LIS[0] = nums[i];
				continue;
			}
			else if (nums[i] > min_val_length_LIS[min_val_length_LIS.size() - 1])
			{
				min_val_length_LIS.push_back(nums[i]);
			}
			else
			{
				int k = bin_search(min_val_length_LIS, nums[i]);
				min_val_length_LIS[k] = nums[i];
			}
		}

		return min_val_length_LIS.size();
	}
};

int main()
{
	Solution s;
	return 0;
}