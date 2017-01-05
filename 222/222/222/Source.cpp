#include <iostream>
#include <cmath>

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

	int getLeftLength(TreeNode* node) 
	{
		if (node == NULL)
			return 0;

		return 1 + getLeftLength(node->left);
	}


	int getRightLength(TreeNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + getRightLength(node->right);
	}

	int countNodesLeft(TreeNode* root, int leftLength)
	{
		if (root == NULL)
			return 0;

		int rightLength = getRightLength(root->right);

		if (leftLength == rightLength)
			return (1 << (leftLength + 1)) - 1;

		int leftTreeCount = countNodesLeft(root->left, leftLength - 1);
		int RightTreeCount = countNodesRight(root->right, rightLength - 1);

		return leftTreeCount + RightTreeCount + 1;
	}

	int countNodesRight(TreeNode* root, int rightLength)
	{
		if (root == NULL)
			return 0;

		int leftLength = getLeftLength(root->left);

		if (leftLength == rightLength)
			return (1 << (leftLength + 1)) - 1;

		int leftTreeCount = countNodesLeft(root->left, leftLength - 1);
		int RightTreeCount = countNodesRight(root->right, rightLength - 1);

		return leftTreeCount + RightTreeCount + 1;
	}

	int countNodes(TreeNode* root) 
	{
		if (root == NULL)
			return 0;

		int leftLength = getLeftLength(root->left);
		int rightLength = getRightLength(root->right);

		if (leftLength == rightLength)
			return (1 << (leftLength+1)) - 1;

		int leftTreeCount = countNodesLeft(root->left, leftLength - 1);
		int RightTreeCount = countNodesRight(root->right, rightLength - 1);

		return leftTreeCount + RightTreeCount + 1;
	}
};

int main()
{
	Solution s;
	return 0;
}