#include <iostream>
#include <algorithm>

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

		bool leftBalanced = isBalanced(root->left);
		bool rightBalanced = isBalanced(root->right);



		return leftBalanced && rightBalanced && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
	}
};

int main()
{
	Solution s;
	return 0;
}