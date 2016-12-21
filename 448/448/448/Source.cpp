#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) 
	{
		vector<int> map(nums.size());

		for (int i = 0; i < nums.size(); i++)
			map[nums[i] - 1] = nums[i];

		vector<int> res;

		for (int i = 0; i < map.size(); i++)
		{
			if (map[i] == 0)
				res.push_back(i + 1);
		}

		return res;

	}
};

int main()
{
	Solution s;
	return 0;
}