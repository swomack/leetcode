#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define MAKE_SET(a, c) for_each(a.begin(), a.end(), c);

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

		unordered_set<int> larger;
		unordered_set<int> smaller;

		MAKE_SET(nums1, [&larger](int element) {
			larger.insert(element);
		});

		MAKE_SET(nums2, [&smaller](int element) {
			smaller.insert(element);
		});
		
		for_each(smaller.begin(), smaller.end(), [&larger, &res](int element) {
			unordered_set<int>::iterator it = larger.find(element);

			if (it != larger.end())
				res.push_back(*it);
		});

		return res;
	}
};

int main()
{
	Solution s;

	vector<int> param1{1, 2, 3};
	vector<int> param2{2, 3};

	vector<int> result = s.intersection(param1, param2);
	getchar();
}
