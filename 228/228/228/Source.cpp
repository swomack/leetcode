#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	string make_range(int a, int b)
	{
		if (a != b)
			return to_string(a) + "->" + to_string(b);
		else
			return to_string(a);
	}

	vector<string> summaryRanges(vector<int>& nums) 
	{
		vector<string> res;

		if (nums.size() <= 0)
			return res;

		int i = 0, j = 0;

		for (; i < nums.size(); i++)
		{
			if (nums[i] - nums[j] == (i - j))
				continue;

			res.push_back(make_range(nums[j], nums[i - 1]));
			j = i;
		}

		res.push_back(make_range(nums[j], nums[i - 1]));
		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}