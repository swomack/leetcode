#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		int max_length = 0;

		if (nums.size() <= 0)
			return max_length;

		vector<int> lis_end_length(nums.size());

		max_length = lis_end_length[0] = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			lis_end_length[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					lis_end_length[i] = max(lis_end_length[i], lis_end_length[j] + 1);
			}
			max_length = max(max_length, lis_end_length[i]);
		}

		return max_length;
	}
};

int main()
{
	Solution s;
	return 0;
}