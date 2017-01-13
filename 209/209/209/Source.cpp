#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		if (nums.size() == 0)
			return 0;

		int first = 0;
		int last = 0;
		int sum = nums[last];
		int min_length = INT_MAX;

		while (last < nums.size() && first < nums.size())
		{
			if (sum >= s)
			{
				min_length = min(min_length, last - first + 1);
				sum -= nums[first];
				first++;
				continue;
			}
			else
			{
				last++;
				sum += nums[last];
			}
		}

		return min_length == INT_MAX ? 0 : min_length;
	}
};

int main()
{
	vector<int> param{ 1,2,3,4,5 };
	Solution s;
	int k = s.minSubArrayLen(11, param);
	return 0;
}