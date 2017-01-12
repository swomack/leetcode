#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findDuplicate(vector<int>& nums) 
	{
		int start = 1;
		int end = nums.size() - 1;

		while (start < end)
		{
			int middle = (start + end) / 2;

			int less = 0;
			int great = 0;

			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] <= middle)
					less++;
				else
					great++;
			}

			if (less > middle)
				end = middle;
			else
				start = middle + 1;
		}

		return start;
	}
};

int main()
{
	Solution s;
	return 0;
}