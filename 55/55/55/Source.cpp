#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool canJump(vector<int>& nums) 
	{
		if (nums.size() <= 1)
			return true;

		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (i + nums[i] >= nums.size() - 1)
				return true;
		}

		return false;
	}
};

int main()
{
	Solution s;
	return 0;
}