#include <iostream>

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

	TreeNode* find_leaf(TreeNode* node)
	{
		if (node == NULL)
			return NULL;

		if (node->left == NULL && node->right == NULL)
			return node;

		return find_leaf(node->right);
	}

	void flatten(TreeNode* root) 
	{
		if (root == NULL)
			return;

		flatten(root->left);
		flatten(root->right);

		TreeNode* left_leaf = find_leaf(root->left);

		if (left_leaf)
		{
			left_leaf->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
	}
};

int main()
{
	Solution s;
	return 0;
}