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
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL)
			return NULL;

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	TreeNode *res = s.invertTree(root);

	getchar();
}