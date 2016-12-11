#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmpStruct 
{
	bool operator() (int const & lhs, int const & rhs) const
	{
		return lhs > rhs;
	}
};

class Solution 
{
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		sort(nums.begin(), nums.end(), cmpStruct());

		return nums[k - 1];
	}
};

int main()
{
	Solution s;
	return 0;
}