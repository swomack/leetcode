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
		vector<int> res;

		if (findNums.size() <= 0 || nums.size() <= 1)
			return res;

		unordered_map<int, int> next_greater_map;
		
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
				next_greater_map[lesser_elements.top().first] = i;
				lesser_elements.pop();
			}

			lesser_elements.push({ nums[i], i });
		}

		

		for (int i = 0; i < findNums.size(); i++)
		{
			res.push_back(next_greater_map[findNums[i]] > 0 ? nums[next_greater_map[findNums[i]]] : -1);
		}

		return res;
	}
};

int main()
{
	return 0;
}