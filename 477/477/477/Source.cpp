#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	int pop_count(int n)
	{
		return __builtin_popcount(n);
	}

	int totalHammingDistance(vector<int>& nums) 
	{
		int count = 0;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				count += pop_count(nums[i] ^ nums[j]);
			}
		}

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}