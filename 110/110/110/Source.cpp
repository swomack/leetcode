#include <iostream>
#include <algorithm>
#include <unordered_map>

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
	int getHeight(TreeNode* node)
	{
		if (node == NULL)
			return 0;

		return max(getHeight(node->left), getHeight(node->right)) + 1;
	}


	bool isBalanced(TreeNode* root) 
	{
		if (root == NULL)
			return true;

		return isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	bool result = s.isBalanced(root);

	return 0;
}