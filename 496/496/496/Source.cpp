#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;


class Solution 
{
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
	{
		vector<int> res(findNums.size(), -1);

		if (findNums.size() <= 0 || nums.size() <= 1)
			return res;

		unordered_map<int, int> elements_map;
		int index = 1;
		for_each(findNums.begin(), findNums.end(), [&elements_map, &index](int element) {
			elements_map[element] = index++; 
		});


		stack<int> lesser_elements;
		lesser_elements.push(nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] <= lesser_elements.top())
			{
				lesser_elements.push(nums[i]);
				continue;
			}

			while (!lesser_elements.empty() && lesser_elements.top() < nums[i])
			{
				if (elements_map[lesser_elements.top()] > 0)
				{
					res[elements_map[lesser_elements.top()] - 1] = nums[i];
				}
				lesser_elements.pop();
			}

			lesser_elements.push(nums[i]);
		}

		return res;
	}
};

int main()
{
	return 0;
}