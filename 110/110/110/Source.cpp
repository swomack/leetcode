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

	unordered_map<TreeNode*, int> heightMap;

	int getHeight(TreeNode* node)
	{
		if (node == NULL)
			return 0;

		int heightFromMap = heightMap[node];

		if (heightFromMap > 0)
			return heightFromMap;

		heightFromMap = max(getHeight(node->left), getHeight(node->right)) + 1;
		heightMap[node] = heightFromMap;
		return heightFromMap;
	}

	bool isBalancedHelper(TreeNode * node)
	{
		if (node == NULL)
			return true;

		return isBalancedHelper(node->left) && isBalancedHelper(node->right) && abs(getHeight(node->left) - getHeight(node->right)) <= 1;
	}

	bool isBalanced(TreeNode* root) 
	{
		heightMap.clear();

		return isBalancedHelper(root);
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