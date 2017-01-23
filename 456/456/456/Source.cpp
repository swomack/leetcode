#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

	bool check_in_range(vector<pair<int, int>>& ranges, int number)
	{
		for (int i = 0; i < ranges.size(); i++)
		{
			if (number > ranges[i].first && number < ranges[i].second)
				return true;
		}

		return false;
	}

	bool find132pattern(vector<int>& nums) 
	{
		bool result = false;

		if (nums.size() < 3)
			return result;

		vector<pair<int, int>> ranges;

		int min = nums[0];
		int max = nums[0];


		for (int i = 1; i < nums.size(); i++)
		{
			if ((nums[i] > min && nums[i] < max) || check_in_range(ranges, nums[i]))
			{
				result = true;
				break;
			}


			if (nums[i] > max)
			{
				max = nums[i];
			}
			
			if (nums[i] > nums[i - 1])
			{
				ranges.push_back(make_pair(min, max));
				min = nums[i - 1];
				max = nums[i];
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 3,1,4,2 };
	bool res = s.find132pattern(param);
	return 0;
}