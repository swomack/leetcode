#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool canJump(vector<int>& nums, vector<bool>& visited, int index)
	{
		if (index >= nums.size() - 1)
			return true;

		if (visited[index])
			return false;

		visited[index] = true;

		for (int i = nums[index]; i >= 1; i--)
		{
			bool ret = canJump(nums, visited, index + i);

			if (ret)
				return ret;
		}

		return false;
	}

	bool canJump(vector<int>& nums) 
	{
		vector<bool> visited(nums.size());

		return canJump(nums, visited, 0);
	}
};

int main()
{
	Solution s;
	return 0;
}