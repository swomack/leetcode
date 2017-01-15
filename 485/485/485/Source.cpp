#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums) 
	{
		int max_one = 0;

		int running_count = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
				running_count++;
			else
			{
				max_one = max(max_one, running_count);
				running_count = 0;
			}
		}

		max_one = max(max_one, running_count);

		return max_one;
	}
};

int main()
{
	Solution s;
	return 0;
}