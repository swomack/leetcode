#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:

	// divide and conquere
	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int i, int j)
	{
		if (i > j)
			return NULL;

		int mid = ceil((i + j) / 2.0);

		TreeNode* root= new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTHelper(nums, i, mid - 1);
		root->right = sortedArrayToBSTHelper(nums, mid + 1, j);

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		if (nums.size() <= 0)
			return NULL;

		return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
	}
};

int main()
{
	Solution s;
	return 0;
}