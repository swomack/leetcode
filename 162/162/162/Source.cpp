#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution 
{
public:
	int findPeakElement(vector<int>& nums) 
	{
		if (nums.size() == 1 || nums[1] < nums[0])
			return 0;

		if (nums[nums.size() - 2] < nums[nums.size() - 1])
			return nums.size() - 1;

		int start = 0;
		int end = nums.size() - 1;

		int res = -1;

		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
			{
				res = middle;
				break;
			}
			else if (nums[middle - 1] > nums[middle])
				end = middle - 1;
			else
				start = middle + 1;
		}
	}
};

int main()
{
	Solution s;
	vector<int> param{1,3,2,6,7,4,5,1,2,9,8};
	int k = s.findPeakElement(param);
	return 0;
}