#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution 
{
public:
	int minMoves2(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());

		int median = nums[nums.size() / 2];

		int count = 0;

		for_each(nums.begin(), nums.end(), [&count, &median](int element) {
			count += abs(element - median);
		});

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}