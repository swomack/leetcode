#include <iostream>
#include <climits>
#include <vector>

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

	bool isValidBSTHelper(TreeNode* node, int min_limit, int max_limit, bool left_inclusive, bool right_inclusive)
	{
		if (node == NULL)
			return true;

		bool bst;
		
		if(left_inclusive && right_inclusive)
			bst = node->val >= min_limit && node->val <= max_limit ? true : false;
		else if (left_inclusive)
			bst = node->val >= min_limit && node->val < max_limit ? true : false;
		else if(right_inclusive)
			bst = node->val > min_limit && node->val <= max_limit ? true : false;
		else
			bst = node->val > min_limit && node->val < max_limit ? true : false;

		if (!bst)
			return false;

		return isValidBSTHelper(node->left, min_limit, node->val, left_inclusive, false) && isValidBSTHelper(node->right, node->val, max_limit, false, right_inclusive);
	}


	bool isValidBST(TreeNode* root) 
	{
		if (root == NULL)
			return true;

		return isValidBSTHelper(root->left, INT_MIN, root->val, true, false) && isValidBSTHelper(root->right, root->val, INT_MAX, false, true);
	}
};





int main()
{
	Solution s;
	return 0;
}