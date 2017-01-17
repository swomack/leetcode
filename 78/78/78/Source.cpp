#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	void subsetHelper(vector<int>& subset, vector<int>& indices, vector<int>& nums, vector<vector<int>> &result)
	{
		if (indices.size() >= nums.size())
			return;

		int last_index = indices.size() > 0 ? indices[indices.size() - 1] : -1;

		for (int i = last_index + 1; i < nums.size(); i++)
		{
			subset.push_back(nums[i]);
			result.push_back(subset);
			indices.push_back(i);

			subsetHelper(subset, indices, nums, result);

			indices.pop_back();
			subset.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) 
	{
		vector<vector<int>> result;
		vector<int> subset;
		vector<int> indices;

		result.push_back(subset);
		subsetHelper(subset, indices, nums, result);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}