#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int search(vector<int>& nums, int target) 
	{
		int start = 0;
		int end = nums.size() - 1;

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (nums[middle] == target)
				return middle;

			if (nums[start] <= nums[middle])
			{
				if (target < nums[middle] && target >= nums[start])
					end = middle - 1;
				else
					start = middle + 1;
			}
			else
			{
				if (target > nums[middle] && target <= nums[end])
					start = middle + 1;
				else
					end = middle - 1;
			}
		}

		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 3, 1};
	int a = s.search(param, 1);
	return 0;
}