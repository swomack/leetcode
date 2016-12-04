#include <iostream>
#include <climits>
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
	int minDepth(TreeNode* root) 
	{
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		int left = INT_MAX;
		if (root->left != NULL)
			left = minDepth(root->left);

		int right = INT_MAX;
		if (root->right != NULL)
			right = minDepth(root->right);

		return min(left, right) + 1;
	}
};

int main()
{
	Solution s;
	
	return 0;
}