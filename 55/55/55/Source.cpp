#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool canJump(vector<int>& nums) 
	{
		vector<bool> visited(nums.size());

		int next_index = nums[0];
		visited[0] = true;

		while (next_index >= 0 && next_index < nums.size())
		{
			//visited[next_index] = true;

			if (nums[next_index] > 0)
				next_index += nums[next_index];
			else
				next_index--;
		}
	}
};

int main()
{
	Solution s;
	return 0;
}