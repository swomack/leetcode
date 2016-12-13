#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		unordered_map<int, int> map;

		for_each(nums.begin(), nums.end(), [&map](int element) {
			map[element]++;
		});

		priority_queue<pair<int, int>> max_heap;
		
		for_each(map.begin(), map.end(), [&max_heap](pair<int, int> element) {
			max_heap.push(make_pair(element.second, element.first));
		});

		vector<int> result;

		for (int i = 0; i < k; i++)
		{
			result.push_back(max_heap.top().second);
			max_heap.pop();
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> param{ -1,-1 };
	vector<int> res = s.topKFrequent(param, 1);
	return 0;
}