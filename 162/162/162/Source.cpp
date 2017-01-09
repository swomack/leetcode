#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sort_func
{
public:
	bool operator () (const pair<int, int> lhs, const pair<int, int> rhs)
	{
		if (lhs.first > rhs.first)
			return true;
		return false;
	}
};

class Solution 
{
public:
	int findPeakElement(vector<int>& nums) 
	{
		if (nums.size() == 1 || nums[1] < nums[0])
			return 0;

		if (nums[nums.size() - 2] < nums[nums.size() - 1])
			return nums.size() - 1;

		vector<pair<int, int>> sorted(nums.size());

		for (int i = 0; i < nums.size(); i++)
			sorted[i] = make_pair(nums[i], i);

		sort(sorted.begin(), sorted.end(), sort_func());

		for (int i = 0; i < nums.size(); i++)
		{
			int num = sorted[i].first;
			int pos = sorted[i].second;

			if (pos == 0 || pos == nums.size() - 1)
				continue;

			if (num > nums[pos - 1] && num > nums[pos + 1])
				return pos;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> param{1,3,2,6,7,4,5,1,2,9,8};
	int k = s.findPeakElement(param);
	return 0;
}