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
	void preorderTraversalHelper(TreeNode* root, vector<int>& result)
	{
		if (root == NULL)
			return;

		result.push_back(root->val);
		preorderTraversalHelper(root->left, result);
		preorderTraversalHelper(root->right, result);
	}

	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		preorderTraversalHelper(root, result);
		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}