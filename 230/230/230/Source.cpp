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

	void inOrder(TreeNode* root, int k, vector<int>& arr)
	{
		if (root == NULL || arr.size() >= k)
			return;

		inOrder(root->left, k, arr);
		arr.push_back(root->val);
		inOrder(root->right, k, arr);
	}

	int kthSmallest(TreeNode* root, int k) 
	{
		vector<int> dummy;
		inOrder(root, k, dummy);

		return dummy[k - 1];
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);

	int val = s.kthSmallest(root, 1);

	return 0;
}