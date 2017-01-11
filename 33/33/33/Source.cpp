#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int find_start_pos(vector<int>& nums)
	{
		int start = 0; 
		int end = nums.size() - 1;

		while (start < end - 1)
		{
			int middle = (start + end) / 2;

			if (nums[middle] > nums[start] && nums[middle] < nums[end])
				return start;

			if (nums[middle] > nums[start])
				start = middle;
			else
				end = middle;
		}

		return nums[start] < nums[end] ? start :  end;
	}

	int search(vector<int>& nums, int target) 
	{
		int start = find_start_pos(nums);
		int end = start + nums.size();

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (nums[middle % nums.size()] == target)
				return middle % nums.size();

			if (nums[middle % nums.size()] > target)
				end = middle - 1;
			else
				start = middle + 1;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 5,7,9,1, 3 };
	int a = s.search(param, 1);
	int b = s.search(param, 3);
	int c = s.search(param, 5);
	int d = s.search(param, 7);
	int e = s.search(param, 9);
	return 0;
}