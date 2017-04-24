#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> sums;

class Solution 
{
public:
	int findTargetSumWays(vector<int>& nums, int S) 
	{

		if (nums.size() == 1)
		{
			if (abs(nums[0]) == abs(S))
				return 1;
			return 0;
		}

		unordered_map<int, int> map;
		unordered_map<int, int> map2;
		int l = nums.size() / 2;

		map.clear();
		sums.clear();

		sums.push_back(nums[0]);
		sums.push_back(-nums[0]);
		fillMap(nums, 1, l, sums, map);

		map2.clear();
		sums.clear();

		sums.push_back(nums[l]);
		sums.push_back(-nums[l]);
		fillMap(nums, l + 1, nums.size(), sums, map2);

		int count = 0;

		for_each(map.begin(), map.end(), [&count, &S, &map2](pair<int, int> element) {
			
			count += element.second * map2[S - element.first];
			
		});

		return count;
	}

	void fillMap(vector<int>& nums, int index, int last_index, vector<int>& sums, unordered_map<int, int>& map)
	{
		if (index >= last_index)
		{
			for_each(sums.begin(), sums.end(), [&](int num) {
				map[num]++;
			});
			return;
		}


		int num = nums[index];
		int size = sums.size();
		for (int i = 0; i < size; i++)
		{
			sums[i] += num;
			sums.push_back(sums[i] - 2 * num);
		}

		return fillMap(nums, index + 1, last_index, sums, map);
	}
};

int main()
{
	Solution s;

	//int count = s.findTargetSumWays({1,1,1,1,1}, 3);

	return 0;
}