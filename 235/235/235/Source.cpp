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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if (root == NULL)
			return root;

		TreeNode* lower = p->val > q->val ? q : p;
		TreeNode* higher = p->val > q->val ? p : q;

		if (root->val >= lower->val && root->val <= higher->val)
			return root;
		else if (root->val > lower->val)
			return lowestCommonAncestor(root->left, lower, higher);
		else
			return lowestCommonAncestor(root->right, lower, higher);
	}
};


int main()
{

	getchar();
	return 0;
}