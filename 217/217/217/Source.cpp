#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++)
		{
			if (map[nums[i]] > 0)
				return true;

			map[nums[i]] = 1;
		}
		return false;
	}
};

int main()
{
	vector<int> param{ 1,2,3,3 };

	Solution s;

	bool result = s.containsDuplicate(param);

	return 0;
}