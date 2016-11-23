#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution 
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int>> results;

		sort(nums.begin(), nums.end());
		
		unordered_map<int, vector<pair<int, int>>> map;

		// make a map to store the summation of all pair
		for (int i = 0; i < nums.size();)
		{
			for (int j = i + 1; j < nums.size();)
			{
				int sum = nums[i] + nums[j];
				map[sum].push_back(make_pair(i, j));

				while (++j && j < nums.size() && nums[j] == nums[j - 1]);
			}

			while (++i && i < nums.size() && nums[i] == nums[i - 1]);
		}

		// now it is a two sum problem

		for (int i = 0, j = nums.size() - 1; i < j ;)
		{
			int search = target - nums[i] - nums[j];

			vector<pair<int, int>> kk = map[search];

			for (int k = 0; k < kk.size(); k++)
			{
				if(pair)
			}
		}
	
	}
};

int main()
{
	Solution s;
	vector<int> param{1, 0, -1, 0, -2, 2};

	vector<vector<int>> res = s.fourSum(param, 0);

	getchar();
	return 0;
}