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
private:

	int traverseLeft(TreeNode* child)
	{
		if (child == NULL)
			return 0;

		if (child->left == NULL && child->right == NULL)
			return child->val;

		return traverseLeft(child->left) + traverseRight(child->right);
	}


	int traverseRight(TreeNode* child)
	{
		if (child == NULL)
			return 0;

		if (child->left == NULL && child->right == NULL)
			return 0;

		return traverseLeft(child->left) + traverseRight(child->right);
	}

public:

	

	int sumOfLeftLeaves(TreeNode* root) 
	{
		if (root == NULL)
			return 0;

		return traverseLeft(root->left) + traverseRight(root->right);
	}
};

int main()
{
	Solution s;

}