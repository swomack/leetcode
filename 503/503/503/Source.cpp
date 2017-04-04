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
		int actual_size = nums.size();
		vector<int> res(actual_size, -1);

		if (actual_size <= 1)
			return res;

		nums.resize(actual_size * 2);

		for (int i = 0; i < actual_size; i++)
			nums[actual_size + i] = nums[i];


		stack<pair<int, int>> lesser_elements;
		lesser_elements.push({ nums[0], 0 });

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] <= lesser_elements.top().first)
			{
				lesser_elements.push({ nums[i], i });
				continue;
			}

			while (!lesser_elements.empty() && lesser_elements.top().first < nums[i])
			{
				res[lesser_elements.top().second % actual_size] = nums[i];
				lesser_elements.pop();
			}

			lesser_elements.push({ nums[i], i });
		}

		return res;
	}
};

int main()
{
	return 0;
}