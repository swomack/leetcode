#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	
	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int> count(target + 1);

		count[0] = 1;
		
		for (int i = 1; i <= target; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i - nums[j] >= 0)
					count[i] += count[i - nums[j]];
			}
		}

		return count[target];
	}
};

int main()
{
	Solution s;
	vector<int> param{ 4,2,1 };

	int res = s.combinationSum4(param, 7);

	return 0;
}