#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		if (n <= 0)
			return;

		vector<int> res;

		int total = m + n;

		int i = 0;
		int j = 0;

		for (int k = 0; k < total && i < m && j < n; k++)
		{
			if (nums1[i] < nums2[j])
			{
				res.push_back(nums1[i++]);
			}
			else
			{
				res.push_back(nums2[j++]);
			}
		}

		while (i < m)
			res.push_back(nums1[i++]);

		while (j < n)
			res.push_back(nums2[j++]);

		copy(res.begin(), res.end(), nums1.begin());
	}
};

int main()
{
	Solution s;
	return 0;
}