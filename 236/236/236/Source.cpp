#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	bool find(TreeNode* node, TreeNode* p, TreeNode* q)
	{
		if (node == NULL)
			return false;

		if (node == p || node == q)
			return true;

		return find(node->left, p, q) || find(node->right, p, q);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if (root == NULL)
			return NULL;

		if (root == p || root == q)
			return root;

		bool left = find(root->left, p, q);
		bool right = find(root->right, p, q);

		if (left && right)
			return root;
	

		if (left)
			return lowestCommonAncestor(root->left, p, q);

		return lowestCommonAncestor(root->right, p, q);
	}
};

int main()
{
	Solution s;
	return 0;
}