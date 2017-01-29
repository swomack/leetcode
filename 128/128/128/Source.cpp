#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int longestConsecutive(vector<int>& nums) 
	{
		int length = 0;
		unordered_map<int, bool> map;

		for (int i = 0; i < nums.size(); i++)
		{
			if (map[nums[i]] == true)
				continue;

			map[nums[i]] = true;

			if (map[nums[i] - 1] == true)
				length++;

			if (map[nums[i] + 1] == true)
				length++;
		}

		return ++length;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 100,4,200,1,3,2 };
	int val = s.longestConsecutive(param);
	return 0;
}