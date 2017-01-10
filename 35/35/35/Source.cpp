#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		if (nums.size() <= 0)
			return 0;

		int start = 0;
		int end = nums.size() - 1;
		int middle = 0;

		while (start <= end)
		{
			middle = (start + end) / 2;

			if (nums[middle] == target)
				return middle;

			if (nums[middle] > target)
				end = middle - 1;
			else
				start = middle + 1;
		}

		if (nums[middle] > target)
			return middle;
	
		return middle + 1;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,3,5,7 };
	int k = s.searchInsert(param, 8);
	return 0;
}