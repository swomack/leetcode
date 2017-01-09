#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findMin(vector<int>& nums) 
	{
		int start = 0;
		int end = nums.size() - 1;

		while (start < end - 1)
		{
			int middle = (start + end) / 2;

			if (nums[start] < nums[middle] && nums[middle] < nums[end])
				return nums[start];

			if (nums[middle] > nums[start])
				start = middle;
			else
				end = middle;

		}

		return min(nums[start], nums[end]);
	}
};

int main()
{
	Solution s;
	return 0;
}