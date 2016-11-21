#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> res;

		if (nums1.size() == 0 || nums2.size() == 0)
			return res;

		unordered_set<int> res_cont;


		sort(nums1.begin(), nums1.end());

		for_each(nums2.begin(), nums2.end(), [&res_cont, &nums1](int element) {
		
			int start = 0;
			int end = nums1.size() - 1;

			while (start <= end) 
			{
				int middle = (start + end) / 2;

				if (nums1[middle] == element)
				{
					res_cont.insert(element);
					break;
				}

				if (nums1[middle] > element)
				{
					end = middle - 1;
					continue;
				}

				start = middle + 1;

			}
		
		});


		for_each(res_cont.begin(), res_cont.end(), [&res](int element) {
			res.push_back(element);
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
