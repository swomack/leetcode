#include <iostream>
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

	int inOrder(TreeNode* root, int& k)
	{
		if (root == NULL)
			return -1;
		
		int val = inOrder(root->left, k);
		if (!k)
			return val;

		k--;
		if (!k)
			return root->val;
		
		return inOrder(root->right, k);
	}

	int kthSmallest(TreeNode* root, int k) 
	{
		return inOrder(root, k);
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);

	int val = s.kthSmallest(root, 1);

	return 0;
}