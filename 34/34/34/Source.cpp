#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> result;

		int start = 0;
		int end = nums.size() - 1;

		int found_index = -1;

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (nums[middle] == target)
			{
				found_index = middle;
				break;
			}
			
			if (nums[middle] > target)
				end = middle - 1;
			else
				start = middle + 1;
		}

		if (found_index == -1)
		{
			result.push_back(found_index);
			result.push_back(found_index);
			return result;
		}

		start = 0;
		end = found_index - 1;
		while (start <= end && nums[end] == target && nums[start] != target)
		{
			int middle = (start + end) / 2;

			if (nums[middle] == target)
				end = middle - 1;
			else
				start = middle + 1;
		}

		result.push_back(nums[start] == target ? start : end + 1);


		start = found_index + 1;
		end = nums.size() - 1;
		while (start <= end && nums[start] == target && nums[end] != target)
		{
			int middle = (start + end) / 2;

			if (nums[middle] == target)
				start = middle + 1;
			else
				end = middle - 1;
		}

		result.push_back(nums[end] == target ? end : start - 1);

		return result;
	}
};

int main()
{
	vector<int> param{ 5,7,7,8,8,10 };
	Solution s;

	vector<int> res = s.searchRange(param, 8);

	return 0;
}