#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) 
	{
		unordered_map<int, int> last_pos;

		for (int i = 0; i < nums.size(); i++)
		{
			int pos = i + 1;
			int last_pos_i = last_pos[nums[i]];
			if (last_pos_i && pos - last_pos_i <= k)
				return true;

			last_pos[nums[i]] = pos;
		}

		return false;
	}
};

int main()
{
	Solution s;
	return 0;
}