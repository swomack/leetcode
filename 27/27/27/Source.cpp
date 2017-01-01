#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int valid_index = nums.size() - 1;

		int running_index = 0;

		while (running_index <= valid_index)
		{
			if (nums[running_index] != val)
			{
				running_index++;
				continue;
			}

			nums[running_index] = nums[valid_index];
			nums[valid_index] = val;
			valid_index--;
		}

		return valid_index + 1;
	}
};

int main()
{
	Solution s;
	return 0;
}