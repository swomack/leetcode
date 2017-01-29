#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool search(vector<int>& nums, int target) 
	{
		int start = 0;
		int end = nums.size() - 1;

		while (start < end && nums[start] == nums[end])
			end--;

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (nums[middle] == target)
			{
				return true;
			}
			else if (target <= nums[end] && target < nums[start])
			{
				if (nums[middle] > target && nums[middle] <= nums[end])
				{
					end = middle - 1;
				}
				else
				{
					start = middle + 1;
				}
			}
			else
			{
				if (nums[middle] < target && nums[middle] >= nums[start])
				{
					start = middle + 1;
				}
				else
				{
					end = middle - 1;
				}
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 2,2,1,1 };
	bool res = s.search(param, 1);
	return 0;
}