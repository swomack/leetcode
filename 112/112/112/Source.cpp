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
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (root == NULL)
			return false;

		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->val)
				return true;

			return false;
		}

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	bool result = s.hasPathSum(root, 22);

	getchar();
	return 0;
}
