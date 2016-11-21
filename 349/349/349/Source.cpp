#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;



class Solution 
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{

		if (nums2.size() > nums1.size())
			return intersection(nums2, nums1);

		vector<int> res;

		if (nums1.size() == 0 || nums2.size() == 0)
			return res;

		unordered_map<int, int> map;

		for_each(nums2.begin(), nums2.end(), [&map](int element) {
			map[element] ++;
		});

		for_each(nums1.begin(), nums1.end(), [&map, &res](int element) {
			int val = map[element];
			if (val > 0)
			{
				res.push_back(element);
				map[element] = 0;
			}
				
		});

		return res;
	}
};

int main()
{
	Solution s;

	vector<int> param1{1, 2, 3};
	vector<int> param2{4, 4};

	vector<int> result = s.intersection(param1, param2);
	getchar();
}
