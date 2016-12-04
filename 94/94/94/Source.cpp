#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
	void inorderTraversalHelper(TreeNode* root, vector<int>& result)
	{
		if (root == NULL)
			return;

		inorderTraversalHelper(root->left, result);
		result.push_back(root->val);
		inorderTraversalHelper(root->right, result);
	}
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;

		inorderTraversalHelper(root, result);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}