#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;


class Solution
{
public:
	vector<int> nextGreaterElements(vector<int>& nums)
	{
		vector<int> res(nums.size(), -1);

		if (nums.size() <= 1)
			return res;

		stack<int> lesser_elements;
		lesser_elements.push(0);

		for (int i = 1; i < nums.size() * 2; i++)
		{
			if (nums[i % nums.size()] <= nums[lesser_elements.top()])
			{
				lesser_elements.push(i % nums.size());
				continue;
			}

			while (!lesser_elements.empty() && nums[lesser_elements.top()] < nums[i % nums.size()])
			{
				res[lesser_elements.top()] = nums[i % nums.size()];
				lesser_elements.pop();
			}

			lesser_elements.push(i % nums.size());
		}

		return res;
	}
};

int main()
{
	return 0;
}