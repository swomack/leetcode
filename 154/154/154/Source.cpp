#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;

		while (nums[start] == nums[end] && start <= end)
			end--;

		while (nums[start] == nums[start + 1] && start <= end)
			start++;

		while (start < end)
		{
			if (nums[start] < nums[end])
				return nums[start];

			int middle = (start + end) / 2;

			if (nums[start] < nums[middle])
				start = middle + 1;
			else
				end = middle;
		}

		return nums[start];
	}
};

int main()
{
	vector<int> param{ 3,5,1 };
	Solution s;
	int minimim = s.findMin(param);
	return 0;
}