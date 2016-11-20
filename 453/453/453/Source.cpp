#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int minMoves(vector<int>& nums) 
	{
		int result = 0;
		sort(nums.begin(), nums.end());

		int lowest = nums[0];

		for (int i = nums.size() - 1; i > 0; i--)
		{
			int diff = nums[i] + result - lowest;
			result += diff;
			lowest += diff;
		}

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{ 1, 2, 5 };


	int result = s.minMoves(param);

	getchar();
}